#ifndef __TCOMPLEJO__
#define __TCOMPLEJO__

#include <iostream>
using namespace std;

class TComplejo
{
    friend ostream &operator<<(ostream &,const TComplejo &);

    friend TComplejo operator+(double,TComplejo &);
    friend TComplejo operator-(double,TComplejo &);
    friend TComplejo operator*(double,TComplejo &);

private:
    double re;
    double im;
    void Copia(const TComplejo &);
public:
    TComplejo();
    TComplejo(double);
    TComplejo(double, double);
    TComplejo(const TComplejo &);
    ~TComplejo();
    TComplejo &operator=(const TComplejo &);

    TComplejo operator+(const TComplejo &);
    TComplejo operator-(const TComplejo &);
    TComplejo operator*(const TComplejo &);
    TComplejo operator+(double);
    TComplejo operator-(double);
    TComplejo operator*(double);

    bool operator==(TComplejo &);
    bool operator!=(TComplejo &);

    double Re();
    double Im();

    void Re(double);
    void Im(double);

    double Arg(void);
    double Mod(void);
};

#endif