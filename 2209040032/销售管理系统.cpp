#include<stdio.h>  //ͷ�ļ�
#include<string.h> //ͷ�ļ�
#include<stdlib.h> //ͷ�ļ�
#define M 100      //��������
#define N 100      //�˿���Ŀ
struct goods       //����������Ϣ��ʽ
{
    int  number;   //��Ʒ���
    char name[20]; //��Ʒ����
    int  price1;   //���ۣ�������
    int  price2;   //�ۼ�
    int  amount;   //����
};
struct orderlist           //������ʽ
{
    struct goods L[M];
};
struct customer            //�ͻ���Ϣ���ݺ͸�ʽ
{
    char name[20];         //����
    char password[6];      //��������
    int count;             //������
};
struct customer khl[N];    //���пͻ���Ϣ
struct goods base[M];      //�����Ϣ
struct orderlist odl[10*N];//������
struct goods lackl[M];     //ȱ����
struct goods suml[M+1];    //���۱���
int PP=0;                  //�������
int QQ=0;                   //�ͻ����
int goodssum=0;              //��������
 
//������
int main()                    //��������ʼ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
    int SysUseWay();        //ϵͳʹ��˵����������
    int chushihua();       //ϵͳ��ʼ����������
    int welcome();        //��ӭ���溯������
    int kh();            //�ͻ���������
    int buyer();        //�ɹ�����������
    int manager();     //��˾����������
    int goodbye();    //���ͺ�������
    int n,m=9;       //��������
    //SysUseWay();    //ϵͳʹ��˵����
    chushihua();   //ϵͳ��ʼ��
    while(m==9)   //ѭ�������
    {
    welcome();  //��ӭ����
    scanf("%d",&n);
    switch(n) //��������
    {
    case 0 : ;break;
    case 1 : kh(); break;       //�ͻ�֮��
    case 2 : buyer(); break;    //�ɹ�֮��
    case 3 : manager(); break;  //����֮��
    default : printf("�������!���˳��ش�������");
    }
    if(n==0)
        break;
    printf("              ���������������밴 9  �˳��밴0\n");
    scanf("%d",&m);
    }
    goodbye();                  //���ͽ���
    return 0;
}                               //����������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 
//��ӭ���溯������
int welcome()
{
 
    printf("................................................................................\n");
    printf("\n");
    printf("                      ~~~~~~~~��ӭʹ����Ʒ����ϵͳ~~~~~~~~\n");
    printf("                              ��˾�ͻ��밴       1\n");
    printf("                              �ɹ���Ա�밴       2\n");
    printf("                              ��˾�����밴       3\n");
    printf("                              �˳��������밴     0\n");
    return 0;
}
 
//��ʼ������
int chushihua()
{
    int i=0,j=0;
    for(i=0;i<M;i++)
    {
     suml[i].number=lackl[i].number=base[i].number=-1;
     base[i].amount=0;
     base[i].price1=base[i].price2=0;
     lackl[i].amount=0;
     suml[i].price1=0;
     suml[i].amount=0;
    }
    suml[M].price1=0;
    for(i=0;i<N;i++)
    khl[i].count=-1;
    for(i=0;i<10*N;i++)
    {
        for(j=0;j<M;j++)
        {
        odl[i].L[j].number=j;
        odl[i].L[j].amount=0;
        odl[i].L[j].price1=base[j].price1;
        odl[i].L[j].price2=base[j].price2;
        }
    }
 
    return 0;
}
 
//���ͽ��溯������
int goodbye()
{
    printf("                 ~~~~��л��ʹ����Ʒ����ϵͳ~~~~\n");
    return 0;
}
//�ɹ�����
int buyer()
{
    int welcomebuyer();     //��ӭ����
    int buildbaser();       //�ֿ⽨��
    int solvelack();        //��ѯȱ�����
    int chackbase();        //��ѯ�ֿ����
    int n;
    int m=9;
    while(m==9)             //ѭ�������
    {
    welcomebuyer();             //��ӭ��ӭ
    scanf("%d",&n);             //��������
    switch(n)
    {
    case 0 : ;break;            //�˳�
    case 1: solvelack();break;  //��ȱ��
    case 2: buildbaser();break; //����ֿ�
    case 3: chackbase();break;  //���ֿ�
    default :printf("�������!\n");
    }
    if(n==0)
        break;
    printf("              �����ɹ��밴 9  �����밴0\n");
    scanf("%d",&m);
    }
    return 0;
}
 
int welcomebuyer()
{
    printf("................................................................................\n");
    printf("\n");
    printf("                      ~~~~~~~~��ӭ�����ɹ�֮��~~~~~~~~\n");
    printf("                              ����ȱ��                �밴   1\n");
    printf("                              ����                    �밴   2\n");
    printf("                              ��ѯ��ǰ������        �밴   3\n");
    printf("                              �˳��ɹ�                �밴   0\n");
return 0;
}
 
//�ɹ�����--��������
int buildbaser()
{
    int i=0;
    printf("            ����ֹͣ����,���ڻ������������� 0\n\n");
    for(i=0;i<M;i++)
    {
        printf("\n��������:");
        scanf("%s",base[i].name);
        base[i].number=i;
        printf("\n��������:");
        scanf("%d",&base[i].amount);
        if(base[i].amount<=0){
            base[i].amount=0;
            break;
        }
        goodssum+=base[i].amount;
        printf("\n�������:");
        scanf("%d",&base[i].price1);
        printf("\n�����ۼ�:");
        scanf("%d",&base[i].price2);
        }
    return 0;
}
 
//�ɹ�����---��ѯ��ǰ�������
int chackbase()
{
    int i=0;
    printf("................................................................................\n");
    if(goodssum==0)
    {
        printf("           �ֿ�û��!!!         ��ɹ����ż�ʱ����!!!\n");
        return 0;
    }
    for(i=0;i<M;i++)
    {
        if(base[i].amount>0){
              printf("................................................................................\n");
              printf("������  ��������             ��������          ����       �ۼ�\n");
              printf(" %3d      %-20s %6d          %6d     %6d \n",base[i].number,base[i].name,base[i].amount,base[i].price1,base[i].price2);
              printf("................................................................................\n");
        }
        else
            continue;
    }
    printf("................................................................................\n");
    return 0;
}
 
//�ɹ�����--����ȱ������
int solvelack()
{
    int i=0,k=0;
    int printlack();           //�ɹ�����--����ȱ������--�鿴��������
    int supplement();          //�ɹ�����--����ȱ������--�����������
    printlack();               //�鿴�Ƿ�ȱ��
    printf("           �����Ҫ�������밴1  �� �����밴0   \n");
    scanf("%d",&k);
    switch(k)
    {
    case 1:supplement();break;
    case 0:;break;
    default :printf("�������!\n");
    }
    return 0;
}
int printlack()                //�ɹ�����--����ȱ������--�鿴��������
{
    int i=0,count=0;
    if(goodssum==0){
          printf("                  !!!�ֿ�û��!!!��ɹ���Ա��ʱ����!!!\n");
          return 0;
          }
    printf("................................................................................\n");
    for(i=0;i<M;i++)
    {
        if(lackl[i].amount==0){
            count++;
            continue;
         }
        else{
         printf("................................................................................\n");
         printf("������  ��������             ȱ������\n");
         printf(" %3d      %-20s %6d          \n",lackl[i].number,base[i].name,lackl[i].amount);
        }
    }
    printf("................................................................................\n");
    if(count==M)
        printf("              ~~~��ȱ~~~�������~~~\n");
    else
        printf("                    ȱ!   ȱ!   ȱ!\n");
return 0;
}
 
//�ɹ�����--����ȱ������--�����������
int supplement()
{
    int i=0,j=1;
    int printlack();
    printlack();
    printf("     ����ֹͣ���������ڻ�������������0\n");
    while(j>0)
    {
        printf("��Ʒ���\n");
        scanf("%d",&i);
        while(i>=M){
        printf("�˻��ﲻ���ڣ�����������\n");
        scanf("%d",&i);}
        base[i].number=i;
        printf("��Ʒ����:\n");
        scanf("%s",base[i].name);
        printf("��������:\n");
        scanf("%d",&j);
        if(j>0){
           base[i].amount+=j;
           goodssum+=j;
        }
        else
            break;
        printf("\n�������:");
        scanf("%d",&base[i].price1);
        printf("\n�����ۼ�:");
        scanf("%d",&base[i].price2);
    }
    return 0;
}
 
//�ͻ�����
int kh()
{
int login();                      //�ͻ�����--��½��������
int registe();                    //�ͻ�����--ע�ắ������
int welcomekh();                  //�ͻ�����--��ӭ��������
int searchkh(int falg);           //�ͻ�����--��ѯ��������ĺ�������
int order(int falg);              //�ͻ�����--������������
int i,k=0,flag=0;
int n=9,m=9;
welcomekh();                     //��ӭ��ӭ
while(m==9)                      //��½��ע��ѭ������·
{
printf("        ��½�밴1��          ע���밴2,          �����밴 0\n");
scanf("%d",&i);
switch(i)
{
case 0 : ;break;
case 1 : flag=login(); break;
case 2 : registe(); break;
default :printf("�������!\n");
}
if(i==0)
        break;
printf("           ��½��ע���밴 9  �����밴0\n");
scanf("%d",&m);
}
 
while(n==9)                      //��������ѯѭ������·
{
printf("         ��ѯ�밴 1,   �����밴 2,      �����밴 0\n");
scanf("%d",&i);
switch(i)
{
case 0 : ;break;
case 1 : searchkh(flag); break;
case 2 : order(flag); break;
default :printf("�������!\n");
}
if(i==0)
    break;
printf("           ������ѯ�򶩹��밴 9  �����밴0\n");
scanf("%d",&n);
}
return 0;
}
 
 
int welcomekh()                    //�ͻ�����---��ӭ��������
{
 
    printf("..............................................................................\n");
    printf("  ~~~~~~~~��ӭ�����ͻ�֮��~~~~~~~~\n");
    printf("..............................................................................\n");
    return 0;
}
 
//�ͻ�����---��½��������
int login()
{
int n,count=0;
char password[6];
printf("-------------------�����������-----------------------\n");
scanf("%d",&n);
printf("-------------------��������λ����-----------------------\n");
scanf("%s",password);
while(strcmp(password,khl[n].password))
{
    printf("~~~~~~~~~~~~~~~������������λ����~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n");
    printf("               �˳���½,������123456\n");
    scanf("%s",password);
    if(!strcmp(password,"123456"))
        break;
}
if(!strcmp(password,"123456"))
return 0;
else
return n;
}
 
//�ͻ�����---ע�ắ������
int registe()
{
printf("~~~~~~~~~~���ķ�������: %d ,����һ��Ҫ������! ~~~~~~~~~~~~~~\n",QQ);
printf("~~~~~~~~~~~~~~~�����������û���:~~~~~~~~~~~~~~~~~~\n");
scanf("%s",khl[QQ].name);
printf("~~~~~~~~~~~~~~~~��������λ����:~~~~~~~~~~~~~~~~~~~\n");
printf("\n");
scanf("%s",khl[QQ].password);
QQ++;
return 0;
}
 
//�ͻ�����---��ѯ��������
int searchkh(int flag)
{
int n,i=0;
n=flag;
printf("................................................................................\n");
printf("               Hello   %s   ���ķ�������: %d\n",khl[n].name,n);
printf("................................................................................\n");
if(khl[n].count!=-1){
    for(i=0;i<M;i++){
        if(odl[khl[n].count].L[i].amount==0)
            i++;
        else{
             printf("................................................................................\n");
             printf("������  ��������             ��������          ����\n");
             printf(" %3d  %-20s %6d  %6d\n",base[i].number,base[i].name,odl[khl[n].count].L[i].amount,base[i].price2);
             printf("................................................................................\n");
        }
 
    }
}
else{
      printf("\n");
      printf("................................................................................\n");
      printf("             ����ǰû�ж�����          \n");
      printf("................................................................................\n");
}
printf("................................................................................\n");
return 0;
}
 
//�ͻ�����---��������
int order(int flag)
{
int i=0,k=0,m=0,n=0,count=0;
printf("\n");
n=flag;
printf("������  ��������               �ۼ�\n");
printf("\n");
for(i=0;i<M;i++){
    if(base[i].number==-1){
        count++;
        continue;}
    else
      printf(" %3d      %-20s %6d\n",base[i].number,base[i].name,base[i].price2);
}
if(count==M)
{
    printf("�ֿ�����û�������Ժ��������鷳��֪ͨ�ɹ����ż�ʱ����������лл������\n");
    return 0;
}
printf("�������Ʒ��ź�����,�������,�ڶ������������� 0 \n");
printf("��Ʒ���\n");
scanf("%d",&k);
while((k>=M)||(base[k].number==-1)){
    printf("�˻��ﲻ���ڣ�����������\n");
    scanf("%d",&k);}
printf("����\n");
scanf("%d",&m);
while(m>0)
{
    if(base[k].amount<m)
    {
    odl[PP].L[k].amount=base[k].amount;
    base[k].amount=0;
    printf("�������,ȱ %d ��,��������%d��,ʣ�µ������Ժ�����ע���������Ԥ��!ͬʱ�鷳��֪ͨ�ɹ����ż�ʱ����������лл������\n",odl[PP].L[k].amount-base[k].amount,base[k].amount);
    lackl[k].amount+=(m-base[k].amount);
    }
    else{
        odl[PP].L[k].amount=m;
        base[k].amount-=m;
    }
    goodssum-=odl[PP].L[k].amount;
    suml[k].price1+=(odl[PP].L[k].amount*(base[k].price2-base[k].price1));
    suml[M].price1+=suml[k].price1;
    suml[k].amount+=odl[PP].L[k].amount;
    printf("��Ʒ���\n");
    scanf("%d",&k);
    while((k>=M)||(base[k].number==-1)){
    printf("�˻��ﲻ���ڣ�����������\n");
    scanf("%d",&k);}
    printf("��������\n");
    scanf("%d",&m);
}
khl[n].count=PP;
PP++;
return 0;
}
 
//����������
int manager()
{
 
    int i=0;
    for(i=0;i<M;i++)
    {
     if(suml[i].amount==0)
         i++;
     else{
              printf("................................................................................\n");
              printf("������  ��������           �û�������\n");
              printf(" %3d      %-20s %6d          \n",suml[i].number,base[i].name,suml[i].price1);
              printf("................................................................................\n");
     }
    }
    printf("\n--------------------�ܻ���Ϊ  %d  ��-----------------------------\n",goodssum);
    printf("\n--------------------������Ϊ  %d  ��Ԫ-----------------------------\n",suml[M].price1);
    return 0;
}
 
