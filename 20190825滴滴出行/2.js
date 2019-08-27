// 题目描述：
// 给出一个仅包含加减乘除四种运算符的算式(不含括号)，如1+2*3/4，
// 在保持运算符顺序不变的情况下，现在你可以进行若干次如下操作：
// 如果交换相邻的两个数，表达式值不变，那么你就可以交换这两个数。

// 现在你可以进行任意次操作，使得算式的数字序列字典序最小，
// 然后输出结果，数字之间的字典序定义为若a<b则a的字典序小于b。

// 输入
// 第一行包含一个整数n，表示算式的长度，即包含n个数字和n-1个运算符。(1≤n≤100000)。

// 第二行包含一个含有n个非0整数和n-1个运算符的算式，整数与运算符用空格隔开，
// 运算符包括“+，-，*，/”，整数的绝对值不超过1000。

// 输出
// 按要求输出字典序最小的表达式，数字与符号之间用空格隔开。

// 样例输入
// 6
// 3 + 2 + 1 + -4 * -5 + 1
// 样例输出
// 1 + 2 + 3 + -5 * -4 + 1 

function test(arr) {
    let prev = 0, next = 0;
    let fuhao = arr[1];
    for (let i = 1; i < arr.length; i += 2) {
        if (i + 2 < arr.length && arr[i + 2] != arr[i]) {
            if ((fuhao == "+" && arr[i + 2] == "-") || (fuhao == "*" && arr[i + 2] == "/")) {
                next = i + 1;
            } else {
                next = i - 1;
            }
            if (fuhao == "+" || fuhao == "*") {
                swap(arr, prev, next);
            }
            if ((fuhao == "+" && arr[i + 2] == "-") || (fuhao == "*" && arr[i + 2] == "/")) {
                prev = next;
            } else {
                prev = next;
            }
            fuhao = arr[i + 2];
        }
    }
    return arr;
}

//将连续的几个值交换
function swap(arr, i, j) {
    //找出其中数字
    let myarr = [];
    for (let m = i; m <= j; m += 2) {
        myarr.push(arr[m]);
    }
    myarr.sort();
    for (let n = 0; n < myarr.length; ++n) {
        arr[i + n * 2] = myarr[n];
    }
}

let arr = [3, "+", 2, "+", 1, "+", -4, "*", -5, "+", 1]
console.log(test(arr));