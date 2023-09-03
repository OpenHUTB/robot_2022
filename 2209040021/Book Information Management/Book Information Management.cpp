#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count=0;//全局变量，定义书籍数 
typedef struct book{//结构体 
    long bianhao;
    char bookname[20];
    char writer[20];
    char press[20];
    char time[20];
    int money;
}boo;
void gongnengqu(){//菜单目录 
    
        printf("欢迎使用图书管理系统\n请按提示选择以下功能\n");
    printf("**********************************\n\n");
    printf("    录入图书信息按1\n");
    printf("    添加图书信息按2\n");
    printf("    查询图书信息按3\n");
    printf("    修改图书信息按4\n");
    printf("    删除图书信息按5\n");
    printf("    按出版社排序图书信息按6\n");
    printf("    浏览所有图书信息按7\n");
    printf("    退出按0\n\n");
    printf("*********************************\n\n");
}
 
void wenjian1(boo books[]){//存储文件的，正常排序 
    FILE *fp;
fp=fopen("D:Demo/tushu.txt","w");
fprintf(fp,"图书编号  书名  作者  出版社  出版时间  价格\n");
for(int i=0;i<count;i++) 
{
    if(books[i].bookname==NULL)
    break;
    fprintf(fp,"%ld  ",books[i].bianhao);
    fprintf(fp,"%s  ",books[i].bookname);
    fprintf(fp,"%s  ",books[i].writer);
    fprintf(fp,"%s  ",books[i].press);
    fprintf(fp,"%s  ",books[i].time);
    fprintf(fp,"%d  ",books[i].money);
    fprintf(fp,"\n");
}
fclose(fp);
}
void wenjian2(boo books[]){//存储文件的，按出版社排序 
    FILE *fp;
fp=fopen("D:Demo/tushu1.txt","w");
fprintf(fp,"图书编号  书名  作者  出版社  出版时间  价格\n");
for(int i=0;i<count;i++) 
{
    if(books[i].bookname==NULL)
    break;
    fprintf(fp,"%ld  ",books[i].bianhao);
    fprintf(fp,"%s  ",books[i].bookname);
    fprintf(fp,"%s  ",books[i].writer);
    fprintf(fp,"%s  ",books[i].press);
    fprintf(fp,"%s  ",books[i].time);
    fprintf(fp,"%d  ",books[i].money);
    fprintf(fp,"\n");
}
fclose(fp);
}
void paixu1(boo books[]);
void luru(boo books[]){//对自己要输入的书籍进行录入，录入只能进行一次，再次进行会进行覆盖 
    for(int i=0;;i++)
    {
        if(i>0)
        {
        printf("如果要停止录入请打0，继续输入请打1:");
        int q;
        scanf("%d",&q);
        if(q==0) break;
    }
    printf("请输入其图书编号:");
    scanf("%ld",&books[i].bianhao); 
        printf("请输入书名:");
    scanf("%s",&books[i].bookname); 
        printf("请输入作者名:");
    scanf("%s",&books[i].writer); 
        printf("请输入其出版社:");
    scanf("%s",&books[i].press); 
        printf("请输入其出版时间:");
    scanf("%s",&books[i].time); 
        printf("请输入其价格:");
    scanf("%d",&books[i].money); 
    count++; 
    system("cls");//清屏 
}
paixu1(books);
wenjian1(books);
}
void paixu1(boo books[]) {
    char a[20];
    int t;
    long x;
    if(count>1){
    for(int i=0;i<count-1;i++){
        for(int j=i+1;j<count;j++)
        if(books[i].bianhao>books[j].bianhao){
                            t=books[i].money;books[i].money=books[j].money;books[j].money=t;
                x=books[i].bianhao;books[i].bianhao=books[j].bianhao;books[j].bianhao=x;
                strcpy(a,books[i].bookname);strcpy(books[i].bookname,books[j].bookname);strcpy(books[j].bookname,a);
                strcpy(a,books[i].writer);strcpy(books[i].writer,books[j].writer);strcpy(books[j].writer,a);
                strcpy(a,books[i].press);strcpy(books[i].press,books[j].press);strcpy(books[j].press,a);
                strcpy(a,books[i].time);strcpy(books[i].time,books[j].time);strcpy(books[j].time,a);
        }
    }
}
}
void tianjia(boo books[]){//添加 ，对书籍进行添加 
    printf("请输入其图书编号:");
    scanf("%ld",&books[count].bianhao); 
        printf("请输入书名:");
    scanf("%s",&books[count].bookname); 
        printf("请输入作者名:");
    scanf("%s",&books[count].writer); 
        printf("请输入其出版社:");
    scanf("%s",&books[count].press); 
        printf("请输入其出版时间:");
    scanf("%s",&books[count].time); 
        printf("请输入其价格:");
    scanf("%d",&books[count].money); 
    printf("添加成功\n");
    system("pause"); 
    paixu1(books);
    FILE *fp;
    fp=fopen("D:Demo/tushu.txt","a");
    fprintf(fp,"%ld  ",books[count].bianhao);
    fprintf(fp,"%s  ",books[count].bookname);
    fprintf(fp,"%s  ",books[count].writer);
    fprintf(fp,"%s  ",books[count].press);
    fprintf(fp,"%s  ",books[count].time);
    fprintf(fp,"%d  ",books[count].money);
    fprintf(fp,"\n");
    fclose(fp);
    count++;
}
void chaxun(boo books[]){//对于你所要的书籍进行查询 
    printf("请输入你要查询的书名:");
    char abc[20];
    int flag=0;
    scanf("%s",&abc); 
    for(int i=0;i<101;i++)
    {
        char a;
        if(books[i].money==NULL)
        break;
        if(strcmp(books[i].bookname,abc)==0)//比较字符串 
        {
            flag=1;
            printf("图书编号为:%ld\n",books[i].bianhao);
            printf("书名为:%s\n",books[i].bookname);
            printf("作者名为:%s\n",books[i].writer);
            printf("出版社为:%s\n",books[i].press);
            printf("出版时间为:%s\n",books[i].time);
            printf("价格为:%d\n",books[i].money);
            system("pause");
            break;
        }
    }
    if(flag==0)
    printf("【书籍为找到或不存在】\n");
    system("pause"); 
}
void xiugai(boo books[]){//对于你需要的书籍进行修改 
        printf("请输入你要查询的书名：");
    char abc[20];
    scanf("%s",&abc); 
    for(int i=0;i<101;i++)
    {
        char a;
        if(books[i].money==NULL)
        break;
        if(strcmp(books[i].bookname,abc)==0)
        {
            printf("原图书编号为:%ld\n",books[i].bianhao);
            printf("原书名为%s\n",books[i].bookname);
            printf("请输入新书名:\n"); 
            scanf("%s",&books[i].bookname);
            printf("原作者名为:%s\n",books[i].writer);
            printf("请输入新作者:\n"); 
            scanf("%s",&books[i].writer);
            printf("原出版社为:%s\n",books[i].press);
            printf("请输入新出版社:\n"); 
            scanf("%s",&books[i].press);
            printf("原出版时间为:%s\n",books[i].time);
            printf("请输入新出版时间\n"); 
            scanf("%s",&books[i].time);
            printf("原价格为:%d\n",books[i].money);
            printf("请输入新价格:\n");
            scanf("%d",&books[i].money); 
            system("pause");
            break;
        }
    }
wenjian1(books);    
}
void shanchu(boo books[]){//删除书籍 
    printf("请输入你要删除的书号:\n");
    int x,i,flag=1;
    scanf("%ld",&x); 
    for(;i<count;i++){
     if(x==books[i].bianhao&i<count-1){
         printf("【%s】书籍已删除\n",books[i].bookname);
         for(int z=i;z<count;z++){
         books[z].bianhao=books[z+1].bianhao;
         strcpy(books[z].bookname,books[z+1].bookname);
         strcpy(books[z].writer,books[z+1].writer);
         strcpy(books[z].press,books[z+1].press);
         strcpy(books[z].time,books[z+1].time);
         books[z].money=books[z+1].money;
         count--;}    flag=0;
        system("pause");break;}
     else if(x==books[i].bianhao&i==count-1){
          printf("【%s】书籍已删除\n",books[i].bookname);flag=0;    count--;    
    system("pause");break;
          }
     }
if(flag==1)
{
printf("书籍未找到\n");
system("pause");} 
paixu1(books);
wenjian1(books);
}
 
void paixu(boo books[]){//对出版社进行排序 
    char a[20];
    int t;
    long x;
    for(int i=0;i<count-1;i++){
        for(int j=i+1;j<count;j++){
            if((strcmp(books[i].press,books[j].press))>0)
            {
                t=books[i].money;books[i].money=books[j].money;books[j].money=t;
                x=books[i].bianhao;books[i].bianhao=books[j].bianhao;books[j].bianhao=x;
                strcpy(a,books[i].bookname);strcpy(books[i].bookname,books[j].bookname);strcpy(books[j].bookname,a);
                strcpy(a,books[i].writer);strcpy(books[i].writer,books[j].writer);strcpy(books[j].writer,a);
                strcpy(a,books[i].press);strcpy(books[i].press,books[j].press);strcpy(books[j].press,a);
                strcpy(a,books[i].time);strcpy(books[i].time,books[j].time);strcpy(books[j].time,a);
            }
        }
    }
    printf("已排序完成\n");
    printf("图书编号  书名  作者  出版社  出版时间  价格\n");
    for(int i=0;i<count;i++)
    {
        printf("%ld  ",books[i].bianhao);
        printf("%s  ",books[i].bookname);
        printf("%s  ",books[i].writer);
        printf("%s  ",books[i].press);
        printf("%s  ",books[i].time);
        printf("%d  \n",books[i].money);
    }
    system("pause"); 
    wenjian2(books);
    paixu1(books);
    wenjian1(books);
}
void read(boo books[])//将你所有的书籍进行浏览 
{
    FILE *fp;
    int i;
    if ((fp = fopen("D:Demo/tushu.txt","r")) == NULL) 
    { 
        printf("Failure to open 1.txt!\n");
        exit(0);
    }
char b[1000];
        fscanf(fp,"%[^n]",b);//输出所有文件的东西 
        printf("%s",b);    
    system("pause");
    fclose(fp);
    
 }
int main(){
    boo books[100];
    for(;;){
    gongnengqu();
    int key=0;
    scanf("%d",&key);
    switch(key){
        case 1:printf("【录入】\n");luru(books);break;
        case 2:printf("【添加】\n");tianjia(books);break;
        case 3:printf("【查询】\n");chaxun(books);break;
        case 4:printf("【修改】\n");xiugai(books);break;
        case 5:printf("【删除】\n");shanchu(books);break;
        case 6:printf("【排序】\n");paixu(books);break;
        case 7:printf("【浏览】\n");read(books);break;
        case 0:printf("【退出】\n");
                printf("退出成功!感谢您的使用！\n");
                system("pause");//暂停，避免输出过快 
                   exit(0);
                break;
        default:
                printf("【error】\n");
    } 
    system("cls");
    }
    return 0;
}
