using System;
using System.IO;

namespace Bronze_2
{
    public class bj1075
    {
        public static void main(){
            string path = @"./input.txt";
            string textValue = File.ReadAllText(path);
            Console.WriteLine(textValue);
        }   
    }
}
