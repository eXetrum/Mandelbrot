//
//  ComplexNumber.hpp
//  ComplexNumber
//
//  Created by Raj Lakhanpal on 9/13/16.
//  Copyright © 2016 Raj Lakhanpal. All rights reserved.
//

#ifndef ComplexNumber_hpp
#define ComplexNumber_hpp

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cmath>

#ifndef M_PI
#define M_PI 3.1415926
#endif // !


class ComplexNumber
{
public:
    
    //--constructors
    ComplexNumber();
    ComplexNumber(double r, double i);
    ComplexNumber(const ComplexNumber &cn);
    
    //--destructor
    ~ComplexNumber();
    
    //--mutators
    void setR(double r);
    void setI(double i);
    
    //--accessors
    double getR() const;
    double getI() const;
    
    //--message handlers
    void print() const;
    ComplexNumber add(const ComplexNumber &rhs) const;
    ComplexNumber sub(const ComplexNumber &rhs) const;
    ComplexNumber mult(const ComplexNumber &rhs) const;
    ComplexNumber div(const ComplexNumber &rhs) const;
    ComplexNumber conj() const;
    ComplexNumber sqrt() const;
    double mag() const;
    bool equals(const ComplexNumber &rhs) const;
    
    
private:
    double re, im;
    
};


#endif /* ComplexNumber_hpp */
