// 题目描述：
// 小米之家有很多米粉喜欢的产品，产品种类很多，价格也不同。比如某签字笔1元，某充电宝79元，某电池1元，某电视1999元等

// 假设库存不限，小明去小米之家买东西，要用光N元预算的钱，请问他最少能买几件产品？
// 输入
// 第1行为产品种类数
// 接下来的每行为每种产品的价格
// 最后一行为预算金额

// 输出
// 能买到的最少的产品的件数，无法没有匹配的返回-1

// 样例输入
// 2
// 500
// 1
// 1000
// 样例输出
// 2

function solution(prices, budget) {
    prices.sort((a, b) => b - a);
    let count = 0;
    for (let i = 0; budget > 0 && i < prices.length; ++i) {
        if (budget < prices[i]) {
            break;
        } else {
            count += Math.floor(budget / prices[i]);
            budget -= Math.floor(budget / prices[i]) * prices[i];
        }
    }
    return count == 0 ? -1 : count;
}

function solve(prices,budget,count){
    if (prices.length <= 0) {
        return 0;
    }

    if (budget % prices[0]==0) {
        return count + Math.floor(budget / prices[0]);
    } else {
        for (let i = Math.floor(budget / prices[0]); i >= 0; --i) {
            let newcount = count + Math.floor(budget / prices[0]);
            let newbudget = budget - Math.floor(budget / prices[0]) * prices[0];
            let res=solve(prices.slice(1), newbudget, newcount);
            if(res==0){
                continue;
            }else{
                return res+ Math.floor(budget / prices[0]);
            }
        }
        return 0;
    }
}

function solution1(prices, budget) {
    prices.sort((a, b) => b - a);
    let result=solve(prices,budget,0);
    return result==0?-1:result;
}

let prices=[500,1];
let budget=1000;
// console.log(solution(prices,budget));
console.log(solution1(prices,budget));