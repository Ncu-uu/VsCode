TempStr = eval(input("请输入带无单位的温度值:"))
Unit = input("请输入单位:")
if Unit in ['F','f'] :
   C = (TempStr - 32)/1.8
   print("{:.0f}C".format(C))
elif Unit in ['C','c'] :
   F = 1.8 * TempStr +32
   print("{:.0f}F".format(F))
else :
   print("格式错误")