/*
Darius Rushaj

Test code for event class and TTree creation
*/

#include"TROOT.h"
#include"TFile.h"
#include"TTree.h"
#include"event.h"
#include"particle.h"
#include"ParticleSystem.h"

int main()
{
	event* ev = new event(0);
	particle Lambda("Lambda"), Proton("Proton"), Pion("Pion");

	TFile* f = new TFile("EventTest.Root","recreate");
	TTree* t1 = new TTree("event","Particle Decay Tree");

	t1->Branch("Event", &ev);

	for (int i = 0; i < 50; ++i)
	{
		ParticleSystem* System = new ParticleSystem(Lambda, Proton, Pion); //Deleting these after causes a crash.
		System->ParticleDecay(5);
		ev->AddSystem(System);
		//System->Print();
		std::cout<<"Progress: "<<(double) (i+1)/(50.0)*100.0<<"% "<<std::endl;
	}

	t1->Fill();
	delete ev;

	t1->Write();
	f->Write();
	f->Close();

	return 0;
}
