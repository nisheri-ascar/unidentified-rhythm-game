

// TODO: Use SDL nano second clock
typedef struct Timer {
  double startTime;
  double lifeTime;
} Timer;

extern Timer gameClock;
extern double howLongIsThisStupidGameRunning;

void StartTimer(Timer *timer, double lifetime);

bool TimerDone(Timer timer);

double GetElapsed(Timer timer);
