

#include <iostream>
#include <sstream>
#include "tlistacom.h"

TListaNodo::TListaNodo()
{
    anterior = NULL;
    siguiente = NULL;
}

TListaNodo::TListaNodo(TListaNodo &n)
{
    e = n.e;
    anterior = n.anterior;
    siguiente = n.siguiente;
}

TListaNodo::~TListaNodo()
{
    e.~TComplejo();

    anterior = NULL;
    siguiente = NULL;
}

TListaNodo &TListaNodo::operator=(TListaNodo &d)
{
    if (this == &d)
    {
        return *this;
    }
    else
    {
        (*this).~TListaNodo();
        e = d.e;
        anterior = d.anterior;
        siguiente = d.siguiente;
        return *this;
    }
}

// TListaPos

TListaPos::TListaPos()
{
    pos=NULL;
}
TListaPos::TListaPos(const TListaPos &d)
{
    pos = d.pos;
}

TListaPos::~TListaPos()
{
    pos = NULL;
}

TListaPos &TListaPos::operator=(const TListaPos &d)
{
    if (this == &d)
    {
        return *this;
    }
    else
    {
        (*this).~TListaPos();
        pos=NULL;
        pos=d.pos;
        return *this;
    }
}

bool TListaPos::operator==(const TListaPos &d)
{
    if(pos==d.pos)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TListaPos::operator!=(const TListaPos &d)
{
    return !(this->operator==(d));
}

TListaPos TListaPos::Anterior()
{
    TListaPos d;
    if(this->pos->anterior != NULL)
    {
        d.pos =pos->anterior;
    }
    return d;
}

TListaPos TListaPos::Siguiente()
{
    TListaPos d;
    if(this->pos->siguiente != NULL)
    {
        d.pos =pos->siguiente;
    }
    return d;
}

bool TListaPos::EsVacia()
{
     if(pos == NULL)
    {
        return true;
    }
    return false;
}

// TListaCom

TListaCom::TListaCom()
{
   primero = NULL;
   ultimo = NULL;
}

TListaCom::TListaCom(const TListaCom &d)
{
    primero=NULL;
    ultimo=NULL;
    TListaPos otro = d.Ultima();
    while(!otro.EsVacia())
    {
        InsCabeza(otro.pos->e);

        otro=otro.Anterior();
    }

}

TListaCom::~TListaCom()
{
    TListaNodo *aux;

    while(this->primero != NULL)
    {
        aux = this->primero->siguiente;
        delete this->primero;
        this->primero=aux;
    }

}

TListaCom &TListaCom::operator=(const TListaCom &d)
{
    if (this == &d)
    {
        return *this;
    }
    else
    {
        (*this).~TListaCom();
        TListaPos otro=d.Ultima();
        while(!otro.EsVacia())
        {
            InsCabeza(otro.pos->e);
            otro=otro.Anterior();
        }
        return *this;
    }
}

bool TListaCom::operator==(TListaCom &d)
{
    while(primero !=NULL)
    {
        if(d.primero==NULL)
        {
            return false;
        }
        else
        {
            if(primero->e!=d.primero->e)
            {
                return false;
            }
            else
            {
                primero=primero->siguiente;
                d.primero=d.primero->siguiente;
            }
        }
    }
    return true;
}

bool TListaCom::operator!=(TListaCom &d)
{
    return !(*this == d);
}

TListaCom TListaCom::operator+(TListaCom &d)
{
    TListaCom res;

    TListaPos otro = d.Ultima();
    while(!otro.EsVacia())
    {
        res.InsCabeza(otro.pos->e);

        otro=otro.Anterior();
    }
    otro=Ultima();
    while(!otro.EsVacia())
    {
        res.InsCabeza(otro.pos->e);

        otro=otro.Anterior();
    }
    return res;
}

TListaCom TListaCom::operator-(TListaCom &d)
{
    TListaCom res;
    bool comprobar=true;
    TListaPos otro=Ultima();
    while(!otro.EsVacia())
    {
        if(!d.Buscar(otro.pos->e))
        {
            res.InsCabeza(otro.pos->e);
            otro=otro.Anterior();
        }
        else
        {
            otro=otro.Anterior();
        }
        
    }

    return res;
}

bool TListaCom::EsVacia()
{
    if(primero==NULL)
    {
        return true;
    }
    return false;
}

bool TListaCom::InsCabeza(TComplejo &d)
{
    TListaNodo *aux;
    if(aux=new TListaNodo())
    {
        aux->e=d;
    }
    else
    {
        return false;
    }
    if(EsVacia())
    {
        primero=aux;
        ultimo=primero;
        return true;
    }
    else
    {
        while(primero->anterior!=NULL)
        {
            primero=primero->anterior;
        }
        aux->siguiente=primero;
        primero->anterior=aux;
        primero=primero->anterior;
        return true;
    }
    
}

bool TListaCom::InsertarI(TComplejo &d,const TListaPos &n)
{
    TListaNodo *aux;
    if(aux=new TListaNodo())
    {
        aux->e=d;
    }
    else
    {
        return false;
    }
    TListaPos otro=n;
    while(!EsVacia())
    {
        if(Primera()==n)
        {
            if(primero->anterior==NULL)
            {
                aux->siguiente=primero;
                primero->anterior=aux;
                primero=primero->anterior;
                return true;
            }
            else
            {
                aux->anterior=primero->anterior;
                aux->siguiente=primero;
                primero->anterior->siguiente=aux;
                primero->anterior=aux;
                primero=primero->anterior;
                return true;
            }
        }
        else
        {
            primero=primero->siguiente;
        }
    }
    return false;
}

bool TListaCom::InsertarD(TComplejo &d,const TListaPos &n)
{
    TListaNodo *aux;
    if(aux=new TListaNodo())
    {
        aux->e=d;
    }
    else
    {
        return false;
    }
    TListaPos otro=n;
    while(!EsVacia())
    {
        if(Primera()==n)
        {
            if(primero->siguiente==NULL)
            {
                aux->anterior=primero;
                primero->siguiente=aux;
                ultimo=primero->siguiente;
                return true;
            }
            else
            {
                aux->siguiente=primero->siguiente;
                aux->anterior=primero;
                primero->siguiente->anterior=aux;
                primero->siguiente=aux;

                return true;
            }
        }
        else
        {
            primero=primero->siguiente;
        }
    }
    return false;
}

bool TListaCom::Borrar(TComplejo &d)
{
    TListaNodo *aux;
    if(!Buscar(d))
    {
        return false;
    }
    while(primero!=NULL)
    {
        if(primero->e==d)
        {
            aux=primero;
            if(primero->anterior!=NULL && primero->siguiente!=NULL)
            {
                primero->anterior->siguiente=primero->siguiente;
                primero->siguiente->anterior=primero->anterior;
                primero=primero->anterior;
                delete aux;
                return true;
            }
            else if(primero->anterior==NULL)
            {
                primero=primero->siguiente;
                primero->anterior->siguiente==NULL;
                primero->anterior==NULL;
                delete aux;
                return true;
            }
        }
        primero=primero->siguiente;

    }
    return false;
}

bool TListaCom::BorrarTodos(TComplejo &d)
{
    bool sol=false;
    while(Borrar(d))
    {
        sol=true;
    }
    return sol;
}

bool TListaCom::Borrar(TListaPos &d)
{
    TListaNodo *aux;
    while(!EsVacia())
    {
        if(primero==d.pos)
        {
            aux=primero;
            primero->anterior->siguiente=primero->siguiente;
            primero->siguiente->anterior=primero->anterior;
            delete aux;
            return true;
        }
        else
        {
            primero=primero->siguiente;
        }
    }
    return false;
}

TComplejo TListaCom::Obtener(TListaPos &d)
{
    return d.pos->e;
}

bool TListaCom::Buscar(TComplejo &d)
{
    for(TListaPos i=Primera(); !i.EsVacia();i=i.Siguiente())
    {
        if(Obtener(i)==d)
        {
            return true;
        }
    }
    return false;
}

int TListaCom::Longitud() const
{
    int cont=0;
    for(TListaPos i= Primera(); !i.EsVacia();i=i.Siguiente())
    {
        cont++;
    }
    return cont;
}

TListaPos TListaCom::Primera() const
{
    TListaPos tpos;
    if(this->primero == NULL)
        return tpos;
    else{
        tpos.pos = this->primero;
        return tpos; 
    }
}

TListaPos TListaCom::Ultima() const
{
    TListaPos tpos;
    tpos.pos=ultimo;
    return tpos;
    
}

ostream &operator<<(ostream &os, TListaCom &d)
{
    os << "{";
    for (TListaPos i = d.Primera(); !i.EsVacia(); i=i.Siguiente())
    {
        os << d.Obtener(i);
        if(i!= d.Ultima())
        {
            os << " ";
        }
    }
    os << "}";

    return os;
}