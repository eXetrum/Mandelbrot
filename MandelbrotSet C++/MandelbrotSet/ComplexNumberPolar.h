//
//  ComplexNumberPolar.h
//  ComplexNumber
//
//  Created by Raj Lakhanpal on 9/23/16.
//  Copyright © 2016 Raj Lakhanpal. All rights reserved.
//

#ifndef ComplexNumberPolar_h
#define ComplexNumberPolar_h
#include "ComplexNumber.hpp"

class ComplexNumberPolar : public ComplexNumber
{
public:

    //--constructors
    ComplexNumberPolar();
    ComplexNumberPolar(double real, double imaginary);
    ComplexNumberPolar(const ComplexNumber &cn);
    ComplexNumberPolar(const ComplexNumberPolar &cn);

    //--destructor
    ~ComplexNumberPolar();

    //--mutators
    void setR(double r);
    void setI(double i);

    //--accessors
    double getR();
    double getI();
    double getRadius();
    double getTheta();

    //--message handlers
    void print();
    ComplexNumberPolar mult(const ComplexNumberPolar &rhs);
    ComplexNumberPolar div(const ComplexNumberPolar &rhs);

    bool equals(const ComplexNumberPolar &rhs);


private:
    double radius,theta;
    void updateRadius();
    void updateTheta();
};


#endif /* ComplexNumberPolar_h */
