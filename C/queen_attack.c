// queen_attack.h

#ifndef QUEEN_ATTACK_H
#define QUEEN_ATTACK_H

#include <stdint.h>

typedef enum { CAN_NOT_ATTACK, CAN_ATTACK, INVALID_POSITION } attack_status_t;

typedef struct {
   uint8_t row;
   uint8_t column;
} position_t;

attack_status_t can_attack(position_t queen_1, position_t queen_2);

#endif


// queen_attack.c

#include "queen_attack.h"


attack_status_t can_attack(position_t queen_1, position_t queen_2){
   attack_status_t check_attack_queen;
   uint8_t temp_column = queen_1.column;
   uint8_t temp_row = queen_1.row;
    
    if ((queen_1.row == queen_2.row && queen_1.column == queen_2.column) ||
         queen_1.row > 7 || queen_2.row > 7 || queen_1.column > 7 || queen_2.column > 7){
        check_attack_queen = INVALID_POSITION;
        return check_attack_queen;
    }
    
    if (queen_1.row == queen_2.row){
        while(temp_column < 8){
            if(temp_column == queen_2.column){
                check_attack_queen = CAN_ATTACK;
                return check_attack_queen;
            }
            temp_column++;
        }
        
        temp_column = queen_1.column;
        
        while(temp_column != 0){
            if(temp_column == queen_2.column){
                check_attack_queen = CAN_ATTACK;
                return check_attack_queen;
            }
            temp_column--;
        }
    }
    
    else if (queen_1.column == queen_2.column){
        while(temp_row < 8){
            if(temp_row == queen_2.row){
                check_attack_queen = CAN_ATTACK;
                return check_attack_queen;
            }
            temp_row++;
        }
        
        temp_row = queen_1.row;
        
        while(temp_row != 0){
            if(temp_row == queen_2.row){
                check_attack_queen = CAN_ATTACK;
                return check_attack_queen;
            }
            temp_row--;
        }
    }
    
    temp_column = queen_1.column;
    temp_row = queen_1.row;
    
    while(temp_row < 8 && temp_column < 8){
        temp_row++;
        temp_column++;
        if(temp_row == queen_2.row && temp_column == queen_2.column){
            check_attack_queen = CAN_ATTACK;
            return check_attack_queen;
        }
        
    }
    
    temp_row = queen_1.row;
    temp_column = queen_1.column;
    
    while(temp_row < 8 && temp_column != 0){
        temp_row++;
        temp_column--;
        if(temp_row == queen_2.row && temp_column == queen_2.column){
            check_attack_queen = CAN_ATTACK;
            return check_attack_queen;
        }
        
    }
    
    temp_row = queen_1.row;
    temp_column = queen_1.column;
    
    while(temp_row != 0 && temp_column < 8){
        temp_row--;
        temp_column++;
        if(temp_row == queen_2.row && temp_column == queen_2.column){
            check_attack_queen = CAN_ATTACK;
            return check_attack_queen;
        }
    }
    
    temp_row = queen_1.row;
    temp_column = queen_1.column;
    
    while(temp_row != 0 && temp_column != 0){
        temp_row--;
        temp_column--;
        if(temp_row == queen_2.row && temp_column == queen_2.column){
            check_attack_queen = CAN_ATTACK;
            return check_attack_queen;
        }
    }
    
   check_attack_queen = CAN_NOT_ATTACK;
    return check_attack_queen;
}
