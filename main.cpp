#include <iostream>

#include "login_screen.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	bool result;
	login_screen login;
	
	result = login.login_screen_main();
	return result;
}
