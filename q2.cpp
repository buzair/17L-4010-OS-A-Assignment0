#include<iostream>
#include <cstdlib> 
#include<fstream>
#include <string.h>
#include <istream>
#include <string>
using namespace std;
int main(int argc, char *arg[])
{
	char name[20] , roll[20],  email[20];

	int input;
	while(true)
	{
		cout << "Press 1 to add a record" << endl;
		cout << "Press 2 to search a record" << endl;
		cout << "Press 3 to delete a record" << endl;
		cout << "Press 0 to exit" << endl;
		cout << "Please Input your Choice: ";
		cin >> input;

		if (input==1)
		{
			ofstream fout("q2Output.txt", fstream::app);
			if (fout.is_open())
			{
				cout << "Enter Name: ";
				cin >> name;
				cout << "Enter Roll: ";
				cin >> roll;
				cout << "Enter Email: ";
				cin >> email;
				fout << name << " " << roll << " " << email << "," << endl;
				fout.close();
				
			}
			else
			{
				cout << "Error Opening File";
			}
			
		}

		else if (input==2)
		{
			bool found = false;
			ifstream fin("q2Output.txt");
			string rolltosearch, buffer;
			cout << "Input Roll to search: ";
			cin >> rolltosearch;

			if (fin.is_open())
			{
				while (getline(fin, buffer))
				{
					if (buffer.find(rolltosearch) != string::npos)
					{
						cout << endl <<  buffer << "\n" << endl;
						found = true;
						break;
					}
				}
				if (found == false)
				{
					cout << "Record does not exist!" << endl << endl;
				}
				fin.close();
			}
			else
			{
				cout << "Error Opening File" << endl;
			}
			
		}

		else if (input == 3)
		{
			//bool found = true;
			//int flag = 1;
			string rolltf;
			cout << "Enter Roll No: ";
			cin >> rolltf; 
			ifstream fin("q2Output.txt");
			ofstream fout("tmp.txt");
			if (fin.is_open())
			{
				string line;
				while (getline(fin, line))
				{
					if (!(line.find(rolltf) != std::string::npos))
					{
						fout << line << endl;
						//flag = 0;
					}
				}
				/*if (flag == 0)
				{
					cout << "Enter Valid Roll No!" << endl;
				}*/
				fin.close();
				fout.close();
				remove("q2Output.txt");
				rename("tmp.txt", "q2Output.txt");
			}
			else
			{
				cout << "Error Opening File";
			}
			/*string line;
			read.open("q2Output.txt");
			if (read.is_open())
			{
				cout << "Remains:";
				while (getline(read, line))
				{
					cout << line << endl;
				}
			}
			read.close();*/
		}
		else if (input==0)
		{
			break;
		}
		else
		{
			cout << "Input Valid Choice" << endl;
		}
		//system("cls");
	}
}

