#include <string>
#include <iostream>

#include "user_interface.h"
#include "hanoi.h"

bool IsContinueRunning(UserInterface ui);

int main()
{
	Hanoi hanoi;
	hanoi.InitUI();
	
	bool running = true;
	while (running){
		std::cout << "\n";
		hanoi.Print("How many plates do you want to play? (1 ~ 7)");
		std::string str;
		hanoi.Input(str);
		unsigned int num = std::atoi(str.c_str());
		if (num < 1 || num > 7)
			continue;
		hanoi.InitParams(num);

		std::cout << "\n";
		hanoi.Print("Do you want to play the game yourself(Y) or let computer do(C)?");
		hanoi.Input(str);
		while (str != "Y" && str != "y" && str != "C" && str != "c"){
			hanoi.Print("Please enter Y or C!");
			hanoi.Input(str);
		}

		if (str == "Y" || str == "y"){
			hanoi.UserProcess(num);
		}
		else if (str == "C" || str == "c"){
			hanoi.Draw("", "");
			hanoi.HanoiProcess(num, "A", "B", "C");
		}

		running = IsContinueRunning(hanoi);
	}
	return 0;
}

bool IsContinueRunning(UserInterface ui)
{
	std::cout << "\n";
	ui.Print("Do you want to quit(Q) or continue(C)?");
	std::string str;
	ui.Input(str);

	int n = 0;
	while (str != "Q" && str != "q" && str != "C" && str != "c"){
		ui.Print("Please enter Q or C!");
		ui.Input(str);
		n++;
		if (n > 3)
			ui.Print("Are you kidding? Please enter correct letter!");
	}

	if (str == "Q" || str == "q")
		return false;
	else
		return true;
}
