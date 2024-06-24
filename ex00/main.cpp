
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *bureaucrat = new Bureaucrat("John", 1);
	std::cout << bureaucrat << std::endl;
	
	try
	{
		bureaucrat->incrementGrade();
		bureaucrat->decrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught 1: " << e.what() << std::endl;
	}
	
	try
	{
		bureaucrat->decrementGrade();
		bureaucrat->incrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught 2: " << e.what() << std::endl;
	}
	std::cout << bureaucrat->getGrade() << std::endl;
	delete bureaucrat;
		
}