ck = function (fn, sn) {
    for (let i = 2n; i < sn; i++) {
        if (fn % i == 0n) {
            return "BAD " + i;
        }
    }
    return "GOOD";
}
let fs = require('fs');
let input = fs.readFileSync("./input.txt").toString().trim().split(" ");

let firstNumber = BigInt(input[0]);
let secondNumber = BigInt(input[1]);

console.log(ck(firstNumber, secondNumber));