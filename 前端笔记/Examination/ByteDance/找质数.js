var findPrimenum = function (N, M) {
    var arr = [];
    for (var i = N; i <= M; i++) {
		var k = Math.sqrt(j)
        for (var j = 2; j <= k; j++) {
            if (i % j === 0) {
                break;
            }
        }
        if (j >= k) {
            arr.push(i);
        }

    }
    return arr;
}
var res = findPrimenum(5, 100);
console.log(res);