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
	LambdaDecaySystem.Print();

	return 0;
}
