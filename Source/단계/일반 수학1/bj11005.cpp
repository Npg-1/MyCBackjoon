#include <stdio.h>
#include <stdlib.h>

// 이 코드 이것보다 훨씬 쉽게 짤 수 있는 방법이 있으니까 생각해보자
// 내가 발전이 없어서 안 되겠다 싶을때 볼 수 있게 힌트를 맨 아래에 작성함

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






































// 이걸 왜 봐? 보면 안 되는 거잖아
// 힌트로 정확한 이유는 모르겠지만 n이라는 숫자를 b진법의 b로 나누면 b진법의 한 자리 수가 나옴
// ex) 
//	 26(10진법) -> 26 % 10 == 6
//	 ZZZZZ(36진법) -> ZZZZZ(10진법 변환 60466175) % 36 == 35(Z)


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

