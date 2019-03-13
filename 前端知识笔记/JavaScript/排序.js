//冒泡排序
var arr=[1,10,2,100,101,98];

function bubbleSort(arr){
    var len=arr.length,flag=null;
    if(len>1){
        for(var i=0;i<len-1;i++){
            flag=false;//位置变更标识符,可以优化性能
            for(var j=0;j<len-1-i;j++){
                if(arr[j]>arr[j+1]){//前一项如果大于后一项
                    //先存下前一项的值
                    var temp=arr[j];
                    //后一项的值赋给前一项
                    arr[j]=arr[j+1];
                    //前一项的值赋给后一项
                    arr[j+1]=temp;
                    flag=true;//有位置交换则改变flag的值
                }
            }
            if(!flag){//检测到上一轮已经没有位置变更,就说明排序已经完成
                break;
            }
        }
    }
    return arr;
}

console.log(bubbleSort(arr));//[1, 2, 10, 98, 100, 101]




//插入排序
var arr=[1,10,2,100,101,98,2];

function insertSort(arr){
    var len=arr.length;
    if(len>1){
        for(var i=1;i<len;i++){
            if(arr[i]<arr[i-1]){//当前项小于前一项的时候才向前插入
                var cur=arr[i],j=i-1;//保存第i项的值,找到前一项的索引
                while(j>=0 && cur<arr[j]){//前一项存在且第i的值小于前一项
                    arr[j+1]=arr[j];//当前比较项赋值为前一项的值
                    j--;//继续向前查找
                }
                arr[j+1]=cur;//将第i项插入到当前位置
            }
        }
    }
    return arr;
}
console.log(insertSort(arr));//[1, 2, 2, 10, 98, 100, 101]


//快速排序
var arr=[1,10,2,100,101,98,2];

function quickSort(arr){
    if(arr.length<=1){
        return arr;
    }
    var midIndex=Math.floor(arr.length/2);
    var minItem=arr.splice(midIndex,1)[0];
    var leftArr=[],rightArr=[];
    for(var i=0;i<arr.length;i++){
        var cur=arr[i];
        cur<minItem?leftArr.push(cur):rightArr.push(cur);
    }
    return quickSort(leftArr).concat(minItem,quickSort(rightArr));
}
console.log(quickSort(arr));//[1, 2, 2, 10, 98, 100, 101]

//快速排序另解
function quickSort(arr){
    if(arr.length<=1){
        return arr;//如果数组只有一个数，就直接返回；
    }

    var num = Math.floor(arr.length/2);//找到中间数的索引值，如果是浮点数，则向下取整

    var numValue = arr.splice(num,1);//找到中间数的值
    var left = [];
    var right = [];

    for(var i=0;i<arr.length;i++){
        if(arr[i]<numValue){
            left.push(arr[i]);//基准点的左边的数传到左边数组
        } else{
           right.push(arr[i]);//基准点的右边的数传到右边数组
        }
    }

    return quickSort(left).concat(numValue,quickSort(right));//递归不断重复比较
}

//阶乘
function factorial(n) {
    if (n === 1) return 1;
    return n * factorial(n - 1);
}


function factorial(n, total) {
    if (n === 1) return total;
    return factorial(n - 1, n * total);
}

factorial(5, 1)