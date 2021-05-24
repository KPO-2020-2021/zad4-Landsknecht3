#pragma once

#include "size.hh"
#include "vector.hh"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

template< unsigned int SIZE>
class Matrix {

private:
    double value[SIZE][SIZE];               // Wartosci macierzy

public:
    Matrix(double [SIZE][SIZE]);            // Konstruktor klasy

    Matrix();                               // Konstruktor klasy

    Matrix(double degr);

    Matrix(char axis, double degr);

    Vector<SIZE> operator * (Vector<SIZE> tmp);           // Operator mnożenia przez wektor

    Matrix operator + (Matrix tmp);

    Matrix operator *(Matrix tmp);

    double  &operator () (unsigned int row, unsigned int column);
    
    const double &operator () (unsigned int row, unsigned int column) const;
};



/******************************************************************************
 |  Konstruktor klasy Matrix.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 */
template< unsigned int SIZE>
Matrix< SIZE>::Matrix() {
    for (unsigned int i = 0; i < SIZE; ++i) {
        for (unsigned int j = 0; j < SIZE; ++j) {
            value[i][j] = 0;
        }
    }
}


/******************************************************************************
 |  Konstruktor parametryczny klasy Matrix.                                   |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                  |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */
template< unsigned int SIZE>
Matrix< SIZE>::Matrix(double tmp[SIZE][SIZE]) {
    for (unsigned int i = 0; i < SIZE; ++i) {
        for (unsigned int j = 0; j < SIZE; ++j) {
            value[i][j] = tmp[i][j];
        }
    }
}


template< unsigned int SIZE>
Matrix< SIZE>::Matrix(double degr)
{   
    if(SIZE != 2)
    { std::cerr << "Uzyto nielasciwego konstruktora macierzy obrotu. Wymiary macierzy nie odpowiadaja temu konstruktorowi"; exit(0);}
    value[0][0]= cos(degr*PID); value[0][1]= -sin(degr*PID);
    value[1][0]= sin(degr*PID); value[1][1]= cos(degr*PID);
}


template< unsigned int SIZE>
Matrix< SIZE>::Matrix(char axis, double degr)
{   
    if(SIZE != 3)
    {std::cerr << "Uzyto nielasciwego konstruktora macierzy obrotu. Wymiary macierzy nie odpowiadaja temu konstruktorowi"; exit(0);}
    switch (axis)
    {
    case 'x':
        value[0][0] = 1; value[0][1] = 0;             value[0][2] = 0;
        value[1][0] = 0; value[1][1] = cos(degr*PID); value[1][2] = -sin(degr*PID);
        value[2][0] = 0; value[2][1] = sin(degr*PID); value[2][2] = cos(degr*PID);
        break;
    case 'y':
        value[0][0] = cos(degr*PID);  value[0][1] = 0;  value[0][2] = sin(degr*PID);
        value[1][0] = 0;              value[1][1] = 1;  value[1][2] = 0;
        value[2][0] = -sin(degr*PID); value[2][1] = 0;  value[2][2] = cos(degr*PID);
        break;
    case 'z':
        value[0][0] = cos(degr*PID); value[0][1] = -sin(degr*PID); value[0][2] = 0;
        value[1][0] = sin(degr*PID); value[1][1] = cos(degr*PID);  value[1][2] = 0;
        value[2][0] = 0;             value[2][1] = 0;              value[2][2] = 1;
        break;
    default:
    std::cerr << "Podano niepoprawny znak"; exit(0);
        break;
    }
}


/******************************************************************************
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */
template< unsigned int SIZE>
Vector<SIZE> Matrix< SIZE>::operator * (Vector< SIZE> tmp) {
    Vector<SIZE> result;
    for (unsigned int i = 0; i < SIZE; ++i) {
        for (unsigned int j = 0; j < SIZE; ++j) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;
}


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
template< unsigned int SIZE>
double &Matrix<SIZE>::operator()(unsigned int row, unsigned int column) {

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem"; 
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */
template< unsigned int SIZE>
const double &Matrix<SIZE>::operator () (unsigned int row, unsigned int column) const {

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}

/******************************************************************************
 |  Przeciążenie dodawania macierzy                                                          |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                     |
 |      v - wektor, czyli drugi skladnik dodawania.                                               |
 |  Zwraca:                                                                   |
 |      Macierz - iloczyn dwóch podanych macierzy.                  |
 */
template< unsigned int SIZE>
Matrix<SIZE> Matrix< SIZE>::operator + (Matrix tmp) {
    Matrix result;
    for (unsigned int i = 0; i < SIZE; ++i) {
        for (unsigned int j = 0; j < SIZE; ++j) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}

template< unsigned int SIZE>
Matrix< SIZE> Matrix< SIZE>::operator *(Matrix tmp)
{  
    Matrix result;
    for(unsigned int i = 0; i < SIZE; ++i){
        for(unsigned int j = 0; j < SIZE; ++j){
            for(unsigned int k = 0; k < SIZE; ++k){
                result.value[i][j] += this->value[i][k] * tmp.value[k][j]; 
            }
        }
    }

}

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      mat - macierz.                                                         |
 */
template< unsigned int SIZE>
std::istream &operator>>(std::istream &in, Matrix<SIZE> &mat) {
    for (unsigned int i = 0; i < SIZE; ++i) {
        for (unsigned int j = 0; j < SIZE; ++j) {
            in >> mat(i, j);
        }
    }
    return in;
}


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      mat - macierz.                                                        |
 */
template< unsigned int SIZE>
std::ostream &operator<<(std::ostream &out, const Matrix<SIZE> &mat) {
    for (unsigned int i = 0; i < SIZE; ++i) {
        for (unsigned int j = 0; j < SIZE; ++j) {
            out << "| " << std::fixed << std::setprecision(10) << mat(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}


template< unsigned int SIZE>
bool operator ==(const Matrix< SIZE> &m1, const Matrix< SIZE> &m2)
{   
    for(unsigned int i = 0; i < SIZE; i++)
    {
        for(unsigned int j = 0; j < SIZE; j++)
        {
            if(m1(i, j) - m2(i, j) > epsilon){return false;}
        }
    }
    return true;
}



template< unsigned int SIZE>
bool operator ==(const Matrix< SIZE> &m1, const double m2[SIZE][SIZE])
{
    for(unsigned int i = 0; i < SIZE; i++)
    {
        for(unsigned int j = 0; j < SIZE; j++)
        {
            if(m1(i, j) - m2[i][j] > epsilon){return false;}
        }
    }
    return true;
}
