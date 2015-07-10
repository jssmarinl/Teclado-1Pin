#include <12F675.h>
#device adc=10

#use delay(clock=4M)
#fuses XT

///////////////////////////////////////////////////////////////////////////
////                               TCL.c                               ////
////               Driver para teclado 4x4 leido por un unico          ////
////               PIN de un Microcontrolador que posea conversion     ////
////               analogico-digital. Lectura por defecto a 10bits     ////
////               de resolucion                                       ////
////                                                                   ////
////                                                                   ////
////  Si la resolucion es a 8 bit (#device adc = 8), descomentar       ////
////  los valores para dicha resolucion. Por defecto se trabaja        ////
////  a 10 bits (#device adc = 10)                                     ////
////                                                                   ////
////                                                                   ////
////  tcl_init()   Debe llamarse desde el programa principal           ////
////               antes de cualquier funcion                          ////
////                                                                   ////
////  tcl_gect()   Función de escaneo de teclado                       ////
////                                                                   ////
////  #define  PIN ANx  Deben llamarse antes de integrar el            ////
////  #define  AN x     driver y cambiarse la 'x' por un valor         ////
////                    de pin analogico-digital valido                ////
////                                                                   ////
////  Ejemplo: #define  PIN AN0 Esto ubica la lectura del              ////
////           #define  AN 0    teclado en el Pin RA0 del              ////
////                            Puerto A                               ////
////                                                                   ////
////  La variable 'key' debe usarse para preguntar por la tecla        ////
////  presionada, para ello debe compararse contra los botones         ////
////  ya definidos                                                     ////
////                                                                   ////
////  Ejemplo: if (key == TX)  Se esta preguntando si el boton         ////
////           {               presionado fue el '*'                   ////
////             /* code */                                            ////
////           }                                                       ////
////                        Autor: Jesus Marin                         ////
////                   Email: marinje90@gmail.com                      ////
///////////////////////////////////////////////////////////////////////////
////
////              -Teclado Real-          -Teclado Leido-
////
////            |---|---|---|---|      |----|----|----|----|
////            | 1 | 2 | 3 | A |      | T1 | T2 | T3 | TA |
////            |---|---|---|---|      |----|----|----|----|
////            | 4 | 5 | 6 | B |      | T4 | T5 | T6 | TB |
////            |---|---|---|---|      |----|----|----|----|
////            | 7 | 8 | 9 | C |      | T7 | T8 | T9 | TC |
////            |---|---|---|---|      |----|----|----|----|
////            | * | 0 | # | D |      | TX | T0 | TW | TD |
////            |---|---|---|---|      |----|----|----|----|
////
///////////////////////////////////////////////////////////////////////////

//////////Deficicion de los botones del teclado//////////
        unsigned int16  key = 0;

    //////////Para adc = 8///////////

        #define  T0 137 //Boton "0"
        #define  T1 216 //Boton "1"
        #define  T2 162 //Boton "2"
        #define  T3 126 //Boton "3"
        #define  T4 200 //Boton "4"
        #define  T5 153 //Boton "5"
        #define  T6 121 //Boton "6"
        #define  T7 183 //Boton "7"
        #define  T8 143 //Boton "8"
        #define  T9 115 //Boton "9"
        #define  TX 174 //Boton "*"
        #define  TW 111 //Boton "#"
        #define  TA 84  //Boton "A"
        #define  TB 82  //Boton "B"
        #define  TC 79  //Boton "C"
        #define  TD 77  //Boton "D"


    //////////Para adc = 10///////////

    /*    #define  T0 550 //Boton "0"
        #define  T1 864 //Boton "1"
        #define  T2 649 //Boton "2"
        #define  T3 507 //Boton "3"
        #define  T4 802 //Boton "4"
        #define  T5 614 //Boton "5"
        #define  T6 485 //Boton "6"
        #define  T7 735 //Boton "7"
        #define  T8 537 //Boton "8"
        #define  T9 460 //Boton "9"
        #define  TX 697 //Boton "*"
        #define  TW 445 //Boton "#"
        #define  TA 339 //Boton "A"
        #define  TB 329 //Boton "B"
        #define  TC 317 //Boton "C"
        #define  TD 310 //Boton "D"*/

////////////////////////////////////////////////////////
	#define AN 0

///////////////Inicializacion del Teclado//////////////////
    void tcl_init(){
        setup_adc(adc_clock_internal);
        setup_adc_ports(all_analog); //Pin de lectura
    }
//////////////////////////////////////////////////////////


/////////////////////Lectura del Teclado//////////////////
    void tcl_gect(){
        set_adc_channel(AN);
        delay_us(20);
        key = read_adc();
    }
/////////////////////////////////////////////////////////

void main() {
}
