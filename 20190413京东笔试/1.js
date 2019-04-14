function test(str) {
    var max = 0;
    var len = 0;
    for (var i = 0; i < str.length; ++i) {
        if (str[i] === "1") {
            len++;
        } else if (str[i] === "0") {
            if (len > max) {
                max = len;
            }
            len=0;
        }
    }
    if(len>max){
        max=len;
    }
    var arr = str.split("");
    for (i = 0; i< arr.length; ++i) {
        arr.unshift(arr.pop());
        len = 0;
        for (var j = 0; j < arr.length; ++j) {
            if (arr[j] === "1") {
                len++;
            } else if (arr[j] === "0") {
                if (len > max) {
                    max = len;
                }
                len=0;
            }
        }
        if(len>max){
            max=len;
        }
    }
    return max;
}

console.log(test("11011"));