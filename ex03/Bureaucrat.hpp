#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include "Form.h"
class Form;

class Bureaucrat
{

public:

	Bureaucrat( const std::string &name, int grade );
	Bureaucrat( const Bureaucrat &src );
	~Bureaucrat( void );

	Bureaucrat	&operator=( const Bureaucrat &rhs );

	const std::string	&getName( void ) const;
	int					getGrade( void ) const;

	void	incrementGrade( void );
	void	decrementGrade( void );
	bool	executeForm( Form const &form );
	bool	signForm( Form &form) const;

private:

	const std::string	_name;
	int					_grade;

	static const int	lowestGrade = 150;
	static const int	highestGrade = 1;

	Bureaucrat( void );

//exceptionクラス作成
public:
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();//throw()とは、この関数はこんな内容の例外を出しますよという指定。例外指定という。今回what()自身は例外を出さないので()
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream	&operator<<( std::ostream &ostr, const Bureaucrat &instance );

#endif
