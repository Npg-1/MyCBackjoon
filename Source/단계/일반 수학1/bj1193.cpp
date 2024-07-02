#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	// arr은 분수로 된 2차원 배열의 첫 번째 행의 값들을 담은 배열
	// arr의 각 요소는 1부터 시작하는데 각 요소의 인덱스가 레벨임
	// 만일 n이 arr[i]보다 크거나 같다면 n은 i이상의 레벨에 속한다는 것을 의미함
	// 만일 n이 arr[i]보다 작다고 하면 n은 i미만의 레벨에 속한다는 것을 의미함
	// 즉 n이 arr[i] 이상이고, n이 arr[i+1]미만이면 n은 레벨 i에 속함
	int arr[4500] = { 0, };
	arr[1] = 1;
	for (int i = 2; i < 4500; i++)
	{
		arr[i] = arr[i - 1] + (i - 1);

	}

	// 분수의 분모 + 분자의 값 = level + 1과 같음
	// n의 해당 레벨의 첫 번째 값 즉, arr[level]의 값과의 차이를 통해 n의 위치를 파악할 수 있음
	int level = 4500;
	while (true)
	{
		if (n >= arr[level] && n < arr[level + 1]) break;
		level--;

	}

	if (level % 2 == 1)
		printf("%d/%d", level - n + arr[level], n - arr[level] + 1);
	else
		printf("%d/%d", n - arr[level] + 1, level - n + arr[level]);

	return 0;
}
