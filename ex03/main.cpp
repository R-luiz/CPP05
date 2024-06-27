#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
int main() {
    try {
        Bureaucrat boss("Boss", 1);
        Intern someRandomIntern;

        // Correcting form names to exactly match expected identifiers
        AForm* pardonForm = someRandomIntern.makeForm("PresidentialPardonForm", "criminal");
        AForm* robotForm = someRandomIntern.makeForm("RobotomyRequestForm", "employee");
        AForm* shrubForm = someRandomIntern.makeForm("ShrubberyCreationForm", "home");

        boss.signForm(*pardonForm);
        boss.signForm(*robotForm);
        boss.signForm(*shrubForm);

        boss.executeForm(*pardonForm);
        boss.executeForm(*robotForm);
        boss.executeForm(*shrubForm);

        delete pardonForm;
        delete robotForm;
        delete shrubForm;

    } catch (const std::exception& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    return 0;
}
