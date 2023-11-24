"""
    计算a+b,但输入方式有所改变。

输入描述
第一行是一个整数N,表示后面会有N行a和b,通过空格隔开。

输出描述
对于输入的每对a和b,你需要在相应的行输出a、b的和。
如第二对a和b,对应的和也输出在第二行。
输入示例
2
2 4
9 21
输出示例
6
30
提示信息
注意,测试数据不仅仅一组。也就是说,会持续输入N以及后面的a和b
"""

while True:
    try:
        n = int(input())
        for i in range(n):
            a, b = map(int, input().split())
            print(a + b)
    except:
        break
        