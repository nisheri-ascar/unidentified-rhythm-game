/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Gameplay Screen Functions Definitions (Init, Update, Draw, Unload)
*
*   Copyright (c) 2014-2022 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#include "raylib.h"
#include "gameplay/hitObject.h"
#include "screens.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;

// A REALLY BIG WARNING!
//
// all this position variables are a technical debt in future.
// this will most likely be a pain in the ass to figure out positions and
// making objects relative to screen size.
//
// currently, right now, everything is hardcoded to fixed resolution
// 800 x 450
// to me, future programmer, i'm so sorry, but i'm still learning
// i'm praying the best of you to make all objects relative to
// resizable screen size.
//
// karl, 2025-04-15 2:56 PM

Vector2 playfieldLineStartpoint;
Vector2 playfieldLineEndpoint;
char onScreenIssueDiagnosement[512];
bool playfieldRenderDone;
int beatCount;
int testBeatCount;
int lastCharPressed = 1;

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitGameplayScreen(void){
    // TODO: Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;
    testBeatCount = 0;
    InitHitObjectArray();

    playfieldLineStartpoint.x = 0;
    playfieldLineEndpoint.x = 0;

    playfieldLineStartpoint.y = GetScreenHeight() / 2;
    playfieldLineEndpoint.y = GetScreenHeight() / 2;

    playfieldRenderDone = false;
}

// Gameplay Screen Update logic
void UpdateGameplayScreen(void){
    // TODO: Update GAMEPLAY screen variables here
    if(playfieldRenderDone){
      MoveHitObject(0, 1.0);
      MoveHitObject(1, 1.5);
      MoveHitObject(2, 2.3);
      MoveHitObject(3, 1.9);
    }
    sprintf(onScreenIssueDiagnosement,
    "Mouse X pos: %d\n"
    "Mouse Y pos: %d\n"
    "Screen Height: %d\n"
    "Screen Width: %d\n"
    "LineBar.x: %d\n"
    "LineBar.y %d\n"
    "beatCount: %d\n"
    "Last Key pressed: %d\n"
    , GetMouseX(), GetMouseY(), GetScreenHeight(), GetScreenWidth(), hitBarLineHorizontal[testBeatCount], hitBarLineVertical[testBeatCount], beatCount, lastCharPressed);
    printf("%s\n ",GetCharPressed());
    if(GetCharPressed() != 0){
        lastCharPressed = GetCharPressed();
    }
    // Press enter or tap to change to ENDING screen
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    {
        finishScreen = 1;
        PlaySound(fxCoin);
    }
    //
}

// Gameplay Screen Draw logics
void DrawGameplayScreen(void)
{
    // TODO: Draw GAMEPLAY screen here!
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), PURPLE);
    Vector2 pos = { 20, 10 };
    DrawTextEx(font, "GAMEPLAY SCREEN", pos, font.baseSize*3.0f, 4, MAROON);
    DrawFPS(0, 0);
    DrawText(onScreenIssueDiagnosement, GetScreenWidth() / 1.35, 0, 2, WHITE);
    DrawText("Press Enter to start the rhythm!", 130, 400, 20, MAROON);
    DrawLineEx(playfieldLineStartpoint, playfieldLineEndpoint, 5.0f, BLACK);
    DrawRectangleLines((GetScreenWidth() / 2) - 300, (GetScreenHeight() / 2) - 30 , 15, 60, BLUE);


    if(playfieldRenderDone){
      DrawHitObject(0, 0.0, 2);
      DrawHitObject(1, 0.0, 1);
      DrawHitObject(2, 0.0, 3);
      DrawHitObject(3, 0.0, 1);
  } else {
      playfieldLineEndpoint.x += 5;
      if(playfieldLineEndpoint.x == GetScreenWidth() || playfieldRenderDone){
        playfieldRenderDone = true;
      }
    }
  }

// Gameplay Screen Unload logic
void UnloadGameplayScreen(void)
{
   // TODO: Unload GAMEPLAY screen variables here!
}

// Gameplay Screen should finish?
int FinishGameplayScreen(void)
{
    return finishScreen;
}
