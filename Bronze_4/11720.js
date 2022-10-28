let fs = require('fs');
let input = fs.readFileSync("./input.txt").toString().split("\n");
let number = input[1].split("");
let sum = 0;
for(let i of number){
    sum += Number(i);
}
console.log(sum);