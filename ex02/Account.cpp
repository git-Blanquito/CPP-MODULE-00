/* **************************************************************************** */
/*                                                                              */
/*                                                         :::      ::::::::    */
/*    Makefile                                           :+:      :+:    :+:    */
/*                                                     +:+ +:+         +:+      */
/*    By: aiblanco <marvin@42.fr>                    +#+  +:+       +#+         */
/*                                                 +#+#+#+#+#+   +#+            */
/*    Created: 2024/06/10 23:05:13 by aiblanco          #+#    #+#              */
/*    Updated: 2024/06/10 23:05:21 by aiblanco         ###   ########.fr        */
/*                                                                              */
/* **************************************************************************** */

#include "Account.hpp"
#include <time.h>
#include <iostream>
#include <iomanip>
using namespace std;

int	Account::_nbAccounts = 0;

int	Account::_totalAmount = 0;

int	Account::_totalNbDeposits = 0;

int	Account::_totalNbWithdrawals = 0;


Account::Account(int initial_deposit)
{
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	this->_accountIndex = _nbAccounts - 1;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	cout << "index:" 
		<< this->_accountIndex 
		<< ";ammount:" 
		<< this->_amount 
		<< ";created" << endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	cout << "index:" 
		<< this->_accountIndex 
		<< ";ammount:" 
		<< this->_amount 
		<< ";closed" << endl;
	Account::_totalAmount -= _amount;
	Account::_nbAccounts--;
}

void Account::_displayTimestamp(void)
{
	time_t	now;
	tm *	tm_struct;

	now = time(0);
	tm_struct = localtime(&now);
	cout << put_time(tm_struct, "[%Y%m%d_%H%M%S] ");
}

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

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	cout << "accounts:" 
		<< Account::getNbAccounts() 
		<< ";total:" 
		<< Account::getTotalAmount() 
		<< ";deposits:" 
		<< Account::getNbDeposits() 
		<< ";withdrawals:" 
		<< Account::getNbWithdrawals() 
		<< endl;
}

void	Account::makeDeposit(int deposit)
{
	Account::_totalNbDeposits++;
	Account::_nbDeposits++;
	_displayTimestamp();
	cout << "index:" 
		<< this->_accountIndex 
		<< ";p_amount:" 
		<< this->_amount 
		<< ";deposit:" 
		<< deposit 
		<< ";amount:"
		<< (this->_amount + deposit)
		<< ";withdrawals:" 
		<< this->_nbWithdrawals 
		<< endl;
	Account::_amount += deposit;
	Account::_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount >= withdrawal)
	{
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		_displayTimestamp();
		cout << "index:" 
			<< this->_accountIndex 
			<< ";p_amount:" 
			<< this->_amount 
			<< ";withdrawal:" 
			<< withdrawal 
			<< ";amount:"
			<< (this->_amount - withdrawal)
			<< ";withdrawals:" 
			<< this->_nbWithdrawals 
			<< endl;
		Account::_totalAmount -= withdrawal;
		Account::_amount -= withdrawal;
		return (true);
	}
	else
	{
		_displayTimestamp();
		cout << "index:" 
			<< this->_accountIndex 
			<< ";p_amount:" 
			<< this->_amount 
			<< ";withdrawal:" 
			<< "refused"
			<< endl;
		return (false);
	}
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	cout << "index:" 
		<< this->_accountIndex 
		<< ";amount:" 
		<< this->_amount 
		<< ";deposits:" 
		<< this->_nbDeposits 
		<< ";withdrawals:" 
		<< this->_nbWithdrawals 
		<< endl;
}
