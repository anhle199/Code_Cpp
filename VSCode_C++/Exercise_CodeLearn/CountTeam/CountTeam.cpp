std::string countTeam(std::string s)
{
    int len = s.length();
    
    if (len <= 3) {
        int x = 1, dec = 0;
        for (int i = 0; i < len; i++) {
            dec += (s[i] - '0') * x;
            x *= 2;
        }

        if (dec < 3) return "even";
    }

    if (s[len - 1] == s[len - 2] && s[len - 1] == '1')
        return "odd";
    return "even";
}



/*
 - 3C3 là 1 số lẻ, cứ 1 số lẻ sẽ có 3 số chẵn rồi đến 1 số lẻ
 - Biểu diễn ra dạng nhị phân sẽ thấy nến 2 số cuối đều là 1 thì chắc chắn XC3 sẽ là số lẻ.
*/