#include "Header.h"

	//HAM TAO DON HANG
void createAnOrder(char* fileName, DonHang& order) {
	fstream file;
	file.open(fileName, ios::out | ios::app);
	
	file << order.product.Name << endl;
	file << order.Count << endl;


	file.close();
}

	//HAM LOAD DON HANG SAU MOI LAN THEM DON HANG
void loadOrderedPurchase(DonHang& order, ifstream& file) {

	file >> order.product.Name;
	file >> order.Count;
}
void load_ListOrder(DonHang order[], int& Sum, string date) {
	char fileName[] = "        .txt";
	for (int i = 7; i >= 0; i--) {
		fileName[i] = date[i];
	}
	ifstream file(fileName);

	int n = 0;
	while (!file.eof()) {
		loadOrderedPurchase(order[n], file);
		n++;
	}
	file.close();
	Sum = n - 2;
}

//KIEM TRA SAN PHAM CO TON TAI
bool checkName(product sp[], DonHang order[], int product_Count, string Name, int add) {
	int j = 0;
	while (sp[j].Name != Name && j < product_Count) {
		j++;
	}
	if ((sp[j].Name != Name) && (j == product_Count)) {
		return false;
	}
	else {
		order[add].product = sp[j];
		return true;
	}
}

//THEM SAN PHAM
bool addProduct(product sp[], DonHang order[], string Name, int& add, int product_Count) {
	add++;
	if (!checkName(sp,order,product_Count,Name,add)) {
		add--;
		return false;
	}
	else { 
		cout << "\n - So luong: ";
		cin >> order[add].Count;
		cin.ignore();
		return true;
	}
}

//XUAT THONG TIN DON HANG
void outputOrder(DonHang order[], int add) {
	
	cout << "=================== Purchase Order ====================\n";
	cout << "\t\t - Delivery time: " << order[0].Ngay << "-" << order[0].Thang << "-" << order[0].Nam;
	for (int i = 0; i <= add; i++) {
		cout << "\n - " << order[i].product.Name << endl ;
		cout<<"\t - So luong: " << order[i].Count;
	}
	cout << "\n\t\t ** Tong tien: " << order[add].TongTien << " (VND)" << endl;
}

//HAM THONG KE SO LUONG DON HANG VA DOANH THU TRONG NGAY
void thongKe(DonHang order[],product sp[], int product_Count, int Sum) {
	int Pay = 0;
	cout << "\n=========== TONG KET " << order[0].Ngay << "-" << order[0].Thang << "-" << order[0].Nam << " =============\n";
	for (int i = 0; i <= Sum; i++) {
		cout << "\n - " << order[i].product.Name << endl;
		cout << "\t - So luong: " << order[i].Count;
		int j = 0;
		while (order[i].product.Name != sp[j].Name) {
			j++;
		}
		order[i].product.Price = sp[j].Price;
		Pay += (order[i].Count * order[i].product.Price);
	}
	
	cout << "\n\t\t ** Tong tien: " << Pay << " (VND)" << endl;
}