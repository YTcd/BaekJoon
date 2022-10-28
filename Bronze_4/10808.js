let fs = require('fs');
let input = fs.readFileSync("./input.txt").toString();
let number = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
let str = input.split("");

let answer = "";
for(let i = 0; i<str.length ; i++){
    let a =Number(str[i].charCodeAt(0)) - 97 
    number[a]++;
}
for(let i = 0; i<26 ; i++){
    answer += number[i];
    if(i != 25){
        answer += " ";
    }
}
console.log(answer);