#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encryptFunc(void)
{
    char sentence[151], sentenceCopy[151], encrypted_chars[151];
    int encrypted[151];
    int count = 0;
    int del = 0;
    int distance = 0;
    int key = 5;
    int error = 0;

    //grab the message and put it to an array
    printf("type the sentence (characters limit - 150):");
    fgets(sentence, 151, stdin);
    strtok(sentence, "\n"); //removes the newline character taken from the input

    //copy characters on the array to a new one
    while (sentence[del] != '\0')
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
            // if the ascii value is lowered past 32 by the key then we go to 127 and shift the value
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

void decryptFunc()
{
    char encSentence[151], encChars[151], decSentence[151];
    int encCharcount = 0, key = 5, difference = 0;
    printf("type the sentence (characters limit - 150):");
    fgets(encSentence, 151, stdin);
    //copy the encrypted sentence to a new array
    while (encSentence[encCharcount] != '\0')
    {
        encChars[encCharcount] = encSentence[encCharcount];
        encCharcount++;
    }
    for (int i = 0; i < encCharcount; i++)
    {
        if (encChars[i] > 122)
        {
            //if the ascii value is higher than 122 then we go to 32 and shift the value by the difference
            difference = encChars[i] - 122;
            decSentence[i] = difference + 32;
        }
        else
        {
            decSentence[i] = encChars[i] + key;
        }
    }
    //decrypted characters output
    printf("\n");
    printf("decrypted sentence: \n");
    for (int i = 0; i < encCharcount; i++)
    {
        printf("%c", decSentence[i]);
    }
    printf("\n");
}

int main()
{
    char choice;
    printf("Do you want to encrypt or decrypt?\n\n");
    printf("a)encrypt  b)decrypt \n");
    choice = getchar();
    while ((getchar()) != '\n'); //this will prevent the encryptFunc's fget getting affected by the getchar input buffer
    if (choice == 'a')
    {
        encryptFunc();
    } 
    else if (choice == 'b')
    {
        decryptFunc();
    }
    else
    {
        printf("Please try again.\n");
    }
    
    return 0;
}