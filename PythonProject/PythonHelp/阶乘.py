n = int(input("请输入一个正整数："))
factorial = 1
sum = 0

for i in range(1, n+1):
    factorial *= i
    sum += factorial

print("阶乘累加和为：", sum)