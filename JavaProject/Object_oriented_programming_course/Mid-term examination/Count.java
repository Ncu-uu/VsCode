//以下为chatgpt优化后的代码

import java.util.Scanner;

public class Count {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double sum = 0;
        double[] a = new double[10];

        for (int i = 0; i < a.length; i++) {
            a[i] = scanner.nextDouble();
            sum += a[i];
        }

        double avg = sum / a.length;

        System.out.printf("Average  is  %.2f\n",  avg);

        int count = 0;
        for (int i = 0; i < a.length; i++) {
            if (a[i] > avg) {
                count++;
            }
        }
        System.out.println("Number of elements above the average is: " + count);
    }
}

//原代码如下

/*
import java.util.Scanner;
public class Count {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int count=0;
        double  sum=0,avg;

        double[] a=new double[10];
        for(int i=0;i<a.length;i++){
            a[i]=scanner.nextInt();
        }

        for(int i=0;i<a.length;i++){
            sum += a[i];
        }

        avg=sum/10.0;

        System.out.printf("Average is " + "%.2f",avg);
        System.out.println();

        for(int i=0;i<a.length;i++){
            if(a[i]>avg){
                count++;
            }
        }
        System.out.print("Number of elements above the average is: ");
        System.out.println(count);
    }
}

 */

/*
gpt优化注释：

        1. 将 `count` 的初始值从 0 改为一开始就定义为 double 型的 `sum`，在输入 `a[i]` 的时候直接累加，可以避免一些重复计算。

        2. 在计算平均值时，直接使用 `a.length` 来代替硬编码的 10，使得代码更具有通用性。

        3. 在输出平均值时，使用了格式化字符串 `%.2f` 来限制小数点后保留两位，而不是手动拼接字符串。

        4. 在输出“Number of elements above the average is”时，将 `println` 和 `print` 结合使用，使得输出更简洁，也可以在一行输出。

 */
