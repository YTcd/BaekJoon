let fs = require('fs');
let input = fs.readFileSync("./input.txt").toString().split("\n");
let count = input[0];
let str = "";
for(let i = 1; i <= count; i++){
    let a = input[i].split(" ");
    str += (Number(a[0]) + Number(a[1]))+"\n";
}
console.log(str);