#include "LQueue.h"

//typedef struct node
//{
//    void* data;                   //数据域指针
//    struct node* next;            //指向当前结点的下一结点
//} Node;
//
//typedef struct Lqueue
//{
//    Node* front;                   //队头
//    Node* rear;                    //队尾
//    size_t length;            //队列长度
//} LQueue;

//typedef enum
//{
//    FALSE = 0, TRUE = 1
//} Status;
//char type;
//char datatype[30];


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue* Q)
{
	(Q->front) = (Q->rear) = (Node*)malloc(sizeof(Node));				//为Q->front和Q->rear分配内存
	if (Q->front == NULL || Q->rear == NULL)
	{
		printf("初始化失败\n");
		return;
	}
	Q->front->next =  NULL;								//使Q->front和Q->rear直线NULL
	Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
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
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue* Q) 
{
	if (Q->length == 0)	return TRUE;
	return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue* Q, void* e) 
{
	if (Q->length == 0)
	{
		printf("链队为空\n");
		return FALSE;
	}
	e = Q->front->next->data;
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue* Q) 
{
	if (Q->length == 0)
	{
		printf("链队为空\n");
		return FALSE;
	}
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue* Q, void* data) 
{
	Node *s;
	s = (Node*)malloc(sizeof(Node));
	if (s == NULL)
	{
		printf("发生错误\n");
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
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue* Q, void* data)
{
	if (Q->length == 0)
	{
		printf("链队为空\n");
		return FALSE;
	}
	Node* s;
	s = (Node*)malloc(sizeof(Node));
	if (s == NULL)
	{
		printf("发生错误\n");
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
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue* Q)
{
	if (Q->length == 0)
	{
		printf("链队无元素可清空\n");
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
	printf("清空链表成功\n");
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) 
{
	if (Q->length == 0)
	{
		printf("链队为空\n");
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
 *    @description : 操作函数
 *    @param         q 指针q

 *  @notice      : None
 */
void LPrint(void* q) 
{
	printf("%d->",q);
}
