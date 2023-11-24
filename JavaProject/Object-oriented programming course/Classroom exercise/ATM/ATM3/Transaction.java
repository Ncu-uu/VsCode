package ATM.ATM3;
import javax.xml.namespace.QName;
import java.util.*;
public class Transaction
{
    Date date;
    char type;
    double amount;
    double balance;
    String description;
    public Transaction(){
        date=new Date();
        description=new String();
    }
    public Transaction(char type,double amount,double balance,String description){
        this.type=type;
        this.amount=amount;
        this.balance=balance;
        this.description=description;
    }
    public Date getDate(){
        return date;
    }
    public char getType(){
        return type;
    }
    public double getAmount()
    {
        return amount;

    }
    public double getBalance()
    {
        return balance;

    }
    public String getDescription(){
        return description;
    }
    public void setDate(Date date){
        this.date=date;
    }
    public void setType(char type){
        this.type=type;
    }
    public void setAmount(double amount){
        this.amount=amount;
    }
    public void setBalance(double balance){
        this.balance=balance;
    }
    public void setDescription(String description){
        this.description=description;
    }
    public String toString()
    {
        return "Name: Tom\n"+ "Type: " + type + "\namount: " + amount +"\nBalance: " + balance +"\n";
    }

}