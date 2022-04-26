/*
Darius Rushaj

particle class header file
*/

#ifndef ROOT_particle
#define ROOT_particle

#include"TROOT.h"
#include"TObject.h"
#include"TBuffer.h"
#include"TLorentzVector.h"
#include<string>
#include<iostream>

class particle : public TObject
{
	protected:
		std::string particle_name;			//Name of particle
		TLorentzVector particle_LVec;		//Lorentz Vector of particle
				
	public:
		//Constructors:
		particle(); 				 																								//Defualt
		particle(std::string name); 																				//Creates object with name and default lorentz vector
		particle(std::string name, TLorentzVector v);												//Give name and lorentz vector
		particle(std::string name, double x, double y, double z, double t); //Specify name and each component of Lorentz Vector.
		
		//Destructor:
		virtual ~particle();
		
		//Setters:
		void SetName(std::string name);	//Sets name
		void SetLVec(TLorentzVector v);	//Sets Lorentz vector
		void SetX1(double x1);					//Sets first component of Lorentz vec: x/Px component
		void SetX2(double x2);					//Sets 2nd comp: y/Py comp
		void SetX3(double x3);					//3rd comp: z/Pz comp
		void SetX4(double x4);					//4th comp: Time/Energy component
		
		//Getters:
		std::string GetName();					//Gets name
		TLorentzVector GetLVec();				//Gets Lorentz Vec
		double GetX1();									//Gets 1st component
		double GetX2();									//Gets 2nd comp
		double GetX3();									//Gets 3rd
		double GetX4();									//Gets 4th
		
		//Member Functions:
		void Print(); //Will print out name and Lorentz vector.
		friend void LorentzView(TLorentzVector*& LVecPtr, particle& p);
		
	//ClassDef(particle,1) <--------------------------------------------Will be needed to implement as ROOT class.

};

#endif //ROOT_particle
