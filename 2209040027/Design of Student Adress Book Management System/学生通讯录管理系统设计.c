#include <stdio.h>   /*头文件*/
#include <stdlib.h> //包含最常用的系统函数
#include <string.h> //关于字符数组的函数定义的头文件
#include <conio.h>

//定义结构体
struct tongxunlu   /*定义通讯录结构体变量*/
{
    char xingming[20];    /*定义输入名字的数组*/
    char dianhua[20]; /*定义输入电话号码的数组*/
    char dizhi[40]; /*定义输入地址的数组*/
} txl[100]; //默认100个数据
int n=0;//记录数据联系人数量
FILE *fp;   /*定义文件*/
//程序用到的所有函数
void zhucaidan();    /*主菜单函数*/
void zengjia();   /*增加联系人函数*/
void readfile();  /*文件中读入函数*/
void writefile();  /*文件中写入函数*/
void xiugai();    /*修改联系人函数*/
void xiugai_xingming();  /*姓名修改*/
void xiugai_dianhua();  /*电话号码修改*/
void chazhao();      /*查找联系人函数*/
void chazhao_xingming();  /*按姓名查找*/
void chazhao_dianhua();  /*按号码查找*/
void shanchu();    /*删除联系人函数*/
void shanchu_quanbu();  /*全部删除*/
void shanchu_dange();  /*单个删除*/
void xianshi();         /*号码显示*/
//程序主函数 模块六
int main()         /*主函数main*/
{
    readfile();    /*读入文件*/
    while(1)      /* 循环（永远进行）*/
    {
        zhucaidan();     /*调用主菜单函数*/
    }
    return 0;
}
//读取文件函数部分开始 模块七
void readfile()
{
    if((fp=fopen("txl.txt","r"))==NULL)  /*以只读方式打开判定文件是否为空*/
    {
        printf("\n\t\t\t    通讯录文件不存在");    /*判断结论*/
        if ((fp=fopen("txl.txt","w"))==NULL) /*只写方式判断*/
        {
            printf("\n\t\t建立失败");      /*为空结论*/
            exit(0);                        /*退出*/
        }
        else                               /*不为空则执行else*/
        {
            printf("\n\t-----------------欢迎使用通讯录管理系统------------------");
            printf("\n\t                    通讯录文件已建立                     ");
            printf("\n\t                   按任意键进入主菜单                    ");
            printf("\n\t---------------------------------------------------------");
            getch();
            return ;
        }
        exit(0);
    }
    fseek(fp,0,2); /*文件位置指针移动到文件末尾*/
    if (ftell(fp)>0) /*文件不为空*/
    {
        rewind(fp); /*文件位置指针移动到文件开始位置*/
        for (n=0; !feof(fp) && fread(&txl[n],sizeof(struct tongxunlu),1,fp); n++);
        printf("\n\t----------  欢迎使用通讯录管理系统  ----------------");
        printf("\n\t                   文件导入成功                          ");
        printf("\n\t                 按任意键返回主菜单                      ");
        printf("\n\t---------------------------------------------------------");
        getch();
        return;
    }
    printf("\n\t------------  欢迎使用通讯录管理系统  --------------");
    printf("\n\t                     文件导入成功                        ");
    printf("\n\t                通讯录文件中无任何纪录                   ");
    printf("\n\t                  按任意键返回主菜单                     ");
    printf("\n\t---------------------------------------------------------");
    getch();
    return;
}
//读取文件函数结束

//文件主菜单函数开始 模块六
void zhucaidan()
{
    char c;
    system("cls");
    printf("\n\t\t|-------  欢迎您使用通讯录管理系统 -----|");
    printf("\n\t\t|         1-添加联系人    2-查询和显示联系人     |");
    printf("\n\t\t|         3-删除联系人    4-修改联系人           |");
    printf("\n\t\t|         5-保存退出      0-不保存退出           |");
    printf("\n\t\t|------------------------------------------------|");
    printf("\n\t\t请选择您所所要的服务：");
    c=getch();
    switch (c) /*对于上边的选择项目*/
    {
    case '1':
        zengjia();
        break;
    case '2':
        chazhao();
        break;
    case '3':
        shanchu();
        break;
    case '4':
        xiugai();
        break;
    case '5':
        writefile();
        break;
    case '0':
        exit(0);
    default:
        zhucaidan(); /*如果没有则返回主菜单等待输入*/
    }
}
//文件主菜单函数结束

//添加新联系人函数开始 模块一
void zengjia()
{
    printf("\n\t\t------------------ 请输入联系人信息 --------------------\n");
    printf("\n\t\t输入联系人姓名:");
    scanf("%s",txl[n].xingming);    /*键盘输入*/
    printf("\n\t\t输入联系人电话号码:");
    scanf("%s",txl[n].dianhua);
    printf("\n\t\t输入联系人地址:");
    scanf("%s",txl[n].dizhi);
    n++;                            /*统计个数*/
    printf("\n\t\t是否继续添加联系人?(Y/N):"); /*是否继续输入联系人.*/
    if (getch()=='y')
        zengjia();
    return;
}
//添加新联系人结束
//写入文件函数开始  模块七
void writefile()     /*联系人写入文件*/
{
    int i;
    if ((fp=fopen("txl.txt","w"))==NULL)
    {
        printf("\n\t\t文件打开失败");
    }
    for (i=0; i<n; i++)
    {
        if (fwrite(&txl[i],sizeof(struct tongxunlu),1,fp)!=1)
        {
            printf("\n\t\t写入文件错误!\n");
        }
    }
    fclose(fp); /*关闭文件*/
    printf("\n\t------------------------------------------------------"); /*输出提示信息*/
    printf("\n\t\t通讯录文件已保存");
    printf("\n\t\t谢谢使用，欢迎再次使用!\n");
    printf("如果对本软件有疑问,请给我们提出您的问题,我们将为您解答.\n");
    printf("我们的软件有不足之处,请与我们反映，我们将努力改正!");
    printf("\n\t\t按任意键退出程序\n\t\t");      /*输出完毕*/
    exit(0);
    printf("\n\t------------------------------------------------------");
}
//写入文件函数结束
///查询联系人函数开始 模块四----------------------------------------------------
void chazhao()
{
    char c;
    system("cls");
    printf("\n\t\t------------------- 显示和查询联系人 ------------------");
    printf("\n\t\t|        1-逐个显示所有          2-按姓名查询         |");
    printf("\n\t\t|        3-按电话查询            4-返回主菜单         |");
    printf("\n\t\t|------------------------------------------------------");
    printf("\n\t\t请选择您所所要的服务：");
    c=getch();
    switch (c)
    {
    case '1':
        xianshi();
        break;   /*显示所有号码*/
    case '2':
        chazhao_xingming();
        break;  /*调用按姓名查询函数*/
    case '3':
        chazhao_dianhua();
        break;  /*调用按号码查询函数*/
    case '4':
        zhucaidan();
        break;       /*主菜单*/
    }
}
void xianshi()//显示所有联系人函数
{
    int i;
    system("cls");//清楚屏幕
    if(n!=0)
    {
        printf("\n\t\t----------欢迎您查询通讯录所有联系人信息-------------");
        for (i=0; i<n; i++)   /*依次序显示*/
        {
            printf("\n\t\t姓名： %s",txl[i].xingming);
            printf("\n\t\t电话： %s",txl[i].dianhua);
            printf("\n\t\t地址： %s",txl[i].dizhi);
            printf("\n\t\t--------------------------------------------------");
            if (i+1<n)
            {
                printf("\n\t\t-----------------------");
                system("pause");//返回错误信息
            }
        }
        printf("\n\t\t---------------------------------------------");
    }
    else                                  /*无联系人*/
        printf("\n\t\t通讯录中无任何纪录");
    printf("\n\t\t按任意键返回主菜单：");
    getch();
    return;
}
//按号码查询函数
void chazhao_dianhua()
{
    int mark=0;
    int i;
    char phone[15];
    printf("\n\t\t------------------- 按电话查找 -------------------------");
    printf("\n\t\t请输入电话号码:");
    scanf("%s",phone);
    for(i=0; i<n; i++)
    {
        if (strcmp(txl[i].dianhua,phone)==0)//对比查找函数
        {
            printf("\n\t\t------------ 以下是您查找的学生信息 ------------");
            printf("\n\t\t姓名： %s",txl[i].xingming);
            printf("\n\t\t电话： %s",txl[i].dianhua);
            printf("\n\t\t地址： %s",txl[i].dizhi);
            printf("\n\t\t------------------------------------------------");
            printf("\n\t\t按任意键返回主菜单：");
            mark++;
            getch();
            return;
        }
    }
    if (mark==0)
    {
        printf("\n\t\t没有找到联系人的信息");
        printf("\n\t\t按任意键返回主菜单");
        getch();
        return;
    }
}
void chazhao_xingming()//按姓名查询
{
    int mark=0;
    int i;
    char name[20];
    printf("\n\t\t----------------按姓名查找 --------------------");
    printf("\n\t\t请输入您要查找的姓名:");
    scanf("%s",name);
    for(i=0; i<n; i++)
    {
        if (strcmp(txl[i].xingming,name)==0)
        {
            printf("\n\t\t------------ 以下是您查找的联系人信息 ---------------");
            printf("\n\t\t姓名： %s",txl[i].xingming);
            printf("\n\t\t电话： %s",txl[i].dianhua);
            printf("\n\t\t地址： %s",txl[i].dizhi);
            printf("\n\t\t---------------------------------------------------");
            mark++;
            getch();
            return;
        }
    }
    if (mark==0)
    {
        printf("\n\t\t没有找到联系人的信息");
        printf("\n\t\t按任意键返回主菜单");
        getch();
        return;
    }
}

////查询联系人函数结束-----------------------------------------------------

////删除联系人函数部分开始-------------------------------------------------
void shanchu()
{
    char c;
    if(n==0)     /*如果通讯录中没有一个记录输出以下部分*/
    {
        printf("\n\t\t对不起，文件中无任何纪录");
        printf("\n\t\t按任意键返回主菜单");
        getch();
        return;
    }
    system("cls");      /*清屏*/
    printf("\n\t\t-----------------  删除菜单 ----------------------");
    printf("\n\t\t|           1-删除所有 2-删除单个                |");
    printf("\n\t\t|                3-返回主菜单                    |");
    printf("\n\t\t|-------------------------------------------------");
    printf("\n\t\t请选择您所所要的服务：");
    c=getch();     /*输入的赋予choice*/
    switch (c)
    {
    case '1':
        shanchu_quanbu();
        break;
    case '2':
        shanchu_dange();
        break;
    case '3':
        zhucaidan();
        break;
    default:
        zhucaidan();
        break;
    }
}
void shanchu_quanbu()//删除所有联系人
{
    printf("\n\t\t确认删除?(y/n)");
    if (getch()=='y')
    {
        fclose(fp);
        if ((fp=fopen("txl.txt","w"))==NULL)   /*文件空输出*/
        {
            printf("\n\t\t不能打开文件，删除失败");
            readfile();
        }
        n=0;
        printf("\n\t\t纪录已删除，按任意键返回主菜单");
        getch();
        return;
    }
    else
        return;
}
void shanchu_xingming()//按姓名删除联系人
{
    int i,m,mark=0,a=0;
    char name[20];
    printf("\n\t\t请输入要删除联系人姓名：");
    scanf("%s",name);    /*键盘输入姓名*/
    for (i=a; i<n; i++)
    {
        if (strcmp(txl[i].xingming,name) == 0) //对比字符串查找到要删除的联系人
        {
            printf("\n\t\t以下是您要删除的联系人纪录：");
            printf("\n\t\t--------------------------------");
            printf("\n\t\t姓名： %s",txl[i].xingming);
            printf("\n\t\t电话： %s",txl[i].dianhua);
            printf("\n\t\t地址： %s",txl[i].dizhi);
            printf("\n\t\t--------------------------------");
            printf("\n\t\t是否删除?(y/n)");
            if (getch()=='y') // 实现删除功能
            {
                for (m=i; m<n-1; m++)
                    txl[m]=txl[m+1];    /*将通讯录的想前移*/
                n--;
                mark++;
                printf("\n\t\t删除成功");
                printf("\n\t\t是否继续删除?(y/n)");
                if (getch()=='y')
                    shanchu_xingming();   /*继续调用删除函数*/
                return;
            }
            else
                return;
        }
        continue;
    }
    if (mark==0)
    {
        printf("\n\t\t没有该联系人的纪录");
        printf("\n\t\t是否继续删除?(y/n)");
        if (getch()=='y')
            shanchu_xingming();
        return;
    }
}
void shanchu_dianhua()//按电话号码删除联系人
{
    int i,m,mark=0;    /*变量定义*/
    char phone[20];
    printf("\n\t\t请输入要删除联系人电话号码：");
    scanf("%s",phone);
    if(n==0)
    {
        printf("\n\t\t对不起，文件中无任何纪录");
        printf("\n\t\t按任意键返回主菜单");
        getch();
        return;
    }
    for (i=0; i<n; i++)
    {
        if (strcmp(txl[i].dianhua,phone)==0)
        {
            printf("\n\t\t以下是您要删除的联系人纪录：");
            printf("\n\t\t姓名： %s",txl[i].xingming);
            printf("\n\t\t电话： %s",txl[i].dianhua);
            printf("\n\t\t地址： %s",txl[i].dizhi);
            printf("\n\t\t是否删除?(y/n)");
            if (getch()=='y')
            {
                for (m=i; m<n-1; m++) //递推替换实现删除
                    txl[m]=txl[m+1];
                n--;
                mark++; //记录删除次数
                printf("\n\t\t删除成功");
                printf("\n\t\t是否继续删除?(y/n)");
                if (getch()=='y')
                    shanchu_dianhua();
                return;
            }
            else
                return;
        }
        continue;

    }
    if (mark==0)
    {
        printf("\n\t\t没有该联系人的纪录");
        printf("\n\t\t是否继续删除?(y/n)");
        if (getch()=='y')
            return ;
    }
}
void shanchu_dange()//删除单个联系人
{
    char c;
    printf("\n\t----------------------------------------------------------");
    printf("\n\t\t   1-按姓名删除    2-按电话删除");
    printf("\n\t\t请选择您所所要的服务：");
    printf("\n\t----------------------------------------------------------");
    c=getch();
    switch (c)
    {
    case '1':
        shanchu_xingming();
        break;
    case '2':
        shanchu_dianhua();
        break;
    }
}
///删除函数部分结束--------------------------------------------------------

///修改联系人函数开始--------------------------------------------------
void xiugai()     /*修改函数*/
{
    char c;
    if(n==0)
    {
        printf("\n\t\t对不起，文件中无任何纪录");
        printf("\n\t\t按任意键返回主菜单");
        getch();
        return;
    }
    system("cls");
    printf("\n\t\t-----------------修改联系人菜单-----------------------");
    printf("\n\t\t|          1-按姓名修改    2-按电话修改              |");
    printf("\n\t\t|              任意键-按返回主菜单                   |");
    printf("\n\t\t------------------------------------------------------");
    c=getch();
    switch(c)
    {
    case '1':
        xiugai_xingming();
        break;
    case '2':
        xiugai_dianhua();
        break;
    default:
        zhucaidan();
        break;
    }
}
void xiugai_xingming()
{
    char c;
    int i,mark=0;
    char name[20];
    printf("\n\t\t请输入要修改的联系人姓名：");
    scanf("%s",name);
    if(n==0)
    {
        printf("\n\t\t文件中无任何联系人");
        printf("\n\t\t按任意键返回主菜单");
        getch();
        mark++;
        return;
    }
    for(i=0; i<n; i++)
    {
        if(strcmp(txl[i].xingming,name)==0)
        {
            printf("\n\t\t以下是您要修改的联系人信息");
            printf("\n\t\t姓名: %s",txl[i].xingming);
            printf("\n\t\t电话: %s",txl[i].dianhua);
            printf("\n\t\t地址: %s",txl[i].dizhi);
            printf("\n\t\t是否修改(y/n)");
            if(getch()=='y')
            {
                printf("\n\t------------请选择修改信息---------------");
                printf("\n\t         1-修改姓名     2-修改电话       ");
                printf("\n\t                3-修改地址               ");
                printf("\n\t-----------------------------------------");
                printf("\n\t请选择您所所要的服务：");
                scanf("%s",&c);
                switch(c)
                {
                case '1':
                    printf("\n\t请输入新姓名：");
                    scanf("%s",txl[i].xingming);
                    break;
                case'2':
                    printf("\n\t请输入新电话：");
                    scanf("%s",txl[i].dianhua);
                    break;
                case'3':
                    printf("\n\t请输入新地址: ");
                    scanf("%s",txl[i].dizhi);
                    break;
                }
            }
        }
    }
    if(mark==0)
    {
        printf("\n\t\t没有找到联系人信息");
        printf("\n\t是否继续修改？(Y/N):");
        if(getch()=='y')
            xiugai_xingming();
        return;
    }
}

void xiugai_dianhua()
{
    char c,phone[15];
    int i,mark=0;
    printf("\n\t\t请输入要修改联系人的号码：");
    scanf("%s",phone);
    if(n==0)
    {
        printf("\n\t\t文件中无任何联系人");
        printf("\n\t\t按任意键返回主菜单");
        getch();
        mark++;
        return;
    }
    for(i=0; i<n; i++)
    {
        if(strcmp(txl[i].dianhua,phone)==0)
        {
            printf("\n\t\t以下是您要修改的联系人信息");
            printf("\n\t\t姓名: %s",txl[i].xingming);
            printf("\n\t\t电话: %s",txl[i].dianhua);
            printf("\n\t\t地址: %s",txl[i].dizhi);
            printf("\n\t\t是否修改(y/n)");
            if(getch()=='y')
            {
                printf("\n\t------------请选择修改信息---------------");
                printf("\n\t       1-修改姓名     2-修改电话         ");
                printf("\n\t               3-修改地址                ");
                printf("\n\t-----------------------------------------");
                printf("\n\t请选择您所所要的服务：");
                scanf("%s",&c);
                switch(c)
                {
                case'1':
                    printf("\n\t请输入新姓名： ");
                    scanf("%s",txl[i].xingming);
                    break;
                case'2':
                    printf("\n\t请输入新电话： ");
                    scanf("%s",txl[i].dianhua);
                    break;
                case'3':
                    printf("\n\t请输入新地址: ");
                    scanf("%s",txl[i].dizhi);
                    break;
                }
            }
        }
    }
    if(mark==0)
    {
        printf("\n\t没有该联系人信息");
        printf("\n\t是否继续修改？(Y/N):");
        if(getch()=='y')
            xiugai_dianhua();
        return;
    }
}
