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

#pragma once
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "lib.hpp"

class	Contact
{
	public:
		Contact(void);
		std::string		get_fname(void) const;
		std::string		get_lname(void) const;
		std::string		get_nick(void) const;
		long			get_phone_num(void) const;
		std::string		get_secret(void) const;
		void			set_fname(std::string str);
		void			set_lname(std::string str);
		void			set_nick(std::string nck_name);
		void			set_phone_num(long num);
		void			set_secret(std::string secret);
	private:
		int			_index;
		std::string	_fname;
		std::string _lname;
		std::string _nick;
		long		_phone_num;
		std::string _secret;
};

#endif