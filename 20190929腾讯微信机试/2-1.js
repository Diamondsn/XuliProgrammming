/**
 * 第二题：实现一个 superBaby:
 * 要求:
 * superBaby("tom") 输出: 
 * I am tom
 * 
 * superBaby("tom").sleep(10).eat("apple") 输出:
 * I am tom 
 * (等待10秒后输出)Start eating after 10 seconds
 * Eating apple
 *
 * superBaby("tom").sleepFirst(5).eat("banana")  输出:
 * (等待5秒后输出)Start eating after 10 seconds
 * I am tom 
 * Eating banana
 * 
 */

let index = 0;
let stack = [];
function next() {
    let fn = stack[index];
    index++;
    if (typeof fn === "function") {
        fn();
    }
}

function Baby(name) {
    stack.push(function () {
        console.log("I am " + name);
        next();
    });

}

var superBaby=function superBaby(name) {
    return new Baby(name);
}
Baby.prototype.sleep = function (time) {
    stack.push(function () {
        setTimeout(function () {
            next();
        }, time * 1000);
    });
    return this;
}
Baby.prototype.eat = function (time) {
    stack.push(() => { console.log("Eating " + str); next(); }, 1000 * time);
    return this;
}
Baby.prototype.sleepFirst = function (time) {
    stack.unshift(function () {
        setTimeout(function () {
            next();
        }, time * 1000);
    });
    return this;
}
superBaby("tom").sleepFirst(5).eat("banana");
