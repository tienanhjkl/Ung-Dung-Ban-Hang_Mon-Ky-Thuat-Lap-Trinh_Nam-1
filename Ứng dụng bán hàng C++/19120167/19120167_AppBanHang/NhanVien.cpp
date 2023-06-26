#include "Header.h"

//HAM NHAP THONG TIN NHAN VIEN
void staffInput(staff& p) {
	fstream file;
	file.open("Thongtinnhanvien.txt", ios::out | ios::app);

	file << p.ID << endl;

	file << p.Fullname << endl;

	file << p.Username << endl;

	file << p.Password << endl;
	file.close();
}

//HAM LOAD THONG TIN NHAN VIEN
void loadStaff(staff& p, ifstream& file) {

	file >> p.ID;
	file >> p.Fullname;
	file >> p.Username;
	file >> p.Password;
	_flushall();
}

//LOAD DS NHAN VIEN
void loadListStaff(staff p[], int& i) {
	ifstream file;

	file.open("Thongtinnhanvien.txt");
	int n = 0;
	while (!file.eof()) {
		loadStaff(p[n], file);
		n++;
	}

	file.close();
	i = n - 2;
}

//HAM KIEM TRA MA NHAN VIEN
bool checkID_Staff(staff p[], string& ID, int i) {
	if (i == 0)
		return false;
	else {
		int j = 0;
		while (p[j].ID != ID && j < i) {
			j++;
		}
		if ((p[j].ID != ID) && (j == i))
			return false;
		else
			return true;
	}
}

//HAM NHAP DANH SACH NHAN VIEN	--- MOI LAN THEM DUOC 1 NHAN VIEN
void add_ToListStaff(staff p[], int& i) {
	i++;
	// char Fullname[255];
	string ID, Fullname, Username, Pass;
	cout << "\n- Nhap ma NV: ";

	cin >> ID;
	cin.ignore();
	//Kiem tra do dai ID
	while (!checkLength(ID)) {
		cout << "\n - Can nhap ID duoi 10 ky tu: ";
		cin >> ID;
	}

		//Kiem tra ID co ton tai
	while (checkID_Staff(p, ID, i)) {
		cout << "\n - Ma nhan vien " << ID << " da ton tai!";
		cout << "\n -- Nhap lai: ";
		cin >> ID;
	}
	p[i].ID = ID;
	cout << "\n- Nhap ho ten (Khong nhap khoang cach): ";
	cin >> Fullname;
	cin.ignore();
	cout << "\n- Nhap ten dang nhap: ";
	cin >> Username;
	cin.ignore();
	cout << "\n- Nhap mat khau: ";
	Pass = getHidePass();
	cout << "\n- Nhap lai mat khau: ";
	string rePass;
	rePass = getHidePass();
	while (Pass != rePass) {
		cout << "\n- Mat khau khong khop! \n";
		cout << " - Xin moi nhap lai: ";
		rePass = getHidePass();
	}
	if (signUp(p[i], Username, Pass)) {

		p[i].Fullname = Fullname;
		p[i].Username = Username;
		p[i].Password = Pass;
		_flushall();
		staffInput(p[i]);
			//XUAT LAI THONG TIN NHAN VIEN VUA LUU
		cout << "\n - Da them thanh cong thong tin nhan vien\n";
		cout << "\n * Nhan vien: " << p[i].ID;
		cout << "\n * Username: " << p[i].Username << endl;
	}
}

//HAM XOA NHAN VIEN KHOI DANH SACH
void delete_Staff(staff p[], string deleted_ID, int& i) {

	int pos = 0;
	while (p[pos].ID != deleted_ID) {
		pos++;
	}
	for (pos; pos <= i; pos++) {
		p[pos] = p[pos + 1];
	}
	i--;

	cout << i << endl;
	system("pause");
	fstream file;
	file.open("Thongtinnhanvien.txt", ios::out);
	for (int j = 0; j <= i; j++) {
		file << p[j].ID << endl;
		file << p[j].Fullname << endl;
		file << p[j].Username << endl;
		file << p[j].Password << endl;
	}
	file.close();
	file.open("Account.txt", ios::out);
	for (int j = 0; j <= i; j++) {
		file << p[j].Username << endl;
	}
	file.close();
	file.open("Password.txt", ios::out);
	for (int j = 0; j <= i; j++) {
		file << p[j].Password << endl;
	}
	file.close();
	cout << "\n - Da cap nhat lai du lieu" << endl;
}

//HAM SUA THONG TIN NHAN VIEN
void edit_StaffInfo(staff p[], string StaffID, int i) {
	int pos = 0;

	while (p[pos].ID != StaffID) {
		pos++;
	}
		//XUAT LAI THONG TIN NHAN VIEN TRUOC KHI CHINH SUA
	cout << "\n - Ma nhan vien: " << p[pos].ID;
	cout << "\n - Ho ten: " << p[pos].Fullname;
	cout << "\n - Ten dang nhap: " << p[pos].Username;
	cout << "\n - Mat khau: " << p[pos].Password << endl;
			//NHAP LAI TOAN BO THONG TIN NHAN VIEN CAN CHINH SUA
	cout << "\n-========= Chinh sua lai thong tin nhan vien=======\n";
	string ID, Fullname, Username, Pass;
	cout << "\n- Nhap ma NV: ";
	cin >> ID;
	cin.ignore();
	cout << "\n- Nhap ho ten (Khong nhap khoang cach): ";
	cin >> Fullname;
	cout << "\n- Nhap ten dang nhap: ";
	cin >> Username;
	cin.ignore();
	cout << "\n- Nhap mat khau: ";
	Pass = getHidePass();

	while (!checkPass(Pass)) {
		cout << "\n - Mat khau phai dai hon 8 ky tu, vui long nhap lai !\n";
		cin >> Pass;
		cin.ignore();
	}
	

	p[pos].ID = ID;
	p[pos].Fullname = Fullname;
	p[pos].Username = Username;
	p[pos].Password = Pass;

	cout << "\n - Da cap nhat thanh cong thong tin nhan vien\n";
	cout << "\n * Nhan vien: " << p[pos].ID;
	cout << "\n * Username: " << p[pos].Username << endl;	

	fstream file;
	file.open("Thongtinnhanvien.txt", ios::out);
	for (int j = 0; j <= i; j++) {
		file << p[j].ID << endl;
		file << p[j].Fullname << endl;
		file << p[j].Username << endl;
		file << p[j].Password << endl;
	}
	file.close();
	file.open("Account.txt", ios::out);
	for (int j = 0; j <= i; j++) {
		file << p[j].Username << endl;
	}
	file.close();
	file.open("Password.txt", ios::out);
	for (int j = 0; j <= i; j++) {
		file << p[j].Password << endl;
	}
	file.close();
}

//Xuat thong tin nhan vien
void outStaff(staff p) {
	cout << "\n - Staff's ID: " << p.ID;
	cout << "\n - Staff's FullName: " << p.Fullname;
	cout << "\n - Staff's Username: " << p.Username;
	cout << "\n - Staff's Password: " << p.Password << endl;
}
//XUAT DS NHAN VIEN
void outListStaff(staff p[], int i) {
	for (int j = 0; j <= i; j++) {
		cout << "\n --- Nhan vien " << j + 1;
		outStaff(p[j]);
	}
	cout << endl;
}

