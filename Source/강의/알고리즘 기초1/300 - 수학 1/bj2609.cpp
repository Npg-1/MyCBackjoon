#include <stdio.h>

int getG(int a, int b)
{
	if (a % b == 0) return b;
	return getG(b, a % b);

}

int main()
{
	// ��Ŭ���� ȣ���� a = b * p + r �� ��, G(a, b) == G(b, r)�� ���� �׸��� �� �ڿ��� a, b �߿��� a > b�� �� 
	// b�� a�� ����̸� b�� �ִ������� ex) G(12, 4) = 4, G(40, 10) = 10
	// ���� ����� �����ϸ� ��͸� ���� �� �ڿ��� a, b�� �ִ������� ���� �� ����

	// �ּҰ���� == �� �ڿ����� �� / �ִ�����

	int a, b; scanf("%d%d", &a, &b);
	int g = getG(a, b);
	printf("%d\n%d", g, a * b / g);

	return 0;

}
