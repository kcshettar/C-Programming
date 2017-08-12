/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: kcshe
 *
 * Created on January 31, 2016, 9:28 PM
 */

#include<stdio.h>
 
/* Reverse the String using Recursion */
char* reverse(char str[20]) //char pointer
{
    int i = 0;
    int j = 0;
    char temp;
    
    j = strlen(str) - 1;
 
    while (i < j) 
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
      i++;
      j--;
   }
   return str;
}

int main(int argc, char* argv[])
{
char word[] = "Happy Birthday!";
printf("%s\n", word);
reverse(word);
printf("%s\n", word);
printf("%s\n", reverse(word));
printf("%s\n", word);
return 0;
}
