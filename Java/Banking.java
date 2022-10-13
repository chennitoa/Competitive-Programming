import java.util.*;

class BankAccount {
	private String password;
	private double balance;
	public static final double OVERDRAW_PENALTY = 20.00;
	
	
	public void Account(String acctPassword, double acctBalance) {
		password = acctPassword;
		balance = acctBalance;
	}
	
	public double getBalance() {
		return balance;
	}
	
	public void deposit(String acctPassword, double amount) {
		
	}
	
	public void withdraw(String acctPassword, double amount) {
		
	}
	
}

public class Banking {
	public static void main(String[] args) {
		Account Austin = new Account("Reeeee", 23.45);
		Austin.getBalance();
		
	}
}