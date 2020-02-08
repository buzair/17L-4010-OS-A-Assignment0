#include<iostream>
#include <stdlib.h> 
#include<fstream>
#include<cstring>
using namespace std;

int containVowel(char* buff)
{
	int n = strlen(buff);
	int ans = 0, i;
	for (i = 0; i<n; i++)
	{
		if (buff[i] == 'u' || buff[i] == 'o' || buff[i] == 'i' || buff[i] == 'e' || buff[i] == 'a')
		{
			ans = 1;
			break;
		}
	}
	return ans;
}

char* invert(char* buff)
{
	int n = strlen(buff), i;
	char c;
	for (i = 0; i<n / 2; i++)
	{
		c = buff[i];
		buff[i] = buff[n - 1 - i];
		buff[n - 1 - i] = c;
	}
	return buff;
}
int main(int argc, char *arg[])
{
	ofstream fout("q3Output.txt");
	char word[30];
	ifstream fin(arg[1]);
	if (fin.is_open() && fout.is_open())
	{
		while (!fin.eof())
		{
			fin >> word;
			if (containVowel(word) == 0)
			{
				invert(word);
			}
			fout << word << " ";
		}
		fin.close();
		fout.close();
	}
	else
	{
		cout << "Error in Opening File";
	}
}
