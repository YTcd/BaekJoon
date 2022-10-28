let fs = require('fs');
let input = fs.readFileSync("./input.txt").toString().split("\n");
let count = input[0].split(" ");
for(let i = 1; i <= count[0]; i++){
    console.log(input[i].split("").reverse());
}