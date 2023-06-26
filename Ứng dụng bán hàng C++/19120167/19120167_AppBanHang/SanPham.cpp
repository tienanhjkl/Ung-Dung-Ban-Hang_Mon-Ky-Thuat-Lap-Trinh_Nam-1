#include "Header.h"

//HAM NHAP THONG TIN SAN PHAM
bool product_Input(product& sp) {
	fstream file;
	file.open("Thongtinsanpham.txt", ios::out | ios::app);
	if (file.is_open()) {
		file << sp.ID << endl;

		file << sp.Type << endl;

		file << sp.Name << endl;

		file << sp.Price << endl;
		file.close();
		return true;
	}
	else
		return false;
}

//HAM LOAD THONG TIN SAN PHAM
void load_Product(product& sp, ifstream& file) {

	file >> sp.ID;
	file >> sp.Type;
	file >> sp.Name;
	file >> sp.Price;
	_flushall();
}

//LOAD DS SAN PHAM
void load_ListProduct(product sp[], int& product_Count) {
	ifstream file;

	file.open("Thongtinsanpham.txt");
	int n = 0;
	while (!file.eof()) {
		load_Product(sp[n], file);
		n++;
	}

	file.close();
	product_Count = n - 2;
}

	//HAM KIEM TRA MA SAN PHAM
bool checkID_Product(product sp[], string& ID_Product, int product_Count) {
	if (product_Count == 0)
		return false;
	else {
		int j = 0;
		while (sp[j].ID != ID_Product && j < product_Count) {
			j++;
		}
		if ((sp[j].ID != ID_Product) && (j == product_Count))
			return false;
		else
			return true;
	}
}

//HAM KIEM TRA DO DAI MA SAN PHAM
bool checkLength(string& ID) {
	int count = 0;
	char* c = new char[ID.size() + 1];
	//Chuyen string input --> char*
	c = convert_Stringtochar(ID);

	while (c[count] != '\0')
		count++;
	if (count > 10)
		return false;
	else
		return true;
}

//HAM NHAP DANH SACH SAN PHAM	--- MOI LAN THEM DUOC 1 SAN PHAM
void add_ToListProduct(product sp[], int& product_Count) {
	product_Count++;
	string ID, Name, Type;
	int Price;
	cout << "\n- Nhap ma san pham: ";
	cin >> ID;

	//Kiem tra do dai ID
	while (!checkLength(ID)) {
		cout << "\n - Can nhap ID duoi 10 ky tu: ";
		cin >> ID;
	}
	cin.ignore();

	//Kiem tra ID co ton tai
	while (checkID_Product(sp, ID, product_Count)) {
		cout << "\n - Ma san pham " << ID << " da ton tai!";
		cout << "\n -- Nhap lai: ";
		cin >> ID;
	}
	sp[product_Count].ID = ID;

	cout << "\n- Nhap loai san pham: ";
	cin >> Type;
	cin.ignore();
	cout << "\n- Nhap ten san pham (Khong nhap khoang cach): ";
	cin >> Name;
	cin.ignore();
	cout << "\n- Nhap gia san pham: ";
	cin >> Price;
	cin.ignore();

	sp[product_Count].ID = ID;
	sp[product_Count].Type = Type;
	sp[product_Count].Name = Name;
	sp[product_Count].Price = Price;
	_flushall();
		//GHI SAN PHAM VUA THEM VAO FILE 	
	if (product_Input(sp[product_Count])) {
		//XUAT LAI THONG TIN SAN PHAM VUA LUU
		cout << "\n -- Da them thanh cong thong tin san pham\n";
		cout << "\n * Ma san pham: " << sp[product_Count].ID;
		cout << "\n * Loai: " << sp[product_Count].Type;
		cout << "\n * Ten san pham: " << sp[product_Count].Name;
		cout << "\n * Gia san pham: " << sp[product_Count].Price << " (VND)" << endl;
	}
	else {
		cout << "\n - Luu san pham that bai! ";
	}
}

//HAM XOA NHAN VIEN KHOI DANH SACH
void delete_Product(product sp[], string deleted_ID, int& product_Count) {
	int j = 0;
	int pos = 0;
	while (sp[pos].ID != deleted_ID) {
		pos++;
	}
	for (pos; pos <= product_Count - 1; pos++) {
		sp[pos] = sp[pos + 1];
	}
	product_Count--;
		// CAP NHAT LAI DU LIEU
	fstream file;
	file.open("Thongtinsanpham.txt", ios::out);
	for (int j = 0; j <= product_Count; j++) {
		file << sp[j].ID << endl;

		file << sp[j].Type << endl;

		file << sp[j].Name << endl;

		file << sp[j].Price << endl;
	}
	file.close();
}

//HAM SUA THONG TIN SAN PHAM
void edit_ProductDetail(product sp[], string product_ID, int product_Count) {
	int pos = 0;

	while (sp[pos].ID != product_ID) {
		pos++;
	}
		//XUAT THONG TIN SAN PHAM TRUOC KHI CHINH SUA
	cout << "\n - Ma san pham: " << sp[pos].ID;
	cout << "\n - Loai san pham: " << sp[pos].Type;
	cout << "\n - Ten san pham: " << sp[pos].Name;
	cout << "\n - Gia san pham: " << sp[pos].Price << " (VND)" << endl;
			//NHAP LAI TOAN BO THONG TIN SAN PHAM CAN CHINH SUA
	string ID, Name, Type;
	int Price;
	cout << "\n============= Nhap lai thong tin san pham ================";
	cout << "\n- Nhap ma san pham: ";
	cin >> ID;
	cin.ignore();
		sp[pos].ID = ID;

	cout << "\n- Nhap loai san pham: ";
	cin >> Type;
	cin.ignore();
	cout << "\n- Nhap ten san pham (Khong nhap khoang cach): ";
	cin >> Name;
	cin.ignore();
	cout << "\n- Nhap gia san pham: ";
	cin >> Price;
	cin.ignore();

	sp[pos].Type = Type;
	sp[pos].Name = Name;
	sp[pos].Price = Price;
	_flushall();
	product_Input(sp[pos]);

	cout << "\n - Da chinh sua thanh cong thong tin san pham\n";
	cout << "\n * Ma san pham: " << sp[pos].ID;
	cout << "\n * Loai: " << sp[pos].Type;
	cout << "\n * Ten san pham: " << sp[pos].Name;
	cout << "\n * Gia san pham: " << sp[pos].Price << " (VND)" << endl;

	// CAP NHAT LAI DU LIEU
	fstream file;
	file.open("Thongtinsanpham.txt", ios::out);
	for (int j = 0; j <= product_Count; j++) {
		file << sp[j].ID << endl;

		file << sp[j].Type << endl;

		file << sp[j].Name << endl;

		file << sp[j].Price << endl;
	}
	file.close();
}

//XUAT THONG TIN SAN PHAM
void out_Product(product sp) {
	cout << "\n - Product's ID: " << sp.ID;
	cout << "\n - Product's Type: " << sp.Type;
	cout << "\n - Product's Name: " << sp.Name;
	cout << "\n - Price: " << sp.Price << " (VND)";
}

//XUAT DANH SACH SAN PHAM
void out_ListofProduct(product sp[], int product_Count) {
	for (int i = 0; i <= product_Count; i++) {
		cout << "\n\t -- SAN PHAM " << i + 1 << " --" << endl << endl;
		out_Product(sp[i]);
	}
	cout << endl;
}