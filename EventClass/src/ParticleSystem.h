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
	ParticleSystem(particle& parent, particle& daughter1, particle& daughter2);

	//Destructor:
	virtual ~ParticleSystem();

	//Setters:
	void SetParentParticle(particle& parent);
	void SetDaughterParticle1(particle& daughter1);
	void SetDaughterParticle2(particle& daughter2);
	void Test(double x);

	//Getters:
	particle GetParentParticle() {return parent_particle;}
	particle GetDaughterParticle1() {return daughter_particle1;}
	particle GetDaughterParticle2() {return daughter_particle2;}

	//Member Functions:
	virtual void Print();
	void ParticleDecay(double initial_parent_momentum);
};

#endif //ROOT_particlesystem
