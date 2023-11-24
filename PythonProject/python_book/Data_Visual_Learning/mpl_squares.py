import matplotlib.pyplot as plt

# input_values = [1, 2, 3, 4, 5]
# squares = [1, 4, 9, 16, 25]
x_values = range(1, 1001)
y_values = [x**2 for x in x_values]


# plt.style.use('Solarize_Light2')
fig, ax = plt.subplots()
# ax.plot(input_values, squares, linewidth=3)
# ax.scatter(input_values, squares, s=100)
ax.scatter(x_values, y_values, c=y_values, cmap=plt.cm.Blues, s=0.1)

# 设置图表标题并给坐标轴加上标签
ax.set_title("Square Numbers", fontsize=24)
ax.set_xlabel("Value", fontsize=14)
ax.set_ylabel("Square of Value", fontsize=14)

# 设置刻度标记的大小
ax.tick_params(axis='both', labelsize=14)

ax.axis([0, 1100, 0, 1100000])

# plt.show()
plt.savefig('squares_plot.png', bbox_inches='tight')