// cardGame.cpp
#include "cardGame.h"
#include <ctime>
#include <iomanip>
#include <algorithm>

bool INFO_HAND::operator<(const INFO_HAND &card)
{
    if (value < card.value)
        return true;
    else if ((value == card.value) && (face > card.face))
        return true;

    return false;
}

INFO_PLAYER::INFO_PLAYER()
{
    score = 0;
    rank = 1;
}

void pauseScreen()
{
    int choice;

    cout << endl;
    do
    {
        cout << "==> Vui long an phim 9 de tiep tuc: ";
        cin >> choice;
    } while (choice != CONDITION);

    system("cls");
}

void getChoice(int &choice, const int &start, const int &end)
{
    cout << "==> Moi nhap lua chon cua ban: ";
    cin >> choice;

    while (choice < start || choice > end)
    {
        cout << "==> So ban vua nhap khong hop le." << endl;
        cout << "==> Moi nhap lai lua chon cua ban: ";
        cin >> choice;
    }
}

void getChoiceOfDealer(const vector<INFO_HAND> &info_card, vector<INFO_HAND> &hand_dealer, const int &n, const int &choice, const int &choose_mode)
{
    int number_of_cards;

    switch (choice)
    {
        case 1:
            break;
        case 2:
            cout << "\n==> Nha cai duoc rut them tu 1-3 den ba la bai." << endl;
            getChoice(number_of_cards, 1, 3);
            
            theFirstAlgorithm(info_card, hand_dealer, number_of_cards, n);
            break;
        case 3:
            cout << "\n==> Nha cai duoc rut them tu 1-3 den ba la bai." << endl;
            getChoice(number_of_cards, 1, 3);
            
            chooseGameMode(info_card, hand_dealer, n, number_of_cards, choose_mode);
            break;
    }
}

void getNumberOfPlayers(int &n)
{
    cout << "==> Moi ban nhap vao so luong nguoi choi (2-9): ";
    cin >> n;

    while (n < 2 || n > MAX_PLAYERS)
    {
        cout << "==> So luong nguoi choi ban nhap vao khong hop le." << endl;
        cout << "==> Moi ban nhap lai so luong nguoi choi: ";
        cin >> n;
    }
}

void getNumberOfTimesPlayed(int &s)
{
    cout << "==> Moi ban nhap vao so lan choi: ";
    cin >> s;

    while (s < 1)
    {
        cout << "==> So lan choi ban nhap vao khong hop le." << endl;
        cout << "==> Moi ban nhap lai so lan choi: ";
        cin >> s;
    }
}

void getUserName(string &user_name)
{   
    cout << "==> Nhap ten nguoi choi (khong qua 25 ky tu): ";
    getline(cin, user_name);

    while (user_name.length() > 25)
    {
        cout << "==> Ten qua dai. Vui long nhap lai ten khac." << endl;
        cout << "==> Nhap ten nguoi choi (khong qua 25 ky tu): ";
        getline(cin, user_name);    
    }
}

void getMultipleUserNames(vector<INFO_PLAYER> &info_players, const int &n, bool is_dealer)
{
    int i = 0;

    if (is_dealer)
    {
        info_players[i].user_name = "Nha cai";
        i++;    
    }

    for ( ; i < n; i++) 
        getUserName(info_players[i].user_name);
}

void showStatusOfHand(const int &score)
{
    switch (score)
    {
    case 0:
        cout << "==> Bai cua ban khong thuoc cac truong hop dac biet." << endl;
        break;
    case 1:
        cout << "==> Bai cua ban thuoc truong hop chua 1 cap (pair)." << endl;
        break;
    case 2:
        cout << "==> Bai cua ban thuoc truong hop chua 2 cap (two pairs)." << endl;
        break;
    case 3:
        cout << "==> Bai cua ban thuoc truong hop chua 3 la cung gia tri (three of a kind)." << endl;
        break;
    case 4:
        cout << "==> Bai cua ban thuoc truong hop chua 5 la co gia tri lien tiep (straight)." << endl;
        break;
    case 5:
        cout << "==> Bai cua ban thuoc truong hop chua 5 la co cung chat (flush)." << endl;
        break;
    case 6:
        cout << "==> Bai cua ban thuoc truong hop chua 3 la co cung gia tri va 1 cap (full house)." << endl;
        break;
    case 7:
        cout << "==> Bai cua ban thuoc truong hop chua 4 la co cung gia tri (four of a kind)." << endl;
        break;
    case 8:
        cout << "==> Bai cua ban thuoc truong hop chua 5 la co gia tri lien tiep va cung chat (straight flush)." << endl;
        break;
    }
}

void showInfoPlayer(const INFO_PLAYER &info_player)
{
    cout << "==> Ten nguoi choi: " << info_player.user_name << endl;
    cout << "==> Diem: " << info_player.score << endl;
}

void showInfoMultiplePlayers(vector<INFO_PLAYER> &info_players, const vector<int> &ranking, const vector<int> &score, const int &n, const int &s, bool is_dealer)
{
    int pos;

    cout << "==> Ket qua cua n nguoi choi sau " << s << " lan:\n" << endl;
    cout << setw(8) << left << " RANK" << setw(30) << left << "NAME PLAYERS" << setw(8) << left << "SCORE" << endl;

    for (int i = 0; i < n; i++)
    {
        info_players[i].rank = ranking[i];
        info_players[i].score = score[i];
    }

    // Sắp xếp thông tin người chơi tăng dần theo thứ hạng.
    for (int i = 0; i < n - 1; i++)
    {
        pos = i;

        for (int j = i + 1; j < n; j++)
            if (info_players[pos].rank > info_players[j].rank)
                pos = j;

        swap(info_players[i], info_players[pos]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << " " << setw(7) << left << info_players[i].rank << setw(32) << left << info_players[i].user_name;
        cout << setw(6) << left << info_players[i].score << endl;
    }
}

//------------------------------------------------
// I. Cơ bản: Card shuffling & Dealing.

void shufflingCards(vector<vector<int>> &deck)
{
    vector<bool> check_card_duplicate(CARDS, false);
    int random_number;

    srand((int)time(NULL));

    for (int i = 0; i < SUITS; i++)
        for (int j = 0; j < FACES; j++)
        {
            random_number = (rand() % CARDS) + 1;

            while (check_card_duplicate[random_number - 1])
                random_number = (rand() % CARDS) + 1;

            deck[i][j] = random_number;
            check_card_duplicate[random_number - 1] = true;
        }
}

void dealingCards(const vector<INFO_HAND> &info_card)
{
    int i = 1;

    // In lá bài theo thứ tự từ 1-52.
    for (const INFO_HAND &card : info_card)
    {
        cout << "La thu " << i++ << ": ";
        cout << "(" << suits[card.face] << ", " << face_value[card.value] << ")" << endl;
    }
}

void createArraySaveCardInformationInOrder(const vector<vector<int>> &deck, vector<INFO_HAND> &info_card)
{
    for (int i = 0; i < SUITS; i++)
        for (int j = 0; j < FACES; j++)
        {
            info_card[deck[i][j] - 1].face = i;
            info_card[deck[i][j] - 1].value = j;
        }
}

//------------------------------------------------
// II. Bài tập: Five-card poker(Card game).

// Phần 1.

void dealingHand(const vector<INFO_HAND> &info_card, vector<INFO_HAND> &hand)
{
    for (int i = 0; i < KCARDS; i++)
        hand[i] = info_card[i];
}

void printHand(const vector<INFO_HAND> &hand)
{
    int i;

    for (i = 0; i < KCARDS - 1; i++)
        cout << "(" << suits[hand[i].face] << ", " << face_value[hand[i].value] << "), ";
    cout << "(" << suits[hand[i].face] << ", " << face_value[hand[i].value] << ")" << endl;
}

bool isFourOfAKind(const vector<INFO_HAND> &hand)
{
    vector<int> value_of_card(FACES, 0);

    for (const INFO_HAND &card : hand)
        value_of_card[card.value]++;

    for (const int &number_of_cards : value_of_card)
        if (number_of_cards == 4)
            return true;

    return false;
}

bool isFullHouse(const vector<INFO_HAND> &hand)
{
    vector<int> value_of_card(FACES, 0);
    bool is_two_cards(false), is_three_cards(false);

    for (const INFO_HAND &card : hand)
        value_of_card[card.value]++;

    for (const int &number_of_cards : value_of_card)
    {
        if (number_of_cards == 3)
            is_three_cards = true;
        else if (number_of_cards == 2)
            is_two_cards = true;
    }

    if (is_three_cards == false || is_two_cards == false)
        return false;
    return true;
}

bool isFlush(const vector<INFO_HAND> &hand)
{
    vector<int> suits_of_card(SUITS, 0);

    for (const INFO_HAND &card : hand)
        suits_of_card[card.face]++;

    for (const int &number_of_cards : suits_of_card)
        if (number_of_cards == 5)
            return true;

    return false;
}

bool isStraight(const vector<INFO_HAND> &hand)
{
    for (int i = 0; i < KCARDS - 1; i++)
        if (hand[i + 1].value - hand[i].value != 1)
            return false;

    return true;
}

bool isStraightFlush(const vector<INFO_HAND> &hand)
{
    if (isStraight(hand) == false || isFlush(hand) == false)
        return false;
    return true;
}

bool isThreeOfAKind(const vector<INFO_HAND> &hand)
{
    vector<int> value_of_card(FACES, 0);

    for (const INFO_HAND &card : hand)
        value_of_card[card.value]++;

    for (const int &number_of_cards : value_of_card)
        if (number_of_cards == 3)
            return true;

    return false;
}

bool isTwoPairs(const vector<INFO_HAND> &hand)
{
    vector<int> value_of_card(FACES, 0);
    int count_two_cards = 0;

    for (const INFO_HAND &card : hand)
        value_of_card[card.value]++;

    for (const int &number_of_cards : value_of_card)
    {
        if (number_of_cards == 4)
            return true;
        else if (number_of_cards == 2)
            count_two_cards++;
    }

    return (count_two_cards == 2) ? (true) : (false);
}

bool isPair(const vector<INFO_HAND> &hand)
{
    vector<int> value_of_card(FACES, 0);

    for (const INFO_HAND &card : hand)
        value_of_card[card.value]++;

    for (const int &number_of_cards : value_of_card)
        if (number_of_cards == 2)
            return true;

    return false;
}

INFO_HAND getHighestCard(const vector<INFO_HAND> &hand)
{
    INFO_HAND max_card = hand[0];

    for (int i = 1; i < KCARDS; i++)
        if (max_card < hand[i])
            max_card = hand[i];

    return max_card;
}

int getStatusOfHand(const vector<INFO_HAND> &hand)
{
    int score = 0;

    if (isStraightFlush(hand))
        score = 8;
    else if (isFourOfAKind(hand))
        score = 7;
    else if (isFullHouse(hand))
        score = 6;
    else if (isFlush(hand))
        score = 5;
    else if (isStraight(hand))
        score = 4;
    else if (isThreeOfAKind(hand))
        score = 3;
    else if (isTwoPairs(hand))
        score = 2;
    else if (isPair(hand))
        score = 1;

    return score;
}

void programForOnePlayer(vector<vector<int>> &deck, vector<INFO_HAND> &info_card)
{
    bool flag = false;
    int choice, score, number_of_times = 0, max_score = 0, pos_max_score = 0;
    const int start(1), end(6);
    vector<INFO_HAND> hand(KCARDS);
    vector<INFO_PLAYER> info_player_s_times;
    INFO_PLAYER info_player;

    cin.ignore();
    getUserName(info_player.user_name);
    info_player_s_times.push_back(info_player);

    system("cls");

    do
    {
        cout << "------------------------------------------------------" << endl;
        cout << "--- CHAO MUNG BAN DEN VOI TRO CHOI FIVE-CARD POKER ---" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "----- CHAO MUNG BAN DEN VOI CHE DO 1 NGUOI CHOI ------" << endl;
        cout << "------------------------------------------------------" << endl;
        cout << "--------------------- CHUC NANG ----------------------" << endl;
        cout << "--- 1. Xao bai." << endl;
        cout << "--- 2. Chia bai." << endl;
        cout << "--- 3. Xem diem." << endl;
        cout << "--- 4. Xem thong tin nguoi choi dat diem cao nhat " 
             << "(nguoi choi cuoi cung dat diem cao nhat)." << endl;
        cout << "--- 5. Thay doi ten nguoi choi." << endl;
        cout << "--- 6. Thoat che do 1 nguoi choi." << endl;

        getChoice(choice, start, end);

        switch (choice)
        {
            case 1:
                shufflingCards(deck);
                createArraySaveCardInformationInOrder(deck, info_card);
                cout << "==> Da xao bai." << endl;
                
                // Tránh trường hợp trong lượt chơi mà s_times = 1 (s_times = 0 mới đúng); 
                if (!flag) 
                {
                    flag = true;
                    break;
                }
                
                info_player_s_times.push_back(info_player);
                number_of_times++; // Mỗi lượt chia bài sẽ là 1 lần chơi mới.
                break;
            case 2:
                dealingHand(info_card, hand);
                cout << "==> Da chia bai." << endl;
                cout << "==> Bai cua ban: ";
                printHand(hand);
                break;
            case 3:
                score = getStatusOfHand(hand);
                cout << "==> Diem cua ban: " << score << endl;
                showStatusOfHand(score);

                info_player_s_times[number_of_times].score = score;
                if (max_score <= score)
                {
                    max_score = score;
                    pos_max_score = number_of_times;
                }
                break;
            case 4:
                showInfoPlayer(info_player_s_times[pos_max_score]);
                break;
            case 5:
                cin.ignore();
                getUserName(info_player.user_name);
                info_player_s_times.push_back(info_player);
                number_of_times++;
                break;
            case 6:
                system("cls");
                break;
        }

        // Dừng màn hình console trước khi chuyển sang chức năng khác.
        if (choice != end)
            pauseScreen();

    } while (choice != end);
}

// Phần 2.

void initArrayForNPlayers(vector<INFO_PLAYER> &info_player, vector<int> &score, vector<int> &ranking, vector<int> &ranking_s_times, vector<vector<INFO_HAND>> &hands, const int &n)
{
    info_player.resize(n);
    score.resize(n);
    ranking.resize(n);
    ranking_s_times.resize(n);

    hands.resize(n);
    for (int i = 0; i < n; i++)
        hands[i].resize(KCARDS);
}

void calculateScoreOfNPlayers(const vector<vector<INFO_HAND>> &hands, vector<int> &score_n_players, const int &n)
{
    bool flag = true; // Biến flag có giá trị "true" nếu toàn bộ người chơi đều bị 0 điểm.

    for (int i = 0; i < n; i++)
    {
        score_n_players[i] = getStatusOfHand(hands[i]);

        if (score_n_players[i] != 0)
            flag = false;
    }

    if (flag)
    { // Tất cả người chơi đều 0đ thì người có lá bài lớn nhất sẽ được 1đ.
        INFO_HAND max_card, card;
        int pos = 0; // Vị trí của người chơi có lá bài lớn nhất.

        max_card = getHighestCard(hands[0]);

        // Tìm chỉ số của người chơi có lá bài lớn nhất.
        for (int i = 1; i < n; i++)
        {
            card = getHighestCard(hands[i]);

            if (max_card < card)
            {
                max_card = card;
                pos = i;
            }
        }

        // Người chơi có lá bài lớn nhất sẽ được 1 điểm.
        score_n_players[pos] = 1;
    }
    else
    { // Tất cả người chơi có điểm nhỏ nhất sao 1 lượt sẽ bị 0đ.
        int min_score = (*min_element(score_n_players.begin(), score_n_players.end()));

        for (int &score : score_n_players)
            if (min_score == score)
                score = 0;
    }
}

vector<int> countScoreAndRank(const vector<int> &score_n_players)
{
    int current_rank(1), distance_rank(1);
    vector<int>::const_iterator it; // Biến it dùng để trỏ đến 1 phần tử trong vector.

    // Tìm điểm cao nhất trong n người chơi.
    it = max_element(score_n_players.begin(), score_n_players.end());
    
    // (*it) + 1 tương đương với điểm từ 0 đến điểm cao nhất.
    vector<int> counting_score((*it) + 1, 0);

    for (const int &score : score_n_players)
        counting_score[score]++;

    for (int i = counting_score.size() - 1; i > -1; i--)
        if (counting_score[i] != 0)
        {
            distance_rank = counting_score[i];
            counting_score[i] = current_rank;
            current_rank += distance_rank;
        }

    return counting_score;
}

void dealingNHands(const vector<INFO_HAND> &info_card, vector<vector<INFO_HAND>> &hands, const int &n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < KCARDS; j++)
            hands[i][j] = info_card[i + (j * n)];
}

void printNHands(const vector<vector<INFO_HAND>> &hands, bool is_dealer)
{
    int i = 1;

    for (const vector<INFO_HAND> &hand : hands)
    {
        if (is_dealer && i == 1)
        {
            cout << "==> Bai cua nha cai: ";
            printHand(hand);
            i++;
        }
        else
        {
            cout << "==> Bai cua nguoi choi " << i++ << ": ";
            printHand(hand);
        }
    }
}

void rankingNHands(const vector<vector<INFO_HAND>> &hands, vector<int> &ranking, vector<int> &score, const int &n)
{
    vector<int> score_n_players(n), counting_score;

    // Tính điểm của n người chơi.
    calculateScoreOfNPlayers(hands, score_n_players, n);

    // Tính số lượng từng loại điểm và xếp hạng từng loại điểm đó.
    counting_score = countScoreAndRank(score_n_players);

    // Xếp thứ hạng từng người chơi.
    for (int i = 0; i < n; i++)
        ranking[i] = counting_score[score_n_players[i]];

    // Copy điểm sang mảng score để dùng cho hàm showInfoMultiplePlayers.
    score = score_n_players;
}

void evaluateNHands(vector<vector<int>> &deck, vector<INFO_HAND> &info_card, vector<vector<INFO_HAND>> &hands, vector<int> &ranking_s_times, vector<int> &score, const int &n, const int &s)
{
    vector<int> score_n_players_s_times(n, 0), score_n_players(n), counting_score;

    for (int i = 0; i < s; i++)
    {
        // Tính điểm của n người chơi sau 1 lần chia bài.
        calculateScoreOfNPlayers(hands, score_n_players, n);

        // Cập nhật số điểm của n người chơi sau 1 lần chơi.
        for (int j = 0; j < n; j++)
            score_n_players_s_times[j] += score_n_players[j];

        if (i == s - 1)
            break;

        shufflingCards(deck); // Tráo bài lại.
        createArraySaveCardInformationInOrder(deck, info_card);
        dealingNHands(info_card, hands, n);

        cout << "Lan chia bai thu " << i + 2 << ":" << endl;
        printNHands(hands);
    }

    // Tính số lượng từng loại điểm và xếp hạng từng loại điểm đó.
    counting_score = countScoreAndRank(score_n_players_s_times);

    // Xếp thứ hạng từng người chơi.
    for (int i = 0; i < n; i++)
        ranking_s_times[i] = counting_score[score_n_players_s_times[i]];

    // Copy điểm sang mảng score để dùng cho hàm showInfoMultiplePlayers.
    score = score_n_players_s_times;
}

void programForMultiplayerWithoutDealer(vector<vector<int>> &deck, vector<INFO_HAND> &info_card, vector<int> &ranking, vector<int> &ranking_s_times, int &n, int &s)
{
    int choice;
    const int start(1), end(6), condition(9);
    vector<vector<INFO_HAND>> hands;
    vector<int> score;
    vector<INFO_PLAYER> info_players;

    getNumberOfPlayers(n);
    getNumberOfTimesPlayed(s);

    // Khởi tạo số lượng phần tử của mảng
    initArrayForNPlayers(info_players, score, ranking, ranking_s_times, hands, n);

    // Nhập tên của n người chơi.
    cin.ignore();
    getMultipleUserNames(info_players, n);

    system("cls");

    do
    {
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "--------------- CHAO MUNG BAN DEN VOI TRO CHOI FIVE-CARD POKER --------------" << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "----- CHAO MUNG BAN DEN VOI CHE DO NHIEU NGUOI CHOI (KHONG CO NHA CAI) ------" << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "-------------------------------- CHUC NANG ----------------------------------" << endl;
        cout << "--- 1. Xao bai." << endl;
        cout << "--- 2. Chia bai." << endl;
        cout << "--- 3. Xem ket qua (diem va thu hang)." << endl;
        cout << "--- 4. Thay doi so luong nguoi choi." << endl;
        cout << "--- 5. Thay doi so lan choi." << endl;
        cout << "--- 6. Thoat che do nhieu nguoi choi." << endl;

        getChoice(choice, start, end);

        switch (choice)
        {
            case 1:
                shufflingCards(deck);
                createArraySaveCardInformationInOrder(deck, info_card);
                cout << "==> Da xao bai." << endl;
                break;
            case 2:
                dealingNHands(info_card, hands, n);
                cout << "--- Lan chia bai thu 1:" << endl;
                printNHands(hands);

                if (s == 1)
                    rankingNHands(hands, ranking, score, n);
                else
                    evaluateNHands(deck, info_card, hands, ranking_s_times, score, n, s);

                cout << "==> Da chia bai." << endl;
                break;
            case 3:
                if (s == 1)
                    showInfoMultiplePlayers(info_players, ranking, score, n, s);
                else
                    showInfoMultiplePlayers(info_players, ranking_s_times, score, n, s);

                break;
            case 4:
                getNumberOfPlayers(n);
                initArrayForNPlayers(info_players, score, ranking, ranking_s_times, hands, n);
                cout << "==> Vui long nhap lai ten cua " << n << " nguoi choi.\n" << endl;
                cin.ignore();
                getMultipleUserNames(info_players, n);
                break;
            case 5:
                getNumberOfTimesPlayed(s);
                break;
            case 6:
                system("cls");
                break;
        }

        // Dừng màn hình console trước khi chuyển sang chức năng khác.
        if (choice != end)
            pauseScreen();

    } while (choice != end);
}

// Phần 3.

bool greaterThan(const int &a, const int &b)
{
    return a > b;
}

bool greaterThanOrEqualTo(const int &a, const int &b)
{
    return a >= b;
}

void changeCardToGetHighestScore1(vector<INFO_HAND> &hand, const INFO_HAND &card)
{
    int pos(-1), score_max, score;
    INFO_HAND temp;

    // Tính điểm trước khi thay thế.
    score_max = getStatusOfHand(hand);

    for (int i = 0; i < KCARDS; i++)
    {
        temp = hand[i]; // Lưu lá bài đã bị thay thế để trả lại vị trí cũ sao khi tính điểm.
        hand[i] = card;
        score = getStatusOfHand(hand);

        if (score >= score_max)
        {
            score_max = score;
            pos = i;
        }

        hand[i] = temp; // Trả lại lá bài trước khi thay thế.
    }

    if (pos != -1)
        hand[pos] = card;
}

void changeCardToGetHighestScore2(vector<INFO_HAND> &hand, const INFO_HAND &card, int &count, bool (*compare)(const int&, const int&))
{
    int pos(-1), score_max, score;
    INFO_HAND temp;

    // Tính điểm trước khi thay thế.
    score_max = getStatusOfHand(hand);

    for (int i = 0; i < KCARDS; i++)
    {
        temp = hand[i]; // Lưu lá bài đã bị thay thế để trả lại vị trí cũ sao khi tính điểm.
        hand[i] = card;
        score = getStatusOfHand(hand);

        if (compare(score, score_max))
        {
            score_max = score;
            pos = i;
        }

        hand[i] = temp; // Trả lại lá bài trước khi thay thế.
    }

    if (pos != -1)
    {
        hand[pos] = card;
        count++;
    }
}

void evaluateNHandsWithDealer(vector<vector<int>> &deck, vector<INFO_HAND> &info_card, vector<vector<INFO_HAND>> &hands, vector<int> &ranking_s_times, vector<int> &score, const int &choice_of_dealer, const int &choose_mode, const int &n, const int &s)
{
    bool is_dealer = true;
    vector<int> score_n_players_s_times(n, 0), score_n_players(n), counting_score;
    vector<INFO_HAND> hand_dealer(KCARDS), hand_player(KCARDS);

    for (int i = 0; i < s; i++)
    {
        // Tính điểm của n người chơi sau 1 lần chia bài.
        calculateScoreOfNPlayers(hands, score_n_players, n);

        // Cập nhật số điểm của n người chơi sau 1 lần chơi.
        for (int j = 0; j < n; j++)
            score_n_players_s_times[j] += score_n_players[j];

        if (i == s - 1)
            break;

        shufflingCards(deck); // Tráo bài lại.
        createArraySaveCardInformationInOrder(deck, info_card);
        dealingNHands(info_card, hands, n); // Chia bài cho n người chơi.

        // Nhà cái là người chơi thứ 1.
        hand_dealer = hands[0];
        getChoiceOfDealer(info_card, hand_dealer, n, choice_of_dealer, choose_mode);
        hands[0] = hand_dealer;

        cout << "--- Lan chia bai thu " << i + 2 << ":" << endl;
        printNHands(hands, is_dealer);
    }

    // Tính số lượng từng loại điểm và xếp hạng từng loại điểm đó.
    counting_score = countScoreAndRank(score_n_players_s_times);

    // Xếp thứ hạng từng người chơi.
    for (int i = 0; i < n; i++)
        ranking_s_times[i] = counting_score[score_n_players_s_times[i]];

    // Copy điểm sang mảng score để dùng cho hàm showInfoMultiplePlayers.
    score = score_n_players_s_times;
}

void theFirstAlgorithm(const vector<INFO_HAND> &info_card, vector<INFO_HAND> &hand_dealer, const int &number_of_cards, const int &n)
{
    if (number_of_cards == 0)
        return; // Dealer không quyết định rút thêm lá bài mới.

    int pos;
    vector<bool> check_card_duplicate(KCARDS, false); // Những vị trí mà thẻ đó đã được thay thế sẽ có giá trị "true".

    srand((int)time(NULL));

    for (int i = 0; i < number_of_cards; i++)
    {
        pos = rand() % 5;

        // Tìm vị trí lá bài chưa bị thay thế
        while (check_card_duplicate[pos])
            pos = rand() % 5;

        hand_dealer[pos] = info_card[(n * KCARDS) + i];
        check_card_duplicate[pos] = true;
    }
}

void programForMultiplayerAndDealer(vector<vector<int>> &deck, vector<INFO_HAND> &info_card, vector<int> &ranking, vector<int> &ranking_s_times, int &n, int &s)
{
    bool is_dealer = true;
    int choice, choice_of_dealer, choose_mode;
    const int start(1), end(7), condition(9);
    vector<vector<INFO_HAND>> hands;
    vector<INFO_HAND> hand_dealer(KCARDS);
    vector<int> score;
    vector<INFO_PLAYER> info_players;

    getNumberOfPlayers(n);
    getNumberOfTimesPlayed(s);

    cout << "\n-------- NHA CAI CO 3 SU LUA CHON CHO PHAN CHOI NAY --------" << endl;
    cout << "--- 1. Khong rut them bai." << endl;
    cout << "--- 2. Thay the ngau nhien cac la bai." << endl;
    cout << "--- 3. Duoc chon thay the cac la bai." << endl;
    
    getChoice(choice_of_dealer, 1, 3);
    if (choice_of_dealer == 3)
    {
        cout << "\n----- LUA CHON NAY CO 3 CAP DO -----" << endl;
        cout << "--- 1. Muc de." << endl;
        cout << "--- 2. Muc trung binh." << endl;
        cout << "--- 3. Muc kho." << endl;
        getChoice(choose_mode, 1, 3);
        cout << endl;
    }

    // Khởi tạo số lượng phần tử của mảng
    initArrayForNPlayers(info_players, score, ranking, ranking_s_times, hands, n);

    // Nhập tên của n người chơi.
    cin.ignore();
    getMultipleUserNames(info_players, n, is_dealer);

    system("cls");

    do
    {
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "--------------- CHAO MUNG BAN DEN VOI TRO CHOI FIVE-CARD POKER --------------" << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "-------- CHAO MUNG BAN DEN VOI CHE DO NHIEU NGUOI CHOI (CO NHA CAI) ---------" << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "-------------------------------- CHUC NANG ----------------------------------" << endl;
        cout << "--- 1. Xao bai." << endl;
        cout << "--- 2. Chia bai." << endl;
        cout << "--- 3. Xem ket qua (diem va thu hang, nha cai la nguoi choi thu 1)." << endl;
        cout << "--- 4. Thay doi so luong nguoi choi (bao gom nha cai)." << endl;
        cout << "--- 5. Thay doi so lan choi." << endl;
        cout << "--- 6. Thay doi cach choi cua nha cai (cach quyet dinh rut them bai hoac khong)." << endl;
        cout << "--- 7. Thoat che do nhieu nguoi choi." << endl;

        getChoice(choice, start, end);

        switch (choice)
        {
            case 1:
                shufflingCards(deck);
                createArraySaveCardInformationInOrder(deck, info_card);
                cout << "==> Da xao bai." << endl;
                break;
            case 2:
                dealingNHands(info_card, hands, n);

                hand_dealer = hands[0];
                getChoiceOfDealer(info_card, hand_dealer, n, choice_of_dealer, choose_mode); // Các lựa chọn rút thêm bài của nhà cái.
                hands[0] = hand_dealer;

                cout << "--- Lan chia bai thu 1:" << endl;
                printNHands(hands, is_dealer);

                if (s == 1)
                    rankingNHands(hands, ranking, score, n);
                else
                    evaluateNHandsWithDealer(deck, info_card, hands, ranking_s_times, score, choice_of_dealer, choose_mode, n, s);

                cout << "==> Da chia bai." << endl;
                break;
            case 3:
                if (s == 1)
                    showInfoMultiplePlayers(info_players, ranking, score, n, s, is_dealer);
                else
                    showInfoMultiplePlayers(info_players, ranking_s_times, score, n, s, is_dealer);

                break;
            case 4:
                getNumberOfPlayers(n);
                initArrayForNPlayers(info_players, score, ranking, ranking_s_times, hands, n);
                cout << "==> Vui long nhap lai ten cua " << n - 1 << " nguoi choi.\n" << endl;
                cin.ignore();
                getMultipleUserNames(info_players, n, is_dealer);
                break;
            case 5:
                getNumberOfTimesPlayed(s);
                break;
            case 6:
                cout << "\n-------- NHA CAI CO 3 SU LUA CHON CHO PHAN CHOI NAY --------" << endl;
                cout << "--- 1. Khong rut them bai." << endl;
                cout << "--- 2. Thay the ngau nhien cac la bai." << endl;
                cout << "--- 3. Duoc chon thay the cac la bai." << endl;
                
                getChoice(choice_of_dealer, 1, 3);
                if (choice_of_dealer == 3)
                {
                    cout << "\n----- LUA CHON NAY CO 3 CAP DO -----" << endl;
                    cout << "--- 1. Muc de." << endl;
                    cout << "--- 2. Muc trung binh." << endl;
                    cout << "--- 3. Muc kho." << endl;
                    getChoice(choose_mode, 1, 3);
                    cout << endl;
                }
                break;
            case 7:
                system("cls");
                break;
        }

        // Dừng màn hình console trước khi chuyển sang chức năng khác.
        if (choice != end)
            pauseScreen();

    } while (choice != end);
}

// Phần 4.

void evaluateDealerAndPLayer(vector<vector<int>> &deck, vector<INFO_HAND> &info_card, vector<vector<INFO_HAND>> &hands, vector<int> &ranking_s_times, vector<int> &score, const int &n, const int &s)
{
    bool is_dealer = true;
    vector<int> score_n_players_s_times(n, 0), score_n_players(n), counting_score;
    vector<INFO_HAND> hand_dealer(KCARDS), hand_player(KCARDS);

    for (int i = 0; i < s; i++)
    {
        // Tính điểm của n người chơi sau 1 lần chia bài.
        calculateScoreOfNPlayers(hands, score_n_players, n);

        // Cập nhật số điểm của n người chơi sau 1 lần chơi.
        for (int j = 0; j < n; j++)
            score_n_players_s_times[j] += score_n_players[j];

        if (i == s - 1)
            break;

        shufflingCards(deck); // Tráo bài lại.
        createArraySaveCardInformationInOrder(deck, info_card);
        dealingNHands(info_card, hands, n); // Chia bài cho n người chơi.

        hand_dealer = hands[0];
        hand_player = hands[1];
        matchBetweenPlayerAndDealer(info_card, hand_player, hand_dealer);
        hands[1] = hand_player;
        hands[0] = hand_dealer;

        cout << "--- Lan chia bai thu " << i + 2 << ":" << endl;
        printNHands(hands, is_dealer);
    }

    // Tính số lượng từng loại điểm và xếp hạng từng loại điểm đó.
    counting_score = countScoreAndRank(score_n_players_s_times);

    // Xếp thứ hạng từng người chơi.
    for (int i = 0; i < n; i++)
        ranking_s_times[i] = counting_score[score_n_players_s_times[i]];

    // Copy điểm sang mảng score để dùng cho hàm showInfoMultiplePlayers.
    score = score_n_players_s_times;
}

void matchBetweenPlayerAndDealer(const vector<INFO_HAND> &info_card, vector<INFO_HAND> &hand_player, vector<INFO_HAND> &hand_dealer)
{
    int choice(1), card_withdraw_pos, number_of_cards_player_draws;
    INFO_HAND card;

    // Nhập số lá bài mà người chơi muốn rút thêm.
    cout << "==> Ban duoc rut them 1-3 la bai." << endl;
    getChoice(number_of_cards_player_draws, 0, 3);

    card_withdraw_pos = 10;

    while (choice != 0)
    {
        if (number_of_cards_player_draws > 0)
        {
            card = info_card[card_withdraw_pos];
            changeCardToGetHighestScore1(hand_player, card);

            card_withdraw_pos++;
            number_of_cards_player_draws--;

            cout << "==> Nguoi choi da rut bai.\n" << endl;
            if (number_of_cards_player_draws == 0)
                cout << "==> Nguoi choi da het luot rut bai.\n" << endl;
        }

        cout << "==> Nha cai co muon rut bai them hay khong?" << endl;
        cout << "==> Vui long nhap vao 1 de rut bai hoac 0 de khong rut them bai." << endl;
        getChoice(choice, 0, 1);

        if (choice == 1)
        {
            card = info_card[card_withdraw_pos];
            changeCardToGetHighestScore1(hand_dealer, card);

            cout << "==> Nha cai da rut bai.\n" << endl;

            if (card_withdraw_pos == CARDS)
            {
                cout << "==> Da het bai." << endl;
                break;
            }

            card_withdraw_pos++;
        }
    }
}

void programForMatchBetweenPlayerAndDealer(vector<vector<int>> &deck, vector<INFO_HAND> &info_card, vector<int> &ranking, vector<int> &ranking_s_times, int &s)
{
    bool is_dealer(true), is_duel(true);
    int choice;
    const int start(1), end(6), n(2);
    vector<INFO_HAND> hand_player(KCARDS), hand_dealer(KCARDS);
    vector<vector<INFO_HAND>> hands(n, vector<INFO_HAND> (KCARDS));
    vector<int> score(n);
    vector<INFO_PLAYER> info_players(n);

    ranking.resize(n);
    ranking_s_times.resize(n);

    cin.ignore();
    getMultipleUserNames(info_players, n, is_dealer);
    getNumberOfTimesPlayed(s);

    system("cls");

    do
    {
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "--------------- CHAO MUNG BAN DEN VOI TRO CHOI FIVE-CARD POKER --------------" << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "---------- CHAO MUNG BAN DEN VOI CHE DO DAU DOI KHANG VOI NHA CAI -----------" << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "-------------------------------- CHUC NANG ----------------------------------" << endl;
        cout << "--- 1. Xao bai." << endl;
        cout << "--- 2. Chia bai." << endl;
        cout << "--- 3. Xem ket qua (diem va thu hang)." << endl;
        cout << "--- 4. Thay doi ten nguoi choi." << endl;
        cout << "--- 5. Thay doi so lan choi." << endl;
        cout << "--- 6. Thoat che do dau doi khang voi nha cai." << endl;

        getChoice(choice, start, end);

        switch (choice)
        {
        case 1:
            shufflingCards(deck);
            createArraySaveCardInformationInOrder(deck, info_card);
            cout << "==> Da xao bai." << endl;
            break;
        case 2:
            dealingNHands(info_card, hands, n);
            
            hand_dealer = hands[0]; // Nhà cái là người chơi thứ 1.
            hand_player = hands[1]; // Người đấu đối kháng với nhà cái là người chơi thứ 2.
            matchBetweenPlayerAndDealer(info_card, hand_player, hand_dealer); // Quá trình rút thêm bài của người chơi và nhà cái.
            hands[0] = hand_dealer;
            hands[1] = hand_player;

            cout << "--- Lan chia bai thu 1:" << endl;
            printNHands(hands, is_dealer);

            if (s == 1)
                rankingNHands(hands, ranking, score, n);
            else
                evaluateDealerAndPLayer(deck, info_card, hands, ranking_s_times, score, n, s);

            cout << "==> Da chia bai." << endl;
            break;
        case 3:
            if (s == 1)
                showInfoMultiplePlayers(info_players, ranking, score, n, s, is_dealer);
            else
                showInfoMultiplePlayers(info_players, ranking_s_times, score, n, s, is_dealer);

            break;
        case 4:
            cin.ignore();
            getMultipleUserNames(info_players, n, is_dealer);
            break;
        case 5:
            getNumberOfTimesPlayed(s);
            break;
        case 6:
            system("cls");
            break;
        }

        // Dừng màn hình console trước khi chuyển sang chức năng khác.
        if (choice != end)
            pauseScreen();

    } while (choice != end);
}

// Phần 5.

void easyMode(const vector<INFO_HAND> &info_card, vector<INFO_HAND> &hand_dealer, const int &n, const int &number_of_cards)
{
    if (number_of_cards == 0)
        return; // Dealer không quyết định rút thêm lá bài mới.

    INFO_HAND card;

    for (int i = 0; i < number_of_cards; i++)
    {
        card = info_card[(n * KCARDS) + i]; // Lấy giá trị lá bài sẽ thay thế.
        changeCardToGetHighestScore1(hand_dealer, card);
    }
}

void mediumMode(const vector<INFO_HAND> &info_card, vector<INFO_HAND> &hand_dealer, const int &n, const int &number_of_cards)
{
    if (number_of_cards == 0)
        return; // Dealer không quyết định rút thêm lá bài mới.

    int number_of_cards_ramaining = CARDS - (n * KCARDS), count = 0;
    INFO_HAND card;

    for (int i = 0; i < number_of_cards_ramaining; i++)
    {
        card = info_card[(n * KCARDS) + i]; // Lấy giá trị lá bài sẽ thay thế.
        changeCardToGetHighestScore2(hand_dealer, card, count);
        
        // Khi đã thay đủ số lá bài thì sẽ dừng
        if (count == number_of_cards)
            break;
    }
}

void difficultMode(const vector<INFO_HAND> &info_card, vector<INFO_HAND> &hand_dealer, const int &n, const int &number_of_cards)
{
    if (number_of_cards == 0)
        return; // Dealer không quyết định rút thêm lá bài mới.

    int number_of_cards_ramaining = CARDS - (n * KCARDS), count = 0;
    INFO_HAND card;

    for (int i = 0; i < number_of_cards_ramaining; i++)
    {
        card = info_card[(n * KCARDS) + i]; // Lấy giá trị lá bài sẽ thay thế.
        changeCardToGetHighestScore2(hand_dealer, card, count, greaterThan);
        
        // Khi đã thay đủ số lá bài thì sẽ dừng
        if (count == number_of_cards)
            break;
    }
}

void chooseGameMode(const vector<INFO_HAND> &info_card, vector<INFO_HAND> &hand_dealer, const int &n, const int &number_of_cards, const int &choose_mode)
{
    switch (choose_mode)
    {
        case 1:
            easyMode(info_card, hand_dealer, n, number_of_cards);
            break;
        case 2:
            mediumMode(info_card, hand_dealer, n, number_of_cards);
            break;
        case 3:
            difficultMode(info_card, hand_dealer, n, number_of_cards);
            break;
        default:
            break;
    }
}