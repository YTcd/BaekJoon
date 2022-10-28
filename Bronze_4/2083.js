let fs = require('fs');
let input = fs.readFileSync("./input.txt").toString().split("\n");

for(let i = 0; i< input.length-1 ; i++){
    let strArr = input[i].split(" ");
    if(strArr[0] == "#"){
        return;
    }
    if(Number(strArr[1]) > 17 || Number(strArr[2]) >= 80){
        console.log(strArr[0] + " Senior");
    } else {
        console.log(strArr[0] + " Junior");
    }
}