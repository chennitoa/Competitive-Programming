/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: achenni1
TASK: friday
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
	int N;
	fin >> N;
	//Calc each day of the week by itself

	for (int i = 1; i <= 7; i++) {
		int month = 1;
		int dayCounter = (i + 5) % 7;
		int total = 0;
		bool yearPassed;
		bool leapYear;
		for (int j = 0; j < N; j++) {
			leapYear = false;
			if (j % 4 == 0) {
				if (j % 100 == 0) {
					if ((1900 + j) % 400 != 0) {
						leapYear = false;
					}
					else leapYear = true;
				}
				else leapYear = true;
			}
			while (yearPassed == false) {
				dayCounter += 7;
				if (dayCounter == 13) {
					total++;
				}
				if (dayCounter >= 28) {
					if (month == 2 && leapYear == false) {
						month++;
						dayCounter = dayCounter % 28;
					}
					else if (dayCounter >= 29) {
						if (month == 2) {
							month++;
							dayCounter = dayCounter % 29;
						}
						else if (dayCounter >= 30) {
							if (month == 4 || month == 6 || month == 9 || month == 11) {
								month++;
								dayCounter = dayCounter%30;
							}
							else if (dayCounter >= 31) {
								month++;
								dayCounter = dayCounter%31;
							}
						}
					}
				}
				if (month == 13) {
					month = 1;
					yearPassed = true;
				}
			}
			yearPassed = false;
		}
		fout << total;
		if (i != 7) fout << " ";
	}
	fout << "\n";
    return 0;
}