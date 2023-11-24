# 获取用户输入的X
X = int(input("请输入一个整数X:"))

# 初始化偶数之和为0
even_sum = 0

# 遍历1到X之间的每个数
for num in range(1, X + 1):
    # 判断是否为偶数
    if num % 2 == 0:
        # 将偶数累加到偶数之和中
        even_sum += num

# 输出偶数之和
print("1到{}之间的偶数之和为：{}".format(X, even_sum))
