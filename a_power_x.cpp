int M;
long long mod(long long x){
    return (((x%M)+M)%M);
}

long long mul(long long a, long long b){
    return mod(mod(a)*mod(b));
}

long long modPow(int x, int y){
    if(y==0) return 1LL;
    if(y==1) return mod(x);
    long long res=1;
    while(y){
        if(y%2==1)
            res=mul(res,x);
        x=mul(x,x);
        y/=2;
    }
    return res;
}

int Solution::pow(int x, int n, int d) {
    M=d;
    if(x==0)
        return 0;
    return modPow(x,n);
}
