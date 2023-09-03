#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 10
typedef struct
{
	int a[NUM];
	int b[NUM];
	char oper[NUM];
	int ans[NUM];
}StudentTest;
 
StudentTest CreateStudentTest();
int add(int a,int b);
int sub(int a,int b);
void Judge(StudentTest S);
 
StudentTest CreateStudentTest(){
		StudentTest S;
		srand((unsigned)time(NULL));
		for(int i=0;i<10;i++){
			S.oper[i] = (rand()%2)?'+':'-';		
			do{
				S.a[i] = rand()%50;
				S.b[i] = rand()%50;
				switch(S.oper[i]){
					case '+':S.ans[i] = add(S.a[i],S.b[i]);break;
					case '-':S.ans[i] = sub(S.a[i], S.b[i]); break;
				}
			}while(S.ans[i]>50||S.ans[i]<0);
		}
		return S;
}
 
int add(int a,int b){
		return a + b;
}
 
int sub(int a, int b){
		return a - b;
}
 
void Judge(StudentTest S){
		int ans,count = 0, score = 0;
		for (int i = 0; i < 10; i++){
			count = 0;
			do{
				printf("%d %c %d = ", S.a[i], S.oper[i], S.b[i]);
				scanf("%d", &ans);
				if (ans == S.ans[i]){
					switch (count){
						case 0: score += 10; break;
						case 1: score += 7; break;
						case 2: score += 5; break;
					}
					printf("恭喜你回答正确，目前的得分 %d分\n\n",score);
					break;
				}
				else {
					count++;
					if (count<3) printf("答案错误，请重新输入！你还有%d次机会\n\n",3-count);
					else printf("答案错误，本题正确答案是 %d\n将会继续下一题\n\n",S.ans[i]);
				}
			} while (count < 3);
		}
		printf("-------------------------------\n");
		printf("您本次测试的总分是 %d 分", score);
		if (score >= 90) printf("  S M A R T  \n");
		else if (score < 90 && score >= 80)printf("  G O O D  \n");
		else if (score < 80 && score >= 70)printf("  O K  \n");
		else if (score < 70 && score >= 60)printf("  P A S S  \n");
		else printf("  TRY AGAIN  \n");
}
 
int main(){
		printf("小学生测验系统\n");
		printf("-------------------------------\n");
		StudentTest S = CreateStudentTest();
		Judge(S);
		system("pause"); 
}
