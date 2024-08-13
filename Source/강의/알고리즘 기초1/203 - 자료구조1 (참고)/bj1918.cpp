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



// Plus, Minus ����
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

// Multiple, Divide ����
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

// �Ұ�ȣ ����
void calculatePar(char* stack, int* stackSize, char* notation, int* i)
{
	push(stack, notation[*i], stackSize);	// notation[i] �� �ƴ϶� '('�� �ص� ����
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
	// �ش� ������ Ǯ�̸� ���� ������ �� �Ʒ��� �̵�
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








































// Ǯ��
// 1918 ����ǥ��� ������ ����ǥ����� ����ǥ������� ��ȯ�ϸ� �Ǵ� �����̴�.
// 
// (+, -), (*, / ) �� ���� ��Ģ����, �׸���() �Ұ�ȣ�̴�.
// �켱������ ���� ���� ���� �Ұ�ȣ ->*, / -> + , -�����ε�
// �켱������ ���� + , -�� �ִ� �ص� A + B - C�� ������ - ���� ���� ���� + �� ���� ����ȴ�.
//
//
// ���� �ۼ��� �ڵ忡���� for������ notation(�Էµ� ���� ǥ���)�� �� ���ھ� ���鼭 Ȯ���Ѵ�.
// ������ ��������� �������� ���� �� ���� ���� ���Ǵ� ���� ����ؼ� ���ÿ��� �����ڿ� �Ұ�ȣ�� �Է��Ѵ�.
//
// ���ÿ��� �Ұ�ȣ�� �����ϸ�(�Ƹ���) ������ ���� �� �ִ� ����� 3���� �ۿ� ����.
// + or -
// *or /
// +or -, * or /
//
// �Ұ�ȣ�� �����ϰ� �������� ��
//
// - ���� �Է��Ϸ��� ���� + (-�� �����ϰ� ����, ���� ���簪)�� ��, ������ top�� ���� �켱������ + �� ��� ������ + �� ���� pop�ϰ� ���簪�� push��
// ���ÿ��� �Ұ�ȣ�� �����ϸ� + �� ����ִ� �� ����� �ٸ� + �� * �� ������� ���� �����Ƿ� �ϳ��� ���� pop�ϰ� ���簪�� push�ϸ� ��
//
// - ���� �Է��Ϸ��� ���� + �� ��, ������ top��* �� ��� ������ ���� �� �ִ� �����[*] �̰ų�[+| *] �̹Ƿ� �ϴ� ���� top�� pop�ϰ�
// + �� ���������� �װ͵� pop�Ѵ�.������ ���� �����ϰ� ���ÿ� �ִ� ���� �� ���� ����Ǿ���ϱ� ���� �׸��� ���� ���簪�� push��
//
// - ���� �Է��Ϸ��� ���� * (/ �� �����ϰ� ����)�� ��, ������ top�� + �� ��� ���簪�� �׳� push�ϸ� �� �ֳ��ϸ� �켱������ ���� ���簪��
// ������ top�� ��ġ�ؾ� ���� ó���Ǳ� ����
//
// - ���� �Է��Ϸ��� ���� * (/ �� �����ϰ� ����)�� ��, ������ top��* �� ��� ���簪�� top�� �켱������ ������ ������ top�� ���簪���� ���� ���������Ƿ�
// ������ top�� pop�ϰ� ���簪�� push��
//
//
// ���� �������� �Լ��� �����Ѵ��� �Ұ�ȣ �����Լ��� �����ϸ� �Ǵµ�
// notation���� ���ڸ� �Ǻ��� �� '('�� �ν��ϸ� �Ұ�ȣ �����Լ��� ȣ���Ѵ�.
// '('�� ���ÿ� �ְ� �� ������ ���ں��� ')'�� ���ö����� while���� ���� �����Ѵ�.
// while�������� �׳� ��Ģ���꿡 ����� �Լ��� �״�� ����ϰ�
// ���⼭ Ư�������� ���� ���� �̻����� '('�� ��ĥ ��� �Ұ�ȣ �����Լ��� ���ȣ���ؼ� �ش� ������ �ݺ��Ѵ�.
//
// while���� ������ stack�� '('�� �߰��� �� ���� pop�Ѵ�.

















