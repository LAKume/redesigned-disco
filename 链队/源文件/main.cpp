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
		printf("\n\n							һ��bugû��\n\n");
		printf("			1.��ʼ��һ������						2.��ն���\n\n");
		printf("			3.���ٶ�							4.����ӵĳ���\n\n");
		printf("			5.���								6.����\n\n");
		printf("			7.�����ӵ�Ԫ��							8.����Ӷ�\n\n");
		printf("			9.�ж�ջ���Ƿ�Ϊ��						0.�Ƴ�ϵͳ\n");
		printf("							������������Ҫ�Ĺ��ܣ�");
		scanf_s("%d", &i);
		fgets(ch, 20, stdin);
		switch (i)
		{
		case 1:
			system("cls");
			if ((Q.front) != NULL)
			{
				printf("�����ٶ���\n");
				system("pause");
				system("cls");
				break;
			}
			InitLQueue(&Q);
			if (Q.front->next ==NULL)	printf("��ʼ���ɹ���\n");
			else printf("��ʼ��ʧ��,�����ٶ���\n");
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
				printf("���ʼ������\n");
				system("pause");
				system("cls");
				break;
			}
			DestoryLQueue(&Q);
			printf("���ٶ����ɹ�\n");
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			data = LengthLQueue(& Q);
			if (data!=0)	printf("�ӵĳ���Ϊ%d", data);
			else printf("����Ϊ��\n");
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			if ((Q.front) == NULL)
			{
				printf("���ʼ������\n");
				system("pause");
				system("cls");
				break;
			}
			printf("������������ӵ�����");
			scanf_s("%d", &data);
			pf = getchar();
			if (pf == 1 || data < -100 || data>1000)
			{
				printf("��������ȷ������\n");
				system("pause");
				system("cls");
				break;
			}
			EnLQueue(&Q, &data);
			printf("��ӳɹ�\n");
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			pf = DeLQueue(& Q, & data);
			if (pf == 1)	printf("���ӵ�Ԫ��Ϊ%d\n", data);
			else printf("����Ϊ��\n");
			system("pause");
			system("cls");
			break;
		case 7:
			system("cls");
			TraverseLQueue(&Q, LPrint);			//��������
			printf("NULL\n");
			system("pause");
			system("cls");
			break;
		case 8:
			system("cls");
			pf = GetHeadLQueue(& Q, &data);
			if (pf == 1)	printf("�Ӷ�Ԫ��Ϊ%d\n", data);
			else printf("����Ϊ��\n");
			system("pause");
			system("cls");
			break;
		case 9:
			system("cls");
			if ((Q.front) == NULL)
			{
				printf("���ʼ����ջ\n");
				system("pause");
				system("cls");
				break;
			}
			pf = IsEmptyLQueue(&Q);
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

	return 0;
}