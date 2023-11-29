package ATM.ATM3;
import java.util.Date;

public class Account
{
    private int id = 0;
    private double balance=100;
    private double annualInterestRate;
    Date dateCreated;
    Account()
    {
        dateCreated = new Date();
    }
    Account(int id, double balance, double annualInterestRate)
    {
        this.id=id;
        this.balance = balance;
        dateCreated = new Date();
    }

    int getId()
    {
        return id;
    }
    double getBalance()
    {
        return balance;
    }
    double getAnnualInterestRate()
    {
        return annualInterestRate;
    }
    void setId(int id)
    {
        this.id=id;
    }
    void setBalance(double balance)
    {
        this.balance=balance;
    }
    void setAnnualInterestRate(double annualInterestRate)
    {
        this.annualInterestRate=annualInterestRate;
    }
    Date getDateCreated()
    {
        return dateCreated;
    }
    double getMonthlyInterest()
    {
        return this.annualInterestRate/12;
    }
    void withDraw(double amount)
    {
        if(amount>balance)
        {
            System.out.println("Your balance is not enough!");
        }
        else
            this.balance -= amount;
    }
    void deposit(double amount)
    {
        this.balance += amount;
    }

}