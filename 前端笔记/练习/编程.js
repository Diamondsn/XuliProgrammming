// 一、数组去重

	

// 二、数组乱序


//三、多维数组转一维

   
//四、localStorge设置过期时间的方法


//五、如何判断动态脚本加载完成，可以对加载的js对象使用onload来判断 
	

//六、字符串反序
	

//七、夸浏览器事件处理程序


//八、深拷贝和浅拷贝

	
//九、千分位分隔符

	
//十、setTimeout输出0~9

	
//十一 JSONP
	
	
//十二 AJax

//十三、 bind实现
	
//十四、call实现
	
//十五、apply实现
	
//十六、单例模式
	

//十七、用js实现一个链表

//十八、快速排序
function quickSort(arr){
    if(arr.length<=1){
        return arr;
    }else{
        var left=[];
        var right=[];
        for(var i=1;i<arr.length;++i){
            if(left<=arr[0]){
                left.push(arr[i]);
            }else{
                right.push(arr[i]);
            }
        }
        return [].concat(quickSort(left),arr[0],quickSort(right));
    }
}
console.log(quickSort([9,8,7,6,5,4,3,2,1,10]));

//十九、归并排序
	// function mergeSort(arr){
    //     if(arr.length<=1)
    //     {
    //         return arr;
    //     }else{
    //         var mid=Math.floor(arr.length/2);
    //         var left=arr.slice(0,mid);
    //         var right=arr.slice(mid);
    //         return merge(mergeSort(left),mergeSort(right));
    //     }
    //     function merge(left,right){
    //         var a=[];
    //         while(left.length>0&&right.length>0){
    //             if(left[0]<right[0]){
    //                 a.push(left.shift());
    //             }else{
    //                 a.push(right.shift());
    //             }
    //         }
    //         return [].concat(a,left,right);
    //     }
    // }
    // console.log(mergeSort([9,8,7,6,5,4,3,2,1,10]));