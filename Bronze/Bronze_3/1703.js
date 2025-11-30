answer = (arr) => {
    let mul = 1;
    let numArr = arr.split(" ").map(Number);
    for (let i = 0; i < numArr[0]; i++) {
        mul *= numArr[i * 2 + 1];
        mul -= numArr[i * 2 + 2];
    }
    console.log(mul);
}
let fs = require('fs');
let input = fs.readFileSync("./input.txt").toString().split("\n");
let i = 0;
while (input[i] != 0) {
    answer(input[i]);
    i++;
}
