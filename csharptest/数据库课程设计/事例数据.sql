USE teachingManagementSystem;
GO

/*����Ա�˻�ע��*/
INSERT dbo.adminmsg VALUES('admin', 'admin'); /*����Ա�˺������Ϊadmin*/

/*����ϵ����*/
INSERT dbo.department(departmentName, departmentIntroduce)
VALUES('�������ѧ�빤��ѧԺ', 'ѧԺ�����ĸ�רҵϵ��һ�����ĺ�һ��ʡ���ص�ʵ����,�����������ѧ�뼼��ϵ�����ܼ����о����������繤��ϵ����������Ϣ��ȫ�о��������������ϵ��������ʵ����ӻ��о�����������������ϵ������������¼����о�����������ʡʵ���ѧʾ�����ġ�����ʡ��������밲ȫ�����ص�ʵ���ҡ����м������ѧ�뼼�������繤�̡���������Լ������������ĸ�����רҵ�����м������ѧ�뼼��ѧ�ƣ����Ǽ����ϵͳ�ṹ�����������������Լ������Ӧ�ü�����������˶ʿѧ�ƣ����������ѧ������˶ʿѧλһ������Ȩ�����⣬ѧԺ�����м���������Լ������������רҵѧλ����Ȩ�������������Ӧ�ò�ʿ�о���������Ϊ��ͼ������ģʽʶ�𡢷���������������������Զ�������������ȣ���')
GO
INSERT dbo.department(departmentName, departmentIntroduce)
VALUES('��ѧԺ', 'ȫԺ����3��ϵ��Ӧ����ѧϵ��Ӧ������ϵ��Ӧ�û�ѧϵ����3�����ģ���ѧԺʵ�����ġ�����ʡ��ѧ����ʵ���ѧʾ�����ġ�����ʡ�������ó������о����ģ���2�����أ���ѧ���������＼�����»��ء���ѧ��ģ���أ���3���о�����ӵ�� 4������רҵ����Ϣ������ѧ��Ӧ������Ӧ�û�ѧ����ҩ���̣���1������ѧ�Ʋ�ʿѧλ��Ȩ�㣬3��һ��ѧ��˶ʿѧλ��Ȩ�㡣');
GO
INSERT dbo.department(departmentName, departmentIntroduce)
VALUES('�Զ�������Ϣ����ѧԺ', '�Զ�������Ϣ����ѧԺ������1958�꣬�����ƾõİ�ѧ��ʷ�ͼ�ഴҵ�Ĺ��ٴ�ͳ�����ѷ�չ��Ϊ��У���Զ��������������Ӽ���Ϣ��רҵ��һ�壬רҵ�������ҵ����ߣ�ѧ����ģ����ѧԺ֮һ ��ѧԺĿǰ�����Զ�����������Ϣ���̡����������̡��������̼����ܿ��ơ��������̼����Զ��������ܵ�����Ϣ���̡����ӿ�ѧ�뼼����ͨ�Ź��̡�΢���ӿ�ѧ�빤�̺ͼ��ɵ�·����뼯��ϵͳ��10������רҵ�������Զ���רҵ�͵��ӿ�ѧ�뼼��רҵΪ�����Ҽ���ɫרҵ���͡�����ʡ��ͨ�ߵ�ѧУ��������רҵ�����������̼����Զ���רҵΪ�����Ҽ���ɫרҵ����ͨ�Ź���Ϊ��ʡ����ɫרҵ��');
GO
INSERT dbo.department(departmentName, departmentIntroduce)
VALUES('ӡˢ��װ������ý��ѧԺ', '��������ѧӡˢ��װ������ý��ѧԺ���ҹ������������չӡˢ��װ��ߵȽ�����Ժϵ֮һ����Ϊ�й�ӡˢ���豸���Ĺ�ҵЭ�ᡢ�й�ӡˢ����Э�᳣�����µ�λ���й�ӡˢ����רҵ����װ����רҵ��ѧָ��ίԱ�ḱ���ε�λ��ѧԺ��ҪΪӡˢ��װ��ҵ�����߼�ר�ż����˲ţ�������ӡˢ���̡���װ���̡�������Ϣ����(ý�崦����)��������רҵ������ѧʿѧλ����Ȩ������ӡˢ����רҵ2005�걻����ʡ��Ϊʡ��������רҵ��');
GO
INSERT dbo.department(departmentName, departmentIntroduce)
VALUES('���������ѧԺ', '��������ѧ���������ѧԺ��ѧԺǰ��Ϊԭ������еѧԺ���̹���ϵ����1958�꿪ʼ���վ����౾���������ҹ��ߵȹ���ԺУ���������ù���ѧ�Ƶ�Ժϵ֮һ����������ķ�չ��ѧԺ�ڽ�ѧ�����С�ʦ�ʶ��齨��ȷ��涼�õ��˳���ķ�չ���γ��ˡ����ء���ȡ���Ͻ�����ʵ��������Ժ�硣ѧԺ���й��̹�����ҵ���̡��г�Ӫ�������ʾ�����ó�ס����ѧ������ѧ����Ϣ��������Ϣϵͳ����������Ȱ˸�����רҵ����Ӧ�Ľ�ѧ��������ʡ������׼��������������ս���о������������������о���Ȼ���Ҳ�ҿ�����Ժ��');
GO

/*����ѧ������*/
INSERT dbo.student(studentId, studentName, studentSex, studentPassword, studentBorntime, departmentId)
VALUES('gc123456', '����', 1, '123456', '19961016', 1);
INSERT dbo.student(studentId, studentName, studentSex, studentPassword, studentBorntime, departmentId)
VALUES('lz123456', '��׿', 1, '123456', '19960717', 3);
INSERT dbo.student(studentId, studentName, studentSex, studentPassword, studentBorntime, departmentId)
VALUES('lzh123456', '��־��', 1, '123456', '19970213', 1);
INSERT dbo.student(studentId, studentName, studentSex, studentPassword, studentBorntime, departmentId)
VALUES('gtt123456', '������', 1, '123456', '19951116', 3);
INSERT dbo.student(studentId, studentName, studentSex, studentPassword, studentBorntime, departmentId)
VALUES('nxy123456', '������', 1, '123456', '19960507', 5);
INSERT dbo.student(studentId, studentName, studentSex, studentPassword, studentBorntime, departmentId)
VALUES('zcy123456', '�ų���', 1, '123456', '19960923', 4);
INSERT dbo.student(studentId, studentName, studentSex, studentPassword, studentBorntime, departmentId)
VALUES('ftm123456', '����Ī', 0, '123456', '19980514', 5);
INSERT dbo.student(studentId, studentName, studentSex, studentPassword, studentBorntime, departmentId)
VALUES('zwq123456', '����ٻ', 0, '123456', '19970322', 5);
INSERT dbo.student(studentId, studentName, studentSex, studentPassword, studentBorntime, departmentId)
VALUES('sp123456', '����', 1, '123456', '19970116', 2);
INSERT dbo.student(studentId, studentName, studentSex, studentPassword, studentBorntime, departmentId)
VALUES('syj123456', '�����', 1, '123456', '19950915', 4);
INSERT dbo.student(studentId, studentName, studentSex, studentPassword, studentBorntime, departmentId)
VALUES('yy123456', 'Ҧ��', 0, '123456', '19971107', 5);
GO
/*����1 ��׿2 ��־��3 ������4 ������5 �ų���6 ����Ī7 ����ٻ8 ����9 �����10 Ҧ��11*/

/*����γ�*/
INSERT dbo.course(courseName, departmentId, coursePeriod, courseCredit, courseIntroduce)
VALUES('���ݽṹ', 1, 55, 3.5, '
������Ϣ
�γ����ƣ����ݽṹ
�γ����ͣ����������޿� 
��ѧ��ʽ�����ý���
ѧ���ɼ�����������ƽʱ�ɼ�40%������60%

��ѧĿ��
ʹѧ����ȫ�������㷨�����ݽṹ�ĸ�����ո������ݽṹ���㷨��ʵ�ַ�ʽ���Ƚϲ�ͬ���ݽṹ���㷨���ص㡣ͨ��ѧϰ��ʹѧ��������ѧ�����ݽṹ���㷨�Ļ���֪ʶ��ͬʱ��������ü�������ʵ�������������
���γ���һ��������ʵ�����ϵĿγ̣�Ҫ��ѧ���ڿ���ѧϰ��ͬʱ������ʵ����ϻ�ʵϰ��ʵϰ�뽲�ε�ʱ��Ȳ���С��1��1�����γ������Ҫ��ÿ��ѧ�����������һ���ϴ�ĳ�����ƿ��⣬��д����Ӧ�Ŀ��ⱨ�棬���Լ��Ĺ������Է������ܽᡣ

������Ҫ
���ۣ��㷨����㷨���������ݽṹ������ݽṹ���ࣻ���ݽṹҪ���۵Ļ�������
���Ա����Ա�ṹ��˳��洢ʵ�֣�˳���������ʵ�֣����ӱ���Ӧ��
�ַ���*���ַ���������������ģʽƥ�䣬�ַ�����Ӧ��
��ջ����У���ջ�ĸ����Ӧ�ã����еĸ��ʵ�ֺ�Ӧ��
����������������������ĸ����ʵ�֣����ֱ����㷨��Huffman���ĸ��Ӧ��
�ֵ���������ֵ����������̬�ֵ䣬˳����������ּ������ֿ����*����Ѷ���������*��ɢ�б�ɢ�к�������ײ�����������Եļ���*�����ű�����ر�*����̬�ֵ��ʵ��*��ƽ�����������*��B����B+��*
�ṹ�������������洢��ʾ������������С�����������·������������*���ؼ�·��*
ϡ�����͹����*����ά�����ϡ�����ϡ����󣬹����
�ļ�����漰�ļ���˳���ļ��������ļ���ɢ���ļ��������ļ�*
��������Ļ������ѡ�����򡢲���������ð�����򣬶��ֲ��롢Shell����*���������򡢶�����*���鲢����*����������*�������㷨�ĸ����Է���
�洢����*���洢�����е����⣬��̬��������գ������Ѽ����洢ѹ��
��*�ŵ�Ϊѡ������

�ο���Ŀ
�����ݽṹ������׿Ⱥ������Т����ࡢ����μ���ߵȽ��������硡1987
�����ݽṹ������������Т�ȣ�������ѧ�����硡1991
�����ݽṹ��C++��������������ơ�������Т�������࣬�ߵȽ��������� 1998
�����ݽṹ��C���԰棩������ε���ȣ��廪��ѧ������ 1997');

INSERT dbo.course(courseName, departmentId, coursePeriod, courseCredit, courseIntroduce)
VALUES('�����������', 1, 45, 2.0, '
һ���γ̽���
��һ�����
���γ��������еϵ�������������˵��������������˼�룺�������ģ�黯����װ����������ԡ�ϵͳ��ѧϰ�ṹ����������Ʒ�������������������Ʒ�����
����ѧ�����̻��Ľ�ģ˼ά��Ϊ������Ӧ������Ŀ����춨������
������ѧĿ��
��һ��ѧϰĿ��
������������Ļ������̣�������������ķ����͹��̣�ѧ������������ͼ������ģ�Ͷ��ض������������ģ���˽�ṹ����Ʒ�������������ݣ�����ģ�黯��Ƶ��ں�������ָ�꣬ѧϰ���������ó���ṹͼ���нṹ��������ƣ��˽�������󷽷��ĸ�����ں���ѧϰ�������������ģ�͵ĺ���Ҫ�أ�ѧϰUMLͳһ��ģ���ԣ����չ���ģ�͡�����ģ�͡���̬ģ�͵ȣ�ѧϰ�������ķ������������������������ķ������н�ģ������ѧϰ����������Ʒ��������������������ķ�������ϵͳ��ƺ���ģ����ƣ��˽������롢���Ժ�ά�����̵��ֶκͷ�����
�������ɲ������
ͨ���������ۡ��γ���ҵ�Լ����ԵȻ��ڲ����ﵽ������ѧĿ�ꡣ');
INSERT dbo.course(courseName, departmentId, coursePeriod, courseCredit, courseIntroduce)
VALUES('��ѧ����', 2, 60, 4.0, '');
INSERT dbo.course(courseName, departmentId, coursePeriod, courseCredit, courseIntroduce)
VALUES('��ѧ�Ļ�', 2, 30, 1.5, '');
INSERT dbo.course(courseName, departmentId, coursePeriod, courseCredit, courseIntroduce)
VALUES('��ѧ��ѧ', 2, 55, 3.5, '');
INSERT dbo.course(courseName, departmentId, coursePeriod, courseCredit, courseIntroduce)
VALUES('����ѧ', 5, 50, 3.5, '');
INSERT dbo.course(courseName, departmentId, coursePeriod, courseCredit, courseIntroduce)
VALUES('����ѧ', 5, 35, 1.5, '');
INSERT dbo.course(courseName, departmentId, coursePeriod, courseCredit, courseIntroduce)
VALUES('�ź���ϵͳ', 4, 45, 2.0, '');
INSERT dbo.course(courseName, departmentId, coursePeriod, courseCredit, courseIntroduce)
VALUES('���ֵ�·���߼����', 3, 55, 2.5, '');
INSERT dbo.course(courseName, departmentId, coursePeriod, courseCredit, courseIntroduce)
VALUES('��·����Ӽ���', 3, 55, 2.5, '');
INSERT dbo.course(courseName, departmentId, coursePeriod, courseCredit, courseIntroduce)
VALUES('C++�������', 3, 55, 2.5, '');
/*���ݽṹ1 �����������2 ��ѧ����3 ��ѧ�Ļ�4 ��ѧ��ѧ5 ����ѧ6 ����ѧ7 �ź���ϵͳ8 ���ֵ�·���߼����9 ��·����Ӽ���10 C++�������*/
GO

/*��ʦ��*/
INSERT dbo.teacher(teacherId, teacherName, teacherSex, teacherPassword, departmentId)
VALUES('sx123456', '�����ʦ', 1, '123456', 1);
INSERT dbo.teacher(teacherId, teacherName, teacherSex, teacherPassword, departmentId)
VALUES('xn123456', '�����ʦ', 1, '123456', 3);
INSERT dbo.teacher(teacherId, teacherName, teacherSex, teacherPassword, departmentId)
VALUES('lw123456', '��ޱ��ʦ', 0, '123456', 1);
INSERT dbo.teacher(teacherId, teacherName, teacherSex, teacherPassword, departmentId)
VALUES('xxl123456', 'л������ʦ', 1, '123456', 5);
INSERT dbo.teacher(teacherId, teacherName, teacherSex, teacherPassword, departmentId)
VALUES('rdd123456', '�����ʦ', 1, '123456', 2);
INSERT dbo.teacher(teacherId, teacherName, teacherSex, teacherPassword, departmentId)
VALUES('txh123456', 'ͯС����ʦ', 1, '123456', 2);
INSERT dbo.teacher(teacherId, teacherName, teacherSex, teacherPassword, departmentId)
VALUES('pl123456', '������ʦ', 0, '123456', 5);
INSERT dbo.teacher(teacherId, teacherName, teacherSex, teacherPassword, departmentId)
VALUES('chy123456', '�ܺ�����ʦ', 1, '123456', 4);
GO

/*���ݽṹ1 �����������2 ��ѧ����3 ��ѧ�Ļ�4 ��ѧ��ѧ5 ����ѧ6 ����ѧ7 �ź���ϵͳ8 ���ֵ�·���߼����9 ��·����Ӽ���10 C++�������*/
/*�ڿα�*/
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

/*ѡ�α�*/
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
/*���ݽṹ1 �����������2 ��ѧ����3 ��ѧ�Ļ�4 ��ѧ��ѧ5 ����ѧ6 ����ѧ7 �ź���ϵͳ8 ���ֵ�·���߼����9 ��·����Ӽ���10 C++�������*/

/*���۱�*//*����1 ��׿2 ��־��3 ������4 ������5 �ų���6 ����Ī7 ����ٻ8 ����9 �����10 Ҧ��11*/
/*���1 ���2 ��ޱ3 л����4 ���5 ͯС��6 ����7 �ܺ���8*/
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

