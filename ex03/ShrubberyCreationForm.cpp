#include "ShrubberyCreationForm.hpp"
#include <fstream>
ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), _target("")
{
	std::cout << "ShrubberyCreationForm Constructor() called" << std::endl;	
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name)
 : Form("ShrubberyCreationForm", 145, 137), _target(name)
{
	std::cout << "ShrubberyCreationForm Constructor(std::string, int, int) called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : Form("ShrubberyCreationForm", 145, 137), _target(obj.getTarget())
{
	std::cout << "ShrubberyCreationForm Constructor(const ShrubberyCreationForm &obj) called" << std::endl;
	*this = obj;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destractor() called" << std::endl;
	// system("leaks -q a.out");
}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm &obj)
{
	if (this != &obj)
	{
		obj.getTarget();
		std::cout << "operator = called" << std::endl;
	}
	return (*this);
}


/******************
 * member function
 * **************/

const std::string&	ShrubberyCreationForm::getTarget( void ) const
{
	return this->_target;
}


void	ShrubberyCreationForm::execute( const Bureaucrat &executor ) const
{
	std::ofstream	myfile;
	std::string		fileName = this->_target + "_shrubbery";

	this->checkExecutability(executor);
	myfile.open(fileName.c_str(), std::ios::out);
	myfile << "      ,.," << std::endl;
	myfile << "      MMMM_    ,..," << std::endl;
	myfile << "        \"_ \"__\"MMMMM          ,...,," << std::endl;
	myfile << " ,..., __.\" --\"    ,.,     _-\"MMMMMMM" << std::endl;
	myfile << "MMMMMM\"___ \"_._   MMM\"_.\"\" _ \"\"\"\"\"\"" << std::endl;
	myfile << " \"\"\"\"\"    \"\" , \\_.   \"_. .\"" << std::endl;
	myfile << "        ,., _\"__ \\__./ .\"" << std::endl;
	myfile << "       MMMMM_\"  \"_    ./" << std::endl;
	myfile << "        ''''      (    )" << std::endl;
	myfile << " ._______________.-'____\"---._." << std::endl;
	myfile << "  \\                          /" << std::endl;
	myfile << "   \\________________________/" << std::endl;
	myfile << "   (_)                    (_)" << std::endl;
	myfile.close();
	std::cout << "Created the shrug in " << this->_target << "_shrubbery"
		<< std::endl;
}