#pragma once

#include <Windows.h>
#include <string>
#include <iostream>

//using namespace std;

class login_screen
{
public:
	//Main login screen program. This executes all other functions when time is right
	bool login_screen_main();
	
private:
	//Details updater when authentication is successful
	bool user_details_updater(std::string username);
	//Header String and Inner string to display program name
	bool Header_String();	
	bool Data_Entry_String();

	//Username and Password Entry
	std::string Password_Entry_Testing()
	{
		//Generators generator;
		HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
		DWORD mode = 0;
		GetConsoleMode(hStdin, &mode);
		SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

		std::string s;
		//std::cout << "Enter Password: (Input will be hidden)";

		//getline(cin, s);
		std::cin >> s;
		//cout << s << endl;
		//system("pause");
		return s;
	}
	std::string Username_Entry()
	{
		std::string username;
		//std::cout << "Enter Username: ";
		std::cin >> username;
		return username;
	}
	
	
	//Username and PAssword details authenticator
	int authenticator(std::string username, std::string password);
	//Algorithm to check username and password before procceeding
	int username_check(std::string username);
	int password_check(std::string password);
	std::string username_password_executer();
	

	//Program Flow Controller
	int pf1_controller(int p);
	int pf2_controller(int p);
	int pf3_controller(int p);
};

