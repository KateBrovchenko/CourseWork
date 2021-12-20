#pragma once
#include "MusicalRecording.h"

class MusicAlbum
{
private:
	MusicalRecording* _music_album;
	int _size;
	int _filled_size;

	MusicalRecording* Recize();
public:
	MusicAlbum(int size);

	void AddMusicalRecording(MusicalRecording musical_recording);

	void Print();

	int GetSize();

	double NormalSymbols();
	double NormalDuration();

	MusicalRecording& operator[](int index);
	MusicAlbum& operator=(MusicAlbum album);

	~MusicAlbum();
};

