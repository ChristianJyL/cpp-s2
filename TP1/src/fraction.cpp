#include "fraction.hpp"
#include "utils.hpp"

void Fraction::display()
{
    std::cout << numerator << "/" << denominator;
}

std::ostream &operator<<(std::ostream &os, Fraction const &f)
{
    return os << f.numerator << "/" << f.denominator;
}

bool operator==(Fraction const &f1, Fraction const &f2)
{
    return f1.numerator * f2.denominator == f2.numerator * f1.denominator;
}
bool operator!=(Fraction const &f1, Fraction const &f2)
{
    return !(f1 == f2);
}

bool operator<(Fraction const &f1, Fraction const &f2)
{
    if (f1.denominator == f2.denominator)
    {
        return f1.numerator < f2.numerator;
    }
    else
    {
        return f1.denominator > f2.denominator;
    }
}

bool operator>(Fraction const &f1, Fraction const &f2)
{
    return f2 < f1;
}

bool operator<=(Fraction const &f1, Fraction const &f2)
{
    return f1 < f2 || f1 == f2;
}

bool operator>=(Fraction const &f1, Fraction const &f2)
{
    return f1 > f2 || f1 == f2;
}

Fraction &operator+=(Fraction &f1, Fraction const &f2)
{
    f1.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    f1.denominator *= f2.denominator;
    f1 = simplify(f1);
    return f1;
}

Fraction &operator-=(Fraction &f1, Fraction const &f2)
{
    f1.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    f1.denominator = f1.denominator * f2.denominator;
    f1 = simplify(f1);
    return f1;
}

Fraction &operator*=(Fraction &f1, Fraction const &f2)
{
    f1.numerator = f1.numerator * f2.numerator;
    f1.denominator = f1.denominator * f2.denominator;
    f1 = simplify(f1);
    return f1;
}

Fraction &operator/=(Fraction &f1, Fraction const &f2)
{
    f1.numerator = f1.numerator * f2.denominator;
    f1.denominator = f1.denominator * f2.numerator;
    f1 = simplify(f1);
    return f1;
}

Fraction operator+(Fraction f1, Fraction const &f2)
{
    f1 += f2;
    return f1;
}

Fraction operator-(Fraction f1, Fraction const &f2)
{
    f1 -= f2;
    return f1;
}

Fraction operator*(Fraction f1, Fraction const &f2)
{
    f1 *= f2;
    return f1;
}

Fraction operator/(Fraction f1, Fraction const &f2)
{
    f1 /= f2;
    return f1;
}

Fraction::operator float() const
{
    return static_cast<float>(numerator) / denominator;
}