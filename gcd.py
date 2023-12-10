import math

def find_z(x, y):
    while y != 0:
        x, y = y, x % y
    return x - 1

x, y = map(int, input().split())
z = find_z(x, y)
print(z)
