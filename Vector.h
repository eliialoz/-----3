#pragma once
#include<iostream>
#include<cstring>
using namespace std;

class Vector {
private:
	int* data = nullptr;
	int capacity;
	int size;
public:
	Vector();
	Vector(int capacity);
	Vector(const Vector& v1);
	Vector(Vector&& v1);
	
	Vector& operator =(const Vector& v1);
	Vector& operator =(Vector&& v1);

	~Vector() {
		delete data;
	}
	
	int getCapacity()const;
	
	int getSize()const;

	friend ostream& operator << (ostream& out, Vector& v1);
		
/*
	vector operator = (vector& v2) {
		vector(v2);
	}
	*/
	bool operator ==(Vector& v2);
		
	int& operator [](int i);

	int& operator * (const Vector& v2);

	Vector* operator + (const Vector& v2);
		
	void clear();
	void delLast();
	void insert(int val);
};
ostream& operator << (ostream& out, Vector& v1);


