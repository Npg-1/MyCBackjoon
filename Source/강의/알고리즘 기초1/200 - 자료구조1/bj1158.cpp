#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int num;
    struct Queue* next;

}Queue;

void enqueue(Queue** head, Queue** tail, int num)
{
    Queue* temp = (Queue*)calloc(sizeof(Queue), 1);
    temp->num = num;

    if (*head == NULL)
    {
        *head = temp;
        *tail = temp;

    }
    else
    {
        (*tail)->next = temp;
        (*tail) = temp;

    }
}

int dequeue(Queue** head, Queue** tail)
{
    if (*head == NULL)
    {
        return -1;

    }
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
        int result = (*head)->num;
        Queue* temp = (*head)->next;
        free(*head);
        *head = temp;
        return result;

    }
}


int main()
{
    int n, k; scanf("%d%d", &n, &k);

    Queue* head = NULL;
    Queue* tail = NULL;
    for (int i = 0; i < n; i++) enqueue(&head, &tail, i + 1);

    printf("<");
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < k - 1; j++)
        {
            int n = dequeue(&head, &tail);
            enqueue(&head, &tail, n);

        }
        printf("%d, ", dequeue(&head, &tail));

    }
    printf("%d>\n\n", dequeue(&head, &tail));

    return 0;
}
