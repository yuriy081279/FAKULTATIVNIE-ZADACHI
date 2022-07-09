#include<iostream>
using namespace std;
#define tab "\t"
void main()
{
	setlocale(LC_ALL, "");
	const int STROKA = 8;
	const int STOLB = 6;
	int arr[STROKA][STOLB];
	int x = 0;

	//Заполнение матрицы случайными числами
	for (int i = 0; i < STROKA; i++)
	{
		for (int j = 0; j < STOLB; j++)
		{
			arr[i][j] = rand() % 7;
		}
	}
	cout << endl;
	//Вывод исходной матрицы на экран
	cout << " Исходная матрица со случайными числами: ";
	cout << endl;
	cout << endl;
	for (int i = 0; i < STROKA; i++)
	{
		for (int j = 0; j < STOLB; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
	cout << " Вывод повторяющихся значений матрицы: ";
	cout << endl;
	cout << endl;
	for (int i = STROKA - 1; i >= 0; i--)
	{
		for (int j = STOLB - 1; j >= 0; j--)
		{
			for (int c = 0; c <= i; c++)
			{
				for (int d = 0; d < STOLB; d++)
				{
					if (arr[i][j] == arr[c][d])
					{
						++x;
					}
				}
			}

			for (int z = i; z < STROKA; z++)
			{
				if (z == i)
				{
					for (int t = j; t < STOLB; t++)
					{
						if (arr[i][j] == arr[z][t + 1] || arr[i][j] == arr[z + 1][t])
						{
							x = 0;
						}
					}
				}
				if (z > i)
				{
					for (int t = 0; t < STOLB; t++)
					{
						if (arr[i][j] == arr[z][t + 1] || arr[i][j] == arr[z + 1][t])
						{
							x = 0;
						}
					}
				}
			}
			if (x > 1)
			{
				cout << " Повторяющееся значение = " << arr[i][j] << tab;
				cout << endl;
				cout << " Количество повторений этого значения = " << x;
				cout << endl;
			}
			x = 0;
		}
	}
}
