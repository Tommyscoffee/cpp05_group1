#ifndef Intern_HPP
# define Intern_HPP

# include <iostream>
# include <stdexcept>
# include "Form.h"
class Form;

class Intern
{

 public:
	Intern( void );
	Intern( const Intern &src );
	~Intern();

	Intern	&operator=( const Intern &rhs );

	Form	*makeForm( const std::string &formName, const std::string &target ) const;


private:
	typedef struct s_formList
	{
		std::string formName;
		Form		*formType;
	}		t_formList;
};

// std::ostream	&operator<<( std::ostream &ostr, const Intern &instance );

#endif
