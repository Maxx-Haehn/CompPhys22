/*
Darius Rushaj

Particle class implementation.
*/

//#include<iostream>
#include"particle.h"
#include<cmath>

//ClassImp(particle) <-------------------Will be needed to implement as ROOT Class

//Constructors:

particle::particle() 									//Default constructor: No Name and Zero lorentz vector.
{
	particle_name = "No_Name";
}

particle::particle(std::string name)	//Constructed With a given name.
{
	particle_name = name;
}

//Destructor:

particle::~particle()
{
	std::cout<<"particle: Deconstructor Called!"<<std::endl;
}

//Setters:

void particle::SetName(std::string name)
{
	particle_name = name;
}

void particle::SetLVec(TLorentzVector v)
{
	particle_LVec = v;
}

void particle::SetX1(double x1) //Sets first component: x/Px componrent
{
	particle_LVec.SetX(x1);
}

void particle::SetX2(double x2)	//Sets second component: y/Py component. 
{
	particle_LVec.SetY(x2);
}

void particle::SetX3(double x3)	//Sets third component: z/Pz component.
{
	particle_LVec.SetZ(x3);
}

void particle::SetX4(double x4)	//Sets fourth component: t/E component.
{
	particle_LVec.SetT(x4);
}

//Getters:

std::string particle::GetName() 	//Returns the name of the particle
{
	return particle_name;
}

TLorentzVector particle::GetLVec()//Returns the Lorentz Vector of the particle
{
	return particle_LVec;
}

double particle::GetX1()					//Returns the first component of the Lorentz vector: x/Px component
{
	return particle_LVec.X();
}

double particle::GetX2()					//Returns the second component of the Lorentz vector: y/Py component
{
	return particle_LVec.Y();
}

double particle::GetX3()					//Returns the third component of the Lorentz vector: z/Pz component
{
	return particle_LVec.Z();
}

double particle::GetX4()					//Returns the fourth component of the Lorentz vector: t/E component
{
	return particle_LVec.T();
}

//Member Functions:
void particle::Print()						//Prints name of the particle and the Lorentz vector of the particle
{
	std::cout<<std::endl;
	std::cout<<"Particle Name: "<<particle_name<<std::endl;
	particle_LVec.Print();					//USing the TLorentzVector class print function.
	std::cout<<std::endl;
}

void LorentzView(TLorentzVector*& LVecPtr, particle& p)
{
	LVecPtr = &p.particle_LVec;
}
