#include <iostream>
#include <string>


//#include "pch.h"
#include "login_screen.h"
#include "maddons_main.h"
#include <iostream>
int invalid_password_counter = 0,ICED_system = 6;


int program_flow = 1; //1 for username, 2 for password, 0 for exit, 3 Authenticate, 4 Update Details, 5 successful login

bool login_screen::login_screen_main()
{
	std::string username = "Default", password = "Default";
	std::string program_choice = "Default";
	do
	{
		system("cls");

		Header_String();
		Data_Entry_String();
		if (program_flow == 1)
		{
			username = username_password_executer();
			int p = username_check(username); // if p 1 then alright, 0 means exit the program, else program will ask again for username (if a keyword exist to take program to changelog or etc)
			//Add also a function which indentifies if a keyword or exit key is entered and deals program accordingly
			//For ex. if user enters changelog on username section then program should take him to changelog instead of trying to login
			//In such case program_flow must remain same. As follows
			
			//Program Flow 1 Controller Start
			program_flow = pf1_controller(p);
			
		}
		else if (program_flow == 2)
		{
			password = username_password_executer();
			//This function will first check password if there exist some specific function. IF they exist program will now procceed to authentication
			int p = password_check(password); // if p == 1 then program will procceed to authentication, for 0 it will go back to username entry, 
			//ProgramFlow 2 controller
			program_flow = pf2_controller(p);
			
		}
		else if (program_flow == 3)
		{
			//Here we will check for user details and match them with database
			//If everything is fine then program_flow will get value 4 and procceed to update user-details else we go back to username entry
			int p = authenticator(username, password);
			std::cout << "Authenticating Details" << std::endl;
			system("Timeout 3");
			//PrograM_flow 3 Controller
			program_flow = pf3_controller(p);
			if(invalid_password_counter == ICED_system)
			{
				program_choice = "Too-much Invalid Password Attemts";
			}
			
		}
		else if (program_flow == 4)
		{
			std::cout << "Updating Details" << std::endl;
			system("Timeout 3");
			user_details_updater(username);
			program_flow = 5;
		}
		else if (program_flow == 5)
		{
			program_choice = "LoginSuccessful";
		}
		else if (program_flow == 0)
		{
			program_choice = "ExitLoginScreen";
		}
	} while (program_choice == "Default");
	
		
		std::cout << "Program Complete | " << program_choice << std::endl;
	
	system("Timeout 5");
	return false;
}

bool login_screen::Header_String()
{
	maddons_main maddons;
	maddons.custom_generator(1, 50, 1, "=");
	std::cout << "Login Screen";
	if (program_flow == 1)
	{
		std::cout << " | Username Entry";
	}
	else if (program_flow == 2)
	{
		std::cout << " | Password Entry";
	}
	else if (program_flow == 3)
	{
		std::cout << " | Authentication of Details";
	}
	else if (program_flow == 4)
	{
		std::cout << " | Authentication Successful";
	}
	else if (program_flow == 6)
	{
		std::cout << " | Terminated by ICED"<<std::endl;
	}
	if(((program_flow == 2 || program_flow == 1))&&(invalid_password_counter>0))
	{
		std::cout << " | invalid Password Attempts = " << invalid_password_counter;
	}
	std::cout << std::endl;
	maddons.custom_generator(1, 50, 1, "=");
	return 0;
}

bool login_screen::Data_Entry_String()
{
	if(program_flow == 1|| program_flow == 2)
	std::cout << "Enter ";
	if (program_flow == 1)
	{
		
		std::cout << "Username: " << std::endl;
	}
	else if (program_flow == 2)
	{
		std::cout << "Password: (Input is hidden, Press Enter when done)" << std::endl;
	}
	return 0;
}

// This program will update user details, assuming details are kept
bool login_screen::user_details_updater(std::string username)
{
	//Give username to function which updates user details and program parameters

	return false;
}

std::string login_screen::username_password_executer()
{
	std::string returned_details = "Default";
	login_screen login;
	if (program_flow == 1)
	{
		returned_details = Username_Entry();
	}
	else if (program_flow == 2)
	{
		returned_details = Password_Entry_Testing();
	}
	return returned_details;
}

int login_screen::username_check(std::string username)
{
	int p = 1;
	if (username == "0")
	{
		p = 0;
	}
	else if (username == "changelog")
	{

	}
	else if (username == "SomeOtherFunction")
	{

	}
	else
	{
		//If no function is matched, which means program will procceed to password entry
	}
	return p;
}


int login_screen::password_check(std::string password)
{
	int p = 1;
	if (password == "0")
	{
		p = 0;
	}
	else if (password == "SomeCommandsyouwant")
	{

	}
	else
	{
		//If nothing matched
	}
	return p;
}

int login_screen::authenticator(std::string username, std::string password)
{
	int p = 0;
	if (username == "dksoni411")
	{
		if (password == "dksoni@123")
		{
			p = 1;
		}
	}
	else if (username == "admin")
	{
		if (password == "admin")
		{
			p = 1;
		}
	}
	else
	{
		p = 0;
	}
	return p;
}



int login_screen::pf1_controller(int p)
{
	int pf1 = 0;
	if (p == 1)
	{
		pf1 = 2;
	}
	else if (p == 0)
	{
		pf1 = 0;
	}
	else
	{
		//cout << ""
	}
	//End
	return pf1;
}

int login_screen::pf2_controller(int p)
{
	int pf2 = 0;
	
	if (p == 1)
	{
		pf2 = 3;
	}
	else if (p == 0)
	{
		pf2 = 1;
	}
	else
	{

	}
	//End
	return pf2;
}

int login_screen::pf3_controller(int p)
{
	int pf3 = 0;
	
	if (p == 1)//Details matched
	{
		pf3 = 4;
	}
	else if (p == 0)//Details not matched
	{
		invalid_password_counter++;
		std::cout << "Invalid Username or password. Try again" << std::endl;
		system("Timeout 3");
		//Add a counter to count invalid login attempt 
		pf3 = 1;//This will take program to username entry
	}
	return pf3;
}


