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
#define LENGTH 16

uint8_t data_buffer[LENGTH];                         // Fix to display variables on 2x16 LCD screen.
uint8_t UID_1[LENGTH], UID_2[LENGTH];                                // Fix for storing UID code
unsigned char status_1, status_2;
char temp[LENGTH] = "\0";
int led = 0;
unsigned char TagType1, TagType2;

void __interrupt() high_isr(void);
void __interrupt(low_priority) low_isr(void);

void uart_init(uint16_t gen_reg, unsigned sync, unsigned brgh, unsigned brg16) {
    TRISCbits.RC7 = 1;
    TRISCbits.RC6 = 1;
    
    SPBRGH = (gen_reg & 0xFF00) >> 8;
    SPBRG = gen_reg * 0x00FF;
    
    RCSTAbits.CREN = 1;
    RCSTAbits.SPEN = 1;
    BAUDCONbits.BRG16 = brg16;
    
    TXSTAbits.SYNC = sync;
    TXSTAbits.BRGH = brgh;
    TXSTAbits.TXEN = 1;
    
    IPR1bits.RCIP = 1;
    PIE1bits.RCIE = 1;
    
//    IPR1bits.TXIP = 0;
//    PIE1bits.TXIE = 1;
}

void uart_send(uint8_t *c){
    TXREG = *c;
    while(TXSTAbits.TRMT == 0){
        Nop();
    }
}

void main(void) {
    I2CLCD_Init(100000);                            // initialize I2C bus with clock frequency of 100kHz
    LCD_Begin(0x4E);                                // Initialize LCD module with I2C address = 0x4E
    MFRC522_Init();                                 // MFRC522.
    uart_init(129, 0, 0, 1);
    __delay_ms(500);
    
    LCD_Goto(1, 1);                                 // Go to column 2 row 1
    LCD_Print("Welcome");
    
    __delay_ms(1000);
    LCD_Cmd(LCD_CLEAR);
    
    while (1) {
        MFRC522_IsCard(&TagType1);
        MFRC522_ReadCardSerial(&UID_1);
        status_1 = MFRC522_AntiColl(&UID_1);
        
        MFRC522_IsCard2(&TagType2);
        MFRC522_ReadCardSerial2(&UID_2);
        status_2 = MFRC522_AntiColl2(&UID_2);
        
        if (strlen(UID_1) == 1 || strlen(UID_2) == 1){
            LCD_Cmd(LCD_CLEAR);   
            LCD_Goto(1, 1);
            LCD_Print("ID:");
        } 

        LCD_Goto(1, 2);
        
        if(status_1 == MI_OK) {
            for(int i = 0; i < 5; i++)                // Print the UID code
            {
                sprintf(data_buffer, "%X", UID_1[i]);
                LCD_Print(data_buffer);               // Print Buffer
            }
            __delay_ms(1000);
        } 
        else if(status_2 == MI_OK){
            for(int i = 0; i < 5; i++)                // Print the UID code
            {
                sprintf(data_buffer, "%X", UID_2[i]);
                LCD_Print(data_buffer);               // Print Buffer
            }
            __delay_ms(1000);
        }
        else {
            __delay_ms(50);
            LATB7 = 0;
            MFRC522_Halt();                // Turn off the RFID antenna.
        }
    }
    return;
}

void __interrupt() high_isr(void){
    INTCONbits.GIEH = 0;
    if(PIR1bits.RCIF) {
        PIR1bits.RCIF = 0;
    }
    INTCONbits.GIEH = 1;
}

void __interrupt(low_priority) low_isr(void){
    INTCONbits.GIEH = 0;
    if(PIR1bits.TXIF) {
        PIR1bits.TXIF = 0;
    }
    INTCONbits.GIEH = 1;
}