package ATM.ATM3;
public class Test {
    public static void main(String[] args)
    {
        NewAccount account=new NewAccount("Tom",0.015,1234,1000);
        account.deposit(30);
        account.deposit(40);
        account.deposit(50);
        account.withDraw(5);
        account.withDraw(4);
        account.withDraw(2);
        for(int i=0;i<account.transactions.size();i++){
            System.out.print(account.transactions.get(i)+" ");
            System.out.println();}
    }
}