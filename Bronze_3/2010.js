let fs = require('fs');
let input = fs.readFileSync("./input.txt").toString().split("\n");

let sum = 0;
for (let i = 1; i < input.length; i++) {
    input[i] -= 1;
    sum += input[i];
}
console.log(sum - 1);