#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(char* stack, char ch, int* stackSize)
{
	if (*stackSize == 100000) return;
	stack[*stackSize] = ch;
	(*stackSize)++;

}

char pop(char* stack, int* stackSize)
{
	if (*stackSize == 0) return -1;

	char result = stack[*stackSize - 1];
	stack[--(*stackSize)] = 0;

	return result;

}

char getTop(char* stack, int* stackSize)
{
	if (*stackSize == 0) return -1;
	return stack[*stackSize - 1];

}



// Plus, Minus 연산
void calculatePM(char* stack, int* stackSize, char ch)
{
	char top = getTop(stack, stackSize);
	if (*stackSize == 0 || top == '(')
	{
		push(stack, ch, stackSize);

	}
	else
	{
		if (top == '*' || top == '/')
		{
			printf("%c", pop(stack, stackSize));
			top = getTop(stack, stackSize);
			if (top == '+' || top == '-')
				printf("%c", pop(stack, stackSize));

			push(stack, ch, stackSize);

		}
		else if (top == '+' || top == '-')
		{
			printf("%c", pop(stack, stackSize));
			push(stack, ch, stackSize);

		}
	}
}

// Multiple, Divide 연산
void calculateMD(char* stack, int* stackSize, char ch)
{
	char top = getTop(stack, stackSize);
	if (*stackSize == 0 || top == '(')
	{
		push(stack, ch, stackSize);

	}
	else
	{
		if (top == '*' || top == '/')
		{
			printf("%c", pop(stack, stackSize));
			push(stack, ch, stackSize);

		}
		else if (top == '+' || top == '-')
		{
			push(stack, ch, stackSize);

		}
	}
}

// 소괄호 연산
void calculatePar(char* stack, int* stackSize, char* notation, int* i)
{
	push(stack, notation[*i], stackSize);	// notation[i] 가 아니라 '('를 해도 같음
	(*i)++;

	while (notation[*i] != ')')
	{
		if (notation[*i] == '(')
		{
			calculatePar(stack, stackSize, notation, i);

		}
		else if (notation[*i] == '*' || notation[*i] == '/')
		{
			calculateMD(stack, stackSize, notation[*i]);

		}
		else if (notation[*i] == '+' || notation[*i] == '-')
		{
			calculatePM(stack, stackSize, notation[*i]);

		}
		else
		{
			printf("%c", notation[*i]);

		}
		(*i)++;

	}

	while (getTop(stack, stackSize) != '(')
		printf("%c", pop(stack, stackSize));

	pop(stack, stackSize);

}


int main()
{
	// 해당 문제의 풀이를 보고 싶으면 맨 아래로 이동
	char notation[101]; scanf("%s", notation);

	char* stack = (char*)calloc(sizeof(char), strlen(notation));
	int stackSize = 0;

	for (int i = 0; i < strlen(notation); i++)
	{
		if (notation[i] == '(')
		{
			calculatePar(stack, &stackSize, notation, &i);

		}
		else if (notation[i] == '*' || notation[i] == '/')
		{
			calculateMD(stack, &stackSize, notation[i]);

		}
		else if (notation[i] == '+' || notation[i] == '-')
		{
			calculatePM(stack, &stackSize, notation[i]);

		}
		else
		{
			printf("%c", notation[i]);

		}
	}

	while (stackSize != 0)
	{
		printf("%c", pop(stack, &stackSize));

	}

	return 0;

}








































// 풀이
// 1918 후위표기식 문제는 중위표기식을 후위표기식으로 변환하면 되는 문제이다.
// 
// (+, -), (*, / ) 와 같은 사칙연산, 그리고() 소괄호이다.
// 우선순위가 가장 높은 것은 소괄호 ->*, / -> + , -순서인데
// 우선순위가 같은 + , -가 있다 해도 A + B - C가 있으면 - 보다 먼저 나온 + 가 먼저 연산된다.
//
//
// 내가 작성한 코드에서는 for문으로 notation(입력된 중위 표기식)을 한 글자씩 돌면서 확인한다.
// 스택은 선입후출로 마지막에 들어온 게 가장 먼저 사용되는 점을 사용해서 스택에는 연산자와 소괄호만 입력한다.
//
// 스택에서 소괄호를 제외하면(아마도) 스택이 가질 수 있는 모양은 3가지 밖에 없다.
// + or -
// *or /
// +or -, * or /
//
// 소괄호를 제외하고 생각했을 때
//
// - 지금 입력하려는 것이 + (-는 제외하고 생각, 이하 현재값)일 때, 스택의 top이 같은 우선순위인 + 인 경우 스택의 + 를 먼저 pop하고 현재값을 push함
// 스택에는 소괄호를 제외하면 + 가 들어있는 것 말고는 다른 + 나 * 가 들어있을 수는 없으므로 하나를 먼저 pop하고 현재값을 push하면 됨
//
// - 지금 입력하려는 것이 + 일 때, 스택의 top이* 인 경우 스택이 가질 수 있는 모습이[*] 이거나[+| *] 이므로 일단 먼저 top을 pop하고
// + 가 남아있으면 그것도 pop한다.이유는 위와 동일하게 스택에 있는 것이 더 먼저 연산되어야하기 때문 그리고 나서 현재값을 push함
//
// - 지금 입력하려는 것이 * (/ 는 제외하고 생각)일 때, 스택의 top이 + 인 경우 현재값을 그냥 push하면 됨 왜냐하면 우선순위가 높은 현재값이
// 스택의 top에 위치해야 먼저 처리되기 때문
//
// - 지금 입력하려는 것이 * (/ 는 제외하고 생각)일 때, 스택의 top이* 인 경우 현재값과 top이 우선순위는 같지만 스택의 top이 현재값보다 먼저 등장했으므로
// 스택의 top을 pop하고 현재값을 push함
//
//
// 위의 내용으로 함수를 구현한다음 소괄호 연산함수를 구현하면 되는데
// notation에서 글자를 판별할 때 '('를 인식하면 소괄호 연산함수를 호출한다.
// '('는 스택에 넣고 그 이후의 문자부터 ')'가 나올때까지 while문을 돌며 연산한다.
// while문에서는 그냥 사칙연산에 사용한 함수를 그대로 사용하고
// 여기서 특이점으로 만일 이중 이상으로 '('가 겹칠 경우 소괄호 연산함수를 재귀호출해서 해당 과정을 반복한다.
//
// while문이 끝나면 stack의 '('를 발견할 때 까지 pop한다.

















