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
            len = 0;
        }
    }
    if (len > max) {
        max = len;
    }
    if (max === str.length) {
        return max;
    }
    var i1 = str.indexOf("0");
    var i2 = str.lastIndexOf("0");
    //统计首末加起来的1个数
    if (i1 + str.length - i2 - 1 > max) {
        max = i1 + str.length - i2 - 1;
    }
    len = 0;
    for (i = i1; i < i2; ++i) {
        if (str[i] === "1") {
            len++;
        } else if (str[i] === "0") {
            if (len > max) {
                max = len;
            }
            len = 0;
        }
    }
    if (len > max) {
        max = len;
    }
    return max;
}

console.log(test("11011"));