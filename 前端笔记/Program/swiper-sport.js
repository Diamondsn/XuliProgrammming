function startMove(obj,target,attr){
    clearInterval(obj.timer);
    obj.timer = setInterval(function(){
       var current = parseFloat(getStyle(obj,attr));
       var speed = 0;
       if(attr === 'opacity'){
          speed = target-current>0?0.1:-0.1;
       }else{
          speed = (target - current)/10; //
          speed = speed > 0 ? Math.ceil(speed) : Math.floor(speed);
       }
       
       if(target == current){
           clearInterval(obj.timer);
       }else{
        if(attr === 'opacity'){
          obj.style[attr] = current+speed;
        }else{
          obj.style[attr] = current+speed+'px';
        }
       }
    },20)
   }
//获取元素的属性
function getStyle(obj,attr){
if(window.getComputedStyle){
return window.getComputedStyle(obj,null)[attr];
}else{
return obj.currentStyle[attr];
}
}
//针对两种情况来进行一下整合