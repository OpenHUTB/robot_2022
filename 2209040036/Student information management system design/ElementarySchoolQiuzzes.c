#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>
#define M 80



char f;
FILE* fp;//定义指向文件的指针 


struct student
{
    char num[13];
    char name[15];
    int age;
    char x[5];
    char year_month_day[15];
    char address[30];
    int iphone;
    char e_mail[30];
    int xx, yy, wl, cyy, pe;
};//定义结构体变量 

int jiami();
void input(struct student stu[M]);
void output(struct student stu[M]);
void lookfor(struct student stu[M]);
void order(struct student stu[M]);
void delete_s(struct student stu[M]);
void modify(struct student stu[M]);
void xuehao(struct student stu[M]);
void xingming(struct student stu[M]);
void fileread(struct student stu[M]);
void filewrite(struct student stu[M]);
int count;//判断学生的数目 
struct student t;




int jiami()
{
    int s = 2345, m;//s为密码，m为输入的密码 
    int i = 0;//用来判断输入的密码是否正确 
    printf("请输入密码(仅有三次机会呦)：");
    scanf("%d", &m);//第一次输入密码 
    if (m != s)
    {
        printf("密码错误，还有两次机会：");
        scanf("%d", &m);//第二次输入密码 
        if (m != s)
        {
            printf("密码错误，这是最后一次机会了呢：");
            scanf("%d", &m);//第三次输入密码 
            if (m != s)
            {
                printf("看来您不是我的主人，程序要结束了呢！\n");
            }
            else i = 1;
        }
        else i = 1;
    }
    else i = 1;
    return i;
}




int main()
{
    system("color F5");//改变运行框和文字的颜色 
    int choice, sum, i;//choice用来判断输入的命令；sum用来记录输入错误的次数；i用来判断输入的密码是否正确 
    struct student stu[M];
    sum = 0;//初始化sum 
    i = jiami();
    if (i == 1)//判断输入的密码是否正确 
        do
        {
            printf("\t-------------------------------------------------\n");
            printf("\t\t+  学生信息管理系统        +\n");
            printf("\t-------------------------------------------------\n");
            printf("\t\t ***************\n");
            printf("\t\t 1、添加学生信息\n");
            printf("\t\t 2、浏览学生信息\n");
            printf("\t\t 3、查询学生信息\n");
            printf("\t\t 4、修改学生信息\n");
            printf("\t\t 5、删除学生信息\n");
            printf("\t\t 6、排序学生信息\n");
            printf("\t\t 7、读取文件学生\n");
            printf("\t\t 8、保存到文件\n");
            printf("\t\t 9、退出系统\n");
            printf("\t\t ***************\n");
            printf("请输入你的选择\n"); //输出菜单 
            scanf("%d", &choice); //输入选择 
            fflush(stdin);   //清空缓冲区    
            if (choice > 9 || choice <= 0)
            {
                sum++;
                if (sum >= 5)
                {
                    printf("输入错误次数过多,程序将重新开始\n");
                    system("pause");
                    system("cls");   //清屏 
                }
            }
            switch (choice)
            {
            case 1:
                input(stu);
                break;      //添加学生信息  
            case 2:
                output(stu);
                break;//浏览学生信息 
            case 3:
                lookfor(stu);
                break; //寻找学生信息 
            case 4:
                modify(stu);
                break; //修改学生信息 
            case 5:
                delete_s(stu);
                break; //删除学生信息 
            case 6:
                order(stu);
                break; //排序学生信息 
            case 7:
                fileread(stu);
                break; //从文件中读取学生信息 
            case 8:
                filewrite(stu);
                break; //将学生信息写入文件 
            case 9:
                printf("感谢你使用学生信息管理系统,请关掉程序!\n");
                system("pause");
                break;
            default:
                printf("无效的选择!请重新输入!\n");
                break;
            }
        } while (choice != 9);
        printf("the program is over!\n");
        return 0;
}





void input(struct student stu[M])//自定义输入函数
{
    system("cls");//清屏 
    printf("请添加要输入学生的信息\n");
    printf("请输入由11位数字组成的学生的学号\n");
    scanf("%s", stu[count].num);//输入学生学号 
    printf("请输入学生的姓名\n");
    scanf("%s", stu[count].name);//输入学生姓名 
    printf("请输入学生的年龄\n");
    scanf("%d", &stu[count].age);//输入学生姓名 
    printf("请输入学生的性别\n");
    scanf("%s", stu[count].x);//输入学生性别 
    printf("请输入学生的出生年月\n");
    scanf("%s", stu[count].year_month_day);//输入学生生日 
    printf("请输入学生的地址\n");
    scanf("%s", stu[count].address); //输入学生地址 
    printf("请输入学生的电话\n");
    scanf("%d", &stu[count].iphone); //输入学生手机号 
    printf("请输入学生的E-mail\n");
    scanf("%s", stu[count].e_mail);//输入学生的邮箱 
    printf("请依次输入五项不大于100的学生各科成绩\n");
    scanf("%d%d%d%d%d", &stu[count].xx, &stu[count].yy, &stu[count].wl, &stu[count].cyy, &stu[count].pe);//输入学生的各项成绩 
    count++;//计算学生人数 
}





void output(struct student stu[M])//自定义输出函数
{
    int j;
    system("cls");//清屏 
    if (count == 0)//判断目前是否有学生信息 
    {
        printf("当前已存入学生的信息为0个\n");
        return;
    }
    else
    {
        for (j = 0;j < count;j++)
        {
            printf("学号:%s\t\t", stu[j].num);//输出学号 
            printf("姓名:%s\t\t", stu[j].name);//输出姓名 
            printf("年龄:%d\t\t", stu[j].age);//输出年龄 
            printf("性别:%s\t\t", stu[j].x);//输出性别 
            printf("出生年月:%s\t\t", stu[j].year_month_day);//输出生日 
            printf("地址:%s\t\t", stu[j].address);//输出地址 
            printf("电话:%d\t\t", stu[j].iphone);//输出手机号 
            printf("E-mail:%s\t\t", stu[j].e_mail);//输出邮箱 
            printf("数学:%d\t\t英语:%d\t\t物理:%d\t\tC语言:%d\t\t体育:%d\n\n", stu[j].xx, stu[j].yy, stu[j].wl, stu[j].cyy, stu[j].pe);//输出各项成绩 
        }
    }
}



void lookfor(struct student stu[M])//自定义查询函数
{
    int choice;//定义选择 
    system("cls");//清屏 
    if (count == 0)//判断目前是否有学生信息 
    {
        printf("当前已存学生的信息为0个，无法查询!!!\n");
        return;
    }
    else
    {
        printf("请选择你所要查询的方式: 1、学号 2、姓名 3、取消\n");
        scanf("%d", &choice);//输入选项 
        switch (choice)
        {
        case 3:return;break;
        case 2:xingming(stu);break;//按姓名查询 
        case 1:xuehao(stu);break; //按学号查询 
        default:printf("无效的选择!请重新输入!\n");break;
        }
    }
}




void xuehao(struct student stu[M])//自定义学号查询函数
{
    int j, flag = 0;
    int k = 0;//判断是否找到该学生信息 
    char xh[25];
    system("cls");
    printf("请输入你想要查询的学生的学号");
    scanf("%s", xh);//输入学号 
    fflush(stdin);//清空缓冲区 
    for (j = 0;j < count;j++)
    {
        if (strcmp(stu[j].num, xh) == 0)//找到该学号的学生信息 
        {
            printf("学号:%s\t", stu[j].num);
            printf("姓名:%s\t", stu[j].name);
            printf("年龄:%d\t", stu[j].age);
            printf("性别:%s\t", stu[j].x);
            printf("出生年月:%s\t", stu[j].year_month_day);
            printf("地址:%s\t", stu[j].address);
            printf("电话:%d\t", stu[j].iphone);
            printf("E-mail:%s\t", stu[j].e_mail);
            printf("数学:%d\t英语:%d\t物理:%d\tC语言:%d\t体育:%d\n", stu[j].xx, stu[j].yy, stu[j].wl, stu[j].cyy, stu[j].pe);//输出该学生的信息 
            k = 1;
        }
    }
    if (k == 0)//没有找到该学号 
    {
        printf("很抱歉，没有你所需要的学生信息\n");
    }
}



void xingming(struct student stu[M])//自定义姓名查询函数
{
    int n = 0;
    int j, flag = 0;
    char xm[25];
    system("cls");
    printf("请输入你想要查询的学生的姓名");
    scanf("%s", xm);
    fflush(stdin);
    for (j = 0;j < count;j++)
    {
        if (strcmp(stu[j].name, xm) == 0)
        {
            printf("学号:%s\t", stu[j].num);
            printf("姓名:%s\t", stu[j].name);
            printf("年龄:%d\t", stu[j].age);
            printf("性别:%s\t", stu[j].x);
            printf("出生年月:%s\t", stu[j].year_month_day);
            printf("地址:%s\t", stu[j].address);
            printf("电话:%d\t", stu[j].iphone);
            printf("E-mail:%s\t", stu[j].e_mail);
            printf("数学:%d\t英语:%d\t物理:%d\tC语言:%d\t体育:%d\n", stu[j].xx, stu[j].yy, stu[j].wl, stu[j].cyy, stu[j].pe);
            n = 1;
        }
    }
    if (n == 0)
    {
        printf("很抱歉，没有你所需要的学生信息\n");
    }
}



void order(struct student stu[M])//自定义排序函数
{
    int j, k, choice, max;
    system("cls");
    printf("请输入你想要进行排序的方式\n");
    printf("1、数学 2、英语 3、物理 4、C语言 5、体育\n");
    scanf("%d", &choice); //输入选项 
    switch (choice)
    {
    case 1:
        for (j = 0;j < count;j++)
        {
            max = j;
            for (k = j + 1;k < count;k++)
                if (stu[k].xx > stu[max].xx)
                {
                    t = stu[k];
                    stu[k] = stu[max];
                    stu[max] = t;
                }
        };
        break; //按数学成绩排序 
    case 2:
        for (j = 0;j < count;j++)
        {
            max = j;
            for (k = j + 1;k < count;k++)
                if (stu[k].yy > stu[max].yy)
                {
                    t = stu[k];
                    stu[k] = stu[max];
                    stu[max] = t;
                }
        };
        break; //按英语成绩排序 
    case 3:
        for (j = 0;j < count;j++)
        {
            max = j;
            for (k = j + 1;k < count;k++)
                if (stu[k].wl > stu[max].wl)
                {
                    t = stu[k];
                    stu[k] = stu[max];
                    stu[max] = t;
                }
        };
        break; //按物理成绩排序 
    case 4:
        for (j = 0;j < count;j++)
        {
            max = j;
            for (k = j + 1;k < count;k++)
                if (stu[k].cyy > stu[max].cyy)
                {
                    t = stu[k];
                    stu[k] = stu[max];
                    stu[max] = t;
                }
        };
        break; //按C语言成绩排序 
    case 5:
        for (j = 0;j < count;j++)
        {
            max = j;
            for (k = j + 1;k < count;k++)
                if (stu[k].pe > stu[max].pe)
                {
                    t = stu[k];
                    stu[k] = stu[max];
                    stu[max] = t;
                }
        };
        break;   //按体育成绩排序 
    default:
        printf("无效的选择!请重新输入!\n");
        break;
    }
    if (choice >= 1 && choice <= 5)
        printf("排序成功！！！");
}









void delete_s(struct student stu[M])//自定义删除函数(按学号删除)
{
    int j, index = 0, k = count;
    char xh[25];
    system("cls");
    if (count == 0)//判断学生数量是否为0 
    {
        printf("当前已存学生信息为0个,无法删除!!!\n");
        return;
    }
    else
    {
        printf("请输入你想要删除的同学学号\n");
        scanf("%s", xh);//输入删除学生的学号 
        fflush(stdin); //清空缓冲区 
        for (j = 0;j < count;j++)
        {
            if (strcmp(stu[j].num, xh) == 0) //寻找该学生 
            {
                for (j = index;j < count;j++)
                    stu[j] = stu[j + 1];
                count--;
                if (count < k) //判断是否删除成功 
                    printf("你已经删除成功\n");
            }
            index++;
        }
        if (j == count) //判断是否有该学生的信息 
            printf("抱歉!!!没有你所需要删除的学生信息!*_*!\n");
    }
}








void modify(struct student stu[M])//自定义修改函数
{
    int j, flag = 0, course;
    int i = 0;
    char xh[25];
    system("cls");
    if (count == 0) //判断是否有学生信息 
    {
        printf("当前已存学生信息为0个,无法修改!!!\n");
        return;
    }
    else
    {
        printf("请输入你想要修改的同学学号\n");
        scanf("%s", &xh); //输入要修改学生的学号 
        fflush(stdin);
        for (j = 0;j < count;j++)
        {
            if (strcmp(stu[j].num, xh) == 0)
            {
                i = 1;
                printf("你确定要修改学生的信息吗?如果不确定的话,请关掉本程序吧!\n");
                printf("选择课程: 1、数学 2、英语 3、物理 4、C语言 5、体育 6、跳过\n");
                scanf("%d", &course); //选择要修改的一部分学生信息 
                switch (course)
                {
                case 1:printf("请输入你想要修改后的学生成绩\n");scanf("%d", &stu[j].xx);break; //修改数学成绩 
                case 2:printf("请输入你想要修改后的学生成绩\n");scanf("%d", &stu[j].yy);break;//修改英语成绩 
                case 3:printf("请输入你想要修改后的学生成绩\n");scanf("%d", &stu[j].wl);break; //修改物理成绩 
                case 4:printf("请输入你想要修改后的学生成绩\n");scanf("%d", &stu[j].cyy);break; //修改C语言成绩 
                case 5:printf("请输入你想要修改后的学生成绩\n");scanf("%d", &stu[j].pe);break; //修改体育成绩 
                case 6:break;
                default:printf("无效的选择!请重新输入!\n");break;
                }
                printf("选择信息: 1、学号 2、姓名 3、年龄 4、性别 5、出生年月 6、地址 7、电话 8、E-mail 9、跳过\n");
                scanf("%d", &course); //选择要修改的一部分学生信息   
                switch (course)
                {
                case 1:scanf("%s", stu[j].num);break;//修改学号 
                case 2:printf("请输入修改后的信息：");scanf("%s", stu[j].name);break;//修改姓名 
                case 3:printf("请输入修改后的信息：");scanf("%d", &stu[j].age);break;//修改年龄 
                case 4:printf("请输入修改后的信息：");scanf("%s", stu[j].x);break;//修改性别 
                case 5:printf("请输入修改后的信息：");scanf("%s", &stu[j].year_month_day);break;//修改生日 
                case 6:printf("请输入修改后的信息：");scanf("%s", stu[j].address);break;//修改地址 
                case 7:printf("请输入修改后的信息：");scanf("%d", &stu[j].iphone);break;//修改电话 
                case 8:printf("请输入修改后的信息：");scanf("%s", stu[j].e_mail);break;//修改邮箱 
                case 9:break;
                default:printf("无效的选择!请重新输入!\n");break;
                }
            }

        }
    }
    if (i == 0) printf("无该学生信息！！\n");
    return;

}





void filewrite(struct student stu[M])//自定义写入文件函数
{
    int j = 0;
    printf("请选择是否要存入已输入的学生信息:'y'还是'n'???\n");
    scanf("%c", &f); //判断是否写入文件 
    fflush(stdin); //清空缓冲区 
    while (f != 'y' && f != 'n')
    {
        if (f != 'y' && f != 'n')
            printf("输入错误,请重新输入\n");
        printf("以下操作将会覆盖已存储的数据,确定请输入'y'或'n'?\n");
        scanf("%c", &f);
        fflush(stdin);
    }
    if (f == 'y')
    {
        if ((fp = fopen("stu.txt", "w")) == NULL)
        {
            printf("cannot open this file\n");
            exit(0);
        }
        for (j = 0;j < count;j++)
        {
            fwrite(&stu[j], sizeof(struct student), 1, fp); //将学生信息写入文件 
        }
        fclose(fp);
        if (count == 0)//判断学生数目是否为0  
            printf("没有文件，无法保存\n");
        else
            printf("数据存储完毕\n");
        system("pause");
    }
    else
        return;
}





void fileread(struct student stu[M])//自定义读取文件信息函数
{
    int j = 0;
    system("cls");
    printf("请选择是否要读取已输入的学生信息:'y'还是'n'?\n");
    scanf("%c", &f); //判断是否从文件中读取学生信息 
    fflush(stdin);  //清空缓冲区 
    if (f == 'y')
    {
        if ((fp = fopen("stu.txt", "r")) == NULL)
        {
            printf("cannot open this file\n");
            exit(0);
        }
        fread(&stu[j], sizeof(struct student), 1, fp);  //从文件中读取学生信息 
        count = 0;
        count++;
        j++;
        while (fread(&stu[j], sizeof(struct student), 1, fp))
        {
            j++;
            count++;
        }
        fclose(fp);
        printf("数据读取完毕!\n");
        system("pause");
    }
    else
        return;
}

