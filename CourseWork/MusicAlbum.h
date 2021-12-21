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
	MusicAlbum(const MusicAlbum& music_album);

	void AddMusicalRecording(MusicalRecording musical_recording);

	void Print();

	int GetSize();
	int GetFilledSize();

	MusicalRecording& operator[](int index);
	MusicAlbum& operator=(const MusicAlbum& album);

	~MusicAlbum();
};

