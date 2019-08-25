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