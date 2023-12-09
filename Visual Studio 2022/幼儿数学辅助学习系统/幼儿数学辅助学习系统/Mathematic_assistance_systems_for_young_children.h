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
void run();                 //���г������˵�
void basic_training();      //����ѵ���Ӳ˵�
void advanced_training();   //����ѵ���Ӳ˵�

//addition
void addition();                    //�ӷ�ѵ��
BOOL give_one_addition(int range);  //����һ���ӷ���Ŀ���ж϶Դ�,������д����Ȿ

//subtraction
void subtraction();                     //����ѵ��
BOOL give_one_subtraction(int range);   //����һ��������Ŀ���ж϶Դ�,������д����Ȿ

//multiplication
void multiplication();                      //�˷�ѵ��
BOOL give_one_multiplication(int range);    //����һ���˷���Ŀ���ж϶Դ�,������д����Ȿ

//division
void division();                            //����ѵ��
BOOL give_one_division(int range);          //����һ��������Ŀ���ж϶Դ�,������д����Ȿ

//files
void mistake_input_add(int a,int b,int c);  //���ӷ��������tmp.txt
void mistake_input_sub(int a,int b,int c);  //�������������tmp.txt
void mistake_input_mult(int a,int b,int c); //���˷��������tmp.txt
void mistake_input_div(int a,int b,int c);  //�������������tmp.txt
void mistake_read_and_copy(int number);     //��tmp.txt�Ĵ������������mistakes.txt
int get_num_of_mistakes();                  //��ȡmistakes.txt����������������

//time_limited
void time_limited();    //��ʱѵ��

//mixed
void mixed();           //���ѵ��

//mistakes
void mistakes();                //����ѵ��
BOOL give_one_mistake(int num); //�Ӵ��Ȿ��ȡһ����Ŀ���ж϶Դ�

#endif // !_MATHEMATIC_ASSISTANCE_SYSTEMS_FOR_YOUNG_CHILDREN_H_