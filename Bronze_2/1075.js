let fs = require("fs");
let input = fs.readFileSync("./input.txt").toString().split("\n");
const N = BigInt(input[0]);
const F = BigInt(input[1]);

const quotient = Math.floor(N / F);
const remainder = N % F;
console.log(quotient + " asd " + remainder);
