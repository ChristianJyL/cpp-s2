#pragma once

#include <iostream>

struct Fraction {
    unsigned int numerator;
    unsigned int denominator;

    void display();

    operator float() const;

};


std::ostream& operator<<(std::ostream& os, Fraction const& f);
bool operator==(Fraction const& f1, Fraction const& f2);
bool operator!=(Fraction const& f1, Fraction const& f2);
bool operator<(Fraction const& f1, Fraction const& f2);
bool operator>(Fraction const& f1, Fraction const& f2);
bool operator<=(Fraction const& f1, Fraction const& f2);
bool operator>=(Fraction const& f1, Fraction const& f2);


Fraction operator+(Fraction f1, Fraction const& f2);
Fraction operator-(Fraction f1, Fraction const& f2);
Fraction operator*(Fraction f1, Fraction const& f2);
Fraction operator/(Fraction f1, Fraction const& f2);

Fraction& operator+=(Fraction& f1, Fraction const& f2);
Fraction& operator-=(Fraction& f1, Fraction const& f2);
Fraction& operator*=(Fraction& f1, Fraction const& f2);
Fraction& operator/=(Fraction& f1, Fraction const& f2);

