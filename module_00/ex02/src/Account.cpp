//
// Created by Diana catherine Salamanca leguizamon on 07-Feb-22
//

#include "../includes/Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;

	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
			  << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::Account() {
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount << ";created" << std::endl;
}

/**
 * The elements will be destroyed in order of decreasing address,
 * that means, in reverse order of the completion of their constructor.
 */
Account::~Account() {
	Account::_nbAccounts--;
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:"
			  << checkAmount() << ";closed" << std::endl;
}

int Account::getNbAccounts() {
	return Account::_nbAccounts;
}

int Account::getTotalAmount() {
	return Account::_totalAmount;
}

int Account::getNbDeposits() {
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals() {
	return Account::_totalNbWithdrawals;
}

int Account::checkAmount() const {
	return this->_amount;
}

void Account::displayAccountsInfos() {
	Account::_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts()
			  << ";total:" << getTotalAmount()
			  << ";deposits:" << getNbDeposits()
			  << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus() const {
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";deposits:" << this->_nbDeposits
			  << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
			  << ";p_amount:" << checkAmount()
			  << ";deposit:" << deposit;

	this->_amount += deposit;
	std::cout << ";amount:" << this->_amount;

	this->_nbDeposits++;
	std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;

	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
			  << ";p_amount:" << checkAmount()
			  << ";withdrawal:";

	if ((this->_amount - withdrawal) < 0) {
		std::cout << "refused" << std::endl;
		return false;
	} else {
		this->_amount -= withdrawal;
		std::cout << withdrawal
				  << ";amount:" << checkAmount();
		this->_nbWithdrawals++;
		std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		return true;
	}
}

/**
 * tm_mon + 1 because months are since January and range is 0-11
 */
void Account::_displayTimestamp() {
	std::time_t rawTime = time(NULL);
	std::tm *timeInfo = localtime(&rawTime);
	std::cout << "[" << 1900 + timeInfo->tm_year
			  << std::setw(2) << std::setfill('0') << timeInfo->tm_mon + 1
			  << std::setw(2) << timeInfo->tm_mday << "_"
			  << std::setw(2) << timeInfo->tm_hour
			  << std::setw(2) << timeInfo->tm_min
			  << std::setw(2) << timeInfo->tm_sec << "]";
}
