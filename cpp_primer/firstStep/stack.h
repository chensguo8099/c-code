/*************************************************************************
	> File Name: stack.h
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Nov 2017 04:36:34 PM PST
 ************************************************************************/

#ifndef _STACK_H
#define _STACK_H

#include <deque>
#include <exception>

template<class T>
class Stack{
    protected:
    std::deque<T> c;

    public:
    class ReadEmptyStack : public std::exception{
        public:
        virtual const char *what() const throw(){
            return "read empty stack 堆栈是空的";
        }
    };

    bool empty() const{
        return c.empty();
    }

    void push(const T& elem){
        c.push_back(elem);
    }

    T pop(){
        if(c.empty()){
            throw ReadEmptyStack();
        }
        T elem(c.back());
        c.pop_back();
        return elem;
    }
    T top(){
        if(c.empty()){
            throw ReadEmptyStack();
        }
        return c.back();
    }
};

#endif
