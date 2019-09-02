var arr = [[1, 3], [1, 1], [4, 1]];
function test(arr) {
    let result = 0;
    var len = arr.length;
    for (let i = 0; i < len - 1; i++) {
        for (let j = 0; j < len - 1 - i; j++) {
            if (count(arr[j][0], arr[j][1], j + 1, len) + count(arr[j + 1][0], arr[j + 1][1], j + 2, len) >
                count(arr[j + 1][0], arr[j + 1][1], j + 1, len) + count(arr[j][0], arr[j][1], j + 2, len)) {
                [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];
            }
        }
    }
    arr.forEach((item, index) => {
        result += count(item[0], item[1], index + 1, len)
    })
    return result;
}

function count(a, b, i, len) {
    return a * (i - 1) + b * (len - i)
}

console.log(test(arr));