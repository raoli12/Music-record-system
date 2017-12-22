#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include<Windows.h>


using namespace std;
class record
{
	string name;
	string album_name;
	string label;
	static int count;
	static int count1;
	int year;
	int tracks;
	int bonus_tracks = 0;

	char ch;
public:
	string name1() const
	{
		return name;
	}
	void get_data()
	{
		system("color 0A");
		count++;
		cout << "Enter Name of Artist/Band " << endl;
		cin >> name;
		cout << "Enter Album's Name" << endl;
		cin >> album_name;
		cout << "Enter  Label " << endl;
		cin >> label;
		cout << "Enter Year of Release " << endl;
		cin >> year;
		cout << "Enter Number of Tracks in Album " << endl;
		cin >> tracks;
		cout << "Enter Number of Bonus Tracks " << endl;
		cin >> bonus_tracks;
	}
	void menu()
	{
		system("color 0A");
		char option;
		do
		{
			system("cls");
			cout << "\t\t        " << "                               " << endl;
			cout << "\t\t        " << "|        ` Main Menu `        |" << endl;
			cout << "\t\t        " << "|_____________________________|" << endl;
			cout << "\n";
			cout << "\n";
			cout << "\t\t 1. Add records" << endl;
			cout << "\t\t 2. View record" << endl;
			cout << "\t\t 3. Modify records" << endl;
			cout << "\t\t 4. Delete records" << endl;
			cout << "\t\t 5. Exit" << endl;
			cout << "\t\t " << endl;
			cout << "\t\t Select an option" << endl;
			cin >> option;
			switch (option)
			{
			case '1':
			{
						system("cls");
						write_music();
						break;
			}
			case '2':
			{
						system("cls");
						display_records1();
						system("cls");
			}
			case '3':
			{
						system("cls");
						edit_records();
			}
			case '4':
			{
						system("cls");
						delete_records();
			}
			case '5':
			{
						exit(0);
			}
			default:
			{
					   cout << "Invalid option" << endl;
			}
			}
			cout << endl;
			cout << "Do you want to go back to the menu? (y/n)" << endl;
			cin >> ch;
		} while (ch == 'y');
	}
	void write_music()
	{
		record r;
		cout << "\t\t        " << "|       `Record Register`     |" << endl;
		cout << "\t\t        " << "|_____________________________| " << endl;
		cout << "\n";
		cout << "\n";
		ofstream outFile;
		outFile.open("record.csv", ios::binary | ios::app);
		r.get_data();
		outFile.write(reinterpret_cast<char *> (&r), sizeof(record));
		outFile.close();
		cout << "\n\n Music Record Has Been Created. ";
		cin.ignore();
		cin.get();
		cout << endl;
		cout << "Do you want to go back to the menu? (y/n)" << endl;
		cin >> ch;
		if (ch == 'y')
			r.menu();
		else
			exit(0);
		system("cls");
	}
	void display_records(string n)
	{
		record r;
		ifstream inFile;
		inFile.open("record.csv", ios::binary);

		if (!inFile)
		{

			cout << "File can't be opened!! Press any Key...";
			cin.ignore();
			cin.get();
			return;
		}
		bool flag = false;
		while (inFile.read(reinterpret_cast<char *> (&r), sizeof(record)))
		{
			if (r.name1() == n)
			{
				r.display();
				flag = true;
			}
		}
		inFile.close();
		if (flag == false)
			cout << "\n\n Record doesn't exist";
		cin.ignore();
		cin.get();
		cout << endl;
		cout << "Do you want to go back to the menu? (y/n)" << endl;
		cin >> ch;
		if (ch == 'y')
			r.menu();
		else
			exit(0);
		system("cls");
	}
	void display_records1()
	{
		record r;

		system("cls");
		cout << "\t\t        " << "_______________________________" << endl;
		cout << "\t\t        " << "|    ``MUSIC RECORD STORE``   |" << endl;

		cout << "\n";
		cout << "\n\t\t      " << "-----------------------------" << endl;
		cout << "\t\t\       " << "| VIEW RECORDS INFORMATION |" << endl;
		cout << "\t\t\       " << "-----------------------------" << endl;
		cout << "\n\n";
		cout << "\n\n\t Please Enter the name of the Artist/Band : ";
		cin >> name;
		display_records(name);
		system("cls");

	}
	void display() const
	{
		count1++;
		cout << "\n";
		cout << "\n";
		cout << "\n\n\n_________";
		cout << "\n\n\n Record # " << count1;
		cout << "\n\n\n Name of Artist/Band: " << name;
		cout << "\n\n\n Album Title: " << album_name;
		cout << "\n\n\n Label: " << label;
		cout << "\n\n\n Year of Release: " << year;
		cout << "\n\n\n Total Tracks: " << tracks;
		cout << "\n\n\n Bonus Tracks: " << bonus_tracks;
	}
	void modify_records(string n)
	{
		bool found = false;
		record r;
		fstream File;
		File.open("record.csv", ios::binary | ios::in | ios::out);
		if (!File)
		{
			cout << "File can't be opened!! Press any Key...";
			cin.ignore();
			cin.get();
			return;
		}
		while (!File.eof() && found == false)
		{
			File.read(reinterpret_cast<char *> (&r), sizeof(record));
			if (r.name1() == n)
			{
				r.display();
				cout << endl;
				cout << "\n\n Please Enter the new Details of the Artist/Band" << endl;
				r.get_data();
				int pos = (-1)*static_cast<int>(sizeof(record));
				File.seekp(pos, ios::cur);
				File.write(reinterpret_cast<char *> (&r), sizeof(record));
				cout << "\n\n\t Record Updated";
				found = true;
			}
		}
		File.close();
		if (found == false)
			cout << "\n\n Record Not Found ";
		cin.ignore();
		cin.get();
		cout << endl; cout << endl;
		cout << "Do you want to go back to the menu? (y/n)" << endl;
		cin >> ch;
		if (ch == 'y')
			r.menu();
		else
			exit(0);
		system("cls");
	}
	void edit_records()
	{
		system("cls");
		cout << "\t\t        " << "_______________________________" << endl;
		cout << "\t\t        " << "|    ``MUSIC RECORD STORE``   |" << endl;
		cout << "\n";

		cout << "\n\t\t      " << "-------------------------------" << endl;
		cout << "\t\t\       " << "|     MODIFY SPECIFIC DATA    |" << endl;
		cout << "\t\t\       " << "-------------------------------" << endl;
		cout << "\n\n";
		cout << "\n\n\tPlease Enter the Name of the Atrist : "; cin >> name;
		modify_records(name);
		system("cls");
	}
	void delete_rec(string n)
	{
		record r;
		ifstream inFile;
		inFile.open("record.csv", ios::binary);
		if (!inFile)
		{
			cout << "File can't not be opened!! Press any Key...";
			cin.ignore();
			cin.get();
			return;
		}
		ofstream outFile;
		outFile.open("Temp.csv", ios::out);
		inFile.seekg(0, ios::beg);
		while (inFile.read(reinterpret_cast<char *> (&r), sizeof(record)))
		{
			if (r.name1() != n)
			{
				outFile.write(reinterpret_cast<char *> (&r), sizeof(record));
			}
		}
		outFile.close();
		inFile.close();
		remove("record.csv");
		rename("Temp.csv", "record.csv");
		cout << "\n\n\t Record Deleted ..";
		cin.ignore();
		cin.get();
		cout << endl;
		cout << endl;
		cout << "Do you want to go back to the menu? (y/n)" << endl;
		cin >> ch;
		if (ch == 'y')
			r.menu();
		else
			exit(0);
		system("cls");
	}
	void delete_records()
	{
		system("cls");
		cout << "\t\t        " << "_______________________________" << endl;
		cout << "\t\t        " << "|    ``MUSIC RECORD STORE``   |" << endl;


		cout << "\n";
		cout << "\n\t\t       " << "-------------------------------" << endl;
		cout << "\t\t\       " << "| DELETE SPECIFIC INFORMATION |" << endl;
		cout << "\t\t\       " << "-------------------------------" << endl;
		cout << "\n\n";
		cout << "\n\n\t Please Enter the Name of the Artist/Band "; cin >> name;
		delete_rec(name);
		system("cls");
	}
};
int record::count = 0;
int record::count1 = 0;
void main()
{
	system("cls");
	system("color 0A");

	cout << "\t\t        " << "_______________________________" << endl;
	cout << "\t\t        " << "|    ``MUSIC RECORD STORE``   |" << endl;

	cout << "\n";
	system("pause");
	system("cls");
	cout << endl;
	cout << endl;
	cout << endl;
	for (int i = 0; i < 9; i++)
	{
		Sleep(250);


		cout << " \t"; cout << "|";


	}
	system("cls");
	record r;
	r.menu();
	_getch();
}
