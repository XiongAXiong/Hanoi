#include <iostream>
#include <string>

#include "user_interface.h"

UserInterface::UserInterface()
{
	title_ = "(No Title)"; 
}

UserInterface::UserInterface(std::string title)
{
	title_ = title;
	if (title.size() > (kWidth - kMargin)){
		std::cerr << "**ERROR: 标题设置过长，不允许超过" << (kWidth - kMargin) << ", @UserInterface(std::string title)";
		while (1);
	}
}

UserInterface::~UserInterface()
{

}

void UserInterface::InitUI()
{
	std::string name = "Designer: " + kAuthorName;
	std::string email = "(" + kAuthorEmail + ")";

	//先定框体长度body_length_：选出name，email，title中最长字符串的长度，再加点余量
	body_length_ = MaxStrLength(name, email, title_) + kMargin;

	//再算出margin_left_的长度
	margin_left_ = (kWidth - body_length_) / 2;

	//打印框体
	PrintBorder();
	PrintBlank();
	PrintStr(title_);
	PrintBlank();
	PrintStr(name);
	PrintStr(email);
	PrintBlank();
	PrintBorder();

	//打印欢迎语句
	std::cout << "\n";
	std::string hello = "Welcome to " + title_;
	unsigned int n = (kWidth - hello.size()) / 2;
	for (unsigned int i = 0; i < n; i++)
		std::cout << " ";
	std::cout << hello << std::endl;
}

void UserInterface::Print(std::string str) const
{
	std::cout << ">>> " << str << std::endl;
}

void UserInterface::Input(std::string &str) const
{
	std::cout << ">>> ";
	std::cin >> str;
}

void UserInterface::PrintBlank()
{
	for (unsigned int i = 0; i < margin_left_; i++)
		std::cout << " ";
	std::cout << kSymbol << kSymbol;
	for (unsigned int i = 0; i < (body_length_ - kSymbol.size() * 4); i++)
		std::cout << " ";
	std::cout << kSymbol << kSymbol << std::endl;
}

void UserInterface::PrintStr(std::string str)
{
	for (unsigned int i = 0; i < margin_left_; i++)
		std::cout << " ";
	std::cout << kSymbol << kSymbol;

	unsigned int margin = (body_length_ - kSymbol.size() * 4 - str.size()) / 2;

	for (unsigned int i = 0; i < margin; i++)
		std::cout << " ";
	std::cout << str;
	for (unsigned int i = 0; i < (body_length_ - kSymbol.size() * 4 - str.size() - margin); i++)
		std::cout << " ";
	std::cout << kSymbol << kSymbol << std::endl;
}

void UserInterface::PrintBorder()
{
	for (unsigned int i = 0; i < margin_left_; i++)
		std::cout << " ";
	for (unsigned int i = 0; i < body_length_; i++)
		std::cout << kSymbol;
	std::cout << std::endl;
}

unsigned int UserInterface::MaxStrLength(std::string a, std::string b, std::string c) const
{
	unsigned int temp = a.size() > b.size() ? a.size() : b.size();
	return (temp > c.size() ? temp : c.size());
}
