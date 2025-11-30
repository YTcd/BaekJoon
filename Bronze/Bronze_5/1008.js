let fs = require('fs');
let input = fs.readFileSync("./input.txt").toString().split(" ");

const a = Number(input[0]) / Number(input[1]);

console.log(a);