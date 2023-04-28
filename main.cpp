#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include "Flight.h"
#include "User.h"
#include "Admin.h"
#include "Passenger.h"
#include "Flight.cpp"
#include "Admin.cpp"
#include "Passenger.cpp"

using namespace std;

int main()
{
	Admin ad;
	Passenger pa;
	Flight fl;
	Flight f;
	int op1,op2,op3;
	int acc1=0,acc2=0;
	bool adminLog = false, passLog = false;
	//introduction 
	cout << endl;
	cout << " 		       \\ \\" << endl;
	cout << " 		  \\ ____\\_\\_______" << endl;
	cout << "	   === \\\\ NPAFS Airlines \\ )" << endl;
	cout << "  		    ~~~~~/ /~~~~~  " << endl;
	cout << "    	              ==/ /  " << endl;
	cout << "	  	       ---    " << endl;
	cout << "Welcome to NPAFS - where we fly with quality." << endl << endl;
	
	cout << "About NPAFS:" << endl;
	cout << "NPAFS was initially found as a cargo airline that transferred cargo. Soon, we felt that Pakistan is in need of an airline that provides quality. Therefore, on the 21st of June, we officially launched commercially. NPAFS flies to 25 countries and five local Pakistani cities with the number increasing every day. We are committed to excellence. So what are you waiting for? Book your tickets now!" << endl << endl;
	
	cout << "Press ENTER to display menu." << endl;
	cin.get();
	
	//main menu
	mainMenu:
	cout << "Select your option." << endl;
	cout << "1. Continue without logging in" << endl;
	cout << "2. Log in" << endl;
	cout << "3. Sign up." << endl;
	cin >> op1;
	
	if (op1 == 1)
	{
		goto menu;
	}
	else if (op1 == 2)
	{
		goto logInType;
	}
	else if (op1 == 3)
	{
		goto signUpType;
	}
	else 
	{
		cout << "Invalid input. Try again." << endl;
		goto mainMenu;
	}
	
	//login menu
	logInType:
	cout << "Please select an option" << endl;
	cout << "1. Admin Login" << endl;
	cout << "2. User Login" << endl;
	cin >> op2;
	
	if (op2 == 1)
	{
		acc2 = 1;
		ad.isLoggedIn();
		adminLog = true;
		if (ad.Case == false)
		{
			cout << "Login unsuccessful. Please try again." << endl;
			goto mainMenu;
		}
		goto logInMenu;
	}
	else if (op2 == 2)
	{
		acc2 = 2;
		pa.isLoggedIn();
//		pa.Case = true;
		if (pa.Case == false)
		{
			cout << "Login unsuccessful. Please try again." << endl;
			goto mainMenu;
		}
		passLog = true;
		goto logInMenu;
	}
	else 
	{
		cout << "You have entered an invalid input. PLease try again." << endl;
		goto logInType;
	}
	
	//sign up menu
	signUpType:
	cout << "Please select an option" << endl;
	cout << "1. Admin Sign up" << endl;
	cout << "2. User Sign up" << endl;
	cin >> op2;
	
	if (op2 == 1)
	{
		ad.registerUser();
		cout << "Succesfully registered! Please log in." << endl;
		goto logInType;
	}
	else if (op2 == 2)
	{
		pa.registerUser();
		cout << "Successfully registered! Please log in." << endl;
		goto logInType;
	}
	else 
	{
		cout << "You have entered an invalid input. PLease try again." << endl;
		goto signUpType;
	}
	
	//LOG IN MENU
	logInMenu:

	if (acc2==1)
	{
		acc1 = 1;
	}
	else if (acc2==2)
	{
		acc1 = 2;
	}
	
	menu:
	cout << "Please select an option." << endl;
	if (acc1 == 0)
	{
		cout << "1. View today's flight schedule" << endl;
		cout << "2. Go to main menu" << endl;
		cout << "3. Register New User" << endl;
		cout << "4. Log in for more options" << endl;
		cout << "0. Exit" << endl;
	}
	if (acc1 == 2)
	{
		cout << "1. View today's flight schedule" << endl;
		cout << "2. Go to main menu" << endl;
		cout << "3. Register New User" << endl;
		cout << "4. Log in again." << endl;
		cout << "5. Update account info " << endl;
		cout << "6. Buy a ticket" << endl;
		cout << "7. Cancel ticket" << endl;
		cout << "0. Exit" << endl;
		///////////
	}
	if (acc1 == 1)
	{
		cout << "1. View today's flight schedule" << endl;
		cout << "2. Go to main menu" << endl;
		cout << "3. Register New User" << endl;
		cout << "4. Log in again." << endl;
		cout << "5. Update account info " << endl;
		cout << "6. Buy a ticket" << endl;
		cout << "7. Cancel ticekt" << endl;
		cout << "8. Make changes to airplane schedule" << endl; //////////////////
		cout << "0. Exit" << endl;
	}
	inputmenu:
	cin >> op3;
	if (op3 == 1)
	{
		fl.showSchedule();
		goto menu;
	}
	else if (op3 == 2)
	{
		cout << "You're already on main menu" << endl;
		goto inputmenu;
	}
	else if (op3 == 3)
	{
		goto signUpType;
	}
	else if (op3 == 4)
	{
		adminLog = false;
		passLog = false;
		cout << "Moving to login screen..." << endl;
	//	cout << "Successfully logged you out." << endl;
		goto logInType;
	}
	else if (op3 == 5)
	{
		int op5;
		cout << "what do you want to update?" << endl;
		cout << "1. Name" << endl;
		cout << "2. Password" << endl;
		cout << "3. CNIC" << endl;
		cin >> op5;
		if (op5==1)
		{
			string Name,Password;
			char ch ;
			cout << "Enter your new username." << endl;
			cin >> Name;
			cout << "Enter password for confirmation. " << endl;
			//cin >> Password;
			ch = _getch();
			while (ch != 13) //13 means enter
			{
				Password.push_back(ch);
				cout << '*';
				ch = _getch();
			}
			cout << endl;
			ofstream pFile;
			pFile.open("Passenger.txt", ios::app);
			ifstream prFile;
			pFile << Name << endl << Password << endl << endl;
			pFile.close();
		}
		else if (op5==2)
		{
			string Name,Password;
			char ch;
			cout << "Enter your username." << endl;
			cin >> Name;
			cout << "Enter your new password" << endl;
			ch = _getch();
			while (ch != 13) //13 means enter
			{
				Password.push_back(ch);
				cout << '*';
				ch = _getch();
			}
			cout << endl << "Password updated successfully" << endl;
			ofstream pFile;
			pFile.open("Passenger.txt", ios::app);
			ifstream prFile;
			pFile << Name << endl << Password << endl << endl;
			pFile.close();
		}
		else if (op5==3)
		{
			string CNIC;
			cout << "Enter your new CNIC." << endl;
			cin >> CNIC;
			ofstream pFile;
			pFile.open("Passenger.txt", ios::app);
			ifstream prFile;
			pFile << CNIC << endl << endl;
			pFile.close();
		}
		else
		{
			cout << "Invalid input. Moving to menu." << endl;
			goto menu;
		}
		goto menu;
	}
	else if (op3 == 6)
	{
		tryAgain:
		
		char ch;
		cout << "Do you wanna travel international or local? (I/L)" << endl;
		cin >> ch;
		if (ch == 'L')
		{
			cout << "Do you wanna see our flying locations? (y/n)" << endl;
			cin >> ch;
			if (ch == 'y')
			{
				cout << "Locally we travel to," << endl << "Islamabad\nLahore\nKarachi\nQuetta\nPeshawar" << endl;
			}
			cout << "Where do you wanna go? (Enter city name with first letter capital and other small)" << endl;
			cin >> f.arrival;
			cout << "Where will you depart from? (Enter city/country name with first letter capital and other small)" << endl;
			cin >> f.departure;
			if (f.arrival == "Lahore" && f.departure == "Karachi") {f.LahoretoKarachi();}
			else if (f.arrival == "Lahore" && f.departure == "Islamabad") {f.LahoretoIslamabad();}
			else if (f.arrival == "Lahore" && f.departure == "Quetta") {f.LahoretoQuetta();}
			else if (f.arrival == "Lahore" && f.departure == "Peshawar") {f.LahoretoPeshawar();}
			else if (f.arrival == "Karachi" && f.departure == "Lahore") {f.KarachitoLahore();}
			else if (f.arrival == "Karachi" && f.departure == "Islamabad") {f.KarachitoIslamabad();}
			else if (f.arrival == "Karachi" && f.departure == "Quetta") {f.KarachitoQuetta();}
			else if (f.arrival == "Karachi" && f.departure == "Peshawar") {f.KarachitoPeshawar();}
			else if (f.arrival == "Quetta" && f.departure == "Lahore") {f.QuettatoLahore();}
			else if (f.arrival == "Quetta" && f.departure == "Islamabad") {f.QuettatoIslamabad();}
			else if (f.arrival == "Quetta" && f.departure == "Karachi") {f.QuettatoKarachi();}
			else if (f.arrival == "Quetta" && f.departure == "Peshawar") {f.QuettatoPeshawar();}
			else if (f.arrival == "Peshawar" && f.departure == "Lahore") {f.PeshawartoLahore();}
			else if (f.arrival == "Peshawar" && f.departure == "Islamabad") {f.PeshawartoIslamabad();}
			else if (f.arrival == "Peshawar" && f.departure == "Karachi") {f.PeshawartoKarachi();}
			else if (f.arrival == "Peshawar" && f.departure == "Quetta") {f.PeshawartoQuetta();}
			else if (f.arrival == "Islamabad" && f.departure == "Lahore") {f.IslamabadtoLahore();}
			else if (f.arrival == "Islamabad" && f.departure == "Peshawar") {f.IslamabadtoPeshawar();}
			else if (f.arrival == "Islamabad" && f.departure == "Karachi") {f.IslamabadtoKarachi();}
			else if (f.arrival == "Islamabad" && f.departure == "Quetta") {f.IslamabadtoQuetta();}
			else 
			{
				int op4;
				cout << "Error occured. This usually occurs when you mispell a certain city. Reply with 1 if you want to try again. Reply with 0 if you want to exit to menu." << endl;
				cin >> op4;
				if (op4 == 0) {goto menu;}
				else if (op4 == 1) { goto tryAgain;}
				else {
				cout << "error occurred.\n";
				goto menu;
				}
			}	
			cout << endl << "Ticket Details:" << endl;
			cout << "Flight for Today: " << endl;
			cout << f.departure << " to " << f.arrival << "\n";
			cout << "Flight Duration: " << f.hours << " hours" << endl;
			cout << "Departure time: " << f.timeDepart << " hrs\nArrival Time: " << f.timeArrival << " hrs" << endl;
			int cost = f.hours*10000;
			cout << "Price: " << cost << " PKR"  << "\nGovernment Tax: " << cost*5/100 << " PKR"  << endl;
			cout << "Seats left: " << f.passengers << endl;
			cout << "Business Seats: " << f.bSeat << "\tEconomy Seats: " << f.eSeat << endl;
			int tick;
			cout << endl << "How much tickets do you need?" << endl;
			cin >> tick;
			char be;
			cout << "Do you want business seats or economy seats? (b/e)" << endl;
			cin >> be;
			cout << endl << "Total for " << tick << " tickets: " ;
			cout << cost*tick << endl;
			
			cout << endl << endl << "Do you wanna confirm the ticket? (y/n)" << endl;
			cin >> ch;
			if (ch == 'y')
			{
				cout << "Ticket/s bought successfully. Payment deducted from account. " << endl;
				if (be == 'b')
				{
					f.passengers=f.passengers-tick;	
					f.bSeat = f.bSeat - tick;
				}
				else if (be == 'e')
				{
					f.passengers=f.passengers-tick;	
					f.eSeat = f.eSeat - tick;
				}
				cout << "Tickets left for the plane: " << f.passengers << endl;
				cout << "Moving to main menu" << endl << endl;
			}
			else if (ch == 'n')
			{
				cout << "Exiting to menu..." << endl;
				goto menu;
			}
		}
		
		else if (ch == 'I')
		{
			int duration;
			int departure;
			int arrival;
			int price;
			char ch;
			cout << "Do you wanna see our international flying locations? (y/n)" << endl;
			cin >> ch;
			if (ch == 'y')
			{
				cout << "Internationally we travel to," << endl << "USA\nBelgium\nGreece\nQatar\nUAE\nBahrain\nSaudiArabia\nOman\nUK\nIreland\nIceland\nNorway\nGreenland\nAustralia\nAustria\nAlbania\nBosnia\nNewZealand\nCanada\nChile" << endl;
			}
			TryAgain:
			cout << "Where do you wanna go? (Enter country name with first letter capital and other small)" << endl;
			cin >> f.arrival;
			if (f.arrival=="USA") {
				duration = 16;
				departure = 0000;
				arrival = 1600;
			}
			else if (f.arrival=="Belgium") {
				duration = 9;
				departure = 0300;
				arrival = 1200;
			}
			else if (f.arrival=="Greece") {
				duration = 7;
				departure = 1000;
				arrival = 1700;
			}
			else if (f.arrival=="Qatar") {
					duration = 3;
				departure = 1800;
				arrival = 2100;
			}
			else if (f.arrival=="UAE")
			{
					duration = 1.5;
				departure = 1230;
				arrival = 1400;
			}
			else if (f.arrival=="Bahrain")
			{
					duration = 2;
				departure = 1800;
				arrival = 2000;
			}
			else if (f.arrival=="Brazil")
			{
					duration = 18;
				departure = 0100;
				arrival = 1900;
			}
			else if (f.arrival=="Oman")
			{
					duration = 2.5;
				departure = 1300;
				arrival = 1530;
			}
			else if (f.arrival=="UK")
			{
				duration = 8;
				departure = 1200;
				arrival = 2000;
			}
			else if (f.arrival=="Ireland")
			{
				duration = 8;
				departure = 2000;
				arrival = 0400;
			}
			else if (f.arrival=="Iceland")
			{
				duration = 11;
				departure = 1100;
				arrival = 2200;
			}
			else if (f.arrival=="Norway")
			{
				duration = 6;
				departure = 1600;
				arrival = 2200;
			}
			else if (f.arrival=="Greenland")
			{
				duration = 11;
				departure = 1000;
				arrival = 2100;
			}
			else if (f.arrival=="Australia")
			{
				duration = 20;
				departure = 0700;
				arrival = 0500;
			}
			else if (f.arrival=="Austria")
			{
				duration = 7;
				departure = 1000;
				arrival = 1700;
			}
			else if (f.arrival=="Albania")
			{
				duration = 7;
				departure = 1000;
				arrival = 1700;
			}
			else if (f.arrival=="Bosnia")
			{
				duration = 7;
				departure = 1000;
				arrival = 1700;
			}
			else if (f.arrival=="Iran")
			{
				duration = 7;
				departure = 1000;
				arrival = 1700;
			}
			else if (f.arrival=="Canada")
			{
				duration = 7;
				departure = 1000;
				arrival = 1700;
			}
			else if (f.arrival=="Chile")
			{
				duration = 7;
				departure = 1000;
				arrival = 1700;
			}
			else 
			{
				int op6;
				cout << "Error occured. This usually occurs when you mispell a certain city. Reply with 1 if you want to try again. Reply with 0 if you want to exit to menu." << endl;
				cin >> op6;
				if (op6 == 0) {goto menu;}
				else if (op6 == 1) { goto TryAgain;}
				else {
				cout << "error occurred.\n";
				goto menu;
				}
			}
		
			cout << "Flight to " << f.arrival << endl;
			cout << "Flight for today: " << endl;
			cout << "Duaration: " << duration << " hours" << endl;
			cout << "Departure: " << departure << " hrs " << endl;
			cout << "Arrival: " << arrival << " hrs " << endl;
			price = duration*20000;
			cout << "Price: " << price << " PKR" << endl;
			cout << "Government Tax: " << price*0.1 << " PKR"  << endl;
			
			char chch;	
			cout << endl << endl << "Do you want to buy the ticket? (y/n)" << endl;
			cin >> chch;
			if (chch == 'y')
			cout << "Ticket successfully purchased " << endl;
			else
			{
				cout << "Exiting to menu..." << endl;
				goto menu;
			}
		}
		
		goto menu;
	}
	else if (op3 == 7)
	{
		tryyagain:
			cout << "What is the destination? (Enter city name with first letter capital and other small)" << endl;
			cin >> f.arrival;
			cout << "Where is departure? (Enter city/country name with first letter capital and other small)" << endl;
			cin >> f.departure;
			if (f.arrival == "Lahore" && f.departure == "Karachi") {f.LahoretoKarachi();}
			else if (f.arrival == "Lahore" && f.departure == "Islamabad") {f.LahoretoIslamabad();}
			else if (f.arrival == "Lahore" && f.departure == "Quetta") {f.LahoretoQuetta();}
			else if (f.arrival == "Lahore" && f.departure == "Peshawar") {f.LahoretoPeshawar();}
			else if (f.arrival == "Karachi" && f.departure == "Lahore") {f.KarachitoLahore();}
			else if (f.arrival == "Karachi" && f.departure == "Islamabad") {f.KarachitoIslamabad();}
			else if (f.arrival == "Karachi" && f.departure == "Quetta") {f.KarachitoQuetta();}
			else if (f.arrival == "Karachi" && f.departure == "Peshawar") {f.KarachitoPeshawar();}
			else if (f.arrival == "Quetta" && f.departure == "Lahore") {f.QuettatoLahore();}
			else if (f.arrival == "Quetta" && f.departure == "Islamabad") {f.QuettatoIslamabad();}
			else if (f.arrival == "Quetta" && f.departure == "Karachi") {f.QuettatoKarachi();}
			else if (f.arrival == "Quetta" && f.departure == "Peshawar") {f.QuettatoPeshawar();}
			else if (f.arrival == "Peshawar" && f.departure == "Lahore") {f.PeshawartoLahore();}
			else if (f.arrival == "Peshawar" && f.departure == "Islamabad") {f.PeshawartoIslamabad();}
			else if (f.arrival == "Peshawar" && f.departure == "Karachi") {f.PeshawartoKarachi();}
			else if (f.arrival == "Peshawar" && f.departure == "Quetta") {f.PeshawartoQuetta();}
			else if (f.arrival == "Islamabad" && f.departure == "Lahore") {f.IslamabadtoLahore();}
			else if (f.arrival == "Islamabad" && f.departure == "Peshawar") {f.IslamabadtoPeshawar();}
			else if (f.arrival == "Islamabad" && f.departure == "Karachi") {f.IslamabadtoKarachi();}
			else if (f.arrival == "Islamabad" && f.departure == "Quetta") {f.IslamabadtoQuetta();}
			else 
			{
				int op8;
				cout << "Error occured. This usually occurs when you mispell a certain city. Reply with 1 if you want to try again. Reply with 0 if you want to exit to menu." << endl;
				cin >> op8;
				if (op8 == 0) {goto menu;}
				else if (op8 == 1) { goto tryyagain;}
				else {
				cout << "error occurred.\n";
				goto menu;
				}
			}	
			int cost = f.hours*10000;
			
			cout << "How many tickets do you wanna cancel? " << endl;
			int tick;
			cin >> tick;
			cout << endl << "Cancelling " << tick << " tickets... " << endl ;
			int totalf = cost*tick;
			int reftotal = (totalf) - (totalf*0.25);
			cout << "Only " << reftotal << " of " << totalf << "will be refunded with a cancellation fee of 25%."  << endl;
		
			cout << endl << endl << "Do you wanna confirm? (y/n)" << endl;
			char ch1;
			cin >> ch1;
			
			if (ch1 == 'y')
			{
				cout << "Ticket cancelled. Amount refunded into your account." << endl;
				cout << "Going to main menu... " << endl;
			
			}


		goto menu;
	}
		else if (op3 == 8)
	{
		int op7;
		cout << "What do you wanna do?" << endl;
		cout << "1. Add" << endl;
		cout << "2. Edit" << endl;
		cout << "3. Delete" << endl;
		cin >> op7;
		
		if (op7 == 1)
		{
			string name;
			string timeL;
			string timeA;
			string type;
			string cityL;
			string typeL;
			string cityA;
			string typeA;
			cout << "Enter name of flight: ";
			cin >> name;
			cout << "Enter time of leaving (in hrs format): ";
			cin >> timeL;
			cout << "Enter arriving time (in hrs format): ";
			cin >> timeA;
			cout << "Local or International? ";
			cin >> type;
			cout << "What is the departure location? " ;
			cin >> cityL;
			cout << "Which airport (north or south)? " ;
			cin >> typeL;
			cout << "What is the arriving location? " ;
			cin >> cityA;
			cout << "Which airpot (north or south) ";
			cin >> typeA;
			ofstream file;
			file.open("schedule.dat",ios::binary | ios::app);
			file << endl << name << "\t\t" << timeL << "\t" << timeA << "\t\t" << type << "\t\t" << cityL << " " << typeL << "\t" << cityA << " " << typeA;
			file.close();
			cout << "Data added!" << endl;
		}
		else if (op7 == 2)
		{
			string olname;
			cout << "Enter old name of which you wish to update. " << endl;
			cin >> olname;
			string name;
			string timeL;
			string timeA;
			string type;
			string cityL;
			string typeL;
			string cityA;
			string typeA;
			cout << "Enter updated/old name of flight: ";
			cin >> name;
			cout << "Enter updated/old time of leaving (in hrs format): ";
			cin >> timeL;
			cout << "Enter updated/old arriving time (in hrs format): ";
			cin >> timeA;
			cout << "Local or International? ";
			cin >> type;
			cout << "What is the updated/old departure location? " ;
			cin >> cityL;
			cout << "Which airport (north or south)? " ;
			cin >> typeL;
			cout << "What is the updated/old arriving location? " ;
			cin >> cityA;
			cout << "Which airpot (north or south) ";
			cin >> typeA;
		//	ofstream file;
			ifstream file;
			ofstream afile;
			afile.open("schedule.txt" ,ios::binary | ios::app);
			file.open("schedule.dat",ios::binary );
			string tempo;
			while (getline (file,tempo))
			{
				if (tempo == name)
				{
					afile << " " ;
				}
			}
			//file << endl << name << "\t\t" << timeL << "\t" << timeA << "\t\t" << type << "\t\t" << cityL << " " << typeL << "\t" << cityA << " " << typeA;
			file.close();
			afile.close();
			cout << "schedule updated!" << endl;
		}
		else if (op7 == 3)
		{
			string name;
			string tempo;
			cout << "Enter name of the flight you want to delete." << endl;
			cin >> tempo;
			ofstream file;
			file.open("schedule.dat",ios::binary | ios::app);
			file.close();
			cout << "Schedule deleted with the particular name " << name << endl;
		}
		else
		{
			cout << "Wrong input. Exiting to menu..." << endl;
			goto menu;
		}
		goto menu;
	}
	else if (op3 == 0)
	{
			return 0;
			goto menu;
	}
	
	else 
	{
		cout << "invalid input. try again." << endl;
		goto menu;
	}
	
	


}


