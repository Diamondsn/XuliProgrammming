/**
 * 第一题：实现 multiply
 * 要求：
 * multiply(1,2).result == 2
 * multiply(1,2)(3).result == 6
 * multiply(1,2)(3,4).result == 24
 * multiply(1,2)(3,4)(5).result == 120
 */

// 1错误解
// function multiply() {
//     var res={};
//     var result=1;
//     var args=Array.prototype.slice.call(arguments);
//     for(let i=0;i<args.length;++i){
//         result*=args[i];
//     }
//     return function(){
//         this.result=result;
//         var otherArgs=Array.prototype.slice.call(arguments);
//         multiply(otherArgs);
//     };
// }

// 2错误解
// function multiply(){
//     var result=1;
//     var args=Array.prototype.slice.call(arguments);
//     for(let i=0;i<args.length;++i){
//         result*=args[i];
//     }
//     return function(){
//         this.result=result;
//         var otherArgs=Array.prototype.slice.call(arguments);
//         return multiply(otherArgs);
//     };
// }
// multiply.prototype.result=1;

function multiply(){
    var result=1;
    var args = Array.prototype.slice.call(arguments);
    for (let i = 0; i < args.length; ++i) {
        result *= args[i];
    }
    var fn = function () {
        var otherArgs=Array.prototype.slice.call(arguments);
        return multiply(result,...otherArgs);
    }
    fn.result=result;
    return fn;
}

console.log(multiply(1,2)(3,4)(5).result);