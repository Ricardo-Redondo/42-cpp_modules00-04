/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:33:15 by rsao-pay          #+#    #+#             */
/*   Updated: 2026/05/14 16:17:39 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"

Contact::Contact(void) : _first_name(""), _last_name(""), _nickname(""), _phone_number(""), _darkest_secret("")
{
    return ;
}

Contact::~Contact(void)
{
    return ;
}

void Contact::set_first_name(std::string first_name)
{
    this->_first_name = first_name;
    return ;
}

void Contact::set_last_name(std::string last_name)
{
    this->_last_name = last_name;
    return ;
}

void Contact::set_nickname(std::string nickname)
{
    this->_nickname = nickname;
    return ;
}

void Contact::set_phone_number(std::string phone_number)
{
    this->_phone_number = phone_number;
    return ;
}

void Contact::set_darkest_secret(std::string darkest_secret)
{
    this->_darkest_secret = darkest_secret;
    return ;
}

std::string Contact::get_first_name()
{
    return this->_first_name;
}

std::string Contact::get_last_name()
{
    return this->_last_name;
}

std::string Contact::get_nickname()
{
    return this->_nickname;
}

std::string Contact::get_phone_number()
{
    return this->_phone_number;
}

std::string Contact::get_darkest_secret()
{
    return this->_darkest_secret;
}
