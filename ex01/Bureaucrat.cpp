#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(this->lowestGrade)
{
	std::cout << "Bureaucrat Constructor() called" << std::endl;	
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat Constructor(std::string) called" << std::endl;
	if(grade > this->lowestGrade)
		throw Bureaucrat::GradeTooLowException();
	else if(grade < this->highestGrade)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
	std::cout << "Bureaucrat Constructor(const Bureaucrat &obj) called" << std::endl;
	*this = obj;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destractor() called" << std::endl;
	// system("leaks -q a.out");
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat &obj)
{
	if (this != &obj)
	{
		std::cout << "operator = called" << std::endl;
		std::cout << "obj._grade" << obj._grade << std::endl;
		this->_grade = obj._grade;
	}
	return (*this);
}

/*****************
	getter
*****************/

const std::string &Bureaucrat::getName( void ) const
{
	return (this->_name);
}

int Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}

/**********************
	member functions
***********************/

void	Bureaucrat::incrementGrade( void  )
{

	if (this->_grade - 1 < this->highestGrade)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	this->_grade--;//incrementはgradeを上げているので_gradeは--している。
	std::cout << this->_name << " incremented his grade to " << this->_grade << std::endl;
}

void	Bureaucrat::decrementGrade( void  )
{

	if (this->_grade + 1 > this->lowestGrade)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;//incrementはgradeを下げているので_gradeは++している。
	std::cout << this->_name << " decreased his grade to " << this->_grade << std::endl;
}

bool	Bureaucrat::signForm( Form &form) const
{
	if (form.beSigned( *this ))
	{
		std::cout << this->_name << " signed form " << form.getName() << std::endl;
		return true;
	}
	else
	{
		std::cout << this->_name << " cannot sign form " << form.getName()
			<< " cause his grade is not high enough " << std::endl;
		return false;
	}
}

/**********************
 *  operator overload
 * *******************/
std::ostream &	operator<<( std::ostream & ostr, Bureaucrat const & instance)
{
	ostr << instance.getName() << ", bureaucrat grade " << instance.getGrade();
	return ostr;
}

/***************************
 * exception class functions
 * *************************/

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade you set is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade you set is too Low");
}