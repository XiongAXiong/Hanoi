#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "ui_design.h"

UIDesign::UIDesign()
{
	title_ = "Hello world!";
	width_ = 60;
	margin_ = 3;
}

UIDesign::UIDesign(std::string title)
{
	title_ = title;
	width_ = 60;
	margin_ = 3;
}

UIDesign::~UIDesign()
{

}

void UIDesign::InitUI() const
{
	std::string name = "Designer: Yueyang Song";
	std::string email = "(yueyangsong@foxmail.com)";


	for (int i = 0; i < width_; i++)
		std::cout << "*";
	std::cout << "\n" << std::endl;

	int blank_num = (width_ - title_.size()) / 2;
	for (int i = 0; i < blank_num; i++)
		std::cout << " ";
	std::cout << title_ << "\n" << std::endl;

	blank_num = (width_ - name.size()) / 2;
	for (int i = 0; i < blank_num; i++)
		std::cout << " ";
	std::cout << name << std::endl;

	blank_num = (width_ - email.size()) / 2;
	for (int i = 0; i < blank_num; i++)
		std::cout << " ";
	std::cout << email << std::endl;

	std::cout << "\n";
	for (int i = 0; i < width_; i++)
		std::cout << "*";
	std::cout << "\n" << std::endl;

	std::string hello = "Welcome to " + title_;
	blank_num = (width_ - hello.size()) / 2;
	for (int i = 0; i < blank_num; i++)
		std::cout << " ";
	std::cout << hello << "\n" << std::endl;
}

void UIDesign::Print(std::string str) const
{
	std::cout << ">>> " << str << std::endl;
}

void UIDesign::Input(std::istream &cin, std::string &str) const
{
	std::cout << ">>> ";
	cin >> str;
}

//参数a b c表示三个柱子上不同的盘子数目
//seq[]表示的是盘子大小的序列，由a下到a上，加上b下到b上，加上c下到c上
void UIDesign::Draw(int steps, std::string res, std::string des, int a, int b, int c, int seq[]) const
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

	for (int i = 0; i < width_; i++)
		std::cout << "-";
	std::cout << "\n";

	for (int i = 0; i < margin_; i++)
		std::cout << " ";

	for (auto &c : res)
		c = toupper(c);
	for (auto &c : des)
		c = toupper(c);

	if (res != "")
		std::cout << "Step " << steps << ".  " << res << " -> " << des << std::endl;
	else
		std::cout << "Step " << steps << ".  " << std::endl;

	//第一行
	for (int i = 0; i < margin_; i++)
		std::cout << " ";
	for (int i = 0; i < 8; i++)
		std::cout << " ";
	std::cout << "*";
	for (int i = 0; i < 18; i++)
		std::cout << " ";
	std::cout << "*";
	for (int i = 0; i < 18; i++)
		std::cout << " ";
	std::cout << "*" << std::endl;

	for (int j = 0; j < 7; j++){
		for (int i = 0; i < margin_; i++)
			std::cout << " ";
		for (int i = 0; i < (8 - a_array[6 - j]); i++)
			std::cout << " ";
		for (int i = 0; i < a_array[6 - j]; i++)
			std::cout << "#";

		if (a_array[6 - j] == 0)
			std::cout << "*";
		else
			std::cout << "#";

		for (int i = 0; i < a_array[6 - j]; i++)
			std::cout << "#";
		for (int i = 0; i < (8 - a_array[6 - j]); i++)
			std::cout << " ";

		std::cout << "  ";

		for (int i = 0; i < (8 - b_array[6 - j]); i++)
			std::cout << " ";
		for (int i = 0; i < b_array[6 - j]; i++)
			std::cout << "#";

		if (b_array[6 - j] == 0)
			std::cout << "*";
		else
			std::cout << "#";

		for (int i = 0; i < b_array[6 - j]; i++)
			std::cout << "#";
		for (int i = 0; i < (8 - b_array[6 - j]); i++)
			std::cout << " ";

		std::cout << "  ";

		for (int i = 0; i < (8 - c_array[6 - j]); i++)
			std::cout << " ";
		for (int i = 0; i < c_array[6 - j]; i++)
			std::cout << "#";

		if (c_array[6 - j] == 0)
			std::cout << "*";
		else
			std::cout << "#";

		for (int i = 0; i < c_array[6 - j]; i++)
			std::cout << "#";
		for (int i = 0; i < (8 - c_array[6 - j]); i++)
			std::cout << " ";

		std::cout << "\n";
	}
	//第九行
	for (int i = 0; i < margin_; i++)
		std::cout << " ";
	for (int i = 0; i < 17; i++)
		std::cout << "*";
	for (int i = 0; i < 2; i++)
		std::cout << " ";
	for (int i = 0; i < 17; i++)
		std::cout << "*";
	for (int i = 0; i < 2; i++)
		std::cout << " ";
	for (int i = 0; i < 17; i++)
		std::cout << "*";
	std::cout << std::endl;

	//第十行
	for (int i = 0; i < margin_; i++)
		std::cout << " ";
	for (int i = 0; i < 8; i++)
		std::cout << " ";
	std::cout << "A";
	for (int i = 0; i < 18; i++)
		std::cout << " ";
	std::cout << "B";
	for (int i = 0; i < 18; i++)
		std::cout << " ";
	std::cout << "C" << std::endl;

	for (int i = 0; i < width_; i++)
		std::cout << "-";
	std::cout << "\n";
}
