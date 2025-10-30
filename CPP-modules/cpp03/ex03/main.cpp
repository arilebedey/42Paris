/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lengarci <lengarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:29:26 by lengarci          #+#    #+#             */
/*   Updated: 2025/07/15 10:34:56 by lengarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

// Utility to print section separators
void separator(const std::string& title) {
    std::cout << "\n" << BOLD << MAGENTA
              << "========== " << title << " =========="
              << RESET << "\n" << std::endl;
}

int main() {
    // ------------------------------------------------------------------------
    separator("CLAPTRAP : CTOR & BASIC METHODS");

    // Default constructor
    ClapTrap ct_default;
    std::cout << CYAN << "[Default] " << RESET;
    ct_default.attack("TargetA");
    ct_default.takeDamage(5);
    ct_default.beRepaired(3);

    // Parametric constructor
    ClapTrap ct_param("Clappy");
    std::cout << CYAN << "[Param] " << RESET;
    ct_param.attack("TargetB");
    ct_param.takeDamage(12);
    ct_param.beRepaired(8);

    // Copy constructor
    ClapTrap ct_copy(ct_param);
    std::cout << CYAN << "[Copy]  " << RESET;
    ct_copy.attack("TargetC");

    // Assignment operator
    ClapTrap ct_assign;
    ct_assign = ct_param;
    std::cout << CYAN << "[Assign]" << RESET;
    ct_assign.beRepaired(2);

    // ------------------------------------------------------------------------
    separator("SCAVTRAP : GUARD GATE");

    ScavTrap st_default;
    std::cout << BLUE << "[Default] " << RESET;
    st_default.attack("IntruderA");
    st_default.takeDamage(20);
    st_default.beRepaired(10);
    st_default.guardGate();

    ScavTrap st_param("Scavy");
    std::cout << BLUE << "[Param]   " << RESET;
    st_param.attack("IntruderB");
    st_param.takeDamage(15);
    st_param.beRepaired(5);
    st_param.guardGate();

    // ------------------------------------------------------------------------
    separator("FRAGTRAP : HIGH FIVES");

    FragTrap ft_default;
    std::cout << GREEN << "[Default] " << RESET;
    ft_default.attack("EnemyA");
    ft_default.takeDamage(30);
    ft_default.beRepaired(20);
    ft_default.highFivesGuys();

    FragTrap ft_param("Fraggy");
    std::cout << GREEN << "[Param]   " << RESET;
    ft_param.attack("EnemyB");
    ft_param.takeDamage(25);
    ft_param.beRepaired(15);
    ft_param.highFivesGuys();

    // ------------------------------------------------------------------------
    separator("DIAMONDTRAP : WHOAMI & HYBRID STATS");

    // Default constructor
    DiamondTrap dt_default;
    std::cout << YELLOW << "[Default] " << RESET;
    dt_default.attack("BossA");       // from ScavTrap
    dt_default.takeDamage(40);        // inherited
    dt_default.beRepaired(30);        // inherited
    dt_default.whoAmI();

    // Parametric constructor
    DiamondTrap dt_param("Dia");
    std::cout << YELLOW << "[Param]   " << RESET;
    dt_param.attack("BossB");
    dt_param.takeDamage(35);
    dt_param.beRepaired(25);
    dt_param.whoAmI();

    // Copy constructor
    DiamondTrap dt_copy(dt_param);
    std::cout << YELLOW << "[Copy]    " << RESET;
    dt_copy.whoAmI();

    // Assignment operator
    DiamondTrap dt_assign;
    dt_assign = dt_param;
    std::cout << YELLOW << "[Assign]  " << RESET;
    dt_assign.whoAmI();

    // ------------------------------------------------------------------------
    separator("POLYMORPHISM & DESTRUCTORS");

    // Polymorphic attack via base pointer
    ClapTrap* poly1 = new ScavTrap("PolyScav");
    ClapTrap* poly2 = new FragTrap("PolyFrag");
    ClapTrap* poly3 = new DiamondTrap("PolyDia");

    std::cout << RED << "[Scav as ClapTrap] " << RESET;
    poly1->attack("Ghost");
    std::cout << RED << "[Frag as ClapTrap]  " << RESET;
    poly2->attack("Shadow");
    std::cout << RED << "[Dia as ClapTrap]   " << RESET;
    poly3->attack("Phantom");

    // Show whoAmI for DiamondTrap via casting
    std::cout << RED << "[Dia whoAmI]        " << RESET;
    dynamic_cast<DiamondTrap*>(poly3)->whoAmI();

    delete poly1;
    delete poly2;
    delete poly3;

    // ------------------------------------------------------------------------
    separator("END OF TESTS");

    return 0;
}