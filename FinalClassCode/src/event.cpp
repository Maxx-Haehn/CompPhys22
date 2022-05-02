/*
Darius Rushaj

event Class implementation. Following example in lecture 10 pdf
*/

#include"event.h"
#include<iostream>

//Constructors:
event::event() //Default
{
	event_Number = -1;					//Event number = -1 for default.
	system_Array = new TObjArray();		//Empty TObjArray.
	system_Array->SetOwner(kTRUE);
}

event::event(int nEvent)
{
	event_Number = nEvent;				//Sets event number to nEvent
	system_Array = new TObjArray(50);	//Empty TObjArray with 50 free spaces.
	system_Array->SetOwner(kTRUE);
}

//Destructor
event::~event()
{
	system_Array->Delete();
	delete system_Array;
}

//Setters and Getters implemented in header file.

//Member Functions
//AddSystem defined inline
void event::Print()
{
	std::cout<<"Event Number = "<<event_Number<<std::endl; //Event number
	std::cout<<std::endl;
	for (int i = 0; i<GetNumberOfTracks(); ++i)				//Loops over tracks in event
	{	
		std::cout<<"Track Number = "<<i+1<<std::endl;		//Prints track number
		GetTrack(i)->Print(); 								//Prints particle system using print function from ParticleSystem class.
		std::cout<<std::endl;
	}
}
