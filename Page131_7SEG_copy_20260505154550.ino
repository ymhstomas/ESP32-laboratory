 //Page131_七段顯示器
 #include <Arduino.h>
 const int LEDIO[8]={13,12,14,27,26,25,33,32}; //定義LED控制腳矩陣變數
byte table[10]={0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};//共陽七段顯示器資料表

void Disp7seg(byte temp)
 {
 for(short j=0;j<8;j++)
  {
   if(temp & 0x01)     //判別a~dp LED需要的狀態
    digitalWrite(LEDIO[j],HIGH); //輸出高電位
   else
    digitalWrite(LEDIO[j],LOW);  //輸出低電位
   temp=temp>>1;      //將需顯示的資料右移一個位元
  }
 }
 void setup() 
{
 for(short i=0;i<8;i++)   //設定所有控制腳為輸出
  pinMode(LEDIO[i],OUTPUT);
 }
 void loop() 
{
 for(short i=0;i<10;i++)  //重複執行10次
  {
  Disp7seg(table[i]);  //取出table中的顯示資料
  delay(300);     //延遲0.3s
  }
 }
