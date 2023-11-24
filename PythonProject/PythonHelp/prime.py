prime_numbers = []# 用于存放素数的列表
count = 0 # 用于记录素数的个数

# 遍历101到200之间的每个数
for num in range(101, 201):
    is_prime = True
    # 判断是否为素数
    for i in range(2, int(num ** 0.5) + 1):
        # 如果能被2到根号num之间的任意一个数整除，则不是素数
        if num % i == 0:
            is_prime = False
            break
    # 如果是素数，则将其添加到列表中,并将素数个数加1
    if is_prime:
        prime_numbers.append(num)
        count += 1
# 输出素数个数和素数列表
print("101到200之间的素数有{}个，分别是：".format(count), end='')
for prime in prime_numbers:
    print(prime, end=' ')
print()  # 输出一个空行

# count = 0           # 用于记录素数的个数
# # 遍历101到200之间的每个数
# for i in range(101, 201):
#     is_prime = True
#     for j in range(2, i):
#         if i % j == 0:
#             is_prime = False
#             break
#     if is_prime:
#         count += 1
#         print(i, end=' ')
# print("素数的个数是:", count)
