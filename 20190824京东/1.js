// 最优打字策略
// 时间限制：C/C++语言 1000MS；其他语言 3000MS
// 内存限制：C/C++语言 65536KB；其他语言 589824KB
// 题目描述：
// 在英文的输入中，我们经常会遇到大小写切换的问题，频繁切换大小写会增加我们的按键次数，也会降低我们的打字效率。
// 众所周知，切换大小写有两种方式，一种是按下“caps locks”，也就是大写锁定键，这样一来，之后的输入模式都会被切换。另一种是同时按下shift和需要打印的字母，可以临时切换大小写(算作按下两个键)。
// 已知初始状态下，打字模式是小写，现在给出需要打印的字符串(区分大小写)，请你计算出最少需按键多少次才能打印出来。
// 输入
// 输入第一行仅包含一个正整数n，表示字符串的长度(1<=n<=1000000)。
// 输入第二行包含一个长度为n的字符串，仅包含大小写字母。
// 输出
// 输出仅包含一个正整数，即最少的按键次数。

// 样例输入
// 6
// AaAAAA
// 样例输出
// 8

// 规则
// 请尽量在全场考试结束10分钟前调试程序，否则由于密集排队提交，可能查询不到编译结果 
// 点击“调试”亦可保存代码
// 编程题可以使用本地编译器，此页面不记录跳出次数

let num=6;
let str="AaAAAA";
// function test(state,index,str){
//     const score=str.charCodeAt(index)
//     if(index==str.length-1){
//         if((state==0&&score>=97)||(state==1&&score<97)){
//             return 1;
//         }else{
//             return 2;
//         }
//     }
//    if(state==1&&score<97){
//        return 1+test(1,index+1,str);
//    }else if(state==0&&score<97){
//        return Math.min(2+test(0,index+1,str),2+test(1,index+1,str));
//    }else if(state==0&&score>=97){
//        return 1+test(0,index+1,str);
//    }else if(state==1&&score>=97){
//        return Math.min(2+test(0,index+1,str),2+test(1,index+1,str));
//    }
// }

// function test(str){
//   let count0=0,count1=0;
//   for(let i=0;i<str.length;++i){
//       if(str.charCodeAt(i)<97){
//           count1++;
//       }else{
//           count0++;
//       }
//   }
//   if(count0<=count1){
//       return str.length+1+count0;
//   }else{
//       return str.length+1+count1;
//   }
// }

// 动态规划
// 参考链接https://blog.csdn.net/sumword_/article/details/52798292
function test(n, a) {
    let dp = [];
    for (let i = 0; i < a.length; ++i) {
        dp.push([0, 0]);
    }
    if (a[0] >= 'a') {
        dp[0][0] = 1;
        dp[0][1] = 2;
    }
    else if (a[0] <= 'Z') {
        dp[0][0] = 2;
        dp[0][1] = 2;
    }
    for (let i = 1; i < a.length; i++) {
        if (a[i] >= 'a') {
            dp[i][0] = Math.min(dp[i - 1][0] + 1, dp[i - 1][1] + 2);
            dp[i][1] = Math.min(dp[i - 1][0] + 2, dp[i - 1][1] + 2);
        }
        if (a[i] <= 'Z') {
            dp[i][0] = Math.min(dp[i - 1][0] + 2, dp[i - 1][1] + 2);
            dp[i][1] = Math.min(dp[i - 1][0] + 2, dp[i - 1][1] + 1);
        }
    }
    return Math.min(dp[n - 1][0], dp[n - 1][1]);
}
console.log(test(num, str));
// console.log(str.charCodeAt(0));
// console.log(str.charCodeAt(1));