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
void run();
void basic_training();
void advanced_training();

//addition
void addition();
BOOL give_one_addition(int range);

//subtraction
void subtraction();
BOOL give_one_subtraction(int range);

//multiplication
void multiplication();
BOOL give_one_multiplication(int range);

//division
void division();
BOOL give_one_division(int range);

//files
void mistake_input_add(int a,int b,int c);
void mistake_input_sub(int a,int b,int c);
void mistake_input_mult(int a,int b,int c);
void mistake_input_div(int a,int b,int c);
void mistake_read_and_copy(int number);
int get_num_of_mistakes();

//time_limited
void time_limited();

//mixed
void mixed();

//mistakes
void mistakes();
BOOL give_one_mistake(int num);

#endif // !_MATHEMATIC_ASSISTANCE_SYSTEMS_FOR_YOUNG_CHILDREN_H_