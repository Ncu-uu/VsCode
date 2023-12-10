// # 小A听隔壁的小B说，同班小C寝室4人竟然有11个群，震惊了小A一整天！

// # 后来他仔细想了想，自己单独肯定不需要建群，两个人之间聊天也没必要建群，所以4个人没有必要11个群，最多建5个群就好了。

// # 题目描述
// # 给定人数
 
// # n, 输出群聊数量最大值，群聊数计算方法如题目背景中所述。由于答案可能很大，请对1e9+7取模。

// # 格式
// # 输入格式
// # 一个整数n。
// # 输出格式
// # 一个整数ans，表示群聊数量最大值。
// # 假设有四个人原子，原群，原根，原神。 那么有{原子，原群，原根}，{原子，原群，原神}，{原子，原根，原神}，{原群，原根，原神}，{原子，原群，原根，原神}共5个群聊。
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// 计算阶乘
long long factorial(int n){
    long long ans = 1;
    for(int i = 1; i <= n; i++){
        ans *= i;
    }
    return ans;
}

// 计算组合数
long long combination(int n, int m){
    return factorial(n) / (factorial(m) * factorial(n - m));
}

int main(){
    long long n;
    scanf("%lld", &n);
    long long sum = 0;
    for(long long i = 3; i <= n; i++){
        sum += combination(n, i);
    }
    int ans = sum % 1000000007;
    printf("%d", ans);
    return 0;
}