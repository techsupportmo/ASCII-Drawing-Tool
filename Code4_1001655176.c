//Mohammed Ahmed 1001655176

#include "DrawTool.h"






int main(void) {
    
    char map[MAX][MAX];
    
    char drawCommand[MAX];
    char *drawCommandPtr;
    char delims[] = "(),";
    
    
    
    int size = 0;
    int *sizePtr = &size;
    
    //variables for strtok()
    char letter;
    char *letterPtr;
    
    int row;
    char *rowPtr;
    
    int col;
    char *colPtr;
    
    int length;
    char *lengthPtr;
    
    char marker;
    char *markerPtr;
    
    
    //prints out instructions and map
    printInstructions();
    CreateMap(map,sizePtr);
    size = *sizePtr;
    printMap(map, size);
    
    //prompts user for draw command
    printf("Enter draw command (enter Q to quit)   ");
    drawCommandPtr = fgets(drawCommand,MAX - 1,stdin);
    
    
    while(!(*drawCommandPtr == 'Q' || *drawCommandPtr == 'q'))
    {
        

        //strtok to parse out command
        
        
        //letter
        letterPtr = strtok(drawCommand,delims);
        letter = *letterPtr;
        //printf("Token: %c\n",letter);
        
        //row
        rowPtr = strtok(NULL,delims);
        row = atoi(rowPtr);
        //printf("Token: %d\n",row);
        
        //col
        colPtr = strtok(NULL,delims);
        col = atoi(colPtr);
        //printf("Token: %d\n",col);
        
        //length
        lengthPtr = strtok(NULL,delims);
        length = atoi(lengthPtr);
        //printf("Token: %d\n",length);
        
        //marker
        markerPtr = strtok(NULL,delims);
        marker = *markerPtr;
        //printf("Token: %c\n",marker);
        
        // checks if no marker is input (\n is entered)
        if(marker == 10)
        {
            marker = 'X';
        }
        
        
        //checks for single point
        if(letter == 'P' || letter == 'p')
        {
            //checks if point is on grid
            if(row > size || col > size)
            {
                printf("\nThat draw command is out of range\n");
            }
            else
            {
                *( *(map+ row) +col)= marker;
            }
            
            
        }
        else
        {
            //checks if H or V command is input or else it is invalid
            if(letter == 'H' || letter == 'h' || letter == 'V' || letter == 'v')
            {
              drawLines(letter, row, col, length, marker, map, size);
            }
            else
            {
                printf("\nThat draw command is unknown\n");
            }
            
            
            
            
        }
        
               
        
        
        
        
        printMap(map, size);

                    
        
        //prompts user for draw command
        printf("Enter draw command (enter Q to quit)   ");
        drawCommandPtr = fgets(drawCommand,MAX - 1,stdin);
            
        
        
        

    }
    
    
    
    
    return 0;
    
}
