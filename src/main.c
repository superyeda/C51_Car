#include "REG52.H"
#include "car.h"
#include "key.h"
sbit buz=P2^3;
sbit L_LED=P3^4;
sbit R_LED=P3^5;
sbit L_LED1=P3^2;
sbit R_LED1=P3^3;
sbit LED = P1^0;
int flag = 0;
void timer0Init(){
    TR0=1;      //������ʱ��0 
    TMOD|=0x02;  //��ʱ��ģʽ
    TH0=0x4b;   //���ø߰�λ
    TL0=0xfc;   //���õͰ�λ
    ET0=1;
    TF0=0;      //��ձ�־λ
    EA=1;
}

void bz(){
   // ����
    while (1)
    {
        if(KEY2==0)
            break;
        if(L_LED && R_LED)car(1);
        if(R_LED==0 && L_LED)car(2);
        if(L_LED==0 && R_LED)car(3);
        if(L_LED==0 && R_LED==0) car(4);
    }
}

void xj(){
    // Ѱ��
    while (1)
    {
        if(KEY1==0) break;
        if(L_LED1 && R_LED1)car(1);
        if(L_LED1==0 && R_LED1)car(2);
        if(R_LED1==0 && L_LED1)car(3);
        if(L_LED1==0 && R_LED1==0)car(4);
    }
}
unsigned char PWM_COUNT,PWM_VALUE;


void main(){
    PWM_COUNT=7;
    PWM_VALUE=3;
    timer0Init();
    while (1)
    {
    if(!KEY1)bz();
    if(!KEY2)xj();
    }
}
void time0Rupt() interrupt 1
{ 
    
    PWM_COUNT--;
    if(PWM_COUNT == PWM_VALUE)ENA=ENB=1;
    if(PWM_COUNT==0)
    {
        ENA=ENB=0;
        PWM_COUNT=10;
    }

}