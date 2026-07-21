/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <pabalvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 20:06:47 by pabalvar          #+#    #+#             */
/*   Updated: 2026/07/21 20:06:48 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstddef>

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern() {}

static AForm* createShrubberyCreationForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomyRequestForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createPresidentialPardonForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	typedef AForm* (*FormCreator)(const std::string&);

	struct FormEntry
	{
		std::string name;
		FormCreator create;
	};

	FormEntry forms[] = {
		{"shrubbery creation", &createShrubberyCreationForm},
		{"robotomy request", &createRobotomyRequestForm},
		{"presidential pardon", &createPresidentialPardonForm}
	};

	size_t count = sizeof(forms) / sizeof(forms[0]);
	for (size_t i = 0; i < count; i++)
	{
		if (forms[i].name == formName)
		{
			AForm* form = forms[i].create(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}
	std::cout << "Intern couldn't find form: " << formName << std::endl;
	return NULL;
}