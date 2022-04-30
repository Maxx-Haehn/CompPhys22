#include <iostream>
#include <fstream>
#include <cmath>

double ProtonP[1000][4]={0}, PionP[1000][4]={0}, mp[1000]={0}, mpi[1000]={0}, im[1000]={0}, dummy=0;

int nData=0;

int InvariantMass(){

  TCanvas c1;


  // This part is to save the x,y and z momentums of the  Proton and Pion particles per event
  fstream Momentumxyz ("DataFiles/Momentumxyz.txt");
  Momentumxyz.ignore(250, '\n');
  do{
    Momentumxyz >> dummy;
    Momentumxyz >> dummy;
    Momentumxyz >> dummy;
    Momentumxyz >> ProtonP[nData][1];
    Momentumxyz >> ProtonP[nData][2];
    Momentumxyz >> ProtonP[nData][3];
    Momentumxyz >> PionP[nData][1];
    Momentumxyz >> PionP[nData][2];
    Momentumxyz >> PionP[nData][3];
    nData++;
  }while(nData<1000);
  Momentumxyz.close();

  nData=0;
  
  // This part is to save the energy of the Proton and Pion partciles per event
  fstream EnergyandMomentum ("DataFiles/EnergyandMomentum.txt");
  EnergyandMomentum.ignore(250, '\n');
  do{
    EnergyandMomentum >> dummy;
    EnergyandMomentum >> dummy;
    EnergyandMomentum >> ProtonP[nData][0];
    EnergyandMomentum >> dummy;
    EnergyandMomentum >> PionP[nData][0];
    EnergyandMomentum >> dummy;
    nData++;
  }while(nData<1000);
  EnergyandMomentum.close(); //Close the file


  // This part is to calculate the proton, pion and the invariant mass per event
  for(int i=1; i<nData; i++){
    mp[i] = sqrt(pow(ProtonP[i][0],2) - (pow(ProtonP[i][1],2) +pow(ProtonP[i][2],2) + pow(ProtonP[i][3],2)));
    mpi[i] = sqrt(pow(PionP[i][0],2) - (pow(PionP[i][1],2) +pow(PionP[i][2],2) + pow(PionP[i][3],2)));
    im[i]= sqrt(pow(mp[i],2) + pow(mpi[i],2) + (2*ProtonP[i][0]*PionP[i][0]) - 2*(ProtonP[i][1]*PionP[i][1] + ProtonP[i][2]*PionP[i][2] + ProtonP[i][3]*PionP[i][3]));
  }

  // Here we create a 1D histogram
  TH1D* InvMass = new TH1D("Invariant Mass", "Invariant mass per event", 100, 1.1, 1.13);
  InvMass->SetStats(0);
  InvMass->GetXaxis()->SetTitle("Invariant Mass (GeV)");
  InvMass->GetYaxis()->SetTitle("Events");

  // We fill the 1D histogram with the invariant mass
  for(int i=1; i<nData; i++){
    InvMass->Fill(im[i]);
  }
  
  // Create and save the graphs
  InvMass->Draw("P*");
  c1.SaveAs("Results/InvariantMass.pdf");
  
  delete InvMass;

return 0;
}
