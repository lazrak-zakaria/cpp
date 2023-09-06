/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:16:54 by zlazrak           #+#    #+#             */
/*   Updated: 2023/05/16 09:54:28 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

// we may want a static function shared among all objects.
// 	● This means it can’t access data member
// 	● But can access static data member as it is shared

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposite)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposite;
	_totalAmount += _amount;
	_nbWithdrawals = _nbDeposits = 0; 
	_displayTimestamp( );
	std ::cout << "index:" << _accountIndex << ";";
	std ::cout << "amount:"<< _amount << ";";
	std ::cout << "created\n";
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp( );
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	std::cout <<"amount:" << this->_amount << ";" << "nb_deposits:" << ++this->_nbDeposits << "\n";
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp( );
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (withdrawal > this->_amount)
	{
		std::cout << "withdrawal:refused\n";
		return (false);
	}
	std::cout << "withdrawal:" << withdrawal << ";";
	this->_amount -= withdrawal;
	std::cout <<"amount:" << this->_amount << ";" << "nb_withdrawals:" << ++this->_nbWithdrawals << "\n";
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp( );
	std::cout << "index:"  << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << ";\n";
}

Account::~Account( void )
{
	_displayTimestamp( );
	
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed\n";
}

/*					static member functions					*/


int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp( );
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << "\n";
}

// https://cplusplus.com/reference/ctime/time/
// https://cplusplus.com/reference/iomanip/put_time/

void	Account::_displayTimestamp( void )
{
	std::time_t tt;
	std::time(&tt);
	struct std::tm * ptm = std::localtime(&tt);
	std::cout << std::put_time(ptm,"[%Y%m%d_%H%M%S] ");
}