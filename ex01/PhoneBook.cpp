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

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
	this->_total_contacts = 0;
}

int		PhoneBook::get_total_contact(void)
{
	return (this->_total_contacts);
}

void	PhoneBook::add_contact(void)
{
	std::string	answer;
	long		tel_number;
	int			contact_id;
	int			i;

	answer = "";
	tel_number = 0;
	contact_id = 0;
 	i = 0;
	if (this->_index != 8)
		contact_id = this->_index++;
	else
	{
		this->_index = 0;
		contact_id = this->_index++;
	}
	if (this->_total_contacts < 8)
		this->_total_contacts++;
	while (answer == "")
	{
		std::cout << "Please, enter a contact first name" << std::endl;
		std::cin >> answer;
		if (answer != "")
			this->_contacts[contact_id].set_fname(answer);
	}
	answer = "";
	while (answer == "")
	{
		std::cout << "Please, enter a contact last name" << std::endl;
		std::cin >> answer;
		if (answer != "")
			this->_contacts[contact_id].set_lname(answer);
	}
	answer = "";
	while (answer == "")
	{
		std::cout << "Please, enter a contact nickname" << std::endl;
		std::cin >> answer;
		if (answer != "")
			this->_contacts[contact_id].set_nick(answer);
	}
	answer = "";
	while (answer == "")
	{
		std::cout << "Please, enter a Telephone Number" << std::endl;
		std::cin >> answer;
		if (answer != "")
		{
			while (answer[i] != '\0' && (answer[i] >= 48 && answer[i] <= 57))
				i++;
			if (i != 0 && i < 19)
			{
				tel_number = stol(answer);
				this->_contacts[contact_id].set_phone_num(tel_number);
			} else
			{
				std::cout << "ERROR, wrong format. Only numbers are accepted." << std::endl;
				answer = "";
			}
		}
	}
	answer = "";
	while (answer == "")
	{
		std::cout << "Please, enter your secret" << std::endl;
		std::cin >> answer;
		if (answer != "")
			this->_contacts[contact_id].set_secret(answer);
	}
}

std::string	PhoneBook::max_ten_char(std::string str)
{
	int 	i;
	std::string	tenchar;

	i = 0;
	tenchar = "";
	while (str[i] != '\0')
		i++;
	if (i > 10)
	{
		i = 0;
		while (i < 9)
			tenchar += str[i++];
		tenchar += ".";
	} else if (i < 10)
	{
		while (i++ != 10)
			tenchar += " ";
		tenchar += str;
	} else
		return (str);
	return (tenchar);
}

void	PhoneBook::display_contacts(void)
{
	int	i;
	int j;

	i = 0;
	j = this->_total_contacts;
	std::cout << std::endl
		<< "_____________________________________________" << std::endl
		<< "|     Index|First Name| Last Name|  Nickname|" << std::endl
		<< "|----------|----------|----------|----------|" << std::endl;
	while (j != 0)
	{
		std::cout 
			<< "|         " << i
			<< "|" << max_ten_char(this->_contacts[i].get_fname()) 
			<< "|" << max_ten_char(this->_contacts[i].get_lname()) 
			<< "|" << max_ten_char(this->_contacts[i].get_nick()) 
			<< "|" << std::endl;
		i++;
		j--;
	}
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::select_one(void)
{
	int	i;
	int j;
	std::string id;

	i = 0;
	j = this->_total_contacts;
	while(j != 0)
	{
		std::cout << "Enter the index of the contact to be displayed" << std::endl;
		std::cin >> id;
		i = 0;
		while (id[i] != '\0' && (id[i] >= 48 && id[i] <= 57))
			i++;
		if (i != 0 && i < 2)
		{
			i = stoi(id);
			if (i >= 0 && i < j)
			{
				std::cout << std::endl
				<< "Index: " << i << std::endl
				<< "First name: " << this->_contacts[i].get_fname() << std::endl
				<< "Last name: " << this->_contacts[i].get_lname() << std::endl
				<< "Nickname: " << this->_contacts[i].get_nick() << std::endl
				<< "Telephone number: " << this->_contacts[i].get_phone_num() << std::endl
				<< "Darkest secret: " << this->_contacts[i].get_secret() << std::endl 
				<< std::endl;
				break;
			} else
				std::cout << "ERROR, the number is not in the list." << std::endl;
		} else
			std::cout << "ERROR, wrong format. Only numbers are accepted. MAX 1 digit." << std::endl;
	}
}

void	PhoneBook::search_contact(void)
{
	display_contacts();
	select_one();
}
