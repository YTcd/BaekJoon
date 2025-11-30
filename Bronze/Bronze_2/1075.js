let fs = require("fs");
let input = fs.readFileSync("./input.txt").toString().split("\n");
const N = BigInt(input[0]);
const F = BigInt(input[1]);

const shortF = input[1];

const numberToString = N + "";
const intNumber = numberToString.slice(0, -2) + "00";
const bigInt = BigInt(intNumber);

const remainder = bigInt % F;
const numberRemainder = Number(F - remainder);
let answer =
  numberRemainder > 10 ? numberRemainder + "" : "0" + numberRemainder;

if (answer == shortF) {
  answer = "00";
}
console.log(answer);
