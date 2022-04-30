/*
Darius Rushaj

event Class implementation.
*/

#include"event.h"
#include<iostream>

//Constructors:
event::event() //Default
{
	event_Number = -1;
	system_Array = new TObjArray();
	system_Array->SetOwner(kTRUE);
}

event::event(int nEvent)
{
	event_Number = nEvent;
	system_Array = new TObjArray(50);
	system_Array->SetOwner(kTRUE);
}

//Destructor
event::~event()
{
	system_Array->Delete();
	delete system_Array;
}

//Setters and Getters defined inline.

//Member Functions
//AddSystem defined inline
void event::Print()
{
	std::cout<<"Event Number = "<<event_Number<<std::endl;
	std::cout<<std::endl;
	for (int i = 0; i<GetNumberOfTracks(); ++i)
	{	
		std::cout<<"Track Number = "<<i+1<<std::endl;
		GetTrack(i)->Print(); //Printing particle system
		std::cout<<std::endl;
	}
}
