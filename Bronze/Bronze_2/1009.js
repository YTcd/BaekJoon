let fs = require('fs');
let input = fs.readFileSync("./input.txt").toString().split("\n");
const length = input[0];
for (let i = 1; i <= length; i++) {
    let arr = input[i].split(" ");
    let originNumber = arr[0] % 10;
    let loopCount = arr[1];
    let tempNumber = originNumber;
    for (let j = 0; j < loopCount - 1; j++) {
        tempNumber = (originNumber * tempNumber) % 10;
    }
    console.log((tempNumber == 0) ? tempNumber = 10 : tempNumber % 10);
}