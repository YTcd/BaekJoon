let fs = require('fs');
let input = fs.readFileSync("./input.txt").toString().split("\n");
let ball = 1;
for (let i = 1; i < input.length; i++) {
    let arr = input[i].split(" ");
    if (arr[0] == ball) {
        ball = arr[1];
    } else if (arr[1] == ball) {
        ball = arr[0];
    }
}
console.log(ball);