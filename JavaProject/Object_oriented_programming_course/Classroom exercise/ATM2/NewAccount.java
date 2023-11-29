package ATM2;
public class NewAccount extends Account {
    private String name;

    public NewAccount(String name, int id, double balance) {
        super(id, balance);
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void withdraw(double amount)  {
        if (getBalance() >= amount) {
            super.withdraw(amount);
            transactions.add(new Transaction('W', amount, getBalance(), "Withdrawal"));
        } else {
            System.out.println("Insufficient funds");
        }
    }

    public void deposit(double amount) {
        super.deposit(amount);
        transactions.add(new Transaction('D', amount, getBalance(), "Deposit"));
    }

    public String toString() {
        return "Name: " + name + "\n" + super.toString();
    }
}