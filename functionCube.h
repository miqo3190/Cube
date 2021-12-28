#include "Cube.h"

void Cube::inputText()
{
	std::cout << "Please enter the text you want to encrypt : \n";
	getline(std::cin, mText);
}

void Cube::divideText()
{
	int first = 0;
	int second = topsOfNumbers;
	for (int i = 0; i < (mText.size()/topsOfNumbers); i++)
	{
		for (int j = first; j < second; j++)
		{
			mDivideText.push_back(mText[j]);
		}
		first += topsOfNumbers;
		second += topsOfNumbers;
		mDivideVec.push_back(mDivideText);
		mDivideText.clear();
	}
}

void Cube::encryption()
{
	inputText();
	checkText();
	divideText();
	inputKey();
	show();
}

void Cube::decryption()
{
	inputKey();
	show();
}

void Cube::checkText()
{
	if (mText.size() % topsOfNumbers != 0)
	{
		residual = mText.size() % topsOfNumbers;
		for (int i = 0; i < topsOfNumbers - residual; i++)
		{
			mText.push_back(' ');
		}
	}
}

void Cube::turnUp(int index)
{
	std::rotate(mDivideVec[index].begin(), mDivideVec[index].begin() + 6, mDivideVec[index].end());
}

void Cube::turnDown(int index)
{
	std::rotate(mDivideVec[index].begin(), mDivideVec[index].begin() + 2, mDivideVec[index].end());
}

void Cube::turnRight(int index)
{
	std::swap(mDivideVec[index][0], mDivideVec[index][6]);
	std::swap(mDivideVec[index][6], mDivideVec[index][7]);
	std::swap(mDivideVec[index][1], mDivideVec[index][7]);
	std::swap(mDivideVec[index][2], mDivideVec[index][4]);
	std::swap(mDivideVec[index][3], mDivideVec[index][4]);
	std::swap(mDivideVec[index][4], mDivideVec[index][5]);
}

void Cube::turnLeft(int index)
{
	std::swap(mDivideVec[index][0], mDivideVec[index][1]);
	std::swap(mDivideVec[index][1], mDivideVec[index][7]);
	std::swap(mDivideVec[index][2], mDivideVec[index][3]);
	std::swap(mDivideVec[index][3], mDivideVec[index][5]);
	std::swap(mDivideVec[index][4], mDivideVec[index][5]);
	std::swap(mDivideVec[index][6], mDivideVec[index][7]);
}

void Cube::inputKey()
{
	std::cout << "\n Enter please key: \n";
	for (int i = 0; i < mDivideVec.size(); i++)
	{
		std::cout << (i + 1);
		std::cin >> key;
		keySave.push_back(i + 1);
		for (int j = 0; j < key.size(); j++)
		{
			if(key[j] == 'U') keySave.push_back('D');
			if(key[j] == 'R') keySave.push_back('L');
			if(key[j] == 'D') keySave.push_back('U');
			if(key[j] == 'L') keySave.push_back('R');
		}
		checkKey(i);
	}
}

void Cube::checkKey(int index)
{
	for (int j = 0; j < key.size(); j++)
	{
		if (key[j] == 'U')
		{
			turnUp(index);
		}
		if (key[j] == 'D')
		{
			turnDown(index);
		}
		if (key[j] == 'R')
		{
			turnRight(index);
		}
		if (key[j] == 'L')
		{
			turnLeft(index);
		}
	}
	key.clear();
}

void Cube::show()
{
	for (int i = 0; i < mDivideVec.size(); i++)
	{
		std::cout << mDivideVec[i];
	}
}

