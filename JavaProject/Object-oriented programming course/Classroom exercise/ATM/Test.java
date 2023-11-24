//package ATM;
//
//import java.util.Scanner;
//
//public class Test
//{
//    public static void main(String[] args)
//    {
//        Scanner sc = new Scanner(System.in);
//        Account[] account = new Account[10];  //新建10个账户
//
//        for(int i = 0; i < 10; i ++ )
//        {
//            account[i] = new Account(i,100);
//        }
//
//        System.out.print("Enter an id: ");
//        int id = sc.nextInt();
//            while(true)
//            {
//                if(id >=0 && id < 10) break;
//                else
//                {
//                    System.out.print("Id error\nEnter an id: ");
//                    id = sc.nextInt();
//                }
//            }
//        while(true)
//        {
//            System.out.println("Main menu");
//            System.out.println("1: check balance");
//            System.out.println("2: withdraw");
//            System.out.println("3: deposit");
//            System.out.println("4: exit");
//            System.out.print("Enter a choice: ");
//            int choice = sc.nextInt();
//
//            switch (choice)
//            {
//                case 1:
//                    {
//                        System.out.println("The balance is " + account[id].getBalance());
//                    }
//                break;
//
//                case 2:
//                    {
//                        System.out.print("Enter an amount to withdraw: ");
//                        double money = sc.nextInt();
//                        if (money > account[id].getBalance())
//                        {
//                            System.out.println("The amount is too large, ignored");
//                        } else account[id].withDraw(money);
//                    }
//                break;
//                case 3:
//                    {
//                        System.out.print("Enter an amount to deposit: ");
//                        double money = sc.nextDouble();
//                        account[id].deposite(money);
//                    }
//                break;
//                case 4:
//                    {
//                        System.out.print("Enter an id: ");
//                        id = sc.nextInt();
//                        System.out.println("Main menu");
//                        System.out.println("1: check balance");
//                        System.out.println("2: withdraw");
//                        System.out.println("3: deposit");
//                        System.out.println("4: exit");
//                    }
//                default:
//                    break;
//            }
//        }
//    }
//}
