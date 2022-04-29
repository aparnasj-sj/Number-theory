lli power(lli a,lli n,int m){
  lli res=1;
  while(n){
    if(n%2){// n odd
      res=(res*a)%m;
      n--;
      
    }else{
      a=(a*a)%m;
      n=n/2; // 2^8 can be simplified as (2^2)^4
      
    }
  }
  return res;
}
lli mul_inv(lli a,lli m){
  return power(a,m-2,m);
}
int main()
{
  fast_io;
  freopen("input.txt","r",stdin);
  int t,a,b,m;
  cin>>t;
  while(t--){
    cin>>a>>m;
    // a^-1 mod m  = a^m-2 mod m // fermats little theorm 
    cout<<mul_inv(a,m)<<endl;
    
    
    
  }

}
