/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachami <yhachami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 23:59:02 by yhachami          #+#    #+#             */
/*   Updated: 2023/09/19 16:47:23 by yhachami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char const **av)
{
	int			x;
	int			y;
	std::string s;

	if (ac > 1)
	{
		y = 1;
		while (y < ac)
		{
			s = av[y];
			for (x = 0; s[x]; x++)
				s[x] = std::toupper(s[x]);
			std::cout << s;
			y++;
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	return 0;
}
