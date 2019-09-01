function test(obj){
    return Array.isArray(obj);
}

function test1(obj){
    return Object.prototype.toString.call(obj)==="[Object Array]";
}

function test2(obj){
    return typeof obj==="object" && obj.__proto__ === Array.prototype;
}

console.log(test(null));
console.log(test({a:"1"}));
console.log(test([1,2,3]));