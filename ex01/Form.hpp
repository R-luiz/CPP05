
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Form
{
	private:
		std::string const name;
		bool formSigned;
		int const gradeToSign;
		int const gradeToExecute;

	public:
		Form();
		Form(std::string const &name, int gradeToSign, int gradeToExecute);
		Form(Form const &form);
		~Form();
		
		Form &operator=(Form const &form);

		std::string const &getName() const;
		bool getFormSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat const &bureaucrat);

		class GradeTooHighException : public std::exception {
			const char *what() const throw() {
				return "Grade too high";
			}
		};

		class GradeTooLowException : public std::exception {
			const char *what() const throw() {
				return "Grade too low";
			}
		};

		class FormNotSignedException : public std::exception {
			const char *what() const throw() {
				return "Form not signed";
			}
		};
};

#endif