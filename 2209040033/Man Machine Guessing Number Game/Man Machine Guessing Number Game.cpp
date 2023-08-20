#include<stdio.h>
#include<time.h>
#include<windows.h>
int check(int n, int *s)
{
	int i=3,t;
	t=n;
	while (n)
	{
		s[i] = n%10;
		if (s[i]==0)
			return 0;
		n /= 10;
		i--;
	}
	if (s[0]!=s[1]&&s[0]!=s[2]&&s[0]!=s[3] && s[1]!=s[2]&&s[1]!=s[3] && s[2]!=s[3])
		return t;
    return 0;
}
int main()
{
	int number,numberplay,a[4],b[4];
	int A=0,B=0,i,j,t=0;
    srand(time(NULL));
	printf("玩家输入数字：");
	while (1) //
	{
		number = rand() % (10000 - 1000 + 1) + 1000; //随机数范围，% 距离差 + 小的数
		number = check(number, a);//生成合法数
		if (number)
		{
			break;
		}
	}
    while (1)//玩家输入的数检测
	{
		A=B=0;
		scanf("%d",&numberplay);
		numberplay = check(numberplay, b);
		//输入不合法
		if (!numberplay)
		{
			printf("请输入四位不相同且都不为0的数！\n");
			continue;
		}
		printf("%d %d\n",number,numberplay);
		//位置相同且数字相同
		for (i=0;i<4;i++)
		{
			if (a[i]==b[i])
				A++;
		}
		//数字相同但位置不同
		for (i=0;i<3;i++)
		{
			for (j=i+1;j<4;j++)
			{
				if (a[i]==b[j]&&i!=j)
					B++;
			}
		}
		printf("本次结果：\n位置相同且数字相同的数：%d\n数字相同但位置不同的数：%d\n",A,B);
		t=t+1;
		if (A==4)
		{
			printf("正确!且次数为：%d\n",t);
			break;
		}
	}
	return 0;
}
