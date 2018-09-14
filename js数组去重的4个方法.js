//数组去重的方法

//方法1:
//直接暴力轮询，在新数组中若未发现待添加元素，则添加
//此方法使用indexOf，较为耗时
Array.prototype.unique1=function(){
    var result=[];
    for(var i=0;i<this.length;++i)
    {
        if(result.indexOf(this[i])==-1)
            result.push(this[i]);
    }
    return result;
}

//方法2:
//建立哈希表，若在哈希表中未发现元素则添加到数组，同时在哈希表中添加
//此方法使用对象的下标进行查找速度较快，但新建了对象占用了更多空间
//此方法耗时少，占用空间多
Array.prototype.unique2=function(){
    var hash={};var result=[];
    for(var i=0;i<this.length;++i)
    {
        if(!hash[this[i]])
        {
            hash[this[i]]=true;
            result.push(this[i]);
        }
    }
    return result;
}

//方法3:
//如果第i位的元素第一次出现的位置不是i，那么为重复元素
//此方法使用indexOf查找，较为耗时
Array.prototype.unique3=function(){
    var result=[];
    for(var i=0;i<this.length;++i)
    {
       if(this.indexOf(this[i])==i)
          result.push(this[i]);
    }
    return result;
}

//方法4:
//此方法对数组排序后，如果待添加的元素跟结果数组的末尾元素不相同则添加元素
Array.prototype.unique4=function(){
    this.sort(function(a,b){
        return a-b;
    });
    //sort()方法接受一个函数
    // 若 a 小于 b，在排序后的数组中 a 应该出现在 b 之前，则返回一个小于 0 的值。
    // 若 a 等于 b，则返回 0。
    // 若 a 大于 b，则返回一个大于 0 的值。
    //console.log("排序后的数组"+this);
    var result=[this[0]];
     for(var i=1;i<this.length;++i)
     {
         if(this[i]!==result[result.length-1])
            result.push(this[i]);
     }
     return result;
}

//test
var arr=[10,2,3,6,7,8,9,10,2,5,4,3,2,6];
console.log(arr.unique1());
console.log(arr.unique2());
console.log(arr.unique3());
console.log(arr.unique4());
