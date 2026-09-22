//创建节点
typedef struct ThreadNode
{
	Elemtype data;
	struct ThreadNode *lchild,*rchild;
	int ltag,rtag;
}ThreadNode,*ThreadTree;

//中序线索化 
void InThread(ThreadTree T) 
{
	if(T!=NULL)
	{
		InThread(T->lchild);
		visit(T);
		InThread(T->rchild);
	}
}

ThreadNode *pre=NULL;

void visit(ThreadNode *q)
{
	if(q->lchild==NULL)
	{
		q->lchild=pre;
		q->ltag=1;
	}
	if(pre!=NULL&&pre->rchild==NULL)
	{
		pre->rchild=q;
		pre->rtag=1;
	}
	pre=q;
}
 
