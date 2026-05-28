/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:27:51 by rsao-pay          #+#    #+#             */
/*   Updated: 2026/05/28 15:53:58 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie::Zombie(std::string name): _name(name)
{
    return ;
}

Zombie::~Zombie(void)
{
    return ;
}

void Zombie::announce(void)
{
    std::string name = this->_name;
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
