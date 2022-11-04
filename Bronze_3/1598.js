let fs = require('fs');
let input = fs.readFileSync("./input.txt").toString().split(" ");

number1 = { x: 0, y: 0 };
number2 = { x: 0, y: 0 };
number1.x = parseInt((parseInt(input[0]) - 1) / 4);
number1.y = ((input[0] - 1) % 4);
number2.x = parseInt((parseInt(input[1]) - 1) / 4);
number2.y = ((input[1] - 1) % 4);
console.log(Math.abs(number1.x - number2.x) + Math.abs(number1.y - number2.y));
