#include <stdio.h>//Ŀǰ���⣺�޷����������ı��ļ��������� 
#include <stdlib.h>
int LIST_INIT_SIZE=1;    //�����ʼ����  
#define ERROR   0
#define OK      1
//����ṹ��
struct LNode
{
    int data;
    int ISBN;
	int book;
	int author;
	int edition;
	int press;
	int year;
    struct LNode *next;
};

//��ȡ������ָ��λ�õ�����(����ͨ���� 
int GetElem_L(struct LNode *L, int i)
{
    //LΪ��ͷ���ĵ������ͷָ�롣����i��Ԫ�ش���ʱ���丳ֵ��e������OK�����򷵻�ERROR
    struct LNode *p;
    p= L->next;
    int j = 1;
    while (p&&j<i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j>i) return ERROR;
    printf("%d   ", p->ISBN);
    printf("%d   ", p->book);
    printf("%d   ", p->author);
    printf("%d   ", p->edition);
    printf("%d   ", p->press);
    printf("%d   ", p->year);
    printf("\n");
    system("pause"); 
    return OK;
}
//��������ָ��λ�ò������ݣ��Ѿ�����ˣ� 
int ListInsert_L(struct LNode *L, int i)
{
    struct LNode *p, *s;
    p = L;
    int v;
    int j = 0;
    while (p&&j<i - 1)
    {
        p = p->next;
        ++j;
    }
    if (!p || j>i - 1) return ERROR;

    s = (struct LNode *) malloc(sizeof(struct LNode));
    printf("ISBN����:");
	scanf("%d", &v);
    s->ISBN = v;
    printf("\n������:");
    scanf("%d", &v);
    s->book = v;
    printf("\n����:");
    scanf("%d", &v);
    s->author = v;
    printf("\n�ڼ���:");
    scanf("%d", &v);
    s->edition = v;
    printf("\n��������:");
    scanf("%d", &v);
	s->press = v;
    printf("\n������:");
    scanf("%d", &v);
    s->year = v;
    s->next = p->next;
    p->next = s;
    return OK;
}

//ɾ��������ָ��λ�õ�����(����ͨ���� 
int ListDelete_L(struct LNode *L, int i, int *e)
{
    struct LNode *p, *q;
    p = L;
    int j = 0;
    while (p->next && j<i - 1)
    {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j>i - 1) return ERROR;
    q = p->next;
    p->next = q->next;
    *e = p->book;
    free(q);
    return OK;
}

//��������,¼���1��ԭʼ���ݣ�����ͨ���� 
void CreateList_L(struct LNode *L, int n)
{
    int i;
    int v;
    struct LNode *p;
    L->next = NULL;
    //ѭ��¼������
    for (i = n; i>0; --i)
    {
        p = (struct LNode *) malloc(sizeof(struct LNode));
        printf("ISBN����:");
		scanf("%d", &v);
        p->ISBN = v;
        printf("\n������:");
        scanf("%d", &v);
        p->book = v;
        printf("\n����:");
        scanf("%d", &v);
        p->author = v;
        printf("\n�ڼ���:");
        scanf("%d", &v);
        p->edition = v;
        printf("\n��������:");
        scanf("%d", &v);
        p->press = v;
        printf("\n������:");
        scanf("%d", &v);
        p->year = v;
        p->next = L->next;  //ͷ�巨
        L->next = p;
    }
}
//��������ļ� (����ͨ��)
int PrintList_F(struct LNode *L){
    struct LNode *p;
    FILE *fp=fopen("text.txt","w");
    p = L->next;
    if (p == NULL)
    {
        printf("����Ϊ��\n");
        return ERROR;
    }
    while (p != NULL){
        fprintf(fp,"%d   ", p->ISBN);
        fprintf(fp,"%d   ", p->book);
        fprintf(fp,"%d   ", p->author);
        fprintf(fp,"%d   ", p->edition);
        fprintf(fp,"%d   ", p->press);
        fprintf(fp,"%d   ", p->year);
        p = p->next;
    }
    printf("\n");
    fclose(fp);  
    return OK;
}

//��������е�����(����ͨ������)
int PrintList_L(struct LNode *L, char* s){
    struct LNode *p;
    printf("%s", s);
    p = L->next;
    if (p == NULL)
    {
        printf("����Ϊ��\n");
        return ERROR;
    }
    while (p != NULL){
    	printf("\n");
        printf("%d   ", p->ISBN);
        printf("%d   ", p->book);
        printf("%d   ", p->author);
        printf("%d   ", p->edition);
        printf("%d   ", p->press);
        printf("%d   ", p->year);
        printf("\n");
        p = p->next;
    }
    printf("\n");
    return OK;
}
int ListInsert_F(struct LNode *L,int i)//debuging
{
    char key;
	FILE *fpRead=fopen("text.txt","r"); 
    if(fpRead==NULL)return 0;
    int v=0;
    struct LNode *p,*q,*head;
    //ѭ��¼������
    while(!feof(fpRead))
    {    
		p = (struct LNode *) malloc(sizeof(struct LNode));
	     if(v==0)
          {
		     q=p;
		     head=p;
	      }
         else
          {
		     q->next=p;
		     q=p;
	      }
        fscanf(fpRead,"%d   %d   %d   %d   %d   %d   ",&p->ISBN,&p->book,&p->author,&p->edition,&p->press,&p->year);
        v++;
    }
    p->next=L->next;
    L->next=head;
    return OK;
}
int Sort(struct LNode *L)/*��������������ڲ����������ͷָ�룬��Ϊ�����е�������*///(����ͨ��) 
{
	struct LNode *p,*q;
	int temp;
	for(p=L;p!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(p->book>q->book)
			{
				temp=q->ISBN;
				q->ISBN=p->ISBN;
				p->ISBN=temp;
				temp=q->book;
				q->book=p->book;
				p->book=temp;
				temp=q->author;
				q->author=p->author;
				p->author=temp;
				temp=q->press;
				q->press=p->press;
				p->press=temp;
				temp=q->year;
				q->year=p->year;
				p->year=temp;
			}
		}
	}
	return L;
}
int caidan()
{
	char c;
		do {
			system("cls");
			printf("1.�����鱾��¼\n");
			printf("2.��ʾ���м�¼\n");
			printf("3.ɾ��¼\n");
			printf("4.����\n");
			printf("5.�����¼\n");
			printf("6.��ѯ\n");
			printf("7.���ı��ĵ�����Ӽ�¼\n");
			printf("8.д�뵽�ı��ĵ���\n");
			printf("0.�ݰ�\n");
			printf("ѡһ��:");
			c=getchar();
	}
	while(c<'0'||c>'8');
	return(c-'0');
}
//�˵� 
int main(void)
{
    //��������
    struct LNode L;
    char key;
    int s, v;
    int i=1;
    int k=1;
    printf("���س�����ʼ���ݣ�"); 
    for(;;)
    {
		getchar();
		switch(caidan())
	{
	    case 1: //¼��������ʾ
        for(;;)
        {
        	printf("�������%d��������ݣ�\n",LIST_INIT_SIZE);//��ʼ������
			if(LIST_INIT_SIZE==1)
			{
				CreateList_L(&L, 1);
			 } else
			 {
			 	ListInsert_L(&L, LIST_INIT_SIZE);
			 }
            printf("��y��������");
            getchar();
			key=getchar();
			LIST_INIT_SIZE++;
			if(key!='y')break;
		}break; 
		case 2:
			for(;i!=LIST_INIT_SIZE;i++)
			{
				PrintList_L(&L,"�����鱾����Ϣ���£�");
				system("pause");
				break;
			}
			break; 
		case 3://ɾ��������ʾ
        	printf("��Ҫɾ����һ���飿");
        	scanf("%d", &s);
        	if (ListDelete_L(&L, s, &v))   
			{
        		printf("ɾ���ɹ�.ɾ�����ǣ�%d�Ȿ��\n", v);LIST_INIT_SIZE--;
			}
        	else 
				printf("ɾ��ʧ��.λ������.");
        	PrintList_L(&L,"ɾ���������");//�������/ɾ������ʱλ�ú���ֵ����
			break;
		case 4:Sort(&L);break;
		case 5://���빦����ʾ
        	getchar();
			printf("Ҫ����һ����֮����룿");
        	scanf("%d", &s);
        	printf("%s", ListInsert_L(&L, s) ?"����ɹ�.\n" : "����ʧ��.\n");
        	PrintList_L(&L,"����������"); break;
        case 6://��ѯ������ʾ
        	printf("��ѯ��һ����?��");
        	scanf("%d", &s);
        	GetElem_L(&L,s);
        	printf("��%d�������Ϣ�ǣ�%d\n\n",s);
        	PrintList_L(&L,"�����鱾����Ϣ���£�");
        	break;
        case 7:
			printf("Ҫ�ӵ����");
			scanf("%d",&k); 
			ListInsert_F(&L,k);break;
        case 8:
			PrintList_F(&L);break;
        case 0:
			system("cls");printf("�ҳ���˧���ģ�\n");return; 
	 } 
    }
    system("pause");
    return 0; 
}
