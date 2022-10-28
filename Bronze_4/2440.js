let fs = require('fs');
let input = fs.readFileSync("./input.txt").toString();
const number = Number(input);
let str ="";
for(let i = 0; i<number; i++){
    for(let j=0; j<number; j++){
        if((i+j) < number){
            str += "*";
        }
    }
    console.log(str);
    str="";
}