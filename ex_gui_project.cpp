// ex_gui_project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

void timer(string msg, char type);
void reminder();

int main()
{
	char type;
	cout << "If you want, \n Timer press 'T' \n Reminder press 'R'"<<endl;
	cin >> type;
	if (type == 'T' || type == 't') {
		string msg = "Time is up.....";
		timer(msg,'t');
	}
	else if(type == 'R' || type == 'r'){
		reminder();
	}
	else {
		cout << "Invalid Input. Please try again";
	}

}

void timer(string msg, char type){
	int h = 0, m = 0, s = 0, err = 0, t = 0;
	
	while (err == 0) {
		cout << "Enter your time...." << endl;
		cout << "Hours : ";
		cin >> h;
		cout << endl;
		cout << "Minutes  : ";
		cin >> m;
		cout << endl;
		cout << "Seconds : ";
		cin >> s;
		cout << endl;
		if (h < 24 && m < 60 && s < 60) {
			system("cls");
			cout << "Valid inputs... Clock start now..." << endl;
		}
		else {
			system("cls");
			cout << "Invald input... Please enter again...";
			err++;
		}

		t = h * 3600 + m * 60 + s;
		while (t > -1)
		{
			h = t / 3600;
			m = (t % 3600) / 60;
			s = (t % 3600) % 60;
			system("cls");
			cout << "Remaining Time =>";
			cout << h << " : " << m << " : " << s<< endl;
			t--;
			Sleep(900);
		}
		cout << msg<<endl;
		if (type == 'r')
			return;
		cout << "Try again( Y / N ) : ";
		char r;
		cin >> r;
		
		if (r == 'N' || r == 'n') {
			return;
		}
	}
}

void reminder() {
	string t;
	string msg;
	cout << "Enter your message : ";
	cin >> msg;
	timer(msg, 'r');
}