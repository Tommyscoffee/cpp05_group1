
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include "Form.hpp"
# include "Bureaucrat.hpp"
# include <iostream>

class PresidentialPardonForm : public Form
{
	private:
		const std::string	_target;
		PresidentialPardonForm( void );
	public:
		PresidentialPardonForm( const std::string &target );
		PresidentialPardonForm( const PresidentialPardonForm &obj );
		~PresidentialPardonForm( void );

		PresidentialPardonForm &operator=( const PresidentialPardonForm &obj );

		const std::string &getTarget( void ) const;
		void		execute( const Bureaucrat &executor ) const;

};
#endif