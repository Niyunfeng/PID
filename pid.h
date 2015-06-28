#ifndef _PID_H
#ifndef _PID_H

#ifdef _PID_C
    #define PID_EXT
#else
    #define PID_EXT extern
#endif

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
}PID,*pPID;

PID_EXT PID sPID;
PID_EXT pPID sptr;

void IncPIDInit(void);
int IncPIDCalc(int NextPoint);

#endif
