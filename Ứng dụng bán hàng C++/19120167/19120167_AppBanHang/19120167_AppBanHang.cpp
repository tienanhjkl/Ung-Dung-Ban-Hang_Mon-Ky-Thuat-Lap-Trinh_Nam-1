#include "Header.h"

int main() {

	staff* list_Staff = new staff[100];
	product* list_Product = new product[100];
	DonHang* Order = new DonHang[100];
	int choice;
	int staff_Count = -1;
	int product_Count = -1;

	//Load du lieu
	cout << " -- Loading data...\n";
		//Load thong tin nhan vien
	loadListStaff(list_Staff, staff_Count);
		//Load thong tin san pham
	load_ListProduct(list_Product, product_Count);

	Sleep(1000);
	string date, ngay, thang, nam;
	cout << " - Nhap ngay (VD: Ngay 1 --> 01): ";
	cin >> ngay;
	cin.ignore();
	cout << "\n - Nhap thang (VD: Thang 1 --> 01): ";
	cin >> thang;
	cout << "\n - Nhap nam: ";
	cin >> nam;
	cin.ignore();
	date = ngay + thang + nam;

	Order[0].Ngay = ngay;
	Order[0].Thang = thang;
	Order[0].Nam = nam;
	Sleep(500);
	system("cls");

		//===== MAIN MENU
	do {
		system("cls");
		cout << "==============\n";
		cout << " 1. Dang nhap.";
		cout << "\n 0. Dang xuat.";
		
		cout << "\n -- Nhap lua chon: ";
		while (!(cin >> choice) || choice < 0 || choice>1) {
			cin.clear();
			cin.ignore(20, '\n');
			cout << "\n - Nhap sai lua chon, vui long nhap lai: ";
		}
		switch (choice)
		{
		case 0: exit(0);
		case 1: {
			system("cls");
			string username, pass;
				//MENU DANG NHAP
			cout << "===== DANG NHAP =====\n";
			cout << "- Ten dang nhap: ";
			cin >> username;
			cout << "\n- Mat khau: ";
			pass = getHidePass();
			if (signIn(username, pass)) {
				cout << "\n -- Dang nhap thanh cong." << endl;
				int Choice;
				Sleep(750);
				system("cls");
				do {
						//MENU CAC CHUC NANG
					cout << "====================== 19120167's STORE ======================\n";
					cout << "1. Them/xoa/sua danh sach nhan vien.";
					cout << "\n2. Them/xoa,sua danh sach san pham.";
					cout << "\n3. Tao don hang.";
					cout << "\n4. Thong ke doanh thu (theo ngay va lua chon khi ket thuc ngay).";
					cout << "\n0.Thoat.";
					cout << "\n -- Nhap lua chon: ";
					while (!(cin >> Choice) || Choice < 0 || Choice>4) {
						cin.clear();
						cin.ignore(20, '\n');
						cout << "\n --Lua chon sai, vui long nhap lai: ";
					}

					switch (Choice)
					{
					case 0: break;

					case 1: {
						system("cls");
						int Choice;
						do {
							cout << "=======================================\n";
							cout << "1. Them nhan vien.";
							cout << "\n2. Xoa nhan vien.";
							cout << "\n3. Chinh sua thong tin nhan vien.";
							cout << "\n4. Xuat danh sach nhan vien.";
							cout << "\n0. Thoat.";
							cout << "\n -- Nhap lua chon: ";
							while (!(cin >> Choice) || Choice < 0 || Choice>4) {
								cin.clear();
								cin.ignore(20, '\n');
								cout << "\n - Lua chon sai, vui long nhap lai: ";
							}
							switch (Choice) {
							case 0:break;

							case 1: {
								system("cls");
								add_ToListStaff(list_Staff, staff_Count);
								system("pause");
								system("cls");
								break;
							}
							case 2: {
								system("cls");
								if (staff_Count == -1) {
									cout << " - Cannot delete.\n";
									system("pause");
									system("cls");
									break;
								}
								else {
									string ID_deleted;
									cout << " - Nhap ID nhan vien can xoa: ";
									cin >> ID_deleted;
									cin.ignore();
										//Kiem tra do dai ID
									while (!checkLength(ID_deleted)) {
										cout << "\n - Can nhap ID duoi 10 ky tu: ";
										cin >> ID_deleted;
									}
										//Kiem tra ID co ton tai
									while (!checkID_Staff(list_Staff, ID_deleted, staff_Count)) {
										cout << "\n - Ma nhan vien " << ID_deleted << " khong ton tai!";
										cout << "\n -- Nhap lai: ";
										cin >> ID_deleted;
									}
									delete_Staff(list_Staff, ID_deleted, staff_Count);
									cout << "\n -- Da xoa nhan vien " << ID_deleted << endl;
									system("pause");
									system("cls");
									break;
								}
							}
							case 3: {
								system("cls");
								if (staff_Count == -1) {
									cout << "\n -- Cannot edit.\n";
									system("pause");
									system("cls");
									break;
								}
								else {
									string ID_edited;
									cout << "\n - Nhap ID nhan vien can chinh sua: ";
									cin >> ID_edited;
									cin.ignore();
										//Kiem tra do dai ID
									while (!checkLength(ID_edited)) {
										cout << "\n - Can nhap ID duoi 10 ky tu: ";
										cin >> ID_edited;
									}
									//Kiem tra ID co ton tai
									while (!checkID_Staff(list_Staff, ID_edited, staff_Count)) {
										cout << "\n - Ma nhan vien " << ID_edited << " khong ton tai!";
										cout << "\n -- Nhap lai: ";
										cin >> ID_edited;
									}
									edit_StaffInfo(list_Staff, ID_edited, staff_Count);
									system("pause");
									system("cls");
									break;
								}
							}
							case 4: {
								system("cls");
								if (staff_Count == -1) {
									cout << " - Empty.\n";
									system("pause");
									system("cls");
									break;
								}
								else {
									outListStaff(list_Staff, staff_Count);
									system("pause");
									system("cls");
									break;
								}
							}
							}
						} while (Choice);
						system("cls");
						break;
					}
					case 2: {
						system("cls");
						int Choice;
						do {
							cout << "==================================\n";
							cout << "1. Them san pham.";
							cout << "\n2. Xoa san pham.";
							cout << "\n3. Chinh sua thong tin san pham.";
							cout << "\n4. Xuat danh sach san pham.";
							cout << "\n0. Thoat.";
							cout << " \n-- Nhap lua chon: ";
							while (!(cin >> Choice) || Choice < 0 || Choice>4) {
								cin.clear();
								cin.ignore(20, '\n');
								cout << "\n - Lua chon sai, vui long nhap lai: ";
							}
							switch (Choice) {
							case 0:break;

							case 1: {
								system("cls");
								add_ToListProduct(list_Product, product_Count);
								system("pause");
								system("cls");
								break;
							}
							case 2: {
								system("cls");
								if (product_Count == -1) {
									cout << " - Cannot delete.\n";
									system("pause");
									system("cls");
									break;
								}
								else {
									string ID_deleted;
									cout << " - Nhap ID san pham can xoa: ";
									cin >> ID_deleted;
									cin.ignore();
										//Kiem tra do dai ID
									while (!checkLength(ID_deleted)) {
										cout << "\n - Can nhap ID duoi 10 ky tu: ";
										cin >> ID_deleted;
									}
										
										//Kiem tra ID co ton tai
									int j = 0;
									while (list_Product[j].ID != ID_deleted && j < product_Count) {
										j++;
									}
									if (list_Product[j].ID != ID_deleted && j == product_Count) {
										cout << "\n Ma san pham " << ID_deleted << " khong ton tai.\n";
										system("pause");
										system("cls");
										break;
									}
									else {
										delete_Product(list_Product, ID_deleted, product_Count);
										cout << "\n -- Da xoa.\n";
										system("pause");
										system("cls");
										break;
									}
								}
							}
							case 3: {
								system("cls");
								if (product_Count == -1) {
									cout << "\n -- Cannot edit.\n";
									system("pause");
									system("cls");
									break;
								}
								else {
									string ID_edited;
									cout << "\n - Nhap ID san pham can chinh sua: ";
									cin >> ID_edited;
									cin.ignore();
										//Kiem tra do dai ID
									while (!checkLength(ID_edited)) {
										cout << "\n - Can nhap ID duoi 10 ky tu: ";
										cin >> ID_edited;
									}
										//Kiem tra ID co ton tai
									while(!checkID_Product(list_Product, ID_edited, product_Count)){
										cout << "\n - Ma san pham " << ID_edited << " khong ton tai!";
										cout << "\n -- Nhap lai: ";
										cin >> ID_edited;
									}
									edit_ProductDetail(list_Product, ID_edited, product_Count);
										system("pause");
										system("cls");
										break;
								}
							}
							case 4: {
								system("cls");
								if (product_Count == -1) {
									cout << " - Empty.\n";
									system("pause");
									system("cls");
									break;
								}
								else {
									out_ListofProduct(list_Product, product_Count);
									system("pause");
									system("cls");
									break;
								}
							}
							}
						} while (Choice); 
						system("cls");
						break;
					}
					case 3: {
						system("cls");
						string filename, ID, Name;
						int add = -1;
						int c;
						int sum = 0;
						do{ 
							cout << "\n 1. Them san pham.";
							cout << "\n 2. Xuat don hang.";
							cout << "\n 0. Thoat.";
							cout << "\n - Nhap lua chon: ";
							while (!(cin >> c) || c < 0 || c>2) {
								cin.clear();
								cin.ignore(20,'\n');
								cout << "\n - Nhap lai lua chon: ";
							}
							switch (c) {
							case 0:break;
							case 1: {
								system("cls");
								cout << "-- Nhap ten san pham: ";
								cin >> Name;
								cin.ignore();
								if (!addProduct(list_Product, Order, Name, add, product_Count)) {
									cout << "\n -- San pham " << " : " << Name << " khong ton tai!\n";
									system("pause");
									system("cls");
									break;
								}
								else {
									char fileName[] = "        .txt";
									for (int i = 7; i >= 0; i--) {
										fileName[i] = date[i];
									}
									sum += (Order[add].Count * Order[add].product.Price);
									Order[add].TongTien = sum;
									createAnOrder(fileName, Order[add]);

									cout << "\n -- Da them san pham: " << Name << endl;
									system("pause");
									system("cls");
									break;
								}
							}
							case 2: {
								system("cls");
								if (add == -1) {
									cout << " -- Chua co don hang nao!\n";
								}
								else {
									outputOrder(Order, add);
								}
								system("pause");
								system("cls");
								break;
							}
							}
						}while (c);
						system("cls");
						break;
					}
					case 4: {
						system("cls");
						int Sum;
						load_ListOrder(Order, Sum, date);
						if (Sum == -1)
							cout << " -- Khong co don hang nao! \n";
						else
							thongKe(Order, list_Product, product_Count, Sum);
						
						system("pause");
						system("cls");
						break;
					}
				}
				} while (Choice);
			}
			else {
				cout << "\n -- Sai ten dang nhap hoac mat khau !\n";
				system("pause");
				system("cls");
				break;
			}
		}
		}
		cout << endl;
	} while (choice);
	
	delete[] list_Staff;
	delete[] list_Product;
	delete[] Order;
	return 1;
}