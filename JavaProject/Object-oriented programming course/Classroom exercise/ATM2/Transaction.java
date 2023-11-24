package ATM2;
public class Transaction {
    private char type;
    private double amount;
    private double balance;
    private String description;

    public Transaction(char type, double amount, double balance, String description) {
        this.type = type;
        this.amount = amount;
        this.balance = balance;
        this.description = description;
    }

    public char getType() {
        return type;
    }

    public double getAmount() {
        return amount;
    }

    public double getBalance() {
        return balance;
    }

    public String getDescription() {
        return description;
    }

    public String toString() {
        return "Type: " + type + "\n" +
                "Amount: " + amount + "\n" +
                "Balance: " + balance + "\n" +
                "Description: " + description + "\n";
    }
}
