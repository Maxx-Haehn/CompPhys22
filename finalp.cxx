#include <iostream>
#include <cmath>

using namespace std;

int main(){

srand(time(NULL)); 

double El=0, Ep=0, Epi=0, Pp=0, Ppi=0, Pl=0, mp=0.938272, mpi=0.13957, ml=1.115683, r=0, r1=0, r2=0, Plx=0, Ply=0, Plz=0, thetal=0, thetap=0, phip=0, thetapi=0, phipi=0;

double a=0, b=0, c=0, d=100, e=1, f=1;

int count1=0, count2=0, count3=0, count4=0, count5=0;

Pl=5;

r1=(double) rand() / (RAND_MAX);
thetal = r1*(M_PI/2.0);
Plx=Pl*cos(thetal);
Ply=Pl*sin(thetal); 

El=sqrt(pow(Pl,2)+pow(ml,2));

do{
  r=(double) rand() / (RAND_MAX);
  Ep = r*El;
  if ((Ep!=El) and (Ep!=0)) break;
}while(true);

Epi=El-Ep;

Pp=sqrt(pow(Ep,2)-pow(mp,2));
Ppi=sqrt(pow(Epi,2)-pow(mpi,2));

do{
  count4++;
  if (count4%1000000==0){
    
    El=0, Ep=0, Epi=0, Pp=0, Ppi=0, mp=0.938272, mpi=0.13957, ml=1.115683, r=0, r1=0, r2=0, Plx=0, Ply=0, Plz=0, thetal=0, thetap=0, phip=0, thetapi=0, phipi=0;
    a=0, b=0, c=0, d=100, e=1, f=1;
    count1=0, count2=0, count3=0;

    r1=(double) rand() / (RAND_MAX);
    thetal = r1*(M_PI/2.0);
    Plx=Pl*cos(thetal);
    Ply=Pl*sin(thetal); 

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
  
  r1=(double) rand() / (RAND_MAX);
  thetap = r1*M_PI;
  
  r2=(double) rand() / (RAND_MAX);
  phip = r2*2*M_PI;

  phipi=acos((Plz-Pp*cos(phip))/Ppi);
  thetapi=asin((Ply-Pp*sin(thetap)*sin(phip))/(Ppi*sin(phipi)));

  Plx = Pp*cos(thetap)*sin(phip) + Ppi*cos(thetapi)*sin(phipi);
  
  a=abs(Pl - sqrt(pow(Plx,2) + pow(Ply,2) + pow(Plz,2)));
  
  if (a<0.001) {
  
    do{
      count5++;
      if ((count1>0) and (count1%100==0)){
        count3++;
        if(count3%2==0) f++;
        d=f*100;
        e*=-1;
      }
      b=1.0/d;
      thetap += b*M_PI*e;
      phip += b*2*M_PI*e;

      phipi=acos((Plz-Pp*cos(phip))/Ppi);
      thetapi=asin((Ply-Pp*sin(thetap)*sin(phip))/(Ppi*sin(phipi)));

      Plx = Pp*cos(thetap)*sin(phip) + Ppi*cos(thetapi)*sin(phipi);
      Plz = Pp*cos(phip) + Ppi*cos(phipi);
      Ply = Pp*sin(thetap)*sin(phip) + Ppi*sin(thetapi)*sin(phipi);
  
      c=abs(Pl - sqrt(pow(Plx,2) + pow(Ply,2) + pow(Plz,2)));
            
      if ((c>a)or(isnan(c)==1)) {
        thetap -= b*M_PI*e;
        phip -= b*2*M_PI*e;
        d+=0.1;
        count1++;
      }else{
        a=c;
        d=100;
        count2++;
        count1=0;
      }
      
      if (count1==1000) break;
      if (count2==10) break;
      if (count5==1000000) break;
    }while(true);
    count5=0;
    if (count2==10) break;

    if ((abs(Plx-(Pl*cos(thetal)))<0.1) and (abs(Ply-(Pl*sin(thetal)))<0.1) and (Plz>=0) and (isnan(Plx)==0) and (isnan(Ply)==0) and (isnan(Plz)==0)) break;

    count1=0;
    count2=0;
    count3=0;
  }
}while(true);

cout << "Lambda Energy is " << El << " and Lambda momentum magnitude is " << Pl << endl;
cout << "Proton Energy is " << Ep << " and Proton momentum magnitude is " << Pp << endl;
cout << "Pion Energy is " << Epi << " and Pion momentum magnitude is " << Ppi << endl;
cout << " " << endl;

cout << "Proton theta is " << thetap << " and Proton phi is " << phip << endl;
cout << "Pion theta is " << thetapi << " and Pion phi is " << phipi << endl;
cout << " " << endl;

cout << "The Proton 4-vector is ("<< Ep << ", " << Pp*cos(thetap)*sin(phip) << ", " << Pp*sin(thetap)*sin(phip) << ", " << Pp*cos(phip) << ")" << endl;
cout << "And the momentum magnitude is " << sqrt(pow(Pp*cos(thetap)*sin(phip),2) + pow(Pp*sin(thetap)*sin(phip),2) + pow(Pp*cos(phip),2)) << endl;
cout << " " << endl;

cout << "The Pion 4-vector is ("<< Epi << ", "  << Ppi*cos(thetapi)*sin(phipi) << ", " << Ppi*sin(thetapi)*sin(phipi) << ", " << Ppi*cos(phipi) << ")" << endl;
cout << "And the momentum magnitude is " << sqrt(pow(Ppi*cos(thetapi)*sin(phipi),2) + pow(Ppi*sin(thetapi)*sin(phipi),2) + pow(Ppi*cos(phipi),2)) << endl;
cout << " " << endl;

cout << "The Lambda 4-vector is ("<< El << ", "  << Plx << ", " << Ply << ", " << Plz << ")" << endl;
cout << "And the momentum magnitude is " << sqrt(pow(Plx, 2) + pow(Ply, 2) + pow(Plz, 2)) << endl;
cout << " " << endl;

return 0;
}
