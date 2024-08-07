#include <stdio.h>
#include <stdlib.h>

typedef struct Deque
{
	int num;
	struct Deque* pre;
	struct Deque* next;

} Deque;


void pushFront(Deque** head, Deque** tail, int n)
{
	Deque* temp = (Deque*)calloc(sizeof(Deque), 1);
	temp->num = n;

	if (*head == NULL)
	{
		*head = temp;
		*tail = temp;

	}
	else
	{
		(*head)->pre = temp;
		temp->next = *head;
		*head = temp;

	}
}

void pushBack(Deque** head, Deque** tail, int n)
{
	Deque* temp = (Deque*)calloc(sizeof(Deque), 1);
	temp->num = n;

	if (*tail == NULL)
	{
		*head = temp;
		*tail = temp;

	}
	else
	{
		(*tail)->next = temp;
		temp->pre = *tail;
		*tail = temp;

	}
}


int popFront(Deque** head, Deque** tail)
{
	if (*head == NULL) return -1;
	else if ((*head)->next == NULL)
	{
		int result = (*head)->num;
		free(*head);
		*head = NULL;
		*tail = NULL;
		return result;

	}
	else
	{
		Deque* next = (*head)->next;
		next->pre = NULL;
		int result = (*head)->num;
		free(*head);
		*head = next;
		return result;

	}
}

int popBack(Deque** head, Deque** tail)
{
	if (*tail == NULL) return -1;
	else if ((*tail)->pre == NULL)
	{
		int result = (*tail)->num;
		free(*tail);
		*head = NULL;
		*tail = NULL;
		return result;

	}
	else
	{
		Deque* pre = (*tail)->pre;
		pre->next = NULL;
		int result = (*tail)->num;
		free(*tail);
		*tail = pre;
		return result;

	}
}


int dequeSize(Deque* head)
{
	Deque* temp = head;
	int size = 0;
	while (temp != NULL)
	{
		size++;
		temp = temp->next;

	}

	return size;
}

int dequeEmpty(Deque* head)
{
	if (head == NULL) return 1;
	return 0;

}

int dequeFront(Deque* head)
{
	if (head == NULL) return -1;
	return head->num;

}

int dequeBack(Deque* tail)
{
	if (tail == NULL) return -1;
	return tail->num;

}



int main()
{
	int n; scanf("%d", &n);
	char whiteSpace = getchar();

	Deque* head = NULL, * tail = NULL;
	for (int i = 0; i < n; i++)
	{
		char command[11]; scanf("%s", command);
		whiteSpace = getchar();

		if (whiteSpace == ' ')
		{
			int num; scanf("%d", &num);
			whiteSpace = getchar();

			if (command[5] == 'f')
			{
				pushFront(&head, &tail, num);

			}
			else
			{
				pushBack(&head, &tail, num);

			}
		}
		else
		{
			switch (command[0])
			{
			case 'p':
			{
				if (command[4] == 'f')
				{
					printf("%d\n", popFront(&head, &tail));

				}
				else
				{
					printf("%d\n", popBack(&head, &tail));

				}

				break;
			}
			case 'f':
			{
				printf("%d\n", dequeFront(head));
				break;

			}
			case 'b':
			{
				printf("%d\n", dequeBack(tail));
				break;

			}
			case 's':
			{
				printf("%d\n", dequeSize(head));
				break;

			}
			case 'e':
			{
				printf("%d\n", dequeEmpty(head));
				break;

			}
			}
		}

	}

	return 0;

}

