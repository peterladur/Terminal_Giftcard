#include <stdio.h>

#define TRUE 1
#define FALSE 0

int boundary()
{
    //Create a boundary array
    int n = 9;
    int boundary_values[2][n] ;

    //Open the ascii file
    FILE *ascii_file;
    ascii_file = fopen("ASCII_art.txt", "r");

    //Read the file
    char file_contents[16];

    // Error Handling
    if (ascii_file == NULL){ 
        printf("Not able to open the file");
    } 
    else {     
        int line = 0;
        while(fgets(file_contents,  16, ascii_file)){
            //Read through every line and add to the boundary array
            int found_start = FALSE;
            int found_end = FALSE;
            boundary_values[0][line] = 0;
            boundary_values[1][line] = 0;

            for (int i = 0; i < 16; i++)
            {   
                printf("%c", file_contents[i]);

                if (file_contents[i] == '#' && (found_start == FALSE)) 
                {
                    found_start = TRUE;
                    boundary_values[0][line] = i;
                }
                if ((file_contents[i] == ' '  && (found_start == TRUE)) ) 
                {
                    found_end = TRUE;
                    boundary_values[1][line] = i;
                }

            }
            printf("\n");


            line++;
        }

    }

    fclose(ascii_file);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", boundary_values[i][j]);
        }
        printf("\n");  // new line after each row
    }

    return 0;
}



int main(){

    boundary();

    return 0;

}
