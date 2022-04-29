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

particle::particle(std::string name, TLorentzVector v)
{
	particle_name = name;
	particle_LVec = v;
}

particle::particle(std::string name, double x, double y, double z, double t)
{
	particle_name = name;
	particle_LVec.SetX(x);
	particle_LVec.SetY(y);
	particle_LVec.SetZ(z);
	particle_LVec.SetT(t);
}

//Destructor:

particle::~particle()
{
	std::cout<<"particle: Deconstructor Called!"<<std::endl;
}

//Operators:
void particle::operator= (const particle& p)
{
	particle_name = p.particle_name;
	particle_LVec = p.particle_LVec;
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

void particle::SetMass(double mass) //Sets mass
{
	particle_mass = mass;
}

void particle::SetPhi(double phi)		//Sets azimuthal angle
{
	particle_phi = phi;
}

void particle::SetTheta(double theta)	//Sets polar angle.
{
	particle_theta = theta;
}

void particle::SetXYZT(double x, double y, double z, double t)
{
	particle_LVec.SetX(x); particle_LVec.SetY(y); particle_LVec.SetZ(z); particle_LVec.SetT(t);
}

//Getters:

std::string particle::GetName()	//Returns the name of the particle
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

double particle::GetMass()					//Gets the mass
{
	return particle_mass;
}

double particle::GetPhi()					//Returns the azimuthal angle
{
	return particle_phi;
}

double particle::GetTheta()					//Returns the polar angle.
{
	return particle_theta;
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
