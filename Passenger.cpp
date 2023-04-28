
#include "Passenger.h"

using namespace std;

void Passenger :: displayMenu()
{
	cout << "1. View plane schedule" << endl;
	cout << "2. Book a flight" << endl;
	cout << "3. Cancel flight" << endl;
	cout << "4. Update account info " << endl;
}


void Passenger :: registerUser()
{
	string repass;
	string cnic;
	ofstream pFile;
	pFile.open("Passenger.txt", ios::app);
	ifstream prFile;
	if (!pFile)
	cout << "File failed to open." << endl;
	prFile.open("Passenger.txt", ios::app);
	cnicc:
	cout << "Please enter your CNIC number" << endl;
	cin >> CNIC;
	bool cni = true;
	while (getline (prFile,cnic))
	{
		if (cnic == CNIC)
		{
			cni = false;
		}
	}
	if (cni == false)
	{
		cout << "The entered CNIC is already in use. Either log in or reenter the CNIC." << endl;
		goto cnicc;
	}
	cout << "Please enter your username" << endl;
	cin >> username;
	pass:
	cout << "Please set a password" << endl;
	char ch = _getch();
	while (ch != 13) //13 means enter
	{
		password.push_back(ch);
		cout << '*';
		ch = _getch();
	}
	cout << endl;

	cout << "Reenter the password" << endl;
	char c = _getch();
	while (c != 13) //13 means enter
	{
		repass.push_back(c);
		cout << '*';
		c = _getch();
	}
	cout << endl;
	if (repass != password)
	{
		cout << "passwords dont match." << endl;
		goto pass;
	}
	
	
	pFile << CNIC << endl << username << endl << password << endl << endl;
	pFile.close();
	
}


bool Passenger :: isLoggedIn()
{
	string un,pw;
	cout << "Please enter your username" << endl;
	cin >> un;
	repass:
	cout << "Please enter your password" << endl;
	char ch = _getch();
	while (ch != 13) //13 means enter
	{
		pw.push_back(ch);
		cout << '*';
		ch = _getch();
	}
	cout << endl;

	ifstream pFile ("Passenger.txt", ios::app);
	if (!pFile)
	cout << "File failed to open." << endl;
	while (getline (pFile, username))
	{

		if (username == un)
		{
			Case = true;
			getline (pFile, password);
			if (password == pw)
			{
				cout << "Successfully logged in." << endl;
				pFile.close();
				Case = true;
				return true;
			}
			else 
			{
				cout << "Wrong password" << endl;
				goto repass;
				pFile.close();
				goto repass;
			}
		}
		else
		{
			Case = false;
		//	cout << "Username isnt registered." << endl;
			
		}
	}
}
