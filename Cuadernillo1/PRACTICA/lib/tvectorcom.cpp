

#include <iostream>
#include <sstream>
#include "tvectorcom.h"

TVectorCom::TVectorCom()
{
    c = NULL;
    tamano = 0;
}

TVectorCom::TVectorCom(int i)
{
    c = NULL;
    if (i <= 0)
    {
        tamano = 0;
    }
    else
    {
        tamano = i;
        c = new TComplejo[i];
    }
}

TVectorCom::TVectorCom(TVectorCom &d)
{
    tamano = d.tamano;
    c = new TComplejo[tamano];

    if (c == NULL)
    {
        return;
    }
    for (int i = 0; i < tamano; i++)
    {
        c[i] = d.c[i];
    }
}

TVectorCom::~TVectorCom()
{
    tamano=0;
    if(c!=NULL)
    {
        delete [] c;
        c=NULL;
    }
}

TVectorCom &TVectorCom::operator=(TVectorCom &d)
{
    if (this == &d)
    {
        return *this;
    }
    else
    {
        (*this).~TVectorCom();
        tamano = d.tamano;
        c = new TComplejo[tamano];
        for (int i = 0; i < tamano; i++)
        {
            c[i] = d.c[i];
        }
        return *this;
    }
}

bool TVectorCom::operator==(TVectorCom &d)
{
    if (tamano != d.tamano)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < tamano; i++)
        {
            if (c[i] != d.c[i])
            {
                return false;
            }
        }
    }
    return true;
}

bool TVectorCom::operator!=(TVectorCom &d)
{
    return !(*this == d);
}

TComplejo &TVectorCom::operator[](int i)
{
    if (i >= 1 && i <= tamano)
    {
        return c[i - 1];
    }
    return error;
}

TComplejo TVectorCom::operator[](int i) const
{
    if (i >= 1 && i <= tamano)
    {
        return c[i - 1];
    }
    return error;
}

int TVectorCom::Tamano()
{
    return tamano;
}

int TVectorCom::Ocupadas()
{
    int contador = 0;
    for (int i = 0; i < tamano; i++)
    {
        if (c[i] != error)
        {
            contador++;
        }
    }
    return contador;
}

bool TVectorCom::ExisteCom(TComplejo &d)
{
    for (int i = 0; i < tamano; i++)
    {
        if (c[i] == d)
        {
            return true;
        }
    }
    return false;
}

void TVectorCom::MostrarComplejos(double d)
{
    stringstream salida;
    salida << "[";
    bool primero = true;

    for (int i = 0; i < tamano; i++)
    {
        if (c[i].Re() >= d)
        {
            if (primero)
            {
                salida << c[i];
                primero = false;
            }
            else
            {
                salida << ", ";
                salida << c[i];
            }
        }
    }

    salida << "]";
    cout << salida.str();
}

bool TVectorCom::Redimensionar(int i)
{
    if (i <= 0 || i == tamano)
    {
        return false;
    }
    else
    {
        TComplejo *aux = new TComplejo[i];
        for (int j = 0; j < i; j++)
        {
            if (j < tamano)
            {
                aux[i] = c[i];
            }
            else
            {
                aux[i] = error;
            }
        }
        (*this).~TVectorCom();
        c = aux;
        tamano = i;
        delete [] aux;
        aux=NULL;
        return true;
    }
}

ostream &operator<<(ostream &os, TVectorCom &d)
{
    os << "[";
    for (int i = 1; i <= d.Tamano(); i++)
    {
        os << "(" << i << ") ";
        os << d.c[i-1];
        if (i != d.Tamano())
        {
            os << ", ";
        }
    }
    os << "]";

    return os;
}
