#ifndef __PID_H
#define __PID_H

typedef struct PID
{
    int SetPoint;

    unsigned char BitMove;

    float Proportion;
    float Integral;
    float Derivative;

    int iError;
    int iIncpid;

    int LastError;
    int PrevError;

    int Uk;
} PID, *pPID;

extern PID sPID;

void IncPIDInit(void);
int IncPIDCalc(int NextPoint);

#endif
