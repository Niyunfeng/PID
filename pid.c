#include "pid.h"
#include <math.h>

#define MAXOUT 1000                 //输出最大值

PID sPID;
static pPID sptr;

void IncPIDInit(void)
{
    sptr                = &sPID;
    sptr->SetPoint      = 700;      //设定值
    sptr->BitMove       = 0u;       //返回结果比例

    sptr->LastError     = 0u;       //前2次误差值
    sptr->PrevError     = 0u;       //前1次误差值

    sptr->Proportion    = 3.0f;     //比例
    sptr->Integral      = 0.0f;     //积分
    sptr->Derivative    = 0.0f;     //微分

    sptr->iError        = 0;        //当前误差
    sptr->iIncpid       = 0;        //增量误差

    sptr->Uk            = 0;        //输出返回值
}

int IncPIDCalc(int NextPoint)
{
    //当前误差
    sptr->iError = sptr->SetPoint - NextPoint;
    //增量误差
    sptr->iIncpid = sptr->Proportion * sptr->iError - sptr->Integral * sptr->LastError
                    + sptr->Derivative * sptr->PrevError;
    //存储误差，用于下次计算
    sptr->PrevError = sptr->iError;
    sptr->LastError = sptr->LastError;

    sptr->Uk += sptr->iIncpid;

    //输出值限幅
    if (sptr->Uk>>sptr->BitMove >= MAXOUT)
    {
        sptr->Uk = MAXOUT;
    }
    else if(sptr->Uk>>sptr->BitMove <= 0u)
    {
        sptr->Uk = 0;
    }
    else sptr->Uk = sptr->Uk>>sptr->BitMove;

    return (sptr->Uk);
}
