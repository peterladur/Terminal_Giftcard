#include <stdio.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0


//CONSTANTS
char ASCCI_ART_FILENAME[] = "ASCII_art.txt";
int TEXT_ANIMATION_NUMBER = 0;

int WIDTH = 200;
int HEIGHT = 10;
int ART_RIGHT_BOUNDARY = 30;


//Structs
struct Color
{
    int r;
    int g;
    int b;
};

//Forward Declaration

//Basic Functionality
void init_buffer(char buffer[HEIGHT][WIDTH]);
void display_buffer(char buffer[HEIGHT][WIDTH]);

//Text Animation 1: Constant colour
void text_char_color(int char_x, int char_y, char char_val);
//Text Animation 2: Colour gradient

//Text Animation 3: Changing Colour Gradient

//Animation 1: Colour Gradient


//Animation 2: Rotation
void boundary(int n, int line_len, int boundary_values[2][n]);
void calculate_x_z_position(int x, int linewidth, int angluar_velocity, float t);



void init_buffer(char buffer[HEIGHT][WIDTH])
{
    //Set Buffer to be empty
    memset(buffer, ' ', HEIGHT * WIDTH);

    //ART:

    //Open the File
    FILE *ascii_art_file;
    ascii_art_file = fopen(ASCCI_ART_FILENAME, "r");

    //Reading the file
    char ascii_file_contents[ART_RIGHT_BOUNDARY];

    if (ascii_art_file == NULL)
    {
        printf("Not able to open the file"); //Really should be an error
    }
    else
    {
        int line = 0;
        while (fgets(ascii_file_contents, ART_RIGHT_BOUNDARY, ascii_art_file))
        {       
            //Iterates through the loop and grabs every char other then \n
            for (int i = 0; i < strlen(ascii_file_contents) - 1; i++)
            {    
                buffer[line][i] = ascii_file_contents[i];
            }
            line++;
        }
    }

    //Close the file
    fclose(ascii_art_file);

    //TEXT

    //Open the File
    FILE *text_file;
    text_file = fopen("text.txt", "r");

    //Reading the file
    char text_file_contents[WIDTH - ART_RIGHT_BOUNDARY];

    if (text_file == NULL)
    {
        printf("Not able to open the file"); //Really should be an error
    }
    else
    {
        int line = 0;
        while (fgets(text_file_contents, WIDTH - ART_RIGHT_BOUNDARY, text_file))
        {   
            //Iterates through the loop and grabs every char other then \n
            for (int i = 0; i < strlen(text_file_contents) - 1; i++)
            {    
                buffer[line][ART_RIGHT_BOUNDARY + i] = text_file_contents[i];
            }
            line++;
        }
    }

    //Close the file
    fclose(text_file);

}

void display_buffer(char buffer[HEIGHT][WIDTH])
{

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {

            printf("%c", buffer[y][x]);
        }
        printf("\n");
    }

}

void text_char_color(int char_x, int char_y, char char_val)
{
    if (TEXT_ANIMATION_NUMBER == 0)
    {
        struct Color constant_color;
        constant_color.r = 50;
        constant_color.g = 50;
        constant_color.b = 50;

        
        
    } 
}

void boundary(int n, int line_len, int boundary_values[2][n])
{

    //Open the ascii file
    FILE *ascii_file;
    //ascii_file = fopen("ASCII_art.txt", "r");
    ascii_file = fopen("ASCII_art.txt", "r");

    //Read the file
    char file_contents[line_len];

    // Error Handling
    if (ascii_file == NULL){ 
        printf("Not able to open the file");
    } 
    else {     
        int line = 0;
        while(fgets(file_contents,  line_len, ascii_file)){
            //Read through every line and add to the boundary array
            int found_start = FALSE;
            int found_end = FALSE;
            boundary_values[0][line] = 0;
            boundary_values[1][line] = 0;

            int i = 0;
            while (i < strlen(file_contents) && (found_end == FALSE))
            {   
                //Looks for the initial # character
                if (file_contents[i] == '#' && (found_start == FALSE)) 
                {
                    found_start = TRUE;
                    boundary_values[0][line] = i;
                }
                //Looks for the final # character
                if ((file_contents[i] == ' '  && (found_start == TRUE)) ) 
                {
                    found_end = TRUE;
                    boundary_values[1][line] = i;
                }
                i++;
            }


            line++;
        }

    }

    //Close the file
    fclose(ascii_file);
}

int main(){

    //Initialise Buffer
    char buffer[HEIGHT][WIDTH];
    init_buffer(buffer);

    //Display Buffer & Text
    display_buffer(buffer);

    //OPTIONAL

    //Text Animation:


    return 0;

}
