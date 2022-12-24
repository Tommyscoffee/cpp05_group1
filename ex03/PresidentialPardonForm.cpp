
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), _target("")
{
	std::cout << "PresidentialPardonForm Constructor() called" << std::endl;	
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &name)
 : Form("PresidentialPardonForm", 25, 5), _target(name)
{
	std::cout << "PresidentialPardonForm Constructor(std::string, int, int) called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : Form("PresidentialPardonForm", 25, 5), _target(obj.getTarget())
{
	std::cout << "PresidentialPardonForm Constructor(const PresidentialPardonForm &obj) called" << std::endl;
	*this = obj;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destractor() called" << std::endl;
	// system("leaks -q a.out");
}

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm &obj)
{
	if (this != &obj)
	{
		obj.getTarget();
		std::cout << "operator = called" << std::endl;
	}
	return (*this);
}

const std::string	&PresidentialPardonForm::getTarget( void ) const
{
	return this->_target;
}

void	PresidentialPardonForm::execute( const Bureaucrat &executor ) const
{
	this->checkExecutability(executor);
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox."
		<< std::endl;
}
