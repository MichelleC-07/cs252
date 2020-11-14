/* LAB 6
*  Name: Michelle Chew Poi Yan
*************************************
   To be filled out by instructor
   Grade:    (Out of 20)
   	Compiles: 
   	Runtime: 
	Other Comments
*************************************  
*/

/* Lab6: This is an extension of the Lab 5 work to make use of 
	1) Multiple files and a makefile
	2) Use of FILE* pointer functions such as fread(), fgetc(), fwrite(), fputc(), fseek().
	** With command-line arguments, run as 


	For Lab 6:
	0) Study the relationships between the given lab6.c, lab6_utils.h, and lab6_utils.c source code files.
		Notice that the function definitions from Lab5 
			char_is_punctuation()
			remove_char_at_str_pos() 
		have been moved into lab6_utils.c
		along with their prototypes specified in the header file called lab6_utils.h 
	   Going back to lab6.c, notice the insertion near the other #include statements: 
			#include "lab6_utils.h"
	   I will walk through the creation of a makefile that builds the source code lab6.c and lab6_utils.c and lab6_utils.h
		into an executable binary called lab6 that can be run
		in the same manner that lab5 was with command-line arguments.
		   $ ./lab6 input2.txt output2.txt
	   Now to compile, you will simply run
		$ make
	   To remove binaries, run
		$ make clean
		
	1) Note the presence of the new function prototype in lab6_utils.h
		int copy_file(const char *src_file_name, const char *dest_file_name);
	   where number of bytes copied is to be returned.
	   TODO: Implement this function copy_file() in lab6_utils.c to open the file with name
		src_file_name in "r" mode, 
		open a new file in "w" mode with name dest_file_name
		using either fgetc() and fputc() OR fread() and fwrite(),
		and keep track of number of bytes read to be returned.
		HINT: See the example in 
			https://www.geeksforgeeks.org/c-program-copy-contents-one-file-another-file/
		(NOTE: Later, we will see that system functions can use 'cp' within C code.)
		BE SURE TO CALL fclose() on both file pointers before the return of this function.

	2) Assume the use of command line arguments where argv[1] is either input1.txt or input2.txt
		and argv[2] is correspondingly either output1.txt or output2.txt.
	   TODO: Dynamically allocate to 
			char* byte_contents;
		    a char array of length (num_bytes+1).
		    Set the last cell to have value '\0'.
	3) Note the new function prototype in lab6_utils.h
			void copy_file_to_str(const char* src_file_name, char* dest_str);
	   TODO: implement copy_file_to_str() in lab6_utils.c

	3) TODO: Use the functions from Lab5 to modify the string byte_contents to remove all of the punctuation. 
		HINT: The while loop from Lab5 is commented out for your reference.

	4) TODO: Using the copied and modified contents of byte_contents, write into the file with name argv[2] 
	   using a while loop in conjunction with fputc(); or just use fputs(). 
	   If you are using fputc() in a while loop, in place of the final '\0' of byte_contents, 
		have EOF written as the last byte in file_to_modify.
		
	   As before, use the 'diff' shell command to compare 
		e.g., output2.txt with expected2.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab6_utils.h"

int main(int argc, char *argv[])
{
	//char textin[80], wordout[80];
	int i, j;
	FILE *out_file_ptr = NULL;

	if (argc > 2)
	{
		printf("Input file is: %s\n", argv[1]);
		printf("Output file is: %s\n", argv[2]);
	}
	else
	{
		printf("Usage: ./lab6 intputN.txt outputN.txt\n");
		exit(0);
	}

	int num_bytes = copy_file(argv[1], argv[2]);
	char *byte_contents = NULL;
	//TODO: call malloc or calloc to allocate a length (num_byte+1) or more array of chars
	byte_contents = malloc((num_bytes + 1) * sizeof(char));

	//	and assign the returned address to byte_contents.
	//TODO: After the dynamic allocation, uncomment the following line
	byte_contents[num_bytes] = '\0'; //Should be so already using calloc(), just to be sure.

	// TODO: UNCOMMENT WHEN READY
	copy_file_to_str(argv[2], byte_contents); //file >>> memory

	//TODO: USE the example of the below commented-out code of Lab 5
	// to have the same punctuation removed from byte_contents.
	for (i = 0; i < strlen(byte_contents); i++)
	{
		if (char_is_punctuation(byte_contents[i]))
		{
			remove_char_at_str_pos(byte_contents, i);
			i--;
		}
	}

	out_file_ptr = fopen(argv[2], "w");
	//TODO: Use fputc() (with while loop) or fputs() to write
	// the contents of byte_contents into out_file_ptr.

	fputs(byte_contents, out_file_ptr);
	//free() dynamic allocation once done.

	free(byte_contents);
	//close the file stream when done.

	fclose(out_file_ptr);

#if 0
    while(1){ 
	//This loop only breaks when the next word/phase read in is "."
        fscanf(in_file_ptr,"%s",textin);
	if (strcmp(textin,".") == 0){
	    break;
	}
	strcpy(wordout,textin);
	for (i=0; i<strlen(wordout); i++){
	    if ( char_is_punctuation( wordout[i] )  ){
		remove_char_at_str_pos(wordout, i);
		i--;
	    }
	}
	fprintf(out_file_ptr,"%s\n",wordout);
    }
#endif
	return 0;
}
