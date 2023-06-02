#ifndef CAR_H
#define CAR_H
#include "smg.h"
sbit IN1=P1^2;
sbit IN2=P1^3;
sbit ENA=P1^4;
sbit ENB=P1^5;
sbit IN3=P1^6;
sbit IN4=P1^7;
/**
 * @brief 小车控制
 * 
 * @param move 0.停止 1.前进 2.左转 3.右转 4.后退
 */
void car(int move){
    if(move==1){
        IN1=0;IN2=1;
        // IN3=0;IN4=1; 
        IN3=1;IN4=0; 
        smg(2,1);
    }
    if(move==2){
         ENA=1;
        ENB=1;
        IN1=0;IN2=0;
        // IN3=0;IN4=1;
        IN3=1;IN4=0; 
        smg(2,2); 
    }
    if(move==3){
         ENA=1;
        ENB=1;
        IN1=0;IN2=1;
        IN3=0;IN4=0; 
        smg(2,3);
    }
    if(move==4){
        IN1=1;IN2=0;
        // IN3=1;IN4=0; 
        IN3=0;IN4=1;
        smg(2,4);
    }
    if(move==0){
        ENA=0;
        ENB=0;
        smg(2,0);
    }
}

#endif