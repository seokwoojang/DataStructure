#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable : 4996)

struct Student_rec {
	int no;
	char name[10];
	int mid;
	int final;
}typedef Student;

void insert(Student* stu, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("�й� : ");
		scanf("%d", &stu[i].no);
		printf("�̸� : ");
		scanf("%s", stu[i].name);
		printf("�߰� : ");
		scanf("%d", &stu[i].mid);
		printf("�⸻ : ");
		scanf("%d", &stu[i].final);
	}
}

void sort(Student* stu, int n)
{
	Student temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((stu[i].mid + stu[i].final) > (stu[j].mid + stu[j].final)) {
				temp = stu[i];
				stu[i] = stu[j];
				stu[j] = temp;
			}
		}
	}
}

int main(void)
{
	int n;
	Student* stu = NULL;
	printf("�� ��?");
	scanf("%d", &n);

	stu = (Student*)malloc(sizeof(Student)*n);
	insert(stu, n);
	sort(stu, n);

	printf("%10s %10s %4s %4s %5s", "�й�", "�̸�", "�߰�", "�⸻", "�հ�");
	printf("\n");
	
	for (int i = 0; i < n; i++)
	{
		printf("%10d %10s %4d %4d %5d\n", stu[i].no, stu[i].name, stu[i].mid, stu[i].final, stu[i].mid + stu[i].final);
	}

	int n2;
	Student* stu2=stu;
	printf("�߰� �� ��>");
	scanf("%d", &n2);
	stu = (Student*)realloc(stu, sizeof(Student) * (n2 + n));
	
	
	
	for (int i = 0; i < n; i++)
	{
		stu[n2 + i] = stu2[i];
	}
	insert(stu, n2);
	sort(stu, n2+n);

	printf("%10s %10s %4s %4s %5s", "�й�", "�̸�", "�߰�", "�⸻", "�հ�");
	printf("\n");

	for (int i = 0; i < n2+n; i++)
	{
		printf("%10d %10s %4d %4d %5d\n", stu[i].no, stu[i].name, stu[i].mid, stu[i].final, stu[i].mid + stu[i].final);
	}
}