#ifndef _MATHEMATIC_ASSISTANCE_SYSTEMS_FOR_YOUNG_CHILDREN_H_
#define _MATHEMATIC_ASSISTANCE_SYSTEMS_FOR_YOUNG_CHILDREN_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

//run
void run();                 //运行程序，主菜单
void basic_training();      //基础训练子菜单
void advanced_training();   //进阶训练子菜单

//addition
void addition();                    //加法训练
BOOL give_one_addition(int range);  //生成一个加法题目并判断对错,将错题写入错题本

//subtraction
void subtraction();                     //减法训练
BOOL give_one_subtraction(int range);   //生成一个减法题目并判断对错,将错题写入错题本

//multiplication
void multiplication();                      //乘法训练
BOOL give_one_multiplication(int range);    //生成一个乘法题目并判断对错,将错题写入错题本

//division
void division();                            //除法训练
BOOL give_one_division(int range);          //生成一个除法题目并判断对错,将错题写入错题本

//files
void mistake_input_add(int a,int b,int c);  //将加法错题加入tmp.txt
void mistake_input_sub(int a,int b,int c);  //将减法错题加入tmp.txt
void mistake_input_mult(int a,int b,int c); //将乘法错题加入tmp.txt
void mistake_input_div(int a,int b,int c);  //将除法错题加入tmp.txt
void mistake_read_and_copy(int number);     //将tmp.txt的错题输出并加入mistakes.txt
int get_num_of_mistakes();                  //获取mistakes.txt的行数，即错题数

//time_limited
void time_limited();    //限时训练

//mixed
void mixed();           //混合训练

//mistakes
void mistakes();                //错题训练
BOOL give_one_mistake(int num); //从错题本抽取一个题目并判断对错

#endif // !_MATHEMATIC_ASSISTANCE_SYSTEMS_FOR_YOUNG_CHILDREN_H_