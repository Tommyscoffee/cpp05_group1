#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include "Form.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form
{
	private:
		const std::string	_target;
		ShrubberyCreationForm( void );
	public:
		ShrubberyCreationForm( const std::string &target );
		ShrubberyCreationForm( const ShrubberyCreationForm &obj );
		~ShrubberyCreationForm( void );

		ShrubberyCreationForm &operator=( const ShrubberyCreationForm &obj );

		const std::string &getTarget( void ) const;
		void		execute( const Bureaucrat &executor ) const;

};

#endif