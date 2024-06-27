
#include "Intern.hpp"

Intern::Intern()
{
	this->functions[0] = &Intern::createPresidentialPardonForm;
	this->functions[1] = &Intern::createRobotomyRequestForm;
	this->functions[2] = &Intern::createShrubberyCreationForm;
}

Intern::Intern(Intern const &intern)
{
	*this = intern;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(Intern const &intern)
{
	(void)intern;
	return (*this);
}

AForm* Intern::makeForm(std::string const &formName, std::string const &target) {
    for (int i = 0; i < 3; i++) {
        if ((formName == "PresidentialPardonForm" && i == 0) ||
            (formName == "RobotomyRequestForm" && i == 1) ||
            (formName == "ShrubberyCreationForm" && i == 2)) {
            return (this->*functions[i])(target);
        }
    }
    throw FormNotFoundException();
}


AForm *Intern::createPresidentialPardonForm(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::createRobotomyRequestForm(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createShrubberyCreationForm(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}
