#!/usr/bin/env node
const buff = [];

function flatten(arr) {
  // TODO
    let result=[];
    for(let value of arr){
    if(Array.isArray(value)){
        result.push(...flatten(value));
    }else{
        result.push(value);
    }
    }
    return result;
}


process.stdin.on('data', (data) => {
    buff.push(data)
});

process.stdin.once('end', () => {
    const input = Buffer.concat(buff).toString('UTF-8');
    
    const res = flatten(JSON.parse(input));

    console.log(res);
});

console.log(flatten([1, 2, [3, 4], [5, 6, [7, [8], 9]]]));