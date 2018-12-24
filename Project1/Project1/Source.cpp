//yitzchak ravitz 204108609	
//meir kalman 312246606

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <functional>
#include "BTR.cpp"
#include "Treatment.h"

using namespace std;
//the program implements the B trees.The program implements a system for queuing, the tree will be sorted by date.
//=============================================================
void main()
{

	char ch;
	BTree<Treatment> bt;
	vector<string> physicians;
	Treatment tr, tr2;
	string str, str2;
	vector<Treatment> keys;
	Treatment *p;

	cout << "\nChoose one of the following" << endl;
	cout << "1: add a new Physician" << endl;
	cout << "2: add an open date and time for a physician" << endl;
	cout << "3: add a new Appointment " << endl;
	cout << "4: print patient calendar " << endl;
	cout << "5: print physician calendar " << endl;
	cout << "6: print date reminders" << endl;
	cout << "7: exit:" << endl;
	do
	{
		cin >> ch;

		switch (ch)
		{
		case '1':
			cout << "Enter physician name ";
			cin >> str;
			physicians.push_back(str);
			break;
		case '2':cin >> tr;
			if (std::find(physicians.begin(), physicians.end(), tr.getPhysician()) == physicians.end())
				cout << "ERROR" << endl;
			else
				bt.insert(tr);
			break;
		case '3':
			cin >> tr; //fix a new treatment. read treatment details.
			p = bt.search(tr);
			if (p == NULL)
				cout << "ERROR" << endl;
			else
			{
				cout << "Enter patient name ";
				cin >> str;

				if (p->getPatient() != "")
					cout << "USED" << endl;
				else
				{
					p->setPatient(str);
					cout << "treatement for " << str << " fixed at " << p->getDate() << " time " << p->getTime() << endl;
				}
			}
			break;
		case '4':cout << "Enter patient name ";
			cin >> str;
			bt.printAllKeys([str](Treatment a) {return (a.getPatient() == str); });
			break;
		case '5':cout << "Enter physician name ";
			cin >> str;
			bt.printAllKeys([str](Treatment a) {return (a.getPhysician() == str && a.getPatient() != ""); });
			break;
		case '6':cout << "Enter date ";
			cin >> str;
			bt.printAllKeys([str](Treatment a) {return (a.getDate() == str && a.getPatient() != ""); });
			break;
		case '7':cout << "bye "; break;
		default: cout << "error ";  break;
		}//switch
	} while (ch != '7');

}