/*
Vorobyev Dmitriy | st140149@student.spbu.ru
Assignment 5
*/


#ifndef MATRIX_H
#define MATRIX_H


#include <vector>
#include <stdexcept>


template <typename T>
class Matrix
{
public:
    Matrix() : rows_(0), columns_(0) {}
    Matrix(std::size_t rows, std::size_t columns, const T& value = T{}) : rows_(rows), columns_(columns), data_(rows * columns, value) {}

    T& operator()(std::size_t i, std::size_t j)
    {
        return data_.at(index(i, j));
    }

    const T& operator()(std::size_t i, std::size_t j) const
    {
        return data_.at(index(i, j));
    }

    Matrix operator+(const Matrix& second_operand) const
    {
        if (rows_ != second_operand.rows_ || columns_ != second_operand.columns_)
        {
            throw std::invalid_argument("Err: matrices must be the same size");
        }
        Matrix result(rows_, columns_);
        for (std::size_t i = 0; i < data_.size(); ++i)
        {
            result.data_[i] = data_[i] + second_operand.data_[i];
        }
        return result;
    }

    Matrix operator*(const Matrix& second_operand) const
    {
        if (columns_ != second_operand.rows_)
        {
            throw std::invalid_argument("Err: M1 columns number must be equal to M2 rows number");
        }
        Matrix result(rows_, second_operand.columns_);
        for (std::size_t i = 0; i < rows_; ++i)
        {
            for (std::size_t j = 0; j < second_operand.columns_; ++j)
            {
                for (std::size_t k = 0; k < columns_; ++k)
                {
                    result(i, j) = result(i, j) + (*this)(i, k) * second_operand(k, j);
                }
            }
        }
        return result;
    }

    Matrix operator*(const T& scalar) const
    {
        Matrix result(rows_, columns_);
        for (std::size_t i = 0; i < data_.size(); ++i)
        {
            result.data_[i] = data_[i] * scalar;
        }
        return result;
    }

    Matrix Transpose()
    {
        Matrix result(columns_, rows_);
        for (std::size_t i = 0; i < rows_; ++i)
        {
            for (std::size_t j = 0; j < columns_; ++j)
            {
                result(j, i) = (*this)(i, j);
            }
        }
        return result;
    }

private:
    std::size_t rows_;
    std::size_t columns_;
    std::vector<T> data_;

    std::size_t index(std::size_t i, std::size_t j) const
    {
        return i * columns_ + j;
    }

};




#endif