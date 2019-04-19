//https://www.jianshu.com/p/c8b86b09daf0
//防抖
function debounce(fn,time){
    var timeid=null;
    return function(){
        if(timeid!==null){
            clearTimeout(timeid);
        }
        timeid=setTimeout(fn,time);
    }
}
var test=function(){
    console.log(Math.random())
};
window.addEventListener("scroll",debounce(test,1000));



//节流
function throttle(fn, time) {
   var timeid;
    return function () {
        var self = this;
        var args = arguments;
        if (!timeid) {
            timeid = setTimeout(function () {
                timeid = null;
                fn.apply(self, args);
            }, time);
        }
    }
}
var test=function(){
    console.log(Math.random())
};
window.addEventListener("scroll",throttle(test,1000));