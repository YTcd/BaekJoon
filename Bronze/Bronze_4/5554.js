let fs = require('fs');
let input = fs.readFileSync("./input.txt").toString().split("\n");
let sum = 0;
for(let i = 0; i<4; i++){
    sum += Number(input[i]);
}

console.log(parseInt(sum/60));
console.log(sum%60);