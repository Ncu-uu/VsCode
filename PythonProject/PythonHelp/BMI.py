
height = float(input("请输入您的身高（米）："))
weight = float(input("请输入您的体重（公斤）："))

bmi = weight / height ** 2
bmi = round(bmi, 2)

print("您的身高为：{:.2f}米".format(height))
print("您的体重为：{:.2f}公斤".format(weight))
print("您的BMI指数为:{:.2f}".format(bmi))

if bmi < 18.5:
    print("您的体重属于偏瘦型")
elif bmi >= 18.5 and bmi < 24:
    print("您的体重属于正常型")
elif bmi >= 24 and bmi < 28:
    print("您的体重属于超重型")
else:
    print("您的体重属于肥胖型")