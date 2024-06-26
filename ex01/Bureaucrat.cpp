
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {
	std::cout << "Bureaucrat " << this->name << " created" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &bureaucrat) : name(bureaucrat.name), grade(bureaucrat.grade) {
	std::cout << "Bureaucrat " << this->name << " created" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " << this->name << " destroyed" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &bureaucrat) {
	if (this == &bureaucrat)
		return *this;
	this->grade = bureaucrat.grade;
	return *this;
}

void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    } catch (const Form::GradeTooLowException& e) {
        std::cout << name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

std::string const &Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::incrementGrade() {
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
