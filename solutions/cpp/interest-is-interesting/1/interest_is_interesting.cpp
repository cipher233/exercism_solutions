// interest_rate returns the interest rate for the provided balance.
double interest_rate(double balance) {
    // TODO: Implement the interest_rate function
    if (balance >= 0.0 && balance < 1000.0) return 0.5;
    if (balance >= 1000.0 && balance < 5000.0) return 1.621;
    if (balance >= 5000.0) return 2.475;
    return 3.213;
}

// yearly_interest calculates the yearly interest for the provided balance.
double yearly_interest(double balance) {
    // TODO: Implement the yearly_interest function
    return balance * interest_rate(balance) / 100.0;
}

// annual_balance_update calculates the annual balance update, taking into
// account the interest rate.
double annual_balance_update(double balance) {
    // TODO: Implement the annual_balance_update function
    return balance + yearly_interest(balance);
}

// years_until_desired_balance calculates the minimum number of years required
// to reach the desired balance.
int years_until_desired_balance(double balance, double target_balance) {
    // TODO: Implement the years_until_desired_balance function
    int year = 0;
    double cur_balance = balance;
    while (cur_balance < target_balance) {
        cur_balance = annual_balance_update(cur_balance);
        ++year;
    }
    return year;
}
