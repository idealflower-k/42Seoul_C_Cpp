/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:58:38 by sanghwal          #+#    #+#             */
/*   Updated: 2023/04/27 15:01:05 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

Account::Account(int initial_deposit) {
	_displayTimestamp();
	this->_amount = initial_deposit;
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

// int	getNbAccounts( void );
int	Account::getNbAccounts(void) {
	
}

// int	getTotalAmount( void );
int	Account::getTotalAmount(void) {
	
}

// int	getNbDeposits( void );
int	Account::getNbDeposits(void) {
	
}

// int	getNbWithdrawals( void );
int	Account::getNbWithdrawals(void) {
	
}

// void	displayAccountsInfos( void );
void	Account::displayAccountsInfos(void) {
	_displayTimestamp();

	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << "\n";
}

// void	makeDeposit( int deposit );
void	Account::makeDeposit(int deposit) {
	_displayTimestamp();

	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	
	this->_amount += deposit;
	this->_nbDeposits += 1;
	
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << "\n";
}

// bool	makeWithdrawal( int withdrawal );
bool	Account::makeWithdrawal(int withdrawal) {
	
}

// int		checkAmount( void ) const;
int	Account::checkAmount(void) const{
	
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
