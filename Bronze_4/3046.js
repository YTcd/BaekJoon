let fs = require('fs');
let input = fs.readFileSync("./input.txt").toString().split(" ");

console.log(input[1]-(input[0]-input[1]));