#include<stdio.h>
#include<math.h>
#include<string.h>
#include<windows.h>
 
 
char sign[3];       //����ʽ�ӵ��������� 
int n[3][2];       //����ʽ�ӵ����������� 
int cnt=0;            //��¼�ڼ��ֽⷨ 
 
int option(int a,int b)    // ������� ����С�����Դ��� 
{
	int c;
	if(a<b){        //������ǰ�� ������������� 
		c=a;
		a=b;
		b=c;
	}
	return (a/b) ;
	
}
 
int pd(int a,int b)    //�Ƿ����������ж� 
{
	int c;
	if(a<b){        //������ǰ�� ������������� 
		c=a;
		a=b;
		b=c;
	}
	if((a*b!=0)&&(a%b==0)){
		return 1;
	}
	else return 0;
}
 
int cal(int a,char x,int b)
{
	if ( x=='+' ) return a+b;
	if ( x=='-' ) return abs(a-b);
	if ( x=='*' ) return a*b;
	if ( x=='/' ) return a/b;
}
void print()
{
	int i,t; 
	int temp;
//	int l,j;
//	for (l=0;l<3;l++){
//		printf("��%d�� ",l+1) ;
//		for(j=0;j<3;j++){
//			printf("%c ",sign[l][j]);
//			if (j==2) printf("\n");
//		}
//	}
 
//	for (t=0;t<3;t++){
//		printf("��%d�� %d %c %d\n",t+1,n[t][0],sign[t],n[t][1]);
//	}
	cnt++;
	printf("**********************�ⷨ%d**********************\n",cnt);		
	for (t=0;t<3;t++){
		if(sign[t]=='-'||sign[t]=='/'){
			if(n[t][0]<n[t][1]){
				int a;
				a=n[t][0];
				n[t][0]=n[t][1];
				n[t][1]=a;
			}
		}
		temp=cal(n[t][0],sign[t],n[t][1]);
		printf("%d%c%d=%d\n",n[t][0],sign[t],n[t][1],temp);
	}
	
}
 
void step3(int num3[4])
{
	int i;
	int temp3[4];
	int *u=temp3;
	int count;
	for (i=1;i<=4;i++){
	//	i=3;  //******����******* 
		memcpy(temp3,num3,sizeof(int)*2);     //��ԭΪԭ�������� 
		switch (i)        //�Ӽ��˳��Ĵβ���  ��¼�ڶ���ʽ�� 
		{
			n[2][0]=*(u+0); 
			n[2][1]=*(u+1); 
			case 1:
				sign[2]='+';
				count=*(u+0) + *(u+1); 
				break;
			case 2:
				sign[2]='-';
				count=abs(*(u+0) - *(u+1));
				break;
			case 3:
				sign[2]='*';
				count=*(u+0) * *(u+1);
				break;
			case 4:
				if(pd(*(u+0) , *(u+1))){
					sign[2]='/';
					count=option(*(u+0) , *(u+1));
				}
				break;
		}
		if(count==24)
		{
			print();
			count=0;
		 } 
	
	}
}
void step2(int a,int b,int num2[4])
{
	int i,cf=1;
	int temp2[4];
	int *u=temp2;
	for (i=1;i<=4;i++){
		cf=1;
		memcpy(temp2,num2,sizeof(int)*3);     //��ԭΪԭ�������� 
		switch (i)        //�Ӽ��˳��Ĵβ���  ��¼�ڶ���ʽ�� 
		{
			case 1:
				sign[1]='+';
				*(u+a)=*(u+a) + *(u+b);
				break;
			case 2:
				sign[1]='-'; 
				*(u+a)=abs(*(u+a) - *(u+b));
				break;
			case 3:
				sign[1]='*';
				*(u+a)=*(u+a) * *(u+b);
				break;
			case 4:
				if(cf=pd(*(u+a) , *(u+b))){      //��¼�Ƿ������� �˲�û�������� ��ô���ü���������ȥ��
					sign[1]='/'; 
					*(u+a)=option(*(u+a),*(u+b));
			    }
				break;
		}
		if(cf){
			int *q;
		for(q=u+b;q<u+2;q++){    //�Ѻ��������ǰ��һλ ��ʣ2���� 
			*q=*(q+1);
		}
		
		n[2][0]=temp2[0];
		n[2][1]=temp2[1];
	//	printf("��� 2 �������棺%d %d\n",temp2[0],temp2[1]) ;
		step3(temp2) ;
	//	if (i==4) printf("\n") ;
		} 
	}
}
 
void step1(int a,int b,int num1[4])        //num1Ϊ�������飬temp[]Ϊ������� 
{
	int i,cf;
	int temp1[4];
	int *u=temp1;
	for (i=1;i<=4;i++){
		cf=1;	
		memcpy(temp1,num1,sizeof(int)*4);     //�ָ�ԭ����������д��� 
		switch (i)        //�Ӽ��˳��Ĵβ���  ��¼��һ��ʽ�� 
		{
			case 1:
				sign[0]='+';
				*(u+a)=*(u+a) + *(u+b);
				break;
			case 2:
				sign[0]='-';
				*(u+a)=abs(*(u+a) - *(u+b));
				break;
			case 3:
				sign[0]='*';
				*(u+a)=*(u+a) * *(u+b);
				break;
			case 4:
				if(cf=pd(*(u+a) , *(u+b))){     //��¼�Ƿ������� �˲�û�������� ��ô���ü���������ȥ��
					sign[0]='/';
					*(u+a)=option(*(u+a),*(u+b));
				}
				break;
		}
		if (cf){
			int *q;
			for(q=u+b;q<u+3;q++){    //�ӵ�b���Ѻ��������ǰ��һλ  ��ʣ3���� 
				*q=*(q+1);
			}
			
			int l,j;
			for(l=0;l<3;l++){
				for(j=l+1;j<3;j++){		
					n[1][0]=temp1[l];
					n[1][1]=temp1[j];
				//	printf("��� 1 �������棺%d %d %d\n",temp1[0],temp1[1],temp1[2]) ;
					step2(l,j,temp1) ;
				}
			} 
		}
	}
}
 
int main(void){
	int num[4];
	void step1(int,int,int temp1[]);
	void step2(int,int,int temp2[]);
	void step3(int temp3[]);
	void print();
	int cal(int ,char,int );
	int pd(int,int); 
	
	printf("****************************\n") ;
	printf("*                          *\n") ;
	printf("*    ������24����Ϸ���    *\n") ;
	printf("*                          *\n") ;
	printf("****************************\n") ;
	
loop:	printf("�������ĸ����� ���˳���Ϸ������0 �ٰ��س���\n");	
	cnt =0;
	int i;
	for (i=0;i<4;i++){        //�����ĸ����� 
		scanf("%d",&num[i]);
		if(num[i]==0) goto out;
	}
	
	int l,j;
	for(l=0;l<4;l++){
		for(j=l+1;j<4;j++){	
			n[0][0]=num[l];
			n[0][1]=num[j];		
			//printf("��ʼ�����棺%d %d %d %d\n",num[0],num[1],num[2],num[3]) ;
			step1(l,j,num);
		}
	}
	if(cnt==0) printf("�ƣ����Ұ��죬������û����\n") ;
	printf("\n");
	goto loop;
	
	
	
out:	     //����������� 	
	return 0;
}
