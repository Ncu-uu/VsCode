//
import java.util.Scanner;
public class QuadraticEquation {


    public static void main(String[] args) {
        // 获取数据
        Scanner input = new Scanner(System.in);
//         System.out.println("Enter a, b, c: ");
        double a = input.nextDouble(), b = input.nextDouble(), c = input.nextDouble();

        // 计算判别式
        double judge = Math.pow(b, 2) - 4 * a * c;

        // 根据判别式结果分三种情况计算根值并输出
        if (judge > 0 && a != 0){
            double r1 = (-b + Math.pow(judge, 0.5)) / (2 * a);
            double r2 = (-b - Math.pow(judge, 0.5)) / (2 * a);
            System.out.printf("The roots are "+ "%.2f",r1 +" and "+ "%.2f",r2);
            System.out.println();
        } else if (judge == 0 && a != 0){
            double r1 = (-b) / (2 * a);
            System.out.printf("The root is " + "%.2f",r1);
            System.out.println();
        }else if (a == 0){  // 补充，如果a=0应该也有结果，但不是根
            double r1 = (-c) / b;
            System.out.printf("The root is " + "%.2f",r1);
            System.out.println();
        }else
            System.out.println("The equation has no roots");
    }
}