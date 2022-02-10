#include "Headers.h"
using namespace std;


int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    cout << "Программа создаёт 2-мерный массив со значениями увеличивающимися вдвое \n";
    int a,b,c;
    cout << "Введите размер массива[a][b]: \na = "; cin >> a;
    cout << "b = ";cin >> b;
    cout << "Введите первый элемент массива: "; cin >> c;
    int** A = new int*[a];
    for (int i = 0; i < a; i++)
    {
        A[i] = new int[b];
    }
    int key = 0;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0;j < b;j++)
        {
            if (j != 0) A[i][j] = A[i][j-1] *2;
            else {
                A[i][j] = c;
            }
            cout << A[i][j] << "; ";
            if (j == b - 1) key = A[i][j];
            else;
        }
        c = key * 2;
        cout << endl;
    }
    cout << endl;
    
    for (int i = 0; i < a; i++)
    {
        delete[] A[i];
    }
    delete[]A;



    
}
