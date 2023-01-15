//
//  ComplexNumberPolar.cpp
//  ComplexNumber
//
//  Created by Raj Lakhanpal on 9/23/16.
//  Copyright © 2016 Raj Lakhanpal. All rights reserved.
//

#include <stdio.h>
#include "ComplexNumberPolar.h"

ComplexNumberPolar::ComplexNumberPolar() : ComplexNumber()
{
    radius=0;
    theta=0;
}
ComplexNumberPolar::ComplexNumberPolar(double real, double imaginary):ComplexNumber(real,imaginary)
{
    updateRadius();
    updateTheta();
}
ComplexNumberPolar::ComplexNumberPolar(const ComplexNumber &cn):ComplexNumber(cn)
{
    updateRadius();
    updateTheta();
}

ComplexNumberPolar::ComplexNumberPolar(const ComplexNumberPolar &cn)
{
    setR(cn.radius*cos(cn.theta));
    setI(cn.radius*sin(cn.theta));
    radius=cn.radius;
    theta=cn.theta;
}

    //--destructor
ComplexNumberPolar::~ComplexNumberPolar()
{

}

//--mutators
void ComplexNumberPolar::setR(double r)
{
    ComplexNumber::setR(r);
    updateRadius();
    updateTheta();
}
void ComplexNumberPolar::setI(double i)
{
    ComplexNumber::setI(i);
    updateRadius();
    updateTheta();
}

    //--accessors
double ComplexNumberPolar::getR()
{
    return ComplexNumber::getR();
}
double ComplexNumberPolar::getI()
{
    return ComplexNumber::getI();
}

double ComplexNumberPolar::getRadius()
{
 return radius;
}
double ComplexNumberPolar::getTheta()
{
 return theta;
}

    //--message handlers
void ComplexNumberPolar::print()
{
    updateRadius();
    updateTheta();
    std::cout << std::fixed << std::setprecision(3) << radius << " ( cos(" << theta<< ")+i sin(" << theta<< ") )"<<std::endl;
}

ComplexNumberPolar ComplexNumberPolar::mult(const ComplexNumberPolar &rhs)
{
    double r=radius*rhs.radius;
    double t=theta+rhs.theta;
    ComplexNumberPolar temp(r*cos(t),r*sin(t));
    return temp;
}
ComplexNumberPolar ComplexNumberPolar::div(const ComplexNumberPolar &rhs)
{
    if(fabs(rhs.radius)>1e-6)
       {
           double r=radius/rhs.radius;
           double t=theta-rhs.theta;
           ComplexNumberPolar temp(r*cos(t),r*sin(t));
           return temp;
       }
    else
       return ComplexNumberPolar(0,0);
}

bool ComplexNumberPolar::equals(const ComplexNumberPolar &rhs)
{
 /*update value for theta (if they for some reason be with difference 2Pi)*/
 if((fabs(rhs.radius-radius)<1e-6)&&(fabs(rhs.theta-theta)<1e-6))
    return true;
 else
    return false;
}

void ComplexNumberPolar::updateRadius()
{
    radius=pow(getI()*getI()+getR()*getR(),0.5);
}
void ComplexNumberPolar::updateTheta()
{
    if(fabs(getR())>1e-6)
        theta=atan(getI()/getR());
    else
        theta=M_PI;
}
