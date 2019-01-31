/*ϵ����*/
USE teachingManagementSystem;
GO
CREATE TABLE department(
	departmentId SMALLINT NOT NULL PRIMARY KEY IDENTITY(1, 1),/*ϵ��*/
	departmentName VARCHAR(100) NOT NULL,/*ϵ����*/
	departmentIntroduce TEXT DEFAULT('')/*��飬text����Ϊ�ɱ䳤���ַ��������2G�ַ�����*/
);
GO

/*ѧ����*/
CREATE TABLE student(
	studentId VARCHAR(20) NOT NULL PRIMARY KEY,/*ѧ��*/
	studentName VARCHAR(50) NOT NULL,/*ѧ������*/
	studentSex SMALLINT NOT NULL CHECK(studentSex = '0' or studentSex = '1'), /*0����Ů 1������*/
	studentPassword VARCHAR(50)  NOT NULL DEFAULT('123456'),/*ѧ������*/
	studentBorntime DATE NOT NULL,/*�������ڣ�֧�ַ�Χ��1000-01-01~9999-12-31*/
	departmentId SMALLINT NOT NULL FOREIGN KEY REFERENCES department(departmentId)/*ϵ�ţ�ͨ�������ϵ�������*/
);
GO

/*�γ̱�*/
CREATE TABLE course(
	courseId INT NOT NULL PRIMARY KEY IDENTITY(1, 1),/*�γ̺�*/
	courseName VARCHAR(50) NOT NULL,/*�γ���*/
	departmentId SMALLINT NOT NULL FOREIGN KEY REFERENCES department(departmentId),/*ϵ��*/
	coursePeriod FLOAT NOT NULL CHECK(coursePeriod >= 0),/*ѧʱ*/
	courseCredit FLOAT NOT NULL CHECK(courseCredit >= 0),/*ѧ��*/
	courseIntroduce TEXT DEFAULT('')/*�γ̽��ܣ�text����Ϊ�ɱ䳤���ַ��������2G�ַ�����*/
);
GO

/*��ʦ��*/
CREATE TABLE teacher(
	teacherId VARCHAR(20) NOT NULL PRIMARY KEY,/*��ʦ��*/
	teacherName VARCHAR(50) NOT NULL,/*��ʦ��*/
	teacherSex SMALLINT NOT NULL CHECK(teacherSex = '0' or teacherSex = '1'), /*0����Ů 1������*/
	teacherPassword VARCHAR(50)  NOT NULL DEFAULT('123456'),/*��ʦ����*/
	departmentId SMALLINT NOT NULL FOREIGN KEY REFERENCES department(departmentId)/*ϵ�ţ�ͨ�������ϵ�������*/
);
GO

/*ѡ�α�*/
CREATE TABLE selectcourse(
	/*selectcourseId INT NOT NULL PRIMARY KEY IDENTITY(1, 1),/*����Ϊ����Ψһ��ʶ��*/*/
	studentId VARCHAR(20) NOT NULL /*FOREIGN KEY REFERENCES student(studentId)*/,/*ѧ����*/
	courseId INT NOT NULL /*FOREIGN KEY REFERENCES course(courseId)*/,/*�γ̺�*/
	teacherId VARCHAR(20) NOT NULL /*FOREIGN KEY REFERENCES teacher(teacherId)*/,/*��ʦ��*/
	courseGrade FLOAT  DEFAULT(NULL) CHECK(courseGrade >= 0 and courseGrade <= 100),/*�ɼ���Ĭ��ΪNULL ���Ʒ�Χ0~100*/
	PRIMARY KEY(studentId, courseId, teacherId),
	FOREIGN KEY(studentId) REFERENCES student(studentId) ON DELETE CASCADE ON UPDATE CASCADE,
	FOREIGN KEY(courseId) REFERENCES course(courseId) ON DELETE CASCADE ON UPDATE CASCADE,
	FOREIGN KEY(teacherId) REFERENCES teacher(teacherId) ON DELETE CASCADE ON UPDATE CASCADE
);
GO

/*�ڿα�*/
CREATE TABLE givecourse(
	/*givecourseId INT NOT NULL PRIMARY KEY IDENTITY(1, 1),*//*����Ϊ����Ψһ��ʶ��*/
	teacherId VARCHAR(20) NOT NULL/*FOREIGN KEY REFERENCES teacher(teacherId)*/,/*ѧ����*/
	courseId INT NOT NULL/*FOREIGN KEY REFERENCES course(courseId)*/,/*�γ̺�*/
	FOREIGN KEY(teacherId) REFERENCES teacher(teacherId) ON DELETE CASCADE ON UPDATE CASCADE,
	FOREIGN KEY(courseId) REFERENCES course(courseId) ON DELETE CASCADE ON UPDATE CASCADE
);

/*���۱�*/
CREATE TABLE comment(
	/*commentId SMALLINT NOT NULL PRIMARY KEY IDENTITY(1, 1),*//*����*/
	studentId VARCHAR(20) NOT NULL,/*ѧ����*/
	teacherId VARCHAR(20) NOT NULL,/*��ʦ��*/
	courseId INT NOT NULL,/*�γ̺�*/
	studentcomment TEXT NOT NULL DEFAULT(''),/*ѧ������*/
	studentgivescore FLOAT DEFAULT(NULL) CHECK(studentgivescore >= 0 and studentgivescore <=100)/*ѧ�����*/
	FOREIGN KEY (studentId) REFERENCES student(studentId) ON DELETE CASCADE ON UPDATE CASCADE,
	FOREIGN KEY (teacherId) REFERENCES teacher(teacherId) ON DELETE CASCADE ON UPDATE CASCADE,
	FOREIGN KEY (courseId) REFERENCES course(courseId) ON DELETE CASCADE ON UPDATE CASCADE
);

/*����Ա��*/
CREATE TABLE adminmsg(
	adminName VARCHAR(50) NOT NULL PRIMARY KEY,/*����Ա�˺�*/
	adminPassword VARCHAR(50) NOT NULL/*����Ա����*/
);

/*�洢����*/
USE [teachingManagementSystem]
GO
/****** Object:  StoredProcedure [dbo].[highgrade]    Script Date: 06/27/2017 21:46:30 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
/*���ڶ��ٷ���*/
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
/*С�ڶ��ٷ���*/
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