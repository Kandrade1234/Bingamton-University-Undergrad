package lab01;

/**
 * A class representing a person taking out a loan
 */
public class Loanee {
    private int money;

    /**
     * Construct a loanee object given an amount of money (in dollars)
     * @param money the amount of dollars the person has
     */
    public Loanee(int money) {
        this.money = money;
    }

    /**
     * Gets the money the Loanee has
     * @return the money the Loanee has
     */
    // TODO fill in the blanks, use the Loan class as a guide
    public int getMoney() {
        return money;
    }

    public boolean canPayLoan(double amt, double ir, int years) {
	Loan l = new Loan (amt, ir);
       
	
	return l.getAmountDue(years) <= this.money;
	
    }
}