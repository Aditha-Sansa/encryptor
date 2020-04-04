#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encryptdecryptFunc(void)
{
    char sentence[151];
    char sentenceCopy[151];
    int encrypted[151];
    char encrypted_chars[151];
    int count = 0;
    int del = 0;
    int distance = 0;
    int key = 5;
    int error = 0;

    
    //grab the message and put it to an array
    printf("type the sentence (characters limit - 150):");
    fgets(sentence, 151, stdin);
    strtok(sentence, "\n");//removes the newline character taken from the input
    
    //copy characters on the array to a new one
	while(sentence[del] != '\0') 
	{
	    sentenceCopy[del] = sentence[del];
	    del++;
	    count++;
	}
	printf("character count: %d \n", count);
	
	//encrypt - Rot-N/Rot cipher (shift down the ascii value)
	for (int i = 0; i < count; i++) 
	{
        if (sentenceCopy[i] < 37 && sentenceCopy[i] >= 32)
        {
            // if the ascii is lowered past 32 by the key then we go to 127 and shift the value
            // if x<37 then;
            // x-32 = y
            // 122+y = encrypted[i]
            distance = sentenceCopy[i] - 32;
            encrypted[i] = distance + 122;
        }
        else if (sentenceCopy[i] >= 37 && sentenceCopy[i] < 127)
        {   
            encrypted[i] = sentenceCopy[i] - key;
        }
        else
        {
            printf("Couldn't encrypt the '%c' character correctly. Unacceptable character \n", sentenceCopy[i]);
            error++;
            exit(0);
        }

	}
	//encrypted characters output
	printf(" ");
    printf("encrypted sentence: \n");
	for (int i = 0; i < count; i++) 
	{
	    encrypted_chars[i] = encrypted[i];
	    printf("%c", encrypted_chars[i]);
	}
    printf("\n");
    printf("%d error(s)\n", error);
    
}

int main()
{
    encryptdecryptFunc();
    return 0;
}