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