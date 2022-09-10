#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Player {
    private:
        unordered_map<int, string> characters;
        string name;
    public:
        unordered_map<string, vector<int>> position;
        string currentCharacter;
        vector<int> currentMove;
        int number;
        Player(string playerName, int num)
        {
            name = playerName;
            currentMove = vector<int>(2,0);
            number = num;
        }
        void insertCharacter(int key, string name, int gridx, int gridy)
        {
            characters[key] = name;
            position[name] = {gridx, gridy};
        }
        void characterKilled(int key)
        {
            position.erase(characters[key]);
            characters.erase(key);
        }
        bool isAnyCharacterAlive()
        {
            if(characters.size()==0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        string playerName()
        {
            return name;
        }
        string characterName(int key)
        {
            return characters[key];
        }
        void newMove()
        {
            string playerMove;
            cin>>playerMove;
            currentCharacter = "";
            while(playerMove[i]!=':')
            {
                currentCharacter = currentCharacter + playerMove[i];
                i++;
            }
            i++;
            string movePosition = "";
            while(i<playerMove.size())
            {
                movePosition = movePosition + playerMove[i];
            }
            if(movePosition == 'F')
            {
                if(number = 1)
                {
                    currentMove[0] = -1;
                }
                else if(number = 2)
                {
                    currentMove[0] = 1;
                }
                currentMove[1] = 0;
            }
            else if(movePosition == 'B')
            {
                if(number = 1)
                {
                    currentMove[0] = 1;
                }
                else if(number = 2)
                {
                    currentMove[0] = -1;
                }
                currentMove[1] = 0;
            }
            else if(movePosition == 'L')
            {
                if(number = 1)
                {
                    currentMove[1] = -1;
                }
                else if(number = 2)
                {
                    currentMove[1] = 1;
                }
                currentMove[0] = 0;
            }
            else if(movePosition == 'R')
            {
                if(number = 1)
                {
                    currentMove[1] = 1;
                }
                else if(number = 2)
                {
                    currentMove[1] = -1;
                }
                currentMove[0] = 0;
            }
            else{
                cout<<"Invalid Move Name";
                cout<<endl<<"Enter move again"<<endl;
                newMove();
                return 0;
            }
        }
};

class GameBoard {
    private:
        vector<vector<int>> grid; 
    public:
        GameBoard()
        {
            grid = vector<vector<int>>( 5 , vector<int> (5, 0));
        }
        int element(int x, int y)
        {
            return grid[x][y];
        }
        void change(int x, int y, int val)
        {
            grid[x][y] = val;
        }
        void displayBoard(Player &p1, Player &p2)
        {
            cout<<endl;
            for(int i = 0; i<5; i++)
            {
                for(int j = 0; j<5; j++)
                {
                    if(grid[i][j] == 0)
                    {
                        cout<<"-"<<setw(8);
                    }
                    else if(grid[i][j]<6)
                    {
                        cout<<p1.playerName()<<"-"<<p1.characterName(grid[i][j])<<setw(8);
                    }
                    else if(grid[i][j]<11)
                    {
                        cout<<p2.playerName()<<"-"<<p2.characterName(grid[i][j])<<setw(8);
                    }
                }
                cout<<endl;
            }
            cout<<"\n";
        }
        void playerInput(Player &p1, int key, int row)
        {
            string initialPosition;
            getline(cin,initialPosition);
            string temp = "";
            int l = 0;
            for(int i = 0; i<initialPosition.size(); i++)
            {
                if(initialPosition[i]==',')
                {
                    p1.insertCharacter(key, temp, row, l);
                    grid[row][l++] = key;
                    key++;
                    temp = "";
                }
                else if (initialPosition[i]==' ')
                {
                    continue;
                }
                else{
                    temp = temp + initialPosition[i];
                }
            }
            p1.insertCharacter(key, temp, row, l);
            grid[row][l] = key;
        }
        bool isValidMove(Player &p, Player &opponent)
        {
            int x = p.position[0]+p.currentMove[0];
            int y = p.position[1]+p.currentMove[1];
            if(x>=5 || y>=5)
            {
                return false;
            }
            
            if(grid[x][y] == 0)
            {
                grid[p.position[0], p.position[1]] = 0
                p.position[0] = x;
                p.position[1] = y;
            }
            
        }
};

int main() {
    // Write C++ code here
    GameBoard grid;
    Player p1("A",1);
    Player p2("B",2);
    grid.displayBoard(p1, p2);
    
    cout<<"Player1 Input: ";
    grid.playerInput(p1, 1, 4);
    
    grid.displayBoard(p1, p2);
    
    cout<<"Player2 Input: ";
    grid.playerInput(p2, 6, 0);
    
    while()
    {
        cout<< "Player1 Input";
        p1.newMove();
        while(!grid.isValidMove(p1))
        {
            cout<<"Invalid Move";
            p1.newMove();
        }
    }

    grid.displayBoard(p1,p2);
    return 0;
}