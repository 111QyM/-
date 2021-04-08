#ifndef _T_H_
#define _T_H_

typedef struct Link{
	int num;
	struct Link *next;
}Link;

typedef enum Status{
	ERROR,
	SUCCESS
}Status;

Link* Create(int n);
void InitLink(Link *L);
Link* DesLink(Link *L);
Status InsertNode(Link *p,int t);
Status DelNode(Link *p,int a);
void TraverseLink(Link *L,void (*visit)(int n));
void visit(int n);
void SearchNode(Link *L,int a);
Link* ReverseLink(Link *L);
//Status isLoopLink(Link *L);
void ReverseEvenLink(Link *L);
void FindMidNode(Link *L);

#endif
