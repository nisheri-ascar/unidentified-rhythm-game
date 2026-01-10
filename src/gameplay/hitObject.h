//#ifndef HITOBJECT_H
//#define HITOBJECT_H
//#include "raylib.h"

extern int beatCount;
extern float timeStamp;
extern int beatType;
extern int beatSpeed;
extern int offScreenLeft;
extern int offScreenRight;
extern int createdHitObjects;
extern int hitColor;

extern int hitBarLineHorizontal[1024];
extern int hitBarLineVertical[1024];
//extern Vector2 gameplayBarLineStartpoint[1024];
//extern Vector2 gameplayBarLineEndpoint[1024];
// TODO: FIGURE OUT LATER HOW TO *ACTUALLY* MAKE THIS RESIZESABLE ON-FLY
// THIS IS PROBABLY DANGEROUS AS HELL, BUT WHO CARES? ITS A PROTOTYPE

void InitHitObjectArray();

void PrepareHitObject(int beatCount);

void DrawHitObject(int beatCount, float timeStamp, int beatType);

void MoveHitObject(int beatCount, float beatSpeed);

void ClearHitObject(int beatCount);

//#endif
