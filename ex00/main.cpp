/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <pabalvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 19:32:00 by pabalvar          #+#    #+#             */
/*   Updated: 2026/07/21 19:32:01 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat a("Alice", 1);
		std::cout << a << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b("Bob", 150);
		std::cout << b << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat c("Charlie", 0);
		std::cout << c << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat d("Dave", 151);
		std::cout << d << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat e("Eve", 1);
		e.incrementGrade();
		std::cout << e << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
	}

	try
	{
		Bureaucrat f("Frank", 150);
		f.decrementGrade();
		std::cout << f << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
	}

	try
	{
		Bureaucrat g("Grace", 2);
		g.incrementGrade();
		std::cout << g << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
	}

	return 0;
}