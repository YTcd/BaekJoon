let fs = require('fs');
let input = fs.readFileSync("./input.txt").toString().split("\n");

let arr1 = input[0].split(" ");
const cnt = arr1[0] * arr1[1];

let arr2 = input[1].split(" ");
let str = "";
for(let i = 0; i<5 ; i++){
    str += -(cnt - arr2[i]);
    if(i!=4){
        str += " ";
    }
}
console.log(str);