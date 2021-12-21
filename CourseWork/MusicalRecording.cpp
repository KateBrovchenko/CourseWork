#include "MusicalRecording.h"

MusicalRecording::MusicalRecording()
{
	_duration_in_seconds = 0;
}

MusicalRecording::MusicalRecording(Music music, Performer performer, int duration)
{
	_music = music;
	_performer = performer;
	SetDurationInSeconds(duration);
	_duration = DurationToString();
}

Music MusicalRecording::GetMusic()
{
	return _music;
}

Performer MusicalRecording::GetPerformer()
{
	return _performer;
}

int MusicalRecording::GetDurationInSecnods()
{
	return _duration_in_seconds;
}

string MusicalRecording::GetDuration()
{
	return _duration;
}

void MusicalRecording::SetMusic(Music music)
{
	_music = music;
}

void MusicalRecording::SetPerformer(Performer performer)
{
	_performer = performer;
}

void MusicalRecording::SetDurationInSeconds(int duration)
{
	if (duration > 0)
	{
		_duration_in_seconds = duration;
	}
	else
	{
		throw "Duration is equal or less 0!";
		exit(1);
	}
}

string MusicalRecording::DurationToString()
{
	int hours = 0;
	int minutes = _duration_in_seconds / 60;

	if (minutes >= 60)
	{
		hours = minutes / 60;
	}
	
	if (hours >= 1)
	{
		return _duration = to_string(hours) + ':' + to_string(minutes) + ':' + to_string(_duration_in_seconds - minutes * 60);
	}
	else
	{
		return _duration = to_string(minutes) + ':' + to_string(_duration_in_seconds - minutes * 60);
	}
}

MusicalRecording& MusicalRecording::operator=(const MusicalRecording& musical_recording)
{
	_music = musical_recording._music;
	_performer = musical_recording._performer;
	_duration_in_seconds = musical_recording._duration_in_seconds;
	_duration = musical_recording._duration;
	return *this;
}
