// Timothy Longo

#include <iostream> // input and output stream
#include <iomanip> // text formatting
#include "BankArithmetic.h" // header file for the class BankArithmetic
#include <vector> // add account object to vector, to make accessable wherever

// this app creates an object of class BankArithmetic with parameters input by the user
// the class members are then called to crunch the numbers for the object input by the user

using namespace std;


vector<BankArithmetic> myVec; // declared vector in the global space, so every function has access to it
                              // vector of type BankArithmetic objects

void DisplayChart2() { // chart withOUT monthly deposits
	bool monthlyDeposits = false; // to be passed to our class functions for this chart without monthly deposits
	cout << setw(51) << setfill('-') << "" << endl;
	cout << "||" << setw(6) << setfill(' ') << "" << "Suppose you just let your money sit";
	cout << setw(6) << "" << "||" << endl;
	cout << "||" << setw(11) << setfill(' ') << "" << "without monthly deposits";
	cout << setw(12) << "" << "||" << endl;
	cout << setw(51) << setfill('-') << "" << endl;
	cout << "|  Year | Yearly Balance | Yearly Earned Interest |" << endl;
	cout << setw(51) << setfill('-') << "" << endl;

	for (int i = 0; i < myVec.at(0).getYears(); ++i) { // for every year in the object, execute
		cout << setfill(' ');
		cout << "|   " << setw(3) << left << i + 1 << " |"; // i + 1 shows the year
		cout << "    $" << setw(11) << setfill(' ') << left;
		cout << setprecision(2) << fixed;
		cout << myVec.at(0).getYearlyBalance(i + 1, monthlyDeposits);
		cout << "|       $" << setw(16);
		cout << myVec.at(0).getYearlyInterestEarned(i + 1, monthlyDeposits);
		cout << "|" << endl;
	}
	cout << setw(51) << setfill('-') << "" << endl;
	cout << endl;
}


void DisplayChart1() { // chart WITH monthly deposits
	cout << setw(51) << setfill('-') << "" << endl;
	cout << "||" << setw(15) << setfill(' ') << "" << "Your money grew!";
	cout << setw(16) << "" << "||" << endl;
	cout << setw(51) << setfill('-') << "" << endl;
	cout << "|  Year | Yearly Balance | Yearly Earned Interest |" << endl;
	cout << setw(51) << setfill('-') << "" << endl;

	for (int i = 0; i < myVec.at(0).getYears(); ++i) { // for every year in the object, execute
		cout << setfill(' ');
		cout << "|   " << setw(3) << left << i + 1 << " |"; // i + 1 shows the year
		cout << "    $" << setw(11) << setfill(' ') << left;
		cout << setprecision(2) << fixed;
		cout << myVec.at(0).getYearlyBalance(i + 1);
		cout << "|       $" << setw(16);
		cout << myVec.at(0).getYearlyInterestEarned(i + 1);
		cout << "|" << endl;
	}
	cout << setw(51) << setfill('-') << "" << endl;
	cout << endl;
}


void DisplayMenu() {
	double moneyUpFront; // declaring local variables that will be passed to create object
	double monthlyMoney;
	double interestRate;
	int numYears;
	cout << setw(51) << setfill('-') << "" << endl;
	cout << "||" << setw(5) << setfill(' ') << "" << "Welcome! Let's watch your money grow!";
	cout << setw(5) << "" << "||" << endl;
	cout << setw(51) << setfill('-') << "" << endl << endl;
	cout << "How much would you like to put in the bank?:" << endl;
	// input validation, there must be a cleaner way to do this but this works
	cin >> moneyUpFront;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		system("CLS");
		cout << "     Invalid input -- enter a number" << endl << endl;
		cout << "How much would you like to put in the bank?:" << endl;
		cin >> moneyUpFront;
	}
	cout << "How much will you add every month?:" << endl;
	cin >> monthlyMoney;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		system("CLS");
		cout << "  Invalid input -- enter a number" << endl << endl;
		cout << "How much will you add every month?:" << endl;
		cin >> monthlyMoney;
	}
	cout << "What is your interest rate percentage? (if 5% enter 5):" << endl;
	cin >> interestRate;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		system("CLS");
		cout << "        Invalid input -- enter a number" << endl << endl;
		cout << "What is your interest rate percentage? (if 5% enter 5):" << endl;
		cin >> interestRate;
	}
	cout << "Over how many years would you like to see it grow?:" << endl;
	cin >> numYears;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		system("CLS");
		cout << "         Invalid input -- enter a number" << endl << endl;
		cout << "Over how many years would you like to see it grow?:" << endl;
		cin >> numYears;
	}
	system("CLS");

	
	// create object of BankArithmetic class named UsersAccount
	BankArithmetic UserAccount(moneyUpFront, monthlyMoney, interestRate, numYears);
	myVec.clear(); // clears the vector
	myVec.push_back(UserAccount); // added account to vector
}


int main() {
	
	char userIn;
	bool keepLoopin = true;
	while (keepLoopin) {
		DisplayMenu();
		DisplayChart1();
		DisplayChart2();
		cout << "Enter any key to test other variables. . ." << endl;
		cout << "                    Enter 'q' to quit" << endl;
		cin >> userIn;
		if (userIn == 'q') {
			keepLoopin = false;
		}
		else {
			system("CLS");
		}
	}
	return 0;
}