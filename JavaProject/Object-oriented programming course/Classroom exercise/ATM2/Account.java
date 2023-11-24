package ATM2;
import java.util.ArrayList;
import java.util.Scanner;

public class Account {
    private int id;
    private double balance;
    private static double annualInterestRate;
    ArrayList<Transaction> transactions;

    public Account(int id, double balance) {
        this.id = id;
        this.balance = balance;
        transactions = new ArrayList<Transaction>();
    }

    public int getId() {
        return id;
    }

    public double getBalance() {
        return balance;
    }

    public static double getAnnualInterestRate() {
        return annualInterestRate;
    }

    public static void setAnnualInterestRate(double annualInterestRate) {
        Account.annualInterestRate = annualInterestRate;
    }

    public double getMonthlyInterest() {
        return balance * (annualInterestRate / 12);
    }

    public void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            transactions.add(new Transaction('W', amount, balance, "Withdrawal"));
        } else {
            System.out.println("Insufficient funds");
        }
    }

    public void deposit(double amount) {
        balance += amount;
        transactions.add(new Transaction('D', amount, balance, "Deposit"));
    }

    public void printTransactions()
    {
        System.out.println("Transaction history:");
        for (Transaction t : transactions)
        {
            System.out.println(t);
        }
    }

    public static void main(String[] args)
    {
        Account[] accounts = new Account[10];
        for (int i = 0; i < accounts.length; i++)
        {
            accounts[i] = new Account(i, 100);
        }

        Scanner input = new Scanner(System.in);
        int id;
        do
        {
            System.out.print("Enter an id: ");
            id = input.nextInt();
            if (id < 0 || id >= accounts.length)
            {
                System.out.println("Invalid id");
            }
        } while (id < 0 || id >= accounts.length);

        Account currentAccount = accounts[id];

        int choice;
        do {
            System.out.println("Main menu");
            System.out.println("1: Check balance");
            System.out.println("2: Withdraw");
            System.out.println("3: Deposit");
            System.out.println("4: View transactions");
            System.out.println("5: Exit");
            System.out.print("Enter a choice: ");
            choice = input.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("The balance is " + currentAccount.getBalance());
                    break;
                case 2:
                    System.out.print("Enter an amount to withdraw: ");
                    double amount = input.nextDouble();
                    currentAccount.withdraw(amount);
                    break;
                case 3:
                    System.out.print("Enter an amount to deposit: ");
                    amount = input.nextDouble();
                    currentAccount.deposit(amount);
                    break;
                case 4:
                    currentAccount.printTransactions();
                    break;
                case 5:
                    break;
                default:
                    System.out.println("Invalid choice");
            }
        } while (choice != 5);
    }
}