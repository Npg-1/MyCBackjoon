#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(a, b) { int temp = a; a = b; b = temp; }


void makeRanArr(int* arr, int size);
void reverseArr(int* arr, int size);


// Big-O (n Log n)
void merge(int* arr, int* sortArr, int l, int m, int r);	// ���� ����
void mergeSort(int* arr, int* sortArr, int l, int r);

void heapSort(int* arr, int size);		// �� ����
void makeHeap(int* arr, int* heapArr, int size, int idx);
int extractHeap(int* heapArr, int lastIdx);

void quickSort(int* arr, int l, int r);	// �� ���� 

// Big-O (n2) 
void bubbleSort(int* arr, int size);	// ���� ���� | ���� �ܼ��� ������ ����, ������ �ð� ���⵵�� �־��̰� ���̽��� ���� ���� ��, 1000 ���� ������ ���� ����ϰ� �� �̿ܿ��� ���ο�
void insertSort(int* arr, int size);	// ���� ���� | �ְ��� ��쿡�� n, �־��� ��쿡�� n2, ��� n2
void selectSort(int* arr, int size);	// ���� ���� | ���� ������ �Է��� ���ĵǾ� �ֵ��� �����ϰ� �Ǿ� �ֵ��� ���о��� �׻� O(n2)�� �ð����⵵�� ����


// Big-O (n?) (1���� ���ѱ��� �پ���)
int bogoSort(int* arr, int size);


int main()
{
	int n = 0;
	printf("�迭 ũ�⸦ �Է��ϼ���: ");
	scanf("%d", &n);
	int* arr = (int*)calloc(sizeof(int), n);

	// n���� ���� �Է� �ϴ� �κ�
	//for (int i = 0; i < n; i++)
	//{
	//	int temp;
	//	scanf("%d", &temp);
	//	arr[i] = temp;

	//}

	makeRanArr(arr, n);

	printf("���� �� ��: ");
	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
	printf("\n");


	heapSort(arr, n);


	printf("\n\n���� �� ��: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");




}








// ���� ����
void bubbleSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j]) swap(arr[i], arr[j]);

		}
	}
}


// ���� ����
void insertSort(int* arr, int size)
{
	// ���� ������ cur���� ���� pre�� ���� ���ؼ� cur(pre���� ���� ��)�� pre���� �۴ٸ� cur�� pre�� �ٲ�
	// �ٲٰ� ���� cur�� pre�� �� �� 1�� �ٿ��� cur�� pre������ �̻��� ��쿡 while�� ���, �׸��� cur�� ��ġ�� �ٽ� ���� ��ġ�� �ǵ���

	for (int cur = 1; cur < size; cur++)
	{
		int pre = cur - 1;
		int temp = cur;
		while (arr[cur] < arr[pre])
		{
			swap(arr[cur], arr[pre]);
			pre--;
			cur--;

		}

		cur = temp;
	}
}


// ���� ����
void selectSort(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		int min = INT_MAX;
		int minIdx = i;
		for (int j = i; j < size; j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				minIdx = j;

			}
		}
		swap(arr[i], arr[minIdx]);

	}
}





// ���� ����
void merge(int* arr, int* sortArr, int l, int m, int r)
{
	int i = l, j = m + 1, k = l;

	while (i <= m && j <= r)
	{
		if (arr[i] < arr[j]) sortArr[k++] = arr[i++];
		else sortArr[k++] = arr[j++];

	}

	while (i <= m) sortArr[k++] = arr[i++];
	while (j <= r) sortArr[k++] = arr[j++];

	for (int a = l; a <= r; a++)
	{
		arr[a] = sortArr[a];

	}
}

void mergeSort(int* arr, int* sortArr, int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2;
		mergeSort(arr, sortArr, l, m);
		mergeSort(arr, sortArr, m + 1, r);
		merge(arr, sortArr, l, m, r);

	}
}


// �� ����
void heapSort(int* arr, int size)
{
	int* heapArr = (int*)calloc(sizeof(int), size);

	makeHeap(arr, heapArr, size, 0);

	printf("��: ");
	for (int i = 0; i < size; i++)
		printf("%d ", heapArr[i]);

	for (int i = 0; i < size; i++)
	{
		arr[i] = extractHeap(heapArr, size - i - 1);

	}
}

void makeHeap(int* arr, int* heapArr, int size, int idx)
{
	if (idx >= size) return;

	int tempIdx = idx;
	heapArr[idx] = arr[idx];
	while (true)
	{
		if (tempIdx % 2 == 0)
		{
			if (tempIdx / 2 - 1 >= 0 && heapArr[tempIdx] > heapArr[tempIdx / 2 - 1])
			{
				swap(heapArr[tempIdx], heapArr[tempIdx / 2 - 1]);
				tempIdx = tempIdx / 2 - 1;
			}
			else break;

		}
		else
		{
			if (heapArr[tempIdx] > heapArr[tempIdx / 2])
			{
				swap(heapArr[tempIdx], heapArr[tempIdx / 2]);
				tempIdx = tempIdx / 2;
			}
			else break;

		}
	}

	makeHeap(arr, heapArr, size, 2 * idx + 1);
	makeHeap(arr, heapArr, size, 2 * idx + 2);
}

int extractHeap(int* heapArr, int lastIdx)
{
	int result = heapArr[0];
	heapArr[0] = heapArr[lastIdx];
	heapArr[lastIdx] = -1;

	int idx = 0;
	while (true)
	{
		if (2 * idx + 2 < lastIdx)
		{
			if (heapArr[2 * idx + 1] > heapArr[2 * idx + 2])
			{
				if (heapArr[idx] < heapArr[2 * idx + 1])
				{
					swap(heapArr[idx], heapArr[2 * idx + 1]);
					idx = 2 * idx + 1;

				}
				else break;
			}
			else
			{
				if (heapArr[idx] < heapArr[2 * idx + 2])
				{
					swap(heapArr[idx], heapArr[2 * idx + 2]);
					idx = 2 * idx + 2;

				}
				else break;
			}
		}
		else if (2 * idx + 1 < lastIdx)
		{
			if (heapArr[idx] < heapArr[2 * idx + 1])
				swap(heapArr[idx], heapArr[2 * idx + 1]);

			break;
		}
		else break;
	}

	return result;
}


// �� ����
// �ߺ����� ���� ���� ���ؼ��� ���������� ������ ������ �� ������ 6 5 1 5 2 1 4(���� ���� 6�� ���� ����)�� ���� �ߺ��� ���� ���� ���� ���۵��� ����
void quickSort(int* arr, int l, int r)
{
	if (l >= r) return;

	int pivot = (l + r) / 2, i = l, j = r;
	int arrPivot = arr[pivot];
	while (i != j && arr[i] != arr[j])
	{
		// �Ʒ��� while���� ���� i�� arr[pivot] �̻��� ���� ��ġ��
		while (arr[i] < arrPivot)
		{
			i++;
		}

		// �Ʒ��� while���� ���� j�� arr[pivot] ������ ���� ��ġ��
		while (arr[j] > arrPivot)
		{
			j--;
		}

		// i�� j�� ���� �ٲ㼭 pivot�� ���ʿ��� pivot���� ���� ��, pivot�� �����ʿ��� pivot���� ū ���� ��ġ��Ŵ
		swap(arr[i], arr[j]);
	}
	pivot = i;

	quickSort(arr, l, pivot - 1);
	quickSort(arr, pivot + 1, r);

}






































// �ٺ� ���� ����
int bogoSort(int* arr, int size)
{
	int count = 0;
	while (true)
	{
		bool isSorted = true;
		for (int i = 1; i < size; i++)
			if (arr[i - 1] > arr[i]) isSorted = false;

		if (isSorted) break;

		// ������ ���ĺκ�
		int* temp = (int*)calloc(sizeof(int), size);
		bool* alreadySelectArr = (bool*)calloc(sizeof(bool), size);
		for (int i = 0; i < size; i++) temp[i] = -1;

		for (int i = 0; i < size; i++)
		{
			int ranIdx = -1;
			while (true)
			{
				ranIdx = rand() % size;
				if (!alreadySelectArr[ranIdx]) break;

			}

			alreadySelectArr[ranIdx] = true;
			temp[i] = arr[ranIdx];

		}

		count++;
		for (int i = 0; i < size; i++)
			arr[i] = temp[i];

		// temp�� alreadySelectArr�� ����ϰ� ���� ������ �� �ϸ� ������ �ʹ� ��� �����ؼ�
		// �� �� �� �����ϱ� while�� ���� ������ ���� �����ϱ�
		if (temp != NULL) free(temp);
		if (alreadySelectArr != NULL) free(alreadySelectArr);

	}

	return count;

}

void reverseArr(int* arr, int size)
{
	int* temp = (int*)calloc(sizeof(int), size);
	for (int i = 0; i < size; i++) temp[i] = arr[size - i - 1];
	for (int i = 0; i < size; i++) arr[i] = temp[i];

}

void makeRanArr(int* arr, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		//arr[i] = rand() % size;
		arr[i] = rand() % 50;
	}

}


