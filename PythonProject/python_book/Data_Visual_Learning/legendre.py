import matplotlib.pyplot as plt
import numpy as np

# 定义勒让德多项式函数
def legendre_poly(n):
    if n == 0:
        return lambda x: 1.0
    elif n == 1:
        return lambda x: x
    else:
        return lambda x: ((2.0*n - 1.0)*x*legendre_poly(n-1)(x) - (n-1)*legendre_poly(n-2)(x)) / n

# 绘制勒让德多项式函数曲线
x = np.linspace(-1, 1, 1000)
fig, ax = plt.subplots()
for n in range(2, 6):
    ax.plot(x, legendre_poly(n)(x), label="P"+str(n))
ax.legend()
plt.show()