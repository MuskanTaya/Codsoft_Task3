#include <iostream>
using namespace std;
char arr[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
void gameBoard()
{
    cout<<"\n     |     |     "<<endl;
    cout<<"  "<<arr[0]<<"  |  "<<arr[1]<< "  |  "<<arr[2]<<"  "<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"-----------------"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  " << arr[3] << "  |  " << arr[4] << "  |  "<< arr[5]<<"  "<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"-----------------"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<arr[6]<<"  |  "<<arr[7]<<"  |  "<<arr[8]<<"  "<<endl;
    cout<<"     |     |     \n\n";
}
void markTheSpot(int choice, char mark)
{
label1:
    if (choice >= 1 && choice <= 9)
    {
        if (arr[choice - 1] != 'X' || arr[choice - 1] != 'O')
        {
            arr[choice - 1] = mark;
            return;
        }
        else
        {
            goto label2;
        }
    }
    else
    {
    label2:
        cout << "\n----- Invalid move------\nEnter again: ";
        cin >> choice;
        goto label1;
    }
}
bool checkWin(char mark)
{
    if(arr[0] == mark && arr[1] == mark && arr[2] == mark)
        return true;
    if(arr[3] == mark && arr[4] == mark && arr[5] == mark)
        return true;
    if(arr[6] == mark && arr[7] == mark && arr[8] == mark)
        return true;
    if(arr[0] == mark && arr[3] == mark && arr[6] == mark)
        return true;
    if(arr[1] == mark && arr[4] == mark && arr[7] == mark)
        return true;
    if(arr[2] == mark && arr[5] == mark && arr[8] == mark)
        return true;
    if(arr[0] == mark && arr[1] == mark && arr[2] == mark)
        return true;
    if(arr[0]==mark && arr[4]==mark && arr[7]==mark)
        return true;
    if(arr[2]==mark && arr[4]==mark && arr[6]==mark){
        return true;
    }
    return false;
}
int main()
{
    int player = 1, i = 0, choice;
    char mark;
    cout << "Player 1 : X"<<endl;
    cout << "Player 2 : O"<<"\n\n";
    do
    {
        gameBoard();
        cout << "Player " << player << " turn. Enter your choice: ";
        cin >> choice;
        if (player == 1)
        {
            mark = 'X';
            player = 2;
        }
        else
        {
            mark = 'O';
            player = 1;
        }

        markTheSpot(choice, mark);
        i++;
        if(i>=5){
        if(checkWin('X')){
            cout<<"Congrats Player 1, you have won the match"<<endl;
            cout<<"Sorry Player 2, you lost the match"<<endl;
            break;
        }
        else if(checkWin('O')){
            cout<<"Congrats Player 2, you have won the match"<<endl;
            cout<<"Sorry Player 1, you lost the match"<<endl;
            break;
        }
        else{
            if(i==10){
                cout<<"It's a Draw :)"<<endl;
                break;
            }
        }
        }

    } while (i < 10);

    return 0;
}