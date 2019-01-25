#include <iostream>
using namespace std;
class htable
{
    public:
    void create(int arr[],int hash[],int, int);
    int hasht(int,int);
    int rehashl(int,int);
};
int htable::hasht(int key,int tsize)
{
   return key%tsize;
}
int htable::rehashl(int key,int tsize)
{
  return (key+1)%tsize;
}
void htable::create(int arr[],int hash[],int n,int tsize)
{
int key,i;
for(int k=0;k<n;k++)
{
    key=arr[k];
    i=hasht(key,tsize);
    while(hash[i]!=-1)
    {
        i=rehashl(i,tsize);
    }
    hash[i]=key;
}
}
int main()
{
    htable h;
    int arr[20],hash[20],i,n,tsize ;
    cin>>tsize;
    cin>>n;
    for (i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for (i=0;i<tsize;i++)
    {
         hash[i]=-1 ;
    }
    h.create(arr,hash,n,tsize);

    for (i=0;i<tsize;i++)
    {
        cout<<i<<"  "<<hash[i]<<"\n";
    }
    return 0;
}
