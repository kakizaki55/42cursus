#include "Account.hpp"
#include <iostream>

// this is for all accounts
int Account ::	_nbAccounts = 0; 			// total number of accounts
int Account ::	_totalAmount = 0;			// total amount of money in account
int Account ::	_totalNbDeposits = 0;		// total number of deposts done on account
int Account ::	_totalNbWithdrawals = 0;	// total number of withdraws done in account

//constuctor
Account :: Account(int initail_deposit)
{
	// this adds to all the accounts
	_totalAmount += initail_deposit;
	_amount += initail_deposit;

	// this initializes the account
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	//this displayes the account
	_displayTimestamp();
	checkAmount();
	std:: cout << ";created" << std :: endl;
	_nbAccounts++;
}

Account :: ~Account()
{
	_displayTimestamp();
	checkAmount();
	std:: cout <<";closed" << std :: endl;
}

//PRIVATE FUNCTIONS

int	Account :: getNbAccounts( void )
{
	return _nbAccounts;
}
int	Account :: getTotalAmount( void )
{
	return _totalAmount;
}
int	Account :: getNbDeposits( void )
{
	return _totalNbDeposits;
}
int	Account :: getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void Account :: displayAccountsInfos( void )
{
	_displayTimestamp();
	std :: cout << "accounts:"<< getNbAccounts();			// totalnumber of accounts?
	std :: cout << ";total:" << getTotalAmount();			// total amount of money in account
	std :: cout << ";deposits:" << getNbDeposits();			// total number of deposts done on account
	std :: cout << ";withdrawals:" << getNbWithdrawals();	// total number of withdraws done in account
	std :: cout << std :: endl;
	return ;
}

// PUBLIC FUNCTIONS
void Account ::	makeDeposit( int deposit )
{
	_displayTimestamp();
	if(deposit < 0)
	{
		std :: cout << "index:" << _accountIndex;
		std :: cout << ";p_amount:" << _amount;
		std :: cout << ";deposit:refused" << std :: endl;
		return ;
	} else {
		_amount += deposit;
		_totalAmount += deposit;
		_nbDeposits++;
		_totalNbDeposits++;
		std :: cout << "index:" << _accountIndex;
		std :: cout << ";p_amount:" << _amount - deposit;
		std :: cout << ";deposit:" << deposit;
		std :: cout << ";amount:" << _amount;
		std :: cout << ";nb_deposits:" << _nbDeposits << std :: endl;
	}
}

bool Account ::	makeWithdrawal( int withdrawal )
{
	_displayTimestamp();

	if(withdrawal > _amount)
	{
		std :: cout << "index:" << _accountIndex;
		std :: cout << ";p_amount:" << _amount;
		std :: cout << ";withdrawal:refused" << std :: endl;
		return false;
	} else {
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std :: cout << "index:" << _accountIndex;
		std :: cout	<< ";p_amount:" << _amount + withdrawal;
		std :: cout << ";withdrawal:" << withdrawal;
		std :: cout << ";amount:" << _amount;
		std :: cout << ";nb_withdrawals:" << _nbWithdrawals << std :: endl;
	}
	return true;
}

int Account ::	checkAmount( void ) const
{
	std::cout << "index:" << _accountIndex;
	std:: cout << ";amount:" << _amount;
	return 0;
}

void Account ::	displayStatus( void ) const
{
	_displayTimestamp();
	std :: cout << "index:" << _accountIndex;
	std :: cout << ";amount:" << _amount;
	std :: cout	<< ";deposits:" << _nbDeposits;
	std :: cout << ";withdrawals:" << _nbWithdrawals << std :: endl;
	return ;
}

void Account :: _displayTimestamp( void )
{
	time_t now = time(0);
	std :: cout << "[" << now << "] ";
	return ;
}
