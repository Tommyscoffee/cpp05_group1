#include "Intern.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotmyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern( void )
{
	std::cout << "Intern Constructor() called" << std::endl;	
}

Intern::Intern(const Intern &obj)
{
	std::cout << "Intern Constructor(const Intern &obj) called" << std::endl;
	*this = obj;
}

Intern::~Intern()
{
	std::cout << "Intern Destractor() called" << std::endl;
	// system("leaks -q a.out");
}

Intern& Intern::operator = (const Intern &obj)
{
	(void)obj;
	if (this != &obj)
	{
		std::cout << "operator = called" << std::endl;
	}
	return (*this);
}

/**********************
 *  member function
 * *******************/

Form* Intern::makeForm(const std::string &formName, const std::string &target ) const
{
	t_formList forms[] =
	{
		{ "presidential pardon", new PresidentialPardonForm(target) },
		{ "robotomy request", new RobotmyRequestForm(target) },
		{ "shrubbery creation", new ShrubberyCreationForm(target) },
		{ "", NULL }
	};
	Form	*resultForm = NULL;

	for ( int i = 0; forms[i].formType != NULL; i++)
	{
		if (forms[i].formName == formName)
			resultForm = forms[i].formType;
		else
			delete forms[i].formType;
	}
	if (resultForm == NULL)
		std::cout << " Intern did not find the form " << formName << std::endl;
	else
		std::cout << " Intern creates " << formName << std::endl;
	return resultForm;
}
