import java.util.Scanner;

public class Equation
{
    public static void main(String[] args)
    {
        System.out.println("Enter the three coefficients of the equation :");
        Scanner input = new Scanner(System.in);
        double a = input.nextDouble();
        double b = input.nextDouble();
        double c = input.nextDouble();

        double delta = Math.pow(b,2)-4*a*c;

        if(delta<0)
        {
            System.out.println("The equation has no real roots.");
        }
        else if (delta==0)
        {
            double root = (-b/(2*a));
            System.out.println("The equation has one root " + root);
        }
        else if (delta>0)
        {
            double root1 = ((-b+Math.pow(delta,0.5))/(2*a));
            double root2 = ((-b-Math.pow(delta,0.5))/(2*a));
            System.out.println("The equation has two roots:" + root1 + " and " + root2);
        }
    }
}
