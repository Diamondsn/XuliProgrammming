// 题目描述
// 用 JavaScript 实现斐波那契数列函数,返回第n个斐波那契数。 f(1) = 1, f(2) = 1 等

function fibonacci(n) {
    //20180906 12:15初解
    /*
    if(n===1)
        return 1;
    else if(n===2)
        return 1;
    else
        return fibonacci(n-1)+fibonacci(n-2);
    */
    
    //迭代方法引入过多重复计算以及函数跳转，消耗空间和时间资源
    var a=1;
    var b=1;
    var c;
    if(n===1)
        return a;
    else if(n===2)
        return b;
    else
    {
         while (n>2)
         {
             var temp=a+b;
             a=b;
             b=temp;
             n--;
         }
        return b;
    }
}

//test
console.log(fibonacci(1));
console.log(fibonacci(2));
console.log(fibonacci(3));
console.log(fibonacci(4));