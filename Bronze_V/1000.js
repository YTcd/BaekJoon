let fs = require('fs');
let input = fs.readFileSync('../input.txt').toString().split('\n');

let numbers = [];

for (let i = 1; i < input.length; i++) {
    if (input[i] !== '') {
        numbers.push(input[i].split(' '));
    }
}

for (let i = 0; i < numbers.length; i++) {
    let num1 = Number(numbers[i][0]);
    let num2 = Number(numbers[i][1]);

    console.log(num1 + num2);
}