#include <string.h>
#include <stdio.h>
#include <stdlib.h>
/*Tests whether the parameter char ch_value input is 
 * a punctuation type character;
 * returning 1 (true) or 0 (false)
 */
int char_is_punctuation(char ch_value)
{
    int is_punctuation = (ch_value == '.'); //0 false, 1 true
    // RECALL: || is the logical OR binary operator
    is_punctuation = is_punctuation || (ch_value == ',') || (ch_value == '"');
    is_punctuation = is_punctuation || (ch_value == ';') || (ch_value == '!');
    is_punctuation = is_punctuation || (ch_value == '?') || (ch_value == '(');
    is_punctuation = is_punctuation || (ch_value == ')') || (ch_value == ':');
    // SO THAT if at least one of the == expressions is true, then is_punctuation is true.
    return is_punctuation;
}

void remove_char_at_str_pos(char *str, int pos)
{
    for (int jj = pos; jj < strlen(str) - 1; jj++)
    {
        str[jj] = str[jj + 1];
    }
    str[strlen(str) - 1] = '\0';
}

int copy_file(const char *src_file_name, const char *dest_file_name) //it is like cp command
{
    //TODO: Implement
    int ch_count = 0;
    FILE *fptr1, *fptr2;
    char c;

    fptr1 = fopen(src_file_name, "r"); //open the source file to read
    if (fptr1 == NULL)
    {
        printf("Cannot open file %s \n", src_file_name);
        exit(0);
    }

    fptr2 = fopen(dest_file_name, "w"); //open the destination file to write in
    if (fptr2 == NULL)
    {
        printf("Cannot open file %s \n", src_file_name);
        exit(0);
    }
    c = fgetc(fptr1); //reads content from file and assign c with btye value

    while (c != EOF) //end of file macro, -1 literal
    {
        fputc(c, fptr2); //write the character value to the destination pointer
        c = fgetc(fptr1);
        ch_count++;
    }

    fclose(fptr1);
    fclose(fptr2);

    return ch_count;
}

void copy_file_to_str(const char *src_file_name, char *dest_str) //copy the content of source file into memory
{
    FILE *in_file = fopen(src_file_name, "r");
    int ch_count = 0; //array index

    //TODO: Implement
    char c = fgetc(in_file); //reads content from file and assign c with btye value

    while (c != EOF) //end of file macro, -1 literal
    {
        dest_str[ch_count] = c;
        c = fgetc(in_file);
        ch_count++;
    }

    dest_str[ch_count] = '\0';
    fclose(in_file);
}
