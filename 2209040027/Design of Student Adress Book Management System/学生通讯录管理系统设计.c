#include <stdio.h>   /*ͷ�ļ�*/
#include <stdlib.h> //������õ�ϵͳ����
#include <string.h> //�����ַ�����ĺ��������ͷ�ļ�
#include <conio.h>

//����ṹ��
struct tongxunlu   /*����ͨѶ¼�ṹ�����*/
{
    char xingming[20];    /*�����������ֵ�����*/
    char dianhua[20]; /*��������绰���������*/
    char dizhi[40]; /*���������ַ������*/
} txl[100]; //Ĭ��100������
int n=0;//��¼������ϵ������
FILE *fp;   /*�����ļ�*/
//�����õ������к���
void zhucaidan();    /*���˵�����*/
void zengjia();   /*������ϵ�˺���*/
void readfile();  /*�ļ��ж��뺯��*/
void writefile();  /*�ļ���д�뺯��*/
void xiugai();    /*�޸���ϵ�˺���*/
void xiugai_xingming();  /*�����޸�*/
void xiugai_dianhua();  /*�绰�����޸�*/
void chazhao();      /*������ϵ�˺���*/
void chazhao_xingming();  /*����������*/
void chazhao_dianhua();  /*���������*/
void shanchu();    /*ɾ����ϵ�˺���*/
void shanchu_quanbu();  /*ȫ��ɾ��*/
void shanchu_dange();  /*����ɾ��*/
void xianshi();         /*������ʾ*/
//���������� ģ����
int main()         /*������main*/
{
    readfile();    /*�����ļ�*/
    while(1)      /* ѭ������Զ���У�*/
    {
        zhucaidan();     /*�������˵�����*/
    }
    return 0;
}
//��ȡ�ļ��������ֿ�ʼ ģ����
void readfile()
{
    if((fp=fopen("txl.txt","r"))==NULL)  /*��ֻ����ʽ���ж��ļ��Ƿ�Ϊ��*/
    {
        printf("\n\t\t\t    ͨѶ¼�ļ�������");    /*�жϽ���*/
        if ((fp=fopen("txl.txt","w"))==NULL) /*ֻд��ʽ�ж�*/
        {
            printf("\n\t\t����ʧ��");      /*Ϊ�ս���*/
            exit(0);                        /*�˳�*/
        }
        else                               /*��Ϊ����ִ��else*/
        {
            printf("\n\t-----------------��ӭʹ��ͨѶ¼����ϵͳ------------------");
            printf("\n\t                    ͨѶ¼�ļ��ѽ���                     ");
            printf("\n\t                   ��������������˵�                    ");
            printf("\n\t---------------------------------------------------------");
            getch();
            return ;
        }
        exit(0);
    }
    fseek(fp,0,2); /*�ļ�λ��ָ���ƶ����ļ�ĩβ*/
    if (ftell(fp)>0) /*�ļ���Ϊ��*/
    {
        rewind(fp); /*�ļ�λ��ָ���ƶ����ļ���ʼλ��*/
        for (n=0; !feof(fp) && fread(&txl[n],sizeof(struct tongxunlu),1,fp); n++);
        printf("\n\t----------  ��ӭʹ��ͨѶ¼����ϵͳ  ----------------");
        printf("\n\t                   �ļ�����ɹ�                          ");
        printf("\n\t                 ��������������˵�                      ");
        printf("\n\t---------------------------------------------------------");
        getch();
        return;
    }
    printf("\n\t------------  ��ӭʹ��ͨѶ¼����ϵͳ  --------------");
    printf("\n\t                     �ļ�����ɹ�                        ");
    printf("\n\t                ͨѶ¼�ļ������κμ�¼                   ");
    printf("\n\t                  ��������������˵�                     ");
    printf("\n\t---------------------------------------------------------");
    getch();
    return;
}
//��ȡ�ļ���������

//�ļ����˵�������ʼ ģ����
void zhucaidan()
{
    char c;
    system("cls");
    printf("\n\t\t|-------  ��ӭ��ʹ��ͨѶ¼����ϵͳ -----|");
    printf("\n\t\t|         1-�����ϵ��    2-��ѯ����ʾ��ϵ��     |");
    printf("\n\t\t|         3-ɾ����ϵ��    4-�޸���ϵ��           |");
    printf("\n\t\t|         5-�����˳�      0-�������˳�           |");
    printf("\n\t\t|------------------------------------------------|");
    printf("\n\t\t��ѡ��������Ҫ�ķ���");
    c=getch();
    switch (c) /*�����ϱߵ�ѡ����Ŀ*/
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
        zhucaidan(); /*���û���򷵻����˵��ȴ�����*/
    }
}
//�ļ����˵���������

//�������ϵ�˺�����ʼ ģ��һ
void zengjia()
{
    printf("\n\t\t------------------ ��������ϵ����Ϣ --------------------\n");
    printf("\n\t\t������ϵ������:");
    scanf("%s",txl[n].xingming);    /*��������*/
    printf("\n\t\t������ϵ�˵绰����:");
    scanf("%s",txl[n].dianhua);
    printf("\n\t\t������ϵ�˵�ַ:");
    scanf("%s",txl[n].dizhi);
    n++;                            /*ͳ�Ƹ���*/
    printf("\n\t\t�Ƿ���������ϵ��?(Y/N):"); /*�Ƿ����������ϵ��.*/
    if (getch()=='y')
        zengjia();
    return;
}
//�������ϵ�˽���
//д���ļ�������ʼ  ģ����
void writefile()     /*��ϵ��д���ļ�*/
{
    int i;
    if ((fp=fopen("txl.txt","w"))==NULL)
    {
        printf("\n\t\t�ļ���ʧ��");
    }
    for (i=0; i<n; i++)
    {
        if (fwrite(&txl[i],sizeof(struct tongxunlu),1,fp)!=1)
        {
            printf("\n\t\tд���ļ�����!\n");
        }
    }
    fclose(fp); /*�ر��ļ�*/
    printf("\n\t------------------------------------------------------"); /*�����ʾ��Ϣ*/
    printf("\n\t\tͨѶ¼�ļ��ѱ���");
    printf("\n\t\tллʹ�ã���ӭ�ٴ�ʹ��!\n");
    printf("����Ա����������,������������������,���ǽ�Ϊ�����.\n");
    printf("���ǵ�����в���֮��,�������Ƿ�ӳ�����ǽ�Ŭ������!");
    printf("\n\t\t��������˳�����\n\t\t");      /*������*/
    exit(0);
    printf("\n\t------------------------------------------------------");
}
//д���ļ���������
///��ѯ��ϵ�˺�����ʼ ģ����----------------------------------------------------
void chazhao()
{
    char c;
    system("cls");
    printf("\n\t\t------------------- ��ʾ�Ͳ�ѯ��ϵ�� ------------------");
    printf("\n\t\t|        1-�����ʾ����          2-��������ѯ         |");
    printf("\n\t\t|        3-���绰��ѯ            4-�������˵�         |");
    printf("\n\t\t|------------------------------------------------------");
    printf("\n\t\t��ѡ��������Ҫ�ķ���");
    c=getch();
    switch (c)
    {
    case '1':
        xianshi();
        break;   /*��ʾ���к���*/
    case '2':
        chazhao_xingming();
        break;  /*���ð�������ѯ����*/
    case '3':
        chazhao_dianhua();
        break;  /*���ð������ѯ����*/
    case '4':
        zhucaidan();
        break;       /*���˵�*/
    }
}
void xianshi()//��ʾ������ϵ�˺���
{
    int i;
    system("cls");//�����Ļ
    if(n!=0)
    {
        printf("\n\t\t----------��ӭ����ѯͨѶ¼������ϵ����Ϣ-------------");
        for (i=0; i<n; i++)   /*��������ʾ*/
        {
            printf("\n\t\t������ %s",txl[i].xingming);
            printf("\n\t\t�绰�� %s",txl[i].dianhua);
            printf("\n\t\t��ַ�� %s",txl[i].dizhi);
            printf("\n\t\t--------------------------------------------------");
            if (i+1<n)
            {
                printf("\n\t\t-----------------------");
                system("pause");//���ش�����Ϣ
            }
        }
        printf("\n\t\t---------------------------------------------");
    }
    else                                  /*����ϵ��*/
        printf("\n\t\tͨѶ¼�����κμ�¼");
    printf("\n\t\t��������������˵���");
    getch();
    return;
}
//�������ѯ����
void chazhao_dianhua()
{
    int mark=0;
    int i;
    char phone[15];
    printf("\n\t\t------------------- ���绰���� -------------------------");
    printf("\n\t\t������绰����:");
    scanf("%s",phone);
    for(i=0; i<n; i++)
    {
        if (strcmp(txl[i].dianhua,phone)==0)//�ԱȲ��Һ���
        {
            printf("\n\t\t------------ �����������ҵ�ѧ����Ϣ ------------");
            printf("\n\t\t������ %s",txl[i].xingming);
            printf("\n\t\t�绰�� %s",txl[i].dianhua);
            printf("\n\t\t��ַ�� %s",txl[i].dizhi);
            printf("\n\t\t------------------------------------------------");
            printf("\n\t\t��������������˵���");
            mark++;
            getch();
            return;
        }
    }
    if (mark==0)
    {
        printf("\n\t\tû���ҵ���ϵ�˵���Ϣ");
        printf("\n\t\t��������������˵�");
        getch();
        return;
    }
}
void chazhao_xingming()//��������ѯ
{
    int mark=0;
    int i;
    char name[20];
    printf("\n\t\t----------------���������� --------------------");
    printf("\n\t\t��������Ҫ���ҵ�����:");
    scanf("%s",name);
    for(i=0; i<n; i++)
    {
        if (strcmp(txl[i].xingming,name)==0)
        {
            printf("\n\t\t------------ �����������ҵ���ϵ����Ϣ ---------------");
            printf("\n\t\t������ %s",txl[i].xingming);
            printf("\n\t\t�绰�� %s",txl[i].dianhua);
            printf("\n\t\t��ַ�� %s",txl[i].dizhi);
            printf("\n\t\t---------------------------------------------------");
            mark++;
            getch();
            return;
        }
    }
    if (mark==0)
    {
        printf("\n\t\tû���ҵ���ϵ�˵���Ϣ");
        printf("\n\t\t��������������˵�");
        getch();
        return;
    }
}

////��ѯ��ϵ�˺�������-----------------------------------------------------

////ɾ����ϵ�˺������ֿ�ʼ-------------------------------------------------
void shanchu()
{
    char c;
    if(n==0)     /*���ͨѶ¼��û��һ����¼������²���*/
    {
        printf("\n\t\t�Բ����ļ������κμ�¼");
        printf("\n\t\t��������������˵�");
        getch();
        return;
    }
    system("cls");      /*����*/
    printf("\n\t\t-----------------  ɾ���˵� ----------------------");
    printf("\n\t\t|           1-ɾ������ 2-ɾ������                |");
    printf("\n\t\t|                3-�������˵�                    |");
    printf("\n\t\t|-------------------------------------------------");
    printf("\n\t\t��ѡ��������Ҫ�ķ���");
    c=getch();     /*����ĸ���choice*/
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
void shanchu_quanbu()//ɾ��������ϵ��
{
    printf("\n\t\tȷ��ɾ��?(y/n)");
    if (getch()=='y')
    {
        fclose(fp);
        if ((fp=fopen("txl.txt","w"))==NULL)   /*�ļ������*/
        {
            printf("\n\t\t���ܴ��ļ���ɾ��ʧ��");
            readfile();
        }
        n=0;
        printf("\n\t\t��¼��ɾ������������������˵�");
        getch();
        return;
    }
    else
        return;
}
void shanchu_xingming()//������ɾ����ϵ��
{
    int i,m,mark=0,a=0;
    char name[20];
    printf("\n\t\t������Ҫɾ����ϵ��������");
    scanf("%s",name);    /*������������*/
    for (i=a; i<n; i++)
    {
        if (strcmp(txl[i].xingming,name) == 0) //�Ա��ַ������ҵ�Ҫɾ������ϵ��
        {
            printf("\n\t\t��������Ҫɾ������ϵ�˼�¼��");
            printf("\n\t\t--------------------------------");
            printf("\n\t\t������ %s",txl[i].xingming);
            printf("\n\t\t�绰�� %s",txl[i].dianhua);
            printf("\n\t\t��ַ�� %s",txl[i].dizhi);
            printf("\n\t\t--------------------------------");
            printf("\n\t\t�Ƿ�ɾ��?(y/n)");
            if (getch()=='y') // ʵ��ɾ������
            {
                for (m=i; m<n-1; m++)
                    txl[m]=txl[m+1];    /*��ͨѶ¼����ǰ��*/
                n--;
                mark++;
                printf("\n\t\tɾ���ɹ�");
                printf("\n\t\t�Ƿ����ɾ��?(y/n)");
                if (getch()=='y')
                    shanchu_xingming();   /*��������ɾ������*/
                return;
            }
            else
                return;
        }
        continue;
    }
    if (mark==0)
    {
        printf("\n\t\tû�и���ϵ�˵ļ�¼");
        printf("\n\t\t�Ƿ����ɾ��?(y/n)");
        if (getch()=='y')
            shanchu_xingming();
        return;
    }
}
void shanchu_dianhua()//���绰����ɾ����ϵ��
{
    int i,m,mark=0;    /*��������*/
    char phone[20];
    printf("\n\t\t������Ҫɾ����ϵ�˵绰���룺");
    scanf("%s",phone);
    if(n==0)
    {
        printf("\n\t\t�Բ����ļ������κμ�¼");
        printf("\n\t\t��������������˵�");
        getch();
        return;
    }
    for (i=0; i<n; i++)
    {
        if (strcmp(txl[i].dianhua,phone)==0)
        {
            printf("\n\t\t��������Ҫɾ������ϵ�˼�¼��");
            printf("\n\t\t������ %s",txl[i].xingming);
            printf("\n\t\t�绰�� %s",txl[i].dianhua);
            printf("\n\t\t��ַ�� %s",txl[i].dizhi);
            printf("\n\t\t�Ƿ�ɾ��?(y/n)");
            if (getch()=='y')
            {
                for (m=i; m<n-1; m++) //�����滻ʵ��ɾ��
                    txl[m]=txl[m+1];
                n--;
                mark++; //��¼ɾ������
                printf("\n\t\tɾ���ɹ�");
                printf("\n\t\t�Ƿ����ɾ��?(y/n)");
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
        printf("\n\t\tû�и���ϵ�˵ļ�¼");
        printf("\n\t\t�Ƿ����ɾ��?(y/n)");
        if (getch()=='y')
            return ;
    }
}
void shanchu_dange()//ɾ��������ϵ��
{
    char c;
    printf("\n\t----------------------------------------------------------");
    printf("\n\t\t   1-������ɾ��    2-���绰ɾ��");
    printf("\n\t\t��ѡ��������Ҫ�ķ���");
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
///ɾ���������ֽ���--------------------------------------------------------

///�޸���ϵ�˺�����ʼ--------------------------------------------------
void xiugai()     /*�޸ĺ���*/
{
    char c;
    if(n==0)
    {
        printf("\n\t\t�Բ����ļ������κμ�¼");
        printf("\n\t\t��������������˵�");
        getch();
        return;
    }
    system("cls");
    printf("\n\t\t-----------------�޸���ϵ�˲˵�-----------------------");
    printf("\n\t\t|          1-�������޸�    2-���绰�޸�              |");
    printf("\n\t\t|              �����-���������˵�                   |");
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
    printf("\n\t\t������Ҫ�޸ĵ���ϵ��������");
    scanf("%s",name);
    if(n==0)
    {
        printf("\n\t\t�ļ������κ���ϵ��");
        printf("\n\t\t��������������˵�");
        getch();
        mark++;
        return;
    }
    for(i=0; i<n; i++)
    {
        if(strcmp(txl[i].xingming,name)==0)
        {
            printf("\n\t\t��������Ҫ�޸ĵ���ϵ����Ϣ");
            printf("\n\t\t����: %s",txl[i].xingming);
            printf("\n\t\t�绰: %s",txl[i].dianhua);
            printf("\n\t\t��ַ: %s",txl[i].dizhi);
            printf("\n\t\t�Ƿ��޸�(y/n)");
            if(getch()=='y')
            {
                printf("\n\t------------��ѡ���޸���Ϣ---------------");
                printf("\n\t         1-�޸�����     2-�޸ĵ绰       ");
                printf("\n\t                3-�޸ĵ�ַ               ");
                printf("\n\t-----------------------------------------");
                printf("\n\t��ѡ��������Ҫ�ķ���");
                scanf("%s",&c);
                switch(c)
                {
                case '1':
                    printf("\n\t��������������");
                    scanf("%s",txl[i].xingming);
                    break;
                case'2':
                    printf("\n\t�������µ绰��");
                    scanf("%s",txl[i].dianhua);
                    break;
                case'3':
                    printf("\n\t�������µ�ַ: ");
                    scanf("%s",txl[i].dizhi);
                    break;
                }
            }
        }
    }
    if(mark==0)
    {
        printf("\n\t\tû���ҵ���ϵ����Ϣ");
        printf("\n\t�Ƿ�����޸ģ�(Y/N):");
        if(getch()=='y')
            xiugai_xingming();
        return;
    }
}

void xiugai_dianhua()
{
    char c,phone[15];
    int i,mark=0;
    printf("\n\t\t������Ҫ�޸���ϵ�˵ĺ��룺");
    scanf("%s",phone);
    if(n==0)
    {
        printf("\n\t\t�ļ������κ���ϵ��");
        printf("\n\t\t��������������˵�");
        getch();
        mark++;
        return;
    }
    for(i=0; i<n; i++)
    {
        if(strcmp(txl[i].dianhua,phone)==0)
        {
            printf("\n\t\t��������Ҫ�޸ĵ���ϵ����Ϣ");
            printf("\n\t\t����: %s",txl[i].xingming);
            printf("\n\t\t�绰: %s",txl[i].dianhua);
            printf("\n\t\t��ַ: %s",txl[i].dizhi);
            printf("\n\t\t�Ƿ��޸�(y/n)");
            if(getch()=='y')
            {
                printf("\n\t------------��ѡ���޸���Ϣ---------------");
                printf("\n\t       1-�޸�����     2-�޸ĵ绰         ");
                printf("\n\t               3-�޸ĵ�ַ                ");
                printf("\n\t-----------------------------------------");
                printf("\n\t��ѡ��������Ҫ�ķ���");
                scanf("%s",&c);
                switch(c)
                {
                case'1':
                    printf("\n\t�������������� ");
                    scanf("%s",txl[i].xingming);
                    break;
                case'2':
                    printf("\n\t�������µ绰�� ");
                    scanf("%s",txl[i].dianhua);
                    break;
                case'3':
                    printf("\n\t�������µ�ַ: ");
                    scanf("%s",txl[i].dizhi);
                    break;
                }
            }
        }
    }
    if(mark==0)
    {
        printf("\n\tû�и���ϵ����Ϣ");
        printf("\n\t�Ƿ�����޸ģ�(Y/N):");
        if(getch()=='y')
            xiugai_dianhua();
        return;
    }
}
