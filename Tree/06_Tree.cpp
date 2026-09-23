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

//中序遍历
//找到中序下的首元素
ThreadNode *FirstNode(ThreadNode *p) 
{
	while(p->ltag==0)
		p=p->lchild;
	return p;
}

//找改节点的后一个
ThreadNode *NextNode(ThreadNode *p) 
{
	if(p->rtag==0)
		return FirstNode(p->rchild);
	return p->rchild;
}

//循环遍历中序线索二叉树
void InOrder(ThreadNode *T) 
{
	for(ThreadNode *p=FirstNode(T);p!=NULL;p=NextNode(p))
	{
		visit(p);
	}
}



















 
