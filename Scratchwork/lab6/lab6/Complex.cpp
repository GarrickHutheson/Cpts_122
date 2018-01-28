#pragma once
#include <iostream>

class Complex {
public:
	Complex() { //default Constructor
		this->real = 0;
		this->img = 0;
		}
	Complex(int real, int img) { //Overloaded Constructor
		this->real = real;
		this->img = img;
	}
	Complex(const Complex & copy) { //Copy Constructor
		this->real = copy.real;
		this->img = copy.img;
	}
	~Complex() {//Destructor

	}

	Complex& operator=(const Complex &rhs) {
		set_real(rhs.get_real());
		set_img(rhs.get_img());

		return *this;
	}

	

	//GETTERS
	int get_real() const {
		return real;
	}
	int get_img() const {
		return img;
	}

	//SETTERS
	void set_real(const int r) {
		real = r;
	}
	void set_img(const int i) {
		img = i;
	}

	Complex add(const Complex & rhs) {
		Complex result;
		result.real = this->real + rhs.real;
		result.img = this->img + rhs.img;
		return result;
	}

private:
	int real = 0;
	int img = 0;
};

Complex operator+(const Complex &lhs, const Complex &rhs) {
	Complex result;

	result.set_real(lhs.get_real() + rhs.get_real());
	result.set_img(lhs.get_img() + rhs.get_img());

	return result;
}

Complex operator-(const Complex &lhs, const Complex &rhs) {
	Complex result;

	result.set_real(lhs.get_real() - rhs.get_real());
	result.set_img(lhs.get_img() - rhs.get_img());

	return result;
}

std::ostream& operator<< (std::ostream &lhs, const Complex &rhs) {
	return lhs << rhs.get_real() << " + " << rhs.get_img() << "i,";
	//return lhs;
}

std::istream& operator>> (std::istream &lhs, Complex &rhs) {
	int real, int img;
	lhs >> real >> img;
	rhs.set_real(real);
	rhs.set_img(img);
	return lhs;
}


Complex add(const Complex& lhs, const Complex & rhs) {
	Complex result;

	result.set_real(lhs.get_real() + rhs.get_real());
	result.set_img(lhs.get_img() + rhs.get_img());

	return result;
}