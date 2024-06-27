
#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

class Intern
{
	private :
		typedef AForm* (Intern::*func)(std::string const &target);
		func functions[3];
		AForm *createPresidentialPardonForm(std::string const &target);
		AForm *createRobotomyRequestForm(std::string const &target);
		AForm *createShrubberyCreationForm(std::string const &target);

	public :
		Intern();
		Intern(Intern const &intern);
		~Intern();
		Intern &operator=(Intern const &intern);
		AForm *makeForm(std::string const &formName, std::string const &target);
		class FormNotFoundException : public std::exception {
		public:
			const char *what() const throw() {
				return "Form not found";
			}
		};

};

#endif // !



