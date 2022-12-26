#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotmyRequestForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern		usefulIdiot;
	Bureaucrat	paul("Paul", 3);
	Form		*form;

	form = usefulIdiot.makeForm("this one doesn't exist", "Justin");
	if (form)
		delete form;
	std::cout << "-------------------------" << std::endl;
	form = usefulIdiot.makeForm("presidential pardon", "Maynard");
	if (form)
		delete form;
	std::cout << "-------------------------" << std::endl;
	form = usefulIdiot.makeForm("shrubbery creation", "Danny");
	if (form)
		delete form;
	std::cout << "-------------------------" << std::endl;
	form = usefulIdiot.makeForm("robotomy request", "Adam");
	form->beSigned(paul);
	form->execute(paul);
	if (form)
		delete form;
}
