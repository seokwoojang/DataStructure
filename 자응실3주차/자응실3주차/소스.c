//#include<stdio.h>
//#include<stdlib.h>
//#pragma warning(disable : 4996)
////(중간성적+기말성적)에 따라 학생을 재배열해라
//
//struct Student_rec {
//	int no;
//	char name[10];
//	int mid;
//	int final;
//}typedef Student;
//
//void Insert(Student* stu, int n)//학생수에 맞춰 학생정보입력
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("학번 : ");
//		scanf("%d", &stu[i].no);
//		printf("이름 : ");
//		scanf("%s", &stu[i].name);
//		printf("중간 : ");
//		scanf("%d", &stu[i].mid);
//		printf("기말 : ");
//		scanf("%d", &stu[i].final);
//	}
//}
//
//void Sort(Student* stu, int n)//버블 정렬 / 퀵솔트도 되려나?
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
//	int n;//학생수
//	Student* stu = NULL;
//
//	printf("몇 명?? ");
//	scanf("%d", &n);
//
//	//stu = (Student*)malloc(sizeof(Student)*n);
//	stu = (Student*)calloc(n, sizeof(Student));
//
//	Insert(stu, n);
//	Sort(stu, n);
//	printf("%10s %10s %4s %4s %5s", "학번", "이름", "중간", "기말", "합계");
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
////(중간성적+기말성적)에 따라 학생을 재배열해라
//
//struct Student_rec {
//	int no;
//	char name[10];
//	int mid;
//	int final;
//}typedef Student;
//
//void Insert(Student* stu, int n)//학생수에 맞춰 학생정보입력
//{
//	for (int i = 0; i < n; i++)
//	{
//		printf("학번 : ");
//		scanf("%d", &stu[i].no);
//		printf("이름 : ");
//		scanf("%s", &stu[i].name);
//		printf("중간 : ");
//		scanf("%d", &stu[i].mid);
//		printf("기말 : ");
//		scanf("%d", &stu[i].final);
//	}
//}
//
//void Sort(Student* stu, int n)//버블 정렬 / 퀵솔트도 되려나?
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
//	int n;//학생수
//	int n2;//추가 학생 수
//	Student* stu = NULL;
//	Student* stu2 = NULL;
//
//	printf("몇 명?? ");
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
//	printf("%10s %10s %4s %4s %5s", "학번", "이름", "중간", "기말", "합계");
//	printf("\n");
//
//	for (int i = 0; i < n; i++)//추가 전 
//	{
//		printf("%10d %10s %4d %4d %5d", stu[i].no, stu[i].name, stu[i].mid, stu[i].final, stu[i].mid + stu[i].final);
//		printf("\n");
//	}
//
//	printf("추가 몇 명?? ");
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
//	printf("%10s %10s %4s %4s %5s", "학번", "이름", "중간", "기말", "합계");
//	printf("\n");
//	for (int i = 0; i < n + n2; i++)//추가 후 
//	{
//		printf("%10d %10s %4d %4d %5d", stu[i].no, stu[i].name, stu[i].mid, stu[i].final, stu[i].mid + stu[i].final);
//		printf("\n");
//	}
//
//	free(stu);
//}