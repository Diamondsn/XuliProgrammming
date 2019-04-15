function test(str) {
    var max = 0;
    var len = 0;
    var index=str.lastIndexOf("0");
    var arr=str.split("");
    var t=arr.splice(index,arr.length-index);
    arr.splice(0,arr.length-index);
    arr=t.concat(arr);
    for (var i = 0; i < arr.length; ++i) {
        if (arr[i] === "1") {
            len++;
        } else if (arr[i] === "0") {
            if (len > max) {
                max = len;
            }
            len=0;
        }
    }
    if(len>max){
        max=len;
    }
    return max;
}

console.log(test("11011"));