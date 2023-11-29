package Complex;
//导入必要的类
import java.util.Arrays;
import java.util.Scanner;

// 定义一个测试类
public class ComplexTest {
    public static void main(String[] args) {
// 创建一个Scanner对象，用于读取用户输入
        Scanner input = new Scanner(System.in);

        // 提示用户输入第一个复数的实部和虚部，并创建一个Complex对象
        System.out.print("Enter the first complex number: ");
        double a = input.nextDouble();
        double b = input.nextDouble();
        Complex c1 = new Complex(a, b);

        // 提示用户输入第二个复数的实部和虚部，并创建一个Complex对象
        System.out.print("Enter the second complex number: ");
        double c = input.nextDouble();
        double d = input.nextDouble();
        Complex c2 = new Complex(c, d);

        // 输出加、减、乘、除、绝对值的运算结果
        System.out.println("(" + c1 + ")" + " + " + "("+ c2 + ")" + " = " + c1.add(c2));
        System.out.println("(" + c1 + ")" + " - " + "("+ c2 + ")" + " = " + c1.subtract(c2));
        System.out.println("(" + c1 + ")" + " * " + "("+ c2 + ")" + " = " + c1.multiply(c2));
        System.out.println("(" + c1 + ")" + " / " + "("+ c2 + ")" + " = " + c1.divide(c2));
        System.out.println("|" + c1 + "|" + " = " + c1.abs());

        // 创建一个与c1相同的复数对象c3，并判断c1与c3是否相等
        Complex c3 = c1.clone();
        System.out.println(c1 == c3);

        // 输出c1的实部和虚部
        System.out.println(c1+"实部：" + c1.getRealPart());
        System.out.println(c1+"虚部：" + c1.getImaginaryPart());

        // 创建一个Complex数组，并将c1、c2、c3存入数组中，然后对数组进行排序并输出
        Complex[] array = {c1, c2, c3};
        Arrays.sort(array);
        System.out.println(Arrays.toString(array));
    }
}
/*
import java.util.Arrays;
import java.util.Scanner;

public class ComplexTest {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the first complex number: ");
        double a = input.nextDouble();
        double b = input.nextDouble();
        Complex c1 = new Complex(a, b);

        System.out.print("Enter the second complex number: ");
        double c = input.nextDouble();
        double d = input.nextDouble();
        Complex c2 = new Complex(c, d);

        System.out.println("(" + c1 + ")" + " + " + "("+ c2 + ")" + " = " + c1.add(c2));
        System.out.println("(" + c1 + ")" + " - " + "("+ c2 + ")" + " = " + c1.subtract(c2));
        System.out.println("(" + c1 + ")" + " * " + "("+ c2 + ")" + " = " + c1.multiply(c2));
        System.out.println("(" + c1 + ")" + " / " + "("+ c2 + ")" + " = " + c1.divide(c2));
        System.out.println("|" + c1 + "|" + " = " + c1.abs());

        Complex c3 = c1.clone();
        System.out.println(c1 == c3);

        System.out.println(c1+"实部：" + c1.getRealPart());
        System.out.println(c1+"虚部：" + c1.getImaginaryPart());

        Complex[] array = {c1, c2, c3};
        Arrays.sort(array);
        System.out.println(Arrays.toString(array));
    }
}


 */
