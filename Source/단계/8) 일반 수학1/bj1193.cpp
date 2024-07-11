#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	// arr�� �м��� �� 2���� �迭�� ù ��° ���� ������ ���� �迭
	// arr�� �� ��Ҵ� 1���� �����ϴµ� �� ����� �ε����� ������
	// ���� n�� arr[i]���� ũ�ų� ���ٸ� n�� i�̻��� ������ ���Ѵٴ� ���� �ǹ���
	// ���� n�� arr[i]���� �۴ٰ� �ϸ� n�� i�̸��� ������ ���Ѵٴ� ���� �ǹ���
	// �� n�� arr[i] �̻��̰�, n�� arr[i+1]�̸��̸� n�� ���� i�� ����
	int arr[4500] = { 0, };
	arr[1] = 1;
	for (int i = 2; i < 4500; i++)
	{
		arr[i] = arr[i - 1] + (i - 1);

	}

	// �м��� �и� + ������ �� = level + 1�� ����
	// n�� �ش� ������ ù ��° �� ��, arr[level]�� ������ ���̸� ���� n�� ��ġ�� �ľ��� �� ����
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
