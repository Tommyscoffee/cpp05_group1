#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool 				_is_signed;
		const int			_grade_to_sign;
		const int			_grade_to_execute;
		static const int	lowestGrade = 150;
		static const int	highestGrade = 1;

	public:
		Form( void );
		Form( const std::string &name, int gradeToSign, int gradeToExecute );
		Form( const Form &obj );
		virtual ~Form( void );
		/****************
		 * getter, setter
		 * **************/
		const std::string	&getName( void ) const;
		int					getSignGrade( void ) const;
		int					getExecuteGrade( void ) const;
		bool				getIsSigned( void ) const;

		Form	&operator=( const Form &obj );
		/****************
		 * member function
		 * **************/
		bool			beSigned( const Bureaucrat &instance);
		void			checkGrades( void ) const;
		virtual void 	execute(const Bureaucrat &executor) const = 0;
		void			checkExecutability( const Bureaucrat &executor ) const;
		/******************
		 * exception class
		 * ****************/
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
		class CantExecuteForm : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		void executeForm(const Form &form);

};
std::ostream	&operator<<( std::ostream &ostr, const Form &instance );

#endif