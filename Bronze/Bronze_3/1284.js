cal = (number) => {
    let sum = 0;
    number = number.split("");
    number.forEach(element => {
        if (element == "1") {
            sum += 3;
        } else if (element == "0") {
            sum += 5;
        } else {
            sum += 4;
        }
    });
    return sum + 1;
}
let fs = require('fs');
let input = fs.readFileSync("./input.txt").toString().split("\n");
let i = 0;
while (input[i] != 0) {
    console.log(cal(input[i]));
    i++;
}