#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat john("John", 2);
        Bureaucrat boss("Boss", 1);
        Form taxForm("1040EZ", 1, 1);
        
        std::cout << john << std::endl;
        std::cout << boss << std::endl;
        std::cout << taxForm << std::endl;
        
        // Test signing with an adequate grade
        john.signForm(taxForm); // Should fail
        boss.signForm(taxForm); // Should succeed
        
        // Decrement and increment tests
        john.incrementGrade();
        std::cout << "After increment: " << john << std::endl;
        john.decrementGrade();
        john.decrementGrade(); // Should throw an exception and not print
        
    } catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // Test lower bounds
    try {
        Bureaucrat lowRank("Intern", 150);
        Form impossibleForm("Impossible", 149, 150);
        lowRank.signForm(impossibleForm);  // Should fail
        std::cout << impossibleForm << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception caught for low rank: " << e.what() << std::endl;
    }

    return 0;
}
