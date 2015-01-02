#include <string>
#include <iostream>
#include <vector>
#include "ui_design.h"

void DelNum(int seq[], int n);
void InsNum(int seq[], int location, int n);
bool IsSuccess(int a, int b, int c, int seq[], UIDesign ui);
void Process(UIDesign ui, int num, std::string str, int seq[], bool success, int steps);
bool IsAvailable(std::string res, std::string des, int a, int b, int c, int seq[], UIDesign ui);

int main()
{
	std::string str;
	int num = 0;
	int seq[7] = { 0 };
	bool success = false;
	int steps = 0;
	bool is_continue = true;

	UIDesign ui("Tower of Hanoi Game");
	ui.InitUI();

	while (is_continue){
		Process(ui, num, str, seq, success, steps);

		std::cout << "\n";
		ui.Print("Do you want to quit(Q) or continue(C)?");
		ui.Input(std::cin, str);
		if (str == "Q" || str == "q")
			break;
		else if (str == "C" || str == "c")
			continue;
	}
	return 0;
}

void DelNum(int seq[], int n)
{
	for (int i = n; i < 6; i++){
		seq[i] = seq[i + 1];
	}
	seq[6] = 0;
}

void InsNum(int seq[], int location, int n)
{
	for (int i = 6; i > location; i--){
		seq[i] = seq[i - 1];
	}
	seq[location] = n;
}

bool IsSuccess(int a, int b, int c, int seq[], UIDesign ui)
{
	for (int i = 0; i < 6; i++)
		if (seq[i] < seq[i + 1])
			return false;

	if (a * b == 0 && a * c == 0 && b * c == 0){
		ui.Print("Congratulation!");
		ui.Print("You made it!");
		return true;
	}
	else
		return false;
}

void Process(UIDesign ui, int num, std::string str, int seq[], bool success, int steps)
{
	ui.Print("How many plates do you want to play?");
	ui.Input(std::cin, str);
	num = std::atoi(str.c_str());
	std::cout << std::endl;
	int num_temp = num;
	for (int i = 0; i < num; i++){
		seq[i] = num_temp;
		num_temp--;
	}

	ui.Draw(0, "", "", num, 0, 0, seq);
	
	int a = num, b = 0, c = 0;

	while (!success){
		bool is_available = false;
		std::string res;
		std::string des;

		while (!is_available){
			std::cout << "\n";
			ui.Print("What's your next move?");
			ui.Input(std::cin, str);
			res = str;
			ui.Input(std::cin, str);
			des = str;

			is_available = IsAvailable(res, des, a, b, c, seq, ui);
		}

		int temp = 0;
		if (res == "A" || res == "a"){
			temp = seq[a - 1];
			DelNum(seq, a - 1);
			a--;
		}
		else if (res == "B" || res == "b"){
			temp = seq[a + b - 1];
			DelNum(seq, a + b - 1);
			b--;
		}
		else if (res == "C" || res == "c"){
			temp = seq[a + b + c - 1];
			DelNum(seq, a + b + c - 1);
			c--;
		}

		if (des == "A" || des == "a"){
			InsNum(seq, a, temp);
			a++;
		}
		else if (des == "B" || des == "b"){
			InsNum(seq, a + b, temp);
			b++;
		}
		else if (des == "C" || des == "c"){
			InsNum(seq, a + b + c, temp);
			c++;
		}
		steps++;
		std::cout << "\n";
		ui.Draw(steps, res, des, a, b, c, seq);
		std::cout << "\n";
		success = IsSuccess(a, b, c, seq, ui);
	}
}

bool IsAvailable(std::string res, std::string des, int a, int b, int c, int seq[], UIDesign ui)
{
	//柱子a, b, c分别有各自的数组，存着各自柱子上的盘子大小
	int a_array[7] = { 0 };
	int b_array[7] = { 0 };
	int c_array[7] = { 0 };

	if (a != 0)
		for (int i = 0; i < a; i++)
			a_array[i] = seq[i];

	if (b != 0)
		for (int i = 0; i < b; i++)
			b_array[i] = seq[a + i];

	if (c != 0)
		for (int i = 0; i < c; i++)
			c_array[i] = seq[a + b + i];

	int temp = 0;
	if (res == "A" || res == "a"){
		if (a_array[0] == 0){
			ui.Print("Sorry! There is no plate!");
			return false;
		}
		else{
			temp = a_array[a - 1];
			a--;
		}
	}
	else if (res == "B" || res == "b"){
		if (b_array[0] == 0){
			ui.Print("Sorry! There is no plate!");
			return false;
		}
		else{
			temp = b_array[b - 1];
			b--;
		}
	}
	else if (res == "C" || res == "c"){
		if (c_array[0] == 0){
			ui.Print("Sorry! There is no plate!");
			return false;
		}
		else{
			temp = c_array[c - 1];
			c--;
		}
	}

	if (des == "A" || des == "a"){
		if (a_array[0] != 0 && a_array[a - 1] < temp){
			ui.Print("Sorry! Big plate can't place on the top of the small one.");
			return false;
		}
	}
	else if (des == "B" || des == "b"){
		if (b_array[0] != 0 && b_array[b - 1] < temp){
			ui.Print("Sorry! Big plate can't place on the top of the small one.");
			return false;
		}
	}
	else if (des == "C" || des == "c"){
		if (c_array[0] != 0 && c_array[c - 1] < temp){
			ui.Print("Sorry! Big plate can't place on the top of the small one.");
			return false;
		}
	}
	return true;
}