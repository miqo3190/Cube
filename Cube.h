#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

class Cube
{
public:
	void inputText();
	void divideText(); 
	void checkText();
	void show();
	void turnRight(int);
	void turnLeft(int);
	void turnUp(int);
	void turnDown(int);
	void inputKey();
	void checkKey(int);
	void encryption();
	void decryption();
private:
	std::string mText;
	std::string mDivideText;
	const int topsOfNumbers = 8;
	std::vector<std::string> mDivideVec;
	int residual;
	std::string key;
	std::string keySave;

};

