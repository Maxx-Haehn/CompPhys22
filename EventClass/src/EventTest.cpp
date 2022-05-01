/*
Darius Rushaj

Test code for event class
*/

#include"TROOT.h"
#include"TFile.h"
#include"TTree.h"
#include"event.h"
#include"particle.h"
#include"ParticleSystem.h"
#include "ctime"

int main()
{
	TFile f("EventTest.root","recreate");
	TTree T("TreeName","Particle Decay Tree");

	event ev(0);
	T.Branch("EventBranchName", &ev);

	srand(time(NULL));	

	for (int i = 0; i < 2; ++i)
	{
		particle Lambda("Lambda"), Proton("Proton"), Pion("Pion");
		ParticleSystem* LambdaSystem = new ParticleSystem(Lambda, Proton, Pion);
		LambdaSystem->ParticleDecay(5);
		ev.AddSystem(LambdaSystem);
		//std::cout<<"Progress: "<<(i+1)*2<<"%"<<std::endl;
	}

	for (int i = 0; i < 2; ++i)
	{
		ev.GetTrack(i)->Print();
	}

	T.Fill();
	f.cd();
	T.Write();
	T.Print();
	f.Close();

	return 0;
}
