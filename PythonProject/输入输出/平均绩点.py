
'''
题目描述
每门课的成绩分为A、B、C、D、F五个等级,为了计算平均绩点,规定A、B、C、D、F分别代表4分、3分、2分、1分、0分。
输入描述
有多组测试样例。每组输入数据占一行,由一个或多个大写字母组成,字母之间由空格分隔。
输出描述
每组输出结果占一行。如果输入的大写字母都在集合｛A,B,C,D,F｝中,则输出对应的平均绩点,结果保留两位小数。否则,输出“Unknown”。
输入示例
A B C D F
B F F C C A
D C E F
输出示例
2.00
1.83
Unknown

'''

dic={'A':4,'B':3,'C':2,'D':1,'F':0}
while True:
    try:
        a=input().split()
        b=[]
        for i in a:
            if i not in dic:
                print('Unknown')
                break
            b.append(dic[i])
        else:
            print('%.2f'%(sum(b)/len(b)))
    except:
        break