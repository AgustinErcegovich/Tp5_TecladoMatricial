#include "MKL25Z4.h"
#include "TECLADOMATRICIAL.h"
#include "ctype.h"

char matriz [4][4] = {'1', '2', '3', 'A'},
                     {'4', '5', '6', 'B'},
                     {'7', '8', '9', 'C'},
                     {'*', '0', '#', 'D'};

int columnas [4] = {4, 5, 6, 7};
int   filas  [4] = {0, 1, 2, 3};

void Puerto(char LetraPuerto) {
    char Letra = toupper(LetraPuerto);
    switch (Letra) {
        case 'A': 
            SIM -> SCGC5 |= SIM_SCGC5_PORTA_MASK;
            for (int i=0;i<4;i++) {
                PORTA -> PCR[filas[i]] |= PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
            }
            for (int e=0;e<4;e++) {
                PORTA -> PCR[columnas[e]] |= PORT_PCR_MUX(1);
            } break;

            case 'B': 
            SIM -> SCGC5 |= SIM_SCGC5_PORTB_MASK;
            for (int i=0;i<4;i++) {
                PORTB -> PCR[filas[i]] |= PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
            }
            for (int e=0;e<4;e++) {
                PORTB -> PCR[columnas[e]] |= PORT_PCR_MUX(1);
            } break;

            case 'C': 
            SIM -> SCGC5 |= SIM_SCGC5_PORTC_MASK;
            for (int i=0;i<4;i++) {
                PORTC -> PCR[filas[i]] |= PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
            }
            for (int e=0;e<4;e++) {
                PORTC -> PCR[columnas[e]] |= PORT_PCR_MUX(1);
            } break;

            case 'D': 
            SIM -> SCGC5 |= SIM_SCGC5_PORTD_MASK;
            for (int i=0;i<4;i++) {
                PORTD -> PCR[filas[i]] |= PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
            }
            for (int e=0;e<4;e++) {
                PORTD -> PCR[columnas[e]] |= PORT_PCR_MUX(1);
            } break;

            case 'E': 
            SIM -> SCGC5 |= SIM_SCGC5_PORTE_MASK;
            for (int i=0;i<4;i++) {
                PORTE -> PCR[filas[i]] |= PORT_PCR_MUX(0)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
            }
            for (int e=0;e<4;e++) {
                PORTE -> PCR[columnas[e]] |= PORT_PCR_MUX(1);
            } break;
    }
}

char TeclaPresionada(char LetraPuerto) {
    char Letra = toupper(LetraPuerto);
    switch (Letra) {
        case 'A':
        for(int i=0;i<4;i++) {
            PTA -> PSOR |= (0u << filas[i]);
            for (int e=0;e<4;e++) {
                int valorSalida = PTA -> PDIR & (1 << columnas[e]);
                if (valorSalida == 0) {
                    return matriz[i][e];
                }
            }
            PTA -> PSOR |= (1u << filas[i]);
        } break;
        case 'B':
        for(int i=0;i<4;i++) {
            PTB -> PSOR |= (0u << filas[i]);
            for (int e=0;e<4;e++) {
                int valorSalida = PTB -> PDIR & (1 << columnas[e]);
                if (valorSalida == 0) {
                    return matriz[i][e];
                }
            }
            PTB -> PSOR |= (1u << filas[i]);
        } break;
        case 'C':
        for(int i=0;i<4;i++) {
            PTC -> PSOR |= (0u << filas[i]);
            for (int e=0;e<4;e++) {
                int valorSalida = PTC -> PDIR & (1 << columnas[e]);
                if (valorSalida == 0) {
                    return matriz[i][e];
                }
            }
            PTC -> PSOR |= (1u << filas[i]);
        } break;
        case 'D':
        for(int i=0;i<4;i++) {
            PTD -> PSOR |= (0u << filas[i]);
            for (int e=0;e<4;e++) {
                int valorSalida = PTD -> PDIR & (1 << columnas[e]);
                if (valorSalida == 0) {
                    return matriz[i][e];
                }
            }
            PTD -> PSOR |= (1u << filas[i]);
        } break;
        case 'E':
        for(int i=0;i<4;i++) {
            PTE -> PSOR |= (0u << filas[i]);
            for (int e=0;e<4;e++) {
                int valorSalida = PTE -> PDIR & (1 << columnas[e]);
                if (valorSalida == 0) {
                    return matriz[i][e];
                }
            }
            PTE -> PSOR |= (1u << filas[i]);
        } break;
    }
}
