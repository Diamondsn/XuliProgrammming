function test(str){
    let arr=str.split(" ");
    let obj={};
    for(let i=0;i<arr.length;++i){
         if(arr[i]!==' '||arr[i]!==','||arr[i]!=='.'||arr[i]!==''){
             if(obj[arr[i]]){
                 obj[arr[i]]++;
             }else{
                 obj[arr[i]]=1;
             }
         }
    }
    let max=0;
    let res=[];
    let count=[];
    for(item in obj){
        let key=item;
        let value=obj[key];
        if(value>max){
            res.length=0;
            count.length=0;
            res.push(key);
            count.push(value);
        }else if(value==max){
            res.push(key);
            count.push(value);
        }
        max=value>max?value:max;
    }
    return{word:res,time:count};
}

console.log(test("ab ab ab bc bc bc, . "));