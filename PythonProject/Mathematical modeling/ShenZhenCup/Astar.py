import math

class Node:
    def __init__(self, x, y, g, h):
        self.x = x
        self.y = y
        self.g = g
        self.h = h
        self.f = g + h

    def __str__(self):
        return str((self.x, self.y))

def heuristic(node, goal):
    return math.hypot(node.x - goal.x, node.y - goal.y)

def astar(start, goal, obstacle):
    openset = set()
    closedset = set()
    current = start
    openset.add(current)

    while openset:
        current = min(openset, key=lambda o:o.f)
        if current == goal:
            path = []
            while current.parent:
                path.append(current)
                current = current.parent
            path.append(current)
            return path[::-1]

        openset.remove(current)
        closedset.add(current)

        for neighbor in get_neighbors(current):
            if neighbor in closedset:
                continue
            if neighbor in obstacle:
                closedset.add(neighbor)
                continue

            temp_g = current.g + 1
            if neighbor not in openset:
                openset.add(neighbor)
            elif temp_g >= neighbor.g:
                continue

            neighbor.parent = current
            neighbor.g = temp_g
            neighbor.h = heuristic(neighbor, goal)

def get_neighbors(node):
    directions = [(0, 1), (0, -1), (1, 0), (-1, 0),
                  (1, 1), (1, -1), (-1, 1), (-1, -1)]
    neighbors = []
    for dx, dy in directions:
        x = node.x + dx
        y = node.y + dy
        neighbors.append(Node(x, y, 0, 0))
    return neighbors

if __name__ == "__main__":
    start = Node(-1000, 0, 0, 0)
    goal = Node(3500, 0, 0, 0)
    obstacle = [(x, y) for x in range(-500, 500) for y in range(-500, 500)]

    path = astar(start, goal, obstacle)
    print(path)