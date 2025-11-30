let fs = require('fs');
let input = fs.readFileSync("./input.txt").toString().split(" ");
let width = input[2] - input[0] >= input[0] ? parseInt(input[0]) : input[2] - input[0];
let height = input[3] - input[1] >= input[1] ? parseInt(input[1]) : input[3] - input[1];
let answer = width > height ? height : width;
console.log(parseInt(answer));