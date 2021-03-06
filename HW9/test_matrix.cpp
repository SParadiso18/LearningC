#include<iostream>
#include "matrix.h"

int main()
{
  // Variable declaration and definition
    int i = 0;
    int j = 0;

    Matrix<long double> m1(3, 3, 3.0);
    Matrix<long double> m2(3, 3, 1.0);

    m1(1,2) = 6.0;
    m2(9,8) = 4.0;

    // Matrix manipulation
    Matrix<long double> m3 = m1 + m2;
    Matrix<long double> m4 = m1 * m2;
    Matrix<long double> m5 = m1.addbyp(m2);
    Matrix<long double> m6 = m1 * 2;
    Matrix<long double> m7 = m1 - m2;

    // Get the number of rows and columns of each created matrix
    int m1r = m1.get_rows();
    int m1c = m1.get_cols();

    int m2r = m2.get_rows();
    int m2c = m2.get_cols();

    int m3r = m3.get_rows();
    int m3c = m3.get_cols();

    int m4r = m4.get_rows();
    int m4c = m4.get_cols();

    int m5r = m5.get_rows();
    int m5c = m5.get_cols();

    int m6r = m6.get_rows();
    int m6c = m6.get_cols();

    int m7r = m7.get_rows();
    int m7c = m7.get_cols();

    // Calculating, printing output, and saving of matrix addition
    std::cout << "Matrix Addition: " << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    for(i = 0; i < m3r; i++)
    {
        for(j = 0; j < m3c; j++)
        {
            std::cout << m3(i, j) << ", ";
        }

        std::cout << std::endl;
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Printing Addition Matrix: " << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    m3.r_print();

    std::cout << std::endl;
    std::cout << std::endl;

    m3.save("add.csv");

    // Calculating, printing output, and saving of matrix multiplication
    std::cout << "Matrix Multiplication: " << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    for(i = 0; i < m4r; i++)
    {
        for(j = 0; j < m4c; j++)
        {
            std::cout << m4(i, j) << ", ";
        }

        std::cout << std::endl;
        std::cout << std::endl;
    }
   
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Printing Multiplication Matrix: " << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    m4.r_print();

    std::cout << std::endl;
    std::cout << std::endl;

    m4.save("mult.csv");

    // Calculating, printing output, and saving of matrix 
    // addition element by element
    std::cout << "Element Wise Matrix Addition: " << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    m5.r_print();

    std::cout << std::endl;
    std::cout << std::endl;

    m5.save("ea.csv");

    // Calculating, printing output, and saving of scalar multiplication
    std::cout << "Scalar Matrix Multiplication: " << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    m6.r_print();

    std::cout << std::endl;
    std::cout << std::endl;

    m6.save("sm.csv");

    // Calculating, printing output, and saving of matrix subtraction
    std::cout << "Matrix Subtraction: " << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    m7.r_print();

    std::cout << std::endl;
    std::cout << std::endl;

    m7.save("sub.csv");

    return 0;
}
