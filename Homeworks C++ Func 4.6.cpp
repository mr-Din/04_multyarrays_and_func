#include "Header.h"

/*
Число называется совершенным, если сумма всех его делителей равна ему самому.
Напишите функцию поиска таких чисел во введенном интервале.
*/

void GetPerfectNumbers(int a, int b) {
	for (int i = a; i < b; ++i) {
		// Проверяем i на совершентсво
		int divisor = 1;
		int perfectNumber = 0;
		while (divisor <= i / 2) {
			if (i % divisor == 0) {
				perfectNumber += divisor;
			}
			++divisor;
		}
		if (perfectNumber == i && perfectNumber!=0) {
			cout << perfectNumber << endl;
		}
		
	}
}

// проверка, високосный ли год
bool YearIsLeap(const int& year) {
	/*if (year % 400 == 0) {
		return true;
	}
	else if (year % 100 == 0) {
		return false;
	}
	else if (year % 4 == 0) {
		return true;
	}
	else return false;*/
	return !(year % 4 || (!(year % 100) && year % 400));
}

int DifferenceOfDatesInDays(int day1, int month1, int year1,
	int day2, int month2, int year2) {
	if (day1 > 31 || day1 < 1 || day2>31 || day2 < 1
		|| month1>12 || month1 < 1 || month2>12 || month2 < 1
		|| year1 > year2 || (year1 == year2 && month1 > month2)) {
		cout << "Переданные данные некорректные!\n";
		return 0;
	}
	--month1; --month2;
	const int days_of_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	// вычисляем количество дней для указанной даты
	int days1 = 0;
	for (int i = 0; i < month1; i++) {
		if (YearIsLeap(year1) && i == 1) {
			days1 += days_of_month[i]+1;
		}
		else {
			days1 += days_of_month[i];
		}
	}
	days1 += day1;
	int days2 = 0;
	for (int i = 0; i < month2; i++) {
		if (YearIsLeap(year2) && i == 1) {
			days2 += days_of_month[i] + 1;
		}
		else {
			days2 += days_of_month[i];
		}
	}
	days2 += day2;

	int difference = days2-days1;
	for (int i = year1; i < year2; i++) {
		if (YearIsLeap(i)) {
			difference += 366;
		}
		else {
			difference += 365;
		}
	}
	return difference;
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	//GetPerfectNumbers(0, 8200);
	cout << YearIsLeap(1600) << endl;
	cout << YearIsLeap(1700) << endl;
	cout << YearIsLeap(1800) << endl;
	cout << YearIsLeap(1900) << endl;
	cout << YearIsLeap(2020) << endl;

	int res = DifferenceOfDatesInDays(1, 2, 2000, 1, 2, 2004);
	cout << res << endl;



	return 0;
}