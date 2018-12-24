//yitzchak ravitz 204108609	
//meir kalman 312246606

#include "Treatment.h"



Treatment::Treatment()
{
}

Treatment::Treatment(string physician1, string patient1, string date1, string time1)//constractor
{
	physician = physician1;
	patient = patient1;
	date = date1;
	time = time1;
}


Treatment::~Treatment()
{
}

bool Treatment::operator==(Treatment & a)//operator ==
{
	if (physician == a.physician && date == a.date && time == a.time)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Treatment::operator<(Treatment & const a)//operator < (Where we will need >= we will use !<)
{
	int year1 = stoi(date.substr(0, 4));
	int	year2 = stoi(a.getDate().substr(0, 4));
	int	month1 = stoi(date.substr(5, 7));
	int month2 = stoi(a.getDate().substr(5, 7));
	int	day1 = stoi(date.substr(8));
	int	day2 = stoi(a.getDate().substr(8));
	int time1 = stoi(time);
	int time2 = stoi(a.time);	//The program checks who is bigger by year and then month, day, time, and at 
	if (year1 > year2)			//the end if everything is equal by the doctor
	{
		return false;
	}
	if (year1 < year2)
	{
		return true;
	}
	if (month1 > month2)
	{
		return false;
	}
	if (month1 < month2)
	{
		return true;
	}
	if (day1 > day2)
	{
		return false;
	}
	if (day1 < day2)
	{
		return true;
	}
	if (time1 > time2)
	{
		return false;
	}
	if (time1 < time2)
	{
		return true;
	}
	if (physician > a.physician)
	{
		return false;
	}
	if (physician < a.physician)
	{
		return true;
	}
}
