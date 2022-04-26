/*
Darius Rushaj

Test file for particle class.
*/

#include"particle.h"
#include"TLorentzVector.h"

int main()
{
	particle p("string");
	particle p2;
	//p.Print();
	
	p.SetName("Name");
	//p.Print();
	
	TLorentzVector v(1,2,3,4);
	p.SetLVec(v);
	//p.Print();
	
	p.SetX1(3.4);
	p.SetX2(4.3);
	p.SetX3(2.78);
	p.SetX4(99.999);
	p.Print();
	
	std::cout<<p.GetName()<<std::endl;
	p.GetLVec().Print();
	std::cout<<p.GetX1()<<", "<<p.GetX2()<<", "<<p.GetX3()<<", "<<p.GetX4()<<", "<<std::endl;
	
	TLorentzVector* w;
	std::cout<<std::endl;
	std::cout<<"Using LVec Pointer:"<<std::endl;
	LorentzView(w, p);
	std::cout<<"Printing LVec Pointer:"<<std::endl;
	w->Print();
	std::cout<<"Printing Particle:"<<std::endl;
	
	w->SetX(0);
	std::cout<<"Printing LVec Ptr After Changing Component of Pointer:"<<std::endl;
	w->Print();
	std::cout<<"Now, Printing the Particle:"<<std::endl;
	p.Print();
	std::cout<<"Changing the LVec through the pointer changes the particle LVec!!!"<<std::endl;
	
	std::cout<<"Particle before operating on LVec Through pointer:"<<std::endl;
	p2.Print();
	
	TLorentzVector* z;
	LorentzView(z, p2);
	*z+=*w;
	
	std::cout<<std::endl;
	std::cout<<"Using operations on the LVecs (LVec Ptr):"<<std::endl;
	z->Print();
	std::cout<<"Particle after LVec Ptr operation:"<<std::endl;
	p2.Print();
	
	return 0;
}
