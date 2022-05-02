/*
Darius Rushaj

Class for the particle system.
*/

#ifndef ROOT_particlesystem
#define ROOT_particlesystem

#include"TROOT.h"
#include"TObject.h"
#include"TBuffer.h"
#include"TLorentzVector.h"
#include<string>
#include<iostream>
#include"particle.h"

class ParticleSystem : public TObject
{
protected:
	particle parent_particle;			//Particles
	particle daughter_particle1;
	particle daughter_particle2;

public:
	//Constructors:
	ParticleSystem();
	ParticleSystem(particle& parent, particle& daughter1, particle& daughter2); //creates particle system with given particles.

	//Destructor:
	virtual ~ParticleSystem();

	//Setters:
	void SetParentParticle(particle& parent);						//Sets parent oarticle
	void SetDaughterParticle1(particle& daughter1);					//Sets first daughter particle
	void SetDaughterParticle2(particle& daughter2);					//Sets second daughter particle.
	void Test(double x);

	//Getters:
	particle GetParentParticle() {return parent_particle;}			//Returns a copy of the parent particle
	particle GetDaughterParticle1() {return daughter_particle1;}	//Returns a copy of the first daughter partcle
	particle GetDaughterParticle2() {return daughter_particle2;}	//Returns a copy of the second daughter particle

	//Member Functions:
	virtual void Print();
	
	void ParticleDecay(double initial_parent_momentum);				//MC simulation of particle decay: Original code by Dan.
};

#endif //ROOT_particlesystem
