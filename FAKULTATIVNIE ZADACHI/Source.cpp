#include<iostream>
using namespace std;
#define tab "\t"
//#define same_znacheniya
//#define random_s_boolom // Плюс сортировка "в одном флаконе"
#define random_bez_boola// Плюс сортировка "в одном флаконе"
#ifdef same_znacheniya
void main()
{
	setlocale(LC_ALL, "");
	const int STROKA = 7;
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
						if (arr[i][j] == arr[z][t + 1])
						{
							x = 0;
						}
					}
				}
				if (z > i)
				{
					for (int t = 0; t < STOLB; t++)
					{
						if (arr[i][j] == arr[z][t + 1])
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
#endif // same_znacheniya
#ifdef random_bez_boola
void main()
{
	setlocale(LC_ALL, "");
	const int STROKA = 6;
	const int STOLB = 4;
	int arr[STROKA][STOLB];
	int x = 0;
	for (int i = 0; i < STROKA; i++)
	{
		for (int j = 0; j < STOLB; j++)
		{			
			arr[i][j] = rand() % (STROKA * STOLB);
			for (int c = 0; c <= i; c++)
			{
				if (c == i)
				{
					for (int d = 0; d < j; d++)
					{
						if (arr[i][j] == arr[c][d])
						{
							x++;
							//break;
						}
					}
				}
				if (c < i)
				{
					for (int d = 0; d < STOLB; d++)
					{
						if (arr[i][j] == arr[c][d])
						{
							x++;
							//break;														
						}
					}
				}
				if (x > 0)
				{
					if (j > 0)
					{
						j--;												
					}
					if (j == 0)
					{
						i--;
						j = STOLB;
				    }
				}
			}			
			x = 0;					
		}
	}
	for (int i = 0; i < STROKA; i++)
	{
		for (int j = 0; j < STOLB; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << " Этот же массив в отсортированном виде: " << endl;
	for (int i = 0; i < STROKA; i++)
	{
		for (int j = 0; j < STOLB; j++)
		{
			for (int c = 0; c < STROKA; c++)
			{
				for (int d = 0; d < STOLB; d++)
				{
					if (arr[i][j] < arr[c][d])
					{
						int min = arr[i][j];
						arr[i][j] = arr[c][d];
						arr[c][d] = min;
					}
				}
			}
		}
	}
	cout << endl;
	for (int i = 0; i < STROKA; i++)
	{
		for (int j = 0; j < STOLB; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}

}

#endif // random_bez_boola
#ifdef random_s_boolom
void main()
{
	setlocale(LC_ALL, "");
	const int STROKA = 6;
	const int STOLB = 4;
	int arr[STROKA][STOLB];
	bool unique;	
	for (int i = 0; i < STROKA; i++)
	{
		for (int j = 0; j < STOLB; j++)
		{
			do
			{
				unique = true;
				arr[i][j] = rand() % (STROKA * STOLB);
				for (int c = 0; c <= i; c++)
				{
					if (c == i)
					{
						for (int d = 0; d < j; d++)
						{
							if (arr[i][j] == arr[c][d])
							{
								unique = false;
								break;
							}
						}
					}
					if (c < i)
					{
						for (int d = 0; d < STOLB; d++)
						{
							if (arr[i][j] == arr[c][d])
							{
								unique = false;
								break;
							}
						}
					}
				}
			} while (!unique);
		}
	}
	cout << " Массив заполненный уникальными значениями: " << endl;
	for (int i = 0; i < STROKA; i++)
	{
		for (int j = 0; j < STOLB; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << " Этот же массив в отсортированном виде: " << endl;
	for (int i = 0; i < STROKA; i++)
	{
		for (int j = 0; j < STOLB; j++)
		{
			for (int c = 0; c < STROKA; c++)
			{
				for (int d = 0; d < STOLB; d++)
				{
					if (arr[i][j] < arr[c][d])
					{
						int min = arr[i][j];
						arr[i][j] = arr[c][d];
						arr[c][d] = min;
					}
				}				
			}			
		}		
	}
	cout << endl;
	for (int i = 0; i < STROKA; i++)
	{
		for (int j = 0; j < STOLB; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}
#endif // random_s_boolom


