//CH5-2-10TWO7SEG0-99
//CH5_2_10TWOSEG00_99_v0507
#include <Arduino.h>
const int LEDIO[8]={13,12,14,27,26,25,33,32}; // 定義七段資料線控制腳矩陣變數
byte table[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90}; // 共陽七段顯示器資料表
const int SCANIO[2]={16,17};
void Disp7seg(byte temp)
{
 for(short j=0;j<8;j++)
 {
 if(temp & 0x01) // 判別a~dp 節段LED 需要的狀態
 digitalWrite(LEDIO[j],HIGH); // 輸出高電位
 else
 digitalWrite(LEDIO[j],LOW); // 輸出低電位
 temp=temp>>1; // 將七段需顯示的資料右移一個位元
 }
}
void setup()
 {
 for(short i=0;i<8;i++) // 設定所有控制腳為輸出
 pinMode(LEDIO[i],OUTPUT);
 for(short i=0;i<2;i++) // 設定所有控制腳為輸出
 pinMode(SCANIO[i],OUTPUT);
 }
void loop()
 {
 for(short i=0;i<=99;i++) //顯示由00~99
 {
 for(short k=0;k<50;k++) // 重複顯示的次數
 { //數字上數間隔為50*6ms
 Disp7seg(table[i/10]); // 取出欲顯示的十位數資料
 digitalWrite(17,LOW); // 打開十位數
 digitalWrite(16,HIGH); // 關閉個位數
delay(3); //延遲3ms
Disp7seg(0); //減少鬼影
Disp7seg(table[i%10]); // 取出欲顯示的個位數資料
digitalWrite(17,HIGH); // 關閉十位數
digitalWrite(16,LOW); // 打開個位數
delay(4);
Disp7seg(0); //減少鬼影
}
}
}
