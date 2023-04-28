#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <conio.h>
#include <string>

#include "User.h"



class Admin : public User {
	
	public:
		void displayMenu();
		void registerUser();
		bool isLoggedIn();
};

#endif /* ADMIN_H */
