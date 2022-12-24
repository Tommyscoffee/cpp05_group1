#ifndef ROBOTMYREQUESTFORM_HPP
# define ROBOTMYREQUESTFORM_HPP
# include "Form.hpp"
# include "Bureaucrat.hpp"

class RobotmyRequestForm : public Form
{
	private:
		const std::string	_target;
		RobotmyRequestForm( void );
	public:
		RobotmyRequestForm( const std::string &target );
		RobotmyRequestForm( const RobotmyRequestForm &obj );
		~RobotmyRequestForm( void );

		RobotmyRequestForm &operator=( const RobotmyRequestForm &obj );

		const std::string &getTarget( void ) const;
		void		execute( const Bureaucrat &executor ) const;

};
#endif