/*
幼儿数学辅助学习系统的总体目标是：
在计算机C语言的开发平台上，分析和设计一个具有良好人机交互界面的幼儿数学辅助学习系统，
系统内容覆盖不同难度的加减乘除算法，深入浅出，各个学习模块均以寓教于乐的方式进行。
1、根据系统的要求，功能必须包括：
    题型题量数据大小的选择、
    根据选项要求自动出题、
    对答案进行判断、
    最后给出评分等。
    其中：
    题型题量数据大小的选择：包括加减乘除算法选择、题量多少选择、学习的数据范围选择等常用操作；
自动出题：根据题型和数据范围采用随机数产生函数自动生成题目由用户输入答案，系统设计中要注意题目的有效性，如减法的被减数需大于等于减数、除法需能整除且除数不能为0；
答案判断：对用户给定的答案进行判断并给出对错结论，若答案错误应能给出正确答案提示；
评分设置：对用户正确答案进行统计并给出最终评分。×
2、整个系统使用C语言开发，人机界面提示语句尽量轻松活泼，提升幼儿学习兴趣；
3、系统除要求的基本功能外还可以进行功能扩充，如建立一个错题本，将做错的题目存储在文件中，在以后可以重复提取给用户，以帮助用户有目的学习等，功能的扩充由同学根据自己的能力和时间自由添加；
*/
#include "Mathematic_assistance_systems_for_young_children.h"

int main(){
    mistake();
    return 0;
}