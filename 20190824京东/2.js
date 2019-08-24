// 时间限制：C/C++语言 3000MS；其他语言 5000MS
// 内存限制：C/C++语言 131072KB；其他语言 655360KB
// 题目描述：
// 马上就要开学了，教务处的老师拿到了新生的名单，现在他需要根据考生的姓名录入一个拼音版的新名单。
// 老师录入时，需要输入姓和名(例如：ZHANG SAN，字母均为大写，姓名以空格隔开)，并且要将这些人按一定规则排序。
// 排序的方式如下：
// 首先，按照该姓的出现次数排序，即：姓出现次数多的人先排序
// 其次，若两个人的姓出现的次数一样多（或者是同一个姓），按照原名单的顺序。
// 输入
// 输入包括多行，每一行两个字符串，代表一个人的姓和名
// 输出
// 输出排序后的名单

// 样例输入
// ZHANG SAN
// LI SI
// WANG WU
// WANG LIU
// WANG QI
// ZHANG WU
// LI WU
// 样例输出
// WANG WU
// WANG LIU
// WANG QI
// ZHANG SAN
// LI SI
// ZHANG WU
// LI WU

// 提示
// 范围 
// 输入只包含大写字母，最多10000行，每行最多50个字符
// 规则
// 请尽量在全场考试结束10分钟前调试程序，否则由于密集排队提交，可能查询不到编译结果 
// 点击“调试”亦可保存代码
// 编程题可以使用本地编译器，此页面不记录跳出次数

function f(arr) {
    let a1 = [], a2 = [], a3 = [], i = 0;
    for (let name of arr) {
        let names = name.split(" ");
        let index = a1.indexOf(names[0]);
        if (index == -1) {
            a1[i] = names[0];
            a2[i] = 1;
            a3[i] = [name];
            i++;
        } else {
            a2[index]++;
            a3[index].push(name);
        }
    }
    let count = a1.length;
    let res = [];
    while (count--) {
        let i = Math.max(...a2);
        res.push(...a3[a2.indexOf(i)]);
        a2[a2.indexOf(i)] = -1;
    }
    return res;
}

let arr = [];
while (1) {
    let str = read_line();
    if (str) {
        arr.push(str);
    }
    else {
        break;
    }
}
let result = f(arr);
for (let i = 0; i < result.length; ++i) {
    printsth(result[i]);
}

const arr = ["ZHANG SAN",
    "LI SI",
    "WANG WU",
    "WANG LIU",
    "WANG QI",
    "ZHANG WU",
    "LI WU"];
console.log(f(arr));