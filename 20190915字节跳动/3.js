function test(arr) {
    let dp = [], sum = [];
    for (let i = 0; i <= arr.length; ++i) {
        dp.push([]);
        sum.push([]);
        for (let j = 0; j <= arr.length; ++j) {
            dp[i].push(0);
            sum[i].push(0);
        }
    }
    for (let i = 1; i <= arr.length; ++i) {
        sum[i][i] = arr[i - 1];
        dp[i][i] = arr[i - 1];
        for (let j = i + 1; j <= arr.length; ++j) {
            sum[i][j] = sum[i][j - 1] + arr[j - 1];
        }
    }
    for (let i = arr.length - 1; i > 0; i--) {
        for (let j = i; j <= arr.length; j++) {
            dp[i][j] = sum[i][j] - Math.min(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    console.log(sum);
    console.log(dp);
    return dp[1][arr.length];
}

console.log(test([1, 1, 1]));