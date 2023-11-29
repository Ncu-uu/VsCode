package ATM2;

import java.util.Scanner;

public class TestATM {
    public static void main(String[] args) {
        NewAccount[] accounts = new NewAccount[1234];
//        NewAccount accounts = new NewAccount("Tom",1234,1000);
        for (int i = 0; i < 10; i++) {
            accounts[i] = new NewAccount("Account " + i, i, 100);
        }
        Scanner scanner = new Scanner(System.in);
        int id;
        do {
            System.out.print("Enter an id: ");
            id = scanner.nextInt();
            if (id < 0 || id >= 10) {
                System.out.println("Please enter a correct id");
            } else {
                showMenu();
                int choice;
                do {
                    System.out.print("Enter a choice: ");
                    choice = scanner.nextInt();
                    switch (choice) {
                        case 1:
                            System.out.println("The balance is " + accounts[id].getBalance());
                            continue;
                        case 2:
                            System.out.print("Enter an amount to withdraw: ");
                            double withdrawAmount = scanner.nextDouble();
                            accounts[id].withdraw(withdrawAmount);
                            continue;
                        case 3:
                            System.out.print("Enter an amount to deposit: ");
                            double depositAmount = scanner.nextDouble();
                            accounts[id].deposit(depositAmount);
                            continue;
                        case 4:
                            System.out.println(accounts[id]);
                            continue;
                        default:
                            System.out.println("Please enter a correct choice");
                    }
                } while (choice != 4);
            }
        } while (id < 0 || id >= 10);
    }

    public static void showMenu() {
        System.out.println("Main menu");
        System.out.println("1: Check balance");
        System.out.println("2: Withdraw");
        System.out.println("3: Deposit");
        System.out.println("4: View transaction history");
    }
}





