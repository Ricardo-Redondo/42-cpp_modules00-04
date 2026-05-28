/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsao-pay <rsao-pay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:27:49 by rsao-pay          #+#    #+#             */
/*   Updated: 2026/05/28 15:50:27 by rsao-pay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie *Zombie::newZombie(std::string name)
{
    Zombie *zombie = new Zombie(name);
    return (zombie);
}
