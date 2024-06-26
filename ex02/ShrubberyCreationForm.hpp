
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &form);
		~ShrubberyCreationForm();
		
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &form);

		std::string const &getTarget() const;
		void execute(Bureaucrat const &executor) const;

		class FileOpenException : public std::exception {
		public:
			const char *what() const throw() {
				return "File open failed";
			}
		};
};

#endif
