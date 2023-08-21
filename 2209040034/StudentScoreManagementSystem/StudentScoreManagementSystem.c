#include<stdio.h>
#include<stdlib.h>
#define N 50



struct Student		
{
	long num;		  //学号
	char name[20];	  //姓名
	int class;        //班级
	int math;		  //数学成绩
	int english;      //英语成绩
	int computer;	  //计算机成绩
	int pj;           //平均成绩
}Stu[99];

int n;
int sum;

void Exit()
{
	system("cls");
	printf("\n\n\n\n");
	printf("\t\t\t****************************************************************\n");
	printf("\t\t\t||                                                            ||\n");
	printf("\t\t\t||                      感谢使用本程序！                      ||\n");
	printf("\t\t\t||                                                            ||\n");
	printf("\t\t\t||                                                            ||\n");
	printf("\t\t\t||                                                            ||\n");
	printf("\t\t\t****************************************************************\n");
}

void Menu()
{

	printf("                              *************************学生成绩管理系统************************\n");
	printf("                                                  请选择要进行的操作\n                                             \n");
	printf("                                                   1 : 添加学生的记录\n");
	printf("                                                   2 : 按学号查询学生\n");
	printf("                                                   3 : 按姓名查询学生\n");
	printf("                                                   4 : 按平均成绩排序\n");
	printf("                                                   5 : 按计算机成绩排序\n");
	printf("                                                   6 : 删除学生信息\n");
	printf("                                                   7 : 修改学生信息\n");
	printf("                                                   8 : 班级成绩分析\n");
	printf("                                                   9 : 输出学生信息表\n");
	printf("                                                   0 : 退出系统\n");
	printf("请输入你的选项: \n");
	scanf("%d", &sum);

}

int InputStudent()  //输入学生信息	
{
	int d;
	int i = n+1;

	while (i)
	{
		system("cls");
		printf("========================学生成绩输入========================\n\n");

		printf("\n请输入第%d个学生的信息:\n", i);
		
		printf("学号: ");
		scanf_s("%ld", &Stu[i].num);
	

		printf("姓名: ");
		scanf("%s", Stu[i].name);

		printf("班级: ");
		scanf("%d", &Stu[i].class);

		printf("数学成绩: ");
		scanf("%d", &Stu[i].math);

		printf("英语成绩: ");
		scanf("%d", &Stu[i].english);

		printf("计算机成绩: ");
		scanf("%d", &Stu[i].computer);
		Stu[i].pj = (Stu[i].math + Stu[i].english + Stu[i].computer) / 3;
		i++;
		n++;

	

		printf("是否继续输入?(1.继续 2.退出)\n");
		scanf("%d", &d);
		if (d == 2) {
			system("cls");
			return main();
		}
	}
}



void PrintStudent()		//输出学生成绩信息表
{

	int i;
	system("cls");
	printf("========================学生成绩显示========================\n\n\n");
	printf("\n学号\t姓名\t班级\t数学成绩\t英语成绩\t计算机成绩\t平均成绩\n\n\n");

	for (i = 1; i <= n; i++) {
		Stu[i].pj = (Stu[i].math + Stu[i].english + Stu[i].computer)/3;
		printf("%ld\t%s\t%d\t%d\t\t%d\t\t%d\t\t%d\n", Stu[i].num, Stu[i].name,Stu[i].class, Stu[i].math, Stu[i].english, Stu[i].computer, Stu[i].pj);
	}
	return main();
}



void SortStudentpj()		//平均成绩排序
{
	struct Student k;	
	int j;
	int i;
	system("cls");
	printf("\n============按平均成绩排序===========\n");//按平均成绩排序
	for (j = 0; j < n - 1; j++)
		for (i = 1; i < n - j; i++) {
			//Stu[i].pj = (Stu[i].computer + Stu[i].english + Stu[i].math) / 3;
			if (Stu[i].pj < Stu[i + 1].pj) {
				k = Stu[i];
				Stu[i] = Stu[i + 1];
				Stu[i + 1] = k;
			}
		}
	for (i = 1; i <= n; i++) {
		Stu[i].pj = (Stu[i].computer + Stu[i].english + Stu[i].math)/3;
		printf("学生的学号为:%ld\n", Stu[i].num);
		printf("学生的姓名为:%s\n", Stu[i].name);
		printf("学生的班级为:%d\n", Stu[i].class);
		printf("数学成绩为:%d\n", Stu[i].math);
		printf("英语成绩为:%d\n", Stu[i].english);
		printf("计算机成绩为:%d\n", Stu[i].computer);
		printf("学生的平均成绩为:%d\n\n", Stu[i].pj);
	}
	printf("\n");
	return main();
}
  
void SortStudentjsj()		//计算机成绩排序
{
	struct Student k;	
	int j;
	int i;
	system("cls");
	printf("\n============按计算机成绩排序===========\n");//按计算机成绩排序
	for (j = 0; j < n - 1; j++)
		for (i = 1; i < n - j; i++) {
			if (Stu[i].computer < Stu[i + 1].computer) {
				k = Stu[i];
				Stu[i] = Stu[i + 1];
				Stu[i + 1] = k;
			}
		}
	for (i = 1; i <= n; i++) {
		//Stu[i].pj = (Stu[i].computer + Stu[i].english + Stu[i].math)/3;
		printf("学生的学号为:%ld\n", Stu[i].num);
		printf("学生的姓名为:%s\n", Stu[i].name);
		printf("学生的班级为:%d\n", Stu[i].class);
		printf("数学成绩为:%d\n", Stu[i].math);
		printf("英语成绩为:%d\n", Stu[i].english);
		printf("计算机成绩为:%d\n", Stu[i].computer);
		printf("学生的平均成绩为:%d\n\n", Stu[i].pj);
	}
	printf("\n");
	return main();
}

void FindStudentxh()		//按学号查找学生信息
{
	long xuehao;
	int i, q;
	system("cls");
	printf("\n============按学号进行查找===========\n");
	printf("请输入要查找的学号: ");
	scanf("%ld", &xuehao);

	for (i = 1; i <= n; i++) {
		if (xuehao == Stu[i].num) {
		    Stu[i].pj = (Stu[i].computer + Stu[i].english + Stu[i].math)/3;
			printf("\n查找成功!\n\n\n");
			printf("学生的学号为:%ld\n", Stu[i].num);
			printf("学生的姓名为:%s\n", Stu[i].name);
			printf("学生的班级为:%d\n", Stu[i].class);
			printf("数学成绩为:%d\n", Stu[i].math);
			printf("语文成绩为:%d\n", Stu[i].english);
			printf("计算机成绩为:%d\n", Stu[i].computer);
			printf("学生平均成绩为:%d\n", Stu[i].pj);

		}
	}

	return main();

}

void FindStudentxm()     //按姓名查找学生信息
{
    char xingming[20];
	//char std[20];
    int i, q;
    system("cls");
    printf("\n============按姓名进行查找===========\n");
    printf("请输入要查找的姓名: ");
    scanf("%s", xingming);

    for (i = 1; i <= n; i++) {
		//strcpy(std,Stu[i].name);
	    if (strcmp(xingming,Stu[i].name) == 0) {
		    Stu[i].pj = (Stu[i].computer + Stu[i].english + Stu[i].math)/3;
		    printf("\n查找成功!\n\n\n");
		    printf("学生的学号为:%ld\n", Stu[i].num);
		    printf("学生的姓名为:%s\n", Stu[i].name);
			printf("学生的班级为:%d\n", Stu[i].class);
		    printf("数学成绩为:%d\n", Stu[i].math);
		    printf("语文成绩为:%d\n", Stu[i].english);
		    printf("计算机成绩为:%d\n", Stu[i].computer);
		    printf("学生平均成绩为:%d\n", Stu[i].pj);

	}
}

return main();

}



void DeleteStudent()	//删除学生记录
{
	int nums;
	int i, j, d;
	system("cls");
	printf("\n============按学号进行删除记录===========\n");
	printf("输入想要删除人的学号: ");
	scanf("%d", &nums);

	for (i = 1; i <= n; i++)
	{
		if (nums == Stu[i].num)
		{
			printf("学号\t姓名\t班级\t数学\t语文\t英语\t\n");
			printf("%ld\t%s\t%d\t%d\t%d\t%d\t\n", Stu[i].num, Stu[i].name,Stu[i].class, Stu[i].math, Stu[i].english, Stu[i].computer);

			printf("确认删除!请选择1或2：(1.YES 2.N0)\n");
			scanf("%d", &d);
			if (d == 1)
			{
				for (j = i; j <= n; j++)
				{
					Stu[j].num = Stu[j + 1].num;
					strcpy(Stu[j].name, Stu[j + 1].name);
					Stu[j].class = Stu[j + 1].class;
					Stu[j].math = Stu[j + 1].math;
					Stu[j].english = Stu[j + 1].english;
					Stu[j].computer = Stu[j + 1].computer;
					Stu[j].pj = Stu[j + 1].pj;
				}
				n--;
				return main();
			}
			if (d == 2)
			{
				return main();
			}
		}
	}
}

void ModifyStudent()	//修改学生信息
{

	int i;
	int w;
	long nums;
	system("cls");
	printf("\n============按学号进行修改===========\n");
	printf("请输入修改的学号:\n\n");
	scanf("%ld", &nums);
	for (i = 1; i <= n; i++)
	{
		if (Stu[i].num == nums)
		{
			printf("请重新输入该生信息: \n\n");
			printf("学号: \n");
			scanf("%ld", &Stu[i].num);
			printf("姓名: \n");
			scanf("%s", Stu[i].name);
			printf("班级: \n");
			scanf("%d", &Stu[i].class);
			printf("数学成绩: \n");
			scanf("%d", &Stu[i].math);
			printf("英语成绩: \n");
			scanf("%d", &Stu[i].english);
			printf("计算机成绩: \n");
			scanf("%d", &Stu[i].computer);
			Stu[i].pj = (Stu[i].math + Stu[i].english + Stu[i].computer)/3;
			printf("修改成功!\n\n");

		}
	}
	return main();
}

void ClassGradeAnalysis()//班级成绩分析
{
	printf("\n============班级成绩分析报告===========\n");
	printf("\n============各科成绩分析===========\n");
	printf("数学平均成绩：");
	int i;
	int m = 0;
	int e = 0;
	int c = 0;
	int mp;
	int ep;
	int cp;
	for (i = 1; i <= n; i++)
	{
		m = m + Stu[i].math;
	} 
	mp = m / n;
	printf("% d\t", mp);
	printf("数学最高分为：");
	int mmax = 0;
	for (i = 1; i <= n; i++)
	{
		if (Stu[i].math > mmax)
		{
			mmax = Stu[i].math;
		}
	}
	printf(" % d\t", mmax);
	printf("数学最低分为：");
	int mmin = mmax;
	for (i = 1; i <= n; i++)
	{
		if (Stu[i].math < mmin)
		{
			mmin = Stu[i].math;
		}
	}
	printf(" % d\t", mmin);
	printf("数学及格率为：");
	int sxjg = 0;
	float sxjgl;
	for (i = 1; i <= n; i++)
	{
		if (Stu[i].math > 59)
		{
			sxjg++;
		}
		else
			continue;
	}
	sxjgl = 100*sxjg /(float) n;
	printf("%.2f%%\n", sxjgl);



	printf("英语平均成绩：");
	for (i = 1; i <= n; i++)
	{
		e = e + Stu[i].english;
	}
	ep = e / n;
	printf("% d\t", ep);
	printf("英语最高分为：");
	int ymax = 0;
	for (i = 1; i <= n; i++)
	{
		if (Stu[i].math > ymax)
		{
			ymax = Stu[i].english;
		}
	}
	printf(" %d\t", ymax);
	printf("英语最低分为：");
	int ymin = ymax;
	for (i = n; i >0; i--)
	{
		if (Stu[i].math < ymin)
		{
			ymin = Stu[i].english;
		}
	}
	printf(" % d\t", ymin);
	printf("英语及格率为：");
	int yyjg = 0;
	float yyjgl;
	for (i = 1; i <= n; i++)
	{
		if (Stu[i].english > 59)
		{
			yyjg++;
		}
		else
			continue;
	}
	yyjgl = 100*yyjg / (float)n;
	printf("%.2f%%\n", yyjgl);



	printf("计算机平均成绩：");
	for (i = 1; i <= n; i++)
	{
		c = c + Stu[i].computer;
	}
	cp = c / n;
	printf("% d\t", cp);
	printf("计算机最高分为：");
	int jmax = 0;
	for (i = 1; i <= n; i++)
	{
		if (Stu[i].computer > jmax)
		{
			jmax = Stu[i].computer;
		}
	}
	printf(" % d\t", jmax);
	printf("计算机最低分为：");
	int jmin = jmax;
	for (i = 1; i <= n; i++)
	{
		if (Stu[i].computer < jmin)
		{
			jmin = Stu[i].computer;
		}
	}
	printf(" % d\t", jmin);
	printf("计算机及格率为：");
	int jjjjg = 0;
	float jjjjgl;
	for (i = 1; i <= n; i++)
	{
		if (Stu[i].computer > 59)
		{
			jjjjg++;
		}
		else
			continue;
	}
	jjjjgl = 100*jjjjg / (float)n;
	printf("%.2f%%\n", jjjjgl);
	return main();
}


//***********************主函数
int main()
{

	Menu();

	switch (sum) {


	case 1:  //添加学生信息

		InputStudent(Stu, N);
		break;
	case 2:  //查学号
		FindStudentxh(Stu, N);
		break;
	case 3:  //查姓名
		FindStudentxm(Stu, N);
		break;
	case 4:  //平均成绩
		SortStudentpj(Stu, N);
		break;
	case 5:  //计算机
		SortStudentjsj(Stu, N);
		break;
	case 6:  //删除
	    DeleteStudent(Stu, N);
		break;
	case 7:  //修改
		ModifyStudent(Stu, N);
		break;
	case 8:  //分析
		ClassGradeAnalysis(Stu, N);
		break;
	case 9:  //输出
		PrintStudent(Stu, N);
		break;
	case 0:  //退出
		Exit(Stu, N);
		break;
	}
	return 0;

}