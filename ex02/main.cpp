/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <pabalvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 20:04:31 by pabalvar          #+#    #+#             */
/*   Updated: 2026/07/21 20:04:33 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	try
	{
		Bureaucrat highGrade("Alice", 1);
		Bureaucrat lowGrade("Bob", 140);

		ShrubberyCreationForm shrubbery("home");
		std::cout << shrubbery << std::endl;

		highGrade.signForm(shrubbery);
		highGrade.executeForm(shrubbery);

		RobotomyRequestForm robotomy("Bender");
		lowGrade.signForm(robotomy);
		highGrade.signForm(robotomy);
		highGrade.executeForm(robotomy);

		PresidentialPardonForm pardon("Snowden");
		highGrade.signForm(pardon);
		highGrade.executeForm(pardon);

		ShrubberyCreationForm unsignedForm("office");
		highGrade.executeForm(unsignedForm);

		lowGrade.executeForm(shrubbery);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}