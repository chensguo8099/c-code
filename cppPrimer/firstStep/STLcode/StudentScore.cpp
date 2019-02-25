/*
    > File Name: StudentScore.cpp
    > Author: JerryChen
    > Created Time: 2019年02月25日 星期一 17时52分37秒
*/

/*
*学生打分
去掉一个最高分和一个最低分
取平均分，排序由大到小输出
* */
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Student{
    public:
    Student(){}
    Student(string name, double score):_name(name), _score(score){}
    public:
    string _name;
    int _score;
};

void createStudentInfo(vector<Student> &v){
    string numName = "ABCDEFG";
    for(int i = 0; i < 7; i++){
        Student stu;
        stu._name = "选手";
        stu._name += numName[i];
        stu._score = 0;

        v.push_back(stu);
    }
}

void setAverageScore(vector<Student> &v){
    int sum = 0;
    for(vector<Student>::iterator it = v.begin(); it != v.end(); it++){
        deque<int> avg;
        for(int i = 0; i < 10; i++){
            avg.push_back(rand()%41 + 60);
            sum += avg[i];
        }
        sort(avg.begin(), avg.end());
        avg.pop_front();//去掉一个最高分
        avg.pop_back();//去掉一个最低分

        int avgScore = sum / avg.size();
        (*it)._score = avgScore;

        for(deque<int>::iterator dit = avg.begin(); dit != avg.end(); dit++){
            cout << *dit << " ";
        }
        cout << " 平均分:" << avgScore << endl;
        sum = 0;
    }
}

bool compare(Student &a1, Student &a2){
    return a1._score > a2._score;
}

void printStudentScore(vector<Student> &v){
    sort(v.begin(), v.end(), compare);
    for(vector<Student>::iterator it = v.begin(); it != v.end(); it++){
        cout << "学生姓名：" << (*it)._name << " 成绩：" << (*it)._score << endl;
    }
}

int main(){
    vector<Student> v;
    createStudentInfo(v);
    setAverageScore(v);
    printStudentScore(v);

    return 0;
}
