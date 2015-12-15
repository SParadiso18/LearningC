//Preprocessing directive used for system header files
#include <iostream>
#include <string>
#include <fstream>

//Makes header files idempotent
//Defines a token once the file has been included
//Checking that the defined token was not already at the top of file
#ifndef __M_C
#define __M_C

//Preprocessing directive used for programmer defined header files
#include "matrix.h"

//Constructos
//-----------

//Default constructor
template<typename T>
Matrix<T>::Matrix(unsigned int nrow, unsigned int ncol, const T& basic)
{

    unsigned int i = 0;
   
    //Resize vector
    mat.resize(nrow);
    for (i = 0; i < mat.size(); i++)
    {
        //Resize columns for each row and initialize
        //elements to defined variable 'basic'
        mat[i].resize(ncol, basic);
    }

    r = nrow;
    c = ncol;
}

//Copy constructor
template<typename T> Matrix<T>::Matrix(const Matrix<T>& res)
{
    //Setting fields
    mat = res.mat;
    r = res.get_rows();
    c = res.get_cols();
}

//Destructor
template<typename T> Matrix<T>::~Matrix(){}


//Accessors
//---------

//Discrete element access
template<typename T>
T& Matrix<T>::operator() (const unsigned int &row, const unsigned int &col)
{
    return this->mat[row][col];
}

//Discrete element access (const version)
template<typename T>
const T& Matrix<T>::operator() (const unsigned int &row, const unsigned int &col) const
{
    return this->mat[row][col];
}

//Acquire number of rows
template<typename T>
unsigned int Matrix<T>::get_rows() const
{
    return this->r;
}

//Acquire number of columns
template<typename T>
unsigned int Matrix<T>::get_cols() const
{
    return this->c;
}


//Overloading
//-----------

//Assignment operator
template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& res)
{
    unsigned int i = 0;
    unsigned int j = 0;

    //Assign values to newly created rows and columns
    unsigned int nnrow = res.get_rows();
    unsigned int nncol = res.get_cols();

    //Returns itself in the case of redundancy
    if(&res == this)
    return *this;

    //Resizing to proper row count
    mat.resize(nnrow);

    //Resizing rows to proper column count
    for (i = 0; i < mat.size(); i++)
    {
        mat[i].resize(nncol);
    }

    //Element by element assignment
    for (i = 0; i < nnrow; i++)
    {
        for (j = 0; j < nncol; j++)
        {
            mat[i][j] = res(i, j);
        }
    }

    r = nnrow;
    c = nncol;

    //Returns the reworked matrix object
    return *this;
}

//Matrix addition
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& res)
{
    unsigned int i = 0;
    unsigned int j = 0;

    //New matrix initialized to 0
    Matrix rd(r, c, 0.0);

    //Actaul elemental addition process
    for (i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            rd(i, j) = this->mat[i][j] + res(i, j);
        }
    }

    return rd;
}

//Print matrix template
template<typename T>
void Matrix<T>::r_print()
{
    int i = 0;
    int j = 0;

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            std::cout << this->mat[i][j] << " , ";
        }
    std::cout << std::endl;
    }
}

//Matrix multiplication
template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& res) const
{
    int i = 0;
    int j = 0;
    int k = 0;

    unsigned int resr = res.get_rows();
    unsigned int resc = res.get_cols();
    unsigned int sum = 0;

    //New matrix initialized to 0
    Matrix rd(r, c, 0.0);

    //Actaul elemental multiplication row by column process
    if(r == resc)
    {
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < resc; j++)
            {
                sum = 0;
                for ( k = 0; k < resr; k++)
                {
                    sum += (mat[i][k] * res(k, j));
                }
            rd(i, j) = sum;
            }
        }
    return rd;
    }
    else
    {
        std::cout << "ERROR! Matrix Dimensions Don't Match!" << std::endl;
    }
}

//Scalar multiplication
template<typename T>
Matrix<T> Matrix<T>::operator*(T scal)
{
    int i = 0;
    int j = 0;

    //New matrix initialized to 0
    Matrix scalres(r, c, 0.0);

    //Actaul elemental scalar multiplication row by column process
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scalres(i, j) = this->mat[i][j] * scal;
        }
    }

    return scalres;
}

//Matrix piecewise addition
template<typename T>
Matrix<T> Matrix<T>::addbyp(const Matrix<T>& rand)
{
    int i = 0;
    int j = 0;

    int rs = rand.get_rows();
    int cs = rand.get_cols();

    //New matrix initialized to 0
    Matrix abp(r, c, 0.0);

    //Actaul elemental by element addition process
    if (r == rs && c == cs)
    {
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                abp(i, j) = this->(mat[i][j] + rand(i, j));
            }
        }

        return abp;
    }
    else
    {
        std::cout << "ERROR! Matrix Dimensions Don't Match!" << std::endl;
    }
}

//Matrix subtraction
template<typename T>
Matrix<T> Matrix<T>::operator-(Matrix<T>& res)
{
    int rs = res.get_rows();
    int cs = res.get_cols();

    //New matrix initialized to 0
    Matrix subres(r, c, 0.0);

    //Actaul subtraction process
    if (rs == r && cs == c)
    {
        subres = *this + res* (T)(-1);

        return subres;
    }
    else
    {
        std::cout << "ERROR! Matrix Dimensions Don't Match!" << std::endl;
    }
}

//Save as a file
template<typename T>
void Matrix<T>::save(char* file)
{
    std::ofstream out;
    out.open(file);
    this->r_print();

    out.close();
}

#endif
