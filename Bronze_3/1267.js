Y = (number) => {
    let bill = 10;
    while (number >= 30) {
        number -= 30;
        bill += 10;
    }
    return bill;
}

M = (number) => {
    let bill = 15;
    while (number >= 60) {
        number -= 60;
        bill += 15;
    }
    return bill;
}
let fs = require('fs');
let input = fs.readFileSync("./input.txt").toString().split("\n");
let number = input[1].split(" ");
let Yb = 0;
let Mb = 0;
for (let i = 0; i < input[0]; i++) {
    Yb += Y(parseInt(number[i]));
    Mb += M(parseInt(number[i]));
}

if (Yb > Mb) {
    console.log("M " + Mb);
} else if (Yb == Mb) {
    console.log("Y M " + Yb);
} else {
    console.log("Y " + Yb);
}