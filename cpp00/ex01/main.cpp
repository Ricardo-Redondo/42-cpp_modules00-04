/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 23:21:13 by rsao-pay          #+#    #+#             */
/*   Updated: 2026/05/15 15:44:07 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
    Troquei a ordem to add contact and add contact info
    por clear a frente de cada print
*/

# include "PhoneBook.hpp"

int main()
{
    std::string buff;
    std::string trim = "\r\t\n";
    PhoneBook pb;
    void (PhoneBook::*func)();

    while(true)
    {
        std::cout << pb.get_clear();
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        if(!std::getline(std::cin, buff))
        {
            std::cout << std::endl << "EOF detected, aborting." << std::endl;
            return EXIT_FAILURE;
        }

        func = pb.option_selector(buff);
        if(!func)
        {
            std::cout << "Invalid Option, use ADD, SEARCH ou EXIT." << std::endl;
            continue ;
        }
        
        (pb.*func)();
        if(pb.is_eof())
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}