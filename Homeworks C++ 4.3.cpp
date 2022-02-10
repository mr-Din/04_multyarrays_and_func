#include "Headers.h"
using namespace std;


int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    cout << "Программа смещает массив в заданном направление на заданное кол-во разрядов \n";
    int a,b,c;
    char direction;
    cout << "Введите размер массива[a][b]: \na = "; cin >> a;
    cout << "b = ";cin >> b;
    //cout << "Введите первый элемент массива: "; cin >> c;
    int** A = new int*[a];
    for (int i = 0; i < a; i++)
    {
        A[i] = new int[b];
    }
    
    for (int i = 0; i < a; i++)
    {
        for (int j = 0;j < b;j++)
        {
            A[i][j] = rand()%(100-(-100))-100;
            cout << A[i][j] << "; ";
            
        }
        cout << endl;
    }
    cout << endl;

    int** B = new int* [a];
    for (int i = 0; i < a; i++)
    {
        B[i] = new int[b];
    }

    /*for (int i = 0; i < a; i++)       //вывод неинициализированного массива
    {
        for (int j = 0;j < b;j++)
        {
            cout << B[i][j] << "; ";

        }
        cout << endl;
    }
    cout << endl;*/

    cout << "Введите количество разрядов для свига: "; cin >> c;
    cout << R"(Выберите направление:
w - вверх; s - вниз; a - влево; d - вправо; q - выход
)";cin >> direction;

    switch (direction)
    {
    case 'a':   //смещение влево
    case'A':
    {
        for (int i = 0; i < a; i++)
        {
            for (int j = 0;j < b;j++)
            {
                B[i][j] = A[i][j+c];
                if ((j+c) >=b) { B[i][j] = A[i][j+c-b]; }
                cout << B[i][j] << "; ";

            }
            cout << endl;
        }
        cout << endl;
        break;
    }
    case 'd':   //смещение вправо
    case'D':
    {
        for (int i = 0; i < a; i++)
        {
            for (int j = 0;j < b;j++)
            {
                B[i][j] = A[i][j - c];
                if ((j - c) <0) { B[i][j] = A[i][j - c + b]; }
                cout << B[i][j] << "; ";

            }
            cout << endl;
        }
        cout << endl;
        break;
    }
    case 'w':   //смещение вверх
    case'W':
    {
        for (int i = 0; i < a; i++)
        {   
            int key = 0;
            if ((i + c) < a) { key = i + c; }
            else key = i+c - a;
            for (int j = 0;j < b;j++)
            {
                B[i][j] = A[key][j];
                cout << B[i][j] << "; ";

            }
            cout << endl;
        }
        cout << endl;
        break;
    }
    case 's':   //смещение вниз
    case'S':
    {
        for (int i = 0; i < a; i++)
        {
            int key = 0;
            if ((i - c) >= 0) { key = i - c; }
            else key = i - c + a;
            for (int j = 0;j < b;j++)
            {
                B[i][j] = A[key][j];
                cout << B[i][j] << "; ";

            }
            cout << endl;
        }
        cout << endl;
        break;
    }
    default:
    {
        cout << "Неправильный ввод!\n";
        break;
    }
    }


    for (int i = 0; i < a; i++)
    {
        delete[] A[i];
        delete[] B[i];
    }
    delete[]A;
    delete[]B;



    
}
