import numpy as np
from matplotlib import pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# 定义玫瑰花的参数方程
def rose(t, k):
    x = np.cos(k * t) * np.cos(t)
    y = np.cos(k * t) * np.sin(t)
    z = np.sin(k * t)
    return np.c_[x, y, z]

theta = np.linspace(0, 2 * np.pi, 100)
k = 5  # 控制玫瑰花瓣的数量
points = rose(theta, k)

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.set_title('3D Rose')
ax.set_xlim(-2, 2)
ax.set_ylim(-2, 2)
ax.set_zlim(-2, 2)
ax.set_box_aspect((1, 1, 1))

ax.scatter(points[:,0], points[:,1], points[:,2], color='red', s=0.1)  # 绘制散点图

# 绘制曲线以形成花瓣的形状
for i in range(len(theta)-1):
    ax.plot([points[i,0], points[i+1,0]], [points[i,1], points[i+1,1]], [points[i,2], points[i+1,2]], color='red')  # 绘制X-Y平面上的曲线
    ax.plot([points[i,0], points[i+1,0]], [points[i,1], points[i+1,1]], [points[i+1,2], points[i+2,2]], color='red')  # 绘制X-Z平面上的曲线    
    ax.plot([points[i,0], points[i+1,0]], [points[i+1,1], points[i+2,1]], [points[i,2], points[i+1,2]], color='red')  # 绘制Y-Z平面上的曲线    
    plt.draw()  # 更新画布上的内容    
plt.show()  # 显示图形    