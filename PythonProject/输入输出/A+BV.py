'''
题目描述
你的任务是计算两个整数的和。
输入描述
输入包含若干行,每行输入两个整数a和b,由空格分隔。
输出描述
对于每组输入,输出a和b的和,每行输出后接一个空行。
输入示例
2 4
11 19
输出示例
6

30

'''

while True:
    try:
        a, b = map(int, input().split())
        print(a + b)
        print()
    except:
        break