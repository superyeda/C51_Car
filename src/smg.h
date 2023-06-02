#ifndef SMG_H
#define SMG_H
sbit WE=P2^7;
sbit DU=P2^6;
// ÊıÂë¹Ü
int wei[8]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
int gy[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
void delay(int time){
    int x,y;
    for(x=time;x>0;x--)
        for(y=114;y>0;y--);
}

void smg(int sta,int n){
   int num[4];
   int x,y=0;
   int j;
   if(n<10)x=3;else 
   if(n<100)x=2;
   else if(n<1000)x=1;
   else if(n<10000)x=0;
   num[0]=n/1000;
   num[1]=n%1000/100;
   num[2]=n%100/10;
   num[3]=n%10;
   for(j=x;j<4;j++,y++){
        WE=1;
        P0=wei[sta+y];
        WE=0;
        DU=1;
        P0=gy[num[j]];
        DU=0;
        delay(2);
        P0=0xff;
   }
}

#endif