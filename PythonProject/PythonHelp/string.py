s = input("请输入一个字符串：")
upper_count = 0
lower_count = 0
digit_count = 0
space_count = 0

for char in s:
    if char.isupper():
        upper_count += 1
    elif char.islower():
        lower_count += 1
    elif char.isdigit():
        digit_count += 1
    elif char.isspace():
        space_count += 1

print("大写字母个数：", upper_count)
print("小写字母个数：", lower_count)
print("数字个数：", digit_count)
print("空格个数：", space_count)
