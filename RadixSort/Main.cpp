/*
	Juarez, Freddy
	CS A200
	November 11, 2016

	RadixSort
*/

#include <iostream>
#include <cmath>


using namespace std;

const int CAPACITY_1 = 3;
const int CAPACITY_2 = 5;
const int CAPACITY_3 = 9;

void radixSort(int a[], int b[], int numDigits, const int CAPACITY);

int main()
{
	 int a[CAPACITY_2];
	 a[0] = 796;
	 a[1] = 837;
	 a[2] = 374;
	 a[3] = 367;
	 a[4] = 248;

	 int b[CAPACITY_2];

	 int numDigits = 3;
	 radixSort(a, b, numDigits, CAPACITY_2);
	 cout << endl;

	 int c[CAPACITY_1];
	 c[0] = 783;
	 c[1] = 561;
	 c[2] = 469;

	 int d[CAPACITY_1];

	 int numDigits1 = 3;
	 radixSort(c, d, numDigits1, CAPACITY_1);
	 cout << endl;


	system("Pause");
	return 0;
}

void radixSort(int a[], int b[], int numDigits, const int CAPACITY)
{
	bool transfer;
	int process = 1;
	int digit1 = 1;
	int digit2 = 1;
	int n = 1;
	int m = 1;

	for (int indx = 0; indx < CAPACITY; indx++)
	{
		cout << a[indx] << " ";
	}

	cout << endl;

	for (int num = 0; num < numDigits; ++num)
	{
		int compare = 0;
		int i = 0;
		int j = 0;
		int rand = 1;
		int bSize = 0;

		if (num != 0)
		{
			++n;
			digit1 = pow(10, n);
			digit2 = pow(10, m);
			++m;
		}

		do
		{
			transfer = false;

			if (process == 1)
			{
				if ((a[i] % 10) == compare)
				{
					b[j] = a[i];
					a[i] = rand;
					++rand;
					++j;
					++bSize;
					transfer = true;

					if (a[i] == a[CAPACITY - 1])
					{
						i = 0;
					}
					else
					{
						++i;
					}
				}
				else if (a[i] == a[CAPACITY - 1])
				{
					i = 0;
				}
				else
				{
					i++;
				}
			}
			else
			{
				if ((a[i] % digit1 / digit2) == compare)
				{
					b[j] = a[i];
					a[i] = rand;
					++rand;
					++j;
					++bSize;
					transfer = true;

					if (a[i] == a[CAPACITY - 1])
					{
						i = 0;
					}
					else
					{
						++i;
					}
				}
				else if (a[i] == a[CAPACITY - 1])
				{
					i = 0;
				}
				else
				{
					i++;
				}
			}

			if (!transfer)
			{
				transfer = true;
				if (i == 0)
				{
					++compare;
				}
			}

			if (bSize == CAPACITY)
				transfer = false;

		} while (transfer);

		for (int back = 0; back < CAPACITY; ++back)
		{
			a[back] = b[back];
			cout << a[back] << " ";
		}
		cout << endl;

		++process;
	}
}