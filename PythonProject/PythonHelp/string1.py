def main():
    str1=input('请输入第一个字符串：')
    str2=input('请输入第二个字符串：')
    str3=input('请输入第三个字符串：')
    print('排序前顺序为：')
    print(str1,str2,str3)
    
    if str1>str2:
        str1,str2=str2,str1
        
    if str1>str3:
        str1,str3=str3,str1
        
    if str2>str3:
        str2,str3=str3,str2
        
    print('排序后顺序为：')
    print(str1,str2,str3)

if __name__ == '__main__':
    main()
    