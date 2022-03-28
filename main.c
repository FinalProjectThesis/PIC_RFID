/*
 * File:   main.c
 * Author: raule
 *
 * Created on March 17, 2022, 11:28 PM
 */
#include "config.h"
#include "I2C.h"
#include "rc522.h"
#include <stdbool.h>
#define _XTAL_FREQ 27000000
#define F_CPU _XTAL_FREQ/64
#define Baud_value (((float)(F_CPU)/(float)baud_rate)-1)
#define LENGTH 20

uint8_t data[LENGTH] = "hello";
uint8_t data_buffer[LENGTH];                         // Fix to display variables on 2x16 LCD screen.
uint8_t UID_1[LENGTH], UID_2[LENGTH];                                // Fix for storing UID code
unsigned char status_1, status_2;
char temp[LENGTH] = "\0";
int led = 0;
unsigned char TagType1, TagType2;

void USART_Init(long);
void USART_TxChar(char*);
char USART_RxChar();

void main(void) {
    I2CLCD_Init(100000);                            // initialize I2C bus with clock frequency of 100kHz
    LCD_Begin(0x4E);                                // Initialize LCD module with I2C address = 0x4E
    MFRC522_Init();                                 // MFRC522.
    USART_Init(9600);
    
    __delay_ms(500);
    while (1) {
        MFRC522_IsCard(&TagType1);
        MFRC522_ReadCardSerial(&UID_1);
        status_1 = MFRC522_AntiColl(&UID_1);
        
        MFRC522_IsCard2(&TagType2);
        MFRC522_ReadCardSerial2(&UID_2);
        status_2 = MFRC522_AntiColl2(&UID_2);  
       
        if(strlen(UID_1) == 1 || strlen(UID_2) == 1){
            LCD_Cmd(LCD_CLEAR);   
        }

        LCD_Goto(1, 2);
        
        if(status_1 == MI_OK) {
            USART_TxChar("P1");
            for(uint8_t i = 0; i < 5; i++)                // Print the UID code
            {
                sprintf(data_buffer, "%X", UID_1[i]);
                LCD_Print(data_buffer);               // Print Buffer
                USART_TxChar(data_buffer);
            }
            LCD_Goto(1, 1);
            LCD_Print("Position 1");
            __delay_ms(500);
        } 
        
        if(status_2 == MI_OK){
            USART_TxChar("P2");
            for(uint8_t i = 0; i < 5; i++)                // Print the UID code
            {
                sprintf(data_buffer, "%X", UID_2[i]);
                LCD_Print(data_buffer);               // Print Buffer
                
                USART_TxChar(data_buffer);
            }
            LCD_Goto(1, 1);
            LCD_Print("Position 2");
            __delay_ms(500);
        }
        
        __delay_ms(50);
        MFRC522_Halt();                // Turn off the RFID antenna.
    }
}

void USART_Init(long baud_rate){
    float temp;
    TRISC6 = 0;                       /*Make Tx pin as output*/
    TRISC7 = 1;                       /*Make Rx pin as input*/
    temp = Baud_value;     
    SPBRG=(int)temp;                /*baud rate=9600, SPBRG = (F_CPU /(64*9600))-1*/
    TXSTA = 0x20;                     /*Transmit Enable(TX) enable*/ 
    RCSTA = 0x90;                     /*Receive Enable(RX) enable and serial port enable */
    INTCONbits.GIE = 1;	/* Enable Global Interrupt */
    INTCONbits.PEIE = 1;/* Enable Peripheral Interrupt */
    PIE1bits.RCIE = 1;	/* Enable Receive Interrupt*/
    PIE1bits.TXIE = 1;	/* Enable Transmit Interrupt*/
}

void USART_TxChar(char* out){        
        while(TXIF == 0);            /*wait for transmit interrupt flag*/
        for (uint8_t i = 0; i < strlen(out); i++) {
            TXREG = out[i];                 /*transmit data via TXREG register*/
        }

}

char USART_RxChar(){
    while(RCIF==0);       /*wait for receive interrupt flag*/
        if(RCSTAbits.OERR)
        {           
            CREN = 0;
            NOP();
            CREN=1;
        }
        return(RCREG);   /*receive data is stored in RCREG register and return */
}