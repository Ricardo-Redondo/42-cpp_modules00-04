/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 16:54:40 by rsao-pay          #+#    #+#             */
/*   Updated: 2026/05/15 11:07:15 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK
# define PHONEBOOK

# include "Contact.hpp"
# include <stdlib.h>
# include <string.h>
# include <iomanip>
# include <sstream>

class PhoneBook {
    public:
        PhoneBook(void);
        ~PhoneBook();

        void add_contact(void);
        void search_contact_info(void);
        void exit_phonebook(void);
        void (PhoneBook::*option_selector(std::string buff))(void);
        bool is_eof(void) const;
        std::string get_clear(void);
    
    private:
        int _contacts_added;
        Contact _contact_array[8];
        bool _eof;
        const std::string _CLEAR;

        void add_contact_info(Contact *index, std::string msg, void (Contact::*func)(std::string str), bool is_phonen_umber);
        bool validate_phone_number(std::string phone_number);
        void left_shift_list(void);
        void print_all_contacts(void);
        void print_contact_info(int index);
};

#endif