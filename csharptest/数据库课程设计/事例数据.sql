USE teachingManagementSystem;
GO

/*管理员账户注册*/
INSERT dbo.adminmsg VALUES('admin', 'admin'); /*管理员账号密码均为admin*/

/*插入系介绍*/
INSERT dbo.department(departmentName, departmentIntroduce)
VALUES('计算机科学与工程学院', '学院现有四个专业系，一个中心和一个省级重点实验室,即：计算机科学与技术系（智能计算研究所）、网络工程系（网络与信息安全研究所）、软件工程系（虚拟现实与可视化研究所）、物联网工程系（网络与软件新技术研究所）与陕西省实验教学示范中心、陕西省网络计算与安全技术重点实验室。设有计算机科学与技术、网络工程、软件工程以及物联网工程四个本科专业，具有计算机科学与技术学科（涵盖计算机系统结构、计算机软件与理论以及计算机应用技术三个二级硕士学科）和软件工程学科两个硕士学位一级授予权。此外，学院还具有计算机技术以及软件工程两个专业学位授予权，并培养计算机应用博士研究生（方向为：图像处理与模式识别、服务计算与网格技术、电力自动化、软件技术等）。')
GO
INSERT dbo.department(departmentName, departmentIntroduce)
VALUES('理学院', '全院设有3个系（应用数学系、应用物理系、应用化学系），3个中心（理学院实验中心、陕西省大学物理实验教学示范中心、陕西省军民两用超快光电研究中心），2个基地（化学化工与生物技术创新基地、数学建模基地），3个研究所。拥有 4个本科专业（信息与计算科学、应用物理、应用化学、制药工程），1个二级学科博士学位授权点，3个一级学科硕士学位授权点。');
GO
INSERT dbo.department(departmentName, departmentIntroduce)
VALUES('自动化与信息工程学院', '自动化与信息工程学院创建于1958年，有着悠久的办学历史和艰苦创业的光荣传统，现已发展成为我校集自动化、电气、电子及信息类专业于一体，专业面最宽，就业率最高，学生规模最大的学院之一 。学院目前设有自动化、电子信息工程、物联网工程、电气工程及智能控制、电气工程及其自动化、智能电网信息工程、电子科学与技术、通信工程、微电子科学与工程和集成电路设计与集成系统等10个本科专业，其中自动化专业和电子科学与技术专业为“国家级特色专业”和“陕西省普通高等学校本科名牌专业”，电气工程及其自动化专业为“国家级特色专业”，通信工程为“省级特色专业”');
GO
INSERT dbo.department(departmentName, departmentIntroduce)
VALUES('印刷包装与数字媒体学院', '西安理工大学印刷包装与数字媒体学院是我国最早成立并开展印刷包装类高等教育的院系之一，现为中国印刷及设备器材工业协会、中国印刷技术协会常务理事单位，中国印刷工程专业及包装工程专业教学指导委员会副主任单位。学院主要为印刷包装行业培养高级专门技术人才，现设有印刷工程、包装工程、电子信息工程(媒体处理技术)三个本科专业，均有学士学位授予权。其中印刷工程专业2005年被陕西省评为省级“名牌专业”');
GO
INSERT dbo.department(departmentName, departmentIntroduce)
VALUES('经济与管理学院', '西安理工大学经济与管理学院，学院前身为原北京机械学院工程管理系，于1958年开始招收经管类本科生，是我国高等工科院校中最早设置管理学科的院系之一。经过多年的发展，学院在教学、科研、师资队伍建设等方面都得到了长足的发展，形成了“开拓、进取、严谨、求实”的良好院风。学院设有工商管理、工业工程、市场营销、国际经济与贸易、会计学、金融学、信息管理与信息系统、电子商务等八个本科专业和相应的教学机构。经省政府批准成立的陕西城市战略研究所、西安技术经济研究会等机构也挂靠在我院。');
GO

/*插入学生数据*/
INSERT dbo.student(studentId, studentName, studentSex, studentPassword, studentBorntime, departmentId)
VALUES('gc123456', '郭晨', 1, '123456', '19961016', 1);
INSERT dbo.student(studentId, studentName, studentSex, studentPassword, studentBorntime, departmentId)
VALUES('lz123456', '刘卓', 1, '123456', '19960717', 3);
INSERT dbo.student(studentId, studentName, studentSex, studentPassword, studentBorntime, departmentId)
VALUES('lzh123456', '李志怀', 1, '123456', '19970213', 1);
INSERT dbo.student(studentId, studentName, studentSex, studentPassword, studentBorntime, departmentId)
VALUES('gtt123456', '高甜甜', 1, '123456', '19951116', 3);
INSERT dbo.student(studentId, studentName, studentSex, studentPassword, studentBorntime, departmentId)
VALUES('nxy123456', '南翔宇', 1, '123456', '19960507', 5);
INSERT dbo.student(studentId, studentName, studentSex, studentPassword, studentBorntime, departmentId)
VALUES('zcy123456', '张成渝', 1, '123456', '19960923', 4);
INSERT dbo.student(studentId, studentName, studentSex, studentPassword, studentBorntime, departmentId)
VALUES('ftm123456', '冯提莫', 0, '123456', '19980514', 5);
INSERT dbo.student(studentId, studentName, studentSex, studentPassword, studentBorntime, departmentId)
VALUES('zwq123456', '赵文倩', 0, '123456', '19970322', 5);
INSERT dbo.student(studentId, studentName, studentSex, studentPassword, studentBorntime, departmentId)
VALUES('sp123456', '孙蓬', 1, '123456', '19970116', 2);
INSERT dbo.student(studentId, studentName, studentSex, studentPassword, studentBorntime, departmentId)
VALUES('syj123456', '孙雨嘉', 1, '123456', '19950915', 4);
INSERT dbo.student(studentId, studentName, studentSex, studentPassword, studentBorntime, departmentId)
VALUES('yy123456', '姚烨', 0, '123456', '19971107', 5);
GO
/*郭晨1 刘卓2 李志怀3 高甜甜4 南翔宇5 张成渝6 冯提莫7 赵文倩8 孙蓬9 孙雨嘉10 姚烨11*/

/*插入课程*/
INSERT dbo.course(courseName, departmentId, coursePeriod, courseCredit, courseIntroduce)
VALUES('数据结构', 1, 55, 3.5, '
基本信息
课程名称：数据结构
课程类型：本科生必修课 
教学方式：课堂讲授
学生成绩评定方法：平时成绩40%，考试60%

教学目的
使学生较全面地理解算法和数据结构的概念、掌握各种数据结构与算法的实现方式，比较不同数据结构和算法的特点。通过学习，使学生不仅能学到数据结构与算法的基本知识，同时还能提高用计算机解决实际问题的能力。
本课程是一门理论与实践相结合的课程，要求学生在课堂学习的同时，完成适当的上机实习，实习与讲课的时间比不得小于1：1。本课程最后几周要求每个学生独立地完成一个较大的程序设计课题，并写出相应的课题报告，对自己的工作加以分析和总结。

内容提要
概论：算法概念，算法分析；数据结构概念、数据结构分类；数据结构要讨论的基本问题
线性表：线性表结构，顺序存储实现（顺序表），链接实现（链接表），应用
字符串*：字符串，基本操作，模式匹配，字符串的应用
堆栈与队列：堆栈的概念、和应用，队列的概念、实现和应用
树与二叉树：树、二叉树的概念和实现，各种遍历算法，Huffman树的概念及应用
字典与检索：字典与检索，静态字典，顺序检索，二分检索，分块检索*，最佳二叉排序树*，散列表、散列函数、碰撞处理，基于属性的检索*，倒排表与多重表*，动态字典的实现*，平衡二叉排序树*，B树与B+树*
结构：基本概念及术语，存储表示法，遍历，最小生成树，最短路径，拓扑排序*，关键路径*
稀疏矩阵和广义表*：多维数组和稀疏矩阵，稀疏矩阵，广义表
文件：外存及文件，顺序文件，索引文件，散列文件，倒排文件*
排序：排序的基本概念，选择排序、插入排序与冒泡排序，二分插入、Shell排序*、快速排序、堆排序*、归并排序*、基数排序*，排序算法的复杂性分析
存储管理*：存储管理中的问题，动态分配与回收，废料搜集，存储压缩
带*号的为选讲内容

参考书目
《数据结构》，许卓群、张乃孝、杨冬青、唐世渭，高等教育出版社　1987
《数据结构基础》，张乃孝等，北京大学出版社　1991
《数据结构－C++与面向对象程序设计》，张乃孝、裘宗燕，高等教育出版社 1998
《数据结构（C语言版）》，严蔚敏等，清华大学出版社 1997');

INSERT dbo.course(courseName, departmentId, coursePeriod, courseCredit, courseIntroduce)
VALUES('软件开发技术', 1, 45, 2.0, '
一、课程介绍
（一）简介
本课程是面向机械系本科生。介绍了当代软件开发基本思想：面向对象，模块化，封装，抽象化与测试。系统化学习结构化分析与设计方法、面向对象分析与设计方法。
培养学生工程化的建模思维，为今后从事应用软件的开发奠定基础。
二、教学目标
（一）学习目标
掌握软件开发的基本过程；掌握需求分析的方法和过程，学会利用数据流图或用例模型对特定问题进行需求建模；了解结构化设计方法的任务和内容，掌握模块化设计的内涵和评价指标，学习并掌握利用程序结构图进行结构化程序设计；了解面向对象方法的概念和内涵，学习并掌握面向对象模型的核心要素；学习UML统一建模语言，掌握功能模型、对象模型、动态模型等；学习面向对象的分析方法，掌握利用面向对象的方法进行建模分析；学习面向对象的设计方法，掌握利用面向对象的方法进行系统设计和类模型设计；了解程序编码、测试和维护过程的手段和方法。
（二）可测量结果
通过课堂讨论、课程作业以及笔试等环节测量达到上述教学目标。');
INSERT dbo.course(courseName, departmentId, coursePeriod, courseCredit, courseIntroduce)
VALUES('数学分析', 2, 60, 4.0, '');
INSERT dbo.course(courseName, departmentId, coursePeriod, courseCredit, courseIntroduce)
VALUES('数学文化', 2, 30, 1.5, '');
INSERT dbo.course(courseName, departmentId, coursePeriod, courseCredit, courseIntroduce)
VALUES('大学化学', 2, 55, 3.5, '');
INSERT dbo.course(courseName, departmentId, coursePeriod, courseCredit, courseIntroduce)
VALUES('经济学', 5, 50, 3.5, '');
INSERT dbo.course(courseName, departmentId, coursePeriod, courseCredit, courseIntroduce)
VALUES('管理学', 5, 35, 1.5, '');
INSERT dbo.course(courseName, departmentId, coursePeriod, courseCredit, courseIntroduce)
VALUES('信号与系统', 4, 45, 2.0, '');
INSERT dbo.course(courseName, departmentId, coursePeriod, courseCredit, courseIntroduce)
VALUES('数字电路与逻辑设计', 3, 55, 2.5, '');
INSERT dbo.course(courseName, departmentId, coursePeriod, courseCredit, courseIntroduce)
VALUES('电路与电子技术', 3, 55, 2.5, '');
INSERT dbo.course(courseName, departmentId, coursePeriod, courseCredit, courseIntroduce)
VALUES('C++程序设计', 3, 55, 2.5, '');
/*数据结构1 软件开发技术2 数学分析3 数学文化4 大学化学5 经济学6 管理学7 信号与系统8 数字电路与逻辑设计9 电路与电子技术10 C++程序设计*/
GO

/*教师表*/
INSERT dbo.teacher(teacherId, teacherName, teacherSex, teacherPassword, departmentId)
VALUES('sx123456', '宋昕老师', 1, '123456', 1);
INSERT dbo.teacher(teacherId, teacherName, teacherSex, teacherPassword, departmentId)
VALUES('xn123456', '邢楠老师', 1, '123456', 3);
INSERT dbo.teacher(teacherId, teacherName, teacherSex, teacherPassword, departmentId)
VALUES('lw123456', '李薇老师', 0, '123456', 1);
INSERT dbo.teacher(teacherId, teacherName, teacherSex, teacherPassword, departmentId)
VALUES('xxl123456', '谢兴龙老师', 1, '123456', 5);
INSERT dbo.teacher(teacherId, teacherName, teacherSex, teacherPassword, departmentId)
VALUES('rdd123456', '阮东东老师', 1, '123456', 2);
INSERT dbo.teacher(teacherId, teacherName, teacherSex, teacherPassword, departmentId)
VALUES('txh123456', '童小红老师', 1, '123456', 2);
INSERT dbo.teacher(teacherId, teacherName, teacherSex, teacherPassword, departmentId)
VALUES('pl123456', '庞兰老师', 0, '123456', 5);
INSERT dbo.teacher(teacherId, teacherName, teacherSex, teacherPassword, departmentId)
VALUES('chy123456', '曹海宇老师', 1, '123456', 4);
GO

/*数据结构1 软件开发技术2 数学分析3 数学文化4 大学化学5 经济学6 管理学7 信号与系统8 数字电路与逻辑设计9 电路与电子技术10 C++程序设计*/
/*授课表*/
INSERT dbo.givecourse(teacherId, courseId) VALUES('sx123456', 1);
INSERT dbo.givecourse(teacherId, courseId) VALUES('sx123456', 2);
INSERT dbo.givecourse(teacherId, courseId) VALUES('lw123456', 1);
INSERT dbo.givecourse(teacherId, courseId) VALUES('lw123456', 2);
INSERT dbo.givecourse(teacherId, courseId) VALUES('xxl123456', 6);
INSERT dbo.givecourse(teacherId, courseId) VALUES('xxl123456', 7);
INSERT dbo.givecourse(teacherId, courseId) VALUES('rdd123456', 2);
INSERT dbo.givecourse(teacherId, courseId) VALUES('txh123456', 3);
INSERT dbo.givecourse(teacherId, courseId) VALUES('txh123456', 4);
INSERT dbo.givecourse(teacherId, courseId) VALUES('chy123456', 5);
INSERT dbo.givecourse(teacherId, courseId) VALUES('pl123456', 5);
INSERT dbo.givecourse(teacherId, courseId) VALUES('pl123456', 6);
INSERT dbo.givecourse(teacherId, courseId) VALUES('xn123456', 8);
INSERT dbo.givecourse(teacherId, courseId) VALUES('txh123456', 9);
INSERT dbo.givecourse(teacherId, courseId) VALUES('txh123456', 10);
INSERT dbo.givecourse(teacherId, courseId) VALUES('lw123456', 11);
GO

/*选课表*/
INSERT dbo.selectcourse(studentId, courseId, teacherId, courseGrade) VALUES('gc123456', 1, 'sx123456', 90);
INSERT dbo.selectcourse(studentId, courseId, teacherId, courseGrade) VALUES('gc123456', 2, 'xn123456', 85);
INSERT dbo.selectcourse(studentId, courseId, teacherId, courseGrade) VALUES('lz123456', 9, 'lw123456', 77);
INSERT dbo.selectcourse(studentId, courseId, teacherId, courseGrade) VALUES('lz123456', 10, 'rdd123456', 93);
INSERT dbo.selectcourse(studentId, courseId, teacherId, courseGrade) VALUES('gtt123456', 9, 'rdd123456', 62);
INSERT dbo.selectcourse(studentId, courseId, teacherId, courseGrade) VALUES('nxy123456', 6, 'xxl123456', 75);
INSERT dbo.selectcourse(studentId, courseId, teacherId, courseGrade) VALUES('nxy123456', 7, 'pl123456', 43);
INSERT dbo.selectcourse(studentId, courseId, teacherId, courseGrade) VALUES('zcy123456', 8, 'xn123456', 55);
INSERT dbo.selectcourse(studentId, courseId, teacherId, courseGrade) VALUES('gtt123456', 10, 'txh123456', 92);
INSERT dbo.selectcourse(studentId, courseId, teacherId, courseGrade) VALUES('ftm123456', 6, 'pl123456', 35);
INSERT dbo.selectcourse(studentId, courseId, teacherId, courseGrade) VALUES('ftm123456', 7, 'pl123456', 59);
INSERT dbo.selectcourse(studentId, courseId, teacherId, courseGrade) VALUES('zwq123456', 6, 'xxl123456', 47);
INSERT dbo.selectcourse(studentId, courseId, teacherId, courseGrade) VALUES('zwq123456', 7, 'xxl123456', 89);
INSERT dbo.selectcourse(studentId, courseId, teacherId, courseGrade) VALUES('sp123456', 3, 'txh123456', 71);
INSERT dbo.selectcourse(studentId, courseId, teacherId, courseGrade) VALUES('sp123456', 4, 'txh123456', 67);
INSERT dbo.selectcourse(studentId, courseId, teacherId, courseGrade) VALUES('syj123456', 8, 'xn123456', 64);
INSERT dbo.selectcourse(studentId, courseId, teacherId, courseGrade) VALUES('yy123456', 9, 'txh123456', 49);
INSERT dbo.selectcourse(studentId, courseId, teacherId, courseGrade) VALUES('yy123456', 10, 'txh123456', 55);
GO
/*数据结构1 软件开发技术2 数学分析3 数学文化4 大学化学5 经济学6 管理学7 信号与系统8 数字电路与逻辑设计9 电路与电子技术10 C++程序设计*/

/*评论表*//*郭晨1 刘卓2 李志怀3 高甜甜4 南翔宇5 张成渝6 冯提莫7 赵文倩8 孙蓬9 孙雨嘉10 姚烨11*/
/*宋昕1 邢楠2 李薇3 谢兴龙4 阮东东5 童小红6 庞兰7 曹海宇8*/
INSERT dbo.comment(studentId, teacherId) VALUES('gc123456', 'sx123456');
INSERT dbo.comment(studentId, teacherId) VALUES('gc123456', 'xn123456');
INSERT dbo.comment(studentId, teacherId) VALUES('lz123456', 'txh123456')
INSERT dbo.comment(studentId, teacherId) VALUES('lz123456', 'rdd123456')
INSERT dbo.comment(studentId, teacherId) VALUES('gtt123456', 'rdd123456')
INSERT dbo.comment(studentId, teacherId) VALUES('nxy123456', 'xxl123456')
INSERT dbo.comment(studentId, teacherId) VALUES('nxy123456', 'pl123456')
INSERT dbo.comment(studentId, teacherId) VALUES('zcy123456', 'xn123456')
INSERT dbo.comment(studentId, teacherId) VALUES('gtt123456', 'txh123456')
INSERT dbo.comment(studentId, teacherId) VALUES('ftm123456', 'pl123456')
INSERT dbo.comment(studentId, teacherId) VALUES('ftm123456', 'pl123456')
INSERT dbo.comment(studentId, teacherId) VALUES('zwq123456', 'xxl123456')
INSERT dbo.comment(studentId, teacherId) VALUES('zwq123456', 'xxl123456')
INSERT dbo.comment(studentId, teacherId) VALUES('sp123456', 'txh123456')
INSERT dbo.comment(studentId, teacherId) VALUES('sp123456', 'txh123456')
INSERT dbo.comment(studentId, teacherId) VALUES('syj123456', 'xn123456')
INSERT dbo.comment(studentId, teacherId) VALUES('yy123456', 'txh123456')
INSERT dbo.comment(studentId, teacherId) VALUES('yy123456', 'txh123456')

