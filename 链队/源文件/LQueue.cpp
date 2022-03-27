#include "LQueue.h"

//typedef struct node
//{
//    void* data;                   //������ָ��
//    struct node* next;            //ָ��ǰ������һ���
//} Node;
//
//typedef struct Lqueue
//{
//    Node* front;                   //��ͷ
//    Node* rear;                    //��β
//    size_t length;            //���г���
//} LQueue;

//typedef enum
//{
//    FALSE = 0, TRUE = 1
//} Status;
//char type;
//char datatype[30];


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue* Q)
{
	(Q->front) = (Q->rear) = (Node*)malloc(sizeof(Node));				//ΪQ->front��Q->rear�����ڴ�
	if (Q->front == NULL || Q->rear == NULL)
	{
		printf("��ʼ��ʧ��\n");
		return;
	}
	Q->front->next =  NULL;								//ʹQ->front��Q->rearֱ��NULL
	Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *  @notice      : None
 */
void DestoryLQueue(LQueue* Q) 
{
	while (Q->front->next!= NULL)
	{
		Q->rear = Q->front->next->next ;
		free(Q->front->next);
		Q->front->next = Q->rear;
	}
	free(Q->front->next);
	Q->front = NULL;
	Q->length = 0;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue* Q) 
{
	if (Q->length == 0)	return TRUE;
	return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue* Q, void* e) 
{
	if (Q->length == 0)
	{
		printf("����Ϊ��\n");
		return FALSE;
	}
	e = Q->front->next->data;
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue* Q) 
{
	if (Q->length == 0)
	{
		printf("����Ϊ��\n");
		return FALSE;
	}
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue* Q, void* data) 
{
	Node *s;
	s = (Node*)malloc(sizeof(Node));
	if (s == NULL)
	{
		printf("��������\n");
		return FALSE;
	}
	s->data = data;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = s;
	Q->length++;
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q,void* data)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue* Q, void* data)
{
	if (Q->length == 0)
	{
		printf("����Ϊ��\n");
		return FALSE;
	}
	Node* s;
	s = (Node*)malloc(sizeof(Node));
	if (s == NULL)
	{
		printf("��������\n");
		return FALSE;
	}
	s = Q->front->next;
	data = s->data;
	Q->front->next = s->next;
	free(s);
	Q->length--;
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue* Q)
{
	if (Q->length == 0)
	{
		printf("������Ԫ�ؿ����\n");
		return;
	}
	while (Q->front->next != NULL)
	{
		Q->rear = Q->front->next->next;
		free(Q->front->next);
		Q->front->next = Q->rear;
	}
	Q->front->next = NULL;
	Q->length = 0;
	printf("�������ɹ�\n");
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) 
{
	if (Q->length == 0)
	{
		printf("����Ϊ��\n");
		return FALSE;
	}
	Node *p;
	p = Q->front;
	while (p->next != NULL)
	{
		LPrint(p->data);
		p = p->next;
	}
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q

 *  @notice      : None
 */
void LPrint(void* q) 
{
	printf("%d->",q);
}
