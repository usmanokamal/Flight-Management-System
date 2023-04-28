#include "flight.h"

void Flight :: showSchedule()
{
	cout << "________________________________________________________________________________________" << endl;
	cout << "|Name\tDeparture (hrs)\tArrival (hrs)\tType\t\tFrom\t\tTo\t\t|" << endl;
	cout << "________________________________________________________________________________________" << endl;
	string data;
	ifstream scheduleFile;
	scheduleFile.open("schedule.dat",  ios::in);
	while (getline (scheduleFile, data))
	{
		cout << "|" << data << "\t|" << endl;
	}
	scheduleFile.close();
	cout << "________________________________________________________________________________________" << endl;
}

void Flight :: bookSeat()
{
	string to,from;
	cout << "Where do you wanna go (mention city name for local and country name for international)?" << endl;
	cin >> to;
	cout << "Where will you leave from (mention city name)?" << endl;
	cin >> from;
	
	/*
	ofstream out;
	out.open("practice.dat",ios::app | ios::binary);
	out.write((char*)&p , sizeof(practice));
	out.close();
	
	ifstream in;
	in.open("practice.dat", ios::binary);
//	in.seekg(0,ios::beg);
//	int n = in.tellg();
//	cout << n << endl;
	in.read((char*)&p2 , sizeof(practice));
//	n = in.tellg();
	cout << p2.c<<" "<<p2.f << endl;
	in.close();
	*/
}

void Flight :: cancelSeat()
{
	string to,from;
	cout << "Please enter destination (mention city name for local and country name for international)?" << endl;
	cin >> to;
	cout << "Please enter departure (mention city name)?" << endl;
	cin >> from;

}


void Flight :: LahoretoKarachi()
{
	hours = 2;
	departure = "Lahore South";
	arrival = "Karachi North";
	timeDepart = 1500;
	timeArrival = 1700;
	passengers = 60;
	bSeat = 10;
	eSeat = 50;
}
void Flight :: LahoretoIslamabad()
{
	hours = 1;
	departure = "Lahore South";
	arrival = "Islamabad North"; 
	timeDepart = 1100;
	timeArrival = 1200;
	passengers = 60;
	bSeat = 10;
	eSeat = 50;
}
void Flight :: LahoretoQuetta()
{
	hours = 1.5;
	departure = "Lahore North";
	arrival = "Quetta North";
	timeDepart = 1700;
	timeArrival = 1950;
	passengers = 60;
	bSeat = 10;
	eSeat = 50;
}
void Flight :: LahoretoPeshawar()
{
	hours = 1;
	departure = "Lahore South";
	arrival = "Peshawar South";
	timeDepart = 0500;
	timeArrival = 0600;
	passengers = 60;
	bSeat = 10;
	eSeat = 50;
}
void Flight :: KarachitoLahore()
{
	hours = 2;
	departure = "Karachi North";
	arrival = "Lahore South";
	timeDepart = 1500;
	timeArrival = 1700;
	passengers = 60;
	bSeat = 10;
	eSeat = 50;
}
void Flight :: KarachitoIslamabad()
{
	hours = 2;
	departure = "Karachi North";
	arrival = "Islamabad South";
	timeDepart = 1300;
	timeArrival = 1500;
	passengers = 60;
	bSeat = 10;
	eSeat = 50;
}
void Flight :: KarachitoQuetta()
{
	hours = 1.5;
	departure = "Karachi North";
	arrival = "Quetta South";
	timeDepart = 8300;
	timeArrival = 1000;
	passengers = 60;
	bSeat = 10;
	eSeat = 50;
}
void Flight :: KarachitoPeshawar()
{
	hours = 2.5;
	departure = "Karachi North";
	arrival = "Peshawar South";
	timeDepart = 1200;
	timeArrival = 1430;
	passengers = 60;
	bSeat = 10;
	eSeat = 50;
}
void Flight :: QuettatoLahore()
{
	hours = 2;
	departure = "Quetta South";
	arrival = "Lahore South";
	timeDepart = 1100;
	timeArrival = 1300;
	passengers = 60;
	bSeat = 10;
	eSeat = 50;
}
void Flight :: QuettatoIslamabad()
{
	hours = 1.5;
	departure = "Quetta South";
	arrival = "Islamabad South";
	timeDepart = 1100;
	timeArrival = 1230;
	passengers = 60;
	bSeat = 10;
	eSeat = 50;
}
void Flight :: QuettatoKarachi()
{
	hours = 1.5;
	departure = "Quetta South";
	arrival = "Karachi North";
	timeDepart = 0600;
	timeArrival = 0730;
	passengers = 60;
	bSeat = 10;
	eSeat = 50;
}
void Flight :: QuettatoPeshawar()
{
	hours = 1;
	departure = "Quetta South";
	arrival = "Peshawar South";
	timeDepart = 2000;
	timeArrival = 2100;
	passengers = 60;
	bSeat = 10;
	eSeat = 50;
}
void Flight :: PeshawartoLahore()
{
	hours = 1.5;
	departure = "Peshawar South";
	arrival = "Lahore South";
	timeDepart = 2200;
	timeArrival = 2330;
	passengers = 60;
	bSeat = 10;
	eSeat = 50;
}
void Flight :: PeshawartoIslamabad()
{
	hours = 1.5;
	departure = "Peshawar South";
	arrival = "Islamabad South";
	timeDepart = 0000;
	timeArrival = 0130;
	passengers = 60;
	bSeat = 10;
	eSeat = 50;
}
void Flight :: PeshawartoKarachi()
{
	hours = 2.5;
	departure = "Peshawar South";
	arrival = "Karachi North";
	timeDepart = 1600;
	timeArrival = 1830;
	passengers = 60;
	bSeat = 10;
	eSeat = 50;
}
void Flight :: PeshawartoQuetta()
{
	hours = 1.5;
	departure = "Peshawar South";
	arrival = "Quetta South";
	timeDepart = 1500;
	timeArrival = 1630;
	passengers = 60;
	bSeat = 10;
	eSeat = 50;
}

void Flight :: IslamabadtoLahore()
{
	hours = 1;
	departure = "Islamabad North";
	arrival = "Lahore South";
	timeDepart = 1000;
	timeArrival = 1100;
	passengers = 60;
	bSeat = 10;
	eSeat = 50;
}
void Flight :: IslamabadtoPeshawar()
{
	hours = 1.5;
	departure = "Islamabad South";
	arrival = "Peshawar South";
	timeDepart = 0100;
	timeArrival = 0230;
	passengers = 60;
	bSeat = 10;
	eSeat = 50;
}
void Flight :: IslamabadtoKarachi()
{
	hours = 2;
	departure = "Islamabad North";
	arrival = "Karachi North";
	timeDepart = 1300;
	timeArrival = 1500;
	passengers = 60;
	bSeat = 10;
	eSeat = 50;
}
void Flight :: IslamabadtoQuetta()
{
	hours = 1.5;
	departure = "Islamabad South";
	arrival = "Quetta South";
	timeDepart = 1500;
	timeArrival = 1650;
	passengers = 60;
	bSeat = 10;
	eSeat = 50;
}
	
