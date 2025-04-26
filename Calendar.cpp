// Calendar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

static void getMounth(int year, int mounth) {
    /*
    получить год
    рассчитать начало года
    получить месяц
    рассчитать начало месяца
    распечатать месяц
    */
    //не забывать про висоцосные года
    //не забывать про дни недели
    //например, февраль 1971: year = 1971, mounth = 2

    int days_numbers_in_mounth[12]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int days = 4;

    for (int i = 1970; i < year; i++) {
        days += 365;
        if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)) {
            days++;
        }
    }

    if (mounth == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
        days_numbers_in_mounth[1] = 29;
    }

    for (int i = 1; i < mounth; i++) {
        days += days_numbers_in_mounth[i - 1];
    }

    int first_day_of_week_in_mounth = days % 7;

    //cout << "first day in mount: " << first_day_of_week_in_mounth << endl;

    int day_of_week = first_day_of_week_in_mounth;

    for (int i = 0; i < day_of_week; i++) {
        cout << "  ";
    }

    for (int i = 1; i <= days_numbers_in_mounth[mounth - 1]; i++) {
        if (day_of_week <= 7) {
            if (i >= 10) {
                cout << i << " ";
            }
            else {
                cout << " " << i << " ";
            }
        }
        else {
            if (i >= 10) {
                cout << endl << i << " ";
            }
            else {
                cout << endl << " " << i << " ";
            }
            day_of_week -= 7;
        }

        day_of_week++;
    }
}

int main()
{

    int years[131] {0};

    for (int i = 1970; i < 2101; i++) {
        years[i-1970] = i;
    }

    cout << "Enter a year between 1970 and 2100" << endl;
    string year_string;
    cin >> year_string;
    int year = stoi(year_string);

    if (year < 1970 || year > 2100) {
        cout << "Invalid year" << endl;
        return 0;
    }

    cout << "Enter mounth number" << endl;
    string mouth_number_string;
    cin >> mouth_number_string;
    int mouth_number = stoi(mouth_number_string);

    if (mouth_number < 1 || mouth_number > 12) {
        cout << "Invalid mounth" << endl;
        return 0;
    }
 
    getMounth(year, mouth_number);
}


