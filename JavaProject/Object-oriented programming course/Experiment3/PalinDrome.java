/*
import java.lang.Math;

public class PalinDrome {
    public static void main(String[] args) {
        for(int i = 0; i <= 99999; i++){
            if(isPalindrome(i) && isPalindrome(i * i) && isPalindrome((int) Math.pow(i, 3))){
                System.out.println(i);
            }
        }
    }

    public static int reverse(int num){
        int reversed = 0;
        while(num != 0){
            int digit = num % 10;
            reversed = reversed * 10 + digit;
            num /= 10;
        }
        return reversed;
    }

    public static boolean isPalindrome(int num){
        return num == reverse(num);
    }
}

 */

/*
public class PalinDrome
{
    public static void main(String[] args)
    {
        //遍历1-99999的所有整数，输出满足条件的数
        for (int i = 1; i < 99999; i++)
        {
            if (isPalindrome(i))
            {
                System.out.println(i);
            }
        }

    }

    //reversed方法
    public static int reverse(int num)
    {
        int reversed=0;
        while (num != 0)
        {
            //算法：用取10的余数得到最后一位dight，用/10的方法去掉最后一位
            int dight =  num % 10;
            reversed = reversed * 10 + dight;
            num /= 10;
        }
        return reversed;
    }
    //isPalindrome方法，调用了reverse方法
    public static boolean isPalindrome(int num)
    {
        return (num == reverse(num) && num*num == reverse(num*num) && num*num*num == reverse(num*num*num) );
    }
}
 */

// PalinDrome类，用于判断回文数
public class PalinDrome
{
    public static void main(String[] args)
    {
        // 遍历1-99999的所有整数，输出满足条件的数
        for (int i = 1; i < 99999; i++)
        {
            if (isPalindrome(i))
            {
                System.out.println(i); // 如果i是回文数，则输出i
            }
        }
    }

    // reversed方法，用于反转一个整数
    public static int reverse(int num)
    {
        int reversed = 0;
        while (num != 0)
        {
            // 算法：用取10的余数得到最后一位dight,用/10的方法去掉最后一位
            int dight = num % 10;
            reversed = reversed * 10 + dight;
            num /= 10;
        }
        return reversed;
    }

    // isPalindrome方法，用于判断一个整数是否为回文数
    public static boolean isPalindrome(int num)
    {
        // 如果num等于它的反转数、num的平方等于它的反转数的平方、以及num的立方等于它的反转数的立方，则返回true,否则返回false
        return (num == reverse(num) && num*num == reverse(num*num) && num*num*num == reverse(num*num*num));
    }
}

