import java.util.Arrays;
import java.util.Scanner;

public class ReciprocalSum
{
    public static void main(String[] args)
    {
        System.out.println("请输入一个正整数：");
        Scanner in=new  Scanner(System.in);
        int n=in.nextInt();
        double sum1=0.0;
        double sum2=0.0;

        for (int i=1;i<=n;i++)
        {
            sum1+=1.0/i;
        }
        int sign=1;

        for (int i=1;i<=n;i++)
        {
            sum2+=sign*1.0/i;
            sign=-sign;
        }
        System.out.printf("1~n的倒数和为"+"%.2f\n",sum1);
        System.out.printf("1~n的正负交替倒数和为"+"%.2f",sum2);
    }
}
