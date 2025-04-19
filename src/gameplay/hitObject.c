/* concept brainstorming
*
* HitObjectSpawn(int speed, ) - function that creates an Hitobject
* HitObjectMove() - destroys the existence of hitobject either by
* being clicked or going negative y-max (missed).
* HitObjectDestroy)
*
* * beatCount is a number for array btw
*/

#include "raylib.h"
#include "hitObject.h"
#include <stdio.h>

int createdHitObjects;
int offScreenLeft;
int offScreenRight;
int hitBarLineHorizontal[1024];
int hitBarLineVertical[1024];
int beatColor;
bool hitObjectCleared[1024];
Color colorString;


void InitHitObjectArray(){
  int offScreenLeft = -10;
  int offScreenRight = GetScreenWidth() + 10; 
  for(int i = 0; i < 1024; i++){
      hitObjectCleared[i] = false;
      hitBarLineHorizontal[i] = offScreenRight;
      //fill all y coords to the array, probably problematic in future since position changes every time and this one is a fixed value, especially window resizing
      hitBarLineVertical[i] = (GetScreenHeight() / 2.3); //prolly guessing this is bad idea
  }
}

void PrepareHitObject(int beatCount){
  //gameplayBarLineStartpoint[beatCount].x = offScreenRight;
  //gameplayBarLineEndpoint[beatCount].x = offScreenRight;
  // Technically we fdont need this? but at the same time how can we create multiple hitobejects? this might be needed in future once dynamic array AND notes are dynamic matching to screen size is made.
}

void DrawHitObject(int beatCount, float timeStamp, int beatType){
  // we using pseudo beatType names for debugging
  // 0 - alpha, 1 - beta, 2 - gamma, 3 - skibidi
  // dont wanna use case cuz im stupid for now
  Color colorString = { 0, 0, 0, 0};
  if(beatType == 0){
    Color colorString = { 230, 41, 55, 255 }; //"RED"
  } if(beatType == 1){
    Color colorString = { 190, 33, 55, 255 } ; //MAROON
  } if(beatType == 2){
    Color colorString = { 0, 121, 241, 255 }; //BLUE
  } if(beatType == 3){
    Color colorString =  { 0, 228, 48, 255 }; //GREEN
  }
  if(!hitObjectCleared[beatCount]){
    DrawRectangle(hitBarLineHorizontal[beatCount], hitBarLineVertical[beatCount], 10, 60, colorString);
    DrawRectangleLines(hitBarLineHorizontal[beatCount], hitBarLineVertical[beatCount], 10, 60, RED);
  }
}


void MoveHitObject(int beatCount, float beatSpeed){
  if(!hitObjectCleared[beatCount]){
    hitBarLineHorizontal[beatCount] -= beatSpeed; 
    }
}

// logic: Once the barline is clicked OR the barline reaches y = -10 (offscreen width), destroy the existence of that barline and free the memory
void ClearHitObject(int beatCount){
  if(hitBarLineHorizontal[beatCount] <= offScreenLeft){
    hitObjectCleared[beatCount] = true;
  } 
}
