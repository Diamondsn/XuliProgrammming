// 一、数组去重
// var arr=[... new Set(arr)];
	

// 二、数组乱序
// arr.sort(function(a,b){return Math.random>0.5?1:-1;})


//三、多维数组转一维
// var res=[];
// function trans(arr){
//   for(var i=0;i<arr.length;++i){
//       if(Array.isArray(arr)){
//           trans(arr[i]);
//       }else{
//           res.push(arr[i]);
//       }
//   }
// }

   
//四、localStorge设置过期时间的方法
// function set(key,value){
//     var curtime=new Date().getTime();
//     localStorage.setItem(key,JSON.stringify({data:value,time:curtime}));
// }
// function get(key,eps){
//     var data=localStorage.getItem(key);
//     data=JSON.parse(data);
//     if(new Date().getTime()-data.time>eps){
//         console.log("过期");
//         localStorage.removeItem(key);
//         return "";
//     }else{
//         return data.data;
//     }
// }


//五、如何判断动态脚本加载完成，可以对加载的js对象使用onload来判断 

	

//六、字符串反序
	// String.split("").reverse().join("");

//七、夸浏览器事件处理程序


//八、深拷贝和浅拷贝
// function deepClone(obj){
//     var newobj={};
//     for(key in obj){
//         if(typeof(obj[key])==="object"){
//             newobj[key]=deepClone(obj[key]);
//         }else{
//             newobj[key]=obj[key];
//         }
//     }
//     return newobj;
// }
// console.log(deepClone({a:1,b:{c:2}}));
	
//九、千分位分隔符
// function trans(num){
//     var arr=num.toString().split("").reverse();
//     var index=arr.indexOf(".");
//     var i=0;
//     if(index>=0){
//         i=index+4;
//     }else{
//         i=3;
//     }
//     for(;i<arr.length;i+=4){
//         arr.splice(i,0,",");
//     }
//     return arr.reverse().join("");
// }
// console.log(trans(123456789));
	
//十、setTimeout输出0~9
for(var i=0;i<10;++i){
    setTimeout(function(i){
        return function(){console.log(i)}
    }(i),i*1000);
}
	
//十一 JSONP
    // var dom=document.createElement("script");
    // dom.setAttribute("type","text/javascript");
    // dom.setAttribute("src","http:www.baidu.com?callback=callback");
    // document.body.appendChild(dom);
    // function callback(data){
    //     console.log(data);
    // }

	
//十二 AJax
// var xhr=new XMLHttpRequest();
// xhr.onreadystatechange=function(){
//     if(xhr.readyState==4){
//         if(xhr.status==200){
//             console.log(xhr.responseText);
//         }else{
//             console.log(xhr.status);
//         }
//     }
// }
// xhr.open("Get",url,bool);
// xhr.send(null);


//十三、 bind实现
	// Function.prototype.bind=function(context){
    //     var self=this;
    //     return function(){
    //         return self.apply(context,arguments);
    //     }
    // }
    // function test() {
    //     console.log(this.a);
    // }
    // test.bind({a:2});


//十四、call实现

// Function.prototype.call=function(context){
//     var self=this;
//     context.fn=self;
//     var args=[];
//     for(var i=1;i<arguments.length;++i){
//         args.push("arguments["+i+"]");
//     }
//     var result=eval("context.fn("+args+")");
//     delete context.fn;
//     return result;
// }

// function test() {
//     console.log(this.a);

// }
// test.call({ a: 2 }, 1, 2, 3);


//十五、apply实现
// Function.prototype.apply=function(content,a){
//     var self=this;
//     content.fn=self;
//     var args=[];
//     for(var i=0;i<a.length;++i){
//         args.push("a["+i+"]");
//     }
//     var result=eval("content.fn("+a+")");
//     delete content.fn;
//     return result;
// }

// function test(args){
//     console.log(this.a);
//     console.log(args);
//     console.log(typeof args);
//     console.log([].slice.call(arguments));
// }
// test.apply({a:2},[1,2,3])
	
//十六、单例模式
// var getSingle=function(){
//       var instance=null;
//       return function(){
//           if(!instance){
//               var a={m:1};
//               instance=a;
//           }
//               return instance;
          
//       }
// }()

// console.log(getSingle());

//十七、用js实现一个链表
// function List(){
//     function Node(){
//         this.value=1;
//         this.next=null;
//     }
//     this.head=null;
//     var current=null;
//     this.length=0;
//     this.append=function(){
//         var node=new Node();
//         if(this.head==null){
//             this.head=node;
//         }else{
//             current=this.head;
//             while(current.next){
//                 current=current.next;
//             }
//             current.next=node;
//         }
//         this.length++;
//     }
// }

// var list=new List();
// list.append();
// list.append();
// console.log(list.head);
// console.log(list.length);

//十八、快速排序
// function quickSort(arr){
//     if(arr.length<=1){
//         return arr;
//     }else{
//         var left=[];
//         var right=[];
//         for(var i=1;i<arr.length;++i){
//             if(arr[i]<=arr[0]){
//                 left.push(arr[i]);
//             }else{
//                 right.push(arr[i]);
//             }
//         }
//         return [].concat(quickSort(left),arr[0],quickSort(right));
//     }
// }
// console.log(quickSort([9,8,7,6,5,4,3,2,1,10]));

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