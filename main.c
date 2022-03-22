/*
 * File:   main.c
 * Author: raule
 *
 * Created on March 17, 2022, 11:28 PM
 */
#include "config.h"
#include "I2C.h"
#include "rc522.h"
#define _XTAL_FREQ 27000000
#define LENGTH 16

unsigned char data_buffer[LENGTH];                         // Fix to display variables on 2x16 LCD screen.
unsigned char UID[LENGTH];                                // Fix for storing UID code
unsigned char status;
char temp[LENGTH] = "\0";

int led = 0;
unsigned char TagType;

void port_Init (void); 

void main(void) {
    port_Init();                                    // initialize ports
    I2CLCD_Init(100000);                            // initialize I2C bus with clock frequency of 100kHz
    LCD_Begin(0x4E);                                // Initialize LCD module with I2C address = 0x4E
    MFRC522_Init();                                 // MFRC522.
    __delay_ms(500);
    
    LCD_Goto(1, 1);                                 // Go to column 2 row 1
    LCD_Print("Welcome");
    LATB7 = 1;
    
    __delay_ms(2000);
    LCD_Cmd(LCD_CLEAR);
    LATB7 = 0;
    
    while (1) {
        MFRC522_IsCard(&TagType);
        MFRC522_ReadCardSerial(&UID);
        status = MFRC522_AntiColl(&UID);
        
        if (strlen(UID) == 1){
            LCD_Cmd(LCD_CLEAR);   
            LCD_Goto(1, 1);
            sprintf(temp, "%d", strlen(UID));
            LCD_Print(temp);
        } 
        else {
            LCD_Cmd(LCD_CLEAR);   
            LCD_Goto(1, 1);
            sprintf(temp, "%d", strlen(UID));
            LCD_Print(temp);
        }
        
        LCD_Goto(1, 2);
        
        if(status == MI_OK) {
            for(int i = 0; i < 5; i++)                // Print the UID code
            {
                sprintf(data_buffer, "%X", UID[i]);
                LCD_Print(data_buffer);               // Print Buffer
            }
            LATB7 = 1;
            __delay_ms(1000);
        } else {
            __delay_ms(50);
            LATB7 = 0;
            MFRC522_Halt();                // Turn off the RFID antenna.
        }
    }
    return;
}

void port_Init(void){
    // Initialize ports
    TRISB7 = 0;
    LATB7 = 0;                      // Low at initial
}