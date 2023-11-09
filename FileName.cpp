#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int i, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** a, const int i, const int rowCount, const int colCount);
void Change(int** a, const int row1, const int row2, const int colCount);
void Calc(int** a, const int i, const int j, const int rowCount, const int colCount, int& S, int& k);

int main()
{
	srand((unsigned)time(NULL));
	int Low = -26;
	int High = 23;
	int rowCount = 8;
	int colCount = 6;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	Create(a, 0, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);
	Sort(a, 0, rowCount, colCount);
	Print(a, rowCount, colCount);
	int S = 0;
	int k = 0;
	Calc(a, 0, 0, rowCount, colCount, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(a, rowCount, colCount);

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

void Create(int** a, const int i, const int rowCount, const int colCount, const int Low, const int High)
{
	if (i < rowCount)
	{
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);

		Create(a, i + 1, rowCount, colCount, Low, High);
	}
}

void Sort(int** a, const int i, const int rowCount, const int colCount)
{
	if (i < rowCount - 1)
	{
		for (int j = 0; j < rowCount - i - 1; j++)
			if ((a[j][0] < a[j + 1][0])
				||
				a[j][0] == a[j + 1][0] && a[j][1] > a[j + 1][1]
				||
				(a[j][0] == a[j + 1][0] &&
					a[j][1] == a[j + 1][1] &&
					a[j][3] > a[j + 1][3]))
				Change(a, j, j + 1, colCount);

		Sort(a, i + 1, rowCount, colCount);
	}
}

void Calc(int** a, const int i, const int j, const int rowCount, const int colCount, int& S, int& k)
{
	if (i < rowCount)
	{
		if (j < colCount)
		{
			if (!((a[i][j] % 2 == 0) && (a[i][j] > 0)))
			{
				S += a[i][j];
				k++;
				a[i][j] = 0;
			}

			Calc(a, i, j + 1, rowCount, colCount, S, k);
		}
		else
		{
			Calc(a, i + 1, 0, rowCount, colCount, S, k);
		}
	}
}
void Change(int** a, const int row1, const int row2, const int colCount)
{
	int tmp;
	for (int j = 0; j < colCount; j++)
	{
		tmp = a[row1][j];
		a[row1][j] = a[row2][j];
		a[row2][j] = tmp;
	}
}
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
