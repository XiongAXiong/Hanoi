#include <iostream>
#include "hanoi.h"

Hanoi::Hanoi() : UserInterface("Tower of Hanoi Game")
{

}

Hanoi::~Hanoi()
{

}

void Hanoi::HanoiProcess(unsigned int n, std::string A, std::string B, std::string C)
{
	if (n == 1)
		Draw(A, C);
	else{
		HanoiProcess(n - 1, A, C, B);
		Draw(A, C);
		HanoiProcess(n - 1, B, A, C);
	}
}

void Hanoi::InitParams(unsigned int n)
{
	if (n > kPlatesMaxNumber){
		std::cerr << "**ERROR: 初始化盘子数失败，不允许超过" << kPlatesMaxNumber << ", InitParams(unsigned int n)";
		while (1);
	}

	for (unsigned int i = 0; i < kPlatesMaxNumber; i++)
		seq[i] = 0;

	unsigned int temp = n;
	for (unsigned int i = 0; i < n; i++){
		seq[i] = temp;
		temp--;
	}
	steps_ = 0;
	a_num_ = n;
	b_num_ = 0;
	c_num_ = 0;
}

void Hanoi::DrawLine(unsigned int a_width, unsigned int b_width, unsigned int c_width)
{
	for (unsigned int i = 0; i < (kAPoint - a_width); i++)
		std::cout << " ";

	if (a_width == 0)
		std::cout << kPillarSymbol;
	else if (a_width == (kPlatesMaxNumber + 1))
		for (unsigned int i = 0; i < (a_width * 2 + 1); i++)
			std::cout << kPillarSymbol;
	else
		for (unsigned int i = 0; i < (a_width * 2 + 1); i++)
			std::cout << kPlateSymbol;

	for (unsigned int i = 0; i < (kBPoint - kAPoint - a_width - b_width - 1); i++)
		std::cout << " ";

	if (b_width == 0)
		std::cout << kPillarSymbol;
	else if (a_width == (kPlatesMaxNumber + 1))
		for (unsigned int i = 0; i < (a_width * 2 + 1); i++)
			std::cout << kPillarSymbol;
	else
		for (unsigned int i = 0; i < (b_width * 2 + 1); i++)
			std::cout << kPlateSymbol;

	for (unsigned int i = 0; i < (kCPoint - kBPoint - c_width - b_width - 1); i++)
		std::cout << " ";

	if (c_width == 0)
		std::cout << kPillarSymbol;
	else if (a_width == (kPlatesMaxNumber + 1))
		for (unsigned int i = 0; i < (a_width * 2 + 1); i++)
			std::cout << kPillarSymbol;
	else
		for (unsigned int i = 0; i < (c_width * 2 + 1); i++)
			std::cout << kPlateSymbol;
	std::cout << std::endl;
}

void Hanoi::Draw(std::string res, std::string des)
{
	//柱子a, b, c分别有各自的数组，存着各自柱子上的盘子大小
	int a_array[kPlatesMaxNumber] = { 0 };
	int b_array[kPlatesMaxNumber] = { 0 };
	int c_array[kPlatesMaxNumber] = { 0 };

	int temp = 0;
	if (res == "A" || res == "a"){
		temp = seq[a_num_ - 1];
		DelNum(a_num_ - 1);
		a_num_--;
	}
	else if (res == "B" || res == "b"){
		temp = seq[a_num_ + b_num_ - 1];
		DelNum(a_num_ + b_num_ - 1);
		b_num_--;
	}
	else if (res == "C" || res == "c"){
		temp = seq[a_num_ + b_num_ + c_num_ - 1];
		DelNum(a_num_ + b_num_ + c_num_ - 1);
		c_num_--;
	}

	if (des == "A" || des == "a"){
		InsNum(a_num_, temp);
		a_num_++;
	}
	else if (des == "B" || des == "b"){
		InsNum(a_num_ + b_num_, temp);
		b_num_++;
	}
	else if (des == "C" || des == "c"){
		InsNum(a_num_ + b_num_ + c_num_, temp);
		c_num_++;
	}

	if (a_num_ != 0)
		for (unsigned int i = 0; i < a_num_; i++)
			a_array[i] = seq[i];

	if (b_num_ != 0)
		for (unsigned int i = 0; i < b_num_; i++)
			b_array[i] = seq[a_num_ + i];

	if (c_num_ != 0)
		for (unsigned int i = 0; i < c_num_; i++)
			c_array[i] = seq[a_num_ + b_num_ + i];

	for (unsigned int i = 0; i < kWidth; i++)
		std::cout << kBorderSymbol;
	std::cout << "\n";

	for (unsigned int i = 0; i < kPrefixLength; i++)
		std::cout << " ";

	for (auto &c : res)
		c = toupper(c);
	for (auto &c : des)
		c = toupper(c);

	if (res != "" && des != "")
		std::cout << "Step " << steps_ << ".  " << res << " -> " << des << std::endl;
	else
		std::cout << "Step " << steps_ << ".  " << std::endl;
	steps_++;

	DrawLine(0, 0, 0);
	for (unsigned int j = 0; j < 7; j++)
		DrawLine(a_array[6 - j], b_array[6 - j], c_array[6 - j]);
	DrawLine(kPlatesMaxNumber + 1, kPlatesMaxNumber + 1, kPlatesMaxNumber + 1);

	for (unsigned int i = 0; i < (kAPoint); i++)
		std::cout << " ";
	std::cout << "A";
	for (unsigned int i = 0; i < (kBPoint - kAPoint - 1); i++)
		std::cout << " ";
	std::cout << "B";
	for (unsigned int i = 0; i < (kCPoint - kBPoint - 1); i++)
		std::cout << " ";
	std::cout << "C" << std::endl;

	for (unsigned int i = 0; i < kWidth; i++)
		std::cout << kBorderSymbol;
	std::cout << "\n";
}

void Hanoi::DelNum(unsigned int n)
{
	for (unsigned int i = n; i < (kPlatesMaxNumber - 1); i++){
		seq[i] = seq[i + 1];
	}
	seq[kPlatesMaxNumber - 1] = 0;
}

void Hanoi::InsNum(unsigned int location, unsigned int n)
{
	for (unsigned int i = (kPlatesMaxNumber - 1); i > location; i--){
		seq[i] = seq[i - 1];
	}
	seq[location] = n;
}

bool Hanoi::IsSuccess()
{
	for (unsigned int i = 0; i < (kPlatesMaxNumber - 1); i++)
		if (seq[i] < seq[i + 1])
			return false;

	if (a_num_ * b_num_ == 0 && a_num_ * c_num_ == 0 && b_num_ * c_num_ == 0){
		Print("Congratulation!");
		Print("You made it!");
		return true;
	}
	else
		return false;
}

bool Hanoi::IsAvailable(std::string res, std::string des)
{
	//柱子a, b, c分别有各自的数组，存着各自柱子上的盘子大小
	int a_array[kPlatesMaxNumber] = { 0 };
	int b_array[kPlatesMaxNumber] = { 0 };
	int c_array[kPlatesMaxNumber] = { 0 };
	unsigned int a_num = a_num_;
	unsigned int b_num = b_num_;
	unsigned int c_num = c_num_;

	if (a_num != 0)
		for (unsigned int i = 0; i < a_num; i++)
			a_array[i] = seq[i];

	if (b_num != 0)
		for (unsigned int i = 0; i < b_num; i++)
			b_array[i] = seq[a_num + i];

	if (c_num != 0)
		for (unsigned int i = 0; i < c_num; i++)
			c_array[i] = seq[a_num + b_num + i];

	int temp = 0;
	if (res == "A" || res == "a"){
		if (a_array[0] == 0){
			Print("Sorry! There is no plate!");
			return false;
		}
		else{
			temp = a_array[a_num - 1];
			a_num--;
		}
	}
	else if (res == "B" || res == "b"){
		if (b_array[0] == 0){
			Print("Sorry! There is no plate!");
			return false;
		}
		else{
			temp = b_array[b_num - 1];
			b_num--;
		}
	}
	else if (res == "C" || res == "c"){
		if (c_array[0] == 0){
			Print("Sorry! There is no plate!");
			return false;
		}
		else{
			temp = c_array[c_num - 1];
			c_num--;
		}
	}

	if (des == "A" || des == "a"){
		if (a_array[0] != 0 && a_array[a_num - 1] < temp){
			Print("Sorry! Big plate can't place on the top of the small one.");
			return false;
		}
	}
	else if (des == "B" || des == "b"){
		if (b_array[0] != 0 && b_array[b_num - 1] < temp){
			Print("Sorry! Big plate can't place on the top of the small one.");
			return false;
		}
	}
	else if (des == "C" || des == "c"){
		if (c_array[0] != 0 && c_array[c_num - 1] < temp){
			Print("Sorry! Big plate can't place on the top of the small one.");
			return false;
		}
	}
	return true;
}

void Hanoi::UserProcess(int num)
{
	Draw("", "");

	bool success = false;
	while (!success){
		bool is_available = false;
		std::string res;
		std::string des;

		while (!is_available){
			std::string str;
			std::cout << "\n";
			Print("What's your next move from?");
			Input(str);
			while (str != "A" && str != "a" && str != "B" && str != "b" && str != "C" && str != "c"){
				Print("Please enter A, B or C!");
				Input(str);
			}
			res = str;

			Print("What's your next move to?");
			Input(str);
			while (str != "A" && str != "a" && str != "B" && str != "b" && str != "C" && str != "c"){
				Print("Please enter A, B or C!");
				Input(str);
			}
			des = str;

			is_available = IsAvailable(res, des);
		}

		Draw(res, des);
		success = IsSuccess();
	}
}
