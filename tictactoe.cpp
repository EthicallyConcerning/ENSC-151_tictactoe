/**
 * Simon Fraser University
 * ENSC-151
 * tictactoe.cpp - plays a game of tic tac toe
 * 
 *
 * Input:
 * moves from players alternating sides
 * Output:
 * gui with gameboard
 *
 **/
//Hi, this is Victor!

#include <iostream>             // default c++ library
#include <string>               // string library for arrays

using namespace std;            // simplifies code

// UI elements

/**
 *  clearscreen()            (UI function)
 *  clears the screen
 * 
 *  Input:
 *  none
 *  Output:
 *  blank spaces
 *  
 **/
void clearscreen() {
    cout << "\x1B[2J\x1B[H";                // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
}

/**
 *  header()                (UI function)
 *  clears the screen
 * 
 *  Input:
 *  none
 *  Output:
 *  header
 *  
 **/
void header() {
        // "Sub-Zero" font by Sub-Zero
        // ==============================
        // -> Conversion to FigLet font by MEPH. (Part of ASCII Editor Service Pack I)
        // (http://studenten.freepage.de/meph/ascii/ascii/editor/_index.htm)
        // -> Defined: ASCII code alphabet
        // -> Uppercase characters only.
        // 
        // ScarecrowsASCIIArtArchive1.0.txt
        // From: "Sub-Zero" <bodom@papaya.ucs.indiana.edu>
        // "Here's a font I've been working on lately. Can someone make the V, Q, and X
        // look better? Also, the B, P, and R could use an improvement too.
        // Oh, here it is."    
    cout
    << R"( ______ ______  ______ ______ __  __       ______  __  ______  ______        )" << endl
    << R"(/\  == /\  __ \/\  == /\__  _/\ \_\ \     /\  ___\/\ \/\___  \/\  ___\       )" << endl
    << R"(\ \  _-\ \  __ \ \  __\/_/\ \\ \____ \    \ \___  \ \ \/_/  /_\ \  __\       )" << endl
    << R"( \ \_\  \ \_\ \_\ \_\ \_\\ \_\\/\_____\    \/\_____\ \_\/\_____\ \_____\     )" << endl
    << R"(  \/_/   \/_/ /_/\/_/ /_/ \/_/ \/_____/     \/_____/\/_/\/____/ \/_____/     )" << endl
    << R"( ______ __  ______       ______ _____   _____        ______ _____   ______   )" << endl
    << R"(/\__  _/\ \/\  ___\     /\__  _/\  __ \/\  ___\     /\__  _/\  __ \/\  ___\  )" << endl
    << R"(\/_/\ \\ \ \ \ \____    \/_/\ \\ \  __ \ \ \____    \/_/\ \\ \ \/\ \ \  __\  )" << endl
    << R"(   \ \_\\ \_\ \_____\      \ \_\\ \_\ \_\ \_____\      \ \_\\ \_____\ \_____\)" << endl
    << R"(    \/_/ \/_/\/_____/       \/_/ \/_/\/_/\/_____/       \/_/ \/_____/\/_____/)" << endl; 
}

// (UI)game "pages"

/**
 *  menu()              (UI function)
 *  "lobby" for the game
 * 
 *  Input:
 *  none
 *  Output:
 *  the header of the function
 *  
 **/

void menu () {
    header();
    cout << "\n"
        << R"(       __  __       ______       __  __       ______       __  __   )" << endl
        << R"(      /\_\_\_\   | /\  __ \   | /\_\_\_\   | /\  __ \   | /\_\_\_\  )" << endl
        << R"(      \/_/\_\/_  | \ \ \/\ \  | \/_/\_\/_  | \ \ \/\ \  | \/_/\_\/_ )" << endl
        << R"(        /\_\/\_\ |  \ \_____\ |   /\_\/\_\ |  \ \_____\ |   /\_\/\_\)" << endl
        << R"(        \/_/\/_/ |   \/_____/ |   \/_/\/_/ |   \/_____/ |   \/_/\/_/)" << endl
        << R"(      --------------------------------------------------------------)" << endl
        << R"(       ______    |  __  __    |  ______    |  __  __    |  ______   )" << endl
        << R"(      /\  __ \   | /\_\_\_\   | /\  __ \   | /\_\_\_\   | /\  __ \  )" << endl
        << R"(      \ \ \/\ \  | \/_/\_\/_  | \ \ \/\ \  | \/_/\_\/_  | \ \ \/\ \ )" << endl
        << R"(       \ \_____\ |   /\_\/\_\ |  \ \_____\ |   /\_\/\_\ |  \ \_____\)" << endl
        << R"(        \/_____/ |   \/_/\/_/ |   \/_____/ |   \/_/\/_/ |   \/_____/)" << endl
        << R"(      --------------------------------------------------------------)" << endl
        << R"(       __  __    |  ______    |  __  __    |  ______    |  __  __   )" << endl
        << R"(      /\_\_\_\   | /\  __ \   | /\_\_\_\   | /\  __ \   | /\_\_\_\  )" << endl
        << R"(      \/_/\_\/_  | \ \ \/\ \  | \/_/\_\/_  | \ \ \/\ \  | \/_/\_\/_ )" << endl
        << R"(        /\_\/\_\ |  \ \_____\ |   /\_\/\_\ |  \ \_____\ |   /\_\/\_\)" << endl
        << R"(        \/_/\/_/ |   \/_____/ |   \/_/\/_/ |   \/_____/ |   \/_/\/_/)" << endl
        << R"(      --------------------------------------------------------------)" << endl
        << R"(       ______    |  __  __    |  ______    |  __  __    |  ______   )" << endl
        << R"(      /\  __ \   | /\_\_\_\   | /\  __ \   | /\_\_\_\   | /\  __ \  )" << endl
        << R"(      \ \ \/\ \  | \/_/\_\/_  | \ \ \/\ \  | \/_/\_\/_  | \ \ \/\ \ )" << endl
        << R"(       \ \_____\ |   /\_\/\_\ |  \ \_____\ |   /\_\/\_\ |  \ \_____\)" << endl
        << R"(        \/_____/ |   \/_/\/_/ |   \/_____/ |   \/_/\/_/ |   \/_____/)" << endl
        << R"(      --------------------------------------------------------------)" << endl
        << R"(       __  __    |  ______    |  __  __    |  ______    |  __  __   )" << endl
        << R"(      /\_\_\_\   | /\  __ \   | /\_\_\_\   | /\  __ \   | /\_\_\_\  )" << endl
        << R"(      \/_/\_\/_  | \ \ \/\ \  | \/_/\_\/_  | \ \ \/\ \  | \/_/\_\/_ )" << endl
        << R"(        /\_\/\_\ |  \ \_____\ |   /\_\/\_\ |  \ \_____\ |   /\_\/\_\)" << endl
        << R"(        \/_/\/_/ |   \/_____/ |   \/_/\/_/ |   \/_____/ |   \/_/\/_/)" << endl;
    // separation line
    cout 
        << "-------------------------------------------------------------------------------\n"
        << "-------------------------------------------------------------------------------\n";
    cout 
        << "    [1] = start game        [2] =  help menu          [3] = exit\n";
}

/**
 *  helpscreen()             (UI function)
 *  clears the screen
 * 
 *  Input:
 *  none
 *  Output:
 *  blank spaces
 *  
 **/
void helpscreen() {
    cout
        << R"( ______ ______  ______ ______ __  __       ______  __  ______  ______        )" << endl
        << R"(/\  == /\  __ \/\  == /\__  _/\ \_\ \     /\  ___\/\ \/\___  \/\  ___\       )" << endl
        << R"(\ \  _-\ \  __ \ \  __\/_/\ \\ \____ \    \ \___  \ \ \/_/  /_\ \  __\       )" << endl
        << R"( \ \_\  \ \_\ \_\ \_\ \_\\ \_\\/\_____\    \/\_____\ \_\/\_____\ \_____\     )" << endl
        << R"(  \/_/   \/_/ /_/\/_/ /_/ \/_/ \/_____/     \/_____/\/_/\/____/ \/_____/     )" << endl
        << R"( ______ __  ______       ______ _____   _____        ______ _____   ______   )" << endl
        << R"(/\__  _/\ \/\  ___\     /\__  _/\  __ \/\  ___\     /\__  _/\  __ \/\  ___\  )" << endl
        << R"(\/_/\ \\ \ \ \ \____    \/_/\ \\ \  __ \ \ \____    \/_/\ \\ \ \/\ \ \  __\  )" << endl
        << R"(   \ \_\\ \_\ \_____\      \ \_\\ \_\ \_\ \_____\      \ \_\\ \_____\ \_____\)" << endl
        << R"(    \/_/ \/_/\/_____/       \/_/ \/_/\/_/\/_____/       \/_/ \/_____/\/_____/)" << endl;
    cout 
        << "------------------------------------------------------------------------------\n";
    cout << "instructions";
}

// Game logic functions

/**
 *  Startgame()
 *  starts the game, resets the board and starts the game via player 1
 * 
 *  Input:
 *  None
 *  Output:
 *  row1, row2, row3, row4(updates)
 *  
 **/
void startgame(string &row1, string &row2, string &row3, string &row4, string &row5) {
    for (int i = 1; i <= 5; i++) {
        row1[i] = 1;                // set all logic values from 0-4 of each row to 0 (blank)
        row2[i] = 1;
        row3[i] = 1;
        row4[i] = 1;
        row5[i] = 1;
    }
}
void errorcodes(int errorcode) {
    if (errorcode == 0) {
        return;
    }
    if (errorcode == 1) {
        cout << "Invalid coordinates\n";
    }
    if (errorcode == 2) {
        cout << "Invalid input length(input: 1 letter, 1 number)\n";
    }
    if (errorcode == 3) {
        cout << "The space is already occupied\n";
    }
    if (errorcode == 4) {
        cout << "no action selected or invalid action";
    }
    if (errorcode == 5) {
        
    }
}

/**
 *  getplayerinput()
 *  gets the player's input(coordinate)
 * 
 *  Input:
 *  player input (1 letter, 1 number)
 *  Output:
 *  row1, row2, row3, row4(update)
 *  
 **/
void getplayerinput(bool &invalidinput, int &playerturn, int players, int &errorcode, string playerinput, string &row1, string &row2, string &row3, string &row4, string &row5) {                         // input of the player given in (letter, number)
    int row, col;

    // check if player input can be processed
    if (playerinput.length() > 2 || playerinput.length() < 2) {
        invalidinput = true;
        errorcode = 2;
        return;        
    }

    // store coordinates 
    // column
    if (playerinput[0] == 'a') {
        col = 1;
    }
    if (playerinput[0] == 'b') {
        col = 2;
    }
    if (playerinput[0] == 'c') {
        col = 3;
    }
    if (playerinput[0] == 'd') {
        col = 4;
    }
    if (playerinput[0] == 'e') {
        col = 5;
    }
    // row
    row = playerinput[1] - 48;

    cout << " \n " << col << " " << row << " " << playerinput[1] << endl;

    // check for invalid values
    if (col > 5 || col < 1) {
        invalidinput = false;
        errorcode = 1;
        return;
    }

    cout << playerinput[0];
    if (row > 5 || row < 1) {
        invalidinput = false;
        errorcode = 1;
        return;
    }

    cout << "valid";

    // store the values in the correct slot
    if (row == 1) {
        // check if slot is occupied, if it is, return back to the main function
        if (row1[col] != 0) {
            errorcode = 3;
            return;
        }
        // provided that the the space is not occupied, the player places their marker on the space.
        if (row1[col] == 0) {
            row1[col] = playerturn;
        }
    }
    if (row == 2) {
        if (row2[col] != 0) {
            errorcode = 3;
            return;
        }
        if (row2[col] == 0) {
            row2[col] = playerturn;
        }
    }
    if (row == 3) {
        if (row3[col] != 0) {
            errorcode = 3;
            return;
        }
        if (row3[col] == 0) {
            row3[col] = playerturn;
        }
    }
    if (row == 4) {
        if (row4[col] != 0) {
            errorcode = 3;
            return;
        }
        if (row4[col] == 0) {
            row4[col] = playerturn;
        }
    }
    if (row == 5) {
        if (row5[col] != 0) {
            errorcode = 3;
            return;
        }
        if (row5[col] == 0) {
            row5[col] = playerturn;
        }
    }

    // tell the user that the coordinates have been successfully inserted
    cout << "input recieved\n\n\n\n";
    invalidinput = false;

    // advance the turn counter for player
    playerturn += 1;
    // check for overload (can be used to count amount of turns)
    if (playerturn > players) {
        playerturn = 1;
    }
}

/**
 *  displayboard()
 *  displays the gameboard
 * 
 *  Input:
 *  none
 *  Output:
 *  Graphical rows of the gameboard
 *  
 **/
void displayboard(string row1,string row2, string row3, string row4, string row5) {
    for (int i = 1;i <= 5; i++) {
        cout << row1[i] << "|" << row2[i] << "|" << row3[i] << "|" << row4[i] << "|" << row5[i] << "|" << endl;
    }

}


/**s
 *  wincheck()
 *  checks if a player has won the game
 * 
 *  Input:
 *  row1, row2, row3, row4
 *  Output:
 *  gamestatus(update)
 *  
 **/
void wincheck(string row1,string row2, string row3, string row4, string row5, int &gamestatus) {
    
}


/**
 *  main()
 *  main function
 * 
 *  Input:
 *  None
 *  Output:
 *  row1, row2, row3, row4(updates)
 *  
 **/
int main() {
    // Game logic variables
    // Logical rows
    string row1, row2, row3, row4, row5 = {0,0,0,0,0,0};            // string arrays for storing the player moves
    int playerturn;                                 // records who's turn it is (0, 1, 2...)
    int players = 2;                                // potential for more than 2 players;
    bool invalidinput;                              // bool for input validity

    // error code (0 = none, 1 = invalid input, 2 - input incorrect length, 3 - space occupied, 4 = no action selected/invalid action)
    int errorcode = 0;
    

    // Graphics related variables
    // Stores graphics display rows (gui (grid row), (letter row))
    string gui11, gui12, gui13, gui14, gui15;       // grid row 1
    string gui21, gui22, gui23, gui24, gui25;       // grid row 2
    string gui31, gui32, gui33, gui34, gui35;       // grid row 3
    string gui41, gui42, gui43, gui44, gui45;       // grid row 4
    string gui51, gui52, gui53, gui54, gui55;       // grid row 5

    // Separators
    string linesep = "      -------------------------------------------------------------------------------\n";
    char bar = '|';


    // tell user to enter fullscreen
    cout << "before starting the game, please enter fullscreen to allow graphics to show\n";
    system("pause");

    int gamestatus = 1;                             // game status (0 = ongoing, 1 = menu/start game, 2 = help menu, 3 = exit, 4 = player win)

    while (gamestatus != 3) {
        clearscreen;
        // game ongoing funcion
        if (gamestatus == 0) {
            invalidinput = true;
            while (invalidinput) {
                header();
                displayboard(row1, row2, row3, row4, row5);
                cout << linesep;
                if (errorcode != 0) {
                    errorcodes(errorcode);
                    errorcode = 0;
                }
                cout << "Please enter the space to put your token (chessboard coordinates): ";
                string playerinput;
                cin >> playerinput;

                getplayerinput(invalidinput, playerturn, errorcode, players, playerinput, row1, row2, row3, row4, row5);
            
            }
            clearscreen;
            continue;
            // pause
            //cin.ignore();
        }
        // option 1 display menu or start the game
        if (gamestatus == 1) {
            menu();
            cin >> gamestatus;
            if (gamestatus == 1) {
                startgame;
                gamestatus = 0;
                clearscreen();
                continue;
            }
            continue;
        }   
        // option 2 display help menu
        if(gamestatus == 2) {
            helpscreen();
            cin.ignore();
            continue;
        }   
        // option 3 exit game
        if (gamestatus == 3) {
            cout << "Thanks for playing!(press any key to close window)";
            cin.ignore();                           // ignores the user input
            break;
        }   
        if (gamestatus == 4) {
            cout << "       [1] = Back to menu         [3] = Exit";
            cin >> gamestatus;
            if (gamestatus != 1 && gamestatus != 3) {
                gamestatus = 1;
            }
            continue;
        }
        if (gamestatus != 0, 1, 2 , 3, 4, 5) {
            cout << "\n\nerror" << gamestatus << errorcode;
            errorcode = 4;
            cin.ignore();
        }
        
        // called at the end of the function to clear the terminal
        clearscreen();
    }

}
