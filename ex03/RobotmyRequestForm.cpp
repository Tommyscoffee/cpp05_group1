#include "RobotmyRequestForm.hpp"

RobotmyRequestForm::RobotmyRequestForm() : Form("RobotmyRequestForm", 72, 45), _target("")
{
	std::cout << "RobotmyRequestForm Constructor() called" << std::endl;	
}

RobotmyRequestForm::RobotmyRequestForm(const std::string &name)
 : Form("RobotmyRequestForm", 72, 45), _target(name)
{
	std::cout << "RobotmyRequestForm Constructor(std::string, int, int) called" << std::endl;
}

RobotmyRequestForm::RobotmyRequestForm(const RobotmyRequestForm &obj) : Form("RobotmyRequestForm", 72, 45), _target(obj.getTarget())
{
	std::cout << "RobotmyRequestForm Constructor(const RobotmyRequestForm &obj) called" << std::endl;
	*this = obj;
}

RobotmyRequestForm::~RobotmyRequestForm()
{
	std::cout << "RobotmyRequestForm Destractor() called" << std::endl;
	// system("leaks -q a.out");
}

RobotmyRequestForm& RobotmyRequestForm::operator = (const RobotmyRequestForm &obj)
{
	if (this != &obj)
	{
		obj.getTarget();
		std::cout << "operator = called" << std::endl;
	}
	return (*this);
}

const std::string	&RobotmyRequestForm::getTarget( void ) const
{
	return this->_target;
}


void	RobotmyRequestForm::execute( const Bureaucrat &executor ) const
{
	this->checkExecutability(executor);
	std::cout << "* Unbearable drilling noises *" << std::endl;
	if (std::rand() % 2)
		std::cout << "The victi... " << this->_target << " has been successfull"
			"y robotomized" << std::endl;
	else
		std::cout << "The robotomization on " << this->_target << " may or may "
			"not have been a complete and utter failure." << std::endl;
}

