function test(n){
    let count=10000;
    for(let i=0;i<=Math.ceil(n/9);++i){
        for(let j=0;j<=Math.ceil(n/4);++j){
            if(i*9+j*4==n&&i+j<count){
                count=i+j;
            }
        }
    }
    return count==10000?-1:count;

}

function test1(n){
    let num9=Math.floor(n/9);
    for(let i=num9;i>0;--i){
        let left=n-i*9;
        if(left%4==0){
            return i+Math.floor(left/4);
        }
    }
    return -1;
}

console.log(test(13));