function find(arr, target) {
}

find([1,2,3,4,5], 9) // [[3,4]]
find([1,2,3,4,5], 19) // null




function find(arr,target){
    let result=[];
    for(let i=0;i<arr.length;++i){
        for(let j=i+1;j<arr.length;++j){
            if(arr[i]+arr[j]===target){
                result.push([i,j]);
            }
        }
    }
    return result.length>0?result:null;
}

function find2(arr,target){
    let obj={};
    let result=[];
    for(let i=0;i<arr.length;++i){
        if(obj[arr[i]]){
            obj[arr[i]].push(i);
        }else{
            obj[arr[i]]=[i];
        }
    }
    for(let j=0;j<arr.length;++j){
        if(obj[target-arr[j]]){
            for(let k=0;k<obj[target-arr[j]].length;++k){
                if(obj[target-arr[j]][k]>j){
                    result.push([j,obj[target-arr[j]][k]]);
                }
            }
        }
    }
    return result.length>0?result:null;
}
console.log(find([1,2,3,4,5],9));
console.log(find([1,2,3,4,5],19));
console.log(find2([1,2,3,4,5],19));