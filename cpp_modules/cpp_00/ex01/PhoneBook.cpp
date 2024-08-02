/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:13:41 by zlazrak           #+#    #+#             */
/*   Updated: 2023/05/16 10:07:23 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"

PhoneBook::PhoneBook () : i(0), size(0)
{}
bool	PhoneBook::add()
{
	Contact contact;
	std::string str;

	std::cout << "please enter first name:\n";
	std::getline(std::cin, str);
	if (std::cin.eof())
		return (false);
	contact.setFirstName(str);

	std::cout << "please enter last name:\n";
	std::getline(std::cin, str);
	if (std::cin.eof())
		return (false);
	contact.setLastName(str);

	std::cout << "please enter nickname:\n";
	std::getline(std::cin, str);
	if (std::cin.eof())
		return (false);
	contact.setNickname(str);

	std::cout << "please enter phone number:\n";
	std::getline(std::cin, str);
	if (std::cin.eof())
		return (false);
	contact.setPhoneNumber(str);

	std::cout << "please enter darkest secret:\n";
	std::getline(std::cin, str);
	if (std::cin.eof())
		return (false);
	contact.setDarkestSecret(str);

	if (contact.getFirstName().empty() || contact.getLastName().empty()
		|| contact.getNickname().empty() || contact.getPhoneNumber().empty()
			|| contact.getDarkestSecret().empty())
	{
		std::cout << "A saved contact can’t have empty fields\n";
		return (true);
	}
	size += size != 8;
	i *= (i != 8);
	contacts[i++] = contact;
	return (true);
}

bool	PhoneBook::search()
{
	int	j = 0;
	std::string str;
	if (!size)
	{
		std::cout << "the phonebook is empty\n";
		return (true);
	}
	while (j < size)
	{
		std::cout << std::setw(10) << j + 1 << "|";
		search_print(contacts[j].getFirstName(), '|');
		search_print(contacts[j].getLastName(), '|');
		search_print(contacts[j].getNickname(), '\n');

		++j;
	}
	
	std::cout << "Enter the index of the entry to display\n";
	std::getline(std::cin, str);
	if (std::cin.eof())
		return (false);
	while (str.empty() || str.length() > 1 
			|| !(str[0] >= '1' && str[0] <= ('0' + (size))))
	{
		std::cout << "The index is out of range or wrong\n";
		std::cout << "Enter the index of the entry to display (index start from 1)\n";
		std::cout << "Or press ENTER to run another command\n";
		std::getline(std::cin, str);
		if (std::cin.eof())
			return (false);
		if (str.empty())
			return (true);
	}
	j = (str[0] - '0') - 1;
	std::cout << "contact informations\n";
	std::cout <<  "First Name:     " << contacts[j].getFirstName() << "\n";
	std::cout <<  "Last Name:      " << contacts[j].getLastName() << "\n";
	std::cout <<  "Nickname:       " << contacts[j].getNickname() << "\n";
	std::cout <<  "PhoneNumber:    " << contacts[j].getPhoneNumber() << "\n";
	std::cout <<  "Darkest secret: " << contacts[j].getDarkestSecret() << "\n";
	return (true);
}

void	PhoneBook::search_print(std::string str, char f) const
{
	if (str.length() > 10)
	{
		str = str.substr(0,10);
		str[9] = '.';
	}
	std::cout << std::setw(10) << str;
	std::cout << f;
}
