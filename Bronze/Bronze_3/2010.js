let fs = require('fs');
let input = fs.readFileSync("./input.txt").toString().trim().split("\n");
console.log(input);
let sum = 1;
for (let i = 1; i < input.length; i++) {
    sum += parseInt(input[i]);
}
console.log(sum - input[0]);