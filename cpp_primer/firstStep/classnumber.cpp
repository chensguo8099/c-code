/*************************************************************************
	> File Name: classnumber.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Nov 2017 02:52:29 AM PST
 ************************************************************************/
#include<iostream>
using namespace std;
int sum(int x, int y){
    return x + y;
}
//销售项目
class Sales_item{
    //private://类的数据成员
    public:
        //类成员函数
        //函数名末尾const说明是常成员函数，函数中不能对类的数据成员进行修改
        //bool same_isbn(const Sales_item &rhs) const {};
        bool same_isbn(const Sales_item &rhs) const {
            return this->isbn == rhs.isbn;
        }
        double avg_price() const;//函数声明

    public:
        std::string isbn;//书号
        unsigned units_sold;//数量
        double revenue;
};
double Sales_item::avg_price() const {
    if(this->units_sold)
        return this->revenue / this->units_sold;
    else
        return 0;
}
int main(){
    Sales_item item1, item2;

    item1.isbn = "0-201-78345-X";
    item1.units_sold = 10;
    item1.revenue = 300.00;
    cout << item1.avg_price() << endl;

    item2.isbn = "0-201-78345-X";
    item2.units_sold = 2;
    item2.revenue = 70.00;
    cout << item2.avg_price() << endl;

    if(item1.same_isbn(item2))
        cout << "这两个sales item是同一种书！" << endl;
    else
        cout << "这两本书不是同一本书！" << endl;

    return 0;
}
