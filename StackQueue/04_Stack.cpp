//创立栈
#define MaxSize 50
typedef struct Sqstack 
{
	Elemtype data[MaxSize];
	int top; 
}SqStack;

//初始化栈
void InitStack(SqStack &S)
{
	S.top=-1;
}

//判断栈空
bool EmptStack(SqStack &S) 
{
	if(S.top==-1)
		return true;
	return false;
}

//进栈
bool Push(SqStack &S,ELemtype e) 
{
	if(S.top==MaxSize-1)
		return false;
	S.top++;
	S.data[S.top]=e;
	return true;
	
}

//出栈
bool Pop(SqStack &S,Elemtype &e) 
{
	if(S.top==-1)
		return false;
	e=S.data[S.top];
	S.top--;
	return true;
}


//读取栈顶元素
bool GetTop(SqStack &S,Elemtype &e) 
{
	if(S.top==-1)
		return false;
	e=S.data[S.top];
	return true;
}


//创建链栈
typedef struct LinkNode 
{
	Elemtype data;
	struct LinkNode *next; 
}LinkNode,*LinkStack;

//初始化链栈//////////////////////////////////////////////////
void InitStack(LinkStack &S) 
{
	S=NULL;
}

//入栈////////////////////////////////////////////////////////
bool Push(LinkStack &S,Elemtype e) 
{
	LinkNode *s=(LinkNode*)malloc(sizeof(LinkNode));
	if(s==NULL)
		return false; 
	s->data=e;
	s->next=S;
	S=s;
	return true;
}


//出栈
bool Pop(LinkStack &S,Elemtype &e) 
{
	if(S==NULL)
		return false;
	e=S->data;
	LinkNode *s=S;
	S=S->next;
	free(s);
	return true;
}
































 
