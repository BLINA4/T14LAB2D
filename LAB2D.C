/* Labyrinth game
 * Primary functions file
 * Protected by GNU GPL license v3 */

#include <stdio.h>

#include "LAB2D.H"

BYTE Lab[MAX][MAX];

int ex, ey, AvaX, AvaY;

/* Lab loading function */
void LoadLab( char *FileName )
{
  FILE *F;
  int ch, x = 0, y = 0;

  memset(Lab, 0, sizeof Lab);

  /* Error opening file */
  if ((F = fopen(FileName, "r")) == NULL)
    return;  

  /* File reading */
  while ((ch = fgetc(F)) != EOF)
  { 
    if (x >= 0 && x < MAX && y >= 0 && y < MAX)  
      switch (ch)
      {
      case ' ':
        Lab[y][x] = 0;
        break;
      case '*':
        Lab[y][x] = 1;
        break;
      case 'e':
        Lab[y][x] = 0;
        ex = x;
        ey = y;
        break;
      case 'a':
        Lab[y][x] = 0;
        AvaX = x;
        AvaY = y;
      case '\n':
        y++, x = 0;
        break;
      default:
        x++;
      }
    else
      if (ch == '\n')
        y++, x = 0;
      else 
        x++;  
  }  
} /* End of 'LoadLab' function */

/* END OF 'LAB2D.C' FILE */

