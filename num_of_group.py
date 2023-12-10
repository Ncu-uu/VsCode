# 小A听隔壁的小B说，同班小C寝室4人竟然有11个群，震惊了小A一整天！

# 后来他仔细想了想，自己单独肯定不需要建群，两个人之间聊天也没必要建群，所以4个人没有必要11个群，最多建5个群就好了。

# 题目描述
# 给定人数
 
# n, 输出群聊数量最大值，群聊数计算方法如题目背景中所述。由于答案可能很大，请对1e9+7取模。

# 格式
# 输入格式
# 一个整数n。
# 输出格式
# 一个整数ans，表示群聊数量最大值。
# 假设有四个人原子，原群，原根，原神。 那么有{原子，原群，原根}，{原子，原群，原神}，{原子，原根，原神}，{原群，原根，原神}，{原子，原群，原根，原神}共5个群聊。

#计算阶乘
def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)
# 计算组合数
def combination(n, m):
    return factorial(n) // factorial(m) // factorial(n-m)

n = int(input())
# print(combination(n, 3))
sum = 0

if (n <= 2):
    print(0)
else:
    for i in range(3 , n+1):
        sum += combination(n, i)
        
ans = sum % (10**9 + 7)
print(ans)
        