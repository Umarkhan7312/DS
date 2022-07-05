#include<iostream.h>
#include<conio.h>
#include<string.h>
class merge
{
  int a[10],b[10],i,j,n,x;
  public:
  void get();
  void disp();
  void sort(int,int);
  void merge1(int,int,int);
};
void merge::get()
{
 cout<<"\nEnter size : ";
 cin>>n;
 for(i=1;i<=n;i++)
 cin>>a[i];
 sort(1,n);
}
void merge::sort(int l, int h)
{
 if(l<h)
 {
  int m = int((l+h)/2);
  sort(l,m-1);
  sort(m+1,h);
  merge1(l,m,h);
 }
}
void merge:: merge1(int l,int m,int h)
{
 int i=l,k=l,j=m+1;
 while((i<=m)&&(j<=h))
 {
   if(a[i]<=a[j])
   {
     b[k]=a[i];
     i++,k++;
   }
   else
   {
     b[k]=a[j];
     j++,k++;
   }
 }
 while(i<=m)
 {
   b[k]=a[i];
   i++,k++;
 }
 while(j<=h)
 {
   b[k]=a[j];
   j++;k++;
 }
 for(int kl=l;kl<=h;kl++)
 a[kl]=b[kl];

}
void merge::disp()
{
 for(i=1;i<=n;i++)
 cout<<a[i]<<"\t";
}
void main()
{
 clrscr();
 merge m;
 m.get();
 m.disp();
 getch();
}