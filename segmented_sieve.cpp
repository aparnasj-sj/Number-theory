#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define vi vector<int>
#define repi(s,e) for(int i=s;i<e;i++)
#define rep(j,s,e) for(int j=s;j<e;j++)
#define pb push_back
typedef pair<int, int> pii;
typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> o_set;
#define F 
#define sz(x) (int)(x).size()
#define S second
#define ppi pair<int,pair<int,int>>
multiset<int>low;
multiset<int>up;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

//const int  LINF = 1e18;
using lli = long long int ;
//const ll LINF = 1e18;
#define REPI(e) for(int i=1;i<=e;i++)
#define REPJ(e) for(int j=1;j<=e;j++)
#define N 1000000000
#define mod 1000000007
int primes[1000001];// all 0 
void sieve(vector<int> &prime){
  primes[1]=primes[0]=1;
  for(int i=2;i*i<=1000000;i++){
    if(!primes[i]){
      for(int j=i*i;j<=1000000;j+=i){
        primes[j]=1;
     
        
      }
    }
  }
  REPI(1000000){
    if(!primes[i]){
      prime.push_back(i);
    }
  }
  
  
}
int range[1000001];
void primes_range(lli l,lli r,vector<int> &prime){
  memset(range,0,1000001);
  //range[1]=range[0]1;
  if(l==1){range[0]=1;}
  for(auto p:prime){
    if(p*p<=r){
      lli start=(l/p)*p; // get last mutltiple of p just before or equal to L 
      if(start<l){
        start+=p;
        
      }
      for(lli j=start;j<=r;j+=p){
        //cout<<j<<endl;
        if(j!=p){ // lets say l =1 , (1/2)*2 =0 , so start ends uo being start=2
          // but since 2 itself prime don wanna update it right.
        range[j-l]=1;
          }
      }
      
    }
  }
  lli size=r-l+1;
  for(lli i=0;i<size;i++){
    if(range[i]==0){
      cout<<(i+l)<<endl;
    }
  }
//cout<<endl;
  
}
int main()
{
  fast_io;
  //freopen("input.txt","r",stdin);
  // a  primes till sqrt(N)
  vector<int>prime;
  
  long long int  t,l,r;
  cin>>t;
  sieve(prime);
  while(t--){
    cin>>l>>r;
   
  primes_range(l,r,prime);
    
    
    
  }

}
