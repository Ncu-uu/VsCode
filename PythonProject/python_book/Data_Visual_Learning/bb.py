import numpy as np
import matplotlib.pyplot as plt

# 问题1
r = 100
angles = np.zeros(9)
angles[0:] = [0, 40.10, 80.21, 119.75, 159.86, 199.96, 240.07, 280.17, 320.28]

x = r * np.cos(np.deg2rad(angles))
y = r * np.sin(np.deg2rad(angles))

# 确定发射信号无人机
d = np.abs(angles[:,None] - angles[None,:])
d[d>180] = 360 - d[d>180]
i, j = np.unravel_index(d.argmax(), d.shape)
fy00, fy1, fy2 = [0, i, j]

fig, ax = plt.subplots()
for k, angle in enumerate(angles):
    # 计算坐标
    x0, y0 = 0, 0
    x1, y1 = x[fy1], y[fy1]
    x2, y2 = x[fy2], y[fy2]

    A = np.array([
        [x0, y0, 1, 0, 0, 0],
        [x1, y1, 0, 1, 0, 0],
        [x2, y2, 0, 0, 1, 0]
    ])

    b = np.array([x[k], y[k], 1])
    coord = np.linalg.solve(A, b)
    xc, yc = coord[:2]

    # 移动到理想位置
    x[k], y[k] = r*np.cos(angle), r*np.sin(angle)

    ax.plot(x[:k+1], y[:k+1], 'o-')

ax.set_aspect('equal')
ax.set_title('Trajectory of UAVs')
ax.set_xlabel('x')
ax.set_ylabel('y')