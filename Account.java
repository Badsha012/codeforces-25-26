class Account {
    private double balance = 5000;
    protected String accountNumber = "ACC12345";

    // Public method to access private balance
    public double getBalance() {
        return balance;
    }
}

class SavingsAccount extends Account {

    void showDetails() {

        

        System.out.println("Account Number: " + accountNumber); 

        System.out.println("Balance: " + getBalance()); 
    }
}

public class Start {
    public static void main(String[] args) {

        SavingsAccount sa = new SavingsAccount();
        sa.showDetails();
    }
}