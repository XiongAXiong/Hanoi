#ifndef UI_DESIGN_H_
#define UI_DESIGN_H_

#include <string>
#include <iostream>

class UIDesign
{
public:
	UIDesign();
	UIDesign(std::string title);
	~UIDesign();

	void InitUI() const;
	void Print(std::string str) const;
	void Input(std::istream &cin, std::string &str) const;
	void Draw(int steps, std::string res, std::string des, int a, int b, int c, int seq[]) const;

private:
	std::string title_;
	int width_;
	int margin_;
};

#endif