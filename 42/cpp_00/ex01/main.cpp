/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:16:40 by zlazrak           #+#    #+#             */
/*   Updated: 2023/05/16 09:20:06 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"

int	main()
{
	PhoneBook phonebook;

	std::cout << "The program only accepts ADD, SEARCH and EXIT\n";
	std::cout << "ADD:    save a new contact\n";
	std::cout << "SEARCH: display a specific contact\n";
	std::cout << "EXIT:   The program quits\n";
	while ('_')
	{
		std::cout << "Enter a command: \n";
		std::string str;
		std::getline(std::cin, str);
		if (std::cin.eof())
			return (0);
		if (str == "ADD")
		{
			if (!phonebook.add())
				return (0);
		}
		else if (str == "SEARCH")
		{
			if (!phonebook.search())
				return (0);
		}
		else if (str == "EXIT")
		{
			std::cout<<"exit\n";
			return (0);
		}
	}
	
	return (0);
}