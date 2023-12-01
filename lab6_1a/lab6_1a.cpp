/*
Дана матрица размера M × N. Найти максимальный среди минимальных элементов ее строк.
*/

#include <iostream>
#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	size_t m, n;
	const int MAX_SIZE = 10;
	int array[MAX_SIZE][MAX_SIZE];
	int minar[MAX_SIZE];

	cout << "Введите размер матрицы m*n: ";
	cin >> m >> n;

	if ((n < 1) or (m < 1) or (n > MAX_SIZE) or (m > MAX_SIZE))
	{
		cerr << "Ошибка: размер массива должен быть не меньше 1 и не больше " << MAX_SIZE;
		return 1;
	}

	cout << "Введите элементы массива:" << endl;
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cin >> array[i][j];
		}
	}

	for (size_t i = 0; i < m; i++)
	{
		int min = array[i][0];
		for (size_t j = 0; j < n; j++)
		{
			if (array[i][j] < min) min = array[i][j];
		}
		minar[i] = min;
	}

	int min = minar[0];
	for (size_t i = 1; i < m; i++)
	{
		if (min < minar[i])
		{
			min = minar[i];
		}
	}

	cout << "Ответ: " << min;
}