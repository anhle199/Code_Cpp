#ifndef FAKE_NAME_H_
#define FAKE_NAME_H_

#include <vector>
#include "Random.h"
#include "Fullname.h"


class FakeName {
	vector<string> _listFirstNames = { "Nguyen", "Tran", "Le", "Pham", "Huynh", "Phan",
		"Vo", "Dang", "Bui", "Do", "Ho", "Ngo", "Duong", "Ly" };

	vector<string> _listMiddleNames = { "Dinh", "Van", "Ngoc", "Phu", "Hung", "Quang", "Thi",
		"Thanh", "An", "Huu", "Vu", "Dinh", "Xuan", "Ba", "Cao" ,"Hoang", "Dan", "Minh", "Hua",
		"Quoc", "Nhat", "Tuong", "Ngoc" };

	vector<string> _listLastNames = { "Ai", "An","Anh", "Bach", "Bang", "Bong", "Canh", "Cao",
		"Chi", "Chinh", "Cuc", "Danh", "Dao", "Dan", "Doan" ,"Em" ,"Duc" ,"Giang",
		"Huy", "Ha", "Hanh", "Hao", "Hieu", "Hung", "Huong", "Kha", "Khoi", "Khang",
		"Nga", "Nhan", "Nhu", "Thuan", "Thi", "Phuc", "Phuoc", "Loc", "Phuong" };

	Random _rng;

public:
	Fullname next();
};

#endif