#include<stdio.h> 
#include<stdlib.h>  
#include<string.h>
struct workers
{
	char jobNo[15];       //职工号
	char name[15];        //姓名
	char sex[15];         //性别
	char birthday[15];    //出生年月
	char degree[15];      //学历
	char position[15];    //职务 
	char salary[15];      //工资 
	char addr[15];        //住址 
	char tel[15];         //电话 

};


//类型定义语句  
typedef struct node
{
	struct workers data;
	struct node *next;

}Node;

 
//添加信息函数     "尾插法建表"
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
		printf("鎻愮ず锛氳緭鍏�0杩斿洖涓昏彍鍗曪紒\n");
		printf("璇疯緭鍏ヨ亴宸ュ彿锛�");
		scanf("%s", n);
		if (strcmp(n, "0") == 0)
		{
			break;
		}
		p = (Node *)malloc(sizeof(Node));
		strcpy(p->data.jobNo, n);
		
		printf("璇疯緭鍏ュ鍚嶏細");
		scanf("%s", p->data.name);
		printf("璇疯緭鍏ユ�у埆锛�");
		scanf("%s", p->data.sex);
		printf("璇疯緭鍏ュ嚭鐢熷勾鏈堬細");
		scanf("%s", p->data.birthday);
		printf("璇疯緭鍏ュ鍘嗭細");
		scanf("%s", p->data.degree);
		printf("璇疯緭鍏ヨ亴鍔★細");
		scanf("%s", p->data.position);
		printf("璇疯緭鍏ュ伐璧勶細");
		scanf("%s", p->data.salary);
		printf("璇疯緭鍏ヤ綇鍧�锛�");
		scanf("%s", p->data.addr);
		printf("璇疯緭鍏ョ數璇濓細");
		scanf("%s", p->data.tel);
		printf("鎻愮ず锛氬凡缁忓畬鎴愪竴鏉¤褰曠殑娣诲姞锛�");
		p->next = NULL;
		q->next = p;      
		q = p;        

	}

}


//修改职工信息函数
int  change(Node *worker)
{
	Node *p;
	char find[20];   
	p = worker->next;   
	if (p == NULL)
	{
		printf("\n鎻愮ず锛氭病鏈夎祫鏂欏彲浠ヤ慨鏀癸紒\n");
		return 0;
	}
	
	printf("璇疯緭鍏ヨ淇敼鐨勮亴宸ュ彿");
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
			printf("瀹屾垚淇敼璇疯緭鍏ワ紝鍚﹀垯杈撳叆闈炴暟瀛楄繘琛屼慨鏀癸紒");
			scanf("%d", &x);
			if (x == 0)
			{
				break;
			}
			printf(" 璇疯緭鍏ユ柊鐨勮亴宸ュ彿: ");
			scanf("%s", p->data.jobNo);
			printf(" 璇疯緭鍏ユ柊鐨勮亴宸ュ鍚�: ");
			scanf("%s", p->data.name);
			printf(" 璇疯緭鍏ユ柊鐨勮亴宸ユ�у埆: ");
			scanf("%s", p->data.sex);
			printf(" 璇疯緭鍏ユ柊鐨勮亴宸ュ嚭鐢熷勾鏈�: ");
			scanf("%s", p->data.birthday);
			printf(" 璇疯緭鍏ユ柊鐨勮亴宸ュ鍘�: ");
			scanf("%s", p->data.degree);
			printf(" 璇疯緭鍏ユ柊鐨勮亴宸ヨ亴鍔�: ");
			scanf("%s", p->data.position);
			printf(" 璇疯緭鍏ユ柊鐨勮亴宸ュ伐璧�: ");
			scanf("%s", p->data.salary);
			printf(" 璇疯緭鍏ユ柊鐨勮亴宸ヤ綇鍧�址: ");
			scanf("%s", p->data.addr);
			printf(" 璇疯緭鍏ユ柊鐨勮亴宸ョ數璇�: ");
			scanf("%s", p->data.tel);
			printf(" \n鎻愮ず锛氳鍛樺伐璧勬枡宸茬粡淇敼锛乗n ");
		}
	}
	else 
		printf("\n鎻愮ず锛氭病鏈変綘瑕佷慨鏀圭殑璧勬枡!\n ");
}


//输出职工信息函数
int  Disp(Node *worker)
{
	Node *p;
	p = worker->next;
	if (p == NULL)
	{
		printf(" \n鎻愮ず锛氭病鏈変俊鎭彲浠ユ樉绀�!\n ");
		return 0;

	}
	printf("\t\t\t\t鏄剧ず缁撴灉\n");
	printf(" \n鑱屽伐鍙峰鍚� 鎬у埆 鍑虹敓骞存湀 瀛﹀巻 鑱屽姟 宸ヨ祫 浣忓潃 鐢佃瘽\n ");
	while (p!=NULL)  
	{
		printf("\n %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t\n ", p->data.jobNo, p->data.name,
			p->data.sex, p->data.birthday, p->data.degree, p->data.position,
			p->data.salary, p->data.addr, p->data.tel);
		p = p->next;

	}

}


//查询职工信息函数: 按职工号查询	按职工姓名查询
int  Cha_xun(Node *worker)
{
	Node *p;
	int sel;
	char find[20];	
	p = worker->next;   

	if (p==NULL) 
	{
		printf(" \n鎻愮ず锛氭病鏈夎祫鏂欏彲浠ユ煡璇紒\n ");
		return 0;

	}

	printf("\n鎻愮ず\n杈撳叆0----閫�鍑篭t杈撳叆1----鎸夎亴宸ュ彿鏌ヨ\t杈撳叆2----鎸夎亴宸ュ鍚嶆煡璇n");
	printf("请选择：");
	scanf("%d", &sel);

	if (sel == 1)
	{
		printf("\n璇疯緭鍏ヤ綘瑕佹煡璇㈠垎绫荤殑鑱屽伐鍙凤細");
		scanf("%s", find);
		while (p!=NULL)  
		{
			if (strcmp(p->data.jobNo, find) == 0)
			{
				printf(" 鑱屽伐鍙峰鍚� 鎬у埆 鍑虹敓骞存湀 瀛﹀巻 鑱屽姟 宸ヨ祫 浣忓潃 鐢佃瘽\n ");
				printf(" \n %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t %s\t\n ", p->data.jobNo, p->data.name,
					p->data.sex, p->data.birthday, p->data.degree, p->data.position,
					p->data.salary, p->data.addr, p->data.tel);

			}
			p = p->next;   

		}

	}

	else if (sel == 2)
	{
		printf(" \n璇疯緭鍏ヤ綘瑕佹煡璇㈠垎绫荤殑鑱屽伐濮撳悕锛�");
		scanf("%s", find);
		while (p!=NULL)
		{
			if (strcmp(p->data.name, find) == 0) 
			{
				printf(" 鑱屽伐鍙峰鍚� 鎬у埆 鍑虹敓骞存湀 瀛﹀巻 鑱屽姟 宸ヨ祫 浣忓潃 鐢佃瘽 \n ");
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


//删除职工信息函数
int  Delete(Node *worker)
{
	Node *p, *r;
	char find[10];
	p = worker->next;
	if (p == NULL)
	{
		printf("鎻愮ず锛氭病鏈夎亴宸ヤ俊鎭彲浠ュ垹闄わ紒\n ");
		return 0; 

	}
	printf(" \n鎻愮ず锛氳杈撳叆浣犺鍒犻櫎鐨勮亴宸ュ彿锛乗n ");
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


//将职工信息保存到文件中
void save(Node *worker)
{
	int n;
	Node *p = NULL;
	FILE *fp;    
	printf("鏄惁淇濆瓨鍒版枃浠讹紵锛�1----淇濆瓨锛侊紝0----涓嶄繚瀛橈紒锛�");
	scanf("%d", &n);

	if (n == 1)
	{
		if (worker->next == NULL)
		{
			printf("娌℃湁璁板綍锛�");
		}

		else
		{
			p = worker->next;
		}

		if ((fp = fopen(" 鑱屽伐淇℃伅绠＄悊绯荤粺.txt ", " wb ")) == NULL)  
		{
			printf(" 鏂囦欢涓嶈兘鎵撳紑锛乗n");     
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


//读取职工信息 
void Du_qu(Node *worker)
{
	Node *p;
	FILE *fp; 

	if ((fp = fopen("鑱屽伐淇℃伅绠＄悊绯荤粺.txt", "rb")) == NULL)     
	{
		printf("鏂囦欢涓嶈兘鎵撳紑!\n ");
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


//主函数实现 
int main()
{
	Node *worker;
	int flag;
	
	worker = (Node*)malloc(sizeof(Node));
	worker->next = NULL; 
	
 	while(1)
 	{
 			printf("\t鑱屽伐淇℃伅绠＄悊绯荤粺\n");
			printf("==================鑿滃崟==================\n ");
			printf("1.杈撳叆鑱屽伐淇℃伅\n ");
			printf("2.淇敼鑱屽伐淇℃伅\n ");
			printf("3.娴忚鑱屽伐淇℃伅\n ");
			printf("4.鏌ヨ鑱屽伐淇℃伅\n ");
			printf("5.鍒犻櫎鑱屽伐淇℃伅\n ");
			printf("6.璇诲彇鑱屽伐淇℃伅\n ");
			printf("0.閫�鍑篭n ");

			printf("杈撳叆浣犻�夋嫨鐨勫簭鍙�");
			scanf("%d", &flag);
			switch (flag)
			{
				case 0:  printf(" \n鎻愮ず锛氶��鍑虹郴缁燂紒!\n ");  break;
				case 1:	 Add(worker); save(worker);  break;    //添加职工信息,保存到文件中 
				case 2:  change(worker);  break;           //修改职工信息 
				case 3:  Disp(worker);  break;             //显示职工信息 
				case 4:  Cha_xun(worker);  break;           //查询职工信息 
				case 5:  Delete(worker);  break;          //删除职工信息 
				case 6:  Du_qu(worker);  break;             //读取职工信息 
				default: printf("鎻愮ず锛氳緭鍏ラ敊璇紒\n ");
			}
	}
	
}
