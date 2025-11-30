let fs = require('fs');
let input = fs.readFileSync("./input.txt").toString();
const number = Number(input)
for(let i = number; i > 0; i--){
    let str = "";
    for(let j=0; j< number; j++){
        if(i<=j+1){
            str += "*";
        }else{
            str += " ";
        }
    }
    console.log(str);
    str = "";
}
