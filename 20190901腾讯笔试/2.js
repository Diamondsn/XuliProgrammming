#!/usr/bin/env node
const buff = [];

function howManyDaysAreThereInFebruary(year) {
    // TODO
    let days;
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        days = 29;
    else
        days = 28;
    return days;
}

process.stdin.on('data', (data) => {
    buff.push(data)
});

process.stdin.once('end', () => {
    const input = Buffer.concat(buff).toString('UTF-8');

    const res = howManyDaysAreThereInFebruary(input);

    console.log(res);
});

console.log(howManyDaysAreThereInFebruary(2019));