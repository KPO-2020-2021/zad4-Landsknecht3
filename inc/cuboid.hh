#pragma once

#include <iomanip>
#include "size.hh"
#include "matrix3x3.hh"
#include "vector3D.hh"


class Cuboid
{   
    private:
        Vector3D cub[APICES];
        friend std::ostream &operator <<(std::ostream &out, Cuboid const &c);
    public:
        Cuboid();
        Cuboid(Vector3D v[APICES]);
        Cuboid rotation(char axis, double degr);
        Cuboid translation(Vector3D v);
        const Vector3D &operator[](unsigned int index) const;
        void sides();
        void sides_show(double arr[12]);

};

Cuboid::Cuboid()
{   
    Vector3D v;
    for(unsigned int i = 0; i < APICES; ++i)
    {
        cub[i] = v;
    }
}


Cuboid::Cuboid(Vector3D v[APICES])
{
    for(unsigned int i = 0; i < APICES; ++i)
    {
        cub[i] = v[i];
    }
}

Cuboid Cuboid::rotation(char axis, double degr)
{   
    Cuboid result;
    Matrix3x3 m(axis, degr);
    for(unsigned int i = 0; i < APICES; ++i)
    {
        result.cub[i] = m * cub[i]; 
    }
    return result;
}

Cuboid Cuboid::translation(Vector3D v)
{
    Cuboid result;
    for(unsigned int i = 0; i < APICES; ++i)
    {
        result.cub[i] = cub[i] + v;
    }
    return result;
}

const Vector3D &Cuboid::operator[](unsigned int index) const
{
    if(index >= APICES){
        std::cerr << "ERROR: Wektor jest poza zasiegiem!" << std::endl;}
    return cub[index];
}

std::ostream &operator <<(std::ostream &out, Cuboid const &c)
{   
    for(unsigned int i = 0; i < APICES; ++i)
    {
        for(unsigned int j = 0; j < 3; ++j)
        {
            out << std::setw(16) << std::fixed << std::setprecision(10) << c.cub[i][j];
            if(j == 2){out << std:: endl;}
        }
    }
    return out;
}

void Cuboid::sides()
{
    double arr[12];
    for(unsigned int i = 0; i < 3; ++i)
        {arr[i] = cub[i].length(cub[i+1]);}
    arr[3] = cub[3].length(cub[0]);
    for(unsigned int i = 4; i < 7; ++i)
        {arr[i] = cub[i].length(cub[i+1]);}
    arr[7] = cub[7].length(cub[4]);
    for(unsigned int i = 0; i < 4; ++i)
        {arr[i+8] = cub[i].length(cub[i+4]);}
    sides_show(arr);
}
void Cuboid::sides_show(double arr[12])
{
    if(arr[0] < arr[1])
    {
        if(arr[0] - arr[2] < epsilon && arr[0] - arr[4] < epsilon && arr[0] - arr[6] < epsilon)
        {
            std::cout << "Krotsze przeciwlegle boki sa sobie rowne\n"
            << std::setw(16) << std::fixed << std::setprecision(10) << arr[0] << "\n" <<std::setw(16)
            << arr[2] << "\n" <<std::setw(16) << arr[4] << "\n" << std::setw(16) << arr[6] << std::endl;
        }
        else
        {
            std::cout << "Krotsze przeciwlegle boki nie sa sobie rowne!!!" << std::endl
            << std::setw(16) << std::fixed << std::setprecision(10) << arr[0] << "\n" <<std::setw(16)
            << arr[2] << "\n" << std::setw(16) << arr[4] << "\n" << std::setw(16) << arr[6] << std::endl;
        }
        if(arr[1] - arr[3] < epsilon && arr[1] - arr[5] < epsilon && arr[1] - arr[7] < epsilon)
        {
            std::cout << "Dluzsze przeciwlegle boki sa sobie rowne\n"
            << std::setw(16) << std::fixed << std::setprecision(10) << arr[1] << "\n" << std::setw(16)
            << arr[3] << "\n" << std::setw(16) << arr[5] << "\n" << std::setw(16) << arr[7] << std::endl;
        }
        else
        {
            std::cout << "Dluzsze przeciwlegle boki nie sa sobie rowne!!!" << std::endl
            << std::setw(16) << std::fixed << std::setprecision(10) << arr[1] << "\n" << std::setw(16)
            << arr[3] << "\n" << std::setw(16) << arr[5] << "\n" << std::setw(16) << arr[7] << std::endl;
        }
    }
    else
    {   
        if(arr[1] - arr[3] < epsilon && arr[1] - arr[5] < epsilon && arr[1] - arr[7] < epsilon)
        {
            std::cout << "Krotsze przeciwlegle boki sa sobie rowne\n"
            << std::setw(16) << std::fixed << std::setprecision(10) << arr[1] << "\n" << std::setw(16)
            << arr[3] << "\n" << std::setw(16) << arr[5] << "\n" << std::setw(16) << arr[7] << std::endl;
        }
        else
        {
            std::cout << "Krotsze przeciwlegle boki nie sa sobie rowne!!!" << std::endl
            << std::setw(16) << std::fixed << std::setprecision(10) << arr[1] << "\n" << std::setw(16)
            << arr[3] << "\n" << std::setw(16) << arr[5] << "\n" << std::setw(16) << arr[7] << std::endl;
        }
        if(arr[0] - arr[2] < epsilon && arr[0] - arr[4] < epsilon && arr[0] - arr[6] < epsilon)
        {
            std::cout << "Dluzsze przeciwlegle boki sa sobie rowne\n"
            << std::setw(16) << std::fixed << std::setprecision(10) << arr[0] << "\n" << std::setw(16)
            << arr[2] << "\n" << std::setw(16) << arr[4] << "\n" << std::setw(16) << arr[6] << std::endl;
        }
        else
        {
            std::cout << "Dluzsze przeciwlegle boki nie sa sobie rowne!!!" << std::endl
            << std::setw(16) << std::fixed << std::setprecision(10) << arr[0] << "\n" << std::setw(16)
            << arr[2] << "\n" << std::setw(16) << arr[4] << "\n" << std::setw(16) << arr[6] << std::endl;
        }
    }
    if(arr[8] - arr[9] < epsilon && arr[8] - arr[10] < epsilon && arr[8] - arr[11] < epsilon)
        {
            std::cout << "Przeciwlegle boki sa sobie rowne\n"
            << std::setw(16) << std::fixed << std::setprecision(10) << arr[8] << "\n" << std::setw(16)
            << arr[9] << "\n" << std::setw(16) << arr[10] << "\n" << std::setw(16) << arr[11] << std::endl;
        }
        else
        {
            std::cout << "Przeciwlegle boki nie sa sobie rowne!!!" << std::endl
            << std::setw(16) << std::fixed << std::setprecision(10) << arr[8] << "\n" << std::setw(16)
            << arr[9] << "\n" << std::setw(16) << arr[10] << "\n" << std::setw(16) << arr[11] << std::endl;
        }
}
bool operator ==(const Cuboid &c1, const Cuboid &c2)
{
    for(unsigned int i =0; i < APICES; ++i)
    {
        if(c1[i] == c2[i]){}
        else{return false;}
    }
    return true;
}
