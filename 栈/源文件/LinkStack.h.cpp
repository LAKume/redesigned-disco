#include "LinkStack.h" 
//��ջ

//typedef  struct StackNode
//{
//	ElemType data;
//	struct StackNode* next;
//}StackNode, * LinkStackPtr;
//
//typedef  struct  LinkStack
//{
//	LinkStackPtr top;
//	int	count;
//}LinkStack;
//

//��ʼ��ջ
Status initLStack(LinkStack* s) 
{
	(s->top) = (LinkStackPtr)malloc(sizeof(StackNode));
	if (s->top == NULL)
		return ERROR;
	s->top->next = NULL;
	s->count = 0;
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack* s) 
{
	if (s->count)	return ERROR;
	return SUCCESS;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack* s, ElemType* e)
{
	if (isEmptyLStack(s))	return ERROR;						//����Ƿ񴴽�ջ
	*e = s->top->data;
	return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack* s) 
{
	if (s->top==NULL)	return ERROR;						//����Ƿ񴴽�ջ
	LinkStackPtr p, n;
	p = s->top;
	while (p !=  NULL)
	{
		n = p->next;
		free(p);
		p = n;
	}
	s->count = 0;
	s->top->next = NULL;
	return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack* s)
{
	clearLStack(s);
	free(s->top->next);
	s->top = NULL;
	return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack* s, int* length)
{
	if (isEmptyLStack(s)==0)	return ERROR;						//����Ƿ񴴽�ջ
	*length = s->count;
	return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack* s, ElemType data)
{
	//if (s->top==NULL)	return ERROR;						//����Ƿ񴴽�ջ
	LinkStackPtr p;
	p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count++;
	return SUCCESS;
}

//��ջ
Status popLStack(LinkStack* s, ElemType* data) 
{
	if (s->count==0)	return ERROR;
	LinkStackPtr p;
	p = (LinkStackPtr)malloc(sizeof(StackNode));
	*data = s->top->data;
	p = s->top;
	s->top = p->next;
	free(p);
	s->count--;
	return SUCCESS;
}

void TraverseStack(LinkStack s, void (*visit)(ElemType e))			//������ջ
{
	if (s.count == 0 && s.count == NULL)
	{
		printf("���ʼ������\n");
		return;
	}
	while (s.top->next != NULL)
	{
		visit(s.top->data);
		s.top = s.top->next;
	}
}
void visit(ElemType e)
{
	printf("%d->",e);
}



