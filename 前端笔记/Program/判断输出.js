var a=10;
function b(){
    a=1;
    return;
    function a(){}
}
b();
console.log(a);//10