#include "src/matrixNd.h"
#include <iomanip>
#include <ctime>

matrixNd* ParticleMatrix(double Pl); 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main( ){
  time_t tt; 
  struct tm * ti;
  srand(time(NULL)); //Set the random seed

  time (&tt);
  ti = localtime(&tt);
  cout << "The program started on " << asctime(ti) << endl;

  double Pl=5; //Declare the initial momentum of the Lambda particle

  matrixNd *PartMatrix=new matrixNd(3,7); //Create a 3x7 Matrix to store all the data from the three particles (Lambda, Proton and Pion)
  
  ofstream angles;
  angles.open ("DataFiles/angles.txt");
  angles << std::fixed;
  
  ofstream Momentumxyz;
  Momentumxyz.open ("DataFiles/Momentumxyz.txt");
  Momentumxyz << std::fixed;
  
  ofstream EnergyandMomentum;
  EnergyandMomentum.open ("DataFiles/EnergyandMomentum.txt");
  EnergyandMomentum << std::fixed;

  angles <<"PhiL"<<"	"<<"ThetaL"<<"	"<<"PhiP"<<"	"<<"ThetaP"<<"	"<<"PhiPi"<<"	"<<"ThetaPi"<< endl;

  Momentumxyz <<"Plx"<<"	"<<"Ply"<<"	"<<"Plz"<<"	"<<"Ppx"<<"	"<<"Ppy"<<"	"<<"Ppz"<<"	"<<"Ppix"<<"	"<<"Ppiy"<<"	"<<"Ppiz"<< endl;

  EnergyandMomentum <<"El"<<"	"<<"Pl"<<"	"<<"Ep"<<"	"<<"Pp"<<"	"<<"Epi"<<"	"<<"Ppi"<< endl;
  
  for (int i=0; i<1000; i++){
  
    PartMatrix=ParticleMatrix(Pl); // Run the MC Particles function
  
    angles << std::setprecision(3) <<PartMatrix->GetValue(0,6)<< "   " <<PartMatrix->GetValue(0,5)<<"	"<<PartMatrix->GetValue(1,6)<< "   " <<PartMatrix->GetValue(1,5)<< "   " 
    <<PartMatrix->GetValue(2,6)<< "   " <<PartMatrix->GetValue(2,5)<< endl;
  
    Momentumxyz << std::setprecision(3) <<PartMatrix->GetValue(0,2)<<"	"<<PartMatrix->GetValue(0,3)<<"	"<<PartMatrix->GetValue(0,4)<<"	"
    <<PartMatrix->GetValue(1,2)<<"	"<<PartMatrix->GetValue(1,3)<<"	"<<PartMatrix->GetValue(1,4) <<"	"<<PartMatrix->GetValue(2,2)<<"	"
    <<PartMatrix->GetValue(2,3)<<"	"<<PartMatrix->GetValue(2,4)<< endl;

    EnergyandMomentum << std::setprecision(3) <<PartMatrix->GetValue(0,0)<<"	"<<PartMatrix->GetValue(0,1)<<"	"<<PartMatrix->GetValue(1,0)<<"	"
    <<PartMatrix->GetValue(1,1)<<"	"<<PartMatrix->GetValue(2,0)<<"	"<<PartMatrix->GetValue(2,1)<< endl;
    
    cout << i << "\r";

  }

  Momentumxyz.close();
  angles.close();
  EnergyandMomentum.close();

  delete PartMatrix; // Delete the Matrix to release memory	
  
  time (&tt);
  ti = localtime(&tt);
  cout << "The program finished on " << asctime(ti) << endl;
  
  return 0;				
}
////////////////////////////////////////////

matrixNd* ParticleMatrix(double Pl){ // MC function for Lambda, Proton and Pion

  matrixNd *ParticleM=new matrixNd(3,7); // Matrix that will store all the particles data

  double El=0, Ep=0, Epi=0, Pp=0, Ppi=0, mp=0.938272, mpi=0.13957, ml=1.115683, r=0, r1=0, r2=0, Plx=0, Ply=0, Plz=0, Ppx=0, Ppy=0, Ppz=0, Ppix=0, Ppiy=0, Ppiz=0, thetal=0, phil=0, thetap=0, phip=0, thetapi=0, phipi=0;

  double PlRange=0, AngleChange=0, PlCheck=0, AngleBin=100, AngleChangeSign=1, AngleBinSize=1;

  int count1=0, count2=0, count3=0, count4=0, PlChecknan=0, Plxnan=0, Plynan=0, Plznan=0, phipinan=0, thetapinan=0;    


  // This part of the code is to assign an initial dispersion angle on the x,y plane for the Lambda particle 
  // and use it to calculate the x and y components of the Lambda Momentum and the Lambda Energy
  r1=(double) rand() / (RAND_MAX);
  thetal = r1*(2.0*M_PI);
  Plx=Pl*cos(thetal);
  Ply=Pl*sin(thetal); 
  Plz=0;

  El=sqrt(pow(Pl,2)+pow(ml,2));

  // This part is to assign a fraction of the Lambda Energy to the Proton and Pion Energy (Conservation of Energy), 
  // then use it to calculate the Momentum Magnitude of the Proton and the Pion
  do{
    r=(double) rand() / (RAND_MAX);
    Ep = r*El;
    if ((Ep!=El) and (Ep!=0)) break;
  }while(true);

  Epi=El-Ep;

  Pp=sqrt(pow(Ep,2)-pow(mp,2));
  Ppi=sqrt(pow(Epi,2)-pow(mpi,2));

// This part will find the angles of dispersion for the Proton and the Pion
  do{
  
    // This is a safety measure. Basically if after 1,000,000 tries it can't find the angles then 
    // it selects a new dispersion angle for Lambda and re-asigns the Proton and Pion Energy
    count4++;
    if (count4%1000000==0){
      AngleBin=100, AngleChangeSign=1, AngleBinSize=1, count1=0, count2=0, count3=0, count4=0;

      r1=(double) rand() / (RAND_MAX);
      thetal = r1*(2.0*M_PI);
      Plx=Pl*cos(thetal);
      Ply=Pl*sin(thetal);
      Plz=0; 

      El=sqrt(pow(Pl,2)+pow(ml,2));

      do{
        r=(double) rand() / (RAND_MAX);
        Ep = r*El;
        if ((Ep!=El) and (Ep!=0)) break;
      }while(true);

      Epi=El-Ep;

      Pp=sqrt(pow(Ep,2)-pow(mp,2));
      Ppi=sqrt(pow(Epi,2)-pow(mpi,2)); 
    }
  
    // Selects random angles for the Proton dispersion
    r1=(double) rand() / (RAND_MAX);
    thetap = r1*M_PI;
  
    r2=(double) rand() / (RAND_MAX);
    phip = r2*2*M_PI;
    
    // Use the selected Proton angles to calculate the Pion angles of dispersion (using the given Lambda Momentum components)
    phipi=acos((Plz-Pp*cos(phip))/Ppi);
    thetapi=asin((Ply-Pp*sin(thetap)*sin(phip))/(Ppi*sin(phipi)));
    
    // Use the angles to calculate the x component of the Lambda Momentum (Conservation of momentum)
    Plx = Pp*cos(thetap)*sin(phip) + Ppi*cos(thetapi)*sin(phipi);
    
    // Calculate the difference between the given Lambda Momentum and the one calculated with the angles.
    PlRange=abs(Pl - sqrt(pow(Plx,2) + pow(Ply,2) + pow(Plz,2)));
  
    if (PlRange<0.001) { // Set an acceptance range for the difference of Lambda Momentums
      do{
        if ((count1>0) and (count1%100==0)){ // This is a safety measure to change the direction in wich we approach the Proton angles, 
          count3++;                          // also it changes the bin size to get closer to the "original" Proton angles
          if(count3%2==0) AngleBinSize++;
          AngleBin=AngleBinSize*100;
          AngleChangeSign*=-1;
        }
        AngleChange=1.0/AngleBin;
        thetap += AngleChange*M_PI*AngleChangeSign; // We change the Proton theta angle by a fraction of pi
        phip += AngleChange*2*M_PI*AngleChangeSign; // We change the Proton phi angle by a fraction of 2pi

        // Calculate the Pion angles using the new Proton angles
        phipi=acos((Plz-Pp*cos(phip))/Ppi);
        thetapi=asin((Ply-Pp*sin(thetap)*sin(phip))/(Ppi*sin(phipi)));

        // Calculate the Lambda Momentum with the new Proton and Pion angles
        Plx = Pp*cos(thetap)*sin(phip) + Ppi*cos(thetapi)*sin(phipi);
        Ply = Pp*sin(thetap)*sin(phip) + Ppi*sin(thetapi)*sin(phipi);
        Plz = Pp*cos(phip) + Ppi*cos(phipi);

        // Calculate the difference between the given Lambda Momentum and the one calculated with the new angles.
        PlCheck=abs(Pl - sqrt(pow(Plx,2) + pow(Ply,2) + pow(Plz,2)));
      
        // Safety check for "nan" values
        PlChecknan=isnan(PlCheck);
        Plxnan=isnan(Plx);
        Plynan=isnan(Ply);
        Plznan=isnan(Plz);
        phipinan=isnan(phipi);
        thetapinan=isnan(thetapi);
            
        // If the Lambda Momentum difference with the new Proton angles is bigger than the one with the "original" Proton angles or there is any "nan" value
        // We return to the previous Proton angles, increace the angle bin (or decrease the fraction of Pi and 2Pi we are summing/resting to the Proton angles)
        // increase the count1 (this means it failed to find better angles)
        if ((PlCheck>PlRange)or(PlChecknan==1)or(Plxnan==1)or(Plynan==1)or(Plznan==1)or(phipinan==1)or(thetapinan==1)) {
          thetap -= AngleChange*M_PI*AngleChangeSign;
          phip -= AngleChange*2*M_PI*AngleChangeSign;
          AngleBin+=0.1;
          count1++;
          
        // If the Lambda Momentum difference with the new Proton angles is smaller than the one with the "original" Proton angles and there is no "nan" value then
        // Now this Lambda Momentum difference is the new acceptance range
        // We reset the angle change bin to 100 to start again when trying to find the new Proton angles
        // increase the count2 (this means it found better angles) and reset count1 (the failure counter)
        // Since we are not returnint to the previous Proton angles, this angles will be now our new "original" Proton angles now.
        }else if ((PlCheck<PlRange)and(PlChecknan==0)and(Plxnan==0)and(Plynan==0)and(Plznan==0)and(phipinan==0)and(thetapinan==0)) {
          PlRange=PlCheck;
          AngleBin=100;
          AngleBinSize=1;
          count2++;
          count1=0;
        }
      
        if (count1==1000) break; // If after 1000 tries it can't find better Proton angles, we break the loop
        if (count2==10) break; // If we succed to find new angles 10 times we break the loop
      
      }while(true);
    
      // Reset the counters
      count1=0;
      count2=0;
      count3=0;
    
      // Use the last Proton angles to re-calculate the Pion angles and the Lambda, Proton and Pion Momentums.
      phipi=acos((Plz-Pp*cos(phip))/Ppi);
      thetapi=asin((Ply-Pp*sin(thetap)*sin(phip))/(Ppi*sin(phipi)));

      Ppx=Pp*cos(thetap)*sin(phip);
      Ppy=Pp*sin(thetap)*sin(phip);
      Ppz=Pp*cos(phip);
      
      Ppix=Ppi*cos(thetapi)*sin(phipi);
      Ppiy=Ppi*sin(thetapi)*sin(phipi);
      Ppiz=Ppi*cos(phipi);

      Plx = Pp*cos(thetap)*sin(phip) + Ppi*cos(thetapi)*sin(phipi);
      Ply = Pp*sin(thetap)*sin(phip) + Ppi*sin(thetapi)*sin(phipi);
      Plz = Pp*cos(phip) + Ppi*cos(phipi);
      
      // Check for "nan" values with the last Proton angles
      Plxnan=isnan(Plx);
      Plynan=isnan(Ply);
      Plznan=isnan(Plz);
      phipinan=isnan(phipi);
      thetapinan=isnan(thetapi);    
    
      // If the difference of the x and the y component of the given Lambda Moment (the initial one) and the one calculated with the Proton angles is within range, 
      // and there is no "nan" value, then we break the loop
      if ((abs(Plx-(Pl*cos(thetal)))<0.1) and (abs(Ply-(Pl*sin(thetal)))<0.1) and (Plxnan==0) and (Plynan==0) and (Plznan==0) and (phipinan==0) and (thetapinan==0)) break;
    }
  }while(true);

  // Save all the important values of every particle in the Matrix
  ParticleM->SetValue(0,0,El);
  ParticleM->SetValue(0,1,Pl);
  ParticleM->SetValue(0,2,Plx);
  ParticleM->SetValue(0,3,Ply);
  ParticleM->SetValue(0,4,Plz);
  ParticleM->SetValue(0,5,thetal);
  ParticleM->SetValue(0,6,phil);
  ParticleM->SetValue(1,0,Ep);
  ParticleM->SetValue(1,1,Pp);
  ParticleM->SetValue(1,2,Ppx);
  ParticleM->SetValue(1,3,Ppy);
  ParticleM->SetValue(1,4,Ppz);
  ParticleM->SetValue(1,5,thetap);
  ParticleM->SetValue(1,6,phip);
  ParticleM->SetValue(2,0,Epi);
  ParticleM->SetValue(2,1,Ppi);
  ParticleM->SetValue(2,2,Ppix);
  ParticleM->SetValue(2,3,Ppiy);
  ParticleM->SetValue(2,4,Ppiz);
  ParticleM->SetValue(2,5,thetapi);
  ParticleM->SetValue(2,6,phipi);

  // Return the Particle Matrix
  return ParticleM;
}
