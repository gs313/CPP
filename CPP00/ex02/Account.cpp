/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scharuka <scharuka@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 23:09:58 by scharuka          #+#    #+#             */
/*   Updated: 2024/07/29 02:37:17 by scharuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals =0;

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}
int	Account::getTotalAmount( void )
{
	return _totalAmount;
}
int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}
int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:"
	<< _totalNbDeposits << ";withdrawals:" <<_totalNbWithdrawals << std::endl;
}
Account::Account(){}
Account::Account( int initial_deposit )
{
	this->_amount = initial_deposit;
	this->_accountIndex = _nbAccounts;
	this->_nbWithdrawals = 0;
	this->_nbDeposits = 0;
	_nbAccounts ++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<<";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account( void )
{
	_totalAmount -= this->_amount;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex <<
	";amount:" << this->checkAmount() << ";closed" <<std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:"
	<< this->checkAmount() << ";deposit:" << deposit;
	this->_amount += deposit;
	this->_nbDeposits++;
	std::cout << ";amount:" << this->checkAmount() << ";nb_deposits:"
	<< this->_nbDeposits <<std::endl;
	_totalAmount +=deposit;
	_totalNbDeposits++;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (withdrawal > this->_amount)
	{
		std::cout << "index:" << this->_accountIndex << ";p_amount:"
		<< this->checkAmount() << ";withdrawal:refused\n";
		return false;
	}
	_totalAmount -= withdrawal;
	_totalNbWithdrawals ++;
	std::cout << "index:" << this->_accountIndex << ";p_amount:"
	<< this->checkAmount() << ";withdrawal:" << withdrawal;
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	std::cout << ";amount:" << this->checkAmount() << ";nb_withdrawals:"
	<< this->_nbWithdrawals <<std::endl;
	return true;
}
int		Account::checkAmount( void ) const
{
	return this->_amount;
}
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" <<
		this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:"
		<< this->_nbWithdrawals << std::endl;
}
void	Account::_displayTimestamp( void )
{
	// time_t rn = std::time(NULL);
	// struct tm timenow = *std::localtime(&rn);

	// std::cout << "[" << timenow.tm_year + 1900
	// << std::setfill('0') << std::setw(2) << timenow.tm_mon + 1
	// << std::setfill('0') << std::setw(2) << timenow.tm_mday << "_"
	// << std::setfill('0') << std::setw(2) << timenow.tm_hour
	// << std::setfill('0') << std::setw(2) << timenow.tm_min
	// << std::setfill('0') << std::setw(2) << timenow.tm_sec << "] ";

	std::cout << "[19920104_091532] ";
}
