#ifndef _LCD_LIBRARY_ANIMATION_QVL_
#define _LCD_LIBRARY_ANIMATION_QVL_
#include "LCD_LIBRERIA_QVL.h"

unsigned char caracter[8]={0x0e,0x1f,0x11,0x11,0x11,0x11,0x1f,0x1f};
unsigned char caracter1[8]={0x0e,0x1f,0x11,0x11,0x11,0x1f,0x1f,0x1f};
unsigned char caracter2[8]={0x0e,0x1f,0x11,0x11,0x1f,0x1f,0x1f,0x1f};
unsigned char caracter3[8]={0x0e,0x1f,0x11,0x1f,0x1f,0x1f,0x1f,0x1f};
unsigned char caracter4[8]={0x0e,0x1f,0x1f,0x1f,0x1f,0x1f,0x1f,0x1f};
unsigned char caracter5[8]={0x0e,0x1f,0x1f,0x1f,0x1f,0x1f,0x1f,0x1f};

unsigned char bater[8]={0x05,0x1e,0x0a,0x0a,0x1e,0x05,0x04,0x04};
unsigned char bater1[8]={0x14,0x0f,0x0a,0x0a,0x0f,0x14,0x04,0x04};

unsigned char SENGAL1[8]={0x00,0x00,0x00,0x00,0x00,0x00,0x010,0x18};
unsigned char SENGAL2[8]={0x00,0x00,0x00,0x00,0x00,0x08,0x18,0x18};
unsigned char SENGAL3[8]={0x00,0x00,0x04,0x04,0x0c,0x0c,0x1c,0x1c};
unsigned char SENGAL4[8]={0x02,0x02,0x06,0x06,0x0e,0x0e,0x1e,0x1e};
unsigned char SENGAL5[8]={0x03,0x03,0x07,0x07,0x0f,0x0f,0x1f,0x1f};
unsigned char SENGAL0[8]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

unsigned char BOCINA[8]={0x00,0x003,0x07,0x0d,0x0d,0x07,0x003,0x01f};
unsigned char SONIDO0[8]={0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00011111};
unsigned char SONIDO1[8]={0b00000000,0b00000000,0b00000000,0b00000000,0b00000000,0b00010000,0b00010000,0b00011111};
unsigned char SONIDO2[8]={0b00000000,0b00000000,0b00000000,0b00000000,0b00001000,0b00011000,0b00011000,0b00011111};
unsigned char SONIDO3[8]={0b00000000,0b00000000,0b00000000,0b00000100,0b00001100,0b00011100,0b00011100,0b00011111};
unsigned char SONIDO4[8]={0b00000000,0b00000000,0b00000010,0b00000110,0b00001110,0b00011110,0b00011110,0b00011111};
unsigned char SONIDO5[8]={0b00000000,0b00000001,0b00000011,0b00000111,0b00001111,0b00011111,0b00011111,0b00011111};



void NIVEL_SONIDO(int8_t/*DIRECCON GDRAM*/,int8_t/*DIRECCION DDRAM*/,int8_t/*NIVEL VOLUMEN*/);
void NIVEL_SONIDO(int8_t X,int8_t Y,int8_t Z){
int VOLUMEN=0;
if(Z<=20){VOLUMEN=20;}else{if(Z<=40){VOLUMEN=40;}else{if(Z<=60){VOLUMEN=60;}else{if(Z<=80){VOLUMEN=80;}else{if(Z<=100){VOLUMEN=100;}}}}}
CARACTERES_PERSONALIZADOS(X,BOCINA);
POSICIONES_DIRECCIONES_DDRAM(Y);
SEND_DATA(X);
PAUSE_FLUJO(100,1,0,1);
switch(VOLUMEN){
case 0:
CARACTERES_PERSONALIZADOS(X+1,SONIDO0);break;
case 20:
CARACTERES_PERSONALIZADOS(X+1,SONIDO1);break;
case 40:
CARACTERES_PERSONALIZADOS(X+1,SONIDO2);break;
case 60:
CARACTERES_PERSONALIZADOS(X+1,SONIDO3);break;
case 80:
CARACTERES_PERSONALIZADOS(X+1,SONIDO4);break;
case 100:
CARACTERES_PERSONALIZADOS(X+1,SONIDO5);break;}
POSICIONES_DIRECCIONES_DDRAM(Y+1);
SEND_DATA(X+1);}
#endif