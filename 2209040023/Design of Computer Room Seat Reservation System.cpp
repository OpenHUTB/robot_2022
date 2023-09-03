#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 20
#define T  (time-8)/2

int sum[6]={0};
int computer[6][20]={{1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,0,0,1,1,1},
{1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0},
{1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1}};
void Menu();       
void Situation();
void Book();
void Cancel();
void SearchWaiting();
void detail(int time);
void prione(int i);
struct waitlist      
{
   char number[3];
   char telephonenumber[11];      
} wait[N];

void printone(int i);
int main()
{
	Menu();     
}
void Menu()        
{
	int n,w;
	do
	{
	  puts("\t\t****************������λԤԼϵͳ************************\n");
      puts("\t\t*************************�˵�***************************\n");
	  puts("\t\t\t 1.��ѯĳʱ��λ�λ״̬");  
	  puts("\t\t\t 2.Ԥ���ջ�λ");   
	  puts("\t\t\t 3.ȡ��Ԥ��");   
	  puts("\t\t\t 4.��ѯ�ȴ���Ϣ");     
      puts("\t\t\t 5.�˳�");    
	  puts("\t\t********************************************************\n");
	  printf("ѡ��˵���(1-5):");
	  scanf("%d",&n); 
	  if(n<1||n>5)
	  {w=1;getchar();}
	  else
	  w=0;
	}while(w==1);
	switch(n)
	{
	case 1:Situation();break;
	case 2:Book();break; 
	case 3:Cancel();break;
	case 4:SearchWaiting();break;
	case 5:exit(0);break;
	}
	getchar();
}
void Situation()
{
	int time;
	printf("���� (8-20)��Χ�ڵ�ʱ��:");
	scanf("%d",&time);
	if(time<8||time>20)
	{printf("\tʱ���������!\n");
	printf("������ (8-20)��Χ�ڵ�ʱ��:");
	scanf("%d",&time);
    }
	detail(time);              
	getchar();
	Menu();
}
void Book()
{
	int time,i=0,x,y;
	FILE *fp;
 	char c;
 	printf("��(8-20)ʱ�䷶Χ����������ҪԤ����ʱ��:");
 	scanf("%d",&time);
 	if(time<8||time>20)
 	{
	 	printf("\tʱ���������!\n");
	 	printf("\t��(8-20)ʱ�䷶Χ����������ҪԤ����ʱ��:");
	 	scanf("%d",&time);
	}
	detail(time);              
	if(sum[T]>0)
	{   
		if((fp=fopen("waitlist.txt","a"))==NULL)
		{
		   printf("\n�޷����ļ�!\n");
		  exit(0);
		}
	    printf("\n\t����������ҪԤ���Ļ��ţ�����������ĵ绰����!:\n");	
	    scanf("%s %s",wait[i].number,wait[i].telephonenumber);
		for(i=0;i<1;i++)
	    fwrite(&wait[i],sizeof(struct waitlist),1,fp);
	    fclose(fp);
		printf("\t�ٴ���������ҪԤ����ʱ��!\n");
		scanf("%d",&x);
		sum[T]--;       
		computer[T][x]=1;   
		printf("\tԤ���ɹ�!\n");
		getchar();
		Menu();
	}
	else
	{
		printf("���������ʱ�����δԤ���ĵ���!\n");
		for(i=T+1;i<6;i++)
		{    time=9+2*i;
			detail(time); 
			if(sum[T]>0)
			printf("\t����Ŀ���ʱ���� %d,%d\n",2*i+8,2*i+10);
			break;
		}
		printf("\t����ҪԤ����?:y/n?");
		scanf("%s",&c);
		getchar();
		if(c=='Y'||c=='y')
		{
		   if((fp=fopen("waitlist.txt","r"))==NULL)
		 {
            printf("\n�޷����ļ�!\n");
	        exit(0);
		 }
		   else
		   {  printf("waitlist�� number  telephonenumber\n");
              for(i=0;!feof(fp);i++)
			  {
			     fscanf(fp,"%s %s",&wait[i].number,&wait[i].telephonenumber);
			  }
                fclose(fp);
		   }
		       for(i=0;i<10;i++)
			   { prione(i);}
        printf("\n\t����������Ԥ���Ļ��Ų�����������ϵ��ʽ!:\n");
        if((fp=fopen("waitlist.txt","a"))==NULL)
		{
		   printf("\n�޷����ļ�!\n");
		  exit(0);
		}
	
	    scanf("%s %s",wait[i].number,wait[i].telephonenumber);
	    for(i=0;i<1;i++)
	    fwrite(&wait[i],sizeof(struct waitlist),1,fp);
	    fclose(fp);                 
		printf("�ٴ�������Ե����!\n");
		scanf("%d",&y);
		sum[T]--;                  
		computer[T][y]=1;  
	    printf("\t����,��ȴ����ǵĵ绰!\n");
	    Menu();
		}
   		else Menu();
	}
}
void Cancel()
{
	int time,number;
	printf("��(8-20)ʱ�䷶Χ���������Ѿ�Ԥ����ʱ��:");
	scanf("%d",&time); 
	if(time<8||time>20)
	{
	 printf("\t����ʱ�����!\n");
	 printf("\t��(8-20)ʱ�䷶Χ���������Ѿ�Ԥ����ʱ��:");
	 scanf("%d",&time);
   	}
	else
	{printf("\t������Ԥ���Ļ��� :");
	scanf("%d",&number);}
	detail(time);
    sum[T]++;    
	computer[T][number]=0;   
	printf("\tȡ���ɹ�!\n");
	getchar();
	Menu();
}
void SearchWaiting()
{
	int time,i;
     FILE *fp;
	printf("\t��(8-20)֮��������Ҫ������ʱ��:");
	scanf("%d",&time);
	if(time<8||time>20)
	{
	 printf("\tʱ���������!\n");
	 printf("\t��(8-20)֮��������Ҫ������ʱ��:");
	 scanf("%d",&time);
	}
	else   if((fp=fopen("waitlist.txt","r"))==NULL)
   {
      printf("\nCannot open file!\n");
	 exit(0);
   }
   else
   {  printf("waitlist�� number  telephonenumber\n");
        for(i=0;!feof(fp);i++)
		 {
			  fscanf(fp,"%s %s",&wait[i].number,&wait[i].telephonenumber);
		 }
          fclose(fp);
}
	for(i=0;i<10;i++)
	{ prione(i);}
	Menu();
}
void detail(int time)      
{   
	int i,j=0,k,s=0;
	int v[30];
    for(i=0;i<20;i++)
	{
    if(computer[T][i]==0)
	{  s++;	
	   v[j++]=i;
	}
	}
	sum[T]=s;
	printf("\tĿǰ���õĵ�������Ϊ:%d\n",sum[T]);
	for(k=0;k<j;k++)
	printf("\t���õĵ�����:%d\n",v[k]);
}
void prione(int i)          
{
	printf("\t\t%s %s  \n",wait[i].number,wait[i].telephonenumber);
}
