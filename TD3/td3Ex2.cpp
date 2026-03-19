#include <iostream>
using namespace std;

class BankAccount {
protected:
    double balance;

public:
    BankAccount(double b = 0) {
        balance = b;
    }

    void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        }
        else {
            cout << "Fonds insuffisants\n";
        }
    }

    virtual void display() {
        cout << "Solde : " << balance << endl;
    }
};


//CHECKING ACCOUNT

class CheckingAccount : public BankAccount {
private:
    double fee;

public:
    CheckingAccount(double b, double f) : BankAccount(b) {
        fee = f;
    }

    void withdraw(double amount) override {
        double total = amount + fee;
        if (total <= balance) {
            balance -= total;
        }
        else {
            cout << "Fonds insuffisants (avec frais)\n";
        }
    }

    void display() override {
        cout << "Compte courant - Solde : " << balance << endl;
    }
};


//SAVINGS ACCOUNT

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(double b, double rate) : BankAccount(b) {
        interestRate = rate;
    }

    void addInterest() {
        balance += balance * interestRate;
    }

    void display() override {
        cout << "Compte epargne - Solde : " << balance << endl;
    }
};

//MAIN

int main() {
    BankAccount b1(100);
    b1.deposit(50);
    b1.withdraw(30);
    b1.display();

    CheckingAccount c1(100, 2);
    c1.withdraw(50);
    c1.display();

    SavingsAccount s1(200, 0.05);
    s1.addInterest();
    s1.display();

    return 0;
}