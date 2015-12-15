#ifndef __M_H
#define __M_H

#include<vector>

template<typename T> class Matrix
{
    // Access Modifiers
    //
    // Any class in this assignment can refer to this field or call this method
    private:
        std::vector<std::vector<T> > mat;

        unsigned int r;
        unsigned int c;

    // Any class in this assignment can refer to this field or call this method
    public:
        Matrix(unsigned int row, unsigned int col, const T& pri);
        Matrix(const Matrix<T> &res);

        virtual ~Matrix();

        Matrix<T>& operator=(const Matrix<T>& res);
        Matrix<T> operator+(const Matrix<T>& res);
        Matrix<T> operator*(const Matrix<T>& res);
        Matrix<T> operator*(T scal);

        T& operator()(const unsigned int &row, const unsigned int &col);

        const T& operator()(const unsigned int &row, unsigned int &col) const;

        void r_print();

        Matrix<T> addbyp(const Matrix<T>& rand1);

        Matrix<T> operator-(Matrix<T>& rand2);

        void save(char* filename);

        unsigned int get_rows() const;
        unsigned int get_cols() const;
};

#include "matrix.cpp"

#endif
