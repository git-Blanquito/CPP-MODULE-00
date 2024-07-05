/* **************************************************************************** */
/*                                                                              */
/*                                                         :::      ::::::::    */
/*    Makefile                                           :+:      :+:    :+:    */
/*                                                     +:+ +:+         +:+      */
/*    By: aiblanco <marvin@42.fr>                    +#+  +:+       +#+         */
/*                                                 +#+#+#+#+#+   +#+            */
/*    Created: 2024/06/10 23:05:13 by aiblanco          #+#    #+#              */
/*    Updated: 2024/06/10 23:05:21 by aiblanco         ###   ########.fr        */
/*                                                                              */
/* **************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(void)
{
	PhoneBook 	ph1;
	std::string		action;

	std::cout << "Welcome to the best PhoneBook ever" << std::endl;
	std::cout << "Please, select as action: ADD, SEARCH or EXIT" << std::endl;
	std::cin >> action;
	while (action != "EXIT")
	{
		if (action == "ADD")
			ph1.add_contact();
		else if (action == "SEARCH")
			ph1.search_contact();
		else
			std::cout << "ERROR. The chosen action is wrong." << std::endl;
		std::cout << "Please, choose an action again: ADD, SEARCH or EXIT" << std::endl;
		std::cin >> action;
	}
	return (0);
}
