#include <stdio.h>
#include "queue.h"

Queue MakeQueue()
{
    Queue q;
    IDX_HEAD(q) = IDX_UNDEF;
    IDX_TAIL(q) = IDX_UNDEF;

    return q;
}

boolean isQueueEmpty(Queue q)
{
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}

boolean isQueueFull(Queue q)
{
    return (IDX_TAIL(q) + 1 == QUEUECAPACITY);
}

int queueLength(Queue q)
{
    if (!isQueueEmpty(q))
    {
        return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
    }
    else
    {
        return 0;
    }
}

void enqueue(Queue *q, ElType val)
{
    if (isQueueEmpty(*q))
    {
        IDX_HEAD(*q) = 0;
    }
    IDX_TAIL(*q) = IDX_TAIL(*q) + 1;

    CopyWord(&TAIL(*q), val);
}

void dequeue(Queue *q, ElType *val)
{
    CopyWord(val, HEAD(*q));
    if (queueLength(*q) == 1)
    {
        IDX_HEAD(*q) = IDX_UNDEF;
    }
    else
    {
        for (int i = IDX_HEAD(*q); i < IDX_TAIL(*q); i++)
        {
            CopyWord(&QUEUEELMT(*q, i), QUEUEELMT(*q, i + 1));
        }
    }
    IDX_TAIL(*q) -= 1;
}

void displayQueue(Queue q)
{
    if (isQueueEmpty(q))
    {
        printf("\n=========== Daftar Kosong ===========\n");
    }
    else
    {
        int i;
        for (i = 0; i < queueLength(q); i++)
        {
            printf("%d. ", i + 1);
            int j;
            for (j = 0; j < QUEUEELMT(q, i).Length; j++)
            {
                printf("%c", QUEUEELMT(q, i).TabWord[j]);
            }
            printf("\n");
        }
    }
}