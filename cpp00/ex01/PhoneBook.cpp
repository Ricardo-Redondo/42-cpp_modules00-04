/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 16:43:08 by rsao-pay          #+#    #+#             */
/*   Updated: 2026/05/15 15:44:37 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"
# include <cstdio>

PhoneBook::PhoneBook(void) : _contacts_added(0), _eof(false), _CLEAR("\033[2J\033[H")
{
    return ;
}

PhoneBook::~PhoneBook(void)
{
    return ;
}

bool PhoneBook::is_eof(void) const
{
    return PhoneBook::_eof;
}

void PhoneBook::exit_phonebook(void)
{
    std::cout << "All traces of the contacts deleted, turning off." << std::endl;
    exit(EXIT_SUCCESS);
    return ;
}

std::string PhoneBook::get_clear(void)
{
    return _CLEAR;
}

bool PhoneBook::validate_phone_number(std::string phone_number)
{
    int max_length = 9;
    if(phone_number[0] == '+' && phone_number[4] == ' ')
        max_length = 14;
    else if(phone_number[0] == '+' && phone_number[3] == ' ')
        max_length = 13;
    if((int)phone_number.length() != max_length)
        return false;
    for(int i = 0; i < (int)phone_number.length(); i++)
    {
        if(i == 0 && phone_number[i] == '+')
            continue ;
        else if(max_length == 14 && phone_number[4] == ' ')
            continue ;
        else if(max_length == 13 && phone_number[3] == ' ')
            continue ;
        else if(phone_number[i] >= '0' && phone_number[i] <= '9')
            continue ;
        return false;
    }
    return true;
}

void PhoneBook::add_contact_info(Contact *index, std::string msg, void (Contact::*func)(std::string str), bool is_phone_number)
{
    std::string buff;
    const std::string trim = "\t\r\n";
    
    while(true)
    {
        std::cout << msg;
        if(!std::getline(std::cin, buff))
        {
            std::cout << std::endl << "EOF detected, aborting." << std::endl;
            PhoneBook::_eof = true;
            return ;
        }
        std::size_t start = buff.find_first_not_of(trim);
        if(start == std::string::npos)
        {
            std::cout << "Field cannot be empty." << std::endl << std::endl;
			continue ;
        }
        
        std::size_t end = buff.find_last_not_of(trim);
        buff = buff.substr(start, end - start + 1);
        if(is_phone_number && !PhoneBook::validate_phone_number(buff))
        {
            std::cout << "Invalid phone number." << std::endl;
            continue ;
        }
        break ;
    }
    (index->*func)(buff);
    return ;
}

void PhoneBook::left_shift_list(void)
{
    for(int i = 0; i < 7; i++)
        _contact_array[i] = _contact_array[i + 1];
    _contacts_added--;
    return ;
}

void PhoneBook::add_contact(void)
{
    if(_contacts_added == 8)
        left_shift_list();
    int index = _contacts_added % 8;
    Contact *num = &_contact_array[index];
    
    add_contact_info(num, "Enter contact first name: ", &Contact::set_first_name, false);
    if(is_eof()) return ;
    add_contact_info(num, "Enter contact last name: ", &Contact::set_last_name, false);
    if(is_eof()) return ;
    add_contact_info(num, "Enter contact nickname: ", &Contact::set_nickname, false);
    if(is_eof()) return ;
    add_contact_info(num, "Enter contact phone number (Ex: \"123456789\" or \"+123 123456789\"): ", &Contact::set_phone_number, true);
    if(is_eof()) return ;
    add_contact_info(num, "Enter contact darkest secret: ", &Contact::set_darkest_secret, false);
    if(is_eof()) return ;
    _contacts_added++;
    std::cout << _CLEAR;
    return ;
}

void PhoneBook::print_all_contacts(void)
{
    std::cout << _CLEAR;
    std::cout << "PhoneBook's Contacts list:" << std::endl;
    for(int i = 0; i < 8; i++)
    {
        if(_contact_array[i].get_first_name().empty())
            break ;
        std::string first_name = _contact_array[i].get_first_name();
        std::string last_name = _contact_array[i].get_last_name();
        std::string phone_num = _contact_array[i].get_phone_number();
        std::cout << "[" << i + 1 << "] - " << "(" << phone_num << ") " << first_name << " " << last_name << std::endl;
    }
    return ;
}

void PhoneBook::print_contact_info(int index)
{
    Contact *c = &_contact_array[index];
    std::string first_name = c->get_first_name();
    std::string last_name = c->get_last_name();
    std::string nickname = c->get_nickname();
    std::string phone_num = c->get_phone_number();
    std::string darkest_secret = c->get_darkest_secret();

    std::cout << "Contact info:" << std::endl;
    std::cout << "Phone number - " << phone_num << std::endl;
    std::cout << "First name - " << first_name << std::endl;
    std::cout << "Last name - " << last_name << std::endl;
    std::cout << "Nickname - " << nickname << std::endl;
    std::cout << "Darkest secret - " << darkest_secret << std::endl << std::endl;
    return ;
}

void PhoneBook::search_contact_info(void)
{
    std::string buff;
    int num;
    char unwanted;
    
    if(_contacts_added == 0)
    {
        std::cout << "Contact list is empty.";
    }
    print_all_contacts();
    std::cout << std::endl << "Enter number corresponding to wanted contact: ";
    if(!std::getline(std::cin, buff))
    {
        std::cout << std::endl << "EOF detected, aborting." << std::endl;
        _eof = true;
        return ;
    }
    
    std::istringstream iss(buff);
    if(!(iss >> num) || iss >> unwanted || num < 1 || num > 8)
        std::cerr << "Invalid input." << std::endl;
    else if(_contact_array[num - 1].get_first_name().empty())
        std::cerr << "Invalid contact." << std::endl;
    else
    {
        std::cout << _CLEAR;
        print_contact_info(num - 1);
    }
    std::cout << "Press enter to continue...";
    if(!std::getline(std::cin, buff))
    {
        std::cout << "EOF detected, aborting." << std::endl;
        _eof = true;
        return ;
    }
    return ;
}

void (PhoneBook::*PhoneBook::option_selector(std::string buff))(void)
{
    if(buff == "ADD")
        return &PhoneBook::add_contact;
    else if(buff == "SEARCH")
        return &PhoneBook::search_contact_info;
    else if(buff == "EXIT")
        return &PhoneBook::exit_phonebook;
    else
        return NULL;
}