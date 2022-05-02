/*
Darius Rushaj
Original particle decay function by Daniel Ricalde Herrmann.
Implementation of ParticleSystem class.
*/

#include"ParticleSystem.h"
#include"particle.h"
#include<iomanip>
#include<ctime>

//using namespace std;

//Constructors:
ParticleSystem::ParticleSystem() //Default: Lorentz vectors will all be zero and the particles will have default name.
{
	parent_particle.SetName("Parent");
	daughter_particle1.SetName("Daughter1");
	daughter_particle2.SetName("Daughter2");
}

ParticleSystem::ParticleSystem(particle& parent, particle& daughter1, particle& daughter2)
{
	parent_particle = parent;
	daughter_particle1 = daughter1;
	daughter_particle2 = daughter2;
}

//Deconstructor:
ParticleSystem::~ParticleSystem()
{
	//std::cout<<"ParticleSystem: Deconstructor Called"<<std::endl;
}

//Setters:
void ParticleSystem::SetParentParticle(particle& parent)
{
	parent_particle = parent;
}

void ParticleSystem::SetDaughterParticle1(particle& daughter1)
{
	daughter_particle1 = daughter1;
}

void ParticleSystem::SetDaughterParticle2(particle& daughter2)
{
	daughter_particle2 = daughter2;
}

//Getters: implemented in header file.

//Member Functions:
void ParticleSystem::Print()
{
	std::cout<<"Parent Particle:";
	parent_particle.Print();
	//std::cout<<std::endl;

	std::cout<<"Daughter Particle One:";
	daughter_particle1.Print();
	//std::cout<<std::endl;

	std::cout<<"Daughter Particle Two:";
	daughter_particle2.Print();
	//std::cout<<std::endl;
}

void ParticleSystem::ParticleDecay(double initial_parent_momentum) //MC function for system of particles.
{
//	matrixNd *ParticleM=new matrixNd(3,7); // Matrix that will store all the particles data
	using namespace std;
	srand(time(NULL));
	double Pl = initial_parent_momentum;

	//Left these values as they are, though we could, technically, use the particle class data to set them for each particle.
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
  	parent_particle.SetX4(El);			//ParticleM->SetValue(0,0,El);   Original code commented out.
  	//ParticleM->SetValue(0,1,Pl);
  	parent_particle.SetX1(Plx);			//ParticleM->SetValue(0,2,Plx);
  	parent_particle.SetX2(Ply);			//ParticleM->SetValue(0,3,Ply);
  	parent_particle.SetX3(Plz);			//ParticleM->SetValue(0,4,Plz);
  	parent_particle.SetTheta(thetal);	//ParticleM->SetValue(0,5,thetal);
  	parent_particle.SetPhi(phil);		//ParticleM->SetValue(0,6,phil);
 
  	//First daughter particle (proton in our case)
  	daughter_particle1.SetX4(Ep);		//ParticleM->SetValue(1,0,Ep);
  	//ParticleM->SetValue(1,1,Pp);
  	daughter_particle1.SetX1(Ppx);		//ParticleM->SetValue(1,2,Ppx);
  	daughter_particle1.SetX2(Ppy);		//ParticleM->SetValue(1,3,Ppy);
  	daughter_particle1.SetX3(Ppz);		//ParticleM->SetValue(1,4,Ppz);
  	daughter_particle1.SetTheta(thetap);//ParticleM->SetValue(1,5,thetap);
  	daughter_particle1.SetPhi(phip);	//ParticleM->SetValue(1,6,phip);
 
  	//Second daughter particle (pion in our case)
  	daughter_particle2.SetX4(Epi);		//ParticleM->SetValue(2,0,Epi);
  	//ParticleM->SetValue(2,1,Ppi);
  	daughter_particle2.SetX1(Ppix);		//ParticleM->SetValue(2,2,Ppix);
  	daughter_particle2.SetX2(Ppiy);		//ParticleM->SetValue(2,3,Ppiy);
  	daughter_particle2.SetX3(Ppiz);		//ParticleM->SetValue(2,4,Ppiz);
  	daughter_particle2.SetTheta(thetapi);//ParticleM->SetValue(2,5,thetapi);
  	daughter_particle2.SetPhi(phipi);	//ParticleM->SetValue(2,6,phipi);

  	// Return the Particle Matrix
  	//return ParticleM;
}
