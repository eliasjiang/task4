//
// Created by jiang-work on 2022-11-11.
//

#ifndef TASK4_POSITION_H
#define TASK4_POSITION_H
class Position{
protected:
    int row;
    int col;
public:
        Position();
        Position(int row,int col);
        void setPosition(int row,int col);
        const int getRow() const;
        const int getColumn() const;

};
#endif //TASK4_POSITION_H
