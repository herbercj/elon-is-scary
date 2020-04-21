#include "Board.h"

/* Class Function Name: Board
 *
 * Function Description:
 * This is the default initializer for Board.
 * This is what the game uses during the first play.
 *
 *
 * Parameters:
 * The x parameter is the amount of fun to have
 * The y parameter is the amount of fun that happened
 *
 * return value:
 * Indicates how much fun this assignment was
 */

Board::Board(){
    const int BOARD_SIZE = 15;
    for(int r = 0; r < BOARD_SIZE; r++){
        for(int c = 0; c < BOARD_SIZE; c++){
        boardDisplay[r][c] = '-';
        boardData[r][c] = '-';
        }
    }
    entityTurn = 'p'; // for player
    currentGameTurn = 0;
    gameStart = false;
    elonWake = false;
    gameAgain = false;
    objects.clear();
    srand(time(NULL));

    avgGameTurn = 0;
    avgWinRatio = 0;
    avgElonLoss = 0;
    avgHintUse  = 0;
}

Board::Board(double prevGameTurn, double prevWinRatio, double prevElonLoss, double prevHintUse){
    const int BOARD_SIZE = 15;
    for(int r = 0; r < BOARD_SIZE; r++){
        for(int c = 0; c < BOARD_SIZE; c++){
        boardDisplay[r][c] = '-';
        boardData[r][c] = '-';
        }
    }
    entityTurn = 'P'; // for player
    currentGameTurn = 0;
    gameStart = false;
    elonWake = false;
    gameAgain = false;
    objects.clear();

    avgGameTurn = prevGameTurn;
    avgWinRatio = prevWinRatio;
    avgElonLoss = prevElonLoss;
    avgHintUse  = prevHintUse;
}


void Board::setSpace(entity object){
    int r, c;
    bool open = false;
    srand(time(NULL));
    while(!open){
        r = rand() % 15;
        c = rand() % 15;
        if(boardDisplay[r][c] == '-')
        {
            open = true;
        }
    }
    boardData[r][c] = object.identifier;
    if(object.identifier == 'P') boardDisplay[r][c] = object.identifier;
    object.row = r;
    object.col = c;
}

int Board::getSpaceR(entity object){
    return object.row;
}

int Board::getSpaceC(entity object){
    return object.col;
}

void Board::revSpace(vector<entity> &objects){
    int playerRow = getSpaceR(objects.at(3));
    int playerCol = getSpaceC(objects.at(3));




}

void Board::initEntity(char id, string name, bool interactable, bool revealed){
    entity newEntity = {id, name, interactable, revealed, 0, 0};

    setSpace(newEntity);

    objects.push_back(newEntity);// yugo always at 0, ford always at 1, road always at 2, play always at 3
}

bool Board::initElon(){
    if(!elonWake){
        char id = 'E';
        string name = "Elon";
        bool interactable = false;
        bool revealed = false;

        elonWake = rand() % 2;
        if(elonWake)
            initEntity(id, name, interactable, revealed);
    }
    // if elon not true (false) do a coin flip. if coin flip true then create elon, return true, if not true, return false try again
    return elonWake;
}
