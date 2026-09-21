//创立顺序队列//////////////////////////////////////////////////////////////////
#define MaxSize 50
typedef struct SqQueue 
{
	Elemtype data[MaxSize];
	int front,rear; 
}SqQueue;

//初始化//////////////////////////////////////////////////////////////////
void InitSqQueue(SqQueue &Q) 
{
	Q.front=Q.rear=0; 
}


//判队空//////////////////////////////////////////////////////////
bool EmptQueue(SqQueue &Q) 
{
	if(Q.front==Q.rear)
		return true;
	return false;
}

//入队
bool EnQueue(SqQueue &Q,Elemtype e) 
{
	if((Q.rear+1)%MaxSize==Q.front)
		return false;
	
	Q.data[Q.rear]=e;
	Q.rear=(Q.rear+1)%MaxSize;
	return true;
}


//出队
bool DeQueue(SqQueue &Q,Elemtype &e) 
{
	if(Q.front==Q.rear)
		return false;
	e=Q.data[Q.front];
	Q.front=(Q.front+1)%MaxSize;
	return true;
}


//链式队列创建/////////////////////////////////////////////////////////////////////
typedef struct LinkNode 
{
	Elemtype data;
	struct LinkNode *next;
}LinkNode;
typedef struct LinkQueue
{
	LinkNode *rear,*front;
}LinkQueue;

//初始化(不带头节点) 
void InitQueue(LinkQueue &Q) 
{
	Q.front=Q.rear=NULL;
}

//初始化（带头结点）
void InitQueue_(LinkQueue &Q) 
{
	Q.rear=Q.front=(LinkNode*)malloc(sizeof(LinkNode));
	Q.rear->next=NULL;
}


//判队空
bool EmptQueue(LinkQueue &Q) 
{
	if(Q.front==Q.rear)
		return true;
	return false;
}

//入队 
bool EnQueue(LinkQueue &Q,Elemtype e)
{
	LinkNode *s=(LinkNode*)malloc(sizeof(LinkNode));
	s->data=e;
	s->next=NULL;
	Q.rear->next=s;
	Q.rear=s; 
	return true;
}

//出队(带结点)///////////////////////////////////////////////////////////////
bool DeQueue(LinkQueue &Q,Elemtype &e) 
{
	if(Q.rear==Q.front)
		return false;
	LinkNode *q;
	q=Q.front->next;
	e=q->data;
	if(q==Q.rear)
		Q.rear=Q.front;
	Q.front->next=q->next;
	free(q);
	return true;
}












































