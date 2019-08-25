// 2048游戏是一个4*4的矩阵，用户可以按上下左右4个方向键让所有
// 的方块向同一个方向运动，两个相同数字方块撞一起之后合并成为
// 它们的和，每次操作之后随机生成一个2或4

// 合并规则：相邻会碰撞的两个数字合并且一个位置只会触发一次合并，
// 且优先合并移动方向顶部的位置
// 比如【2 2 2 2】行向右合并为【0 0 4 4】
// 【0 2 2 2】行向右合并为【0 0 2 4】

// 输入描述：
// 输入第一行是用户按下的方向键，1代表上，2代表下，3代表左，4代表右
// 接下来是一个4*4的矩阵，空格分割，0代表该位置没有数字
// 输出描述：
// 输出用户按下该方向键后的矩阵数值，忽略堆积产生数字

// 示例1
// 输入
// 1
// 0 0 0 2
// 0 0 0 2
// 0 0 4 8
// 输出
// 0 0 8 4
// 0 0 0 16
// 0 0 0 0
// 0 0 0 0

// 示例2
// 输入
// 2
// 0 0 0 0
// 0 0 2 2
// 0 2 8 8
// 2 4 2 16
// 输出
// 0 0 0 0
// 0 0 2 2
// 0 2 8 8
// 2 4 2 16

//向左合并，4*4方格
function test(arr) {
    //剔除其中为0的数
    for (let i = 0; i < arr.length;) {
        if (arr[i] == 0) {
            arr.splice(i, 1);
        } else {
            i++;
        }
    }
    //合并
    for (let j = 0; j + 1 < arr.length; ++j) {
        if (arr[j] == arr[j + 1]) {
            arr[j] = 2 * arr[j];
            arr.splice(j + 1, 1);
        }
    }
    //补0
    let num = arr.length;
    while (num < 4) {
        arr.push(0);
        num++;
    }
    return arr;
}
let dir = 1;
let qipan = [[0, 0, 0, 2], [0, 0, 0, 2], [0, 0, 4, 8], [0, 0, 4, 8]];
let dir1 = 2;
let qi = [[0, 0, 0, 0], [0, 0, 2, 2], [0, 2, 8, 8], [2, 4, 2, 16]];
function output(dir, qipan) {
    let temp = [];
    let res = [];
    if (dir == 3) {//左
        for (let m = 0; m < qipan.length; ++m) {
            res.push(test(qipan[m]));
        }
    } else if (dir == 4) {//右
        for (let m = 0; m < qipan.length; ++m) {
            res.push(test(qipan[m].reverse()).reverse());
        }
    } else if (dir == 1) {//上
        //新棋盘
        let newqipan = [[], [], [], []];
        for (let m = 0; m < qipan.length; ++m) {
            for (let n = 0; n < qipan[m].length; ++n) {
                newqipan[m][n] = qipan[n][m];
            }
        }
        for (let q = 0; q < newqipan.length; ++q) {
            temp.push(test(newqipan[q]));
        }
        res = [[], [], [], []];
        for (m = 0; m < temp.length; ++m) {
            for (n = 0; n < temp[m].length; ++n) {
                res[m][n] = temp[n][m];
            }
        }
    } else if (dir == 2) {//下
        //新棋盘
        let newqipan = [[], [], [], []];
        for (let m = 0; m < qipan.length; ++m) {
            for (let n = 0; n < qipan[m].length; ++n) {
                newqipan[m][n] = qipan[n][m];
            }
        }
        for (let q = 0; q < newqipan.length; ++q) {
            temp.push(test(newqipan[q].reverse()).reverse());
        }
        res = [[], [], [], []];
        for (m = 0; m < temp.length; ++m) {
            for (n = 0; n < temp[m].length; ++n) {
                res[m][n] = temp[n][m];
            }
        }
    }
    return res;
}
console.log(output(dir, qipan));
console.log(output(dir1, qi));