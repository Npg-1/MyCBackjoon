#include <stdio.h>

void setSieveOfEratosthenes(bool primeNumArr[])
{
	for (int i = 2; i < 500; i++)
	{
		// i가 소수인 경우에만 진행, 소수가 아닌데도 for을 돌면 낭비자나.... chat gpt가 가르쳐줌
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

	// 내 컴퓨터에서는 primeNumArr[i]를 따로 true로 안 해줘도 전부 다 true로 되어 있었지만 
	// 백준에서는 C++로 제출해서 그런가 true로 안 되어있던 문제가 있어서 틀렸었음, ㅈㄴ 억울함
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

