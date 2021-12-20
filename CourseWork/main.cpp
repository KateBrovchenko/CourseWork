#include "Header.h"
#include "MusicAlbum.h"
#include "Sonata.h"
#include "Cellist.h"



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
	cout << album.NormalSymbols() << endl;
	cout << album.NormalDuration() << endl;

	return 0;
}