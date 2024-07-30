#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue
{
	int num;
	struct Queue* next;

}Queue;


int queueSize(Queue* head)
{
	Queue* temp = head;
	int size = 0;
	while (temp != NULL)
	{
		size++;
		temp = temp->next;

	}
	return size;

}

int queueEmpty(Queue* head)
{
	if (head == NULL) return 1;
	return 0;

}

int queueFront(Queue* head)
{
	if (head == NULL) return -1;
	return head->num;

}

int queueBack(Queue* tail)
{
	if (tail == NULL) return -1;
	return tail->num;

}


Queue* addQueue(Queue* tail, int num)
{
	Queue* temp = (Queue*)calloc(sizeof(Queue), 1);
	temp->num = num;

	if (tail != NULL)
	{
		tail->next = temp;

	}

	return temp;
}

Queue* removeQueue(Queue* head)
{
	if (head == NULL)
	{
		printf("-1\n");
		return head;

	}

	int n = head->num;
	Queue* next = head->next;
	printf("%d\n", n);
	free(head);
	return next;

}




void excuteCommand(Queue** head, Queue** tail, char command, int num)
{
	switch (command)
	{
	case 'u':	// push
	{
		*tail = addQueue(*tail, num);
		if (queueSize(*head) == 0)
		{
			*head = *tail;

		}

		break;

	}
	case 'o':	// pop
	{
		*head = removeQueue(*head);
		if (queueSize(*head) == 0)
		{
			*tail = *head;

		}

		break;

	}
	case 'i':	// size
	{
		printf("%d\n", queueSize(*head));
		break;

	}
	case 'm':	// empty
	{
		printf("%d\n", queueEmpty(*head));
		break;

	}
	case 'r':	// front
	{
		printf("%d\n", queueFront(*head));
		break;

	}
	case 'a':	// back
	{
		printf("%d\n", queueBack(*tail));
		break;

	}
	}
}

int main()
{
	int n; scanf("%d", &n);
	char whiteSpace = getchar();

	Queue* head = NULL;
	Queue* tail = head;

	for (int i = 0; i < n; i++)
	{
		char command[6]; scanf("%s", command);
		whiteSpace = getchar();

		if (whiteSpace == ' ')
		{
			int num; scanf("%d", &num);
			excuteCommand(&head, &tail, command[1], num);

			whiteSpace = getchar();

		}
		else
		{
			excuteCommand(&head, &tail, command[1], 0);

		}
	}
}

