#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main(void) {
{
    std::cout << "\n[Test] Form construction with invalid grades\n";
    try {
        Form f("InvalidLow", 0, 100);
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    try {
        Form f("InvalidHigh", 151, 150);
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

{
    std::cout << "\n[Test] Signing form with sufficient grade\n";
    Bureaucrat b("Alice", 40);
    Form f("Permit", 50, 100);

    std::cout << f << std::endl;
    b.signForm(f);
    std::cout << f << std::endl;
}

{
    std::cout << "\n[Test] Signing form with insufficient grade\n";
    Bureaucrat b("Bob", 100);
    Form f("License", 50, 100);

    std::cout << f << std::endl;
    b.signForm(f);
    std::cout << f << std::endl;
}
}