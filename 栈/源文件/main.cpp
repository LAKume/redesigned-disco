#include "LinkStack.h"

LinkStack s;

int main(void)
{
	char *ch;
	int pf,data;
	int i=-1;
	ch = (char*)malloc(sizeof(char));
	while (i != 0)
	{
		system("color 04");
		printf("\n\n							十行代码九行警告的作品\n\n");
		printf("			1.初始化一个链栈						2.清空链栈\n\n");
		printf("			3.销毁栈							4.输出栈的长度\n\n");
		printf("			5.入栈								6.出栈\n\n");
		printf("			7.遍历栈的元素							8.输出栈顶\n\n");
		printf("			9.判断栈链是否为空						0.推出系统\n");
		printf("							请输入你所需要的功能：");
		scanf_s("%d", &i);
		fgets(ch, 20, stdin);
		switch (i)
		{
		case 1:
			system("cls");
			if ((s.top) != NULL)
			{
				printf("请销毁链栈\n");
				system("pause");
				system("cls");
				break;
			}
			pf = initLStack(&s);
			if (pf)	printf("初始化成功！\n");
			else printf("初始化失败,请销毁链栈\n");
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			pf = clearLStack(&s);
			if (pf!=0) printf("清空链栈成功\n");
			else printf("链栈内无元素\n");
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			if ((s.top) == NULL)
			{
				printf("请初始化链栈\n");
				system("pause");
				system("cls");
				break;
			}
			destroyLStack(&s);
			printf("销毁链栈成功\n");
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			pf = LStackLength(&s, &data);
			if (pf!=0)	printf("栈的长度为%d", data);
			else printf("链栈为空\n");
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			if ((s.top) == NULL)
			{
				printf("请初始化链栈\n");
				system("pause");
				system("cls");
				break;
			}
			printf("请输入所需入栈的数：");
			scanf_s("%d", & data);
			pf=getchar();
			if (pf == 1||data<-100||data>1000)
			{
				printf("请输入正确的整数\n");
				system("pause");
				system("cls");
				break;
			}
			pushLStack(&s, data);
			printf("入栈成功\n");
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			pf = popLStack(&s, &data);
			if (pf==1)	printf("弹出的栈顶元素为%d\n",data);
			else printf("链栈为空\n");
			system("pause");
			system("cls");
			break;
		case 7:
			system("cls");
			TraverseStack(s, visit);			//遍历链栈
			printf("NULL\n");
			system("pause");
			system("cls");
			break;
		case 8:
			system("cls");
			pf = getTopLStack(&s, &data);
			if (pf == 1)	printf("栈顶元素为%d\n", data);
			else printf("链栈为空\n");
			system("pause");
			system("cls");
			break;
		case 9:
			system("cls");
			if ((s.top) == NULL)
			{
				printf("请初始化链栈\n");
				system("pause");
				system("cls");
				break;
			}
			pf=isEmptyLStack(&s);
			if (pf == 1)	printf("栈链为空\n");
			else printf("链栈不为空\n");
			system("pause");
			system("cls");
			break;
		case 0:
			system("cls");
			printf("感谢观看\n");
			return 0;
		default:
			system("cls");
			printf("请输入正确的整数\n");
			system("pause");
			system("cls");
			break;

		}

	}
	return 0;

}