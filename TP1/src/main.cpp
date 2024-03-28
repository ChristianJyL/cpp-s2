#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1{3, 4}; 
    Fraction f2{1, 2};

    std::cout << "f1 = " << f1 << std::endl;
    std::cout << "f2 = " << f2 << std::endl;

    Fraction f3{f1 + f2};

    std::cout << "add(f1, f2) = " << f3;

    std::cout << std::endl
              << "sub(f1, f2) = " << f1 - f2;

    std::cout << std::endl
              << "mul(f1, f2) = " << f1 * f2;

    std::cout << std::endl
              << "div(f1, f2) = " << f1 / f2;

    std::cout << std::endl
              << "add(1/6, 2/6) = " << (Fraction{1, 6} + Fraction{2, 6}) << std::endl;

    // Egalité
    f1 = {1, 2};
    f2 = {2, 4};
    std::cout << "Egalité (1/2) == (2/4) : " << (f1 == f2) << std::endl;

    f1 = {1, 3};
    std::cout << "Egalité (1/3) == (2/4) ?: " << (f1 == f2) << std::endl;
    std::cout << "Inégalité (1/2) != (1/3) : " << (f1 != f2) << std::endl;

    // Comparaison
    f1 = {7, 8};
    f2 = {3, 6};
    std::cout << "Comparaison (7/8) < (3/6) : " << (f1 < f2) << std::endl;

    f1 = {3, 4};
    f2 = {3, 2};
    std::cout << "Comparaison (3/4) < (3/2) : " << (f1 < f2) << std::endl;

    std::cout << "Comparaison (3/4) <= (3/2) : " << (f1 <= f2) << std::endl;
    f2 = {3, 4};
    std::cout << "Comparaison (3/4) >= (3/4) : " << (f1 >= f2) << std::endl;

    // Opérateur +=, -=, *=, /=
    f1 = {3, 4};
    f2 = {1, 2};
    f1 += f2;
    std::cout << "f1 += f2 : " << f1 << std::endl;

    f1 = {3, 4};
    f1 -= f2;
    std::cout << "f1 -= f2 : " << f1 << std::endl;

    f1 = {3, 4};
    f1 *= f2;
    std::cout << "f1 *= f2 : " << f1 << std::endl;

    f1 = {3, 4};
    f1 /= f2;
    std::cout << "f1 /= f2 : " << f1 << std::endl;

    // Conversion :
    f1={1, 2};
    float d1{static_cast<float>(f1)}; // conversion explicite avec static_cast
    std::cout << d1 << std::endl;

    return 0;
}