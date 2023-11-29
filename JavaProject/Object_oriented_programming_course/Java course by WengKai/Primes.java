
public class Primes
{
    public static void main(String[] args)
    {
        int[] primes = new int[50];
        primes[0]=2;
        int cnt =1;
//        int i=0;
        MAIN_LOOP:
        for (int x =3 ; cnt<primes.length;x++)
        {
            for ( int i=0;i<cnt;i++)
            {
                if (x % primes[i]== 0)
                {
                    continue MAIN_LOOP;
                }
            }
            primes[cnt++]=x;
        }
        for (int k:primes)
        {
            System.out.print(k+" ");
        }
    }
}

/*

public  class  Primes
{
    public  static  void  main(String[]  args)
    {
        int[]  primes  =  new  int[50];
        primes[0]  =  2;
        int  cnt  =  1;
        int  i  =  0;
        //  主循环
        MAIN_LOOP:
        for  (int  x  =  3;  cnt  <  primes.length;  x++)
        {
            //  判断是否是素数
            for  (i  =  0;  i  <  cnt;  i++)
            {
                if  (x  %  primes[i]  ==  0)   //  不是素数
                {
                    continue  MAIN_LOOP;  //  继续外层循环
                }
            }
            primes[cnt]  =  x;  //  是素数，加入数组
            cnt++;  //  素数个数加1
        }
        //  输出素数数组
        for  (int  k  :  primes)
        {
            System.out.print(k  +  "  ");
        }
    }
}


 */