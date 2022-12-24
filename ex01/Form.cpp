#include "Form.hpp"

Form::Form() : _name("default"), _is_signed(false), _grade_to_sign(this->lowestGrade), _grade_to_execute(this->highestGrade)
{
	std::cout << "Form Constructor() called" << std::endl;	
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _is_signed(false), _grade_to_sign(gradeToSign), _grade_to_execute(gradeToExecute)
{
	this->checkGrades();
	std::cout << "Form Constructor(std::string, int, int) called" << std::endl;
	

}

Form::Form(const Form &obj) : _name(obj._name),
							  _is_signed(obj._is_signed),
							  _grade_to_sign(obj._grade_to_sign),
							  _grade_to_execute(obj._grade_to_execute)
{
	std::cout << "Form Constructor(const Form &obj) called" << std::endl;
	*this = obj;
}

Form::~Form()
{
	std::cout << "Form Destractor() called" << std::endl;
	// system("leaks -q a.out");
}

Form& Form::operator = (const Form &obj)
{
	if (this != &obj)
	{
		std::cout << "operator = called" << std::endl;
		std::cout << "obj._name" << obj._name << std::endl;
		this->_is_signed = obj.getIsSigned();
	}
	return (*this);
}

/*****************
	getter
*****************/

const std::string &Form::getName( void ) const
{
	return (this->_name);
}

int	Form::getSignGrade( void ) const
{
	return (this->_grade_to_sign);
}

int	Form::getExecuteGrade( void ) const
{
	return (this->_grade_to_execute);
}

bool	Form::getIsSigned( void ) const
{
	return (this->_is_signed);
}

/**********************
 *  operator overload
 * *******************/
std::ostream &	operator<<( std::ostream & ostr, Form const & instance)
{
	ostr << instance.getName() << " Form has to be signed by a "
		<< instance.getSignGrade() << " grade and executed by a "
		<< instance.getExecuteGrade() << " grade, it is "
		<< ((instance.getIsSigned()) ? "" : "not ") << "signed";
	return ostr;
}

/**********************
 *  member functions
 * *******************/

bool Form::beSigned( const Bureaucrat &obj)
{//7ページに"If the grade is too low, throw a Form::"とあるが、ここはエラー処理いらない
	if (this->_grade_to_sign < obj.getGrade())//官僚はランクが足りない。equalならsignできる
	{
		this->_is_signed = false;
		return false;
	}
	else// equalならsignできる。7ページ　（higher or egal to the required one) egalはおそらくequal
	{
		this->_is_signed = true;
		return true;
	}
	
}

void	Form::checkGrades( void ) const
{
	if (this->_grade_to_execute < Form::highestGrade
			|| this->_grade_to_sign < Form::highestGrade)
		throw Form::GradeTooHighException();
	if (this->_grade_to_execute > Form::lowestGrade
			|| this->_grade_to_sign > Form::lowestGrade)
		throw Form::GradeTooLowException();
}


/***************************
 * exception class functions
 * *************************/

const char* Form::GradeTooHighException::what() const throw()
{
	return ("The grade you set is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("The grade you set is too Low");
}