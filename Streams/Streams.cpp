#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
using namespace std;

bool CheckingName(const string& s) {
	bool b = true;
	for (auto& a : s) {
		if (!isalpha(a)) {
			b = false;
			break;
		}
	}
	return b;
}
bool CheckingDouble(const string& s) {
	bool b = true;
	for (auto& a : s) {
		if (!isdigit(a) && a != '.' && a != '-') {
			b = false;
			break;
		}
	}
	return b;
}

class Music {

	int n = 0;
	string name[10];
	string group[10];
	string genre[10];
	double length[10];
public:
	void Input() {
		string s;
		cout << "Enter song name: ";
		if (n > 0)
			cin.ignore();
		getline(cin, name[n]);
		cout << "Enter group name: ";
		getline(cin, group[n]);
		cout << "Enter genre of song: ";
		do {
			cin >> s;
			if (CheckingName(s))
			genre[n] = s;
			else
			cout << "Somethung went wrong. Try again: ";
		} while (!CheckingName(s));
		cout << "Enter length of song(mm.ss): ";
		do {
			cin >> s;
			if (CheckingDouble(s))
				length[n] = stof(s);
			else
				cout << "Something went wrong. Try again: ";
		} while (!CheckingDouble(s));
		n++;
	}
	void Print() {
		if (n == 0) {
			cout << "Playlist now is empty.Try to add some songs\n";
			return;
		}
		for (int i = 0; i < n; i++) {
			cout << "Song " << i + 1 << ":\n";
			cout << "Song: " << name[i] << "\n";
			cout << "Group: " << group[i] << "\n";
			cout << "Genre: " << genre[i] << "\n";
			cout << "Length: " << length[i] << "\n\n";
		}
	}

	void Save1() {
		ofstream file("Playlist1.txt");
		if (!file.is_open())
			cout << "Error!\n";
		else
			file << n << "\n";
		for (int i = 0; i < n; i++) {
			file << name[i] << "\t" << group[i] << "\t" << genre[i] << "\t" << length[i] << "\n";
		}
		file.close();
		cout << "Saved!\n";
	}
	void Save2() {
		ofstream file("Playlist2.txt");
		if (!file.is_open())
			cout << "Error!\n";
		else
			file << n << "\n";
		for (int i = 0; i < n; i++) {
			file << name[i] << "\t" << group[i] << "\t" << genre[i] << "\t" << length[i] << "\n";
		}
		file.close();
		cout << "Saved!\n";
	}
	void Save3() {
		ofstream file("Playlist3.txt");
		if (!file.is_open())
			cout << "Error!\n";
		else
			file << n << "\n";
		for (int i = 0; i < n; i++) {
			file << name[i] << "\t" << group[i] << "\t" << genre[i] << "\t" << length[i] << "\n";
		}
		file.close();
		cout << "Saved!\n";
	}
	void Load1() {
		ifstream file("Playlist1.txt");
		file >> n;
		for (int i = 0; i < n; i++) {
			file >> name[i];
			file >> group[i];
			file >> genre[i];
			file >> length[i];
		}
		cout << "Loaded!\n";
	}
	void Load2() {
		ifstream file("Playlist2.txt");
		file >> n;
		for (int i = 0; i < n; i++) {
			file >> name[i];
			file >> group[i];
			file >> genre[i];
			file >> length[i];
		}
		cout << "Loaded!\n";
	}
	void Load3() {
		ifstream file("Playlist3.txt");
		file >> n;
		for (int i = 0; i < n; i++) {
			file >> name[i];
			file >> group[i];
			file >> genre[i];
			file >> length[i];
		}
		cout << "Loaded!\n";
	}

	void Del() {
		string s;
		int f = 0;
		int j;
		cout << "Enter name of song to be deleted: ";
		cin >> s;
		for (int i = 0; i < n; i++) {
			if (name[i] == s) {
				f++;
				j = i;
				break;
			}
		}
		if (f == 0) {
			cout << "Song with name " << s << " was not found\n";
			return;
		}
		for (int i = j; i < n-1; i++) {
			name[i] = name[i + 1];
			group[i] = group[i + 1];
			genre[i] = genre[i + 1];
			length[i] = length[i + 1];
			n--;
			cout << "Song with name " << s << " deleted\n";
		}

	}
	void Comp() {
		char ch;
		int nc = 0;
		string namec[10];
		string groupc[10];
		string genrec[10];
		double lengthc[10];
		do {
			cout << "Enter the number of the playlist you want to add(1,2,3): ";
			ch = _getch();
		} while (ch != '1' && ch != '2' && ch != '3');
		if (ch == '1') {
			ifstream file("Playlist1.txt");
			file >> nc;
			for (int i = 0; i < nc; i++) {
				file >> namec[i];
				file >> groupc[i];
				file >> genrec[i];
				file >> lengthc[i];
			}
		}
		else if (ch == '2') {
			ifstream file("Playlist2.txt");
			file >> nc;
			for (int i = 0; i < nc; i++) {
				file >> namec[i];
				file >> groupc[i];
				file >> genrec[i];
				file >> lengthc[i];
			}
		}
		else {
			ifstream file("Playlist3.txt");
			file >> nc;
			for (int i = 0; i < nc; i++) {
				file >> namec[i];
				file >> groupc[i];
				file >> genrec[i];
				file >> lengthc[i];
			}
		}
		int a = 0;
		for (int i = n; a<nc; i++) {
			name[i] = namec[a];
			group[i] = groupc[a];
			genre[i] = genrec[a];
			length[i] = lengthc[a];
			a++;
			n++;
		}
		cout << "Added\n";
	}
};

int main()
{
	Music m;
	char ch, s;
	do {
		cout << "Menu.\n1 - Add song\n2 - Print playlist on screen\n3 - Save playlist\n4 - Load playlist\n5 - Delete song by name\n6 - Add songs from another playlist\nEsc - Exit\n";
		ch = _getch();
		switch (ch)
		{
		case'1':
			m.Input();
			system("cls");
			break;
		case'2':
			system("cls");
			m.Print();
			system("pause");
			system("cls");
			break;
		case'3':
			do {
				cout << "Enter number of playlist(1,2,3): ";
				s = _getch();
			} while (s != '1' && s != '2' && s != '3');
			if (s == '1') {
				m.Save1();
				system("pause");
				system("cls");
				break;
			}
			if (s == '2') {
				m.Save2();
				system("pause");
				system("cls");
				break;
			}
			if (s == '3') {
				m.Save3();
				system("pause");
				system("cls");
				break;
			}
		case'4':
			do {
				cout << "Enter number of playlist(1,2,3): ";
				s = _getch();
			} while (s != '1' && s != '2' && s != '3');
			if (s == '1') {
				m.Load1();
				system("pause");
				system("cls");
				break;
			}
			if (s == '2') {
				m.Load2();
				system("pause");
				system("cls");
				break;
			}
			if (s == '3') {
				m.Load3();
				system("pause");
				system("cls");
				break;
			}
		case'5':
			m.Del();
			system("pause");
			system("cls");
			break;
		case'6':
			m.Comp();
			system("pause");
			system("cls");
			break;
		}
	} while (ch != 27);
}