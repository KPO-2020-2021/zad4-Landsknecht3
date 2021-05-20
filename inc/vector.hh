#pragma once

#include "size.hh"
#include <iostream>
#include <cmath>

template <typename TYPE, unsigned int SIZE>
class Vector
{
private:
    TYPE coor[SIZE];
public:
    Vector();

    Vector(double [SIZE]);

    Vector operator +(const Vector &v);

    Vector operator -(const Vector &v);

    Vector operator *(const TYPE &mul);

    Vector operator /(const TYPE &div);

    const double &operator [] (unsigned int index) const;

    double &operator [] (unsigned int index);

};


/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartoscia 0.                                       |
 */
template<typename TYPE, unsigned int SIZE>
Vector<TYPE, SIZE>::Vector() {
    for (unsigned int i = 0; i < SIZE; ++i) {
        coor[i] = 0;
    }
}


/******************************************************************************
 |  Konstruktor klasy Vector.                                                 |
 |  Argumenty:                                                                |
 |      tmp - Jednowymiarowa tablica typu double.                             |
 |  Zwraca:                                                                   |
 |      Tablice wypelniona wartosciami podanymi w argumencie.                 |
 */

template<typename TYPE, unsigned int SIZE>
Vector<TYPE, SIZE>::Vector(double tmp[SIZE]) {
    for (unsigned int i = 0; i < SIZE; ++i) {
        coor[i] = tmp[i];
    }
}


/******************************************************************************
 |  Realizuje dodawanie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik dodawania,                                   |
 |      v - drugi skladnik dodawania.                                         |
 |  Zwraca:                                                                   |
 |      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |      na parametr.                                                          |
 */
template<typename TYPE, unsigned int SIZE>
Vector<TYPE, SIZE> Vector<TYPE, SIZE>::operator + (const Vector &v) {
    Vector result;
    for (unsigned int i = 0; i < SIZE; ++i) {
        result[i] = coor[i] += v[i];
    }
    return result;
}


/******************************************************************************
 |  Realizuje odejmowanie dwoch wektorow.                                     |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik odejmowania,                                 |
 |      v - drugi skladnik odejmowania.                                       |
 |  Zwraca:                                                                   |
 |      Roznice dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */
template<typename TYPE, unsigned int SIZE>
Vector<TYPE, SIZE> Vector<TYPE, SIZE>::operator - (const Vector &v) {
    Vector result;
    for (unsigned int i = 0; i < SIZE; ++i) {
        result[i] = coor[i] -= v[i];
    }
    return result;
}


/******************************************************************************
 |  Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa.               |
 |  Argumenty:                                                                |
 |      this - pierwszy skladnik mnozenia (wektor),                           |
 |      v - drugi skladnik mnozenia (liczba typu double).                     |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
 |      na parametr.                                                          |
 */

template<typename TYPE, unsigned int SIZE>
Vector<TYPE, SIZE> Vector<TYPE, SIZE>::operator * (const TYPE &mul) {
    Vector result;
    for (unsigned int i = 0; i < SIZE; ++i) {
        result[i] = coor[i] *= mul;
    }
    return result;
}


/******************************************************************************
 |  Realizuje dzielenie dwoch wektorow.                                       |
 |  Argumenty:                                                                |
 |      this - licznik dzielenia,                                             |
 |      v - mianownik dzielenia.                                              |
 |  Zwraca:                                                                   |
 |      Iloraz dwoch skladnikow przekazanych jako wskaznik                    |
 |      na parametr.                                                          |
 */

template<typename TYPE, unsigned int SIZE>
Vector<TYPE, SIZE> Vector<TYPE, SIZE>::operator / (const TYPE &div) {
    Vector result;

    for (unsigned int i = 0; i < SIZE; ++i) {
        result[i] = coor[i] / div;
    }

    return result;
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy jako stala.                   |
 */
template<typename TYPE, unsigned int SIZE>
const double &Vector<TYPE, SIZE>::operator [] (unsigned int index) const {
    if (index < 0 || index >= SIZE) {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
    } // lepiej byłoby rzucić wyjątkiem stdexcept
    return coor[index];
}


/******************************************************************************
 |  Funktor wektora.                                                          |
 |  Argumenty:                                                                |
 |      index - index wektora.                                                |
 |  Zwraca:                                                                   |
 |      Wartosc wektora w danym miejscu tablicy.                              |
 */
template<typename TYPE, unsigned int SIZE>
double &Vector<TYPE, SIZE>::operator[](unsigned int index) {
    return const_cast<double &>(const_cast<const Vector *>(this)->operator[](index));
}


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      tmp - wektor.                                                         |
 */
template<typename TYPE, unsigned int SIZE>
std::ostream &operator << (std::ostream &out, Vector<TYPE, SIZE> const &tmp) {
    for (unsigned int i = 0; i < SIZE; ++i) {
        out << "[ " << tmp[i] << " ]\n";
    }
    return out;
}


/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      tmp - wektor.                                                         |
 */
template<typename TYPE, unsigned int SIZE>
std::istream &operator >> (std::istream &in, Vector<TYPE, SIZE> &tmp) {
    for (unsigned int i = 0; i < SIZE; ++i) {
        in >> tmp[i];
    }
    std::cout << std::endl;
    return in;
}

template<typename TYPE, unsigned int SIZE>
bool operator ==(const Vector<TYPE, SIZE> &v1, const Vector<TYPE, SIZE> &v2)
{
    for(unsigned int i = 0; i < SIZE; ++i) {
        if(fabs(v1[i] - v2[i]) > epsilon)
        {return false;}
    }
    return true;
}


template<typename TYPE, unsigned int SIZE>
bool operator ==(const Vector<TYPE, SIZE> &v1, const double tmp[SIZE])
{
    for(unsigned int i = 0; i < SIZE; ++i) {
        if(fabs(v1[i] - tmp[i]) > epsilon)
        {return false;}
    }
    return true;
}