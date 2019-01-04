#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class lop;
class sinhvien
{
	friend class lop;
	private:
		char maso[20];
		char hoten[60];
	public:
		void nhapbp();
		void xemmh();
};
void sinhvien::nhapbp()
{
	fflush(stdin);
	cout<<"Nhap ma sinh vien: ";cin.getline(maso,20);
	cout<<"Nhap ho ten sinh vien: ";cin.getline(hoten,60);
}
void sinhvien::xemmh()
{
	cout<<maso<<" "<<hoten;
}
class lop
{
	private:
		sinhvien dssinhvien[100];
		long tssinhvien;
	public:
		void nhapbp();
		void xemmh();
		void ghitep();
		lop(const char c[]);
		lop sapxeptang();
};
void lop::nhapbp()
{
	cout<<"Nhap tong so sinh vien: ";cin>>tssinhvien;
	for(int i=1;i<=tssinhvien;i++)
	{
		dssinhvien[i].nhapbp();
	}
}
void lop::xemmh()
{
	for(int i=1;i<=tssinhvien;i++)
	{
		dssinhvien[i].nhapbp();
		cout<<endl;
	}
}
void lop::ghitep()
{
	fstream f("3.dat",ios::out|ios::binary);
	f.write(reinterpret_cast <char*> (this),sizeof(lop));
	f.close();
}
lop::lop(const char c[])
{
	fstream f(c,ios::in|ios::binary);
	f.read(reinterpret_cast <char*> (this),sizeof(lop));
	f.close();	
}
lop lop::sapxeptang()
{
	/*Sap xep noi bot*/
	lop result=*this;
	for(int i=1;i<=result.tssinhvien;i++)
	{
		for(int j=result.tssinhvien;j>=i+1;j--)
		{
			if(result.dssinhvien[j-1].maso>result.dssinhvien[j].maso)
			{
				sinhvien a=result.dssinhvien[j-1];
				result.dssinhvien[j-1]=result.dssinhvien[j];
				result.dssinhvien[j]=a;
			}
		}
	}
	return result;
}
main()
{
}
