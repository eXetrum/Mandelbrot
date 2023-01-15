//
//  ComplexNumber.cpp
//  ComplexNumber
//
//  Created by Raj Lakhanpal on 9/13/16.
//  Copyright © 2016 Raj Lakhanpal. All rights reserved.
//

#include "ComplexNumber.hpp"

//--constructors
ComplexNumber::ComplexNumber()
{
    re=0;
    im=0;
}
ComplexNumber::ComplexNumber(double r, double i) //:re(r), im(i)
{
    re = r;
    im = i;


}
ComplexNumber::ComplexNumber(const ComplexNumber &cn)
{
    re=cn.re;
    im=cn.im;
}

//--destructor
ComplexNumber::~ComplexNumber()
{

}

//--mutators
void ComplexNumber::setR(double r)
{
    re=r;
}
void ComplexNumber::setI(double i)
{
    im=i;
}

//--accessors
double ComplexNumber::getR() const
{
    return re;
}
double ComplexNumber::getI() const
{
    return im;
}

//--message handlers
void ComplexNumber::print() const
{
    std::cout << std::fixed << std::setprecision(1) << this->re << " + " << this->im << "i" << std::endl;
}

//--add two complex numbers
ComplexNumber ComplexNumber::add(const ComplexNumber &rhs) const
{
    return ComplexNumber(this-> re + rhs.re, this-> im + rhs.im);
}


//--subtract two complex numbers
ComplexNumber ComplexNumber::sub(const ComplexNumber &rhs) const
{
    return ComplexNumber(this-> re - rhs.re, this->im - rhs.im);
}

//--multiply two complex numbers
ComplexNumber ComplexNumber::mult(const ComplexNumber &rhs) const
{

    //return ComplexNumber(this-> re * rhs.re - im * rhs.im, this->im * rhs.im - re + rhs.re);
	return ComplexNumber(this->re * rhs.re - im * rhs.im, this->re * rhs.im + rhs.re * this->im);
}


//--divide two complex numbers
ComplexNumber ComplexNumber::div(const ComplexNumber &rhs) const
{

    return ComplexNumber(((this-> re) * (rhs.re) + ((im) * (rhs.im))) / (pow(rhs.re, 2) + pow(rhs.im, 2)), (((this-> im) * (rhs.re) - ((re) * (rhs.im))) / (pow(rhs.re, 2) + pow(rhs.im, 2))));
}


//--conjugate two complex numbers
ComplexNumber ComplexNumber::conj() const
{

    return ComplexNumber(this-> re, -1 * this->im);

}

double ComplexNumber::mag () const {
    return ::sqrt(this->re * this->re + this->im * this->im);
}




