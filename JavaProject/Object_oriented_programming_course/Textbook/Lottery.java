import java.util.Scanner;

public class Lottery
{
    public static void main(String[] args)
    {
        int lottery = (int)(Math.random()*100);
//        System.out.println(lottery);

        Scanner input = new Scanner(System.in);
        System.out.println("Enter your lottery pick (two dights) :");
        int guess = input.nextInt();


        int lotterydight1 = lottery/10;
        int lotterydight2 = lottery%10;

        int guessdight1 = guess/10;
        int guessdight2 = guess%10;

        if(lottery==guess)
        {
            System.out.println("You win 10000$");

        }
        else if (lotterydight1==guessdight2 && lotterydight2 == guessdight1)
        {
            System.out.println("You win 3000$");
        } else if (guessdight1==lotterydight1||guessdight1==lotterydight2||guessdight2==lotterydight1||guessdight2==lotterydight2)
        {
            System.out.println("You win 1000$");

        }
        else
        {
            System.out.println("Sorry , no match");
        }
    }
}
