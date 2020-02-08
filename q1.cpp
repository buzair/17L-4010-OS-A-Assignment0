#include<iostream>
#include <stdlib.h> 
#include<fstream>
using namespace std;
int main(int argc, char *arg[])
{
	int count = 0;
	char s;
	ifstream fin(arg[1]);
	if (fin.is_open())
	{
		while(fin.get(s), !fin.eof())
		{
			if (s>47 && s<58)
			{
				count++;
			}
		}
		cout << "The number of digits in file are " << count;
		fin.close();
	}
	else
	{
		cout << "Error in Opening File";
	}
}