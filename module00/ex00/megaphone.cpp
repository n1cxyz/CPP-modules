/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasal <dasal@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:03:38 by dasal             #+#    #+#             */
/*   Updated: 2024/08/20 09:03:41 by dasal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/* int main(int ac, char **av) {
	int i = 1;
	int j;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
	else {
		while (i < ac) {
			j = 0;
			while (av[i][j]) {
				std::cout << (char) toupper(av[i][j]);
				j++;
			}
			i++;
		}
		std::cout << "\n";
	}
	return 0;
} */

int	main(int ac, char **av) {
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
	else {
		for (int i = 1; i < ac; i++) {
			for (int j = 0; av[i][j]; j++) {
				std::cout << (char) toupper(av[i][j]);
			}

		}
		std::cout << "\n";
	}
	return 0;
}
