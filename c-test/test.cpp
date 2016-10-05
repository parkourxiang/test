/*************************************************************************
	> File Name: test.cpp
	> Author: laomao
	> Mail: 1531638007@qq.com 
	> Created Time: 2016年09月20日 星期二 18时20分38秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;



class FuncArray {

  public:
    FuncArray() {
	func_array.num = 0;
    } 
	void insert_func(void *func());
    void show_func(int num);

  private:
    struct {
	int num;
	void *(*func_list[]) ();
    } func_array;

};


void FuncArray::insert_func(void *func())
{
    func_array.func_list[func_array.num] = func;
    func_array.num += 1;
}


void FuncArray::show_func(int num)
{
    if (num > func_array.num) {
	printf("the num of you input is too large");
    } else {
	func_array.func_list[num] ();
    }
}

void *func_show_1()
{

    printf("------1------\n");

}


void *func_show_2()
{

    printf("------2------\n");

}


void *func_show_3()
{

    printf("------3------\n");

}


int main()
{


    FuncArray myFuncArray;

    myFuncArray.insert_func(func_show_1);
    myFuncArray.insert_func(func_show_2);
    myFuncArray.insert_func(func_show_3);

    myFuncArray.show_func(0);
    myFuncArray.show_func(1);
    myFuncArray.show_func(2);



    return 0;
}
