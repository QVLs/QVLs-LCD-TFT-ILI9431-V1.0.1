#ifndef LIBRERIA_DELAY_QVL
#define LIBRERIA_DELAY_QVL
#include <avr/io.h>
#define BIT0 0
#define BIT1 1
void PAUSE_FLUJO(uint16_t DELAY,int CS_12,int CS_11,int CS_10);
/*FUNCION DE RETARDO DEL FLUJO DE EJECUCION DDE INSTRUCCION DEL MICROCONTROLARDOR*/
/*CS12  CS11  CS10*/
/*0       0     0     1*/
/*0       0     1     8*/
/*0       1     0     64*/
/*0       1     1     256*/
/*1       0     0     1024*/
/*1       0     1*/
/*1       1     0*/
void PAUSE_FLUJO(uint16_t DELAY,int CS_12,int CS_11,int CS_10){
int C_12=CS_12;
int C_11=CS_11;
int C_10=CS_10;
int TEMP=DELAY;
if ((C_12==BIT0)&&(C_11==BIT1)&&(C_10==BIT1)){TCCR1B=0x03;}else{
if((C_12==BIT0)&&(C_11==BIT1)&&(C_10==BIT0)){TCCR1B=0x02;}else{
if((C_12==BIT1)&&(C_11==BIT0)&&(C_10==BIT1)){TCCR1B=0x05;}else{
if((C_12==BIT1)&&(C_11==BIT1)&&(C_10==BIT0)){TCCR1B=0x04;}else{
if((C_12==BIT0)&&(C_11==BIT0)&&(C_10==BIT1)){TCCR1B=0x01;}}}}}
TCNT1=BIT0;
while((TCNT1<TEMP)){}
TCNT1=BIT0;}
/*FUNCION DE RETARDO DEL FLUJO DE PROGRAMACION DEL MICROCONTROLARDOR*/
#endif


