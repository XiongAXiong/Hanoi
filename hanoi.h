#ifndef HANOI_H_
#define HANOI_H_

#include "user_interface.h"

const unsigned int kPlatesMaxNumber = 7;

class Hanoi : public UserInterface
{
public:
	Hanoi();
	~Hanoi();
	
	void Hanoi::HanoiProcess(unsigned int n, std::string A, std::string B, std::string C);
	void Hanoi::UserProcess(int num);
	void InitParams(unsigned int n);
	void Draw(std::string res, std::string des);
	
private:
	unsigned int seq[kPlatesMaxNumber];
	unsigned int steps_;
	unsigned int a_num_;
	unsigned int b_num_;
	unsigned int c_num_;
	
	void DrawLine(unsigned int a_width, unsigned int b_width, unsigned int c_width);
	void DelNum(unsigned int n);
	void InsNum(unsigned int location, unsigned int n);
	bool IsAvailable(std::string res, std::string des);
	bool IsSuccess();
	
	const std::string kPlateSymbol = "#";
	const std::string kPillarSymbol = "*";
	const std::string kBorderSymbol = "-";
	const unsigned int kAPoint = 11;
	const unsigned int kBPoint = 30;
	const unsigned int kCPoint = 49;
};

#endif