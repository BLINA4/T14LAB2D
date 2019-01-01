/* Labyrinth game
 * Main programm file
 * Protected by GNU GPL license v3 */

#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
 
#define FRAME_W (1920 / 1)
#define FRAME_H (1080 / 1)
  
#include <math.h>

#include "LAB2D.H"

BYTE Frame[FRAME_H][FRAME_W][3], Pause;
double Zoom = 1, SyncTime, FPS, DeltaTime, PauseTime;
 
void Timer( void )
{
  long t;
  static long StartTime = -1, FPSTime, FrameCount, OldTime;

  t = clock();
  if (StartTime == -1)
    StartTime = FPSTime = OldTime = t;
 
  if (!Pause)
  {
    DeltaTime = (t - OldTime) / (double)CLOCKS_PER_SEC;
    SyncTime = (t - StartTime - PauseTime) / (double)CLOCKS_PER_SEC;
  }
  else
  {
    DeltaTime = 0;
    PauseTime += t - OldTime;
  }
  FrameCount++;
 
  if (t - FPSTime > 3 * CLOCKS_PER_SEC)
  {
    FPS = FrameCount / ((t- FPSTime) / (double)CLOCKS_PER_SEC);
    FPSTime = t;
    FrameCount = 0;
  }
}

/* Display function */
void Display( void )
{
    
} /* End of 'Display' function */

/* Keyboard function */
void Keyboard( BYTE Key, int X, int Y )
{

} /* End of 'Keybaord' function */

/* Main programm function */
void main( int arcg, char *argv[] )
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

  glutInitWindowPosition(400, 200);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Labyrinth");

  glutDisplayFunc(Display);
  glutKeyboardFunc(Keyboard);

  glutMainLoop();
} /* End of 'main' function */

/* END OF 'T14LAB2D.C' FILE */

