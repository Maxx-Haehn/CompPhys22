/*
Darius Rushaj

Event class header file.
*/

#ifndef ROOT_event
#define ROOT_event

#include"particle.h"
#include"ParticleSystem.h"

#include"TObject.h"
#include"TBuffer.h"
#include"TObjArray.h"

//Definition of class:
class event : public TObject
{
protected:
	int event_Number;
	TObjArray* system_Array;

public:
	//Constructors:
	event(); 			//Default
	event(int nEvent);  //Specifies which event

	//Destructor:
	virtual ~event();

	//Setter:
	void SetEventNumber(int nEvent) {event_Number = nEvent;}

	//Getters:
	int GetEventNumber() {return event_Number;}
	int GetNumberOfTracks() {return (int) system_Array->GetEntries();}
	ParticleSystem* GetTrack(int TrackNum) {return (ParticleSystem*) system_Array->At(TrackNum);};

	//Member Functions:
	void AddSystem(ParticleSystem* mp) {system_Array->AddLast(mp);}
	virtual void Print();
};

#endif //ROOT_event
