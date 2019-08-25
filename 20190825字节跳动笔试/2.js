function test(n){
    let arr=[];
    for(let i=0;i<n+1;++i){
        arr[i]=1;
    }
    // arr[4]=2;
    for(i=4;i<=n;i+=2){
        arr[i]=0;
        for(let j=1;j<=i;j+=2){
            arr[i]+=arr[j-1]*arr[i-j-1];
        }
    }
    return arr[n]%1000000007;
}

console.log(test(1000));