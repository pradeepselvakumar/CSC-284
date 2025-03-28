#include <iostream>

class BankAccount {
public:
    BankAccount(double balance) : balance(balance) {}

    int withdraw(double amount) {
        if (amount <= 0) return -1; // Invalid amount error
        if (amount > balance) return -2; // Insufficient funds error

        balance -= amount;
        return 0; // Success
    }

    double getBalance() const {
        return balance;
    }

private:
    double balance;
};

int main() {
    BankAccount account(500.0);
    double amount;

    std::cout << "Enter amount to withdraw: ";
    std::cin >> amount;

    int result = account.withdraw(amount);

    if (result == -1) {
        std::cerr << "Error: Invalid withdrawal amount." << std::endl;
    }
    else if (result == -2) {
        std::cerr << "Error: Insufficient funds." << std::endl;
    }
    else {
        std::cout << "Withdrawal successful. Remaining balance: $" << account.getBalance() << std::endl;
    }

    return 0;
}
