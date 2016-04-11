#include "I2C.h"

u8 f_Send2Bytes;
u8 f_SendByte;

extern u8 BytesHandL[];



void I2C_InitAsMaster(void)
{
    SMP=0;
    CKE=0;
    SSPCON1 = 0b00101000;           //i2c master mode, clock = Fosc/(4*(SSPADD+1))
    SSPCON2 = 0;
    TRISBbits.TRISB0 = 1;
    TRISBbits.TRISB1 = 1;
    SSPADD = 0x03;                  //100 kHz
}


//The next two functions are hardcoded. if you use them, check the functions and
//just try to improve them, to send multiple bytes.

//Send byte


void I2C_SendByte(u8 slave, u8 address, u8 data){
    SSPIF=0;
    SSPCON2bits.SEN=1;
    while(SSPIF!=1);
    SSPIF=0;
    SSPBUF = slave;
    //ack
    while(SSPIF!=1);
    SSPIF=0;
    SSPBUF = address;
    //ack
    while(SSPIF!=1);
    SSPIF=0;
    SSPBUF = data;
    //ack
    while(SSPIF!=1);
    SSPIF=0;
    PEN = 1;
    while(SSPIF!=1);
    SSPIF=0;
}


void I2C_Send2Bytes(u8 slave, u16* pointer){
    if(f_slave2==1)
    {
        SSPIF=0;
        SSPCON2bits.SEN=1;
        while(SSPIF!=1);
        SSPIF=0;
        SSPBUF = slave;
    //ack
        while(SSPIF!=1);
        SSPIF=0;
        SSPBUF = (*pointer&0xFF00);
    //ack
        while(SSPIF!=1);
        SSPIF=0;
        SSPBUF = (*pointer&0x00FF);
    //ack
        while(SSPIF!=1);
        SSPIF=0;
        PEN = 1;
        while(SSPIF!=1);
        SSPIF=0;
        f_slave2=0;
    }
}


//The nest function is hardcoded, if you use it, try to improve it so you can
//have a easy-to-use function
/*
s16* I2C_ReadSlave(u8 slave_address, u8 AccH, u8 GyroH){

    SSPIF=0;
    SSPCON2bits.SEN=1;
    while(SSPIF!=1);
    SSPIF=0;
    SSPBUF=slave_address;
    while(SSPIF!=1);
    SSPIF=0;
    SSPBUF=AccH;;
    while(SSPIF!=1);
    SSPIF=0;
    SSPCON2bits.SEN=1;
    while(SSPIF!=1);
    SSPIF=0;
    SSPBUF=slave_address++;
    while(SSPIF!=1);
    SSPIF=0;
    SSPCON2bits.RCEN=1;
    while(SSPIF!=1);
    SSPIF=0;
    //change to pinter
    recibido=SSPBUF;
    SSPCON2bits.ACKDT=1;
    SSPCON2bits.ACKEN=1;
    while(SSPIF!=1);
    SSPIF=0;
    SSPCON2bits.PEN=1; 
    while(SSPIF!=1);
    SSPIF=0;
    return recibido;
}
*/

//Nevermind this is the function for ReadIMU, anyway, please make the state
//machine for this function
u8 I2C_ReadIMU(u8 slave_address, u8 Data ){

    u8 recibido;
    SSPIF=0;
    SSPCON2bits.SEN=1;//manda start bit
    while(SSPIF!=1){} //espera bandera
    SSPIF=0;
    SSPBUF=slave_address; //direccion del esclavo y escribir W
    while(SSPIF!=1){} //espera bandera
    SSPIF=0;
    SSPBUF=Data;//direccion a leer
    while(SSPIF!=1){} //espera bandera
    SSPIF=0;
    SSPCON2bits.SEN=1;//manda start bit
    while(SSPIF!=1){} //espera bandera
    SSPIF=0;
    SSPBUF=(slave_address+1);
    while(SSPIF!=1){} //espera bandera
    SSPIF=0;
    SSPCON2bits.RCEN=1;//cambia a modo de recepcion
    while(SSPIF!=1){} //espera bandera
    SSPIF=0;
    recibido=SSPBUF;//guarda dato recibido
    SSPCON2bits.ACKDT=1;//manda NOACK
    SSPCON2bits.ACKEN=1;//habilita NACK
    while(SSPIF!=1){} //espera bandera
    SSPIF=0;
    SSPCON2bits.PEN=1; //manda stop bit
    while(SSPIF!=1){} //espera bandera
    SSPIF=0;


    return recibido;
}