
alien_0 = {'x_position':0,'y_position':25,'speed':'medium'}
print(f"Original position: {alien_0['x_position']}")

# 向右移动外星人
# 根据外星人当前速度决定将其移动多远
if alien_0['speed'] == 'slow':
    x_increment = 1
elif alien_0['speed'] == 'medium':
    x_increment = 2
else:
    x_increment = 3

# 新位置等于老位置加上增量
alien_0['x_position'] = alien_0['x_position'] + x_increment
# alien_0['x_position']+= x_increment
print(f"New position: {alien_0['x_position']}")


# alien_0 = {'color':'green','points':5}
# print(alien_0)
#
# alien_0['x_position'] = 0
# alien_0['y_position'] = 25
# print(alien_0)

# available_toppings = ['mushroom','olives','green peppers','pepperoni','pineapple','extra cheese']
# requested_toppings = ['mushroom','french fries','extra cheese']
# for requested_topping in requested_toppings:
#     if requested_topping in available_toppings:
#         print(f"Adding {requested_topping}.")
#     else:print(f"Sorry we don't have {requested_topping}")
# print("\nFinished making your pizza!")

# if True:
#     print("true")
# elif False:
#     print("false")

# car = 'subaru'
# print("Is car == 'subaru' ? I predict True.")
# print(car == 'subaru')
# print("\nIs car == 'audi' ? I predict False.")
# print(car == 'audi')

# numbers = [value ** 3 for value in range(1,11)]
# numbers2 = numbers
# print(numbers)
# print(numbers2)
# numbers2[0] = 999999;
# print(numbers)
# print(numbers2)
# numbers[1] = 8888888;
# print(numbers)
# print(numbers2)

# numbers = list(range(3,31,3))
# print(numbers)

# numbers = [value for value in range(1,1000001)]
# print(numbers)
# print(min(numbers))
# print(max(numbers))
# print(sum(numbers))

# 普通写法
# squares = []
# for value in range(1,11):
#     square = value ** 2
#     squares.append(square)
#列表解析写法
# squares = [value ** 2 for value in range(1,11)]
#
# print(squares)
# print(max(squares))
# print(min(squares))
# print(sum(squares))

# for value in range(0 , 4):
#     print(value)

# cars = ['bmw','audi','toyota','subaru']
# for car in cars:
#     print(car)
# print(cars)

# print(f"\nhow{cars}")

# print("原列表：")
# print(cars)
# # print("\n")
# print("临时排序输出：")
# print(sorted(cars))
# # print("\n")
# print("确认原列表：")
# print(cars)
# # print("\n")
# cars.reverse()
# print(cars)
# # print("\n")
# cars.reverse()
# print(cars)
# # print("\n")
# cars.sort()
# print(cars)


# import this

# print("Albert Einstein once said,\"A person who never made a mistake never tried anything new.\"" )

# first_name="Steve"
# last_name="John"
# full_name=f"{first_name} {last_name}"
# print(full_name)

# print("Hello world!")