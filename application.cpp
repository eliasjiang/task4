//
// Created by jiang-work on 2022-11-11.
//

#include <iostream>
#include "application.h"

const int PLO = 9;//possible location
const int TRIED = 2;
const int ROWS = 8;
const int COLS = 8;
int board[ROWS][COLS] = {0};
int queens = 0;

Position start,finish;
const bool checkValidRow(const Position& p);
const bool checkValidCol(const Position& p);
const bool checkValidDia(const Position& p);
using namespace std;

void Application::initialize() {

}

Position Application::getStartPosition() {
    return Position();
}

bool Application::isValid(const Position &p) {

}

void Application::progress(const Position &p) {
    board[p.getRow()][p.getColumn()] = PLO;
    queens++;
}

bool Application::success(const Position& p){
    return queens==8;
}

void Application::goBack(const Position &p) {
    board[p.getRow()][p.getColumn()]=TRIED;

}

void Application::print(){
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if(board[i][j]==PLO) printf("Q ");
            else printf("* ");
        }
        printf("\n");
    }
}

struct currItrPosField{
    int row;
    int col;
};


Application::Iterator::Iterator(const Position& pos) {

    currItrPosField* curItr = new currItrPosField();
    curItr->row = pos.getRow();
    curItr->col = pos.getColumn();
    currItrPosPtr  = curItr;
}

Position Application::Iterator::getNextPosition(){
    currItrPosField* itrPtr = (currItrPosField*)currItrPosPtr;
    int newCol,newRow;
    if(itrPtr->row==7){
        newCol = itrPtr->col+1;
        newRow = 0;
    }else{
        newCol = itrPtr->col;
        newRow = itrPtr->row;
    }
    Position next(newRow,newCol);
    return next;
}

bool Application::Iterator::noNextPosition(){
    currItrPosField* itrPtr = (currItrPosField*)currItrPosPtr;
    return (itrPtr->col==7)&&(itrPtr->row==7);
}

Application::Iterator::Iterator() {

}

Application::Iterator::~Iterator() {

}


const bool checkValidRow(const Position& p){

    for(int i=0;i<COLS;i++){
        if(board[p.getRow()][i]==PLO) return false;
    }
    return true;
    return true;
}
const bool checkValidCol(const Position& p){
    for(int i=0;i<ROWS;i++){
        if(board[i][p.getColumn()]==PLO) return false;
    }
}
const bool checkValidDia(const Position& p){
    for(int i= 1;i<7;i++){
        if(board[p.getRow()+i][p.getColumn()+i]==PLO&&(p.getRow()+i>=0&&p.getRow()+i<=7)&&(p.getColumn()+i>=0&&p.getColumn()+i<=7)) return false;
        if(board[p.getRow()+i][p.getColumn()-i]==PLO&&(p.getRow()+i>=0&&p.getRow()+i<=7)&&(p.getColumn()-i>=0&&p.getColumn()-i<=7)) return false;
        if(board[p.getRow()-i][p.getColumn()+i]==PLO&&(p.getRow()-i>=0&&p.getRow()-i<=7)&&(p.getColumn()+i>=0&&p.getColumn()+i<=7)) return false;
        if(board[p.getRow()-i][p.getColumn()-i]==PLO&&(p.getRow()-i>=0&&p.getRow()-i<=7)&&(p.getColumn()-i>=0&&p.getColumn()-i<=7)) return false;
        return true;
    }
}

