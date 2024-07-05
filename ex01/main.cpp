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

#include "lib.hpp"

int	main(void)
{
	PhoneBook 	ph1;
	string		action;

	cout << "Welcome to the best PhoneBook ever" << endl;
	cout << "Please, select as action: ADD, SEARCH or EXIT" << endl;
	cin >> action;
	while (action != "EXIT")
	{
		if (action == "ADD")
			ph1.add_contact();
		else if (action == "SEARCH")
			ph1.search_contact();
		else
			cout << "ERROR. The chosen action is wrong." << endl;
		cout << "Please, choose an action again: ADD, SEARCH or EXIT" << endl;
		cin >> action;
	}
	return (0);
}
