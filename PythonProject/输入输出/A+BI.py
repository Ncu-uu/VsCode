"""
你的任务是计算a+b。

输入描述
输入包含一系列的a和b对,通过空格隔开。一对a和b占一行。

输出描述
对于输入的每对a和b,你需要依次输出a、b的和。

如对于输入中的第二对a和b,在输出中它们的和应该也在第二行。

输入示例
3 4
11 40
输出示例
7
51

"""
while True:
    try:
        a, b = map(int, input().split())
        print(a + b)
    except:
        break