package Loan;

import java.util.Date;

public class Loan
{
    private double annualInterestRate ;
    private int numberOfYears ;
    private double loanAmount ;

   private Date loanDate ;


    public Loan(double annualInterestRate, int numberOfYears, double loanAmount) {
        this.annualInterestRate = annualInterestRate;
        this.numberOfYears = numberOfYears;
        this.loanAmount = loanAmount;
        loanDate = new Date();
    }

    public Loan()
    {
        this(2.5,1,100);
    }

    public double getAnnualInterestRate()
    {
        return this.annualInterestRate;
    }
    public int getNumberOfYears()
    {
        return this.numberOfYears;
    }
    public double getLoanAmount()
    {
        return this.loanAmount;
    }
    public Date getLoanDate()
    {
        return this.loanDate;
    }

    public void setAnnualInterestRate(double annualInterestRate) {
        this.annualInterestRate = annualInterestRate;
    }

    public void setNumberOfYears(int numberOfYears) {
        this.numberOfYears = numberOfYears;
    }

    public void setLoanAmount(double loanAmount) {
        this.loanAmount = loanAmount;
    }

    public double getMonthlyPayment()
    {
        return 0;
    }

    public double getTotalPayment()
    {
        return 0;
    }


}
