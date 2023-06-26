#ifndef _HEADER_H
#define _HEADER_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
using namespace std;


struct product {
	string ID;
	string Name;
	string Type;
	int Price;
};

struct staff {
	string ID;
	string Fullname;
	string Username;
	string Password;
};

struct DonHang {
	string Ngay;
	string Thang;
	string Nam;
	string date = Ngay + Thang + Nam;
	int Count;
	long int TongTien;
	product product;

};
	// CAC HAM VE DANG NHAP

bool checkAcc(string username);
bool checkPass(string input_pass);
bool signUp(staff& p, string& new_user, string& input_pass);
bool signIn(string username, string password);
char* convert_Stringtochar(string Pass);
char* getHidePass();

	// CAC HAM VE NHAN VIEN

void loadListStaff(staff p[], int& i);
bool checkID_Staff(staff p[], string& ID, int i);
void edit_StaffInfo(staff p[], string StaffID, int i);
void delete_Staff(staff p[], string deleted_ID, int& i);
void add_ToListStaff(staff p[], int& i);
void staffInput(staff& p);
void outListStaff(staff p[], int i);
	
	//CAC HAM VE SAN PHAM

bool product_Input(product& sp);
void load_Product(product& sp, ifstream& file);
void load_ListProduct(product sp[], int& product_Count);
bool checkID_Product(product sp[], string& ID_Product, int product_Count);
bool checkLength(string& ID);
void add_ToListProduct(product sp[], int& product_Count);
void delete_Product(product sp[], string deleted_ID, int& product_Count);
void edit_ProductDetail(product sp[], string product_ID, int product_Count);
void out_Product(product sp);
void out_ListofProduct(product sp[], int product_Count);

	//CAC HAM VE DON HANG

void createAnOrder(char* fileName, DonHang& A);
bool addProduct(product sp[], DonHang A[], string Name, int& add, int product_Count);
void outputOrder(DonHang order[], int add);
bool checkName(product sp[], DonHang order[], int product_Count, string Name, int add);
void loadOrderedPurchase(DonHang& order, ifstream& file);
void load_ListOrder(DonHang order[], int& Sum, string date);
void thongKe(DonHang order[], product sp[], int product_Count, int Sum);
#endif // !1




