# import emoji
import matplotlib.pyplot as plt

print("\a")


# a = [1,2,3,4,5,6,7,8,9,10,]
# b = [1,2,3,4,5,6,7,8,9,10,11]
# c = []
# print(max(a,b,c))


# if (n := len(a)) > 10:
#     print(f"List is too long ({n} elements, expected <= 10)")



# print(plt.style.available)


# def make_pizza(*toppings,) -> None:
#     """
#     打印顾客点的所有配料
#     """
#     print("\nMaking a pizza with the following toppings:")
#     for topping in toppings:
#         print(f"- {topping}")

# def print_models(unprinted_designs,completed_models):
#     """
#     模拟打印每个设计，直到没有未打印的设计为止
#     打印每个设计后，都将其移到列表completed_models中
#     """
#     while unprinted_designs:
#         current_design = unprinted_designs.pop()
#         # 模拟根据设计制作3D打印模型的过程
#         print(f"Printing model: {current_design}")
#         completed_models.append(current_design)
#
# def show_completed_models(completed_models):
#     """显示打印好的所有模型"""
#     print("\nThe following models have been printed:")
#     for completed_model in completed_models:
#         print(completed_model)
#
# unprinted_designs = ['iphone case','robot pendant','dodecahedron']
# completed_models = []
#
# print_models(unprinted_designs,completed_models)
# show_completed_models(completed_models)
# # print(unprinted_designs)
# # print(completed_models)


# def greet_users(names):
#     """向列表中的每位用户都发出简单的问候"""
#     for name in names:
#         msg = f"Hello, {name.title()}!"
#         print(msg)
#
# usernames = ['hannah','ty','margot']
# greet_users(usernames)





# responses = {}
#
# # 设置一个标志，指出调查是否继续
# polling_active = True
#
# while polling_active:
#     # 提示输入被调查者的名字和回答
#     name = input("\nWhat is your name?")
#     response = input("Which mountain would you like to climb someday?")
#     # 将答案存储在字典中
#     responses[name] = response
#     # 看看是否还有人要参与调查
#     repeat = input("Would you like to let another person respond?(yes/no)")
#     if repeat == 'no':
#         polling_active = False
#
# # 调查结束，显示结果
# print("\n--- Poll Results ---")
# for name,response in responses.items():
#     print(f"{name} would like to climb {response}.")




# pets = ['dog','cat','dog','goldfish','cat','rabbit','cat']
# print(pets)
#
# while 'cat' in pets:
#     pets.remove('cat')
#
# print(pets)



# prompt = "\nTell me something, and I will repeat it back to you:"
# prompt += "\nEnter 'quit' to end the program."
# message = ""
# while message != 'quit':
#     message = input(prompt)
#     if message != 'quit':
#         print(message)
# prompt = "If you tell us who you are, we can personalize the messages you see."
# prompt += "\nWhat is your first name? "
# name = input(prompt)
# print(f"\nHello, {name}!")


# message = input("Tell me something, and I will repeat it back to you: ")
# print(message)

# favorite_languoges = {
#     'jen':'python',
#     'sarah':'c',
#     'edward':'ruby',
#     'phil':'python',
# }
# friends = ['phil','sarah']
# for name in favorite_languoges.keys():
#     print(name.title())
#     if name in friends:
#         print(f" Hi {name.title()}, I see your favorite language is {favorite_languoges[name].title()}!")

# user_0 = {
#     'username':'efermi',
#     'first':'enrico',
#     'last':'fermi',
# }
# for key,value in user_0.items():
#     print(f"Key: {key}")
#     print(f"Value: {value}\n")

# alien_0 = {'x_position':0,'y_position':25,'speed':'medium'}
# print(f"Original position: {alien_0['x_position']}")
#
# # 向右移动外星人
# # 根据外星人当前速度决定将其移动多远
# if alien_0['speed'] == 'slow':
#     x_increment = 1
# elif alien_0['speed'] == 'medium':
#     x_increment = 2
# else:
#     x_increment = 3
#
# # 新位置等于老位置加上增量
# alien_0['x_position'] = alien_0['x_position'] + x_increment
# # alien_0['x_position']+= x_increment
# print(f"New position: {alien_0['x_position']}")


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