'''
题目描述
你的任务依然是计算a+b。

输入描述
输入中每行是一对a和b。其中会有一对是0和0标志着输入结束,且这一对不要计算。

输出描述
对于输入的每对a和b,你需要在相应的行输出a、b的和。
如第二对a和b,他们的和也输出在第二行。
输入示例
2 4
11 19
0 0
,
6
30
'''

while True:
    try:
        a, b = map(int, input().split())
        if a == 0 and b == 0:
            break
        print(a + b)
    except:
        break