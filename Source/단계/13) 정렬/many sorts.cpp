#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(a, b) { int temp = a; a = b; b = temp; }


void makeRanArr(int* arr, int size);
void reverseArr(int* arr, int size);


// Big-O (n Log n)
void merge(int* arr, int* sortArr, int l, int m, int r);	// 병합 정렬
void mergeSort(int* arr, int* sortArr, int l, int r);

void heapSort(int* arr, int size);		// 힙 정렬
void makeHeap(int* arr, int* heapArr, int size, int idx);
int extractHeap(int* heapArr, int lastIdx);

void quickSort(int* arr, int l, int r);	// 퀵 정렬 

// Big-O (n2) 
void bubbleSort(int* arr, int size);	// 버블 정렬 | 가장 단순한 버전의 정렬, 쉽지만 시간 복잡도가 최악이고 케이스가 정말 작을 때, 1000 이하 정도일 때만 사용하고 그 이외에는 공부용
void insertSort(int* arr, int size);	// 삽입 정렬 | 최고의 경우에는 n, 최악의 경우에는 n2, 평균 n2
void selectSort(int* arr, int size);	// 선택 정렬 | 선택 정렬은 입력이 정렬되어 있든지 랜덤하게 되어 있든지 구분없이 항상 O(n2)의 시간복잡도를 가짐


// Big-O (n?) (1부터 무한까지 다양함)
int bogoSort(int* arr, int size);


int main()
{
	int n = 0;
	printf("배열 크기를 입력하세요: ");
	scanf("%d", &n);
	int* arr = (int*)calloc(sizeof(int), n);

	// n개의 값을 입력 하는 부분
	//for (int i = 0; i < n; i++)
	//{
	//	int temp;
	//	scanf("%d", &temp);
	//	arr[i] = temp;

	//}

	makeRanArr(arr, n);

	printf("정렬 전 값: ");
	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
	printf("\n");


	heapSort(arr, n);


	printf("\n\n정렬 후 값: ");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");




}








// 버블 정렬
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


// 삽입 정렬
void insertSort(int* arr, int size)
{
	// 삽입 정렬은 cur에서 이전 pre와 값을 비교해서 cur(pre보다 뒤의 값)이 pre보다 작다면 cur과 pre를 바꿈
	// 바꾸고 나서 cur과 pre를 둘 다 1씩 줄여서 cur가 pre값보다 이상인 경우에 while을 벗어남, 그리고 cur의 위치를 다시 원래 위치로 되돌림

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


// 선택 정렬
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





// 병합 정렬
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


// 힙 정렬
void heapSort(int* arr, int size)
{
	int* heapArr = (int*)calloc(sizeof(int), size);

	makeHeap(arr, heapArr, size, 0);

	printf("힙: ");
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


// 퀵 정렬
// 중복되지 않은 값에 대해서는 정상적으로 정렬을 실행할 수 있지만 6 5 1 5 2 1 4(제일 앞의 6은 숫자 갯수)와 같이 중복된 값이 있을 때는 오작동이 있음
void quickSort(int* arr, int l, int r)
{
	if (l >= r) return;

	int pivot = (l + r) / 2, i = l, j = r;
	int arrPivot = arr[pivot];
	while (i != j && arr[i] != arr[j])
	{
		// 아래의 while문을 통해 i는 arr[pivot] 이상의 값에 위치함
		while (arr[i] < arrPivot)
		{
			i++;
		}

		// 아래의 while문을 통해 j는 arr[pivot] 이하의 값에 위치함
		while (arr[j] > arrPivot)
		{
			j--;
		}

		// i와 j를 서로 바꿔서 pivot의 왼쪽에는 pivot보다 작은 값, pivot의 오른쪽에는 pivot보다 큰 값을 위치시킴
		swap(arr[i], arr[j]);
	}
	pivot = i;

	quickSort(arr, l, pivot - 1);
	quickSort(arr, pivot + 1, r);

}






































// 바보 병신 정렬
int bogoSort(int* arr, int size)
{
	int count = 0;
	while (true)
	{
		bool isSorted = true;
		for (int i = 1; i < size; i++)
			if (arr[i - 1] > arr[i]) isSorted = false;

		if (isSorted) break;

		// 무작위 정렬부분
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

		// temp와 alreadySelectArr을 사용하고 나서 해제를 안 하면 공간을 너무 계속 차지해서
		// 펑 될 수 있으니까 while이 끝날 때마다 공간 해제하기
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


