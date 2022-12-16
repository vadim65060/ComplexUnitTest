#ifndef COMPLEXUNITTEST_COMPLEX_H
#define COMPLEXUNITTEST_COMPLEX_H

#include <iostream>
#include <cmath>

class Complex {
public:
    Complex(double _re = 0, double _im = 0) : re(_re), im(_im) {};

    double Re() const { return re; }

    double Im() const { return im; }

    const double &get_Re() const { return re; }

    const double &get_Im() const { return im; }

    Complex MultIm(double value) const { return {-im * value, re * value}; }

    Complex DivIm(double value) const {
        if (value != 0)
            return {im / value, -re / value};
        else return {0, 0};
    }

    Complex AddIm(double value) const { return {re, im + value}; }

    Complex SubIm(double value) const { return {re, im - value}; }

    Complex &PAddIm(double value) {
        im += value;
        return *this;
    }

    Complex &PSubIm(double value) {
        im -= value;
        return *this;
    }

    double Module() const { return sqrt(re * re + im * im); }

    double SqModule() const { return re * re + im * im; }

    Complex Co() const { return {re, -im}; }

    Complex Swap() const { return {im, re}; }

    Complex &operator=(const Complex &complex) = default;

    Complex operator+(double value) const
    {
        return {re + value, im};
    }

    Complex &operator+=(double value)
    {
        re += value;
        return *this;
    }

    Complex &operator-=(double value) {
        re -= value;
        return *this;
    }

    Complex operator-(double value) const {
        return {re - value, im};
    }

    friend Complex operator-(double value, Complex complex) {
        return {value - complex.re, -complex.im};
    }

    friend Complex operator*(double value, Complex complex) {
        return {complex.re * value, complex.im * value};
    }

    Complex operator*(double value) const {
        return {re * value, im * value};
    }

    Complex &operator*=(double value) {
        re *= value;
        im *= value;
        return *this;
    }

    Complex &operator*=(const Complex &complex) {
        double temp = re;
        re = re * complex.re - im * complex.im;
        im = temp * complex.im + im * complex.re;
        return *this;
    }

    Complex operator/(double value) const {
        if (value != 0) return {re / value, im / value};
        else return {re / 0.0, im / 0.0};
    }

    Complex &operator/=(double value) {
        if (value != 0) {
            re /= value;
            im /= value;
            return *this;
        } else {
            re = re / 0.0;
            im = im / 0.0;
            return *this;
        }
    }

    Complex &operator/=(Complex &complex) {
        Complex tempNum = (*this) * complex.Co();
        const double reTemp = complex.Module() * complex.Module();
        re = tempNum.Re() / reTemp;
        im = tempNum.Im() / reTemp;
        return *this;
    }

    Complex operator*(Complex complex) const
    {
        return {complex.re * this->re - this->im * complex.im, complex.re * this->im + this->re * complex.im};
    }

    friend Complex operator+(double value, Complex complex)
    {
        return {value + complex.re, complex.im};
    }

    friend std::ostream &operator<<(std::ostream &stream, Complex complex)
    {
        stream << "(" << complex.re << ", " << complex.im << ")";
        return stream;
    }

    friend std::istream &operator>>(std::istream &stream, Complex &complex)
    {
        stream >> complex.re >> complex.im;
        return stream;
    }

    Complex operator-(Complex complex) const
    {
        return {this->re - complex.re, this->im - complex.im};
    }

    bool operator==(Complex &complex) const
    {
        if (complex.re == this->re && complex.im == this->im) return true;
        return false;
    }

    bool operator!=(Complex &complex) const
    {
        if (complex.re != this->re || complex.im != this->im) return true;
        return false;
    }

    Complex operator/(Complex &complex) const {
        double sq = complex.SqModule();
        return {(this->re * complex.re + this->im * complex.im) / sq,
                (this->im * complex.re - this->re * complex.im) / sq};
    }

    friend Complex operator/(double value, Complex &complex) {
        Complex c1(value, 0);
        return c1 / complex;
    }

    Complex &operator+=(const Complex &c)
    {
        re += c.re;
        im += c.im;
        return *this;
    }

    Complex &operator-=(const Complex &c) {
        re -= c.re;
        im -= c.im;
        return *this;
    }

    Complex operator+(const Complex &c) const
    {
        return {re + c.re, im + c.im};
    }

    Complex &operator+() {
        return *this;
    }

    Complex &operator-() {
        re = -re;
        im = -im;
        return *this;
    }

private:
    double re, im;
};

#endif //COMPLEXUNITTEST_COMPLEX_H
