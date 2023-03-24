
#include "tcomplejo.h"
#include <math.h>
#include <cmath>

void TComplejo::Copia(const TComplejo &d)
{
    re = d.re;
    im = d.im;
}

TComplejo::TComplejo()
{
    re = 0;
    im = 0;
}

TComplejo::TComplejo(double d)
{
    re = d;
    im = 0;
}

TComplejo::TComplejo(double d, double i)
{
    re = d;
    im = i;
}

TComplejo::TComplejo(const TComplejo &d)
{
    Copia(d);
}

TComplejo::~TComplejo()
{
    re = 0;
    im = 0;
}

TComplejo &TComplejo::operator=(const TComplejo &d)
{
    if (this != &d)
    {
        (*this).~TComplejo();

        Copia(d);
    }

    return *this;
}

TComplejo TComplejo::operator+(const TComplejo &d)
{
    TComplejo result;

    result.re = this->re + d.re;
    result.im = this->im + d.im;

    return result;
}

TComplejo TComplejo::operator-(const TComplejo &d)
{
    TComplejo result;

    result.re = this->re - d.re;
    result.im = this->im - d.im;

    return result;
}

TComplejo TComplejo::operator*(const TComplejo &d)
{
    TComplejo result;

    result.re = ((this->re * d.re) - (this->im * d.im));
    result.im = ((this->re * d.im) - (this->im * d.re));

    return result;
}

TComplejo TComplejo::operator+(double d)
{
    TComplejo suma(d);

    return *this + suma;
}

TComplejo TComplejo::operator-(double d)
{
    TComplejo resta(d);

    return *this - resta;
}

TComplejo TComplejo::operator*(double d)
{
    TComplejo mult(d);

    return *this * mult;
}

bool TComplejo::operator==(TComplejo &d)
{
    if (re == d.re && im == d.im)
    {
        return true;
    }
    return false;
}

bool TComplejo::operator!=(TComplejo &d)
{
    return !(*this == d);
}

double TComplejo::Re()
{
    return re;
}

double TComplejo::Im()
{
    return im;
}

void TComplejo::Re(double d)
{
    re = d;
}

void TComplejo::Im(double d)
{
    im = d;
}

double TComplejo::Arg(void)
{
    double d = atan2(im, re);
    return d;
}

double TComplejo::Mod(void)
{
    double d = sqrt(pow(re, 2) + pow(im, 2));
    return d;
}


ostream &operator<<(ostream &os,const TComplejo & d){

    os << "(" << d.re << " " << d.im << ")";

	return os;
}

TComplejo operator+(double t,TComplejo &d){
    return d+t;
}
TComplejo operator-(double t,TComplejo &d){
    return d-t;
}
TComplejo operator*(double t,TComplejo &d){
    return d*t;
}

