// 在漫天的星空里散落着一些糖果，它们各有各的甜度。有一些糖果之间
// 会按照一定的规则有桥梁链接。好让你获得了这个糖果之后，可以去
// 获得和该糖果相连的其他糖果。现在你要选择一个糖果开始，去尽
// 可能的得到更多糖果。
// 我们将糖果一一编号1，2，3，4，...n,每一个糖果的甜度记为a[n]。
// 若糖果i和糖果j的甜度的最大公约数>1，则糖果i和糖果j之间有桥梁连接。

// 输入描述
// 首先输入一个数字n表示天上有n个糖果
// 接下来一行有那个数字，表示各个糖果的甜度
// 输出描述：
// 输出一个数，表示最多能获得多少个糖果

// 示例1
// 输入
// 6
// 20 50 22 74 9 63
// 输出
// 4
// 说明
// 各个糖所构造出的图如下
// 因为20 50 22 74两两之间至少有公约数2，所以两两之间有边
// 9和63的最大公约数=9，所以9和63有边
// 其他的数之间公约数均为1，所以没有边

// 备注
// 70%的数据 n<1000 ai<20000
// 100%的数据 n<20000 ai<200000

function test(arr) {
    let res = [];
    for (let i = 0; i < arr.length; ++i) {
        for (let j = i+1; j < arr.length; ++j) {
            if (gongyueshu(arr[i], arr[j]) > 1) {
                let count1 = -1, count2 = -1;
                for (let k = 0; k < res.length; ++k) {
                    if (res[k].indexOf(i) >= 0) {
                        count1 = k;
                    }
                    if (res[k].indexOf(j) >= 0) {
                        count2 = k;
                    }
                }
                if (count1 == -1 && count2 == -1) {
                    res.push([i, j]);
                } else if ((count1 == -1 && count2 >= 0) || (count1 >= 0 && count2 == -1)) {
                    let choose = count1 >= 0 ? count1 : count2;
                    let choosenum = count1 >= 0 ? j : i;
                    res[choose].push(choosenum);
                } else {
                    if (count1 != count2) {
                        let del = res.splice(count1, 1);
                        res[count2 - 1] = [res[count2 - 1], ...del];
                    }
                }
            }
        }
    }
    console.log(res);
    let count=0;
    for(let q=0;q<res.length;++q){
        if(res[q].length>count){
            count=res[q].length;
        }
    }
    return count;
}

function gongyueshu(num1, num2) {
    let t;
    if (num1 < num2) {
        [num1, num2] = [num2, num1];
    }
    while (t = num1 % num2) {
        num1 = num2;
        num2 = t;
    }
    return num2;
}

let arr=[20,50,22,74,9,63];
console.log(test(arr));