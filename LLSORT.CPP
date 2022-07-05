#include<iostream.h>
#include<conio.h>
class node
{
  int info,x;
  node *link;
  public:
  void get();
  void disp();
  void sort();
  void del_pos();
  void del_info();
};
node *start=NULL,*next,*temp;


void node :: del_info()
{
 if(start==NULL)
 cout<<"Empty LL";
 else
 {
  cout<<"enter info: ";
  cin>>x;
  node *p;
  int f=0;
  if(start->info==x)
  {
   start=start->link;
   f=1;
  }
  temp=start;
   while(temp!=NULL)
   {
    p=temp;
    temp=temp->link;
    if(temp->info==x)
    {
     f=1;
     p->link=temp->link;
    }
   }
  if(f==0)
  cout<<"\nnot found";
  }
}

void node :: del_pos()
{
 if(start==NULL)
 cout<<"Empty LL";
 else
 {
  cout<<"enter pos : ";
  int pos,f=0,c=0;
  cin>>pos;
  node *p;
  if(pos==1)
  {
   start=start->link;
   f=1;
  }
  temp=start;
   while(temp!=NULL)
   {
    c++;
    p=temp;
    temp=temp->link;
    if(pos-1==c)
    {
     f=1;
     p->link=temp->link;
    }
   }
  if(f==0)
  cout<<"\nnot found";
  }
}
void node :: sort()
{
 node *t=start;
 int c=0;
 while(t!=NULL)
 {
  c++; // no. node find out
  t=t->link;
 }
 for(int j=1;j<=c;j++)
  for(t=start;t->link!=NULL;t=t->link)
   if(t->info>(t->link)->info)
   {
     int a=t->info;
     t->info=(t->link)->info;
     (t->link)->info=a;
   }
}
void node :: get()
{
 node *n1 = new node;
 cout<<"enter info : ";
 cin>>x;
 n1->info=x;
 n1->link=NULL;
 if(start==NULL)
 start=n1;
 else
 {
  next=start;
  while(next->link!=NULL)
  next=next->link;
  next->link=n1;
 }
}
void node :: disp()
{
 temp=start;
 int sum=0;
 cout<<"\nLL :";
 while(temp!=NULL)
 {
  cout<<"\t"<<temp->info;
  sum+=temp->info;
  temp=temp->link;
 }
 cout<<"\nsum : "<<sum;
}
void main()
{
 clrscr();
 node n;
 n.get();
 n.get();
 n.get();
 n.disp();
 n.sort();
 n.disp();
 n.del_pos();
 n.del_info();
 n.disp();
 getch();
}