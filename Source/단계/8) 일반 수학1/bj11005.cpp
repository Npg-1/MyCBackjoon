#include <stdio.h>
#include <stdlib.h>

// �� �ڵ� �̰ͺ��� �ξ� ���� © �� �ִ� ����� �����ϱ� �����غ���
// ���� ������ ��� �� �ǰڴ� ������ �� �� �ְ� ��Ʈ�� �� �Ʒ��� �ۼ���

int main()
{
	int num, nSystem;

	scanf("%d%d", &num, &nSystem);

	int theNumberOfDigits = 0;
	int temp = num;
	while (temp != 0)
	{
		temp /= nSystem;
		theNumberOfDigits++;
	}

	char* arr = (char*)calloc(sizeof(char), theNumberOfDigits + 1);
	arr[theNumberOfDigits] = NULL;

	int idx = 0;
	while (theNumberOfDigits != 0)
	{
		int umm = 1;
		for (int i = 0; i < theNumberOfDigits - 1; i++)
			umm *= nSystem;

		int umm2 = num / umm;
		if (umm2 < 10)
			arr[idx++] = umm2 + '0';
		else
			arr[idx++] = (umm2 - 10 + 'A');

		num -= (umm * umm2);
		theNumberOfDigits--;

	}

	printf("%s\n", arr);

	return 0;

}






































// �̰� �� ��? ���� �� �Ǵ� ���ݾ�
// ��Ʈ�� ��Ȯ�� ������ �𸣰����� n�̶�� ���ڸ� b������ b�� ������ b������ �� �ڸ� ���� ����
// ex) 
//	 26(10����) -> 26 % 10 == 6
//	 ZZZZZ(36����) -> ZZZZZ(10���� ��ȯ 60466175) % 36 == 35(Z)


#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, b;
	scanf("%d%d", &n, &b);

	int length = 0;
	int temp = n;
	while (temp != 0)
	{
		temp /= b;
		length++;
	}

	char* arr = (char*)calloc(sizeof(char), length + 1);
	arr[length] = NULL;

	for (int i = length - 1; i >= 0; i--)
	{
		arr[i] = (n % b < 10) ? (n % b + '0') : (n % b - 10 + 'A');
		n /= b;

	}

	printf("%s\n", arr);

	return 0;
}

