/*************************************************************************
 先把N个自然数按次序排列起来。1不是质数也不是合数，要划去。第二个数2是质数
 保留下来，而把2后面所有能被2整除的数都划去。2后面第一个没划去的数是3，把3
 留下，再把3后面所有能被3整除的数都划去。3后面第一个没划去的数是5，把5留下，
 再把5后面所有能被5整除的数都划去。这样一直下去，就会把不超过N的全部合数都
 筛选掉，留下的就是不超过N的全部质数。
 ************************************************************************/

#include<iostream>
#include <bitset>
#include <cmath>
using namespace std;

int main(){
    int const max_number(100);
    int const max_test((int)sqrt((double)max_number));
    bitset<max_number+1> numbers;
    numbers.set();//101个0
    //numbers[0]不用它
    numbers[1] = 0;
    for(int i(1); i!=max_test; ++i){
        if(numbers[i]){
            //筛掉倍数
            for(int j = i*i; j<max_number+1; j+=i){
                numbers[j] = 0;
            }
        }
    }
//任何非质数至少有一个因数不会大于它的平方根
    cout << "the num of primes less than" << max_number
        << "is" << numbers.count() << endl;

    for(int i(1); i!=max_number+1; ++i){
        if(numbers[i])
            cout << i << ",";
    }
    return 0;
}
