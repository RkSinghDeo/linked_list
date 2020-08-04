#include<iostream>
#include<cstddef>
using namespace std;
struct node
{
	int data;
	node *next;
	node *back;
}*first=NULL,*firstt=NULL,*firstd=NULL,*firsttd=NULL;



void create(int a[], int n)
{
	int i;
	struct node *t,*last;
	first= new node;
	first->data=a[0];
	first->next=NULL ;
	last=first;
	
	for(int i=1;i<n;i++)
	{
		t= new node;
		t->data=a[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}

}
void createe(int a[], int n)
{
	int i;
	struct node *t,*last;
	firstt= new node;
	firstt->data=a[0];
	firstt->next=NULL ;
	last=firstt;
	
	for(int i=1;i<n;i++)
	{
		t= new node;
		t->data=a[i];
		t->next=NULL;
		last->next=t;
		last=t;
	}
}
	void display( struct node *p)
	{ while(p!=NULL)
	{
		cout<<" "<<p->data;
		p=p->next;
	}
	}
void insert(struct node *p, int x)
{
	struct node *t,*q=0;
	t= new node;
	t->data=x;
	t->next=NULL;
	if(first==NULL)
	{
		first=t;
	}
	else
	{
		while(p&&p->data<=x)
		{
			q=p;
			p=p->next;
		}
		if(p==first)
		{
			t->next=first;
			first=t;
		}
		else
		{
			t->next=q->next;
			q->next=t;
		}
	}
}

void del(struct node *p,int n)
{
	struct node *d;
	int v;
	
	//to del the first node
	//move the first node to next
	//then use other pointer to del it
	//Store data of the node
	if(n==1)
	{
	first=first->next;
	int x=p->data;
	delete p;
	}
	else
	{
	for(int i=1;i<n;i++)
	{
		d=p;
		p=p->next;
	}
	d->next=p->next;
	v=p->data;
	delete p;
	}
}
void removedupli(struct node *p)
{
	struct node *r;
	r=p->next;
while(r!=NULL)
{
	if(r->data!=p->data)
	{
		p=r;
		r=r->next;
	}
	else
	{	
		p->next=r->next;
		
		delete r;
		r=p->next;
	
	}	
}
}
void reverse(struct node *p)
{	
struct node *r,*q;
q=p;
r=q->next;
p->next=NULL;
while(r!=NULL)
{
	q=r;
	r=r->next;
	q->next=p;
	p=q;
}
first=p;
}
void dappend(struct node *p,struct node *q)
{
	struct node *a;
	a = new node;
	a->next=NULL;
	a->data=0;
	a->back=NULL;
	
	a=p->next;
	while(a->next!=NULL)
	{
		a=a->next;
	}
	a->next=q;
	q->back=a;
}
void append(struct node *p,struct node *q)
{
	struct node *a;
	
	a = new node;
	a->next=NULL;
	a->data=0;
	a=p->next;
	while(a->next!=NULL)
	{
		a=a->next;
	}
	a->next=q;
	
}
void cheakloop(struct node *p)
{
	int flag=-1;
	struct node *q;
	
	q=p;
	do
	{
		p=p->next;
		q=q->next;
		q=q->next;
		if(q->next==NULL)
		{
			cout<<"!!  linear list  !!";
			flag=1;
		}
		if(q->next==p->next)
		{
			cout<<"((  looped list  ))";
			flag=1;
		}
	}while(flag==-1);
}
void doublecreate(int b[],int n)
{
	struct node *d, *lastd;
	firstd = new node;
	firstd->back=NULL;
	firstd->next=NULL;
	firstd->data=b[0];
	lastd=firstd;
	for(int i=1;i<n;i++)
	{
		d = new node;
		d->next=NULL;
		d->data=b[i];
		lastd->next=d;
		d->back=lastd;
		lastd=d;
		
	}
	
}
void ddoublecreate(int b[],int n)
{
	struct node *d, *lastd;
	firsttd = new node;
	firsttd->back=NULL;
	firsttd->next=NULL;
	firsttd->data=b[0];
	lastd=firsttd;
	for(int i=1;i<n;i++)
	{
		d = new node;
		d->next=NULL;
		d->data=b[i];
		lastd->next=d;
		d->back=lastd;
		lastd=d;
		
	}
}
void doubledel(struct node *p,int n)
{
	struct node *d;
	for(int i=1;i<n-1;i++)
	{
		p=p->next;
	}
	d=p->next;
	p->next=d->next;
	int x=d->data;
	cout<<x<<"  is deleted";
	d->next->back=p;
	delete d;
}
void crebyinsert(int x)
{
	struct  node *p,*last;
	
	if(first==NULL)
	{
		first = new node;
		first->next=NULL;
		first->data=x;
		last=first;
	}
	else
	{
		p = new node;
		p->next=NULL;
		p->data=x;
		last->next=p;
		last=p;
	}
}
void choiceinsert(struct node *p,int n,int x)
{
	struct node *q,*t;
	t= new node;
	t->next=NULL;
	t->data=x;
	if(n==1)
	{
		t->next=p;
		first=t;
	}
	else
	{
	for(int i=1;i<n;i++)
	{
		q=p;
		p=p->next;
	}
	q->next=t;
	t->next=p;
	}

}
void linked1(int n )
{
	int b[n];
	for(int i=0;i<n;i++)
	{
		cout<<" enter element : ";
		cin>>b[i];
	}
	create(b,n);
}
void linked6(int n)
{
	int b[n];
	for(int i=0;i<n;i++)
	{
		cout<<" enter element : ";
		cin>>b[i];
	}
	createe(b,n);
	append(first,firstt);
}
void dlinked1(int x)
{
	int a[x];
	for(int i=0;i<x;i++)
	{
		cout<<" enter element : ";
		cin>>a[i];
	}
	doublecreate(a,x);
}
void dlinked6(int n)
{
		int b[n];
	for(int i=0;i<n;i++)
	{
		cout<<" enter element : ";
		cin>>b[i];
	}
	ddoublecreate(b,n);
	dappend(firstd,firsttd);
}
void dchoiceinsert(struct node *p,int x,int n)
{

struct node *q,*t;
	t= new node;
	t->next=NULL;
	t->back=NULL;
	t->data=x;
	if(n==1)
	{
		t->next=p;
		t->back=NULL;
		first=t;
	}
	else
	{
	for(int i=1;i<n;i++)
	{
		q=p;
		p=p->next;
	}
	q->next=t;
	t->back=q;
	t->next=p;
	p->back=t;
	
	}
	
}	
void dinsert(struct node *p, int x)
{
	struct node *t,*q=0;
	t= new node;
	t->data=x;
	t->next=NULL;
	t->back=NULL;
	if(firstd==NULL)
	{
		firstd=t;
	}
	else
	{
		while(p&&p->data<=x)
		{
			q=p;
			p=p->next;
		}
		if(p==firstd)
		{
			t->next=firstd;
			t->back=NULL;
			firstd=t;
		}
		else
		{
			t->next=q->next;
			q->next=t;
			t->back=q;
			q->next->back=t;
		}
	}
}
void dremovedupli(struct node *p)
{
	struct node *r;
	r=p->next;
while(r!=NULL)
{
	if(r->data!=p->data)
	{
		p=r;
		r=r->next;
	}
	else
	{	
		p->next=r->next;
		r->next->back=p;
		delete r;
		r=p->next;
	
	}	
}
}
void dreverse(struct node *p)
{	
	struct node *r,*q;
q=p;
r=q->next;
p->next=NULL;
while(r!=NULL)
{
	q=r;
	r=r->next;
	q->next=p;
	p->back=q;
	p=q;
}
firstd=p;
}
int main()
{
	int c,e,j,i;
	char ch,flag;
	cout<<"want to create singly linked list OR doubly linked list (s/d) : ";
	cin>>ch;
	if(ch=='s')
	{
	cout<<"creating linked list !!!!!!!"<<endl<<endl;
	cout<<"no of elements to be entered ";
	cin>>i;
	linked1(i);
	cout<<"linked list created : ";
	display(first);
	cout<<"\n";
	do
	{
	cout<<"1. to enter the value in linked list at choice "<<endl;
	cout<<"2. to enter the value sorted in (sorted linked list)"<<endl;
	cout<<"3. to delete an element"<<endl;
	cout<<"4. to remove duplicates from list"<<endl;
	cout<<"5. to reverse the list "<<endl;
	cout<<"6. to create new list and append it "<<endl;
	cout<<"7. to cheak if the list is looped or not"<<endl;
	cout<<"Enter the choice :";
	cin>>c;
	switch (c)
	{
		
		
		case 1: cout<<"enter the value to be entered: ";
				cin>>i;
				cout<<"enter the position to be entered: ";
				cin>>j;
				choiceinsert(first,j,i);		
				break;
				
		case 2: cout<<"enter the value to be entered ";
				cin>>i;
				insert(first,i);
				break;
		
		case 3: cout<<"enter the position to be deleted ";
				cin>>i;
				del(first,i);
				break;
		
		case 4: cout<<"removing duplicates!! "<<endl;
				removedupli(first);
				break;
				
		case 5: cout<<"reversing list!! "<<endl;
				reverse(first);
				break;
		
		case 6: cout<<"no of values to be entered ";
				cin>>i;
				linked6(i);	
				break;
		
		case 7: cheakloop(first);	
				
		default : cout<<"invalid value ";
				  break;
	}
	cout<<"linked list :";
	display(first);
	cout<<"\n want to go back to menu?(y/n) ";
	cin>>flag;
}while(flag=='y');
}
else
{
	cout<<"creating doubly linked list !!!!!!!"<<endl<<endl;
	cout<<"no of elements to be entered ";
	cin>>i;
	dlinked1(i);
	cout<<"linked list created : ";
	display(firstd);
	cout<<"\n";
	do
	{
	cout<<"1. to enter the value in linked list at choice "<<endl;
	cout<<"2. to enter the value sorted in (sorted linked list)"<<endl;
	cout<<"3. to delete an element"<<endl;
	cout<<"4. to remove duplicates from list"<<endl;
	cout<<"5. to reverse the list "<<endl;
	cout<<"6. to create new list and append it "<<endl;
	cout<<"7. to cheak if the list is looped or not"<<endl;
	cout<<"Enter the choice :";
	cin>>c;
	switch (c)
	{
		case 1: cout<<"enter the value to be entered: ";
				cin>>i;
				cout<<"enter the position to be entered: ";
				cin>>j;
				dchoiceinsert(firstd,i,j);		
				break;
				
		case 2: cout<<"enter the value to be entered ";
				cin>>i;
				dinsert(firstd,i);
				break;
		
		case 3: cout<<"enter the position to be deleted ";
				cin>>i;
				doubledel(firstd,i);
				break;
		
		case 4: cout<<"removing duplicates!! "<<endl;
				dremovedupli(firstd);
				break;
				
		case 5: cout<<"reversing list!! "<<endl;
				dreverse(firstd);
				break;
		
		case 6: cout<<"no of values to be entered ";
				cin>>i;
				dlinked6(i);	
				break;
		
		case 7: cheakloop(first);	
				
		default : cout<<"invalid value ";
				  break;
		
	}
	
	cout<<"linked list :";
	display(firstd);
	cout<<"\n want to go back to menu?(y/n) ";
}while(flag=='y');
}

	
	return 0;
}
