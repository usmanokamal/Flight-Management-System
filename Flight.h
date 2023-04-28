#ifndef FLIGHT_H
#define FLIGHT_H
#include <iostream>
#include <fstream>

using namespace std;


class Flight {
	
	public:
		double hours;
		string departure;
		string arrival;
		int timeDepart;
		int timeArrival;
		int passengers;
		int bSeat;
		int eSeat;
		
		void showSchedule();
		void bookSeat();
		void cancelSeat();

		
		void LahoretoKarachi();
		void LahoretoIslamabad();
		void LahoretoQuetta();
		void LahoretoPeshawar();
		void KarachitoLahore();
		void KarachitoIslamabad();
		void KarachitoQuetta();
		void KarachitoPeshawar();
		void QuettatoLahore();
		void QuettatoIslamabad();
		void QuettatoKarachi();
		void QuettatoPeshawar();
		void PeshawartoLahore();
		void PeshawartoIslamabad();
		void PeshawartoKarachi();
		void PeshawartoQuetta();
		void IslamabadtoLahore();
		void IslamabadtoPeshawar();
		void IslamabadtoKarachi();
		void IslamabadtoQuetta();
};

#endif /* FLIGHT_H */
