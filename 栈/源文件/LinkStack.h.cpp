#include "LinkStack.h" 
//链栈

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

//初始化栈
Status initLStack(LinkStack* s) 
{
	(s->top) = (LinkStackPtr)malloc(sizeof(StackNode));
	if (s->top == NULL)
		return ERROR;
	s->top->next = NULL;
	s->count = 0;
	return SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack* s) 
{
	if (s->count)	return ERROR;
	return SUCCESS;
}

//得到栈顶元素
Status getTopLStack(LinkStack* s, ElemType* e)
{
	if (isEmptyLStack(s))	return ERROR;						//检测是否创建栈
	*e = s->top->data;
	return SUCCESS;
}

//清空栈
Status clearLStack(LinkStack* s) 
{
	if (s->top==NULL)	return ERROR;						//检测是否创建栈
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

//销毁栈
Status destroyLStack(LinkStack* s)
{
	clearLStack(s);
	free(s->top->next);
	s->top = NULL;
	return SUCCESS;
}

//检测栈长度
Status LStackLength(LinkStack* s, int* length)
{
	if (isEmptyLStack(s)==0)	return ERROR;						//检测是否创建栈
	*length = s->count;
	return SUCCESS;
}

//入栈
Status pushLStack(LinkStack* s, ElemType data)
{
	//if (s->top==NULL)	return ERROR;						//检测是否创建栈
	LinkStackPtr p;
	p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count++;
	return SUCCESS;
}

//出栈
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

void TraverseStack(LinkStack s, void (*visit)(ElemType e))			//遍历链栈
{
	if (s.count == 0 && s.count == NULL)
	{
		printf("请初始化链表\n");
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



