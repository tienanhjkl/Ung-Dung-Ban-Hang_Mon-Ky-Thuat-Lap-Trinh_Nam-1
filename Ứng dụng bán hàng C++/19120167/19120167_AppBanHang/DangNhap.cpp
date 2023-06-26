#include "Header.h"

//HAM KIEM TRA TAI KHOAN
bool checkAcc(string Username) {
	fstream file;
	char temp[255];
	string line;

	file.open("Account.txt", ios::in);
	do {
		file.getline(temp, 255);
		line = temp;
	} while (!file.eof() & Username != line);

	if (line == Username && !file.eof()) {
		return false;
	}
	if (line != Username && file.eof()) {
		return true;
	}
	file.close();
}
//HAM CHUYEN STRING SANG CHAR*
char* convert_Stringtochar(string Pass) {
	char* c = new char[Pass.size() + 1];
	for (int i = 0; i < Pass.size(); i++)
	{
		c[i] = Pass[i];
	}
	c[Pass.size()] = '\0';
	return c;
}
//HAM KIEM TRA MAT KHAU 
bool checkPass(string input_Pass) {
	int count = 0;
	char* c = new char[input_Pass.size() + 1];
	//Chuyen string input --> char*
	c = convert_Stringtochar(input_Pass);

	while (c[count] != '\0')
		count++;
	if (count < 8)
		return false;
	else
		return true;
}
//HAM TAO TAI KHOAN
bool signUp(staff& p, string& new_user, string& input_pass) {
	fstream fileAcc, filePass;
	//Ghi ten dang nhap vao file
	fileAcc.open("Account.txt", ios::out | ios::app);

	while (checkAcc(new_user) == false) {
		cout << "\n- Ten dang nhap ton tai, vui long nhap ten khac!";
		cin >> new_user;
	}
	fileAcc << new_user << endl;

	p.Username = new_user;

	fileAcc.close();

	//Ghi mat khau vao file
	filePass.open("Password.txt", ios::out | ios::app);

	while (!checkPass(input_pass)) {		// MAT KHAU PHAI DAI HON 8 KY TU
		cout << "\n- Mat khau khong hop le !\n";
		cin >> input_pass;
	}
	filePass << input_pass << endl;
	p.Password = input_pass;
	filePass.close();
	return true;
}

// HAM DANG NHAP
bool signIn(string username, string password) {
	

	fstream fileAcc, filePass;
	char tempAcc[255], tempPass[255];
	string lineAcc, linePass;
	bool checkAcc, checkPass;
	fileAcc.open("Account.txt", ios::in);
	filePass.open("Password.txt", ios::in);

	if (fileAcc.is_open() && filePass.is_open()) {
		do {
			fileAcc.getline(tempAcc, 255);
			lineAcc = tempAcc;
			filePass.getline(tempPass, 255);
			linePass = tempPass;
			checkAcc = (!fileAcc.eof() & lineAcc != username);
			checkPass = (!filePass.eof() & linePass != password);
		} while (checkAcc && checkPass);
		if ((!fileAcc.eof() & !filePass.eof()) && ((lineAcc == username) & (linePass == password)))
			return true;
		else
			return false;
	}
}

//HAM LAM AN PASSWORD
char* getHidePass() {
	char tmp[100];
	int i = 0;
	char a = ' ';
	for (i = 0;;) {
		a = _getch();
		if (a == '\b' && i >= 1) {
			cout << "\b \b";
			--i;
		}
		else if (a == '\r') {
			tmp[i] = '\0';
			i++;
			break;
		}
		else if (a != '\b') {
			tmp[i] = a;
			i++;
			cout << "*";
		}
	}
	char* res = new char[i];
	strcpy(res, tmp);
	return res;
}