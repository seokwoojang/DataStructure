//#include<stdio.h>
//#include<stdlib.h>
//#pragma warning(disable : 4996)
////(�߰�����+�⸻����)�� ���� �л��� ��迭�ض�
//
//struct Student_rec {
//	int no;
//	char name[10];
//	int mid;
//	int final;
//}typedef Student;
//
//void Insert(Student* stu, int n)//�л����� ���� �л������Է�
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("�й� : ");
//		scanf("%d", &stu[i].no);
//		printf("�̸� : ");
//		scanf("%s", &stu[i].name);
//		printf("�߰� : ");
//		scanf("%d", &stu[i].mid);
//		printf("�⸻ : ");
//		scanf("%d", &stu[i].final);
//	}
//}
//
//void Sort(Student* stu, int n)//���� ���� / ����Ʈ�� �Ƿ���?
//{
//	Student temp;
//	for (int i = 0; i < n; i++)
//	{
//		for (int q = 0; q < n; q++)
//		{
//			if ((stu[q].mid + stu[q].final) < (stu[q + 1].mid + stu[q + 1].final))
//			{
//				temp = stu[q];
//				stu[q] = stu[q + 1];
//				stu[q + 1] = temp;
//			}
//		}
//	}
//}
//
//int main(void)
//{
//	int n;//�л���
//	Student* stu = NULL;
//
//	printf("�� ��?? ");
//	scanf("%d", &n);
//
//	//stu = (Student*)malloc(sizeof(Student)*n);
//	stu = (Student*)calloc(n, sizeof(Student));
//
//	Insert(stu, n);
//	Sort(stu, n);
//	printf("%10s %10s %4s %4s %5s", "�й�", "�̸�", "�߰�", "�⸻", "�հ�");
//	printf("\n");
//
//	for (int i = 0; i < n; i++)
//	{
//		printf("%10d %10s %4d %4d %5d", stu[i].no, stu[i].name, stu[i].mid, stu[i].final, stu[i].mid + stu[i].final);
//	}
//
//	free(stu);
//}
//
//
//
//---------------------------------------------------------------------------------- -
//#include<stdio.h>
//#include<stdlib.h>
//#pragma warning(disable : 4996)
////(�߰�����+�⸻����)�� ���� �л��� ��迭�ض�
//
//struct Student_rec {
//	int no;
//	char name[10];
//	int mid;
//	int final;
//}typedef Student;
//
//void Insert(Student* stu, int n)//�л����� ���� �л������Է�
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("�й� : ");
//		scanf("%d", &stu[i].no);
//		printf("�̸� : ");
//		scanf("%s", &stu[i].name);
//		printf("�߰� : ");
//		scanf("%d", &stu[i].mid);
//		printf("�⸻ : ");
//		scanf("%d", &stu[i].final);
//	}
//}
//
//void Sort(Student* stu, int n)//���� ���� / ����Ʈ�� �Ƿ���?
//{
//	Student temp;
//	for (int i = n - 1; i >= 0; i--)
//	{
//		for (int q = 0; q < i; q++)
//		{
//			if ((stu[q].mid + stu[q].final) < (stu[q + 1].mid + stu[q + 1].final))
//			{
//				temp = stu[q];
//				stu[q] = stu[q + 1];
//				stu[q + 1] = temp;
//			}
//		}
//	}
//}
//
//int main(void)
//{
//	int n;//�л���
//	int n2;//�߰� �л� ��
//	Student* stu = NULL;
//	Student* stu2 = NULL;
//
//	printf("�� ��?? ");
//	scanf("%d", &n);
//
//	//stu = (Student*)malloc(sizeof(Student)*n);
//	stu = (Student*)calloc(n, sizeof(Student));
//
//	Insert(stu, n);
//	stu2 = stu;
//	Sort(stu, n);
//
//
//	printf("%10s %10s %4s %4s %5s", "�й�", "�̸�", "�߰�", "�⸻", "�հ�");
//	printf("\n");
//
//	for (int i = 0; i < n; i++)//�߰� �� 
//	{
//		printf("%10d %10s %4d %4d %5d", stu[i].no, stu[i].name, stu[i].mid, stu[i].final, stu[i].mid + stu[i].final);
//		printf("\n");
//	}
//
//	printf("�߰� �� ��?? ");
//	scanf("%d", &n2);
//	stu = (Student*)realloc(stu, sizeof(Student) * (n + n2));
//
//	for (int i = 0; i < n; i++)
//	{
//		stu[i + n2] = stu2[i];
//	}
//	Insert(stu, n2);
//	Sort(stu, n2 + n);
//
//	printf("%10s %10s %4s %4s %5s", "�й�", "�̸�", "�߰�", "�⸻", "�հ�");
//	printf("\n");
//	for (int i = 0; i < n + n2; i++)//�߰� �� 
//	{
//		printf("%10d %10s %4d %4d %5d", stu[i].no, stu[i].name, stu[i].mid, stu[i].final, stu[i].mid + stu[i].final);
//		printf("\n");
//	}
//
//	free(stu);
//}