/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 01:09:34 by diade-so          #+#    #+#             */
/*   Updated: 2026/01/22 18:15:44 by diade-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

// static data definitions
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/**
 * @brief Construct a new Account with an initial deposit
 * @param initial_deposit Initial balance
 */
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

/**
 * @brief Destroy the Account and log closure
 */
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";closed\n";
}

/**
 * @brief Display current timestamp in [YYYYMMDD_HHMMSS] format
 */
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

/** @return Total number of accounts */
int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

/** @return Total balance of all accounts */
int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

/** @return Total number of deposits across all accounts */
int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

/** @return Total number of withdrawals across all accounts */
int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

/**
 * @brief Display summary of all accounts
 */
void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	//print log
	std::cout << "account:" << _nbAccounts
			  << ";total:"  << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals
			  << "\n";
}

/**
 * @brief Make a deposit to this account and update totals
 * @param deposit Amount to deposit
 */
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

/**
 * @brief Attempt to withdraw from this account
 * @param withdrawal Amount to withdraw
 * @return true if successful, false if refused
 */
bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();

	int p_amount = _amount;

	if (_amount < withdrawal)
	{
		std::cout << "index:" << _accountIndex
				  << ";p_amount:" << p_amount
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

/** @return Current account balance */
int	Account::checkAmount(void) const
{
	return (_amount);
}

/**
 * @brief Display the current status of this account
 */
void	Account::displayStatus(void) const
{
	_displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << '\n';
}
