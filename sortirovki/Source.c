#include "stdio.h"
#include "locale.h"
#include "stdlib.h"


void vvod_array(int a[], int n)
{
	int i;
	srand(1000);

	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 10;
	}
}

void print_array(int a[], int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d  ", a[i]);
	}
}

void sort1(int a[], int n)
{
	int i, j, tmp;

	while (a[n] <= a[0])
	{
		for (i = 0; i < n; i++)
		{
			for (j = i + 1; j < n; j++)
			{
				if (a[i] > a[j])
				{
					tmp = a[j];
					a[j] = a[i];
					a[i] = tmp;
				}
			}
		}

		for (i = n; i > 0; i--)
		{
			for (j = i-1; j > 0; j--)
			{
				if (a[i] > a[j])
				{
					tmp = a[j];
					a[j] = a[i];
					a[i] = tmp;
					
				}
			}
		}
	}
}

void sort2(int a[], int n)
{
	int k, l;
	for (int i = 1; i < n; i++)
	{
		k = a[i];
		l = i - 1;
		while (l >= 0 && a[l] > k)
		{
			a[l + 1] = a[l];
			l = l - 1;
		}
		a[l + 1] = k;
	}
}

int a[10];
int b[11];

void merging( int left, int mid, int right)
{
    int l1, l2, i;

    for (l1 = left, l2 = mid + 1, i = left; l1 <= mid && l2 <= right; i++)
    {
        if (a[l1] <= a[l2])
        {
            b[i] = a[l1++];
        }
        else
        {
            b[i] = a[l2++];
        }
    }

    while (l1 <= mid)
    {
        b[i++] = a[l1++];
    }

    while (l2 <= right)
    {
        b[i++] = a[l2++];
    }

    for (i = left; i <= right; i++)
    {
        a[i] = b[i];
    }
}

void sort3( int left, int right)
{
    int mid;

    if (left < right)
    {
        mid = (left + right) / 2;
        sort3(left, mid);
        sort3(mid + 1, right);
        merging(left, mid, right);
    }
}

void menu()
{
    {
        printf("\nMENU:\n");
        printf("1. ñãåíåðèðîâàòü ìàññèâ\n");
        printf("2. âûâåñòè ìàññèâ\n");
        printf("3. îòñîðòèðîâàòü ñîðòèðîâêîé ïóçûðüêîì\n");
        printf("4. îòñîðòèðîâàòü ñîðòèðîâêîé âñòàâêàìè\n");
        printf("5. îòñîðòèðîâàòü ñîðòèðîâêîé ñëèÿíèåì\n");
        printf("0. exit\n");
    }
}

void main()
{
	setlocale(LC_CTYPE, "Russian");
	int a[10];
	int n = 10;
	int t = 10;

	while (t != 0)
	{
		menu();
		scanf_s("%d", &t);
		switch (t)
		{
		case 1:
		{
			vvod_array(a, n);
			break;
		}
		case 2:
		{
			print_array(a, n);
			break;
		}
		case 3:
		{
			sort1(a, n);
			print_array(a, n);
			break;
		}
		case 4:
		{
			sort2(a, n);
			print_array(a, n);
			break;
		}
		case 5:
		{
			sort3(a, n);
			print_array(a, n);
			break;
		}
		}
	}
}	
