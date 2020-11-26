//regard an array as a circular queue
#define MaxLength 100

typedef int ElementType;
typedef struct
{
    ElementType Elements[MaxLength];
    //Store the elements
    int Front, Rear;
} Queue;
void MakeNull_Queue(Queue *Q)
{
    Q->Front = -1;
    Q->Rear = -1;
}
int Empty_Queue(Queue Q)
{
    return Q.Front == -1;
}
int Full_Queue(Queue Q)
{
    return (Q.Rear - Q.Front + 1) % MaxLength == 0;
}
void DeQueue(Queue *Q)
{
    if (!Empty_Queue(*Q))
    { //if queue contain only one element
        if (Q->Front == Q->Rear)
            MakeNull_Queue(Q);
        else
            Q->Front = (Q->Front + 1) % MaxLength;
    }
    else
        printf("Queue is empty!");
}
void EnQueue(ElementType X, Queue *Q)
{
    if (!Full_Queue(*Q))
    {
        if (Empty_Queue(*Q))
            Q->Front = 0;
        Q->Rear = (Q->Rear + 1) % MaxLength;
        Q->Elements[Q->Rear] = X;
    }
    else
        printf("Queue is full!");
}