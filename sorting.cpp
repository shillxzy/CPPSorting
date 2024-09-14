#include <iostream>
#include <Windows.h>
#include <algorithm>


using namespace std;

// Сортування бульбашкою
void bubbleSort(int arr[], int n) 
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
} 
// Сортування вставкою
void sortInsertion(int a[], int n)
{
	int i, j, key;

	for (i = 1; i < n; i++)
	{
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;

	}
}
// Сортування вибіркою
void sortSelection(int a[], int n)
{
	int i, j, mini;
	for (i = 0; i < n; i++)
	{
		mini = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[mini])
			{
				mini = j;
			}
		}
		swap(a[mini], a[i]);
	}
}
// Сортування Гномом
void sortGnome(int a[], int n)
{
	int index = 0;
	while (index < n)
	{
		if (index == 0)
		{
			index++;
		}
		if (a[index] >= a[index - 1])
		{
			index++;
		}
		else
		{
			swap(a[index], a[index - 1]);
			index--;
		}
	}
}

void Exchange(int i, int j, int* x)
{
	int tmp;
	tmp = x[i];
	x[i] = x[j];
	x[j] = tmp;
}
//"просіювання" елементів
void Sifting(int left, int right, int* x)
{
	int q, p;
	q = 2 * left + 1;
	p = q + 1;
	if (q <= right)
	{
		if (p <= right && x[p] > x[q])
			q = p;
		if (x[left] < x[q])
		{
			Exchange(left, q, x);
			Sifting(q, right, x);
		}
	}
}
void Build_Pyramid(int k, int r, int* x)
{
	Sifting(k, r, x);
	if (k > 0)
		Build_Pyramid(k - 1, r, x);
}
void Sort_Piramid(int k, int* x)
{
	Exchange(0, k, x);
	Sifting(0, k - 1, x);
	if (k > 1)
		Sort_Piramid(k - 1, x);
}
// Сортування Бінарним деревом
void Binary_Pyramidal_Sort(int k, int* x) 
{
	Build_Pyramid(k / 2 + 1, k - 1, x);
	Sort_Piramid(k - 1, x);
}

// Сортування Шелл
void Shell_Sort(int n, int* x) 
{
	int h, i, j;
	for (h = n / 2; h > 0; h = h / 2)
		for (i = 0; i < n - h; i++)
			for (j = i; j >= 0; j = j - h)
				if (x[j] > x[j + h])
					Exchange(j, j + h, x);
				else j = 0;
}

// Швидке Сортування Хояре
void quickSort(int arr[], int left, int right) 
{
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2]; // Вибір опорного елемента
	/* Розділення масиву відносно опорного елемента
	* і повернення індексу опорного елемента
	*/
	while (i <= j) 
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) 
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}
	/* Рекурсивний виклик для сортування
	* лівої та правої частин
	*/
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}
// Сортування злиттям
void Merging_Sort(int n, int* x) 
{
	int i, j, k, t, s, Fin1, Fin2;
	int* tmp = new int[n];
	k = 1;
	while (k < n) 
	{
		t = 0;
		s = 0;
		while (t + k < n)
		{
			Fin1 = t + k;
			Fin2 = (t + 2 * k < n ? t + 2 * k : n);
			i = t;
			j = Fin1;
			for (; i < Fin1 && j < Fin2; s++) 
			{
				if (x[i] < x[j]) 
				{
					tmp[s] = x[i];
					i++;
				}
				else 
				{
					tmp[s] = x[j];
					j++;
				}
			}
			for (; i < Fin1; i++, s++)
				tmp[s] = x[i];
			for (; j < Fin2; j++, s++)
				tmp[s] = x[j];
			t = Fin2;
		}
		k *= 2;
		for (s = 0; s < t; s++)
			x[s] = tmp[s];
	}
}




int main()
{
	SetConsoleOutputCP(1251);
	srand(static_cast<unsigned>(time(nullptr)));
	int a1[10];
	int a2[100];
	int a3[1000];
	double sum_t1, sum_t2, sum_t3, sum_t4, sum_t5, sum_t6, sum_t7, sum_t8, sum_t9, sum_t10;
	double sum_t11, sum_t12, sum_t13, sum_t14, sum_t15, sum_t16, sum_t17, sum_t18, sum_t19, sum_t20;
	double sum_t21, sum_t22, sum_t23, sum_t24;

//////////////////////////// СОРТУВАННЯ БУЛЬБАШКОЮ ///////////////////////////////////////////////////////

	for (int i = 0; i < 10; i++) 
	{
		a1[i] = rand() % 5000;
	}
	for (int i = 0; i < 100; i++) 
	{
		a2[i] = rand() % 5000;
	}
	for (int i = 0; i < 1000; i++) 
	{
		a3[i] = rand() % 5000;
	}

	clock_t start, end;
	start = clock();
	bubbleSort(a1, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << a1[i] << " ";
	}
	end = clock();
	sum_t1 = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl;

	start = clock();
	bubbleSort(a2, 100);
	for (int i = 0; i < 100; i++)
	{
		cout << a2[i] << " ";
	}
	end = clock();
	sum_t2 = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl;

	start = clock();
	bubbleSort(a3, 1000);
	for (int i = 0; i < 1000; i++)
	{
		cout << a3[i] << " ";
	}
	end = clock();
	sum_t3 = ((double)(end - start)) / CLOCKS_PER_SEC;


	//////////////////////////// СОРТУВАННЯ ВСТАВКАМИ ///////////////////////////////////////////////////////


	for (int i = 0; i < 10; i++)
	{
		a1[i] = rand() % 5000;
	}
	for (int i = 0; i < 100; i++)
	{
		a2[i] = rand() % 5000;
	}
	for (int i = 0; i < 1000; i++)
	{
		a3[i] = rand() % 5000;
	}

	start = clock();
	sortInsertion(a1, 10);
	for (int i = 0; i < 10; i++) 
	{
		cout << a1[i] << " ";
	}
	end = clock();
	sum_t4 = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl;

	start = clock();
	sortInsertion(a2, 100);
	for (int i = 0; i < 100; i++)
	{
		cout << a2[i] << " ";
	}
	end = clock();
	sum_t5 = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl;

	start = clock();
	sortInsertion(a3, 1000);
	for (int i = 0; i < 1000; i++)
	{
		cout << a3[i] << " ";
	}
	end = clock();
	sum_t6 = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl;

	//////////////////////////// СОРТУВАННЯ ВИБОРОМ ///////////////////////////////////////////////////////


	for (int i = 0; i < 10; i++)
	{
		a1[i] = rand() % 5000;
	}
	for (int i = 0; i < 100; i++)
	{
		a2[i] = rand() % 5000;
	}
	for (int i = 0; i < 1000; i++)
	{
		a3[i] = rand() % 5000;
	}

	start = clock();
	sortSelection(a1, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << a1[i] << " ";
	}
	end = clock();
	sum_t7 = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl;

	start = clock();
	sortSelection(a2, 100);
	for (int i = 0; i < 100; i++)
	{
		cout << a2[i] << " ";
	}
	end = clock();
	sum_t8 = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl;

	start = clock();
	sortSelection(a3, 1000);
	for (int i = 0; i < 1000; i++)
	{
		cout << a3[i] << " ";
	}
	end = clock();
	sum_t9 = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl;

	//////////////////////////// СОРТУВАННЯ ГНОМОМ ///////////////////////////////////////////////////////

	for (int i = 0; i < 10; i++)
	{
		a1[i] = rand() % 5000;
	}
	for (int i = 0; i < 100; i++)
	{
		a2[i] = rand() % 5000;
	}
	for (int i = 0; i < 1000; i++)
	{
		a3[i] = rand() % 5000;
	}

	start = clock();
	sortGnome(a1, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << a1[i] << " ";
	}
	end = clock();
	sum_t10 = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl;

	start = clock();
	sortGnome(a2, 100);
	for (int i = 0; i < 100; i++)
	{
		cout << a2[i] << " ";
	}
	end = clock();
	sum_t11 = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl;

	start = clock();
	sortGnome(a3, 1000);
	for (int i = 0; i < 1000; i++)
	{
		cout << a3[i] << " ";
	}
	end = clock();
	sum_t12 = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl;

	//////////////////////////// СОРТУВАННЯ ПІРАМІДОЮ ///////////////////////////////////////////////////////

	for (int i = 0; i < 10; i++)
	{
		a1[i] = rand() % 5000;
	}
	for (int i = 0; i < 100; i++)
	{
		a2[i] = rand() % 5000;
	}
	for (int i = 0; i < 1000; i++)
	{
		a3[i] = rand() % 5000;
	}

	start = clock();
	Binary_Pyramidal_Sort(10, a1);
	for (int i = 0; i < 10; i++)
	{
		cout << a1[i] << " ";
	}
	end = clock();
	sum_t13 = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl;

	start = clock();
	Binary_Pyramidal_Sort(100, a2);
	for (int i = 0; i < 100; i++)
	{
		cout << a2[i] << " ";
	}
	end = clock();
	sum_t14 = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl;

	start = clock();
	Binary_Pyramidal_Sort(1000, a3);
	for (int i = 0; i < 1000; i++)
	{
		cout << a3[i] << " ";
	}
	end = clock();
	sum_t15 = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl;

	//////////////////////////// СОРТУВАННЯ ШЕЛЛА ///////////////////////////////////////////////////////

	for (int i = 0; i < 10; i++)
	{
		a1[i] = rand() % 5000;
	}
	for (int i = 0; i < 100; i++)
	{
		a2[i] = rand() % 5000;
	}
	for (int i = 0; i < 1000; i++)
	{
		a3[i] = rand() % 5000;
	}

	start = clock();
	Shell_Sort(10, a1);
	for (int i = 0; i < 10; i++)
	{
		cout << a1[i] << " ";
	}
	end = clock();
	sum_t16 = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl;

	start = clock();
	Shell_Sort(100, a2);
	for (int i = 0; i < 100; i++)
	{
		cout << a2[i] << " ";
	}
	end = clock();
	sum_t17 = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl;

	start = clock();
	Shell_Sort(1000, a3);
	for (int i = 0; i < 1000; i++)
	{
		cout << a3[i] << " ";
	}
	end = clock();
	sum_t18 = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl;

	//////////////////////////// СОРТУВАННЯ ШВИДКЕ ///////////////////////////////////////////////////////

	for (int i = 0; i < 10; i++)
	{
		a1[i] = rand() % 5000;
	}
	for (int i = 0; i < 100; i++)
	{
		a2[i] = rand() % 5000;
	}
	for (int i = 0; i < 1000; i++)
	{
		a3[i] = rand() % 5000;
	}

	start = clock();
	quickSort(a1, 0, 9);
	for (int i = 0; i < 10; i++)
	{
		cout << a1[i] << " ";
	}
	end = clock();
	sum_t19 = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl;

	start = clock();
	quickSort(a2, 0, 99);
	for (int i = 0; i < 100; i++)
	{
		cout << a2[i] << " ";
	}
	end = clock();
	sum_t20 = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl;

	start = clock();
	quickSort(a3, 0, 999);
	for (int i = 0; i < 1000; i++)
	{
		cout << a3[i] << " ";
	}
	end = clock();
	sum_t21 = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl;

	//////////////////////////// СОРТУВАННЯ ЗЛИТТЯМ ///////////////////////////////////////////////////////

	for (int i = 0; i < 10; i++)
	{
		a1[i] = rand() % 5000;
	}
	for (int i = 0; i < 100; i++)
	{
		a2[i] = rand() % 5000;
	}
	for (int i = 0; i < 1000; i++)
	{
		a3[i] = rand() % 5000;
	}

	start = clock();
	Merging_Sort(10, a1);
	for (int i = 0; i < 10; i++)
	{
		cout << a1[i] << " ";
	}
	end = clock();
	sum_t22 = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl;

	start = clock();
	Merging_Sort(100, a2);
	for (int i = 0; i < 100; i++)
	{
		cout << a2[i] << " ";
	}
	end = clock();
	sum_t23 = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl;

	start = clock();
	Merging_Sort(1000, a3);
	for (int i = 0; i < 1000; i++)
	{
		cout << a3[i] << " ";
	}
	end = clock();
	sum_t24 = ((double)(end - start)) / CLOCKS_PER_SEC;
	cout << endl;




	cout << endl;
	cout << endl;

	cout << "=======================ТАБЛИЧКА СОРТУВАННЯ=======================" << endl;
	cout << "------------------------------------------------------------------" << endl;
	cout << "| №п/п |        Алгоритм           | n = 10 | n = 100 | n = 1000 |" << endl;
	cout << "------------------------------------------------------------------" << endl;
	cout << "|  1   | Сортування Бульбашкою     | " << sum_t1 << " s | " << sum_t2 << " s | " << sum_t3 << " s | " << endl;
	cout << "------------------------------------------------------------------" << endl;
	cout << "|  2   | Сортування вставками      | " << sum_t4 << " s | " << sum_t5 << " s | " << sum_t6 << " s | " << endl;
	cout << "------------------------------------------------------------------" << endl;
	cout << "|  3   | Сортування вибором        | " << sum_t7 << " s | " << sum_t8 << " s | " << sum_t9 << " s | " << endl;
	cout << "------------------------------------------------------------------" << endl;
	cout << "|  4   | Алгоритм гнома            | " << sum_t10 << " s | " << sum_t11 << " s | " << sum_t12 << " s | " << endl;
	cout << "------------------------------------------------------------------" << endl;
	cout << "|  5   | Сортування пірамідою      | " << sum_t13 << " s | " << sum_t14 << " s | " << sum_t15 << " s | " << endl;
	cout << "------------------------------------------------------------------" << endl;
	cout << "|  6   | Сортування Шелла          | " << sum_t16 << " s | " << sum_t17 << " s | " << sum_t18 << " s | " << endl;
	cout << "------------------------------------------------------------------" << endl;
	cout << "|  7   | Швидке сортування         | " << sum_t19 << " s | " << sum_t20 << " s | " << sum_t21 << " s | " << endl;
	cout << "------------------------------------------------------------------" << endl;
	cout << "|  8   | Сортування злиттям        | " << sum_t22 << " s | " << sum_t23 << " s | " << sum_t24 << " s | " << endl;
	cout << "------------------------------------------------------------------" << endl;


	double bubble[3] = { sum_t1, sum_t2, sum_t3 }; // Сортування Бульбашкою
	double insertion[3] = { sum_t4, sum_t5, sum_t6 }; // Сортування вставками
	double selection[3] = { sum_t7, sum_t8, sum_t9 }; // Сортування вибором
	double gnome[3] = { sum_t10, sum_t11, sum_t12 }; // Алгоритм гнома
	double pyramid[3] = { sum_t13, sum_t14, sum_t15 }; // Сортування пірамідою
	double shell[3] = { sum_t16, sum_t17, sum_t18 }; // Сортування Шелла
	double quick[3] = { sum_t19, sum_t20, sum_t21 }; // Швидке сортування
	double merge[3] = { sum_t22, sum_t23, sum_t24 }; // Сортування злиттям

	int n[3] = { 10, 100, 1000 };
	for (int i = 0; i < 3; i++)
	{
		double min = bubble[i];
		double max = bubble[i];
		string min1 = "Сортування бульбашкою";
		string max1 = "Сортування бульбашкою";



		if (min > insertion[i])
		{
			min = insertion[i];
			min1 = "Сортування вставками";
		}
		else if (min > selection[i])
		{
			min = selection[i];
			min1 = "Сортування вибором";
		}
		else if (min > gnome[i])
		{
			min = gnome[i];
			min1 = "Сортування гномом";
		}
		else if (min > pyramid[i])
		{
			min = pyramid[i];
			min1 = "Сортування пірамідою";
		}
		else if (min > shell[i])
		{
			min = shell[i];
			min1 = "Сортування Шелла";
		}
		else if (min > quick[i])
		{
			min = quick[i];
			min1 = "Швидке сортування";
		}
		else if (min > merge[i])
		{
			min = merge[i];
			min1 = "Сортування злиттям";
		}

		// max

		if (max < insertion[i])
		{
			max = insertion[i];
			max1 = "Сортування вставками";
		}
		else if (max < selection[i])
		{
			max = selection[i];
			max1 = "Сортування вибором";
		}
		else if (max < gnome[i])
		{
			max = gnome[i];
			max1 = "Сортування гномом";
		}
		else if (max < pyramid[i])
		{
			max = pyramid[i];
			max1 = "Сортування пірамідою";
		}
		else if (max < shell[i])
		{
			max = shell[i];
			max1 = "Сортування Шелла";
		}
		else if (max < quick[i])
		{
			max = quick[i];
			max1 = "Швидке сортування";
		}
		else if (max < merge[i])
		{
			max = merge[i];
			max1 = "Сортування злиттям";
		}


		cout << "n = " << n[i] << endl;
		cout << "Найкращий алгоритм: " << min1 << " | час: " << min << " с" << endl;
		cout << "Найгірший алгоритм: " << max1 << " | час: " << max << " с" << endl;
		cout << endl;	

	}

	


	return 0;
}




