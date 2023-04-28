
#include "Admin.h"

using namespace std;

void Admin :: displayMenu()
{
	cout << "1. View plane schedule" << endl;
	cout << "2. Book a flight" << endl;
	cout << "3. Cancel flight" << endl;
	cout << "4. Update account info " << endl;
}

void Admin :: registerUser()
{
	string repass;
	ofstream aFile;
	string cnic;
	aFile.open("Admin.txt", ios::app);
	ifstream arFile;
	arFile.open("Admin.txt", ios::app);
	if (!aFile)
	cout << "File failed to open." << endl;
	cnicc:
	cout << "Please enter your CNIC number" << endl;
	cin >> CNIC;
	bool cni = true;
	while (getline (arFile,cnic))
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
	char c = _getch();
	cout << "Reenter the password" << endl;
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
	
	aFile << CNIC << endl << username << endl << password << endl << endl;
	aFile.close();
	
}

bool Admin :: isLoggedIn()
{
	string un,pw;
	char ch;
	cout << "Please enter your username" << endl;
	cin >> un;
	repass:
	cout << "Please enter your password" << endl;
	ch = _getch();
	while (ch != 13) //13 means enter
	{
		pw.push_back(ch);
		cout << '*';
		ch = _getch();
	}
	cout << endl;
	ifstream aFile ("Admin.txt", ios::app);
	if (!aFile)
	cout << "File failed to open." << endl;
	while (getline (aFile, username))
	{

		if (username == un)
		{
			getline (aFile, password);
			if (password == pw)
			{
				cout << "Successfully logged in." << endl;
				aFile.close();
				Case = true;
				return true;
			}
			else 
			{
				aFile.close();
				
				cout << "Wrong password" << endl;
				goto repass;
				return false;
			}
		}
		else
		{
			Case = false;
		//	cout << "Username isnt registered." << endl;
			
		}
	}
}
