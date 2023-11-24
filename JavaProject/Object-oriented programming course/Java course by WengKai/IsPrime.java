import java.util.Scanner;

public class IsPrime
{
    public static void main(String[] args)
    {
        Scanner in =new Scanner(System.in);
        System.out.println("请输入一个正整数N：");
        int n =in.nextInt();
        boolean isPrime=true;

        if (n==1||n%2==0&&n!=2)
        {
            isPrime=false;
        }
        for(int i = 1;i<n;i+=2)
        {
            if (n%i==0)
            {
                isPrime=false;
                break;
            }
        }
        if (isPrime==true && n!=1)
        {
            System.out.println(n + "是素数");
        }
        else if (isPrime==false && n!=1)
        {
            System.out.println(n + "不是素数");
        }
        else
        {
            System.out.println("1既不是素数也不是合数");
        }
    }
}
