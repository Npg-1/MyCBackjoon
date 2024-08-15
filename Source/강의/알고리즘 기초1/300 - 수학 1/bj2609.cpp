#include <stdio.h>

int getG(int a, int b)
{
	if (a % b == 0) return b;
	return getG(b, a % b);

}

int main()
{
	// 유클리드 호제법 a = b * p + r 일 때, G(a, b) == G(b, r)과 같음 그리고 두 자연수 a, b 중에서 a > b일 때 
	// b가 a의 약수이면 b가 최대공약수임 ex) G(12, 4) = 4, G(40, 10) = 10
	// 위의 사실을 조합하면 재귀를 통해 두 자연수 a, b의 최대공약수를 구할 수 있음

	// 최소공배수 == 두 자연수의 곱 / 최대공약수

	int a, b; scanf("%d%d", &a, &b);
	int g = getG(a, b);
	printf("%d\n%d", g, a * b / g);

	return 0;

}
