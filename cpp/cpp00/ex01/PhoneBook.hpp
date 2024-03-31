/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:59:22 by yhachami          #+#    #+#             */
/*   Updated: 2023/09/19 16:50:38 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contact[8];

public:
	PhoneBook();
	~PhoneBook();

	void set_contact(Contact contact, int i);
	Contact get_contact(int i);

	void	add_contact(int i);
	void	show(int size);
	void	search(int size);
};
