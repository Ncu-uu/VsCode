def main():
    print("请分别三次计算问题：")
    for i in range(3):
        print("[第%d次计算]"%(i+1))
        n=float(input("请输输入定期利率n(0.0<n<10.0):"))
        cunkuan=10000 #本金
        year=0
        while cunkuan<20000:
            cunkuan=cunkuan*(1+n/100)
            year+=1
        print("存款翻倍需要%d年"%year)
        
if __name__ == "__main__":
    main()
