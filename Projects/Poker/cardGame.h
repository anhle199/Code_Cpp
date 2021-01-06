// cardGame.h
#ifndef CARD_GAME_H_
#define CARD_GAME_H_

#include <iostream>
#include <vector>

// - Tính đúng kích thước của kiểu struct.
#pragma pack(1)

#define SUITS 4
#define FACES 13
#define CARDS 52
#define KCARDS 5
#define MAX_PLAYERS 9 // Số lượng người chơi tối đa.
#define CONDITION 9 // Biến dùng để tiếp tục chương trình (ngắt hàm dừng màn hình (hàm pauseScreen)).

using namespace std;

struct INFO_HAND
{
    int face, value;

    /* 
    - So sánh 2 lá bài. 
    - VD: có biểu thức card1 < card2.
    - Trả về true nếu card2 lớn hơn.
    - Ngược lại trả về false.
    */
    bool operator<(const INFO_HAND &card);
};

struct INFO_PLAYER
{
    string user_name;
    int rank, score;

    INFO_PLAYER();
};

const vector<string> suits = { "Hearts", "Diamonds", "Clubs", "Spades" };
const vector<string> face_value = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

//------------------------------------------------
// - Các chức năng liên quan đến trò chơi.

// - Dừng màn hình console trước khi chuyển sang chức năng khác.
void pauseScreen();
// - Nhập lựa chọn.
void getChoice(int &choice, const int &start, const int &end);
// - Hàm chọn các cách rút thêm bài của dealer hoặc là không rút thêm.
void getChoiceOfDealer(const vector<INFO_HAND> &info_card, vector<INFO_HAND> &hand_dealer, const int &n, const int &choice, const int &choose_mode);
// - Nhập số lượng người chơi.
void getNumberOfPlayers(int &n);
// - Nhập số lần chơi.
void getNumberOfTimesPlayed(int &s);
// - Nhập tên 1 người chơi.
void getUserName(string &user_name);
// - Nhập tên nhiều người chơi.
void getMultipleUserNames(vector<INFO_PLAYER> &info_players, const int &n, bool is_dealer = false);
// - In trạng thái của 5 lá bài.
void showStatusOfHand(const int &score);
// - In tên và điểm của 1 người chơi.
void showInfoPlayer(const INFO_PLAYER &info_player);
// - Hàm in tên, điểm và thứ hạng của n người chơi sau s lần chơi.
void showInfoMultiplePlayers(vector<INFO_PLAYER> &info_players, const vector<int> &ranking, const vector<int> &score, const int &n, const int &s, bool is_dealer = false);

//------------------------------------------------
// I. Cơ bản: Card shuffling & Dealing.

// - Hàm tráo bài
void shufflingCards(vector<vector<int>> &deck);
// - Hàm in ra giá trị và tính chất từng lá bài
void dealingCards(const vector<INFO_HAND> &info_card);
// - Tạo mảng chứa giá trị và chất của lá bài theo thứ tự lá bài từ 1-52.
void createArraySaveCardInformationInOrder(const vector<vector<int>> &deck, vector<INFO_HAND> &info_card);

//------------------------------------------------
// II. Bài tập: Five-card poker(Card game).

// Phần 1.

// - Hàm chia bài cho 1 người chơi.
// - Mảng hand có 5 lá bài.
void dealingHand(const vector<INFO_HAND> &info_card, vector<INFO_HAND> &hand);
// - Hàm in các lá bài của 1 người chơi.
void printHand(const vector<INFO_HAND> &hand);
// - Hàm kiểm tra bài của người chơi có chứa 4 lá cùng giá trị hay không.
bool isFourOfAKind(const vector<INFO_HAND> &hand);
// - Hàm kiểm tra bài của người chơi có chứa 3 lá cùng giá trị + 1 cặp hay không.
bool isFullHouse(const vector<INFO_HAND> &hand);
// - Hàm kiểm tra bài của người chơi có chứa 5 lá cùng chất hay không.
bool isFlush(const vector<INFO_HAND> &hand);
// - Hàm kiểm tra bài của người chơi có chứa 5 lá có giá trị liên tiếp hay không.
bool isStraight(const vector<INFO_HAND> &hand);
// - Hàm kiểm tra bài của người chơi có chứa 5 lá có giá trị liên tiếp + cùng chất hay không.
bool isStraightFlush(const vector<INFO_HAND> &hand);
// - Hàm kiểm tra bài của người chơi có chứa 3 lá cùng giá trị hay không.
bool isThreeOfAKind(const vector<INFO_HAND> &hand);
// - Hàm kiểm tra bài của người chơi có chứa 2 cặp hay không.
bool isTwoPairs(const vector<INFO_HAND> &hand);
// - Hàm kiểm tra bài của người chơi có chứa 1 cặp hay không.
bool isPair(const vector<INFO_HAND> &hand);
// - Hàm trả về lá bài cao nhất.
INFO_HAND getHighestCard(const vector<INFO_HAND> &hand);
// - Hàm trả về trạng lá của 5 lá bài (8 nếu chứa straight flush và 0 nếu không chứa cặp đặc biệt nào).
int getStatusOfHand(const vector<INFO_HAND> &hand);
// - Chương trình cho 1 người chơi.
void programForOnePlayer(vector<vector<int>> &deck, vector<INFO_HAND> &info_card);

// Phần 2.

// Khởi tạo số lượng phần tử của các mảng dùng cho n người chơi.
void initArrayForNPlayers(vector<INFO_PLAYER> &info_player, vector<int> &score, vector<int> &ranking, vector<int> &ranking_s_times, vector<vector<INFO_HAND>> &hands, const int &n);
// - Hàm tính điểm của n người chơi.
void calculateScoreOfNPlayers(const vector<vector<INFO_HAND>> &hands, vector<int> &score_n_players, const int &n);
// - Hàm đếm số lượng từng loại điểm của n người chơi và xếp hạng từng loại điểm đó.
vector<int> countScoreAndRank(const vector<int> &score_n_players);
// - Hàm chia bài cho n người chơi.
void dealingNHands(const vector<INFO_HAND> &info_card, vector<vector<INFO_HAND>> &hands, const int &n);
// - Hàm in bài n người chơi.
void printNHands(const vector<vector<INFO_HAND>> &hands, bool is_dealer = false);
// - Hàm xếp hạng n người chơi sau 1 lần chia bài.
void rankingNHands(const vector<vector<INFO_HAND>> &hands, vector<int> &ranking, vector<int> &score, const int &n);
// - Hàm xếp hạng n người chơi sau s lần chia bài (người thắng cuộc có điểm cao nhất, người đứng chót mặc định không có điểm).
void evaluateNHands(vector<vector<int>> &deck, vector<INFO_HAND> &info_card, vector<vector<INFO_HAND>> &hands, vector<int> &ranking_s_times, vector<int> &score, const int &n, const int &s);
// - Chương trình cho nhiêu người chơi (không có nhà cái).
void programForMultiplayerWithoutDealer(vector<vector<int>> &deck, vector<INFO_HAND> &info_card, vector<int> &ranking, vector<int> &ranking_s_times, int &n, int &s);

// Phần 3.
// - Việc chọn thay thế 1, hoặc 2, hoặc 3 lá mới là do nhà cái (dealer) quyết định.

// - Trả về true nếu a > b, ngược lại trả về false.
bool greaterThan(const int &a, const int &b);
// - Trả về true nếu a >= b, ngược lại trả về false.
bool greaterThanOrEqualTo(const int &a, const int &b);
// - Hàm này sẽ thực hiện việc tìm vị trí và thay thế 1 trong 5 lá bài sao cho đạt điểm cao nhất.
// - Phiên bản này dùng cho theSecondAlgorithm, matchBetweenPlayerAndDealer và easyMode , mặc định 1 kiểu thay thế bài. 
void changeCardToGetHighestScore1(vector<INFO_HAND> &hand, const INFO_HAND &card);
// - Phiên bản này dùng cho mediumMode và difficultMode, có thêm biến đếm số lượng lá bài đã thay thế, biến bool để quyết định việc thay thế bài. 
void changeCardToGetHighestScore2(vector<INFO_HAND> &hand, const INFO_HAND &card, int &count, bool (*compare)(const int&, const int&) = greaterThanOrEqualTo);
// - Giống chức năng của hàm evaluateNHands nhưng dùng cho các phần chơi có nhà cái.
void evaluateNHandsWithDealer(vector<vector<int>> &deck, vector<INFO_HAND> &info_card, vector<vector<INFO_HAND>> &hands, vector<int> &ranking_s_times, vector<int> &score, const int &choice_of_dealer, const int &choose_mode, const int &n, const int &s);
// - Thuật toán (1), chọn vị trí thay thế ngẫu nhiên.
void theFirstAlgorithm(const vector<INFO_HAND> &info_card, vector<INFO_HAND> &hand_dealer, const int &number_of_cards, const int &n);
// - Chương trình chơi cho nhà cái.
void programForMultiplayerAndDealer(vector<vector<int>> &deck, vector<INFO_HAND> &info_card, vector<int> &ranking, vector<int> &ranking_s_times, int &n, int &s);

// Phần 4.
// - Hàm xếp hạng phần chơi đối kháng giữa người chơi và nhà cái sau s lần.
void evaluateDealerAndPLayer(vector<vector<int>> &deck, vector<INFO_HAND> &info_card, vector<vector<INFO_HAND>> &hands, vector<int> &ranking_s_times, vector<int> &score, const int &n, const int &s);
// - Hàm thực hiện việc đấu đối kháng giữa người chơi và dealer (rút bài của người chơi, quyết định rút hay dừng rút bài của dealer).
void matchBetweenPlayerAndDealer(const vector<INFO_HAND> &info_card, vector<INFO_HAND> &hand_player, vector<INFO_HAND> &hand_dealer);
// - Chương trình đấu đối kháng giữa người chơi và dealer.
void programForMatchBetweenPlayerAndDealer(vector<vector<int>> &deck, vector<INFO_HAND> &info_card, vector<int> &ranking, vector<int> &ranking_s_times, int &s);

// Phần 5.

// - Hàm này giống hoàn toàn với thuật toán (2).
// - Chọn 2 lá liên tiếp (2 lá đầu) trong 7 lá còn lại.
// - Sẽ thay thế lá bài nếu điểm sau khi rút >= điểm trước khi rút.
void easyMode(const vector<INFO_HAND> &info_card, vector<INFO_HAND> &hand_dealer, const int &n, const int &number_of_cards);
/*
 - Rút từng lá trong 7 lá còn lại theo thứ tự.
 - Nếu đã rút lá thứ i thì chỉ được rút những lá ở phía sau từ vị trí (i + 1) chứ không được rút những lá phía trước lá đã rút.
 - Rút những lá sao cho điểm sau khi rút >= điểm trước khi rút.
*/
void mediumMode(const vector<INFO_HAND> &info_card, vector<INFO_HAND> &hand_dealer, const int &n, const int &number_of_cards);
/*
 - Được rút các lá không cần theo thứ tự.
 - Nếu đã rút lá thứ i thì vẫn được rút những lá ở phía trước i từ vị trí (i - 1) về vị trí 0.
 - Rút những lá sao cho điểm sau khi rút > điểm trước khi rút.
 - Nếu không có lá nào thỏa mãn thì sẽ không rút. 
*/
void difficultMode(const vector<INFO_HAND> &info_card, vector<INFO_HAND> &hand_dealer, const int &n, const int &number_of_cards);
// - Hàm chọn chế độ chơi.
void chooseGameMode(const vector<INFO_HAND> &info_card, vector<INFO_HAND> &hand_dealer, const int &n, const int &number_of_cards, const int &choose_mode);

//------------------------------------------------

#endif // Kết thúc tập tin cardGame.h.