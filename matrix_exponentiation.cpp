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
using ll = long long;
const ll LINF = 1e18;
#define REPI(e) for(int i=1;i<=e;i++)
#define REPJ(e) for(int j=1;j<=e;j++)
#define N 101
#define mod 1000000007
long long int A[N][N],I[N][N];
void printMat(long long int arr[][N],int dim){
  REPI(dim){ REPJ( dim){ cout<<arr[i][j]<<" ";}cout<<endl;}
}
void mul(long long int A[][N],long long int B[][N],int dim){
  long long int res[N][N];
  REPI(dim){ REPJ(dim) {res[i][j]=0;}}

  // normal matrix mul
  REPI(dim) {REPJ(dim) {
    res[i][j]=0;
    for(int k=1;k<=dim;k++){
        res[i][j] = ((res[i][j]%mod) + ((A[i][k])%mod*(B[k][j])%mod)%mod)%mod;
      
    }
    }
  }

  // copy back into a
 // printMat(res,dim);
  REPI(dim){ REPJ(dim) {A[i][j]=res[i][j];}}
  
  
}
void power(long long int arr[][N],int dim ,int n){
  // create I 
  REPI(dim) {REPJ(dim) {
    if(i==j){
      I[i][j]=1;
    }else{
      I[i][j]=0;
      
    }
    }
  }

  while(n>0){
    if(n%2){ /// n odd
      // res=res*a , n--
      mul(I,A,dim);
      n--;
      
      
    }else{
      // a=a*a , n=n/2
      mul(A,A,dim);
      n=n/2;
    }
  }

  //store back into arr
  REPI(dim){ REPJ(dim) {arr[i][j]=I[i][j];}}
}

int main()
{
  fast_io;
  freopen("input.txt","r",stdin);
  int t,dim,n;
  cin>>t;
  while(t--){
    cin>>dim>>n;
    REPI(dim){ REPJ(dim) {cin>>A[i][j];}}
    power(A,dim,n);
    printMat(A,dim);
    
    
  }

}
