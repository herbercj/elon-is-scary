#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;


struct entity{
    char identifier;
    string name;

    bool interaction; //if player has interacted
    bool revealed; //if player has revealed

    int row;
    int col;
};

class Board{
    private:
        char boardDisplay[15][15];
        char boardData[15][15]; //sets the placement of an entity, does not reveal to player
        bool gameStart;
        int currentGameTurn;
        char entityTurn;

        bool elonWake;
        bool gameAgain;
        vector<entity> objects;
        //^ values related to current game :: v values related to play since start
        double avgGameTurn;
        double avgWinRatio;
        double avgElonLoss;
        double avgHintUse;

    public:
        Board(); //initializes game stat tracking
        Board(double, double, double, double); //used if new game following past game, retains stats

        void setSpace(entity);
        int getSpaceR(entity);
        int getSpaceC(entity);
        void revSpace(vector<entity>);
        void initEntity(char, string, bool, bool);// initializes entities
        bool initElon();
        void boardTurn(entity); //communicates changes to board following turn updates
        double;
        double;
        double;
        int;
        int;
        int;

};

#endif // BOARD_H
