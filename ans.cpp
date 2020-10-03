#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int size[1000001],Arr[1000001];
 map<int,int>mp;
int n;
    int root (int i)
    {
        while(Arr[ i ] != i)
        {
            Arr[ i ] = Arr[ Arr[ i ] ] ; 
    i = Arr[ i ]; 
        }
    return i;
    }
void print(){
    for(int i=0;i<n;i++){
        // cout<<" rt "<<root(i)<<" "<<i<<endl;
        mp[root(i)]++;
    }
    //vector<int> vv;
    //for(auto it : mp)vv.push_back(it.second);
   // sort(vv.begin(),vv.end());
    //for(auto it1:vv)cout<<it1<<" ";cout<<endl;
}
void weightedunion(int A,int B)
    {
        int root_A = root(A);//argument difference error
        int root_B = root(B);
        if(size[root_A] < size[root_B ])
        {
    Arr[ root_A ] = Arr[root_B];
    size[root_B] += size[root_A];
    }
        else
        {
    Arr[ root_B ] = Arr[root_A];
    size[root_A] += size[root_B];
    }
//print();
    }
int main()
{
    int m,i,j,k;
    cin>>n>>m;
    int a[n+1]={0},b[n+1]={0},c[n+1]={0};
for(i=0;i<n;i++)
{
size[i]=1;
Arr[i]=i;
}
    for(i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
      weightedunion(x-1,y-1);
 
    }
/*for(i=0;i<n;i++)
cout<<Arr[i]<<" "<<"\n";*/
print();
for(i=0;i<n;i++)
{
cout<<mp[root(i)]-1<<" ";
}
}