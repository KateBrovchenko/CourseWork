#include "Header.h"
#include "HeaderClasses.h"
#include <locale.h>

template<typename T>
T NormalSymbols(MusicAlbum music_album)
{
	int album_size = music_album.GetFilledSize();
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
	int album_size = music_album.GetFilledSize();
	T normal_count = 0;

	for (int i = 0; i < album_size; i++)
	{
		normal_count += (T)music_album[i].GetDurationInSecnods();
	}

	return normal_count /= album_size;
}

vector<string> split(const string& s, char delim) {
	vector<string> result;
	stringstream ss(s);
	string item;

	while (getline(ss, item, delim)) {
		result.push_back(item);
	}

	return result;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	ofstream out;
	ifstream in("file.txt");
	ofstream bin_out("file_bin.bin",ios::binary | ios::out);
	ifstream bin_in("file.bin", ios::binary | ios::in);

	int size = 0;
	string composer_date_of_birth;
	string composer_name;
	string composer_surname;
	string composer_date_of_creation;
	string musical_composition_type_name;
	string musical_composition_type_text;
	string music_name;
	string music_opus;
	string harmonist_text;
	string person_date_of_birth;
	string person_name;
	string person_surname;
	int duration_in_seconds;

	vector<string> spliters;

	MusicAlbum album(8);
	Date date(1, 1, 1);
	Person composer;
	Person person;
	Sonata sonata;
	Symphony symphony;
	Concert concert;
	Divertissement divertissement;
	Cellist cellist;
	Conductor conductor;
	Pianist pianist;
	Violinist violonist;

	Music music;
	Performer performer;

	MusicalRecording recording;

	if (in.is_open())
	{
		while (in >> composer_date_of_birth >> composer_name >> composer_surname >> composer_date_of_creation >> musical_composition_type_name >> musical_composition_type_text >> music_name >> music_opus >> harmonist_text >> person_date_of_birth >> person_name >> person_surname >> duration_in_seconds)
		{
			composer.SetName(composer_name);
			composer.SetSurname(composer_surname);
			spliters = split(composer_date_of_birth, '.');
			composer.SetDateOfBirth(stoi(spliters[0]), stoi(spliters[1]), stoi(spliters[2]));

			music.SetComposer(composer);
			spliters = split(composer_date_of_creation, '.');
			music.SetDateOfCreation(stoi(spliters[0]), stoi(spliters[1]), stoi(spliters[2]));
			if (musical_composition_type_name == "Sonata")
			{
				sonata.SetName(musical_composition_type_name);
				sonata.SetText(musical_composition_type_text);
				music.SetMusicalCompositionType(&sonata);
			}
			else if (musical_composition_type_name == "Symphony")
			{
				symphony.SetName(musical_composition_type_name);
				symphony.SetText(musical_composition_type_text);
				music.SetMusicalCompositionType(&symphony);
			}
			else if (musical_composition_type_name == "Concert")
			{
				concert.SetName(musical_composition_type_name);
				concert.SetText(musical_composition_type_text);
				music.SetMusicalCompositionType(&concert);
			}
			else if (musical_composition_type_name == "Divertissement")
			{
				divertissement.SetName(musical_composition_type_name);
				divertissement.SetText(musical_composition_type_text);
				music.SetMusicalCompositionType(&divertissement);
			}
			music.SetName(music_name);
			music.SetOpus(music_opus);

			recording.SetMusic(music);
			spliters = split(person_date_of_birth, '.');
			person.SetDateOfBirth(stoi(spliters[0]), stoi(spliters[1]), stoi(spliters[2]));
			person.SetName(person_name);
			person.SetSurname(person_surname);

			performer.SetPerson(person);
			if (harmonist_text == "Cellist")
			{
				cellist.SetText(harmonist_text);
				performer.SetHarmonist(&cellist);
			}
			else if (harmonist_text == "Conductor")
			{
				conductor.SetText(harmonist_text);
				performer.SetHarmonist(&conductor);
			}
			else if (harmonist_text == "Pianist")
			{
				pianist.SetText(harmonist_text);
				performer.SetHarmonist(&pianist);
			}
			else if (harmonist_text == "Violonist")
			{
				violonist.SetText(harmonist_text);
				performer.SetHarmonist(&violonist);
			}

			recording.SetPerformer(performer);
			recording.SetDurationInSeconds(duration_in_seconds);
			album.AddMusicalRecording(recording);
		}
	}
	in.close();
	
	size = album.GetFilledSize();
	for (int i = 0; i < size; i++)
	{
		bin_out.write((char*)album[i].GetMusic().GetComposer().GetDateOfBirth().c_str(), sizeof(album[i].GetMusic().GetComposer().GetDateOfBirth()));
		bin_out.write((char*)album[i].GetMusic().GetComposer().GetName().c_str(), sizeof(album[i].GetMusic().GetComposer().GetName()));
		bin_out.write((char*)album[i].GetMusic().GetComposer().GetSurname().c_str(), sizeof(album[i].GetMusic().GetComposer().GetSurname()));
		bin_out.write((char*)album[i].GetMusic().GetDateOfCreation().ToString().c_str(), sizeof(album[i].GetMusic().GetDateOfCreation().ToString()));
		bin_out.write((char*)album[i].GetMusic().GetMusicalCompositionType()->GetName().c_str(), sizeof(album[i].GetMusic().GetMusicalCompositionType()->GetName()));
		bin_out.write((char*)album[i].GetMusic().GetMusicalCompositionType()->GetText().c_str(), sizeof(album[i].GetMusic().GetMusicalCompositionType()->GetText()));
		bin_out.write((char*)album[i].GetMusic().GetName().c_str(), sizeof(album[i].GetMusic().GetName()));
		bin_out.write((char*)album[i].GetMusic().GetOpus().c_str(), sizeof(album[i].GetMusic().GetOpus()));
		bin_out.write((char*)album[i].GetPerformer().GetHarmonist()->GetText().c_str(), sizeof(album[i].GetPerformer().GetHarmonist()->GetText()));
		bin_out.write((char*)album[i].GetPerformer().GetPerson().GetDateOfBirth().c_str(), sizeof(album[i].GetPerformer().GetPerson().GetDateOfBirth()));
		bin_out.write((char*)album[i].GetPerformer().GetPerson().GetName().c_str(), sizeof(album[i].GetPerformer().GetPerson().GetName()));
		bin_out.write((char*)album[i].GetPerformer().GetPerson().GetSurname().c_str(), sizeof(album[i].GetPerformer().GetPerson().GetSurname()));
		duration_in_seconds = album[i].GetDurationInSecnods();
		bin_out.write((char*)&duration_in_seconds, sizeof(duration_in_seconds));
	}
	bin_out.close();

	

	while(bin_in.eof() == true)
	{
		bin_in.read((char*)composer_date_of_birth.c_str(), sizeof(composer_date_of_birth));
		bin_in.read((char*)composer_name.c_str(), sizeof(composer_name));
		bin_in.read((char*)composer_surname.c_str(), sizeof(composer_surname));

		spliters = split(composer_date_of_birth, '.');
		composer.SetDateOfBirth(stoi(spliters[0]), stoi(spliters[1]), stoi(spliters[2]));
		composer.SetName(composer_name);
		composer.SetSurname(composer_surname);

		bin_in.read((char*)composer_date_of_creation.c_str(), sizeof(composer_date_of_creation));

		music.SetComposer(composer);
		spliters = split(composer_date_of_creation, '.');
		music.SetDateOfCreation(stoi(spliters[0]), stoi(spliters[1]), stoi(spliters[2]));

		bin_in.read((char*)musical_composition_type_name.c_str(), sizeof(musical_composition_type_name));
		bin_in.read((char*)musical_composition_type_text.c_str(), sizeof(musical_composition_type_text));

		if (musical_composition_type_name == "Sonata")
		{
			sonata.SetName(musical_composition_type_name);
			sonata.SetText(musical_composition_type_text);
			music.SetMusicalCompositionType(&sonata);
		}
		else if (musical_composition_type_name == "Symphony")
		{
			symphony.SetName(musical_composition_type_name);
			symphony.SetText(musical_composition_type_text);
			music.SetMusicalCompositionType(&symphony);
		}
		else if (musical_composition_type_name == "Concert")
		{
			concert.SetName(musical_composition_type_name);
			concert.SetText(musical_composition_type_text);
			music.SetMusicalCompositionType(&concert);
		}
		else if (musical_composition_type_name == "Divertissement")
		{
			divertissement.SetName(musical_composition_type_name);
			divertissement.SetText(musical_composition_type_text);
			music.SetMusicalCompositionType(&divertissement);
		}

		bin_in.read((char*)music_name.c_str(), sizeof(music_name));
		bin_in.read((char*)music_opus.c_str(), sizeof(music_opus));

		music.SetName(music_name);
		music.SetOpus(music_opus);

		bin_in.read((char*)harmonist_text.c_str(), sizeof(harmonist_text));
		if (harmonist_text == "Cellist")
		{
			cellist.SetText(harmonist_text);
			performer.SetHarmonist(&cellist);
		}
		else if (harmonist_text == "Conductor")
		{
			conductor.SetText(harmonist_text);
			performer.SetHarmonist(&conductor);
		}
		else if (harmonist_text == "Pianist")
		{
			pianist.SetText(harmonist_text);
			performer.SetHarmonist(&pianist);
		}
		else if (harmonist_text == "Violonist")
		{
			violonist.SetText(harmonist_text);
			performer.SetHarmonist(&violonist);
		}

		bin_in.read((char*)person_date_of_birth.c_str(), sizeof(person_date_of_birth));
		bin_in.read((char*)person_name.c_str(), sizeof(person_name));
		bin_in.read((char*)person_surname.c_str(), sizeof(person_surname));

		recording.SetMusic(music);
		spliters = split(person_date_of_birth, '.');
		person.SetDateOfBirth(stoi(spliters[0]), stoi(spliters[1]), stoi(spliters[2]));
		person.SetName(person_name);
		person.SetSurname(person_surname);

		performer.SetPerson(person);
		bin_in.read((char*)&duration_in_seconds, sizeof(duration_in_seconds));
		recording.SetPerformer(performer);
		recording.SetDurationInSeconds(duration_in_seconds);
		album.AddMusicalRecording(recording);
	}
	album.Print();

	if (out.is_open())
	{
		size = album.GetFilledSize();
		for (int i = 0; i < size; i++)
		{
			out << album[i].GetMusic().GetComposer().GetDateOfBirth() << " " << album[i].GetMusic().GetComposer().GetName() << " " << album[i].GetMusic().GetComposer().GetSurname() << " " << album[i].GetMusic().GetDateOfCreation().ToString() << " " << album[i].GetMusic().GetMusicalCompositionType()->GetName() << " " << album[i].GetMusic().GetMusicalCompositionType()->GetText() << " " << album[i].GetMusic().GetName() << " " << album[i].GetMusic().GetOpus() << " " << album[i].GetPerformer().GetHarmonist()->GetText() << " " << album[i].GetPerformer().GetPerson().GetDateOfBirth() << " " << album[i].GetPerformer().GetPerson().GetName() << " " << album[i].GetPerformer().GetPerson().GetSurname() << " " << album[i].GetDurationInSecnods() << endl;
		}
	}
	out.close();

	
menu:
	int menu;
	
		cout << "1.Завантажити iнформацiю з документу" << endl << "2.Вивести iнформацiю про музичні твори у виглядi таблицi" << endl << "3.Обрахувати середню кiлькiсть символiв в назвах твору" << endl;
		cout << "4.Обрахувати середню довжину музичного запису" << endl << "5.Завершити програму" << endl;

		cout << "Оберiть варiант меню: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			cout << "Завантажено!" << endl;
			break;
		case 2:
			cout << " Музичний твiр " << endl;
			
			cout << "|   Композитор  |  Назва  |       Тип      | Опус | Рiк  створення |" << endl;
			album.Print();
			break;
		case 3:
			cout << NormalSymbols<float>(album) << endl;

			break;
		case 4:
			cout << NormalDuration<double>(album) << endl;
			break;
		case 5:
			cout << "Завершення програми!";
			return 0;
			break;
		}
		goto menu;
	



	return 0;
}