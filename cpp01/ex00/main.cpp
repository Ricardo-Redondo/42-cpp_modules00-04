/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:27:59 by rsao-pay          #+#    #+#             */
/*   Updated: 2026/05/28 15:56:22 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main()
{
    Zombie *zombie = Zombie::newZombie("Foo");
    
    std::cout << "Using heap allocation:" << std::endl;
    zombie->announce();
    
    std::cout << std::endl << "Using stack allocation:" << std::endl;
    Zombie::randomChump("Gary");
    return (0);
}
