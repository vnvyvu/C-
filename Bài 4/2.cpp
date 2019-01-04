#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class banggia;
class hoadon;
class hang
{
	friend class banggia;
	protected:
		char tenhang[60];
		int gia;
	public:
		void nhap();
		void xem();
};
void hang::nhap()
{
	fflush(stdin);
	cout<<"Ten hang: ";cin.getline(tenhang,60);
	cout<<"Don gia(VND/1): ";cin>>gia;
}
void hang::xem()
{
	cout<<tenhang<<"["<<gia<<"(VND)]";
}
/*-----------------------------------------------*/
class banggia
{
	private:
		hang dshang[100];
		unsigned tshang;
	public:
		void nhap();
		void xem();
		hang xemgia(char c[]);
};
void banggia::nhap()
{
	cout<<"Tong so hang: ";cin>>tshang;
	for(int i=1;i<=tshang;i++)
	{
		dshang[i].nhap();
	}
}
void banggia::xem()
{
	for(int i=1;i<=tshang;i++)
	{
		dshang[i].xem();
		cout<<endl;
	}
}
hang banggia::xemgia(char c[])
{
	for(int i=1;i<=tshang;i++)//duyet toan bo danh ds
	{
		char *token;
		token=strstr(dshang[i].tenhang,c);
		if(token!=NULL) return dshang[i];
	}
}
/*-----------------------------------------------*/
class hangban:public hang
{
	friend class hoadon;
	private:
		unsigned soluong,thanhtien;
	public:
		void nhap();
		void xem();
};
void hangban::nhap()
{
	cout<<"->"<<"So luong: ";cin>>soluong;
	thanhtien=soluong*gia;
}
void hangban::xem()
{
	cout<<"x"<<soluong<<"="<<thanhtien<<"(VND)";
}
/*-----------------------------------------------*/
class hoadon
{
	private:
		unsigned sohoadon,tshangban,tongtien;
		hangban dshangban[100];
	public:
		void nhap();
		void xem();
		void ghitep();
};
void hoadon::nhap()
{
	cout<<"So hoa don: ";cin>>sohoadon;
	cout<<"Tong so loai mat hang: ";cin>>tshangban;
	for(int i=1;i<=tshangban;i++)
	{
		dshangban[i].hang::nhap();
		dshangban[i].hangban::nhap();
		tongtien+=dshangban[i].thanhtien;
	}
}
void hoadon::xem()
{
	cout<<"-------------------------------"<<endl;
	cout<<"So hoa don: "<<sohoadon<<endl;
	cout<<"Tong so loai mat hang: "<<tshangban<<endl;
	cout<<"--------------------------------"<<endl;
	cout<<"Ten_Mat_Hang[Don_Gia(VND)]xSo_Luong=Thanh_Tien(VND)"<<endl<<endl;
	for(int i=1;i<=tshangban;i++)
	{
		dshangban[i].hang::xem();
		dshangban[i].hangban::xem();
		cout<<endl;
	}
	cout<<"--------------------------------"<<endl;
	cout<<"Tong tien: "<<tongtien<<"(VND)";
}
void hoadon::ghitep()
{
	fstream f("2.dat",ios::out|ios::binary|ios::app);
	f.write(reinterpret_cast <char*> (this),sizeof(hoadon));
	f.close();
}
void doctep(hoadon x[],unsigned &tshoadon)
{
	fstream f("2.dat",ios::in|ios::binary);
	while(f)
	{
		tshoadon++;
		f.read(reinterpret_cast <char*> (&x[tshoadon]),sizeof(hoadon));
	}
	tshoadon-=1;
	f.close();
}
/*-----------------------------------------------*/
main()
{
//	hang a;
//	a.nhap();
//	a.xem();

//	banggia b;
//	b.nhap();
//	b.xem();

//	char c[60];
//	cout<<"Nhap ten mat hang muon mua: ";
//	fflush(stdin);cin.getline(c,60);
//	cout<<b.xemgia(c);

//	hangban d;
//	d.nhap();
//	d.xem();

	hoadon e;
	e.nhap();
	e.xem();
	e.ghitep();
//	e.xem();
}
