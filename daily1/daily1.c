char reverse(char *word)
{
  	int length, i;
	char *start;
	char *end; 
	char temp;
	//Process1
	//word_length function is called here
	start = word;
	end = word;	
	length = word_length(word);
	//Process2
	for(i=0; i<length -1 ; i++)
	end++;
	//Process3
	//for loop is executed until the string is completely reversed
	//Pre-Condition: The given string is not reversed and is taken as an input
	//Post-Condition: The given string is reversed and stored
	for(i=0; i<length/2 ; i++)
	{
	//To reverse a given string by swapping characters with the help of temp
		//Process4
		temp = *end;
		*end = *start;
		*start = temp;
		//Process5
	//once the charcters are moved pointer is shifted	
	start++;
	end--;	
	}
return 0;
}

int word_length(char *pointer)
{
	//Compilation happens in this loop for three times
	char i = 0;
	while( *(pointer + i) != '\0' )
	i++;
return i++;
}
