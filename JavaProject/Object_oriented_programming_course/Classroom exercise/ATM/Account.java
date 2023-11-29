//package ATM;
//
//import java.util.Date;
//public class Account
//{
//    private int id = 0;
//    private String name;
//    private double balance = 0.0;
//    private double annualInterestRate = 0.0;
//    private Date dateCreate;
//
//
//    //构造方法
//    public Account()
//    {
//        this.dateCreate = new Date();
//    };
//    public Account(int id,double balance)
//    {
//        this.id = id;
//        this.balance = balance;
//    }
//
//    public Account(int id,double balance,String name)
//    {
//        this.dateCreate = new Date();
//        this.id = id;
//        this.balance = balance;
//        this.name = name;
//    }
//
////访问器和修改器
//
//    public void setId(int id)
//    {
//        this.id = id;
//    }
//
//    public int getId()
//    {
//        return id;
//    }
//
//    public void setBalance(double balance)
//    {
//        this.balance = balance;
//    }
//
//    public double getBalance()
//    {
//        return balance;
//    }
//
//    public void setAnnualInterestRate(double annualInterestRate)
//    {
//        this.annualInterestRate = annualInterestRate;
//    }
//
//    public double getAnnualInterestRate()
//    {
//        return annualInterestRate;
//    }
//
//    public Date getDateCreated()
//    {
//        return dateCreate;
//    }
//    public void setName(String name)
//    {
//        this.name = name;
//    }
//    public String getName()
//    {
//        return name;
//    }
//
////月利息
//
//    public double getMonthInterestRate()
//    {
//        return this.balance * this.annualInterestRate/12;
//    }
//
////取款
//
//    public void withDraw(double money)
//    {
//        this.balance -= money;
//    }
//
////存款
//
//    public void deposite(double money)
//    {
//        this.balance += money;
//    }
//}
