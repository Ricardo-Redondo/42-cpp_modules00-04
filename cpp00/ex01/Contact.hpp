/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 16:54:38 by rsao-pay          #+#    #+#             */
/*   Updated: 2026/05/14 15:32:39 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTACT
# define CONTACT

# include <iostream>
# include <string>

    class Contact {
        public:
            Contact(void);
            ~Contact();

            void set_first_name(std::string first_name);
            void set_last_name(std::string last_name);
            void set_nickname(std::string nickname);
            void set_phone_number(std::string phone_number);
            void set_darkest_secret(std::string darkest_secret);
        
            std::string get_first_name(void);
            std::string get_last_name(void);
            std::string get_nickname(void);
            std::string get_phone_number(void);
            std::string get_darkest_secret(void);

        private:
            std::string _first_name;
            std::string _last_name;
            std::string _nickname;
            std::string _phone_number;
            std::string _darkest_secret;
    };

#endif