#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class banggia;
class phieunhap;
class hang
{
	friend class banggia;
	friend class phieunhap;
	protected:
		char tenhang[60];
		unsigned gia;
	public:
		void nhap();
		void xem();
};
void hang::nhap()
{
	cout<<"Ten hang: ";fflush(stdin);cin.getline(tenhang,60);
	cout<<"Gia: ";cin>>gia;
}
void hang::xem()
{
	cout<<tenhang<<" "<<gia;
}
/*-------------------------------------*/
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
	for(int i=1;i<=tshang;i++)
	{
		bool check=true;
		for(int j=0;j<strlen(c);j++)
		{
			if(c[j]!=dshang[i].tenhang[j])
			{
				check=false;
				break;
			}
		}
		if(check) return dshang[i];
	}
}
/*-------------------------------------*/
class hangnhap:public hang
{
	friend class phieunhap;
	private:
		unsigned soluongnhap,thanhtien;
	public:
		void nhap();
		void xem();
};
void hangnhap::nhap()
{
	cout<<"So luong hang nhap: ";cin>>soluongnhap;
	thanhtien=soluongnhap*gia;
}
void hangnhap::xem()
{
	cout<<soluongnhap<<"="<<thanhtien<<" VND";
}
/*-------------------------------------*/
class phieunhap
{
	private:
		unsigned sophieu,tongtien,tshangnhap;
		hangnhap dshangnhap[100];
	public:
		void nhap();
		void xem();
		void ghitep();
};
void phieunhap::nhap()
{
	cout<<"So phieu: ";cin>>sophieu;
	cout<<"Tong so hang nhap: ";cin>>tshangnhap;
	tongtien=0;
	for(int i=1;i<=tshangnhap;i++)
	{
		dshangnhap[i].hang::nhap();
		dshangnhap[i].hangnhap::nhap();
		tongtien+=dshangnhap[i].thanhtien;
	}
}
void phieunhap::xem()
{
	cout<<"So phieu: "<<sophieu<<endl;
	cout<<"Tong so hang nhap: "<<tshangnhap<<endl;
	for(int i=1;i<=tshangnhap;i++)
	{
		dshangnhap[i].hang::xem();
		cout<<endl;
		dshangnhap[i].hangnhap::xem();
		cout<<endl;
	}
	cout<<"Tong tien: "<<tongtien;
}
void phieunhap::ghitep()
{
	fstream f("7.dat",ios::out|ios::binary|ios::app);
	f.write(reinterpret_cast <char*> (this),sizeof(phieunhap));
	f.close();
}
void doctep(phieunhap x[],unsigned &tsphieunhap)
{
	fstream f("7.dat",ios::in|ios::binary);
	while(f)
	{
		tsphieunhap++;
		f.read(reinterpret_cast <char*> (&x[tsphieunhap]),sizeof(phieunhap));
	}
	tsphieunhap-=1;
	f.close();
}
/*-------------------------------------*/
main()
{
	
}
