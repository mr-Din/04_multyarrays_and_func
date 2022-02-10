#include "Header.h"

/*
В двумерном массиве целых числе посчитать:
- Сумму всех элементов массива
- Среднее арифметическое всех элементов массива
- Минимальный элемент
- Максимальный элемент
*/



class Arr {
public:
	Arr(int a, int b) {
		a_ = a;
		b_ = b;
		arr_ = new int* [a];
		for (int i = 0; i < a; ++i) {
			arr_[i] = new int[b];
		}
	}
	Arr(int a, int b, int range) {
		a_ = a;
		b_ = b;
		arr_ = new int* [a];
		for (int i = 0; i < a; ++i) {
			arr_[i] = new int[b];
		}
		// заполнение случайными значениями
		for (int i = 0; i < a; ++i) {
			for (int j = 0; j < b; ++j) {
				//arr_[i][j] = rand() % (100 - (-100)) - 100;
				arr_[i][j] = rand() % range;
			}
		}
	}

	//Arr() {}
	// Конструктор копирования
	Arr (const Arr& array) {
		a_ = array.a_;
		b_ = array.b_;
		arr_ = new int* [array.a_];
		for (int i = 0; i < array.a_; ++i) {
			arr_[i] = new int[array.b_];
		}
		for (int i = 0; i < array.a_; ++i) {
			for (int j = 0; j < array.b_; ++j) {
				arr_[i][j] = array.arr_[i][j];
			}
		}

	}

	Arr& operator = (const Arr& array) {
		a_ = array.a_;
		b_ = array.b_;
		arr_ = new int* [array.a_];
		for (int i = 0; i < array.a_; ++i) {
			arr_[i] = new int[array.b_];
		}
		for (int i = 0; i < array.a_; ++i) {
			for (int j = 0; j < array.b_; ++j) {
				arr_[i][j] = array.arr_[i][j];
			}
		}
		return *this;
	}

	~Arr() {
		for (int i = 0; i < a_; ++i) {
			delete arr_[i];
		}
		delete[] arr_;
	}
	void Show() {
		for (int i = 0; i < a_; ++i) {
			for (int j = 0; j < b_; ++j) {
				cout << arr_[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}
	// сумма всех элементов массива
	const int GetSum() {
		int sum = 0;
		for (int i = 0; i < a_; ++i) {
			for (int j = 0; j < b_; ++j) {
				sum += arr_[i][j];
			}
		}
		return sum;
	}
	// среднее арифметическое всех элементов
	double GetAverage() {
		int sum = this->GetSum();
		return static_cast<double>(this->GetSum()) / static_cast<double>(a_ * b_);
	}
	// минимальный элемент
	int GetMin() {
		int min = arr_[0][0];
		for (int i = 0; i < a_; ++i) {
			for (int j = 0; j < b_; ++j) {
				if (arr_[i][j] < min) {
					min = arr_[i][j];
				}
			}
		}
		return min;
	}

	// максимальный элемент
	int GetMax() {
		int max = arr_[0][0];
		for (int i = 0; i < a_; ++i) {
			for (int j = 0; j < b_; ++j) {
				if (arr_[i][j] > max) {
					max = arr_[i][j];
				}
			}
		}
		return max;
	}

	/*
	В двумерном массиве целых чисел посчитать сумму элементов:
	в каждой строке; в каждом столбце; одновременно по всем строкам и всем столбцам.
	*/

	void ShowRowColSum() {
		int sum_row = 0;
		int sum_col = 0;
		for (int i = 0; i < a_; ++i) {
			for (int j = 0; j < b_; ++j) {
				cout << arr_[i][j] << "\t";
				sum_row += arr_[i][j];
			}
			cout << " | " << sum_row << endl;
			sum_row = 0;
		}
		
		for (int i = 0; i < b_+1; ++i) {
			cout << "--------";
		}
		cout << endl;
		for (int i = 0; i < b_; ++i) {
			for (int j = 0; j < a_; ++j) {
				sum_col += arr_[j][i];
			}
			cout << sum_col << "\t";
			sum_col = 0;
		}
		cout << " | " << this->GetSum() << endl;
	}

	/*
	Напишите программу, в которой объявляется массив размером 5х10 и массив размером 5х5.
	Первый массив заполняется случайными числами, в диапазоне от 0 до 50. Второй массив
	заполняется по следующему принципу: первый элемент второго массива равен сумме первого
	и второго элемента первого массива, второй элемент второго массива равен сумму
	третьего и четвертого элемента первого массива.
	*/

	// Заполняем текущий массив из переданного по условию выше
	void GetArrFromOtherArr(const Arr& a) {
		for (int i = 0; i < this->a_; ++i) {
			for (int j = 0; j < this->b_; ++j) {
				this->arr_[i][j] = a.arr_[i][j+j] + a.arr_[i][j+j+ 1];
			}
		}
		//return *this;
	}

	// Возвращает массив из текущего массива согласно условию выше
	// Необходим конструктор копирования и перегрузка =
	Arr GetArrFromOtherArr() {
		Arr new_arr(this->a_, (this->b_) / 2);

		for (int i = 0; i < new_arr.a_; ++i) {
			for (int j = 0; j < new_arr.b_; ++j) {
				new_arr.arr_[i][j] = this->arr_[i][j + j] + this->arr_[i][j + j + 1];
			}
		}
		return new_arr;
	}

	void Info() {
		cout << "\nИНФОРМАЦИЯ О МАССИВЕ:\n";
		this->Show();
		cout << "Сумма всех элементов = " << this->GetSum() << endl;
		cout << "Среднее арифметическое элементов = " << this->GetAverage() << endl;
		cout << "Минимальный элемент = " << this->GetMin() << endl;
		cout << "Максимальный элемент = " << this->GetMax() << endl;
	}
private:
	int a_;
	int b_;
	int** arr_;
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	int a, b;
	cout << "Введите размер массива [a][b]: \na = "; cin >> a;
	cout << "b = ";cin >> b;
	Arr arr(a, b, 50);
	/*arr.Show();
	cout << "Сумма всех элементов = " << arr.GetSum() << endl;
	cout << "Среднее арифметическое элементов = " << arr.GetAverage() << endl;
	cout << "Минимальный элемент = " << arr.GetMin() << endl;
	cout << "Максимальный элемент = " << arr.GetMax() << endl;*/
	arr.Info();
	arr.ShowRowColSum();

	Arr arr5x10(5, 10, 50);
	//arr5x10.Show();
	/*Arr arr5x5(5, 5);
	arr5x5.GetArrFromOtherArr(arr5x10);*/
	Arr arr5x5 = arr5x10.GetArrFromOtherArr();

	arr5x5.Show();



	return 0;
}