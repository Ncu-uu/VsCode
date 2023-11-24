package ATM.ATM3;
import java.util.*;
public class NewAccount extends Account
{
    String name;
    java.util.ArrayList transactions=new java.util.ArrayList();

    NewAccount(String name,double annualInterestRate,int id,double balance)
    {
        super(id,balance,annualInterestRate);
        this.name=name;
    }
    public ArrayList<Transaction> getTransaction(){
        return transactions;
    }
    public  void withDraw(double num){
        super.withDraw(num);
        transactions.add(new Transaction('W',num,super.getBalance(),(new Date()).toString()));

    }
    public void deposit(double num){
        super.deposit(num);
        transactions.add(new Transaction('D',num,super.getBalance(),(new Date()).toString()));

    }
}