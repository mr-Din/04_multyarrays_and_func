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

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	GetPerfectNumbers(0, 8200);
	



	return 0;
}