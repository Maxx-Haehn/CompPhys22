/*
Darius Rushaj

Event class header file. Following example in the Lecture 10 pdf
*/

#ifndef ROOT_event
#define ROOT_event

#include"particle.h"
#include"ParticleSystem.h"

#include"TObject.h"
#include"TBuffer.h"
#include"TObjArray.h"

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
	void SetEventNumber(int nEvent) {event_Number = nEvent;} 									//Sets Number of event

	//Getters:
	int GetEventNumber() {return event_Number;}													//Returns event number
	int GetNumberOfTracks() {return (int) system_Array->GetEntries();}							//Returns number of tracks in event
	ParticleSystem* GetTrack(int TrackNum) {return (ParticleSystem*) system_Array->At(TrackNum);};//Returns track in TObjArray.

	//Member Functions:

	void AddSystem(ParticleSystem* mp) {system_Array->AddLast(mp);}		//Appends system to TObjArray.

	virtual void Print();
};

#endif //ROOT_event
