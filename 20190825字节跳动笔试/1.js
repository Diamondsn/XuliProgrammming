// 抖音上每天都有几亿用户，如果用户A和B互动不少于3次，我们就认为
// A和B属于“豆油”，如果A和B是“豆油”，B和C也是“豆油”，那么A和C也
// 互为“豆油”，我们定义“豆油”就是由直系和间接朋友所组成的群体。

// 给定一个M*N的矩阵M，代表抖音上所有用户的互动次数，如果
// M[i][j]=5，那么第i个和第j个用户就互动过5次，为0的话代表没有互动。
// 其中，对于i=j，即同一个用户，互动次数women计为0。请你计算并输出发现
// 的抖音上所有“豆油瓶”的个数。

// 例子1
// 输入：
// 3
// 0 4 0
// 4 0 0
// 0 0 0
// 输出：2
// 解释：第一个和第二个用户互动超过3次，互为豆油，第3个学生和其他人没有
// 互动，自成一个“豆油瓶”，所以结果为2

// 例子2
// 输入：
// 3
// 0 4 0
// 4 0 6
// 0 6 0
// 输出：1
// 解释：第1个和2个用户互动超过3次，互为豆油，第2个和第3个用户也互为
// 豆油，所有1和3互为间接豆油，三个用户都在同一个豆油瓶里，返回1.

// N的范围为[1,200]
// 所有学生自己对自己都是1，即M[i][j]=1，
// 如果M[i][j]=1，那么M[i][j]=1。

// 输入描述：
// 输入第1行：而为数组的行数（列数一样）N
// 接下来的N行：每行N个数字，空格分割
// 输出描述：
// 输出发现的“豆油瓶”数量k

// 示例1
// 输入
// 3
// 0 4 0
// 4 0 0
// 0 0 0
// 输出
// 2

// 示例2
// 输入
// 3
// 0 4 0
// 4 0 6
// 0 6 0
// 输出
// 1

function test(arr) {
    let count = 0;
    let res = [];
    for (let i = 0; i < arr.length; ++i) {
        for (let j = 0; j < arr[i].length; ++j) {
            if (i == j) continue;
            if (arr[i][j] >= 3) {
                //i 和j是绑定的，此时轮训res中的所有数组，如果i和j有一个在数组中，直接将另一个放进去，
                //如果i 和j两个在不同的数组，则直接合并这两个数组
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
                    if(count1!=count2){
                    let del = res.splice(count1, 1);
                    res[count2 - 1] = [res[count2 - 1], ...del];
                    }
                }
            }
        }
    }
    //获取res中的总人数；
    let a = 0;
    for (let m = 0; m < res.length; ++m) {
        a += res[m].length;
    }
    return arr.length - a + res.length;
}

arr=[["0","4","0"],["4","0","0"],["0","0","0"]];
console.log(test(arr));