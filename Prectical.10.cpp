#include <iostream>
#include <exception>
using namespace std;

class InvalidWithdrawal : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Invalid amount! Amount must be greater than zero.";
    }
};

class BalanceError : public exception
{
public:
    const char *what() const noexcept override
    {
        return "InsufficientFunds! Balance is too low.";
    }
};

class Account
{
    double balance;

public:
    Account(double balance)
    {
        this->balance = balance;
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            throw InvalidWithdrawal();
        }
        else if (amount > balance)
        {
            throw BalanceError();
        }
        else
        {

            balance -= amount;
            cout << "Amount successfully withdrawn: " << amount << "\n";
        }
    }

    void showBalance()
    {
        cout << "Balance:  " << balance << "\n";
    }
};

int main()
{
    cout << "Student name: RAMESH KUMAR\nURN: E25B001202\n\n";

    Account account(1000);
    cout << "Initial ";
    account.showBalance();

    try
    {
        account.withdraw(200);
    }
    catch (const InvalidWithdrawal &e)
    {
        cout << e.what() << "\n";
    }
    catch (const BalanceError &e)
    {
        cout << e.what() << "\n";
    }
    account.showBalance();

    try
    {
        account.withdraw(2000);
    }
    catch (const InvalidWithdrawal &e)
    {
        cout << e.what() << "\n";
    }
    catch (const BalanceError &e)
    {
        cout << e.what() << "\n";
    }
    account.showBalance();

    try
    {
        account.withdraw(-200);
    }
    catch (const InvalidWithdrawal &e)
    {
        cout << e.what() << "\n";
    }
    catch (const BalanceError &e)
    {
        cout << e.what() << "\n";
    }
    account.showBalance();

    return 0;
}