#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sys/time.h>

// Initialize static class members
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Static method to display timestamp in format [YYYYMMDD_HHMMSS]
void Account::_displayTimestamp(void)
{
    struct timeval tv;
    struct tm *timeinfo;
    char buffer[20];

    gettimeofday(&tv, NULL);
    timeinfo = localtime(&tv.tv_sec);

    // Format: [YYYYMMDD_HHMMSS]
    strftime(buffer, 20, "[%Y%m%d_%H%M%S]", timeinfo);

    std::cout << buffer << " ";
}


// Static methods to retrieve account information
int Account::getNbAccounts(void) {
    return _nbAccounts;
}

int Account::getTotalAmount(void) {
    return _totalAmount;
}

int Account::getNbDeposits(void) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}

// Display information about all accounts
void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

// Constructor with initial deposit
Account::Account(int initial_deposit) {
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

// Destructor
Account::~Account(void) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

// Make a deposit to the account
void Account::makeDeposit(int deposit) {
    int p_amount = _amount;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << p_amount << ";deposit:" << deposit
              << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

// Try to make a withdrawal from the account
bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";

    if (withdrawal > _amount) {
        std::cout << "refused" << std::endl;
        return false;
    }

    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

// Check current account balance
int Account::checkAmount(void) const {
    return _amount;
}

// Display account status
void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
              << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

// Private default constructor - not implemented since it's not used
Account::Account(void) {
}