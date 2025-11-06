#include<stdio.h>
#include<stdlib.h>
typedef int Datatype;

/*线性表的单链表存储结构*/
typedef struct Lnode{
	Datatype data;
	struct Lnode * next;

}LNode, *LinkList;

/*生成一个带头节点的空的单链表*/
void Initlist(LinkList *L){
	*L = (LinkList)malloc(sizeof(LNode));				/*生成一个LNode节点，并将该节点起始地址赋值给L*/
	(*L)->next = NULL;						/*将该节点的指针域置为空*/
}

/*建立有n个节点的单链表(倒序输入数据)*/
void Create_L(LinkList  *L,int n){
	Initlist(L);							/*生成一个带头节点的空单链表*/
	LinkList p;
	for(int i = n;i > 0;i--){
		p = (LinkList)malloc(sizeof(LNode));			/*生成一个LNode节点，将该节点的初始地址赋值给p*/
		printf("请输入第%d个数据",i);
		scanf("%d",&(p->data));					/*将数据输入数据域*/
		p->next = (*L)->next;					/*将上一个生成的节点连接到新的节点的后面*/
		(*L)->next = p;						/*将新建的节点连接到头节点的后面*/
	}


}


/*输出链表的全部内容*/
void output(LinkList  *L){
	LinkList p = (*L)->next;					/*将p指向首元节点*/
	while(1){
		printf("%d\n",p->data);					/*输出当前节点的数据域*/			
		p = p->next;						/*将指针指p向下一个节点*/
		if(!(p)){						/*如果下一个节点是空的，就退出*/
			break;
		}
	}
}


/*单链表的查找结构:找到并输出第i个节点的数据域中的值*/

void FindElement_L(LinkList *L,int i){
	LinkList p = (*L)->next;					/*将p指向首元节点*/
	int counter = 1;						/*用于控制循环次数*/
	while(p && counter < i){					/*若当前节点不为空，且前还没有到第i个元素,则进入循环体*/
		p = p->next;
		counter++;
	}
	printf("第%d个元素是%d\n",i,p->data);

}


/*单链表的按值查找*/

LinkList LocateNode(LinkList *L,Datatype i){
	if(*L == NULL){
		printf("传进来的链表是空的");
		return NULL;
	}
	else{
		LinkList p = (*L)->next;				/*将p指向首元节点*/
		while(p&&(p->data!=i)){
			p = p->next;
		}	
		if(p == NULL){
			printf("%d不在该链表中\n",i);
			return NULL;
		}
		else{
			return p;
		}
	}
}

int main(){
	LinkList L;
	Create_L(&L,5);							/*新建一个链表*/
	output(&L);							/*输出链表中所有的元素*/
	FindElement_L(&L,3);						/*找到第三个元素并输出其中的数据*/
	LinkList mid = LocateNode(&L,3);				/*返回数值为3的节点的位置*/
	printf("%d\n",mid->data);					/*根据地址输出元素的值*/
	return 0;							
}
