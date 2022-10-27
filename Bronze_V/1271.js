let fs = require('fs');
let input = fs.readFileSync("./input.txt").toString().split(" ");

const a = parseInt(Number(input[0]) / Number(input[1]));
const b = Number(input[0] % Number(input[1]));

console.log(a);
console.log(b);