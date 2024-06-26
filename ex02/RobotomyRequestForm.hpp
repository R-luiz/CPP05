
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &form);
		~RobotomyRequestForm();
		
		RobotomyRequestForm &operator=(RobotomyRequestForm const &form);

		std::string const &getTarget() const;
		void execute(Bureaucrat const &executor) const;

		class RobotomizeException : public std::exception {
		public:
			const char *what() const throw() {
				return "Robotomize failed";
			}
		};
};

#endif









