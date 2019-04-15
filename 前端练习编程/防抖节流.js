//防抖
//https://www.cnblogs.com/momo798/p/9177767.html
var debounce=function(func,delay){
    let timer=null;
    return ()=>{
        clearTimeout(timer);
        timer=setTimeout(func,delay);
    }
}

window.addEventListener('scroll',debounce(function(){
    console.log("ok")
},1000));



//节流
var throttle = function (func, delay) {
    let timer = null;
    return () => {
        if (!timer) {
            timer = setTimeout(() => {
               func();
                timer = null;
            }, delay);
        }
    }
}

window.addEventListener('scroll', throttle(function () {
    console.log("ok")
}, 1000));