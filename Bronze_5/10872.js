let fs = require('fs');
let input = fs.readFileSync("./input.txt").toString();
let fac = 1;
while(input != 0){
    fac *= input;
    input--;
}
console.log(fac);