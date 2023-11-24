money = input("请输入货币数量和单位:")
if money[-1] =='$':
    RMB = eval(money[0:-1]) * 6
    print("{}￥".format(RMB))
elif money[-1] =='￥':
    dollar = eval(money[0:-1]) / 6
    print("{}$".format(dollar))
else :
    print("输入单位格式错误")