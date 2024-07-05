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
	string	answer;
	long	tel_number;
	int		contact_id;
	int		i;

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
		cout << "Please, enter a contact first name" << endl;
		cin >> answer;
		if (answer != "")
			this->_contacs[contact_id].set_fname(answer);
	}
	answer = "";
	while (answer == "")
	{
		cout << "Please, enter a contact last name" << endl;
		cin >> answer;
		if (answer != "")
			this->_contacs[contact_id].set_lname(answer);
	}
	answer = "";
	while (answer == "")
	{
		cout << "Please, enter a contact nickname" << endl;
		cin >> answer;
		if (answer != "")
			this->_contacs[contact_id].set_nick(answer);
	}
	answer = "";
	while (answer == "")
	{
		cout << "Please, enter a Telephone Number" << endl;
		cin >> answer;
		if (answer != "")
		{
			while (answer[i] != '\0' && (answer[i] >= 48 && answer[i] <= 57))
				i++;
			if (i != 0 && i < 19)
			{
				tel_number = stol(answer);
				this->_contacs[contact_id].set_phone_num(tel_number);
			} else
			{
				cout << "ERROR, wrong format. Only numbers are accepted." << endl;
				answer = "";
			}
		}
	}
	answer = "";
	while (answer == "")
	{
		cout << "Please, enter your secret" << endl;
		cin >> answer;
		if (answer != "")
			this->_contacs[contact_id].set_secret(answer);
	}
}

string	PhoneBook::max_ten_char(string str)
{
	int 	i;
	string	tenchar;

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
	cout << endl
		<< "_____________________________________________" << endl
		<< "|     Index|First Name| Last Name|  Nickname|" << endl
		<< "|----------|----------|----------|----------|" << endl;
	while (j != 0)
	{
		cout 
			<< "|         " << i
			<< "|" << max_ten_char(this->_contacs[i].get_fname()) 
			<< "|" << max_ten_char(this->_contacs[i].get_lname()) 
			<< "|" << max_ten_char(this->_contacs[i].get_nick()) 
			<< "|" << endl;
		i++;
		j--;
	}
	cout << "---------------------------------------------" << endl;
	cout << endl;
}

void	PhoneBook::select_one(void)
{
	int	i;
	int j;
	string id;

	i = 0;
	j = this->_total_contacts;
	while(j != 0)
	{
		cout << "Enter the index of the contact to be displayed" << endl;
		cin >> id;
		i = 0;
		while (id[i] != '\0' && (id[i] >= 48 && id[i] <= 57))
			i++;
		if (i != 0 && i < 2)
		{
			i = stoi(id);
			if (i >= 0 && i < j)
			{
				cout << endl
				<< "Index: " << i << endl
				<< "First name: " << this->_contacs[i].get_fname() << endl
				<< "Last name: " << this->_contacs[i].get_lname() << endl
				<< "Nickname: " << this->_contacs[i].get_nick() << endl
				<< "Telephone number: " << this->_contacs[i].get_phone_num() << endl
				<< "Darkest secret: " << this->_contacs[i].get_secret() << endl 
				<< endl;
				break;
			} else
				cout << "ERROR, the number is not in the list." << endl;
		} else
			cout << "ERROR, wrong format. Only numbers are accepted. MAX 1 digit." << endl;
	}
}

void	PhoneBook::search_contact(void)
{
	display_contacts();
	select_one();
}
