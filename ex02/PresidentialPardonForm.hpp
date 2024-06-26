
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &form);
		~PresidentialPardonForm();
		
		PresidentialPardonForm &operator=(PresidentialPardonForm const &form);

		std::string const &getTarget() const;
		void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm const &form);

#endif 