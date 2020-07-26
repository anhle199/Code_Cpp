// main.cpp
#include "cardGame.h"

int main()
{
    int n(6), s, choice;
    const int start(1), end(5);
    vector<vector<int>> deck(SUITS, vector<int>(FACES, 0));
    vector<INFO_HAND> info_card(CARDS);
    vector<int> ranking(n), ranking_s_times;

    system("cls");

    do
    {
        cout << "------------------------------------------------------" << endl;
        cout << "--- CHAO MUNG BAN DEN VOI TRO CHOI FIVE-CARD POKER ---" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "--------------------- CHE DO CHOI --------------------" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "--- 1. 1 nguoi choi." << endl;
        cout << "--- 2. Nhieu nguoi choi (khong co nha cai)." << endl;
        cout << "--- 3. Nhieu nguoi choi (co nha cai)." << endl;
        cout << "--- 4. Dau doi khang voi nha cai." << endl;
        cout << "--- 5. Thoat tro choi." << endl;
        
        getChoice(choice, start, end);

        switch (choice)
        {
            case 1:
                system("cls");
                programForOnePlayer(deck, info_card);
                break;
            case 2:
                system("cls");
                programForMultiplayerWithoutDealer(deck, info_card,ranking, ranking_s_times, n, s);
                break;
            case 3:
                system("cls");
                programForMultiplayerAndDealer(deck, info_card, ranking, ranking_s_times, n, s);
                break;
            case 4:
                system("cls");
                programForMatchBetweenPlayerAndDealer(deck, info_card, ranking, ranking_s_times, s);
                break;
            case 5:
                cout << "==> Ban da thoat tro choi." << endl;
                break;
        }
    } while (choice != end);

    return 0;
}