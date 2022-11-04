judge = (sum) => {
    if (sum > 0) {
        console.log("+");
    } else if (sum < 0) {
        console.log("-");
    } else {
        console.log("0");
    }
}

let fs = require('fs');
let input = fs.readFileSync("./input.txt").toString().split("\n");
let sum = 0n;
let answerArr = [];
for (let i = 0; i < 3; i++) {
    answerArr.push(input.splice(0, parseInt(parseInt(input[0]) + 1)));
    for (let j = 1; j < answerArr[i].length; j++) {
        sum += BigInt(answerArr[i][j]);
    }
    judge(parseInt(sum));
    sum = 0n;
}