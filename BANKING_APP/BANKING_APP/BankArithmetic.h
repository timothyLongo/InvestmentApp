#pragma once
#ifndef BANKARITHMETIC_h
#define BANKARITHMETIC_h
// private members start with m_
// function parameters start with t_

// class declaration

class BankArithmetic {

public:
	// constructor with parameters
	BankArithmetic(double t_moneyUpFront, double t_monthlyMoney, double t_interestRate, int t_numYears);
	double getYearlyBalance(int t_yearNum, bool monthlyDeposits = true);
	double getYearlyInterestEarned(int t_yearNum, bool monthlyDeposits = true);
	int getYears();

private:
	double m_moneyUpFront;
	double m_monthlyMoney;
	double m_interestRate;
	int m_numYears;

};
#endif // BANKARITHMETIC_h

