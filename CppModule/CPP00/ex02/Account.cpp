/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:58:38 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/28 15:53:52 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	_displayTimestamp();

	this->_accountIndex = _nbAccounts + 1;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts += 1;
	_totalAmount += this->_amount;

	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

// int	getNbAccounts( void );
int	Account::getNbAccounts(void) {
	return (_nbAccounts);
}

// int	getTotalAmount( void );
int	Account::getTotalAmount(void) {
	return (_totalAmount);
}

// int	getNbDeposits( void );
int	Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

// int	getNbWithdrawals( void );
int	Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

// void	displayAccountsInfos( void );
void	Account::displayAccountsInfos(void) {
	_displayTimestamp();

	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << "\n";
}

// void	makeDeposit( int deposit );
void	Account::makeDeposit(int deposit) {
	_displayTimestamp();

	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits += 1;
	_totalNbDeposits += 1;
	
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << "\n";
}

// bool	makeWithdrawal( int withdrawal );
bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();

	std::cout << "index" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "withdrawal:";

	if (checkAmount() < withdrawal) {
		{std::cout << "refused" << std::endl;}
		return (false);
	}

	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	this->_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;

	std::cout << withdrawal << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

// int		checkAmount( void ) const;
int	Account::checkAmount(void) const{
	return (this->_amount);
}

// void	displayStatus( void ) const;
void	Account::displayStatus(void) const {
	_displayTimestamp();

	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}

// void	_displayTimestamp( void );
void	Account::_displayTimestamp(void) {
	std::time_t t = std::time(NULL);
    char timestamp[16];
    std::strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", std::localtime(&t));
    std::cout << "[" << timestamp << "] ";
}

Account::~Account(void) {
	_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << "\n";
}