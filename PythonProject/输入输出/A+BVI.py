'''
题目描述
你的任务是计算若干整数的和。
输入描述
输入的第一行为一个整数N,接下来N行每行先输入一个整数M,然后在同一行内输入M个整数。

输出描述
对于每组输入,输出M个数的和,每组输出之间输出一个空行。
输入示例
3
4 1 2 3 4
5 1 2 3 4 5
3 1 2 3
输出示例
10

15

6
'''

while True:
    try:
        n = int(input())
        for i in range(n):
            a = list(map(int, input().split()))
            print(sum(a[1:]))
            if i != n - 1:
                print()
    except:
        break


