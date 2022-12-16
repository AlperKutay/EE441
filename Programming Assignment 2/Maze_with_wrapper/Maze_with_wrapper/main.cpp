//PART1
//ALPER KUTAY ÖZBEK
//2375467
#include <fstream>
#include "stack_queues.hpp"
#include "LL_wrapper.hpp"
using namespace std;
class Maze
{
    public:
        Maze();
        StackQueue<char> sq;//it can be changed between StackQueue and wrapper func
        int row;
        int column;
        char **state;
        int s_row,s_column;
        int t_row,t_column;
        int can_move_left(void) const;
        int can_move_right(void) const;
        int can_move_forward(void) const;
        int can_move_back(void) const;
        void move_left(void);
        void move_right(void);
        void move_forward(void);
        void move_back(void);
        void print_state(void) const;
        int is_solved(void) const;
        void maze_solver(void);
        void second_pass(void);
};
Maze::Maze()
{
     ifstream input_file;
     char info[1][5]={'E','W','N','S','T'};
     input_file.open("input_maze2.txt");
     input_file >> row >> column;

     state = new char*[row];
     for(int i=0; i<row; ++i)//Taking Values of map to state 2D array
    {
            state[i]=new char[column];
         for(int j=0; j<column; ++j)
            {
             input_file >> state[i][j];
             if(info[0][0]==state[i][j]|| info[0][1]==state[i][j]|| info[0][2]==state[i][j]|| info[0][3]==state[i][j])//Taking position of E
             {
                 s_row=i;
                 s_column=j;
             }
             if(info[0][4]==state[i][j])//Taking position of E
             {
                 t_row=i;
                 t_column=j;
             }
        }
     }
     input_file.close();
}
int Maze::can_move_back(void) const
{
    switch(state[s_row][s_column])//check current position of player
    {
    case 'W':
        if(state[s_row][s_column+1]=='.' || state[s_row][s_column+1]=='T' )//check way is adaquate to move or game can finish
           return true;
        else
            return false;
    case 'E':
        if(state[s_row][s_column-1]=='.' || state[s_row][s_column-1]=='T' )//check way is adaquate to move or game can finish
           return true;
        else
            return false;
    case 'N':
        if(state[s_row+1][s_column]=='.' || state[s_row+1][s_column]=='T' )//check way is adaquate to move or game can finish
           return true;
        else
            return false;
    case 'S':
        if(state[s_row-1][s_column]=='.' || state[s_row-1][s_column]=='T' )//check way is adaquate to move or game can finish
           return true;
        else
            return false;
    }
}
int Maze::can_move_left(void) const
{

    switch(state[s_row][s_column])//check current position of player
    {
    case 'W':
        if(state[s_row+1][s_column]=='.' || state[s_row+1][s_column]=='T' )//check way is adaquate to move or game can finish
           return true;
        else
            return false;
    case 'E':
        if(state[s_row-1][s_column]=='.' || state[s_row-1][s_column]=='T' )//check way is adaquate to move or game can finish
           return true;
        else
            return false;
    case 'N':
        if(state[s_row][s_column-1]=='.'|| state[s_row][s_column-1]=='T' )//check way is adaquate to move or game can finish
           return true;
        else
            return false;
    case 'S':
        if(state[s_row][s_column+1]=='.'|| state[s_row][s_column+1]=='T' )//check way is adaquate to move or game can finish
           return true;
        else
            return false;
    }

}
int Maze::can_move_right(void) const
{
    switch(state[s_row][s_column])//check current position of player
    {
    case 'W':
        if(state[s_row-1][s_column]=='.'|| state[s_row-1][s_column]=='T' )//check way is adaquate to move or game can finish
           return true;
        else
            return false;
    case 'E':
        if(state[s_row+1][s_column]=='.'|| state[s_row+1][s_column]=='T' )//check way is adaquate to move or game can finish
           return true;
        else
            return false;
    case 'N':
        if(state[s_row][s_column+1]=='.'|| state[s_row][s_column+1]=='T' )//check way is adaquate to move or game can finish
           return true;
        else
            return false;
    case 'S':
        if(state[s_row][s_column-1]=='.'|| state[s_row][s_column-1]=='T' )//check way is adaquate to move or game can finish
           return true;
        else
            return false;
    }
}
int Maze::can_move_forward(void) const
{
    switch(state[s_row][s_column])//check current position of player
    {
    case 'W':
        if(state[s_row][s_column-1]=='.' || state[s_row][s_column-1]=='T' )//check way is adaquate to move or game can finish
           return true;
        else
            return false;
    case 'E':
        if(state[s_row][s_column+1]=='.' || state[s_row][s_column+1]=='T' )//check way is adaquate to move or game can finish
           return true;
        else
            return false;
    case 'N':
        if(state[s_row-1][s_column]=='.' || state[s_row-1][s_column]=='T' )//check way is adaquate to move or game can finish
           return true;
        else
            return false;
    case 'S':
        if(state[s_row+1][s_column]=='.' || state[s_row+1][s_column]=='T' )//check way is adaquate to move or game can finish
           return true;
        else
            return false;
    }
}
void Maze::move_right(void)
{
    if(can_move_right())//if can move right
    {

        switch(state[s_row][s_column])//check current position of player
        {

        case 'W':
            state[s_row][s_column]='.';//previous position becomes "."
            s_row--;//position changed
            state[s_row][s_column]='N';//direction changed
            break;

        case 'E':
            state[s_row][s_column]='.';//previous position becomes "."
            s_row++;//position changed
            state[s_row][s_column]='S';//direction changed
            break;

        case 'N':
            state[s_row][s_column]='.';//previous position becomes "."
            s_column++;//position changed
            state[s_row][s_column]='E';//direction changed
            break;

        case 'S':
            state[s_row][s_column]='.';//previous position becomes "."
            s_column--;//position changed
            state[s_row][s_column]='W';//direction changed
            break;
        }
    }

}
void Maze::move_left(void)
{
    if(can_move_left())
    {

        switch(state[s_row][s_column])
        {
        case 'W':
            state[s_row][s_column]='.';//previous position becomes "."
            s_row++;//position changed
            state[s_row][s_column]='S';//direction changed
            break;

        case 'E':
            state[s_row][s_column]='.';//previous position becomes "."
            s_row--;//position changed
            state[s_row][s_column]='N';//direction changed
            break;

        case 'N':
            state[s_row][s_column]='.';//previous position becomes "."
            s_column--;//position changed
            state[s_row][s_column]='W';//direction changed
            break;

        case 'S':

            state[s_row][s_column]='.';//previous position becomes "."
            s_column++;//position changed
            state[s_row][s_column]='E';//direction changed
            break;
        }
    }

}
void Maze::move_back(void)
{
    if(can_move_back())
    {
        switch(state[s_row][s_column])
        {
        case 'W':
            state[s_row][s_column]='.';//previous position becomes "."
            s_column++;//position changed
            state[s_row][s_column]='E';//direction changed
            break;

        case 'E':
            state[s_row][s_column]='.';//previous position becomes "."
            s_column--;//position changed
            state[s_row][s_column]='W';//direction changed
            break;

        case 'N':
            state[s_row][s_column]='.';//previous position becomes "."
            s_row++;//position changed
            state[s_row][s_column]='S';//direction changed
            break;

        case 'S':
            state[s_row][s_column]='.';//previous position becomes "."
            s_row--;//position changed
            state[s_row][s_column]='N';//direction changed
            break;
        }
    }

}
void Maze::move_forward(void)
{

    if(can_move_forward())
    {
        switch(state[s_row][s_column])
        {
        case 'W':
            state[s_row][s_column]='.';//previous position becomes "."
            s_column--;//position changed
            state[s_row][s_column]='W';//direction changed
            break;

        case 'E':

            state[s_row][s_column]='.';//previous position becomes "."
            s_column++;//position changed
            state[s_row][s_column]='E';//direction changed
            break;

        case 'N':
            state[s_row][s_column]='.';//previous position becomes "."
            s_row--;//position changed
            state[s_row][s_column]='N';//direction changed
            break;

        case 'S':
            state[s_row][s_column]='.';//previous position becomes "."
            s_row++;//position changed
            state[s_row][s_column]='S';//direction changed
            break;
        }
    }
}
void Maze::print_state(void)const
{
    for(int i=0; i<row; ++i)//Taking Values of map to state 2D array
    {
         for(int j=0; j<column; ++j)
            {
             cout<<state[i][j];
        }
        cout<<endl;
     }

}
int Maze::is_solved(void) const
{
    if(s_row==t_row && s_column==t_column)//check current position of player is equal to the position of the target
    {
        cout<<"Maze is solved."<<endl;
        return true;
    }
    else
        return false;
}
void Maze::maze_solver(void)
{
    if(can_move_left())
    {
        move_left();
        if(sq.peek_rear()!='B')//if last element is not "B"
        {
            sq.push_rear('L');
        }
        else if(sq.peek_rear()=='B')//if last element is "B"
        {
            sq.pop_rear();//Rear element of the Stack
            char direction = sq.pop_rear();//Rear-1 element of the Stack
            if(direction=='L')//change direction according to previos directions
            {
                sq.push_rear('F');
            }
            else if(direction=='F')//change direction according to previos directions
            {
                sq.push_rear('R');
            }
            else if(direction=='R')//change direction according to previos directions
            {
                sq.push_rear('B');
            }

        }
        sq.print_elements();
         print_state();
    }
    else if(!can_move_left() && can_move_forward())
    {
        move_forward();
        if(sq.peek_rear()!='B')//change direction according to previos directions
        {
            sq.push_rear('F');
        }
        else if(sq.peek_rear()=='B')//if last element is not "B"
        {
            sq.pop_rear();//Rear element of the Stack
            char direction = sq.pop_rear();//Rear-1 element of the Stack
            if(direction=='L')//change direction according to previos directions
            {
                sq.push_rear('R');
            }
            else if(direction=='F')//change direction according to previos directions
            {
                sq.push_rear('B');
            }
        }
        sq.print_elements();
         print_state();
    }
    else if(!can_move_left() && !can_move_forward()&& can_move_right())
    {
        move_right();
        if(sq.peek_rear()!='B')//if last element is not "B"
        {
            sq.push_rear('R');
        }
        else if(sq.peek_rear()=='B')//if last element is "B"
        {
            sq.pop_rear();//Rear element of the Stack
            char direction = sq.pop_rear();//Rear-1 element of the Stack
            if(direction=='L')
            {
                sq.push_rear('B');
            }
        }
        sq.print_elements();
         print_state();
    }
    else if(!can_move_left() && !can_move_forward() && !can_move_right() && can_move_back())
    {
        move_back();
        sq.push_rear('B');
        sq.print_elements();
         print_state();
    }

    if(!is_solved())
    {
        maze_solver();
    }
    else
        return;


}
void Maze::second_pass(void)
{
    Maze m_new;
    sq.print_elements();
    m_new.print_state();
     cout<<endl;
    cout<<"Second Pass:"<<endl;
    while(!m_new.is_solved())//loop until maze is solved
    {

        char direction =sq.pop_front();//always look at the front element
        switch(direction)//according to direction of front element, functions process
        {
            case 'F':
                m_new.move_forward();
                sq.print_elements();
                m_new.print_state();
                break;
            case 'B':
                m_new.move_back();
                sq.print_elements();
                m_new.print_state();
                break;
            case 'R':
                m_new.move_right();
                sq.print_elements();
                m_new.print_state();
                break;
            case 'L':
                m_new.move_left();
                sq.print_elements();
                m_new.print_state();
                break;
        }
    }
}
int main()
{
    Maze m;
    cout<<"First Pass:"<<endl;
    m.maze_solver();
    m.second_pass();


}
