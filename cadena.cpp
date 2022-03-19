#include "cadena.hpp"
#include <cstring>
#include <stdexcept>

Cadena::Cadena(unsigned t, char c)
{
    tam_ = t;
    s_ = new char[t+1];
    for (int i = 0; i <t; i++)
    {
        s_[i] = c;
    }
    s_[t] = '\0';
}

Cadena::Cadena(const char* S)
{
    tam_ = strlen(S);
    s_ = new char[tam_ + 1];

    strcpy(s_,S);
}

Cadena::Cadena(const Cadena& S)
{
    s_ = new char[S.tam_ + 1];
    tam_ = S.tam_;
    strcpy(s_,S.s_);
}

Cadena Cadena::operator= (const Cadena& S)
{
    if (this != &S)
    {
        if (tam_ != S.tam_)
        {
            delete[] s_;
            tam_ = S.tam_;
            s_ = new char[S.tam_ + 1];
        }
        strcpy(s_,S.s_);
    }
    return *this;
}

Cadena Cadena::operator= (const char* S)
{
    if (tam_ != strlen(S))
    {
        delete[] s_;
        tam_ = strlen(S);
        s_ = new char[tam_ + 1];
    }
    strcpy(s_,S);
    return* this;
}

const char* Cadena::c_str() const
{
    return s_;
}

Cadena& Cadena::operator+=(Cadena& C)
{
    unsigned tam = this->tam_ + C.tam_;
    Cadena Cad{tam};
    strcpy(Cad.s_,this->s_);
    strcat(Cad.s_, C.s_);
    *this = Cad;
    return *this;
}

Cadena operator+ (Cadena& S, Cadena& C)
{
    unsigned tam = S.tam_ + C.tam_;
    Cadena Cad{tam};
    strcpy(Cad.s_,S.s_);
    strcat(Cad.s_,C.s_);
    return Cad;
}

char Cadena::operator[](int n) const
{
    return s_[n];
}

char& Cadena::operator[](int n)
{
    return s_[n];
}
unsigned Cadena:: length() const
{
    return tam_;
}

char Cadena::at(int n) const
{
    if (n < 0 || n > tam_ - 1)
    {
        throw std::out_of_range("Fuera de rango");
    }
    
    return s_[n];
}

char& Cadena::at(int n)
{
    if (n < 0 || n > tam_ - 1)
    {
        throw std::out_of_range("Fuera de rango");
    }
    
    return s_[n];
}

bool operator== (const Cadena& S, const Cadena& C)
{
    if(strcmp(S.c_str(),C.c_str()) == 0)
        return true;
    else
        return false;
}

bool operator != (const Cadena& S, const Cadena& C)
{
    return !(S==C);
}

bool operator < (const Cadena& S, const Cadena& C)
{
    if(strcmp(S.c_str(),C.c_str()) > 0)
        return true;
    else
        return false;
}

bool operator > (const Cadena& S, const Cadena& C)
{
    return !((S < C) || (S == C));
}

bool operator <= (const Cadena& S, const Cadena& C)
{
    return (S<C || S==C);
}

bool operator >= (const Cadena& S, const Cadena& C)
{
    return (S > C || S == C);
}

Cadena Cadena::substr(int i, unsigned t) const
{
    if (i > tam_ - 1 || i < 0 || i + t > tam_ - 1)
    {
        throw std::out_of_range("Fuera de rango");
    }

    Cadena C{t};
    for (size_t j = 0; j < t; j++)
    {
        C[j] = s_[j+i];
    }
    
    return C;
}


Cadena::Cadena(Cadena&& S): s_(S.s_), tam_(S.tam_)
{
    S.s_ == nullptr;
    tam_ = 0;
}

Cadena Cadena::operator=(Cadena&& S)
{
    if(this != &S)
    {
        if(tam_ != S.tam_)
        {
            delete[] s_;
        }

        tam_ = S.tam_;
        s_ = S.s_;
        S.tam_ = 0;
        S.s_ = nullptr;
    }

    return *this;
}