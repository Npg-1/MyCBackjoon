#include <stdio.h>

int main()
{
	// 진짜 쉽지 않음, 예제가 좋아서 푼 느낌이 강함, 예제 입력이 1개만 빠져도 진짜 풀기 어려웠을 거 같음
	// 이 문제는 여러모로 조금 알아둬야 할 거 같음 
	int a, b, v;
	scanf("%d%d%d", &a, &b, &v);

	int day = (v - a) / (a - b);
	if (((v - a) % (a - b)) != 0) day++;

	printf("%d", day + 1);

	return 0;

}
