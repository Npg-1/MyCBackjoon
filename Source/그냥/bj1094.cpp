#include <stdio.h>

int main()
{
	int n; scanf("%d", &n);

	int arr[6];
	arr[0] = 64;
	for (int i = 1; i < 6; i++)arr[i] = 0;

	int idx = 0;	// ���� ª�� ���� ��ġ�� �ε���
	while (true)
	{
		// 1. ������ ���̸� �� ���ؼ� n�� �Ǿ����� Ȯ��
		int sum = 0;
		for (int i = 0; i < 6; i++) sum += arr[i];
		if (sum == n) break;

		// ������ �ִ� ���� �� ���̰� ���� ª�� ���� �������� �ڸ�
		int a = arr[idx];
		arr[idx] = a / 2;
		arr[idx + 1] = a / 2;

		// �������� ©�� ���� ������ �������� ���� X���� ũ�ٸ� �������� ©�� ���� ����
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
