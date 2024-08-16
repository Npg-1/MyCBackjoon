#include <stdio.h>

void setSieveOfEratosthenes(bool primeNumArr[])
{
	for (int i = 2; i < 500; i++)
	{
		// i�� �Ҽ��� ��쿡�� ����, �Ҽ��� �ƴѵ��� for�� ���� �����ڳ�.... chat gpt�� ��������
		if (primeNumArr[i])
		{
			for (int j = i * 2; j < 1001; j += i)
				primeNumArr[j] = false;

		}
	}
}


int main()
{
	bool primeNumArr[1001];

	// �� ��ǻ�Ϳ����� primeNumArr[i]�� ���� true�� �� ���൵ ���� �� true�� �Ǿ� �־����� 
	// ���ؿ����� C++�� �����ؼ� �׷��� true�� �� �Ǿ��ִ� ������ �־ Ʋ�Ⱦ���, ���� �����
	for (int i = 0; i <= 1000; i++) primeNumArr[i] = true;
	primeNumArr[1] = false;

	setSieveOfEratosthenes(primeNumArr);

	int n, count = 0; scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int temp; scanf("%d", &temp);
		if (primeNumArr[temp]) count++;

	}

	printf("%d\n", count);

	return 0;
}

