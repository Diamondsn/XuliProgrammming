let str1="1 2 3 4 5 6 7 8 9";
let str2="a b c";
function test(str1,str2){
    let arr1=str1.split(" ");
    let arr2=str2.split(" ");
    let res=[];
    while(arr1.length>=4&&arr2.length>=1){
        res.push(...arr1.splice(0,4));
        res.push(...arr2.splice(0,1));
    }
    res=[...res,...arr1,...arr2];
    return res;
}
let res=test(str1,str2);
console.log(res.join(" "));