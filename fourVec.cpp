/*
Darius Rushaj

fourVector Class implementation
*/

#include"fourVec.h"
#include<iostream>
#include<cmath>

using namespace std;

//Constructors:
fourVec::fourVec()	//Base constructor
{
	array = new double[dim];
}

fourVec::fourVec(const fourVec& V) //Copy constructor
{
	array = new double[dim];
	*this=V; //Used = operator defined below.
}

fourVec::fourVec(double ptx0, double ptx1, double ptx2, double ptx3) //All components specified.
{
	array = new double[dim];
	Set(0,ptx0); Set(1,ptx1); Set(2,ptx2); Set(3,ptx3);
}

fourVec::fourVec(double ptx0, double ar[3]) //First component is given and then the remaining three are given as an array.
{
	array = new double[dim];
	Set(0,ptx0);
	for(int i=1; i<4; i++)
	{
		Set(i,ar[i-1]);
	}
}

//Destructor:
fourVec::~fourVec()
{
	delete[] array;
	cout<<"fourVec: Deconstructor Called!"<<endl;
}

//Operators:
void fourVec::operator= (const fourVec& V)
{
	dim = V.dim;
	for(int i=0; i<dim; i++)
	{
		Set(i, V.Get(i));
	}
}

fourVec fourVec::operator+ (const fourVec& V)
{
	fourVec returnVec;
	returnVec.dim = V.dim;
	for(int i=0; i<dim; i++)
	{
		returnVec.Set(i, Get(i) + V.Get(i));
	}
	return returnVec;
}

void fourVec::operator+= (const fourVec& V)
{
	dim = V.dim;
	for(int i=0; i<dim; i++)
	{
		Set(i, Get(i)+V.Get(i));
	}
}

fourVec fourVec::operator- (const fourVec& V)
{
	fourVec returnVec;
	returnVec.dim = V.dim;
	for(int i=0; i<dim; i++)
	{
		returnVec.Set(i, Get(i) - V.Get(i));
	}
	return returnVec;
}

void fourVec::operator-= (const fourVec& V)
{
	dim = V.dim;
	for(int i=0; i<dim; i++)
	{
		Set(i, Get(i)-V.Get(i));
	}
}

fourVec fourVec::operator* (const double& scalar)
{
	fourVec returnVec;
	returnVec.dim = dim;
	for(int i=0; i<dim; i++)
	{
		returnVec.Set(i,(double) Get(i)*scalar);
	}
	return returnVec;
}

void fourVec::operator*= (const double& scalar)
{
	*this = *this*scalar;
}

fourVec operator* (const double& scalar, fourVec& V)
{
	return V*scalar;
}

fourVec fourVec::operator/ (const double& scalar)
{
	fourVec returnVec;
	returnVec.dim = dim;
	returnVec = *this*((double)1/scalar);
	return returnVec;
}

void fourVec::operator/= (const double& scalar)
{
	*this = *this*((double)1/scalar);
}

//Setter:
void fourVec::Set(int index, double value)
{
	array[index] = value;
}

//Getter:
double fourVec::Get(int index) const
{
	return array[index];
}

//Member Functions:
void fourVec::print()
{
	cout<<endl;
	for(int i=0; i<dim; i++)
	{
		cout<<"["<<Get(i)<<"]"<<endl;
	}
	cout<<endl;
}

double fourVec::Dot(const fourVec& V) //Using +--- metric.
{
	double dot = 0;
	dot+=Get(0)*V.Get(0);
	dot-= (Get(1)*V.Get(1) + Get(2)*V.Get(2) + Get(3)*V.Get(3));
	return dot;
}
