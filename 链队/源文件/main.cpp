#include "LQueue.h"
LQueue Q;
int main(void)
{
	system("color 70");
	char* ch;
	int pf, data;
	int i = -1;
	ch = (char*)malloc(sizeof(char));
	while (i != 0)
	{
		printf("\n\n							一堆bug没改\n\n");
		printf("			1.初始化一个队链						2.清空队链\n\n");
		printf("			3.销毁队							4.输出队的长度\n\n");
		printf("			5.入队								6.出队\n\n");
		printf("			7.遍历队的元素							8.输出队顶\n\n");
		printf("			9.判断栈链是否为空						0.推出系统\n");
		printf("							请输入你所需要的功能：");
		scanf_s("%d", &i);
		fgets(ch, 20, stdin);
		switch (i)
		{
		case 1:
			system("cls");
			if ((Q.front) != NULL)
			{
				printf("请销毁队链\n");
				system("pause");
				system("cls");
				break;
			}
			InitLQueue(&Q);
			if (Q.front->next ==NULL)	printf("初始化成功！\n");
			else printf("初始化失败,请销毁队链\n");
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			ClearLQueue(&Q);
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			if ((Q.front) == NULL)
			{
				printf("请初始化队链\n");
				system("pause");
				system("cls");
				break;
			}
			DestoryLQueue(&Q);
			printf("销毁队链成功\n");
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			data = LengthLQueue(& Q);
			if (data!=0)	printf("队的长度为%d", data);
			else printf("队链为空\n");
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			if ((Q.front) == NULL)
			{
				printf("请初始化队链\n");
				system("pause");
				system("cls");
				break;
			}
			printf("请输入所需入队的数：");
			scanf_s("%d", &data);
			pf = getchar();
			if (pf == 1 || data < -100 || data>1000)
			{
				printf("请输入正确的整数\n");
				system("pause");
				system("cls");
				break;
			}
			EnLQueue(&Q, &data);
			printf("入队成功\n");
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			pf = DeLQueue(& Q, & data);
			if (pf == 1)	printf("出队的元素为%d\n", data);
			else printf("队链为空\n");
			system("pause");
			system("cls");
			break;
		case 7:
			system("cls");
			TraverseLQueue(&Q, LPrint);			//遍历队链
			printf("NULL\n");
			system("pause");
			system("cls");
			break;
		case 8:
			system("cls");
			pf = GetHeadLQueue(& Q, &data);
			if (pf == 1)	printf("队顶元素为%d\n", data);
			else printf("队链为空\n");
			system("pause");
			system("cls");
			break;
		case 9:
			system("cls");
			if ((Q.front) == NULL)
			{
				printf("请初始化链栈\n");
				system("pause");
				system("cls");
				break;
			}
			pf = IsEmptyLQueue(&Q);
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

	return 0;
}