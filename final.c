#include <stdio.h>
#include <stdlib.h>
int LIST_INIT_SIZE=1;    //链表初始长度  
#define ERROR   0
#define OK      1
//链表结构体
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

//获取链表中指定位置的数据(测试通过） 
int GetElem_L(struct LNode *L, int i)
{
    //L为带头结点的单链表的头指针。当第i个元素存在时，其赋值给e并返回OK，否则返回ERROR
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
//向链表中指定位置插入数据（已经解决了） 
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
    printf("ISBN多少:");
	scanf("%d", &v);
    s->ISBN = v;
    printf("\n书名字:");
    scanf("%d", &v);
    s->book = v;
    printf("\n作者:");
    scanf("%d", &v);
    s->author = v;
    printf("\n第几版:");
    scanf("%d", &v);
    s->edition = v;
    printf("\n出版社名:");
    scanf("%d", &v);
	s->press = v;
    printf("\n出版年:");
    scanf("%d", &v);
    s->year = v;
    s->next = p->next;
    p->next = s;
    return OK;
}

//删除链表中指定位置的数据(测试通过） 
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

//创建链表,录入第1个原始数据（测试通过） 
void CreateList_L(struct LNode *L, int n)
{
    int i;
    int v;
    struct LNode *p;
    L->next = NULL;
    //循环录入数据
    for (i = n; i>0; --i)
    {
        p = (struct LNode *) malloc(sizeof(struct LNode));
        printf("ISBN多少:");
		scanf("%d", &v);
        p->ISBN = v;
        printf("\n书名字:");
        scanf("%d", &v);
        p->book = v;
        printf("\n作者:");
        scanf("%d", &v);
        p->author = v;
        printf("\n第几版:");
        scanf("%d", &v);
        p->edition = v;
        printf("\n出版社名:");
        scanf("%d", &v);
        p->press = v;
        printf("\n出版年:");
        scanf("%d", &v);
        p->year = v;
        p->next = L->next;  //头插法
        L->next = p;
    }
}
//输出链表到文件 (测试通过)
int PrintList_F(struct LNode *L){
    struct LNode *p;
    FILE *fp=fopen("text.txt","w");
    p = L->next;
    if (p == NULL)
    {
        printf("链表为空\n");
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

//输出链表中的数据(测试通过测试)
int PrintList_L(struct LNode *L, char* s){
    struct LNode *p;
    printf("%s", s);
    p = L->next;
    if (p == NULL)
    {
        printf("链表为空\n");
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
    //循环录入数据
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
int Sort(struct LNode *L)/*递增排序函数：入口参数：链表的头指针，此为链表中的排序函数*///(测试通过) 
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
			printf("1.输入书本记录\n");
			printf("2.显示所有记录\n");
			printf("3.删记录\n");
			printf("4.排序\n");
			printf("5.插入记录\n");
			printf("6.查询\n");
			printf("7.从文本文档中添加记录\n");
			printf("8.写入到文本文档中\n");
			printf("0.拜拜\n");
			printf("选一个:");
			c=getchar();
	}
	while(c<'0'||c>'8');
	return(c-'0');
}
//菜单 
int main(void)
{
    //定义链表
    struct LNode L;
    char key;
    int s, v;
    int i=1;
    int k=1;
    printf("按回车键开始表演！"); 
    for(;;)
    {
		getchar();
		switch(caidan())
	{
	    case 1: //录入数据演示
        for(;;)
        {
        	printf("请输入第%d本书的数据：\n",LIST_INIT_SIZE);//初始化链表
			if(LIST_INIT_SIZE==1)
			{
				CreateList_L(&L, 1);
			 } else
			 {
			 	ListInsert_L(&L, LIST_INIT_SIZE);
			 }
            printf("按y继续输入");
            getchar();
			key=getchar();
			LIST_INIT_SIZE++;
			if(key!='y')break;
		}break; 
		case 2:
			for(;i!=LIST_INIT_SIZE;i++)
			{
				PrintList_L(&L,"所有书本的信息如下：");
				system("pause");
				break;
			}
			break; 
		case 3://删除功能演示
        	printf("请要删除哪一本书？");
        	scanf("%d", &s);
        	if (ListDelete_L(&L, s, &v))   
			{
        		printf("删除成功.删除的是：%d这本书\n", v);LIST_INIT_SIZE--;
			}
        	else 
				printf("删除失败.位置有误.");
        	PrintList_L(&L,"删除后的链表：");//定义插入/删除操作时位置和数值参数
			break;
		case 4:Sort(&L);break;
		case 5://插入功能演示
        	getchar();
			printf("要在哪一本书之间插入？");
        	scanf("%d", &s);
        	printf("%s", ListInsert_L(&L, s) ?"插入成功.\n" : "插入失败.\n");
        	PrintList_L(&L,"插入后的链表："); break;
        case 6://查询功能演示
        	printf("查询哪一本书?：");
        	scanf("%d", &s);
        	GetElem_L(&L,s);
        	printf("第%d本书的信息是：%d\n\n",s);
        	PrintList_L(&L,"所有书本的信息如下：");
        	break;
        case 7:
			printf("要加到哪里？");
			scanf("%d",&k); 
			ListInsert_F(&L,k);break;
        case 8:
			PrintList_F(&L);break;
        case 0:
			system("cls");printf("我超级帅气的！\n");return; 
	 } 
    }
    system("pause");
    return 0; 
}
