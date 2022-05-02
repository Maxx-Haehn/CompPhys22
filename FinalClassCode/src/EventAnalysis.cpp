/*
Darius Rushaj

Testing reading the TTree of EventTest
*/

#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "particle.h"
#include "ParticleSystem.h"
#include "event.h"

int main()
{
	TFile* f = new TFile("EventTest.root", "READ");
	TTree* T = (TTree*) f->Get("TreeName");

	event* ev = 0;
	T->SetBranchAddress("EventBranchName", &ev);

	T->GetEntry(0);

	ev->Print(); //I'm pretty sure this is where the code crashes.
}
