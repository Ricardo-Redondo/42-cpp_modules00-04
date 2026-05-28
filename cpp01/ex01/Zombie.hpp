/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:27:56 by rsao-pay          #+#    #+#             */
/*   Updated: 2026/05/28 16:54:28 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class Zombie
{
    public:
        Zombie(std::string name);
        ~Zombie();

        Zombie *zombieHorde(int N, std::string name);
        void announce(void);
    private:
        std::string _name;
};

#endif