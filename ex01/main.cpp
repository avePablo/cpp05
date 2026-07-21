/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <pabalvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 19:46:56 by pabalvar          #+#    #+#             */
/*   Updated: 2026/07/21 19:46:58 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	try
	{
		Form f1("Tax Form", 50, 25);
		std::cout << f1 << std::endl;

		Bureaucrat b1("Alice", 40);
		b1.signForm(f1);
		std::cout << f1 << std::endl;

		Form f2("Building Permit", 50, 25);
		Bureaucrat b2("Bob", 60);
		b2.signForm(f2);
		std::cout << f2 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Form badForm("Bad Form", 0, 25);
		(void)badForm;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}