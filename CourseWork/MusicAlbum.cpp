#include "MusicAlbum.h"

MusicalRecording* MusicAlbum::Recize()
{
	MusicalRecording* temp_array = new MusicalRecording[_size + 1];

	for (int i = 0; i < _size; i++)
	{
		temp_array[i] = _music_album[i];
	}
	
	delete[] _music_album;
	_size++;

	return temp_array;
}

MusicAlbum::MusicAlbum(int size)
{
	if (size > 0)
	{
		_size = size;
		_music_album = new MusicalRecording[_size];
		_filled_size = 0;
	}
	else
	{
		throw "Size is less or equal 0!";
		exit(1);
	}
}

MusicAlbum::MusicAlbum(const MusicAlbum& music_album)
{
	_size = music_album._size;

	_music_album = new MusicalRecording[_size];
	for (int i = 0; i < _size; i++)
	{
		_music_album[i] = music_album._music_album[i];
	}
	_filled_size = music_album._filled_size;
}

void MusicAlbum::AddMusicalRecording(MusicalRecording musical_recording)
{
	if (_filled_size == 0)
	{
		_music_album[0] = musical_recording;
		_filled_size++;
	}
	else if (_filled_size + 1 > _size)
	{
		_music_album = Recize();

		_music_album[_filled_size] = musical_recording;
		_filled_size++;
	}
	else
	{
		_music_album[_filled_size] = musical_recording;
		_filled_size++;
	}
}

void MusicAlbum::Print()
{
	for (int i = 0; i < _size; i++)
	{
		cout << _music_album[i].GetMusic().GetComposer().GetName() << endl;
	}
}

int MusicAlbum::GetSize()
{
	return _size;
}

int MusicAlbum::GetFilledSize()
{
	return _filled_size;
}

MusicalRecording& MusicAlbum::operator[](int index)
{
	return _music_album[index];
}

MusicAlbum& MusicAlbum::operator=(const MusicAlbum& album)
{
	_size = album._size;

	_music_album = new MusicalRecording[_size];
	for (int i = 0; i < _size; i++)
	{
		_music_album[i] = album._music_album[i];
	}
	_filled_size = album._filled_size;

	return *this;
}

MusicAlbum::~MusicAlbum()
{
	delete[] _music_album;
}
