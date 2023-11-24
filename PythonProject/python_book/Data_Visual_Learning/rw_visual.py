import matplotlib.pyplot as plt
from random_walk import RandomWalk

# 创建一个RandomWalk实例，并将其包含的点都绘制出来
rw = RandomWalk(50000)
rw.fill_walk()

#将所有的点都绘制出来
plt.style.use('classic')
fig, ax = plt.subplots()
poimt_numbers = range(rw.num_points)
ax.scatter(rw.x_values, rw.y_values, c=poimt_numbers, cmap=plt.cm.Blues, edgecolors='none', s=15)
# ax.scatter(rw.x_values, rw.y_values, s=15)

# 突出起点和终点
ax.scatter(0, 0, c='green', edgecolors='none', s=100)
ax.scatter(rw.x_values[-1], rw.y_values[-1], c='red', edgecolors='none', s=100)

# 隐藏坐标轴
ax.get_xaxis().set_visible(False)
ax.get_yaxis().set_visible(False)

plt.show()
