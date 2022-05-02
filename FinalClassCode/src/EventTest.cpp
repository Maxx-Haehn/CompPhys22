/*
Darius Rushaj

Test code for event class. Trying to make a TTree.
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
	TFile* f = new TFile("EventTest.root","recreate");
	TTree* T = new TTree("TreeName","Particle Decay Tree");

	event* ev = event(0);
	T->Branch("EventBranchName", &ev);

	for (int i = 0; i < 2; ++i)
	{
		particle Lambda("Lambda"), Proton("Proton"), Pion("Pion");
		ParticleSystem* LambdaSystem = new ParticleSystem(Lambda, Proton, Pion);
		LambdaSystem->ParticleDecay(5);
		ev->AddSystem(LambdaSystem);
	}

	for (int i = 0; i < 2; ++i)
	{
		ev->GetTrack(i)->Print();
	}

	T->Fill();
	T.Write();
	T.Print();
	f.Close();

	return 0;
}
