#include "Header.h"
#include "MusicAlbum.h"
#include "Sonata.h"
#include "Cellist.h"

template<typename T = int>
T NormalSymbols(MusicAlbum music_album)
{
	int album_size = music_album.GetSize();
	T normal_count = 0;

	for (int i = 0; i < album_size; i++)
	{
		normal_count += (T)music_album[i].GetMusic().GetName().length();
	}

	return normal_count /= album_size;
}

template<typename T>
T NormalDuration(MusicAlbum music_album)
{
	int album_size = music_album.GetSize();
	T normal_count = 0;

	for (int i = 0; i < album_size; i++)
	{
		normal_count += (T)music_album[i].GetDurationInSecnods();
	}

	return normal_count /= album_size;
}

int main()
{
	MusicAlbum album(10);
	Date date(1, 1, 1);
	Person person("Name", "Surname", date);
	Sonata sonata("Name", "Some text");
	Music music(person, "Shit", &sonata, "opus", date);
	Cellist cellist("Some text");
	Performer performer(person, &cellist);

	MusicalRecording recording(music, performer, 1900);
	album.AddMusicalRecording(recording);
	album.AddMusicalRecording(recording);
	album.AddMusicalRecording(recording);
	album.AddMusicalRecording(recording);
	album.AddMusicalRecording(recording);
	album.AddMusicalRecording(recording);
	album.AddMusicalRecording(recording);
	album.AddMusicalRecording(recording);
	album.AddMusicalRecording(recording);
	album.AddMusicalRecording(recording);
	album.AddMusicalRecording(recording);
	album.AddMusicalRecording(recording);
	album.AddMusicalRecording(recording);
	album.AddMusicalRecording(recording);

	album.Print();
	cout << NormalSymbols<float>(album) << endl;
	cout << NormalDuration<double>(album) << endl;

	return 0;
}