

lli power(int a,int n,int d){
  lli res=1;
  
  while(n){
    if(n%2){
      res=(res*a)%d;
      n--;
      
    }else{
      a=(a*a)%d;
      n=n/2;
    }
  }
  return res;
  
}

lli gcd(int a,int b,int n){
     if(a==b){
    return (power(a,n,mod)+power(b,n,mod))%mod;
  }
  lli candidate=1;
  int num=abs(a-b);
  lli ans=1;
  for(int i=1;i*i<=num;i++){
    if(num%i==0){
      candidate=i;
      lli tmp=(power(a,n,candidate)+power(a,n,candidate))%candidate;
      if(tmp==0){
      ans=max(candidate,ans);
        }
  candidate=num/i; // if we iterate will sqrt(num) , if i*(num/i) =num , so from te factorisation we hav to check the other number also as candidate 
  // x*y =num => hav to check for x and y 
        tmp=(power(a,n,candidate)+power(a,n,candidate))%candidate;
      if(tmp==0){
      ans=max(candidate,ans);
        }
      
      }
  }
  return ans;
  
  
}

int main()
{
  fast_io;
  //freopen("input.txt","r",stdin);
  int t,a,b,n;
  cin>>t;
  while(t--){
    cin>>a>>b>>n;
    cout<<gcd(a,b,n)<<endl;
    
    
  }

}
