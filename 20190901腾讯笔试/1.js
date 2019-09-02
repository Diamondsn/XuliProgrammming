function test(arr1,arr2){
    let ji1=0,ou1=0,ji2=0,ou2=0;
    for(let i=0;i<arr1.length;++i){
        if(arr1[i]%2){
            ou1++;
        }else{
            ji1++;
        }
    }
    for(let i=0;i<arr2.length;++i){
        if(arr2[i]%2){
            ou2++;
        }else{
            ji2++;
        }
    }
    return Math.min(ou1,ji2)+Math.min(ou2,ji1);
}

console.log(test([1,1],[1,1]));