/*
Darius Rushaj

Analysis for decay.
*/

#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "particle.h"
#include "ParticleSystem.h"
#include "event.h"

int main()
{
	TFile f("EventTest.root","READ");
	TTree* T = (TTree*) f.Get("TreeName");
	event* ev = 0;
	T->SetBranchAddress("EventBranchName", &ev);

	T->GetEntry(0);

	for (int i = 0; i < 2; ++i)
	{
		ev->GetTrack(i)->Print();
	}

	return 0;
}
