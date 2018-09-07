// 题目描述
// 为 Array 对象添加一个去除重复项的方法

// 示例1
// 输入
// [false, true, undefined, null, NaN, 0, 1, {}, {}, 'a', 'a', NaN]
// 输出
// [false, true, undefined, null, NaN, 0, 1, {}, {}, 'a']

Array.prototype.uniq = function () {
    //20180906 11:14初解
    //此题在于排除NaN，注意NaN！==NaN，只要第一个NaN
    var newarr=[];
    var flag=true;
    this.forEach(function(a){
        if(a!==a){
              if(flag && newarr.indexOf(a)<0)
              {
                  newarr.push(a);
                  flag=false;
              }
        }
        else
        {
            if(newarr.indexOf(a)<0)
                newarr.push(a);
        }
    });
    return newarr;
}

//test
var arr=[false, true, undefined, null, NaN, 0, 1, {}, {}, 'a', 'a', NaN];
arr.uniq();
console.log(arr);