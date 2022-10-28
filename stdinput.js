// copy this
// "../input.txt"
// "/dev/stdin"
{
let fs = require('fs');
let input = fs.readFileSync("/dev/stdin").toString().split(" ");
}
{
    let fs = require('fs');
    let input = fs.readFileSync('./input.txt').toString().split(' ');
}
{
    let fs = require('fs');
    let input = fs.readFileSync('./input.txt').toString().split('\n');
}