#include "BankArithmetic.h"


using namespace std;


BankArithmetic::BankArithmetic(double t_moneyUpFront, double t_monthlyMoney, double t_interestRate, int t_numYears) {
	m_moneyUpFront = t_moneyUpFront;
	m_monthlyMoney = t_monthlyMoney;
	m_interestRate = t_interestRate;
	m_numYears = t_numYears;
}


int BankArithmetic::getYears() {
	return m_numYears;
}


double BankArithmetic::getYearlyBalance(int t_yearNum, bool monthlyDeposits) {
	double moneyUpFront = m_moneyUpFront; // assignes objects private members with local
	double monthlyMoney = m_monthlyMoney; // variables to be manipulated and crunched
	double interestRate = m_interestRate;
	int numYears = m_numYears;
	if (monthlyDeposits == true) {
		for (int i = 0; i < (numYears * 12.0); ++i) {
			double monthlyInterest = (moneyUpFront + monthlyMoney) * ((interestRate / 100.0) / 12.0);
			double closingMonthlyBal = monthlyInterest + (moneyUpFront + monthlyMoney);
			moneyUpFront = closingMonthlyBal;
			if (i == ((t_yearNum * 12.0)) - 1) { // using proper symbolic logic for every possible year
				return closingMonthlyBal;
			}
		}
	}
	else if (monthlyDeposits == false) {
		for (int i = 0; i < (numYears * 12.0); ++i) {
			double monthlyInterest = (moneyUpFront) * ((interestRate / 100.0) / 12.0);
			double closingMonthlyBal = monthlyInterest + (moneyUpFront);
			moneyUpFront = closingMonthlyBal;
			if (i == ((t_yearNum * 12.0)) - 1) { // using proper symbolic logic for every possible year
				return closingMonthlyBal;
			}
		}
	}
}


double BankArithmetic::getYearlyInterestEarned(int t_yearNum, bool monthlyDeposits) {
	double moneyUpFront = m_moneyUpFront; // assignes objects private members with local
	double monthlyMoney = m_monthlyMoney; // variables to be manipulated and crunched
	double interestRate = m_interestRate;
	int numYears = m_numYears;
	double monthlyInterestTotal = 0;
	if (monthlyDeposits == true) {
		for (int i = 0; i < (numYears * 12.0); ++i) {
			if ((i % 12) == 0.0) { // uses logic to 'reset' interest earned for the year
				monthlyInterestTotal = 0;
			}
			double monthlyInterest = (moneyUpFront + monthlyMoney) * ((interestRate / 100.0) / 12.0);
			double closingMonthlyBal = monthlyInterest + (moneyUpFront + monthlyMoney);
			moneyUpFront = closingMonthlyBal;

			monthlyInterestTotal = monthlyInterestTotal + monthlyInterest;
			if (i == ((t_yearNum * 12.0)) - 1) { // using proper symbolic logic for every possible year
				return monthlyInterestTotal;
			}
		}
	}
	else if (monthlyDeposits == false) {
		for (int i = 0; i < (numYears * 12.0); ++i) {
			if ((i % 12) == 0.0) { // uses logic to 'reset' interest earned for the year
				monthlyInterestTotal = 0;
			}
			double monthlyInterest = (moneyUpFront) * ((interestRate / 100.0) / 12.0);
			double closingMonthlyBal = monthlyInterest + (moneyUpFront);
			moneyUpFront = closingMonthlyBal;

			monthlyInterestTotal = monthlyInterestTotal + monthlyInterest;
			if (i == ((t_yearNum * 12.0)) - 1) { // using proper symbolic logic for every possible year
				return monthlyInterestTotal;
			}
		}
	}
}