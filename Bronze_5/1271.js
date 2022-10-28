let fs = require('fs');
let input = fs.readFileSync("./input.txt").toString().split(" ");

let a = BigInt(input[0]);
let b = BigInt(input[1]);

console.log((a/b).toString());
console.log((a%b).toString());