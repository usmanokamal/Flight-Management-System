#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>

using namespace std;



class User {
	public:
		string username;
		string password;
		string CNIC;
		bool Case;
//	public:
		virtual void displayMenu()=0;
		virtual void registerUser()=0;
		virtual bool isLoggedIn()=0;
};

#endif /* USER_H */
