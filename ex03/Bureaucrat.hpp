
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string const name;
		int grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &bureaucrat);
		~Bureaucrat();
		
		Bureaucrat &operator=(Bureaucrat const &bureaucrat);

		std::string const &getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm& form);
		void executeForm(AForm const &form);
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

};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);

#endif