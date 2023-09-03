#include<stdio.h> 
#include<stdlib.h>  
#include<string.h>
struct workers
{
	char jobNo[15];       //ְ����
	char name[15];        //����
	char sex[15];         //�Ա�
	char birthday[15];    //��������
	char degree[15];      //ѧ��
	char position[15];    //ְ�� 
	char salary[15];      //���� 
	char addr[15];        //סַ 
	char tel[15];         //�绰 

};


//���Ͷ������  
typedef struct node
{
	struct workers data;
	struct node *next;

}Node;

 
//������Ϣ����     "β�巨����"
void Add(Node *worker)
{
	Node *p, *q;
	char n[10]; 
	q = worker; 
	while (q->next != NULL)
	{
		q = q->next;     
	}
	while (1)
	{
		printf("提示：输入0返回主菜单！\n");
		printf("请输入职工号：");
		scanf("%s", n);
		if (strcmp(n, "0") == 0)
		{
			break;
		}
		p = (Node *)malloc(sizeof(Node));
		strcpy(p->data.jobNo, n);
		
		printf("请输入姓名：");
		scanf("%s", p->data.name);
		printf("请输入性别：");
		scanf("%s", p->data.sex);
		printf("请输入出生年月：");
		scanf("%s", p->data.birthday);
		printf("请输入学历：");
		scanf("%s", p->data.degree);
		printf("请输入职务：");
		scanf("%s", p->data.position);
		printf("请输入工资：");
		scanf("%s", p->data.salary);
		printf("请输入住址：");
		scanf("%s", p->data.addr);
		printf("请输入电话：");
		scanf("%s", p->data.tel);
		printf("提示：已经完成一条记录的添加！");
		p->next = NULL;
		q->next = p;      
		q = p;        

	}

}


//�޸�ְ����Ϣ����
int  change(Node *worker)
{
	Node *p;
	char find[20];   
	p = worker->next;   
	if (p == NULL)
	{
		printf("\n提示：没有资料可以修改！\n");
		return 0;
	}
	
	printf("请输入要修改的职工号");
	scanf("%s", find);

	while (p != NULL) 
	{
		if (strcmp(p->data.jobNo, find) == 0)
		{
			break;
		}
		p = p->next;
	}
	
	if (p!=NULL)
	{
		int x;
		while (1)
		{
			printf("完成修改请输入，否则输入非数字进行修改！");
			scanf("%d", &x);
			if (x == 0)
			{
				break;
			}
			printf(" 请输入新的职工号: ");
			scanf("%s", p->data.jobNo);
			printf(" 请输入新的职工姓名: ");
			scanf("%s", p->data.name);
			printf(" 请输入新的职工性别: ");
			scanf("%s", p->data.sex);
			printf(" 请输入新的职工出生年月: ");
			scanf("%s", p->data.birthday);
			printf(" 请输入新的职工学历: ");
			scanf("%s", p->data.degree);
			printf(" 请输入新的职工职务: ");
			scanf("%s", p->data.position);
			printf(" 请输入新的职工工资: ");
			scanf("%s", p->data.salary);
			printf(" 请输入新的职工住址ַ: ");
			scanf("%s", p->data.addr);
			printf(" 请输入新的职工电话: ");
			scanf("%s", p->data.tel);
			printf(" \n提示：该员工资料已经修改！\n ");
		}
	}
	else 
		printf("\n提示：没有你要修改的资料!\n ");
}


//���ְ����Ϣ����
int  Disp(Node *worker)
{
	Node *p;
	p = worker->next;
	if (p == NULL)
	{
		printf(" \n提示：没有信息可以显示!\n ");
		return 0;

	}
	printf("\t\t\t\t显示结果\n");
	printf(" \n职工号姓名 性别 出生年月 学历 职务 工资 住址 电话\n ");
	while (p!=NULL)  
	{
		printf("\n %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t\n ", p->data.jobNo, p->data.name,
			p->data.sex, p->data.birthday, p->data.degree, p->data.position,
			p->data.salary, p->data.addr, p->data.tel);
		p = p->next;

	}

}


//��ѯְ����Ϣ����: ��ְ���Ų�ѯ	��ְ��������ѯ
int  Cha_xun(Node *worker)
{
	Node *p;
	int sel;
	char find[20];	
	p = worker->next;   

	if (p==NULL) 
	{
		printf(" \n提示：没有资料可以查询！\n ");
		return 0;

	}

	printf("\n提示\n输入0----退出\t输入1----按职工号查询\t输入2----按职工姓名查询\n");
	printf("��ѡ��");
	scanf("%d", &sel);

	if (sel == 1)
	{
		printf("\n请输入你要查询分类的职工号：");
		scanf("%s", find);
		while (p!=NULL)  
		{
			if (strcmp(p->data.jobNo, find) == 0)
			{
				printf(" 职工号姓名 性别 出生年月 学历 职务 工资 住址 电话\n ");
				printf(" \n %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t\n ", p->data.jobNo, p->data.name,
					p->data.sex, p->data.birthday, p->data.degree, p->data.position,
					p->data.salary, p->data.addr, p->data.tel);

			}
			p = p->next;   

		}

	}

	else if (sel == 2)
	{
		printf(" \n请输入你要查询分类的职工姓名：");
		scanf("%s", find);
		while (p!=NULL)
		{
			if (strcmp(p->data.name, find) == 0) 
			{
				printf(" 职工号姓名 性别 出生年月 学历 职务 工资 住址 电话 \n ");
				printf(" \n %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t \n ", p->data.jobNo, p->data.name,
					p->data.sex, p->data.birthday, p->data.degree, p->data.position,
					p->data.salary, p->data.addr, p->data.tel);

			}
			p = p->next;

		}
	}
	
	else if (sel == 0)
		return 0;
		
}


//ɾ��ְ����Ϣ����
int  Delete(Node *worker)
{
	Node *p, *r;
	char find[10];
	p = worker->next;
	if (p == NULL)
	{
		printf("提示：没有职工信息可以删除！\n ");
		return 0; 

	}
	printf(" \n提示：请输入你要删除的职工号！\n ");
	scanf("%s", find);
	while (p != NULL)
	{
		if (strcmp(p->data.jobNo, find) == 0)
		{
			break;
		}
		p = p->next;

	}

	if (p!=NULL)
	{
		r = worker;
		while (r->next != p)
		{
			r = r->next;
		}
		r->next = r->next->next;    
	}
}


//��ְ����Ϣ���浽�ļ���
void save(Node *worker)
{
	int n;
	Node *p = NULL;
	FILE *fp;    
	printf("是否保存到文件？（1----保存！，0----不保存！）");
	scanf("%d", &n);

	if (n == 1)
	{
		if (worker->next == NULL)
		{
			printf("没有记录！");
		}

		else
		{
			p = worker->next;
		}

		if ((fp = fopen(" 职工信息管理系统.txt ", " wb ")) == NULL)  
		{
			printf(" 文件不能打开！\n");     
		}

		while (p != NULL)   
		{
			fprintf(fp, " %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t ", p->data.jobNo, p->data.name, p->data.sex,
				p->data.birthday, p->data.degree, p->data.position, p->data.salary,
				p->data.addr, p->data.tel);        
			p = p->next; 

		}
		fclose(fp);  

	}

}


//��ȡְ����Ϣ 
void Du_qu(Node *worker)
{
	Node *p;
	FILE *fp; 

	if ((fp = fopen("职工信息管理系统.txt", "rb")) == NULL)     
	{
		printf("文件不能打开!\n ");
	}
	
	p = worker->next;
	while (p!=NULL)
	{
		fscanf(fp, " %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t ", p->data.jobNo, p->data.name, p->data.sex,
			p->data.birthday, p->data.degree, p->data.position, p->data.salary,
			p->data.addr, p->data.tel);     
		p=p->next;

	}
	fclose(fp);

}


//������ʵ�� 
int main()
{
	Node *worker;
	int flag;
	
	worker = (Node*)malloc(sizeof(Node));
	worker->next = NULL; 
	
 	while(1)
 	{
 			printf("\t职工信息管理系统\n");
			printf("==================菜单==================\n ");
			printf("1.输入职工信息\n ");
			printf("2.修改职工信息\n ");
			printf("3.浏览职工信息\n ");
			printf("4.查询职工信息\n ");
			printf("5.删除职工信息\n ");
			printf("6.读取职工信息\n ");
			printf("0.退出\n ");

			printf("输入你选择的序号");
			scanf("%d", &flag);
			switch (flag)
			{
				case 0:  printf(" \n提示：退出系统！!\n ");  break;
				case 1:	 Add(worker); save(worker);  break;    //����ְ����Ϣ,���浽�ļ��� 
				case 2:  change(worker);  break;           //�޸�ְ����Ϣ 
				case 3:  Disp(worker);  break;             //��ʾְ����Ϣ 
				case 4:  Cha_xun(worker);  break;           //��ѯְ����Ϣ 
				case 5:  Delete(worker);  break;          //ɾ��ְ����Ϣ 
				case 6:  Du_qu(worker);  break;             //��ȡְ����Ϣ 
				default: printf("提示：输入错误！\n ");
			}
	}
	
}
