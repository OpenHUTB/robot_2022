#include <stdio.h>
#include <string.h>
#include <math.h>
 
#define LING 1E-6
#define CONT 4
#define VOLUE 24
 
float num[CONT];  
char E[CONT][20] ;    
bool m_judge = false;   //判断是否有解。
int count = 0;
 
void Find(int n)
{
 int i = 0, j = 0;
 
 if (n == 1)
 {
  if ( fabs(num[i] - 24) <= LING)
  {
   for (i = 0; i < 20; i++) 
   {
    printf("%c", E[0][i]) ;
   }
   printf("\t\t") ;
   m_judge = true;
   count ++;                       //结果总数
   if((count % 2)==0)     //使输出时每行二个表达式
    printf("\n") ;
  }
 }
 for(i = 0; i < n; i++)    //查找
 {
  for (j = i + 1; j < n; j++)  //与其后面的查找进行计算
  {
   float a, b; 
   char Ea[20], Eb[20];
    
   a = num[i] ;
   b = num[j] ;
   num[j] = num[n - 1];
 
   strcpy(Ea, E[i]) ;
   strcpy(Eb, E[j]) ;
   strcpy(E[j], E[n - 1]) ;
   
   sprintf(E[i], "(%s+%s)", Ea, Eb) ;
   num[i] = a + b;
   Find(n-1);
  
   sprintf(E[i], "(%s-%s)",Ea, Eb) ;
   num[i] = a - b;
   Find(n-1);
   
   sprintf(E[i], "(%s-%s)", Eb, Ea) ;
   num[i] = b - a;
   Find(n-1);
   
   sprintf(E[i], "(%s*%s)", Ea, Eb) ;
   num[i] = a * b;
   Find(n-1);
   
   if (b != 0)
   {
    sprintf(E[i], "(%s/%s)", Ea, Eb) ;
    num[i] = a / b;
    Find(n-1);
   }
   if (a != 0)
   {
    sprintf(E[i], "(%s/%s)", Eb, Ea) ;
    num[i] = b / a;
    Find(n-1);
   }
   num[i] = a;       // 最后一层number[0]
   num[j] = b;       
   strcpy(E[i], Ea) ; 
   strcpy(E[j], Eb) ;
  }
 }
}
 
int Input() //按要求输入数字
{
 int i, j ;
 printf("请输入四个数（介于1——13之间）:\n") ;
 for (i = 0; i < CONT; i++)
 {
  char ch[20], s;
  int a ;
  printf("第%d个数:", i+1) ;
  scanf("%f", &num[i]) ;
  a = (int)num[i] ;
  s = char(a + 48);
  ch[0] = s ;
  for (j = 1; j < 20; j++) 
  {
   ch[j] = 0 ;
  }
  strcpy(E[i], ch) ;
 }
 
 printf("\n") ;
 return 0;
}
 
int main()          //主函数
{
    Input();         //输入函数：输入数字
 Find(CONT) ;     //查找函数：找出结果
 if(m_judge==true)
 {
  printf("\n成功:以上是所有可能！\n") ;
  printf("总共的计算方法共有:%d\n", count) ;
 }
 else
 {
  printf("失败：没有结果！") ;
 }
 printf("\n\n\n");
 return Input();
}
 
