/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 15:45:41 by rsao-pay          #+#    #+#             */
/*   Updated: 2026/05/28 15:29:42 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Account.hpp"
# include <iostream>
# include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit): _amount(initial_deposit), _nbDeposits(0)
{
    _accountIndex = _nbAccounts;
    _totalAmount += initial_deposit;
    _nbAccounts++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << initial_deposit << ";";
    std::cout << "created" << std::endl;
    return ;
}

Account::~Account(void)
{
    return ;
}

int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int Account::getNbDeposits(void)
{
    return _totalNbDeposits;    
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

int Account::getTotalAmount(void)
{
    return _totalAmount;    
}

int Account::checkAmount(void) const
{
    return this->_amount;
}

void Account::_displayTimestamp(void)
{
    char buff[32];
    time_t t;
    struct tm *dt;

    t = time(NULL);
    dt = localtime(&t);

    strftime(buff, sizeof(buff), "[%Y%m%d_%H%M%S] ", dt);
    std::cout << buff;
    return ;
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
    return ;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_totalAmount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
    return ;
}

void Account::makeDeposit(int deposit)
{
    int p_amount = checkAmount();
    this->_amount += deposit;
    this->_nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << p_amount << ";";
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << this->_totalAmount << ";";
    std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
    return ;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << checkAmount() << ";";

    if(checkAmount() >= withdrawal)
    {
        this->_amount -= withdrawal;
        this->_nbWithdrawals++;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;

        std::cout << "withdrawal:" << withdrawal << ";";
        std::cout << "amount:" << this->_totalAmount << ";";
        std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
        return true;
    }
    else
        std::cout << "withdrawal:refused" << std::endl;
    return false;
}
