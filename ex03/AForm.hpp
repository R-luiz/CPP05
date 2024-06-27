
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const name;
		bool formSigned;
		int const gradeToSign;
		int const gradeToExecute;

	public:
		AForm();
		AForm(std::string const &name, int gradeToSign, int gradeToExecute);
		AForm(AForm const &form);
		virtual ~AForm();
		
		AForm &operator=(AForm const &form);

		std::string const &getName() const;
		bool getFormSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat const &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException : public std::exception {
		public:
			const char *what() const throw() {
				return "Grade too high";
			}
		};

		class GradeTooLowException : public std::exception {
		public:
			const char *what() const throw() {
				return "Grade too low";
			}
		};

		class FormNotSignedException : public std::exception {
		public:
			const char *what() const throw() {
				return "Form not signed";
			}
		};
};

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif