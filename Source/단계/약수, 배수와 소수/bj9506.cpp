#include <stdio.h>
#include <stdlib.h>

int main()
{
	// ������ ������ �ڵ尡 �ʹ� �������ϰ� �� ��ȿ������ �� ����, ã�ƺ��ϱ� �������� ���ϴ� ������ �ִ� �� ������
	// �װ� ����ؼ� �ڵ带 �� ���̰� �������� ���� �� ���� ���� ��, ��ư ���� ���������� ���߿� �ѹ� �� «���� �غ���

	while (true)
	{
		int n;
		scanf("%d", &n);

		if (n == -1) break;

		int* arr = (int*)calloc(sizeof(int), n);
		int idx = 0;

		for (int i = 1; i <= n; i++)
		{
			if (n % i == 0)
			{
				arr[idx++] = i;
			}

		}

		int sum = 0;
		for (int i = 0; arr[i] != 0; i++)
		{
			sum += arr[i];
		}

		if (sum - n == n)
		{
			int umm = 0;
			for (int i = 0; i < n; i++) if (arr[i] == n) umm = i - 1;

			printf("%d = ", n);
			for (int i = 0; i < umm; i++)
				printf("%d + ", arr[i]);
			printf("%d\n", arr[umm]);

		}
		else printf("%d is NOT perfect.\n", n);

	}

	return 0;

}
