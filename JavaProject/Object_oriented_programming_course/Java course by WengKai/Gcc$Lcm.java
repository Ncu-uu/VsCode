import java.util.Scanner;

public class Gcc$Lcm
{
    public static void main(String[] args)
    {
        System.out.println("请输入两个正整数：");
        Scanner in = new Scanner(System.in);
        int a=in.nextInt();
        int b=in.nextInt();
        int oa=a;
        int ob=b;
        int r;
        while (b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }

        int gcc=a;

        int lcm=oa*ob/gcc;

        System.out.println(oa+"和"+ob+"的最大公约数为"+gcc);
        System.out.println(oa+"和"+ob+"的最小公倍数为"+lcm);
    }
}
