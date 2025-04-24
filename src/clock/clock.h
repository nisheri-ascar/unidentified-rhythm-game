
/*
// TODO: Use SDL nano second clock
typedef struct Timer {
  double startTime;
  double lifeTime;
} Timer;

extern Timer gameClock;
extern double gameRunningTime;
*/
extern float gameClockRunning;   

void StartGameClock(Timer *timer, double gameRunningTime);

bool StopClock(Timer timer);

double ElapsedGameClock(Timer timer);
