#include <stdio.h>

int main()
{
	int n; scanf("%d", &n);

	int arr[6];
	arr[0] = 64;
	for (int i = 1; i < 6; i++)arr[i] = 0;

	int idx = 0;	// 가장 짧은 것이 위치한 인덱스
	while (true)
	{
		// 1. 막대의 길이를 다 더해서 n이 되었는지 확인
		int sum = 0;
		for (int i = 0; i < 6; i++) sum += arr[i];
		if (sum == n) break;

		// 가지고 있는 막대 중 길이가 가장 짧은 것을 절반으로 자름
		int a = arr[idx];
		arr[idx] = a / 2;
		arr[idx + 1] = a / 2;

		// 절반으로 짤린 것을 제외한 나머지의 합이 X보다 크다면 절반으로 짤린 것을 버림
		int umm = 0;
		for (int i = 0; i <= idx; i++) umm += arr[i];

		if (umm >= n)
			arr[idx + 1] = 0;
		else
			idx++;
	}

	printf("%d\n", idx + 1);

	return 0;

}
