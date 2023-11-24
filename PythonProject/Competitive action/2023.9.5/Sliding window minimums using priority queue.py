import heapq

n, k = map(int, input().split())
arr = list(map(int, input().split()))

q = []
res = 0
for i in range(k):
    heapq.heappush(q, arr[i])
    
res += q[0] ** 2

for i in range(k, n):
    heapq.heappop(q)
    heapq.heappush(q, arr[i])
    res += q[0] ** 2
      
print(res)