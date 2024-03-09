/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 09:16:49 by zlazrak           #+#    #+#             */
/*   Updated: 2023/05/16 09:16:50 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "./Contact.hpp"

// ● User depends on what (.h)
// ○ We can change how (.cpp)
 
class PhoneBook
{
	private:
		Contact contacts[8];
		int		i;
		int		size;
		void	search_print(std::string str, char f) const;
	public:
		PhoneBook ();
		bool	add();
		bool	search();
};

#endif