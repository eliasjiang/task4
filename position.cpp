//
// Created by jiang-work on 2022-11-11.
//
#include "position.h"

Position::Position(){
    row = 0;
    col = 0;
};

Position::Position(int row,int col) {
    this->row = row;
    this->col = col;
}

void Position::setPosition(int row, int col) {
    this->row = row;
    this->col = col;
}

const int Position::getRow() const {
    return row;
}

const int Position::getColumn() const {
    return col;
}



