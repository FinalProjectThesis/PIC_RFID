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

unsigned char data_buffer[LENGTH];                         // Arreglo para mostrar las variabes en la pantalla LCD 2x16.
uint8_t UID[LENGTH];                                // Arreglo para almacena el c?digo del UID
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
        LCD_Goto(1, 1);
        LCD_Print("ID:");
      
        while(!MFRC522_IsCard(&TagType));           // Verifica si hay TAG presente.
        while(!MFRC522_ReadCardSerial(&UID));      // Lee el c?digo del TAG.
        LCD_Goto(1, 2);           
 
        for(uint8_t i=0; i < 4; i++)                // Imprime el c?digo del UID
        {
            sprintf(data_buffer, "%X", UID[i]);
            LCD_Print(data_buffer);               // Print Buffer

        }    
        // led operator
//        if (led == 1)
//        {
//            LATB7 = 1;
//        } else {
//            LATB7 = 0;
//        }
   
        __delay_ms(1000);
        MFRC522_Halt();                // Turn off the RFID antenna.
        LCD_Cmd(LCD_CLEAR);
    }
    return;
}

void port_Init(void){
    // Initialize ports
    TRISB7 = 0;
    LATB7 = 0;                      // Low at initial
}