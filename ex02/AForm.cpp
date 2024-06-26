
#include "AForm.hpp"

AForm::AForm() : name("default"), formSigned(false), gradeToSign(150), gradeToExecute(150) {
	std::cout << "Form " << name << " created" << std::endl;
}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) : name(name), formSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	std::cout << "Form " << name << " created" << std::endl;
}

AForm::AForm(AForm const &form) : name(form.name), formSigned(form.formSigned), gradeToSign(form.gradeToSign), gradeToExecute(form.gradeToExecute) {
	std::cout << "Form " << name << " created" << std::endl;
}

AForm::~AForm() {
	std::cout << "Form " << name << " destroyed" << std::endl;
}

AForm &AForm::operator=(AForm const &form) {
	if (this == &form)
		return *this;
	formSigned = form.formSigned;
	return *this;
}

std::string const &AForm::getName() const {
	return name;
}

bool AForm::getFormSigned() const {
	return formSigned;
}

int AForm::getGradeToSign() const {
	return gradeToSign;
}

int AForm::getGradeToExecute() const {
	return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (this->formSigned)
	{
		std::cout << "Form " << this->name << " is already signed by " << bureaucrat.getName() << std::endl;
		return;
	}
    if (bureaucrat.getGrade() > this->gradeToSign) {
        throw GradeTooLowException();
    }
    this->formSigned = true;
}

std::ostream &operator<<(std::ostream &out, AForm const &form) {
	out << "Form " << form.getName() << " is ";
	if (!form.getFormSigned())
		out << "not ";
	out << "signed";
	return out;
}

void AForm::execute(const Bureaucrat& executor) const {
	if (!this->formSigned) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > this->gradeToExecute) {
		throw GradeTooLowException();
	}
}
