//yitzchak ravitz 204108609	
//meir kalman 312246606

#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <functional>
using namespace std;
class Treatment
{
public:
	string physician;
	string patient;
	string date;
	string time;
	Treatment();
	Treatment(string physician1, string patient1, string date1, string time1);
	~Treatment();
	void setPhysician(string a) { physician = a; }
	void setPatient(string a) { patient = a; }
	void setDate(string a) { date = a; }
	void setTime(string a) { time = a; }
	string getPhysician() { return physician; }
	string getPatient() { return patient; }
	string getDate() { return date; }
	string getTime() { return time; }

	bool operator == (Treatment & a);
	bool operator < (Treatment & const a);
	friend istream&operator>>(istream& is, Treatment& t)//operator>>
	{
		cout << "Enter physician year-month-day hour ";
		is >> t.physician >> t.date >> t.time;
		t.patient = string("");
		return is;
	}
	friend ostream&operator<<(ostream& os, Treatment& t)//operator<<
	{
		os << "Treatement details: physician: " << t.physician << " patient: " << t.patient << " date: " << t.date << "," << t.time << endl;
		return os;
	}

};