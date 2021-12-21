#pragma once
#include "Music.h"
#include "Performer.h"

class MusicalRecording
{
private:
	Music _music;
	Performer _performer;
	int _duration_in_seconds;
	string _duration;
public:
	MusicalRecording();
	MusicalRecording(Music music, Performer performer, int duration);

	Music GetMusic();
	Performer GetPerformer();
	int GetDurationInSecnods();
	string GetDuration();

	void SetMusic(Music music);
	void SetPerformer(Performer performer);
	void SetDurationInSeconds(int duration);

	string DurationToString();

	MusicalRecording& operator=(const MusicalRecording& musical_recording);
};

