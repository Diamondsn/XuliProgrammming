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