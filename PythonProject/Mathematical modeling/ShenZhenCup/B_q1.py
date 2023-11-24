import math
from queue import PriorityQueue

# 定义无人机速度、转弯半径等参数
v = 10  # 速度，单位：米/秒
r_t = 30  # 转弯半径，单位：米

# 定义站点A和站点B的坐标
x_A, y_A = -1000, 0
x_B, y_B = 3500, 0

# 定义障碍圆的圆心坐标和半径
x_c, y_c = 0, 0
radius = 500

def heuristic_cost_estimate(start, goal):
    # 欧几里得距离作为启发式估计函数
    x1, y1 = start
    x2, y2 = goal
    return math.sqrt((x2 - x1)**2 + (y2 - y1)**2)

def is_valid_position(position):
    # 判断位置是否在飞行区域内，并且不与障碍圆相交
    x, y = position
    distance_to_center = math.sqrt((x - x_c)**2 + (y - y_c)**2)
    if x >= 0 and distance_to_center >= radius:
        return True
    return False

def generate_successors(position):
    # 生成邻居节点
    x, y = position
    successors = []
    for angle in range(0, 360, 5):  # 每隔5度生成一个邻居节点
        angle_rad = math.radians(angle)
        new_x = x + v * math.cos(angle_rad)
        new_y = y + v * math.sin(angle_rad)
        successor = (new_x, new_y)
        if is_valid_position(successor):
            successors.append(successor)
    return successors

def a_star_search(start, goal):
    open_set = PriorityQueue()
    open_set.put((0, start))

    came_from = {}
    g_score = {start: 0}
    f_score = {start: heuristic_cost_estimate(start, goal)}

    while not open_set.empty():
        current = open_set.get()[1]

        if current == goal:
            path = [current]
            while current in came_from:
                current = came_from[current]
                path.append(current)
            path.reverse()
            return path

        for neighbor in generate_successors(current):
            tentative_g_score = g_score[current] + v

            if neighbor not in g_score or tentative_g_score < g_score[neighbor]:
                came_from[neighbor] = current
                g_score[neighbor] = tentative_g_score
                f_score[neighbor] = tentative_g_score + heuristic_cost_estimate(neighbor, goal)
                open_set.put((f_score[neighbor], neighbor))

    return None

# 求解问题一
path = a_star_search((x_A, y_A), (x_B, y_B))

if path:
    # 计算第一个到达目的站点的无人机的飞行时间
    T_1 = len(path) / v
    print("最优航迹方案：", path)
    print("第一个到达目的站点的无人机的飞行时间：", T_1)
else:
    print("无法找到最优航迹方案")
