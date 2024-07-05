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

# include "lib.hpp"

Contact::Contact(void)
{
	this->_fname = "";
}

string	Contact::get_fname(void) const
{
	return (this->_fname);
}

string	Contact::get_lname(void) const
{
	return (this->_lname);
}

string	Contact::get_nick(void) const
{
	return (this->_nick);
}

long	Contact::get_phone_num(void) const
{
	return (this->_phone_num);
}

string	Contact::get_secret(void) const
{
	return (this->_secret);
}

void	Contact::set_fname(string str)
{
	this->_fname = str;
}

void	Contact::set_lname(string lst_name)
{
	this->_lname = lst_name;
}

void	Contact::set_nick(string nck_name)
{
	this->_nick = nck_name;
}

void	Contact::set_phone_num(long phn_nmber)
{
	this->_phone_num = phn_nmber;
}

void	Contact::set_secret(string secret)
{
	this->_secret = secret;
}