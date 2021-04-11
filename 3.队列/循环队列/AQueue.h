#ifndef AQUEUE_H_INCLUDED
#define AQUEUE_H_INCLUDED

#define MAXQUEUE 10

//ѭ�����нṹ
typedef struct Aqueue
{	
	void *data[MAXQUEUE];      //������     ��ŵ��� *���� 
    int front;
    int rear;
    size_t length;        //���г���
} AQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;

char type;
char datatype[MAXQUEUE];

void InitAQueue(AQueue *Q);
void DestoryAQueue(AQueue *Q);
Status IsFullAQueue(const AQueue *Q);
Status IsEmptyAQueue(const AQueue *Q);
Status GetHeadAQueue(AQueue *Q, void *e);
int LengthAQueue(AQueue *Q);
Status EnAQueue(AQueue *Q, void *data);
Status DeAQueue(AQueue *Q);	
void ClearAQueue(AQueue *Q);
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q));	
void APrint(void *q);

#endif	

