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