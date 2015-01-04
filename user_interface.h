#ifndef USER_INTERFACE_H_
#define USER_INTERFACE_H_

#include <string>

class UserInterface
{
public:
	UserInterface();
	UserInterface(std::string title);
	~UserInterface();

	void InitUI();
	void Print(std::string str) const;
	void Input(std::string &str) const;

protected:
	const unsigned int kWidth = 60;
	const unsigned int kPrefixLength = 3;

private:
	std::string title_;
	unsigned int margin_left_;
	unsigned int body_length_;

	const unsigned int kMargin = 12;
	const std::string kAuthorName = "Yueyang Song";
	const std::string kAuthorEmail = "yueyangsong@foxmail.com";
	const std::string kSymbol = "#";

	void PrintBlank();
	void PrintStr(std::string str);
	void PrintBorder();
	unsigned int MaxStrLength(std::string a, std::string b, std::string c) const;
};

#endif
