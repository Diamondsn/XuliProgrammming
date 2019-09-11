function test(m,n){
   if(m>n){
       [m,n]=[n,m];
   }
   if(m==n){
       return 0;
   }else{
       let count=m^(m+1);
       for(let i=m+2;i<=n;++i){
           count^=i;
       }
       return count;
   }
}

function compute(m){
    if(m%4==1){
        return 1;
    }else if(m%4==2){
        return m+1;
    }else if(m%4==3){
        return 0;
    }else{
        return m;
    }
}
function test1(m,n){
    if(m>n){
        [m,n]=[n,m];
    }
    if(m==n){
        return 0;
    }else if(m==1){
        return compute(n);
    }else{
        let res1=compute(m-1);
        let res2=compute(n);
        return res1^res2;
    }
}

// console.log(test(2,4));
console.log(test1(7,1000000000000));