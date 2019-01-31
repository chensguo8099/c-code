/*系部表*/
USE teachingManagementSystem;
GO
CREATE TABLE department(
	departmentId SMALLINT NOT NULL PRIMARY KEY IDENTITY(1, 1),/*系号*/
	departmentName VARCHAR(100) NOT NULL,/*系名称*/
	departmentIntroduce TEXT DEFAULT('')/*简介，text类型为可变长度字符串，最多2G字符数据*/
);
GO

/*学生表*/
CREATE TABLE student(
	studentId VARCHAR(20) NOT NULL PRIMARY KEY,/*学号*/
	studentName VARCHAR(50) NOT NULL,/*学生姓名*/
	studentSex SMALLINT NOT NULL CHECK(studentSex = '0' or studentSex = '1'), /*0代表女 1代表男*/
	studentPassword VARCHAR(50)  NOT NULL DEFAULT('123456'),/*学生密码*/
	studentBorntime DATE NOT NULL,/*出生日期，支持范围：1000-01-01~9999-12-31*/
	departmentId SMALLINT NOT NULL FOREIGN KEY REFERENCES department(departmentId)/*系号，通过外键与系部表关联*/
);
GO

/*课程表*/
CREATE TABLE course(
	courseId INT NOT NULL PRIMARY KEY IDENTITY(1, 1),/*课程号*/
	courseName VARCHAR(50) NOT NULL,/*课程名*/
	departmentId SMALLINT NOT NULL FOREIGN KEY REFERENCES department(departmentId),/*系号*/
	coursePeriod FLOAT NOT NULL CHECK(coursePeriod >= 0),/*学时*/
	courseCredit FLOAT NOT NULL CHECK(courseCredit >= 0),/*学分*/
	courseIntroduce TEXT DEFAULT('')/*课程介绍，text类型为可变长度字符串，最多2G字符数据*/
);
GO

/*教师表*/
CREATE TABLE teacher(
	teacherId VARCHAR(20) NOT NULL PRIMARY KEY,/*教师号*/
	teacherName VARCHAR(50) NOT NULL,/*教师名*/
	teacherSex SMALLINT NOT NULL CHECK(teacherSex = '0' or teacherSex = '1'), /*0代表女 1代表男*/
	teacherPassword VARCHAR(50)  NOT NULL DEFAULT('123456'),/*教师密码*/
	departmentId SMALLINT NOT NULL FOREIGN KEY REFERENCES department(departmentId)/*系号，通过外键与系部表关联*/
);
GO

/*选课表*/
CREATE TABLE selectcourse(
	/*selectcourseId INT NOT NULL PRIMARY KEY IDENTITY(1, 1),/*仅作为主键唯一标识用*/*/
	studentId VARCHAR(20) NOT NULL /*FOREIGN KEY REFERENCES student(studentId)*/,/*学生号*/
	courseId INT NOT NULL /*FOREIGN KEY REFERENCES course(courseId)*/,/*课程号*/
	teacherId VARCHAR(20) NOT NULL /*FOREIGN KEY REFERENCES teacher(teacherId)*/,/*教师号*/
	courseGrade FLOAT  DEFAULT(NULL) CHECK(courseGrade >= 0 and courseGrade <= 100),/*成绩，默认为NULL 限制范围0~100*/
	PRIMARY KEY(studentId, courseId, teacherId),
	FOREIGN KEY(studentId) REFERENCES student(studentId) ON DELETE CASCADE ON UPDATE CASCADE,
	FOREIGN KEY(courseId) REFERENCES course(courseId) ON DELETE CASCADE ON UPDATE CASCADE,
	FOREIGN KEY(teacherId) REFERENCES teacher(teacherId) ON DELETE CASCADE ON UPDATE CASCADE
);
GO

/*授课表*/
CREATE TABLE givecourse(
	/*givecourseId INT NOT NULL PRIMARY KEY IDENTITY(1, 1),*//*仅作为主键唯一标识用*/
	teacherId VARCHAR(20) NOT NULL/*FOREIGN KEY REFERENCES teacher(teacherId)*/,/*学生号*/
	courseId INT NOT NULL/*FOREIGN KEY REFERENCES course(courseId)*/,/*课程号*/
	FOREIGN KEY(teacherId) REFERENCES teacher(teacherId) ON DELETE CASCADE ON UPDATE CASCADE,
	FOREIGN KEY(courseId) REFERENCES course(courseId) ON DELETE CASCADE ON UPDATE CASCADE
);

/*评价表*/
CREATE TABLE comment(
	/*commentId SMALLINT NOT NULL PRIMARY KEY IDENTITY(1, 1),*//*主键*/
	studentId VARCHAR(20) NOT NULL,/*学生号*/
	teacherId VARCHAR(20) NOT NULL,/*教师号*/
	courseId INT NOT NULL,/*课程号*/
	studentcomment TEXT NOT NULL DEFAULT(''),/*学生评价*/
	studentgivescore FLOAT DEFAULT(NULL) CHECK(studentgivescore >= 0 and studentgivescore <=100)/*学生打分*/
	FOREIGN KEY (studentId) REFERENCES student(studentId) ON DELETE CASCADE ON UPDATE CASCADE,
	FOREIGN KEY (teacherId) REFERENCES teacher(teacherId) ON DELETE CASCADE ON UPDATE CASCADE,
	FOREIGN KEY (courseId) REFERENCES course(courseId) ON DELETE CASCADE ON UPDATE CASCADE
);

/*管理员表*/
CREATE TABLE adminmsg(
	adminName VARCHAR(50) NOT NULL PRIMARY KEY,/*管理员账号*/
	adminPassword VARCHAR(50) NOT NULL/*管理员密码*/
);

/*存储过程*/
USE [teachingManagementSystem]
GO
/****** Object:  StoredProcedure [dbo].[highgrade]    Script Date: 06/27/2017 21:46:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
/*大于多少分数*/
create proc [dbo].[highgrade]
 @grade float
 as
 select studentName ,courseName, courseGrade
 from  student, course, selectcourse
 where courseGrade > (@grade) and student.studentId = selectcourse.studentId and 
      selectcourse.CourseId = course.courseId 
 group by studentName ,courseName,courseGrade
 order by courseGrade
GO

USE [teachingManagementSystem]
GO
/****** Object:  StoredProcedure [dbo].[lowgrade]    Script Date: 06/27/2017 21:46:43 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
/*小于多少分数*/
create proc [dbo].[lowgrade]
 @grade float
 as
 select studentName ,courseName, courseGrade
 from  student, course, selectcourse
 where courseGrade < (@grade) and student.studentId = selectcourse.studentId and 
      selectcourse.CourseId = course.courseId 
 group by studentName ,courseName,courseGrade
 order by courseGrade
GO