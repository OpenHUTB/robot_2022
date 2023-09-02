#include<stdio.h>
#include<math.h>
#include<string.h>
#include<windows.h>
 
 
char sign[3];       //三条式子的三个符号 
int n[3][2];       //三条式子的三对运算数 
int cnt=0;            //记录第几种解法 
 
int option(int a,int b)    // 计算除法 避免小数除以大数 
{
	int c;
	if(a<b){        //大数排前面 方便后面做除法 
		c=a;
		a=b;
		b=c;
	}
	return (a/b) ;
	
}
 
int pd(int a,int b)    //是否做除法的判断 
{
	int c;
	if(a<b){        //大数排前面 方便后面做除法 
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
//		printf("第%d条 ",l+1) ;
//		for(j=0;j<3;j++){
//			printf("%c ",sign[l][j]);
//			if (j==2) printf("\n");
//		}
//	}
 
//	for (t=0;t<3;t++){
//		printf("第%d条 %d %c %d\n",t+1,n[t][0],sign[t],n[t][1]);
//	}
	cnt++;
	printf("**********************解法%d**********************\n",cnt);		
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
	//	i=3;  //******调试******* 
		memcpy(temp3,num3,sizeof(int)*2);     //还原为原来的数组 
		switch (i)        //加减乘除四次操作  记录第二条式子 
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
		memcpy(temp2,num2,sizeof(int)*3);     //还原为原来的数组 
		switch (i)        //加减乘除四次操作  记录第二条式子 
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
				if(cf=pd(*(u+a) , *(u+b))){      //记录是否做除法 此步没有做运算 那么不用继续进行下去了
					sign[1]='/'; 
					*(u+a)=option(*(u+a),*(u+b));
			    }
				break;
		}
		if(cf){
			int *q;
		for(q=u+b;q<u+2;q++){    //把后面的数往前移一位 还剩2个数 
			*q=*(q+1);
		}
		
		n[2][0]=temp2[0];
		n[2][1]=temp2[1];
	//	printf("算第 2 遍后的牌面：%d %d\n",temp2[0],temp2[1]) ;
		step3(temp2) ;
	//	if (i==4) printf("\n") ;
		} 
	}
}
 
void step1(int a,int b,int num1[4])        //num1为接入数组，temp[]为输出数组 
{
	int i,cf;
	int temp1[4];
	int *u=temp1;
	for (i=1;i<=4;i++){
		cf=1;	
		memcpy(temp1,num1,sizeof(int)*4);     //恢复原来的数组进行处理 
		switch (i)        //加减乘除四次操作  记录第一条式子 
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
				if(cf=pd(*(u+a) , *(u+b))){     //记录是否做除法 此步没有做运算 那么不用继续进行下去了
					sign[0]='/';
					*(u+a)=option(*(u+a),*(u+b));
				}
				break;
		}
		if (cf){
			int *q;
			for(q=u+b;q<u+3;q++){    //从第b个把后面的数往前移一位  还剩3个数 
				*q=*(q+1);
			}
			
			int l,j;
			for(l=0;l<3;l++){
				for(j=l+1;j<3;j++){		
					n[1][0]=temp1[l];
					n[1][1]=temp1[j];
				//	printf("算第 1 遍后的牌面：%d %d %d\n",temp1[0],temp1[1],temp1[2]) ;
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
	printf("*    这里是24点游戏外挂    *\n") ;
	printf("*                          *\n") ;
	printf("****************************\n") ;
	
loop:	printf("请输入四个整数 （退出游戏：输入0 再按回车）\n");	
	cnt =0;
	int i;
	for (i=0;i<4;i++){        //读入四个整数 
		scanf("%d",&num[i]);
		if(num[i]==0) goto out;
	}
	
	int l,j;
	for(l=0;l<4;l++){
		for(j=l+1;j<4;j++){	
			n[0][0]=num[l];
			n[0][1]=num[j];		
			//printf("开始的牌面：%d %d %d %d\n",num[0],num[1],num[2],num[3]) ;
			step1(l,j,num);
		}
	}
	if(cnt==0) printf("淦！算我半天，这组数没解哇\n") ;
	printf("\n");
	goto loop;
	
	
	
out:	     //程序结束出口 	
	return 0;
}
