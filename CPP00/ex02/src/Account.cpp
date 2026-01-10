#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

// static data definitions
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructor/destructor
Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts),
	  _amount(initial_deposit),
	  _nbDeposits(0),
	  _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";created\n";
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";closed\n";
}

// static helper functions
void Account::_displayTimestamp(void)
{
	std::time_t epochTime;
	std::time(&epochTime);
	std::tm* now = std::localtime(&epochTime);

	std::cout << '['
			  << (now->tm_year + 1900)
			  << std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
			  << std::setw(2) << std::setfill('0') << now->tm_mday
			  << '_'
			  << std::setw(2) << std::setfill('0') << now->tm_hour
			  << std::setw(2) << std::setfill('0') << now->tm_min
			  << std::setw(2) << std::setfill('0') << now->tm_sec
			  << "] ";
}

// static public functions
int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
}

// member functions
void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();

	int	p_amount = _amount; // store previous amount

	_amount += deposit;        // update account balance
	_nbDeposits++;			   // increment acount deposits

	_totalAmount += deposit;   // update total balance
	_totalNbDeposits++;        // increment total deposits

	//print log
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << p_amount
			  << ";deposit:" << deposit
			  << ";amount:" << _amount
			  << "nb_deposits:" << _nbDeposits
			  << '\n';
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();

	int p_amount = _amount;

	if (_amount < withdrawal)
	{
		std::cout << "index:" << _accountIndex
				  << "p_amount:" << p_amount
				  << ";withdrawal:refused\n";
		return (false);
	}

	_amount -= withdrawal;
	_nbWithdrawals++;

	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << p_amount
			  << ";withdrawal:" << withdrawal
			  << ";amount" << _amount
			  << ";nb_withdrawals:" << _nbWithdrawals
			  << '\n';

	return (true);
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << '\n';
}
