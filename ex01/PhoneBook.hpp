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

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include "Contact.hpp"
# include <iostream>

class	PhoneBook
{
	public:
		PhoneBook(void);
		void	add_contact(void);
		void	search_contact(void);
		int		get_total_contact(void);
	private:
		int			_index;
		int			_total_contacts;
		Contact		_contacts[8];
		std::string	max_ten_char(std::string str);
		void		display_contacts(void);
		void		select_one(void);
};

#endif