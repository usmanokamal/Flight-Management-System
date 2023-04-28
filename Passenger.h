#ifndef PASSENGER_H
#define PASSENGER_H
#include <iostream>
#include <conio.h>
#include "User.h"
class Passenger : public User {
	
	public:
		void displayMenu();
		void registerUser();
		bool isLoggedIn();
};

#endif /* PASSENGER_H */
