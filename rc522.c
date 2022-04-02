#include "rc522.h"                
unsigned char MFRC522_Rd(unsigned char address)
{
    unsigned int i, ucAddr;
    unsigned int ucResult = 0;
    MFRC522_CLK_PIN = 0;
    MFRC522_CS_PIN = 0;
    ucAddr = ((address << 1) & 0x7E) | 0x80;
    
    for(i=8; i>0; i--)
    {
        MFRC522_SDO_PIN = ((ucAddr & 0x80) == 0x80);
        MFRC522_CLK_PIN = 1;
        ucAddr <<= 1;
        MFRC522_CLK_PIN = 0;
    }
    for(i=8; i>0; i--)
    {
        MFRC522_CLK_PIN = 1;
        ucResult <<= 1;
        ucResult |= (short)MFRC522_SDI_PIN;
        MFRC522_CLK_PIN = 0;
    }
    MFRC522_CS_PIN = 1;
    MFRC522_CLK_PIN = 1;
    return ucResult;
}

unsigned char MFRC522_Rd2(unsigned char address)
{
    unsigned int i, ucAddr;
    unsigned int ucResult = 0;
    MFRC522_CLK_PIN = 0;
    MFRC522_CS_PIN2 = 0;
    ucAddr = ((address << 1) & 0x7E) | 0x80;
    
    for(i=8; i>0; i--)
    {
        MFRC522_SDO_PIN = ((ucAddr & 0x80) == 0x80);
        MFRC522_CLK_PIN = 1;
        ucAddr <<= 1;
        MFRC522_CLK_PIN = 0;
    }
    for(i=8; i>0; i--)
    {
        MFRC522_CLK_PIN = 1;
        ucResult <<= 1;
        ucResult |= (short)MFRC522_SDI_PIN;
        MFRC522_CLK_PIN = 0;
    }
    MFRC522_CS_PIN2 = 1;
    MFRC522_CLK_PIN = 1;
    return ucResult;
}

unsigned char MFRC522_Rd3(unsigned char address)
{
    unsigned int i, ucAddr;
    unsigned int ucResult = 0;
    MFRC522_CLK_PIN = 0;
    MFRC522_CS_PIN3 = 0;
    ucAddr = ((address << 1) & 0x7E) | 0x80;
    
    for(i=8; i>0; i--)
    {
        MFRC522_SDO_PIN = ((ucAddr & 0x80) == 0x80);
        MFRC522_CLK_PIN = 1;
        ucAddr <<= 1;
        MFRC522_CLK_PIN = 0;
    }
    for(i=8; i>0; i--)
    {
        MFRC522_CLK_PIN = 1;
        ucResult <<= 1;
        ucResult |= (short)MFRC522_SDI_PIN;
        MFRC522_CLK_PIN = 0;
    }
    MFRC522_CS_PIN3 = 1;
    MFRC522_CLK_PIN = 1;
    return ucResult;
}

unsigned char MFRC522_Rd4(unsigned char address)
{
    unsigned int i, ucAddr;
    unsigned int ucResult = 0;
    MFRC522_CLK_PIN = 0;
    MFRC522_CS_PIN4 = 0;
    ucAddr = ((address << 1) & 0x7E) | 0x80;
    
    for(i=8; i>0; i--)
    {
        MFRC522_SDO_PIN = ((ucAddr & 0x80) == 0x80);
        MFRC522_CLK_PIN = 1;
        ucAddr <<= 1;
        MFRC522_CLK_PIN = 0;
    }
    for(i=8; i>0; i--)
    {
        MFRC522_CLK_PIN = 1;
        ucResult <<= 1;
        ucResult |= (short)MFRC522_SDI_PIN;
        MFRC522_CLK_PIN = 0;
    }
    MFRC522_CS_PIN4 = 1;
    MFRC522_CLK_PIN = 1;
    return ucResult;
}

void MFRC522_Wr(unsigned char address, unsigned char value)
{
    unsigned char i, ucAddr;
    MFRC522_CLK_PIN = 0;
    MFRC522_CS_PIN = 0;
    ucAddr = ((address << 1) & 0x7E);
    
    for(i=8; i>0; i--)
    {
        MFRC522_SDO_PIN = ((ucAddr&0x80) == 0x80);
        MFRC522_CLK_PIN = 1;
        ucAddr <<= 1;
        MFRC522_CLK_PIN = 0;
    }
    for(i=8; i>0; i--)
    {
        MFRC522_SDO_PIN = ((value&0x80) == 0x80);
        MFRC522_CLK_PIN = 1;
        value <<= 1;
        MFRC522_CLK_PIN = 0;
    }
    MFRC522_CS_PIN = 1;
    MFRC522_CLK_PIN = 1;
}

void MFRC522_Wr2(unsigned char address, unsigned char value)
{
    unsigned char i, ucAddr;
    MFRC522_CLK_PIN = 0;
    MFRC522_CS_PIN2 = 0;
    ucAddr = ((address << 1) & 0x7E);
    
    for(i=8; i>0; i--)
    {
        MFRC522_SDO_PIN = ((ucAddr&0x80) == 0x80);
        MFRC522_CLK_PIN = 1;
        ucAddr <<= 1;
        MFRC522_CLK_PIN = 0;
    }
    for(i=8; i>0; i--)
    {
        MFRC522_SDO_PIN = ((value&0x80) == 0x80);
        MFRC522_CLK_PIN = 1;
        value <<= 1;
        MFRC522_CLK_PIN = 0;
    }
    MFRC522_CS_PIN2 = 1;
    MFRC522_CLK_PIN = 1;
}

void MFRC522_Wr3(unsigned char address, unsigned char value)
{
    unsigned char i, ucAddr;
    MFRC522_CLK_PIN = 0;
    MFRC522_CS_PIN3 = 0;
    ucAddr = ((address << 1) & 0x7E);
    
    for(i=8; i>0; i--)
    {
        MFRC522_SDO_PIN = ((ucAddr&0x80) == 0x80);
        MFRC522_CLK_PIN = 1;
        ucAddr <<= 1;
        MFRC522_CLK_PIN = 0;
    }
    for(i=8; i>0; i--)
    {
        MFRC522_SDO_PIN = ((value&0x80) == 0x80);
        MFRC522_CLK_PIN = 1;
        value <<= 1;
        MFRC522_CLK_PIN = 0;
    }
    MFRC522_CS_PIN3 = 1;
    MFRC522_CLK_PIN = 1;
}

void MFRC522_Wr4(unsigned char address, unsigned char value)
{
    unsigned char i, ucAddr;
    MFRC522_CLK_PIN = 0;
    MFRC522_CS_PIN4 = 0;
    ucAddr = ((address << 1) & 0x7E);
    
    for(i=8; i>0; i--)
    {
        MFRC522_SDO_PIN = ((ucAddr&0x80) == 0x80);
        MFRC522_CLK_PIN = 1;
        ucAddr <<= 1;
        MFRC522_CLK_PIN = 0;
    }
    for(i=8; i>0; i--)
    {
        MFRC522_SDO_PIN = ((value&0x80) == 0x80);
        MFRC522_CLK_PIN = 1;
        value <<= 1;
        MFRC522_CLK_PIN = 0;
    }
    MFRC522_CS_PIN4 = 1;
    MFRC522_CLK_PIN = 1;
}

static void MFRC522_Clear_Bit(char addr, char mask)
{
    unsigned char tmp = 0;
    tmp = MFRC522_Rd(addr) ;
    MFRC522_Wr(addr, tmp&~mask);
}

static void MFRC522_Clear_Bit2(char addr, char mask)
{
    unsigned char tmp = 0;
    tmp = MFRC522_Rd2(addr) ;
    MFRC522_Wr2(addr, tmp&~mask);
}

static void MFRC522_Clear_Bit3(char addr, char mask)
{
    unsigned char tmp = 0;
    tmp = MFRC522_Rd3(addr) ;
    MFRC522_Wr3(addr, tmp&~mask);
}

static void MFRC522_Clear_Bit4(char addr, char mask)
{
    unsigned char tmp = 0;
    tmp = MFRC522_Rd4(addr) ;
    MFRC522_Wr4(addr, tmp&~mask);
}


static void MFRC522_Set_Bit(char addr, char mask)
{
    unsigned char tmp = 0;
    tmp = MFRC522_Rd(addr);
    MFRC522_Wr(addr, tmp | mask);
}

static void MFRC522_Set_Bit2(char addr, char mask)
{
    unsigned char tmp = 0;
    tmp = MFRC522_Rd2(addr);
    MFRC522_Wr2(addr, tmp | mask);
}

static void MFRC522_Set_Bit3(char addr, char mask)
{
    unsigned char tmp = 0;
    tmp = MFRC522_Rd3(addr);
    MFRC522_Wr3(addr, tmp | mask);
}

static void MFRC522_Set_Bit4(char addr, char mask)
{
    unsigned char tmp = 0;
    tmp = MFRC522_Rd4(addr);
    MFRC522_Wr4(addr, tmp | mask);
}

void MFRC522_Reset(void)
{ 
    // RFID 1
    MFRC522_RST_PIN = 1;
    __delay_us(1);
    MFRC522_RST_PIN = 0;
    __delay_us(1);
    MFRC522_RST_PIN = 1;
    __delay_us(1);
    MFRC522_Wr(COMMANDREG, PCD_RESETPHASE);
    __delay_us(1);
    // RFID 2
    MFRC522_RST_PIN = 1;
    __delay_us(1);
    MFRC522_RST_PIN = 0;
    __delay_us(1);
    MFRC522_RST_PIN = 1;
    __delay_us(1);
    MFRC522_Wr2(COMMANDREG, PCD_RESETPHASE);
    __delay_us(1);
    // RFID 3
    MFRC522_RST_PIN = 1;
    __delay_us(1);
    MFRC522_RST_PIN = 0;
    __delay_us(1);
    MFRC522_RST_PIN = 1;
    __delay_us(1);
    MFRC522_Wr3(COMMANDREG, PCD_RESETPHASE);
    __delay_us(1);
    // RFID 4
    MFRC522_RST_PIN = 1;
    __delay_us(1);
    MFRC522_RST_PIN = 0;
    __delay_us(1);
    MFRC522_RST_PIN = 1;
    __delay_us(1);
    MFRC522_Wr4(COMMANDREG, PCD_RESETPHASE);
    __delay_us(1);
}

void MFRC522_AntennaOn(void)
{
    unsigned char stt;
    stt = MFRC522_Rd(TXCONTROLREG);
    MFRC522_Set_Bit(TXCONTROLREG, 0x03);
}

void MFRC522_AntennaOn2(void)
{
    unsigned char stt;
    stt = MFRC522_Rd2(TXCONTROLREG);
    MFRC522_Set_Bit2(TXCONTROLREG, 0x03);
}

void MFRC522_AntennaOn3(void)
{
    unsigned char stt;
    stt = MFRC522_Rd3(TXCONTROLREG);
    MFRC522_Set_Bit3(TXCONTROLREG, 0x03);
}

void MFRC522_AntennaOn4(void)
{
    unsigned char stt;
    stt = MFRC522_Rd4(TXCONTROLREG);
    MFRC522_Set_Bit4(TXCONTROLREG, 0x03);
}

void MFRC522_AntennaOff(void)
{
    MFRC522_Clear_Bit(TXCONTROLREG, 0x03);
}

void MFRC522_AntennaOff2(void)
{
    MFRC522_Clear_Bit2(TXCONTROLREG, 0x03);
}

void MFRC522_AntennaOff3(void)
{
    MFRC522_Clear_Bit3(TXCONTROLREG, 0x03);
}

void MFRC522_AntennaOff4(void)
{
    MFRC522_Clear_Bit4(TXCONTROLREG, 0x03);
}

void MFRC522_Init(void)
{
    MFRC522_SDO_DIR = 0;
    MFRC522_CLK_DIR = 0;
    MFRC522_CS_DIR = 0;         // DIR 1
    MFRC522_CS_DIR2 = 0;        // DIR 2
    MFRC522_CS_DIR3 = 0;        // DIR 3
    MFRC522_CS_DIR4 = 0;        // DIR 4
    MFRC522_SDI_DIR = 1;
    MFRC522_RST_DIR = 0;
    MFRC522_CLK_PIN = 0;
    MFRC522_SDO_PIN = 0;
    MFRC522_CS_PIN = 1;         // Chip Select 1
    MFRC522_CS_PIN2 = 1;        // Chip Select 2
    MFRC522_CS_PIN3 = 1;        // Chip Select 3
    MFRC522_CS_PIN4 = 1;        // Chip Select 4
    MFRC522_RST_PIN = 1;
    MFRC522_Reset();
    // RFID 1
    MFRC522_Wr(TMODEREG, 0x8D);
    MFRC522_Wr(TPRESCALERREG, 0x3E);
    MFRC522_Wr(TRELOADREGL, 30);
    MFRC522_Wr(TRELOADREGH, 0);
    MFRC522_Wr(TXAUTOREG, 0x40);
    MFRC522_Wr(MODEREG, 0x3D);
    MFRC522_AntennaOff();
    MFRC522_AntennaOn();
    // RFID 2
    MFRC522_Wr2(TMODEREG, 0x8D);
    MFRC522_Wr2(TPRESCALERREG, 0x3E);
    MFRC522_Wr2(TRELOADREGL, 30);
    MFRC522_Wr2(TRELOADREGH, 0);
    MFRC522_Wr2(TXAUTOREG, 0x40);
    MFRC522_Wr2(MODEREG, 0x3D);
    MFRC522_AntennaOff2();
    MFRC522_AntennaOn2();
    // RFID 3
    MFRC522_Wr3(TMODEREG, 0x8D);
    MFRC522_Wr3(TPRESCALERREG, 0x3E);
    MFRC522_Wr3(TRELOADREGL, 30);
    MFRC522_Wr3(TRELOADREGH, 0);
    MFRC522_Wr3(TXAUTOREG, 0x40);
    MFRC522_Wr3(MODEREG, 0x3D);
    MFRC522_AntennaOff3();
    MFRC522_AntennaOn3();
    // RFID 4
    MFRC522_Wr4(TMODEREG, 0x8D);
    MFRC522_Wr4(TPRESCALERREG, 0x3E);
    MFRC522_Wr4(TRELOADREGL, 30);
    MFRC522_Wr4(TRELOADREGH, 0);
    MFRC522_Wr4(TXAUTOREG, 0x40);
    MFRC522_Wr4(MODEREG, 0x3D);
    MFRC522_AntennaOff4();
    MFRC522_AntennaOn4();
}

char MFRC522_ToCard(char command, char *sendData, char sendLen, char *backData, unsigned *backLen)
{
    char _status = MI_ERR;
    char irqEn = 0x00;
    char waitIRq = 0x00;
    char lastBits;
    char n;
    unsigned i;
    
    switch(command)
    {
        case PCD_AUTHENT:
            irqEn = 0x12;
            waitIRq = 0x10;
            break;
            
        case PCD_TRANSCEIVE:
            irqEn = 0x77;
            waitIRq = 0x30;
            break;
            
        default:
            break;
    }
    MFRC522_Wr(COMMIENREG, irqEn | 0x80);
    MFRC522_Clear_Bit(COMMIRQREG, 0x80);
    MFRC522_Set_Bit(FIFOLEVELREG, 0x80);
    MFRC522_Wr(COMMANDREG, PCD_IDLE);
    
    for(i=0; i<sendLen; i++)
    {
        MFRC522_Wr(FIFODATAREG, sendData[i]);
    }
    MFRC522_Wr(COMMANDREG, command);
    if(command == PCD_TRANSCEIVE)
    {
        MFRC522_Set_Bit(BITFRAMINGREG, 0x80);
    }
    i = 0xFFFF;  
    do
    {
        n = MFRC522_Rd(COMMIRQREG);
        i--;
    }while(i && !(n & 0x01) && !(n & waitIRq));
    
    MFRC522_Clear_Bit(BITFRAMINGREG, 0x80);   
    if(i != 0)
    {
        if(!(MFRC522_Rd(ERRORREG) & 0x1B))
        {
            _status = MI_OK;
            if(n & irqEn & 0x01)
            {
                _status = MI_NOTAGERR;
            }
            if(command == PCD_TRANSCEIVE)
            {
                n = MFRC522_Rd(FIFOLEVELREG);
                lastBits = MFRC522_Rd(CONTROLREG) & 0x07;
                if(lastBits)
                {
                    *backLen = (n-1) * 8 + lastBits;
                }
                else
                {
                    *backLen = n * 8;
                }
                if(n == 0)
                {
                    n = 1;
                }
                if(n > 16)
                {
                    n = 16;
                }
                for(i=0; i<n; i++)
                {
                    backData[i] = MFRC522_Rd(FIFODATAREG);
                }
                backData[i] = 0;
            }
        }
        else
        {
            _status = MI_ERR;
        }
    }
    return _status;
}

char MFRC522_ToCard2(char command, char *sendData, char sendLen, char *backData, unsigned *backLen)
{
    char _status = MI_ERR;
    char irqEn = 0x00;
    char waitIRq = 0x00;
    char lastBits;
    char n;
    unsigned i;
    
    switch(command)
    {
        case PCD_AUTHENT:
            irqEn = 0x12;
            waitIRq = 0x10;
            break;
            
        case PCD_TRANSCEIVE:
            irqEn = 0x77;
            waitIRq = 0x30;
            break;
            
        default:
            break;
    }
    MFRC522_Wr2(COMMIENREG, irqEn | 0x80);
    MFRC522_Clear_Bit2(COMMIRQREG, 0x80);
    MFRC522_Set_Bit2(FIFOLEVELREG, 0x80);
    MFRC522_Wr2(COMMANDREG, PCD_IDLE);
    
    for(i=0; i<sendLen; i++)
    {
        MFRC522_Wr2(FIFODATAREG, sendData[i]);
    }
    MFRC522_Wr2(COMMANDREG, command);
    if(command == PCD_TRANSCEIVE)
    {
        MFRC522_Set_Bit2(BITFRAMINGREG, 0x80);
    }
    i = 0xFFFF;  
    do
    {
        n = MFRC522_Rd2(COMMIRQREG);
        i--;
    }while(i && !(n & 0x01) && !(n & waitIRq));
    
    MFRC522_Clear_Bit2(BITFRAMINGREG, 0x80);   
    if(i != 0)
    {
        if(!(MFRC522_Rd2(ERRORREG) & 0x1B))
        {
            _status = MI_OK;
            if(n & irqEn & 0x01)
            {
                _status = MI_NOTAGERR;
            }
            if(command == PCD_TRANSCEIVE)
            {
                n = MFRC522_Rd2(FIFOLEVELREG);
                lastBits = MFRC522_Rd2(CONTROLREG) & 0x07;
                if(lastBits)
                {
                    *backLen = (n-1) * 8 + lastBits;
                }
                else
                {
                    *backLen = n * 8;
                }
                if(n == 0)
                {
                    n = 1;
                }
                if(n > 16)
                {
                    n = 16;
                }
                for(i=0; i<n; i++)
                {
                    backData[i] = MFRC522_Rd2(FIFODATAREG);
                }
                backData[i] = 0;
            }
        }
        else
        {
            _status = MI_ERR;
        }
    }
    return _status;
}

char MFRC522_ToCard3(char command, char *sendData, char sendLen, char *backData, unsigned *backLen)
{
    char _status = MI_ERR;
    char irqEn = 0x00;
    char waitIRq = 0x00;
    char lastBits;
    char n;
    unsigned i;
    
    switch(command)
    {
        case PCD_AUTHENT:
            irqEn = 0x12;
            waitIRq = 0x10;
            break;
            
        case PCD_TRANSCEIVE:
            irqEn = 0x77;
            waitIRq = 0x30;
            break;
            
        default:
            break;
    }
    MFRC522_Wr3(COMMIENREG, irqEn | 0x80);
    MFRC522_Clear_Bit3(COMMIRQREG, 0x80);
    MFRC522_Set_Bit3(FIFOLEVELREG, 0x80);
    MFRC522_Wr3(COMMANDREG, PCD_IDLE);
    
    for(i=0; i<sendLen; i++)
    {
        MFRC522_Wr3(FIFODATAREG, sendData[i]);
    }
    MFRC522_Wr3(COMMANDREG, command);
    if(command == PCD_TRANSCEIVE)
    {
        MFRC522_Set_Bit3(BITFRAMINGREG, 0x80);
    }
    i = 0xFFFF;  
    do
    {
        n = MFRC522_Rd3(COMMIRQREG);
        i--;
    }while(i && !(n & 0x01) && !(n & waitIRq));
    
    MFRC522_Clear_Bit3(BITFRAMINGREG, 0x80);   
    if(i != 0)
    {
        if(!(MFRC522_Rd3(ERRORREG) & 0x1B))
        {
            _status = MI_OK;
            if(n & irqEn & 0x01)
            {
                _status = MI_NOTAGERR;
            }
            if(command == PCD_TRANSCEIVE)
            {
                n = MFRC522_Rd3(FIFOLEVELREG);
                lastBits = MFRC522_Rd3(CONTROLREG) & 0x07;
                if(lastBits)
                {
                    *backLen = (n-1) * 8 + lastBits;
                }
                else
                {
                    *backLen = n * 8;
                }
                if(n == 0)
                {
                    n = 1;
                }
                if(n > 16)
                {
                    n = 16;
                }
                for(i=0; i<n; i++)
                {
                    backData[i] = MFRC522_Rd3(FIFODATAREG);
                }
                backData[i] = 0;
            }
        }
        else
        {
            _status = MI_ERR;
        }
    }
    return _status;
}

char MFRC522_ToCard4(char command, char *sendData, char sendLen, char *backData, unsigned *backLen)
{
    char _status = MI_ERR;
    char irqEn = 0x00;
    char waitIRq = 0x00;
    char lastBits;
    char n;
    unsigned i;
    
    switch(command)
    {
        case PCD_AUTHENT:
            irqEn = 0x12;
            waitIRq = 0x10;
            break;
            
        case PCD_TRANSCEIVE:
            irqEn = 0x77;
            waitIRq = 0x30;
            break;
            
        default:
            break;
    }
    MFRC522_Wr4(COMMIENREG, irqEn | 0x80);
    MFRC522_Clear_Bit4(COMMIRQREG, 0x80);
    MFRC522_Set_Bit4(FIFOLEVELREG, 0x80);
    MFRC522_Wr4(COMMANDREG, PCD_IDLE);
    
    for(i=0; i<sendLen; i++)
    {
        MFRC522_Wr4(FIFODATAREG, sendData[i]);
    }
    MFRC522_Wr4(COMMANDREG, command);
    if(command == PCD_TRANSCEIVE)
    {
        MFRC522_Set_Bit4(BITFRAMINGREG, 0x80);
    }
    i = 0xFFFF;  
    do
    {
        n = MFRC522_Rd4(COMMIRQREG);
        i--;
    }while(i && !(n & 0x01) && !(n & waitIRq));
    
    MFRC522_Clear_Bit4(BITFRAMINGREG, 0x80);   
    if(i != 0)
    {
        if(!(MFRC522_Rd4(ERRORREG) & 0x1B))
        {
            _status = MI_OK;
            if(n & irqEn & 0x01)
            {
                _status = MI_NOTAGERR;
            }
            if(command == PCD_TRANSCEIVE)
            {
                n = MFRC522_Rd4(FIFOLEVELREG);
                lastBits = MFRC522_Rd4(CONTROLREG) & 0x07;
                if(lastBits)
                {
                    *backLen = (n-1) * 8 + lastBits;
                }
                else
                {
                    *backLen = n * 8;
                }
                if(n == 0)
                {
                    n = 1;
                }
                if(n > 16)
                {
                    n = 16;
                }
                for(i=0; i<n; i++)
                {
                    backData[i] = MFRC522_Rd4(FIFODATAREG);
                }
                backData[i] = 0;
            }
        }
        else
        {
            _status = MI_ERR;
        }
    }
    return _status;
}

char MFRC522_Request(char reqMode, char *TagType)
{
    char _status;
    unsigned backBits;           
    MFRC522_Wr(BITFRAMINGREG, 0x07);
    TagType[0] = reqMode;
    _status = MFRC522_ToCard(PCD_TRANSCEIVE, TagType, 1, TagType, &backBits);
    if((_status != MI_OK) || (backBits != 0x10))
    {
        _status = MI_ERR;
    }
    return _status;
}

char MFRC522_Request2(char reqMode, char *TagType)
{
    char _status;
    unsigned backBits;           
    MFRC522_Wr2(BITFRAMINGREG, 0x07);
    TagType[0] = reqMode;
    _status = MFRC522_ToCard2(PCD_TRANSCEIVE, TagType, 1, TagType, &backBits);
    if((_status != MI_OK) || (backBits != 0x10))
    {
        _status = MI_ERR;
    }
    return _status;
}

char MFRC522_Request3(char reqMode, char *TagType)
{
    char _status;
    unsigned backBits;           
    MFRC522_Wr3(BITFRAMINGREG, 0x07);
    TagType[0] = reqMode;
    _status = MFRC522_ToCard3(PCD_TRANSCEIVE, TagType, 1, TagType, &backBits);
    if((_status != MI_OK) || (backBits != 0x10))
    {
        _status = MI_ERR;
    }
    return _status;
}

char MFRC522_Request4(char reqMode, char *TagType)
{
    char _status;
    unsigned backBits;           
    MFRC522_Wr4(BITFRAMINGREG, 0x07);
    TagType[0] = reqMode;
    _status = MFRC522_ToCard4(PCD_TRANSCEIVE, TagType, 1, TagType, &backBits);
    if((_status != MI_OK) || (backBits != 0x10))
    {
        _status = MI_ERR;
    }
    return _status;
}

void MFRC522_CRC(char *dataIn, char length, char *dataOut)
{
    char i, n;
    MFRC522_Clear_Bit(DIVIRQREG, 0x04);
    MFRC522_Set_Bit(FIFOLEVELREG, 0x80);
    for(i=0; i<length; i++)
    {
        MFRC522_Wr(FIFODATAREG, *dataIn++);  
    }
    MFRC522_Wr(COMMANDREG, PCD_CALCCRC);
    i = 0xFF;
    do
    {
        n = MFRC522_Rd( DIVIRQREG );
        i--;
    }
    while(i && !(n & 0x04));
    dataOut[0] = MFRC522_Rd(CRCRESULTREGL);
    dataOut[1] = MFRC522_Rd(CRCRESULTREGM);       
}

void MFRC522_CRC2(char *dataIn, char length, char *dataOut)
{
    char i, n;
    MFRC522_Clear_Bit2(DIVIRQREG, 0x04);
    MFRC522_Set_Bit2(FIFOLEVELREG, 0x80);
    for(i=0; i<length; i++)
    {
        MFRC522_Wr2(FIFODATAREG, *dataIn++);  
    }
    MFRC522_Wr2(COMMANDREG, PCD_CALCCRC);
    i = 0xFF;
    do
    {
        n = MFRC522_Rd2( DIVIRQREG );
        i--;
    }
    while(i && !(n & 0x04));
    dataOut[0] = MFRC522_Rd2(CRCRESULTREGL);
    dataOut[1] = MFRC522_Rd2(CRCRESULTREGM);       
}

void MFRC522_CRC3(char *dataIn, char length, char *dataOut)
{
    char i, n;
    MFRC522_Clear_Bit3(DIVIRQREG, 0x04);
    MFRC522_Set_Bit3(FIFOLEVELREG, 0x80);
    for(i=0; i<length; i++)
    {
        MFRC522_Wr3(FIFODATAREG, *dataIn++);  
    }
    MFRC522_Wr3(COMMANDREG, PCD_CALCCRC);
    i = 0xFF;
    do
    {
        n = MFRC522_Rd3( DIVIRQREG );
        i--;
    }
    while(i && !(n & 0x04));
    dataOut[0] = MFRC522_Rd3(CRCRESULTREGL);
    dataOut[1] = MFRC522_Rd3(CRCRESULTREGM);       
}

void MFRC522_CRC4(char *dataIn, char length, char *dataOut)
{
    char i, n;
    MFRC522_Clear_Bit4(DIVIRQREG, 0x04);
    MFRC522_Set_Bit4(FIFOLEVELREG, 0x80);
    for(i=0; i<length; i++)
    {
        MFRC522_Wr4(FIFODATAREG, *dataIn++);  
    }
    MFRC522_Wr4(COMMANDREG, PCD_CALCCRC);
    i = 0xFF;
    do
    {
        n = MFRC522_Rd4( DIVIRQREG );
        i--;
    }
    while(i && !(n & 0x04));
    dataOut[0] = MFRC522_Rd4(CRCRESULTREGL);
    dataOut[1] = MFRC522_Rd4(CRCRESULTREGM);       
}

char MFRC522_SelectTag(char *serNum)
{
    char i;
    char _status;
    char size;
    unsigned recvBits;
    char buffer[9];
    buffer[0] = PICC_SElECTTAG;
    buffer[1] = 0x70;
    
    for(i=2; i<7; i++)
    {
        buffer[i] = *serNum++;
    }
    MFRC522_CRC(buffer, 7, &buffer[7]);
    _status = MFRC522_ToCard(PCD_TRANSCEIVE, buffer, 9, buffer, &recvBits);
    if((_status == MI_OK) && (recvBits == 0x18))
    {
        size = buffer[0];
    }
    else
    {
        size = 0;
    }
    return size;
}

char MFRC522_SelectTag2(char *serNum)
{
    char i;
    char _status;
    char size;
    unsigned recvBits;
    char buffer[9];
    buffer[0] = PICC_SElECTTAG;
    buffer[1] = 0x70;
    
    for(i=2; i<7; i++)
    {
        buffer[i] = *serNum++;
    }
    MFRC522_CRC2(buffer, 7, &buffer[7]);
    _status = MFRC522_ToCard2(PCD_TRANSCEIVE, buffer, 9, buffer, &recvBits);
    if((_status == MI_OK) && (recvBits == 0x18))
    {
        size = buffer[0];
    }
    else
    {
        size = 0;
    }
    return size;
}

char MFRC522_SelectTag3(char *serNum)
{
    char i;
    char _status;
    char size;
    unsigned recvBits;
    char buffer[9];
    buffer[0] = PICC_SElECTTAG;
    buffer[1] = 0x70;
    
    for(i=2; i<7; i++)
    {
        buffer[i] = *serNum++;
    }
    MFRC522_CRC3(buffer, 7, &buffer[7]);
    _status = MFRC522_ToCard3(PCD_TRANSCEIVE, buffer, 9, buffer, &recvBits);
    if((_status == MI_OK) && (recvBits == 0x18))
    {
        size = buffer[0];
    }
    else
    {
        size = 0;
    }
    return size;
}

char MFRC522_SelectTag4(char *serNum)
{
    char i;
    char _status;
    char size;
    unsigned recvBits;
    char buffer[9];
    buffer[0] = PICC_SElECTTAG;
    buffer[1] = 0x70;
    
    for(i=2; i<7; i++)
    {
        buffer[i] = *serNum++;
    }
    MFRC522_CRC4(buffer, 7, &buffer[7]);
    _status = MFRC522_ToCard4(PCD_TRANSCEIVE, buffer, 9, buffer, &recvBits);
    if((_status == MI_OK) && (recvBits == 0x18))
    {
        size = buffer[0];
    }
    else
    {
        size = 0;
    }
    return size;
}

void MFRC522_Halt(void)
{
    unsigned unLen;
    char buff[4];
    buff[0] = PICC_HALT;
    buff[1] = 0;
    MFRC522_CRC(buff, 2, &buff[2]);
    MFRC522_Clear_Bit(STATUS2REG, 0x80);
    MFRC522_ToCard(PCD_TRANSCEIVE, buff, 4, buff, &unLen);
    MFRC522_Clear_Bit(STATUS2REG, 0x08);
}

void MFRC522_Halt2(void)
{
    unsigned unLen;
    char buff[4];
    buff[0] = PICC_HALT;
    buff[1] = 0;
    MFRC522_CRC2(buff, 2, &buff[2]);
    MFRC522_Clear_Bit2(STATUS2REG, 0x80);
    MFRC522_ToCard2(PCD_TRANSCEIVE, buff, 4, buff, &unLen);
    MFRC522_Clear_Bit2(STATUS2REG, 0x08);
}

void MFRC522_Halt3(void)
{
    unsigned unLen;
    char buff[4];
    buff[0] = PICC_HALT;
    buff[1] = 0;
    MFRC522_CRC3(buff, 2, &buff[2]);
    MFRC522_Clear_Bit3(STATUS2REG, 0x80);
    MFRC522_ToCard3(PCD_TRANSCEIVE, buff, 4, buff, &unLen);
    MFRC522_Clear_Bit3(STATUS2REG, 0x08);
}

void MFRC522_Halt4(void)
{
    unsigned unLen;
    char buff[4];
    buff[0] = PICC_HALT;
    buff[1] = 0;
    MFRC522_CRC4(buff, 2, &buff[2]);
    MFRC522_Clear_Bit4(STATUS2REG, 0x80);
    MFRC522_ToCard4(PCD_TRANSCEIVE, buff, 4, buff, &unLen);
    MFRC522_Clear_Bit4(STATUS2REG, 0x08);
}

char MFRC522_AntiColl(char *serNum)
{
    char _status;
    char i;
    char serNumCheck = 0;
    unsigned unLen;
    MFRC522_Wr(BITFRAMINGREG, 0x00);
    serNum[0] = PICC_ANTICOLL;
    serNum[1] = 0x20;
    MFRC522_Clear_Bit(STATUS2REG, 0x08);
    _status = MFRC522_ToCard(PCD_TRANSCEIVE, serNum, 2, serNum, &unLen);
    if(_status == MI_OK)
    {
        for(i=0; i<5; i++)
        {
            serNumCheck ^= serNum[i];
        }
        if(serNumCheck != serNum[5])
        {
            _status = MI_ERR;
        }
    }
    return _status;
}

char MFRC522_AntiColl2(char *serNum)
{
    char _status;
    char i;
    char serNumCheck = 0;
    unsigned unLen;
    MFRC522_Wr2(BITFRAMINGREG, 0x00);
    serNum[0] = PICC_ANTICOLL;
    serNum[1] = 0x20;
    MFRC522_Clear_Bit2(STATUS2REG, 0x08);
    _status = MFRC522_ToCard2(PCD_TRANSCEIVE, serNum, 2, serNum, &unLen);
    if(_status == MI_OK)
    {
        for(i=0; i<5; i++)
        {
            serNumCheck ^= serNum[i];
        }
        if(serNumCheck != serNum[5])
        {
            _status = MI_ERR;
        }
    }
    return _status;
}

char MFRC522_AntiColl3(char *serNum)
{
    char _status;
    char i;
    char serNumCheck = 0;
    unsigned unLen;
    MFRC522_Wr3(BITFRAMINGREG, 0x00);
    serNum[0] = PICC_ANTICOLL;
    serNum[1] = 0x20;
    MFRC522_Clear_Bit3(STATUS2REG, 0x08);
    _status = MFRC522_ToCard3(PCD_TRANSCEIVE, serNum, 2, serNum, &unLen);
    if(_status == MI_OK)
    {
        for(i=0; i<5; i++)
        {
            serNumCheck ^= serNum[i];
        }
        if(serNumCheck != serNum[5])
        {
            _status = MI_ERR;
        }
    }
    return _status;
}

char MFRC522_AntiColl4(char *serNum)
{
    char _status;
    char i;
    char serNumCheck = 0;
    unsigned unLen;
    MFRC522_Wr4(BITFRAMINGREG, 0x00);
    serNum[0] = PICC_ANTICOLL;
    serNum[1] = 0x20;
    MFRC522_Clear_Bit4(STATUS2REG, 0x08);
    _status = MFRC522_ToCard4(PCD_TRANSCEIVE, serNum, 2, serNum, &unLen);
    if(_status == MI_OK)
    {
        for(i=0; i<5; i++)
        {
            serNumCheck ^= serNum[i];
        }
        if(serNumCheck != serNum[5])
        {
            _status = MI_ERR;
        }
    }
    return _status;
}

char MFRC522_IsCard(char *TagType)
{
    if(MFRC522_Request(PICC_REQIDL, TagType) == MI_OK)
        return 1;
    else
        return 0;
}

char MFRC522_IsCard2(char *TagType)
{
    if(MFRC522_Request2(PICC_REQIDL, TagType) == MI_OK)
        return 1;
    else
        return 0;
}

char MFRC522_IsCard3(char *TagType)
{
    if(MFRC522_Request3(PICC_REQIDL, TagType) == MI_OK)
        return 1;
    else
        return 0;
}

char MFRC522_IsCard4(char *TagType)
{
    if(MFRC522_Request4(PICC_REQIDL, TagType) == MI_OK)
        return 1;
    else
        return 0;
}

char MFRC522_ReadCardSerial(char *str)
{
    char _status;
    _status = MFRC522_AntiColl(str);
    str[5] = 0;                         // originally [4]
    if(_status == MI_OK)
        return 1;
    else
        return 0;
}

char MFRC522_ReadCardSerial2(char *str)
{
    char _status;
    _status = MFRC522_AntiColl2(str);
    str[5] = 0;                         // originally [4]
    if(_status == MI_OK)
        return 1;
    else
        return 0;
}

char MFRC522_ReadCardSerial3(char *str)
{
    char _status;
    _status = MFRC522_AntiColl3(str);
    str[5] = 0;                         // originally [4]
    if(_status == MI_OK)
        return 1;
    else
        return 0;
}

char MFRC522_ReadCardSerial4(char *str)
{
    char _status;
    _status = MFRC522_AntiColl4(str);
    str[5] = 0;                         // originally [4]
    if(_status == MI_OK)
        return 1;
    else
        return 0;
}

char MFRC522_Compare_UID(char *l, char *u)
{
    for(char i=0; i<4; i++)
    {
        if(l[i] != u[i])
        {
            return 0;
        }
    }
    return 1;
}