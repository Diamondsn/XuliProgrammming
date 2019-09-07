function jiecheng(n) {
    var res = 1;
    for (var i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

function test(n, m) {
    var arr = [];
    for (let i = 0; i <= n; ++i) {
        let row = [];
        for (let j = 0; j <= m; j++) {
            row[j] = 0;
        }
        arr.push(row);
    }
    for (let i = 1; i <= n; ++i) {
        arr[1][i] = 1;
        arr[i][1] = i;
    }
    for (let i = 2; i <= n; ++i) {
        for (let j = 2; j <= m; ++j) {
            let sum = 0;
            for (let k = i; k >= 1; k--) {
                sum += arr[k][j - 1];
            }
            arr[i][j] = sum;
        }
    }
    return arr[n][m] % 1000000007;
}

function test1(n, m) {
    var arr = [];
    for (let i = 0; i <= n; ++i) {
        arr.push(new Array(m + 1));
    }
    for (let i = 1; i <= n; ++i) {
        arr[1][i] = 1;
        arr[i][1] = i;
    }
    for (let i = 2; i <= n; ++i) {
        for (let j = 2; j <= m; ++j) {
            arr[i][j] = (arr[i - 1][j] + arr[i][j - 1])% 1000000007;
        }
    }
    return arr[n][m] % 1000000007;
}

console.log(test1(1000, 1000));