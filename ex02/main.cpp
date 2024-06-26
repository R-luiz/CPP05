#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        // Create bureaucrats
        Bureaucrat boss("Boss", 1);
        Bureaucrat intern("Intern", 150);

        // Create forms
        ShrubberyCreationForm shrubForm("home");
        RobotomyRequestForm robotForm("employee");
        RobotomyRequestForm robotForm2("employee2");
        RobotomyRequestForm robotForm3("employee3");
        PresidentialPardonForm pardonForm("criminal");

        // Print initial state
        std::cout << boss << std::endl;
        std::cout << intern << std::endl;

        // Attempt to sign forms
        intern.signForm(shrubForm);
        boss.signForm(shrubForm);

        boss.signForm(robotForm);
        boss.signForm(pardonForm);
        boss.signForm(robotForm2);
        boss.signForm(robotForm3);

        // Execute forms
        std::cout << "Attempting to execute forms:" << std::endl;
        try {
            intern.executeForm(shrubForm);  // Should fail
            boss.executeForm(shrubForm);    // Should succeed and create a file
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            boss.executeForm(robotForm);  // Should output a robotomization message
            boss.executeForm(robotForm2);  // Should output a robotomization message
            boss.executeForm(robotForm3);  // Should output a robotomization message
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            boss.executeForm(pardonForm);  // Should pardon the criminal
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    return 0;
}
