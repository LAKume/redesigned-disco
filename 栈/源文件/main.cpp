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
		printf("\n\n							ʮ�д�����о������Ʒ\n\n");
		printf("			1.��ʼ��һ����ջ						2.�����ջ\n\n");
		printf("			3.����ջ							4.���ջ�ĳ���\n\n");
		printf("			5.��ջ								6.��ջ\n\n");
		printf("			7.����ջ��Ԫ��							8.���ջ��\n\n");
		printf("			9.�ж�ջ���Ƿ�Ϊ��						0.�Ƴ�ϵͳ\n");
		printf("							������������Ҫ�Ĺ��ܣ�");
		scanf_s("%d", &i);
		fgets(ch, 20, stdin);
		switch (i)
		{
		case 1:
			system("cls");
			if ((s.top) != NULL)
			{
				printf("��������ջ\n");
				system("pause");
				system("cls");
				break;
			}
			pf = initLStack(&s);
			if (pf)	printf("��ʼ���ɹ���\n");
			else printf("��ʼ��ʧ��,��������ջ\n");
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			pf = clearLStack(&s);
			if (pf!=0) printf("�����ջ�ɹ�\n");
			else printf("��ջ����Ԫ��\n");
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			if ((s.top) == NULL)
			{
				printf("���ʼ����ջ\n");
				system("pause");
				system("cls");
				break;
			}
			destroyLStack(&s);
			printf("������ջ�ɹ�\n");
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			pf = LStackLength(&s, &data);
			if (pf!=0)	printf("ջ�ĳ���Ϊ%d", data);
			else printf("��ջΪ��\n");
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			if ((s.top) == NULL)
			{
				printf("���ʼ����ջ\n");
				system("pause");
				system("cls");
				break;
			}
			printf("������������ջ������");
			scanf_s("%d", & data);
			pf=getchar();
			if (pf == 1||data<-100||data>1000)
			{
				printf("��������ȷ������\n");
				system("pause");
				system("cls");
				break;
			}
			pushLStack(&s, data);
			printf("��ջ�ɹ�\n");
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			pf = popLStack(&s, &data);
			if (pf==1)	printf("������ջ��Ԫ��Ϊ%d\n",data);
			else printf("��ջΪ��\n");
			system("pause");
			system("cls");
			break;
		case 7:
			system("cls");
			TraverseStack(s, visit);			//������ջ
			printf("NULL\n");
			system("pause");
			system("cls");
			break;
		case 8:
			system("cls");
			pf = getTopLStack(&s, &data);
			if (pf == 1)	printf("ջ��Ԫ��Ϊ%d\n", data);
			else printf("��ջΪ��\n");
			system("pause");
			system("cls");
			break;
		case 9:
			system("cls");
			if ((s.top) == NULL)
			{
				printf("���ʼ����ջ\n");
				system("pause");
				system("cls");
				break;
			}
			pf=isEmptyLStack(&s);
			if (pf == 1)	printf("ջ��Ϊ��\n");
			else printf("��ջ��Ϊ��\n");
			system("pause");
			system("cls");
			break;
		case 0:
			system("cls");
			printf("��л�ۿ�\n");
			return 0;
		default:
			system("cls");
			printf("��������ȷ������\n");
			system("pause");
			system("cls");
			break;

		}

	}
	return 0;

}