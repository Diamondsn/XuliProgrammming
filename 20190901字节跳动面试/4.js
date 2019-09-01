// 给定一个升序整形数组[0,1,2,4,5,7,13,15,16]，找出其中连续出现的数字区间为如下：
// - ["0->2", "4->5", "7", "13", "15->16"]

function test(arr) {
    if (arr.length < 1) return;
    let prev = arr[0];
    let next = arr[0];
    let result = [];
    for (let i = 1; i < arr.length; ++i) {
        if (arr[i] - next > 1) {
            if (next !== prev) {
                result.push(prev.toString() + "->" + next.toString());
            } else {
                result.push(next.toString());
            }
            prev = arr[i];
            next = arr[i];
        } else {
            next = arr[i];
        }
    }
    if (next !== prev) {
        result.push(prev.toString() + "->" + next.toString());
    } else {
        result.push(next.toString());
    }
    return result;
}
console.log(test([0, 1, 2, 4, 5, 7, 13, 15, 16]));