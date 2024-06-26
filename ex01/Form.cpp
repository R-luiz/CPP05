
#include "Form.hpp"

Form::Form() : name("default"), formSigned(false), gradeToSign(150), gradeToExecute(150) {
	std::cout << "Form " << name << " created" << std::endl;
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) : name(name), formSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form " << name << " created" << std::endl;
}

Form::Form(Form const &form) : name(form.name), formSigned(form.formSigned), gradeToSign(form.gradeToSign), gradeToExecute(form.gradeToExecute) {
	std::cout << "Form " << name << " created" << std::endl;
}

Form::~Form() {
	std::cout << "Form " << name << " destroyed" << std::endl;
}

Form &Form::operator=(Form const &form) {
	if (this == &form)
		return *this;
	formSigned = form.formSigned;
	return *this;
}

std::string const &Form::getName() const {
	return name;
}

bool Form::getFormSigned() const {
	return formSigned;
}

int Form::getGradeToSign() const {
	return gradeToSign;
}

int Form::getGradeToExecute() const {
	return gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > this->gradeToSign) {
        throw GradeTooLowException();
    }
    this->formSigned = true;
}

std::ostream &operator<<(std::ostream &out, Form const &form) {
	out << "Form " << form.getName() << " is ";
	if (!form.getFormSigned())
		out << "not ";
	out << "signed";
	return out;
}
