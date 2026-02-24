#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime> 

Base* generate(void) {
    int r = std::rand() % 3;

    switch (r) {
        case 0:
            std::cout << "Generated: A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated: B" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated: C" << std::endl;
            return new C();
    }
    return NULL;
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "Type identified: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type identified: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type identified: C" << std::endl;
    else
        std::cout << "Type identified: Unknown" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Type identified by reference: A" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Type identified by reference: B" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Type identified by reference: C" << std::endl;
        return;
    } catch (...) {}

    std::cout << "Type identified by reference: Unknown" << std::endl;
}

int	main(void) {
	std::srand(std::time(NULL));

    for (int i = 0; i < 5; ++i) {
        Base* obj = generate();

        identify(obj);
        identify(*obj);

        delete obj;
        std::cout << "----------------------" << std::endl;
    }

    return 0;
}