#include "Audio_Interface.h"

Audio_Interface::Audio_Interface(void)
{

}

Audio_Interface::~Audio_Interface(void)
{

}

void Audio_Interface::Init()
{

	gSound = new AudioSystem(); //Set Com for sound in APP window

	int counter = 1;

	//////////////////////////////////////////////////////////////////////////
	// Initialize FMOD w/ FR wrapper
	//////////////////////////////////////////////////////////////////////////
	//Test sound by Paul
	FR(gSound->getSystem()->createSound("Laser.wav", FMOD_DEFAULT, 0, &Laser));
	FR(gSound->getSystem()->createSound("AutoFire.wav", FMOD_DEFAULT, 0, &AutoFire));
	FR(gSound->getSystem()->createSound("CannonFire.wav", FMOD_DEFAULT, 0, &CannonFire));
	FR(gSound->getSystem()->createSound("ButtonSelect.wav", FMOD_DEFAULT, 0, &ButtonSelect));


	//////////////////////////////////////////////////////////////////////////
	// Initialize DirectShow / directly add due to issues w/ wrapper HR
	//////////////////////////////////////////////////////////////////////////

	// Initialize COM
	CoInitialize(NULL);

}