
<<<<<<< HEAD
typedef struct stunode
{
	char sport[20];
	char sex[10];
	char name[10];
	char college[20];
	char grade[10];
	int rank;
	struct stunode* next;
}STU;  			
STU head;		
char stu[20][20];	
void maininterface();
void createList();
void printall();
void findperson();
void findcollege();
void freelist();
void findcollogescore();
void modify();
void allscore();
void getprize();
int getscore();
int N, M, W;		
int k = 0;		
int main(int argc, char* argv[])
{
	int i;
	int select;
	head.next = NULL;		
	printf("\t\t\t------------------------\n");
	printf("\t\t\t*******ϵͳ��ʼ��*******\n");
	printf("\t\t\t1.���������Ժϵ������");
	scanf("%d", &N);
	printf("\t\t\t2.���������Ӿ�����Ŀ����");
	scanf("%d", &M);
	printf("\t\t\t3.������Ů�Ӿ�����Ŀ����");
	scanf("%d", &W);
	printf("\t\t\t4.�����������Ժϵ����");
	for (i = 0;i < N;i++)
	{
		scanf("%s", &stu[i]);
	}
	printf("\n\t\t\t-----------------------\n");
	printf("\t\t\t  �˶������ѧԺ�У�");
	for (i = 0;i < N;i++)
	{
		printf("%s ", stu[i]);
	}
	printf("\n\t\t\t");
	system("pause");
	while (1)
	{
		maininterface();
		printf("\n*��ѡ����Ҫ�Ĳ�����");
		scanf("%d", &select);
		fflush(stdin);	
		switch (select)	/*�����û�ѡ�񣬵�����Ӧ������ɲ���*/
		{
		case 1:createList();break;
		case 2:findperson();break;
		case 3:findcollege();break;
		case 4:findcollogescore();break;
		case 5:allscore();break;
		case 6:getprize();break;
		case 7:modify();break;
		case 8:printall();break;
		case 0:freelist();exit(0);
		default:printf("�������\n");
		}
		system("pause");
	}
	return 0;
}
/*�������ܣ���ʾ�˵�*/
void maininterface()
{
	system("cls");	/*����*/
	printf("\t\t--------------------------\n");
	printf("\t\t******�˶������ϵͳ******\n");
	printf("\t\t1.������Ŀ����Ϣ\n");
	printf("\t\t2.��ѯ���˵ı����ɼ�\n");
	printf("\t\t3.��ѯԺϵ�ı�����Ϣ\n");
	printf("\t\t4.��ѯԺϵ�ı����ɼ�\n");
	printf("\t\t5.���������ֱܷ���\n");
	printf("\t\t6.�鿴����Ŀ���˶�Ա��Ϣ\n");
	printf("\t\t7.�޸���Ŀ��Ϣ\n");
	printf("\t\t8.��ʾ������Ϣ\n");
	printf("\t\t0.�˳�\n");
	printf("\t\t--------------------------\n");
	return;
}/*�������ܣ�����ĳ��Ŀ��n������Ϣ*/ 
void createList()
{
	int i, n, j = 0;
	int a, b;
	float c;
	int grade1[60], grade2[60];
	int place[60];
	char sport4[20] = "����", sport5[20] = "����", sport6[20] = "Ǧ��";
	STU* p, * tail, * p3;
	if (k == 0)		/*�״δ�������*/
	{
		k++;
		if (head.next != NULL)
		{
			printf("��Ŀ�������Ѵ���!\n");
			return;
		}
		tail = &head;			/*��ʼ��������tailָ��ͷ���head*/
		printf("*�������������:");
		scanf("%d", &n);
		printf("\n------------------------\n");
		for (i = 1;i <= n;i++)		/*����n����Ŀ��Ϣ��������*/
		{
			p = (STU*)malloc(sizeof(STU));		/*�½���һ�����*/
			if (p == NULL)
			{
				printf("��������ʱ�ڴ����ʧ�ܣ�\n");
				return;
			}
			printf("��Ŀ �Ա� ���� ѧԺ �ɼ�\n");
			scanf("%s%s%s%s%f", p->sport, p->sex, p->name, p->college, &p->grade);
			/*�������ӵ�����β��*/
			p->rank = 0;
			grade1[j] = p->grade;
			j++;
			tail->next = p;		/*��p��ָ����next�����½���next*/
			p->next = NULL;		/*���½��ĵ�ַ����p��ָ����next*/
			tail = p;
		}
		if (strcmp(p->sport, sport4) == 0 || strcmp(p->sport, sport5) == 0 || strcmp(p->sport, sport6) == 0)
		{
			for (i = 0;i < j;i++)		/*��ʼ��palce,grade2��grade1*/
			{
				place[i] = 0;
				grade2[i] = 0;
			}
			for (i = 0;i < j;i++)
			{
				grade2[i] = grade1[i];
			}
			for (a = 0;a < j - 1;a++)		/*����ð�ݷ���������*/
			{
				for (b = 0;b < j - a - 1;b++)
				{
					if (grade2[b] < grade2[b + 1])
					{
						c = grade2[b];		/*��������*/
						grade2[b] = grade2[b + 1];
						grade2[b + 1] = c;
					}
				}
			}
			for (i = 0;i < j;i++)		/*�Ƚϣ��ҵ�����Ӧ������*/
			{
				for (a = 0;a < j;a++)
				{
					if (grade2[i] == grade1[a])
					{
						place[a] = i + 1;
					}
				}
			}
			p3 = head.next;
			for (i = 0;i < j;i++)
			{
				p3->rank = place[i];
				p3 = p3->next;
			}
		}
		else {
			for (i = 0;i < j;i++)		/*��ʼ��palce,grade2��grade1*/
			{
				place[i] = 0;
				grade2[i] = 0;
			}
			for (i = 0;i < j;i++)
			{
				grade2[i] = grade1[i];
			}
			for (a = 0;a < j - 1;a++)		/*����ð�ݷ���������*/
			{
				for (b = 0;b < j - a - 1;b++)
				{
					if (grade2[b] > grade2[b + 1])
					{
						c = grade2[b];		/*��������*/
						grade2[b] = grade2[b + 1];
						grade2[b + 1] = c;
					}
				}
			}
			for (i = 0;i < j;i++)		/*�Ƚϣ��ҵ�����Ӧ������*/
			{
				for (a = 0;a < j;a++)
				{
					if (grade2[i] == grade1[a])
					{
						place[a] = i + 1;
					}
				}
			}
			p3 = head.next;
			for (i = 0;i < j;i++)
			{
				p3->rank = place[i];
				p3 = p3->next;
			}
		}
		return;
	}
	if (k == 1)		/*�ٴδ��������൱������һ�δ����������β�����룩*/
	{
		j = 0;
		STU* p1, * p2, * p5;
		p1 = &head;
		while (1)
		{
			if (p1->next == NULL)break;		/*������ѭ����β��ʱ����ѭ��*/
			p1 = p1->next;		/*p1ָ����һ�����*/
		}
		p5 = &head;
		while (1)
		{
			if (p5->next == NULL)break;		/*������ѭ����β��ʱ����ѭ��*/
			p5 = p5->next;		/*p1ָ����һ�����*/
		}
		printf("�������������:");
		scanf("%d", &n);
		for (i = 1;i <= n;i++) {
			p2 = (STU*)malloc(sizeof(STU));		/*�½���һ�����*/
			if (p2 == NULL)
			{
				printf("��̬�ڴ����ʧ�ܣ�");
				return;
			}
			printf("��Ŀ �Ա� ���� ѧԺ �ɼ�\n");
			scanf("%s%s%s%s%f", p2->sport, p2->sex, p2->name, p2->college, &p2->grade);
			p2->rank = 0;
			grade1[j] = p2->grade;
			j++;
			p2->next = p1->next;		/*��p1��ָ����next�����µĽ���next*/
			p1->next = p2;			/*���µĽ��ĵ�ַ����p1��ָ����next*/
			for (i = 0;i < j;i++)		/*��ʼ��palce,grade2��grade1*/
			{
				place[i] = 0;
				grade2[i] = 0;
			}
			a = 0;
			b = 0;
			c = 0;
			if (strcmp(p2->sport, sport4) == 0 || strcmp(p2->sport, sport5) == 0 || strcmp(p2->sport, sport6) == 0)
			{
				for (i = 0;i < j;i++)		/*��ʼ��palce,grade2��grade1*/
				{
					place[i] = 0;
					grade2[i] = 0;
				}
				for (i = 0;i < j;i++)
				{
					grade2[i] = grade1[i];
				}
				for (a = 0;a < j - 1;a++)		/*����ð�ݷ���������*/
				{
					for (b = 0;b < j - a - 1;b++)
					{
						if (grade2[b] < grade2[b + 1])
						{
							c = grade2[b];		/*��������*/
							grade2[b] = grade2[b + 1];
							grade2[b + 1] = c;
						}
					}
				}
				for (i = 0;i < j;i++)		/*�Ƚϣ��ҵ�����Ӧ������*/
				{
					for (a = 0;a < j;a++)
					{
						if (grade2[i] == grade1[a])
						{
							place[a] = i + 1;
						}
					}
				}
				p3 = p5;
				for (i = 0;i < j;i++)
				{
					p3 = p3->next;
					p3->rank = place[i];

				}
			}
			else {
				for (i = 0;i < j;i++)		/*��ʼ��palce,grade2��grade1*/
				{
					place[i] = 0;
					grade2[i] = 0;
				}
				for (i = 0;i < j;i++)
				{
					grade2[i] = grade1[i];
				}
				for (a = 0;a < j - 1;a++)		/*����ð�ݷ���������*/
				{
					for (b = 0;b < j - a - 1;b++)
					{
						if (grade2[b] < grade2[b + 1])
						{
							c = grade2[b];		/*��������*/
							grade2[b] = grade2[b + 1];
							grade2[b + 1] = c;
						}
					}
				}
				for (i = 0;i < j;i++)		/*�Ƚϣ��ҵ�����Ӧ������*/
				{
					for (a = 0;a < j;a++)
					{
						if (grade2[i] == grade1[a])
						{
							place[a] = i + 1;
						}
					}
				}
				p3 = p5;
				for (i = 0;i < j;i++)
				{
					p3 = p3->next;
					p3->rank = place[i];

				}
			}
		}
		return;
	}
}
/*�������ܣ����������Ŀ��Ϣ*/
void printall()
{
	STU* p;
	if (head.next == NULL)
	{
		printf("δ����ѧ������\n");
		return;
	}
	p = head.next;		/*pָ���һ�����*/
	printf("-------------------------------------\n");
	printf("��Ŀ\t�Ա�\t����\tѧԺ\t�ɼ�\t����\n");
	while (p != NULL)		/*��p��ΪNULL*/
	{
		printf("%s\t%s\t%s\t%s\t%.2f\t%d\n", p->sport, p->sex, p->name, p->college, p->grade, p->rank);
		p = p->next;		/*pָ����һ�����*/
	}
	return;
}
/*�������ܣ���ѯ���˵ı����ɼ�*/
void findperson()
{
	int tatal, goal;
	char name1[10];
	printf("*�������ѯ���˶�Ա������");
	scanf("%s", &name1);
	printf("--------------------------------------------\n");
	printf("��Ŀ\t�Ա�\t����\tѧԺ\t����\t�ɼ�\t�÷�\n");
	STU* p3;
	p3 = head.next;		/*p3ָ���һ�����*/
	while (p3 != NULL)		/*��p3��ΪNULL*/
	{

		if (strcmp(p3->name, name1) == 0)
		{
			goal = getscore(p3->rank);		/*����getscore�����������������Ӧ�ķ���*/
			printf("%s\t%s\t%s\t%s\t%.2f\t%d\t%d\n", p3->sport, p3->sex, p3->name, p3->college, p3->grade, p3->rank, goal);
			tatal += goal;
		}
		p3 = p3->next;		/*p3ָ����һ�����*/

	}
	printf("�ܷ֣�%d\n", tatal);
	return;

}
/*�������ܣ��ͷ����������д���˶���Ŀ��Ϣ�Ľ��*/
void freelist()
{
	STU* p;
	p = head.next;			/*�ӵ�һ����㿪ʼ�ͷ�*/
	while (p != NULL)			/*ѭ���ͷ�������ÿ�����Ŀռ�*/
	{
		head.next = p->next;
		free(p);			/*�ͷ�pָ��Ľ��ռ�*/
		p = head.next;		/*ָ�����pָ����һ�����ͷŵĽ��*/
	}
	return;
}
/*�������ܣ���ѯѧԺ������Ϣ*/
void findcollege()
{
	STU* p4;
	p4 = head.next;		/*p4ָ���һ�����*/
	char college1[10];
	printf("*�������ѯ��ѧԺ��");
	scanf("%s", &college1);
	printf("-------------------------------------\n");
	printf("��Ŀ\t�Ա�\t����\tѧԺ\t�ɼ�\t����\n");
	while (p4 != NULL)
	{
		if (strcmp(p4->college, college1) == 0)		/*�����ȣ��������*/
		{
			printf("%s\t%s\t%s\t%s\t%.2f\t%d\n", p4->sport, p4->sex, p4->name, p4->college, p4->grade, p4->rank);
		}
		p4 = p4->next;		/*p4ָ����һ�����*/
	}
	return;
}
/*�������ܣ��÷ּ���*/
int getscore(score1)
{
	int n = 0;
	if (score1 == 1)
	{
		n = 7;
		return n;
	}
	else if (score1 == 2)
	{
		n = 5;
		return n;
	}
	else if (score1 == 3)
	{
		n = 3;
		return n;
	}
	else if (score1 == 4)
	{
		n = 2;
		return n;
	}
	else if (score1 == 5)
	{
		n = 1;
		return n;
	}
	else
	{
		n = 0;
		return n;
	}
	return;
}
/*������Ϣ���鿴ѧԺ����Ϣ*/
void findcollogescore()
{
	int tatal, goal;
	char name1[20];
	printf("*�������ѯ��ѧԺ��");
	scanf("%s", &name1);
	printf("--------------------------------------------\n");
	printf("��Ŀ\t�Ա�\t����\tѧԺ\t�ɼ�\t����\t�÷�\n");
	STU* p3;
	p3 = head.next;		/*p3ָ���һ�����*/
	while (p3 != NULL)
	{

		if (strcmp(p3->college, name1) == 0)		/*�����ȣ��������*/
		{
			goal = getscore(p3->rank);
			printf("%s\t%s\t%s\t%s\t%.2f\t%d\t%d\n", p3->sport, p3->sex, p3->name, p3->college, p3->grade, p3->rank, goal);
			tatal += goal;
		}
		p3 = p3->next;		/*p3ָ����һ�����*/

	}
	printf("�ܷ֣�%d\n", tatal);
	return;

}
/*�������ܣ��������������ֱܷ���*/
void allscore()
{
	int tatal[60], goal = 0, i, man[60], women[60], pla[60], data[60], tatal2[60], man2[60], women2[60];
	STU* p3;

	char ma[10] = { "��" };
	char wo[10] = { "Ů" };
	printf("-------------------------------------\n");
	printf("Ժϵ\t����\tŮ��\t�ܷ�\t����\n");
	for (i = 0;i < N;i++)
	{
		p3 = head.next;		/*p3ָ���һ�����*/
		tatal[i] = 0;
		man[i] = 0;
		women[i] = 0;
		while (p3 != NULL)
		{
			if (strcmp(p3->college, stu[i]) == 0 && strcmp(p3->sex, ma) == 0)		/*�ж��Ƿ�Ϊͬһ������Ŀ*/
			{
				goal = getscore(p3->rank);
				man[i] += goal;		/*���������ܷ�*/
			}
			if (strcmp(p3->college, stu[i]) == 0 && strcmp(p3->sex, wo) == 0)		/*�ж��Ƿ�ΪͬһŮ����Ŀ*/
			{
				goal = getscore(p3->rank);
				women[i] += goal;		/*����Ů���ܷ�*/
			}
			p3 = p3->next;		/*p3ָ����һ�����*/
		}
		tatal[i] = man[i] + women[i];		/*�����ܷ�*/
	}
	for (i = 0;i < N;i++)
	{
		data[i] = tatal[i];
	}
	int a, b, c;
	for (a = 0;a < N - 1;a++)		/*����ð�ݷ���������*/
	{
		for (b = 0;b < N - a - 1;b++)
		{
			if (data[b] < data[b + 1])
			{
				c = data[b];		/*��������*/
				data[b] = data[b + 1];
				data[b + 1] = c;
			}
		}
	}
	for (i = 0;i < N;i++) {		/*��ʼ��pla*/
		pla[i] = 0;

	}
	for (i = 0;i < N;i++)		/*�Ƚϣ��ҵ�����Ӧ������*/
	{
		for (a = 0;a < N;a++)
		{
			if (data[i] == tatal[a])
			{
				pla[a] = i + 1;
			}
		}
	}
	int p;

	for (p = 0;p < N;p++)
	{
		p3 = head.next;		/*p3ָ���һ�����*/
		man2[p] = 0;
		women2[p] = 0;
		while (p3 != NULL)
		{
			if (strcmp(p3->college, stu[p]) == 0 && strcmp(p3->sex, ma) == 0)
			{
				goal = getscore(p3->rank);
				man2[p] += goal;
			}
			if (strcmp(p3->college, stu[p]) == 0 && strcmp(p3->sex, wo) == 0)
			{
				goal = getscore(p3->rank);

				women2[p] += goal;
			}
			p3 = p3->next;		/*p3ָ����һ�����*/
		}
		tatal2[p] = man2[p] + women2[p];
		printf("%s\t%d\t%d\t%d\t%d\n", stu[p], man2[p], women2[p], tatal2[p], pla[p]);
	}
	return;

}
/*�������ܣ��鿴����Ŀ���˶�Ա*/
void getprize()
{
	STU* p;
	int i, j;
	p = &head;
	printf("-------------------------------------\n");
	printf("����Ŀǰ������Ϣ���£�\n");
	printf("��Ŀ\t�Ա�\t����\tѧԺ\t�ɼ�\t����\n");
	while (p != NULL)
	{
		if ((p->rank) >= 1 && (p->rank) <= 3)		/*ѡȡ����Ŀ����ǰ�����˶�Ա*/
		{
			printf("%s\t%s\t%s\t%s\t%.2f\t%d\n", p->sport, p->sex, p->name, p->college, p->grade, p->rank);
		}
		p = p->next;
	}
	return;
}
/*�������ܣ����������޸�ָ������Ŀ��Ϣ*/
void modify()
{
	int n, i;
	char sport1[20], sex1[10], name1[10], college1[20];
	STU* p, * p1;
	p = head.next;		/*pָ���һ�����*/
	printf("������Ҫ�޸�λ�õ������Ϣ��\n");
	printf("��Ŀ �Ա� ���� ѧԺ\n");
	scanf("%s%s%s%s", &sport1, &sex1, &name1, &college1);
	if (head.next == NULL)
	{
		printf("δ������Ŀ����");
		return;
	}
	while (p != NULL)
	{
		if (strcmp(p->sport, sport1) == 0 && strcmp(p->sex, sex1) == 0 && strcmp(p->name, name1) == 0 && strcmp(p->college, college1) == 0)
		{
			p1 = p;
			break;
		}
		p = p->next;		/*pָ����һ�����*/
	}
	char sport2[10] = "��Ŀ", sex2[10] = "�Ա�", name2[10] = "����", college2[10] = "ѧԺ", grade2[10] = "�ɼ�", rank2[10] = "����";
	char xiugai[10];
	printf("������Ҫ�޸ĵ���Ϣ��");
	scanf("%s", &xiugai);
	if (xiugai[1] == sport2[1])
	{
		printf("�������޸ĺ�����ݣ�");
		scanf("%s", p1->sport);
		printf("�޸ĳɹ���");
	}
	else if (xiugai[1] == sex2[1])
	{
		printf("�������޸ĺ�����ݣ�");
		scanf("%s", p1->sex);
		printf("�޸ĳɹ���");
	}
	else if (xiugai[1] == name2[1])
	{
		printf("�������޸ĺ�����ݣ�");
		scanf("%s", p1->name);
		printf("�޸ĳɹ���");
	}
	else if (xiugai[1] == college2[1])
	{
		printf("�������޸ĺ�����ݣ�");
		scanf("%s", p1->college);
		printf("�޸ĳɹ���");
	}
	else if (xiugai[1] == grade2[1])
	{
		printf("�������޸ĺ�����ݣ�");
		scanf("%f", p1->grade);
		printf("�޸ĳɹ���");
	}
	else if (xiugai[1] == rank2[1])
	{
		printf("�������޸ĺ�����ݣ�");
		scanf("%d", &p1->rank);
		printf("�޸ĳɹ���");
	}
	return;
}
=======
>>>>>>> 00d2222d1b96d07ad55272e0ad27df41e1fd7cca
