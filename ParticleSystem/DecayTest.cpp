/*
Darius Rushaj

Testing ParticleSystem class.
*/

#include"particle.h"
#include"ParticleSystem.h"

int main()
{
	particle Lambda("Lambda"), Proton("Proton"), Pion("Pion");

	ParticleSystem LambdaDecaySystem(Lambda, Proton, Pion);

	LambdaDecaySystem.ParticleDecay(5); //Applying MC to system with initial lambada momentum of 5;

	Lambda.Print(); Proton.Print(); Pion.Print(); //Printing the particles themselves. Note: I used the TLorentzVector print function in the print function for my particle
												  //class, so there is a p, eta, phi, E vector as well.

	LambdaDecaySystem.Print();	//Using system print function. This is just for testing.

	std::cout<<"Proton Phi: "<<Proton.GetPhi()<<std::endl; //All angles and energies were also set.

	return 0;
}
