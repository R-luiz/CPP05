
#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{
	std::cout << "RobotomyRequestForm default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm parameter constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &form) : AForm(form), target(form.target)
{
	std::cout << "RobotomyRequestForm copy constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &form)
{
	std::cout << "RobotomyRequestForm assignment operator" << std::endl;
	if (this == &form)
		return (*this);
	AForm::operator=(form);
	this->target = form.target;
	return (*this);
}

std::string const &RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << "Drilling noises" << std::endl;
	if (rand() % 2)
		std::cout << this->target << " has been robotomized" << std::endl;
	else
		throw RobotomizeException();
}

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm const &form)
{
	out << "Form " << form.getName() << " is ";
	if (form.getFormSigned())
		out << "signed";
	else
		out << "not signed";
	out << " and requires grade " << form.getGradeToSign() << " to sign and grade " << form.getGradeToExecute() << " to execute" << std::endl;
	return (out);
}
