#include<iostream>
#include <string>
#include"vector.h"

using namespace std;
Vector::Vector() {
	this->capacity = 10;
	this->data = new int[capacity];
}

Vector::Vector(int capacity) {
	this->capacity = capacity;
	this->data = new int[capacity];
}

Vector::Vector(const Vector& v1) {
	this->capacity = v1.capacity;
	this->size = v1.size;
	this->data = new int[*(v1.data)];
}

Vector::Vector(Vector&& v1) {
	this->capacity = v1.capacity;
	this->size = v1.size;
	this->data = v1.data;
	v1.data = nullptr;
	v1.size = 0;
}

int Vector:: getCapacity()const {
	return capacity;
}

int Vector::getSize()const {
	return size;
}

Vector& Vector:: operator = (const Vector& v1) {
	if (this == &v1)
		return*this;
	this->capacity = v1.capacity;
	this->size = v1.size;
	if (data != v1.data) {
		delete [] data;
		data = new int[v1.capacity];
		for (int i = 0; i < v1.capacity; i++)
			this->data[i] = v1.data[i];
		
	}
	return *this;
}

Vector& Vector:: operator = (Vector&& v1) {
	this->capacity = v1.capacity;
	this->size = v1.size;
	this->data = v1.data;
	v1.data = nullptr;
}

ostream& operator << (ostream& out, Vector& v1) {
	out << "capacity: " << v1.capacity << "size: " << v1.size << "content: ";
	for (int i = 0; i < v1.size; i++) {
		out << v1.data[i] << endl;
	}
	return out;
}
////////
///////
bool Vector:: operator ==(Vector& v2) {
	if (this->size == v2.size) {
		for (int i = 0; i < this->size; i++) {
			if (this->data[i] != v2.data[i]) {
				return false;
			}

		}
		return true;
	}
	return false;
}

int& Vector::operator [](int i) {
	if ((i >= this->size) || (i < 0)) {
		throw "ERROR: the number is out of range:";
	}
	return this->data[i];
}

int& Vector::operator * (const Vector& v2) {
	int sum = 0;
	if (this->size == v2.size) {
		for (int i = 0; i < this->size; i++)
			sum += this->data[i] * v2.data[i];
	}
	else {
		throw "ERROR: the size of the array must be equal!";
	}
}

Vector* Vector:: operator + (const Vector& v2) {
	Vector* v3 = new Vector;
	v3->capacity = this->capacity + v2.capacity;
	v3->size = this->size + v2.size;

	for (int i = 0; i < this->size; i++)
		v3->data[i] = this->data[i];
	for (int j = this->size; j < v2.size; j++)
		v3->data[j] = v2.data[j];

	return v3;
}

void Vector::clear() {
	for (int i = 0; i < this->size; i++) 
		this->data[i] = 0;
	
	this->size = 0;
}

void Vector::delLast() {
	if (this->size > 0) {
		this->data[size] = 0;
		this->size--;
	}
	else
		throw "ERROR: array is empty: size = 0: ";
		
}
void Vector::insert(int val) {
	if (this->size !=this-> capacity)
		this->data[size] = val;
	else
		throw "ERROR: the array is full: capacity = " + to_string(capacity);
}