#include <stdio.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0


//CONSTANTS
char ASCCI_ART_FILENAME[] = "ASCII_art.txt";
int TEXT_ANIMATION_NUMBER = 0;

const int WIDTH = 200;
const int HEIGHT = 10;
const int ART_RIGHT_BOUNDARY = 30;
const int TEXT_WIDTH = WIDTH - ART_RIGHT_BOUNDARY;


//Structs
typedef struct
{
    int r;
    int g;
    int b;
} Color;

//Forward Declaration

//Basic Functionality
void init_buffer(char buffer[HEIGHT][WIDTH]);
void display_buffer(char buffer[HEIGHT][WIDTH]);

//Text Animation 1: Constant colour
Color text_char_color(int char_x, int char_y, char char_val);
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
    char text_file_contents[TEXT_WIDTH];

    if (text_file == NULL)
    {
        printf("Not able to open the file"); //Really should be an error
    }
    else
    {
        int line = 0;
        while (fgets(text_file_contents, TEXT_WIDTH, text_file))
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

            //Checks if the char is part of text or art, for animation purposes
            if (x < ART_RIGHT_BOUNDARY)
            {
                printf("%c", buffer[y][x]);
            }
            else 
            {
                
                Color color = text_char_color(x - ART_RIGHT_BOUNDARY, y, buffer[y][x]); //Get color of char
                printf("\033[38;2;%d;%d;%dm", color.r, color.g, color.b); //Sets the color
                printf("%c", buffer[y][x]); //Prints char
                printf("\033[0m"); //Resets the color
            }
        }
        printf("\n");
    }

}

Color text_char_color(int char_x, int char_y, char char_val)
{
    //Inits the color
    Color color = {255, 255, 255};

    int relative_char_x = char_x - TEXT_WIDTH;
    //Constant color
    if (TEXT_ANIMATION_NUMBER == 0)
    {   
        color.r = 255;
        color.g = 80;
        color.b = 100;
        
    } 

    //Gradient
    if (TEXT_ANIMATION_NUMBER == 1)
    {   
        color.r = 200 + 55 * (relative_char_x - TEXT_WIDTH);
        color.g = 70 + 20 * (relative_char_x - TEXT_WIDTH);
        color.b = 80 + 20 * ((relative_char_x - TEXT_WIDTH));
        
    } 

    return color;
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
