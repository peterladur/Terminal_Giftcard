#include <stdio.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0


//CONSTANTS
int WIDTH = 100;
int HEIGHT = 40;
int ART_RIGHT_BOUNDARY = 50;

//Structs
struct Position
{
    int x;
    int y;
};

//Forward Declaration
void calculate_x_z_position(int x, int linewidth, int angluar_velocity, float t);
void boundary(int n, int line_len, int boundary_values[2][n]);
void display_buffer(int n, int line_length, char buffer[n][line_length]);
void calculate_x_z_position(int x, int linewidth, int angluar_velocity, float t);
void init_buffer(int n, int line_len, char buffer[n][line_len]);


void init_buffer(int n, int line_len, char buffer[n][line_len])
{
    //Open the File
    FILE *ascii_art_file;
    ascii_art_file = fopen("ASCII_art.txt", "r");

    //Reading the file
    char file_contents[line_len];

    if (ascii_art_file == NULL)
    {
        printf("Not able to open the file");
    }
    else
    {
        int line = 0;
        while (fgets(file_contents, line_len, ascii_art_file))
        {   
            for (int i = 0; i < strlen(file_contents); i++)
            {    
                buffer[line][i] = file_contents[i];
            }
            line++;
        }
    }

    //Close the file
    fclose(ascii_art_file);


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

void display_buffer(int n, int line_length, char buffer[n][line_length])
{

    for (int y = 0; y < n; y++)
    {
        int x = 0;
        while ((x < line_length) && (buffer[y][x] != 0))
        {

            printf("%c", buffer[y][x]);
            x++;
        }
    }
    printf("\n");

}

/*void animation(int n, int line_length, int boundary_values[2][n]){


    
    display_buffer(n, line_length, buffer);

    //calculate_x_z_position(1, line_length, 1, 0.2);
    
}*/

void calculate_x_z_position(int x, int linewidth, int angluar_velocity, float t)
{   
    int r = (x - linewidth/2);
    printf("%d\n", r);
    printf("%f\n", t);
    float x_new = r * cos(angluar_velocity * t);
    float z_new = r * sin(angluar_velocity * t);
}

int main(){

    //Initialise Variables
    int line_len = 100;
    int boundary_values[2][n];
    char buffer[n][line_len];

    //Initialise Buffer
    init_buffer(n, line_len, buffer);

    //Initialise Text
    //init_text();

    //Display Buffer & Text
    display_buffer(n, line_len, buffer);

    //OPTIONAL: Animation -> Rotates the 2d image in 3d

    //Set the boundary Array
    //boundary(n, line_len, boundary_values);

    //Displays the characters between the boundary
    //animation(n, line_len, boundary_values);

    return 0;

}
