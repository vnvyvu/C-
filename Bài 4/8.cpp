/*Bai 8*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class hang
{
	friend class banggia;
	protected:
		char tenhang[40];
		int gia;
	public:
		void nhap();
		void xem();
};
void hang::nhap()
{
	fflush(stdin);
	cout<<"Ten hang: ";cin.getline(tenhang,40);
	cout<<"Gia: ";cin>>gia;
}
void hang::xem()
{
	cout<<tenhang<<" ("<<gia<<" VND/1)";
}
/*-----------------------------------------------*/
class banggia
{
	private:
		hang dshang[100];
		int tshang;
	public:
		void nhap();
		void xem();
		hang xemten(char c[]);
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
hang banggia::xemten(char c[])
{
	for(int i=1;i<=tshang;i++)
	{
		bool check=true;
		for(int j=0;j<=strlen(c);j++)
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
/*-----------------------------------------------*/
class hangxuat:public hang
{
	friend class phieuxuat;
	private:
		int soluongxuat,thanhtien;
	public:
		void nhap();
		void xem();
};
void hangxuat::nhap()
{
	cout<<"So luong xuat: ";cin>>soluongxuat;
	thanhtien=soluongxuat*gia;
}
void hangxuat::xem()
{
	cout<<"x"<<soluongxuat<<"= "<<thanhtien<<" VND";
}
/*-----------------------------------------------*/
class phieuxuat
{
	private:
		int sophieu,tongtien,tshangxuat;
		hangxuat dshx[100];
	public:
		void nhap();
		void xem();
		void ghitep();
};
void phieuxuat::nhap()
{
	cout<<"So phieu: ";cin>>sophieu;
	cout<<"Tong so hang xuat: ";cin>>tshangxuat;
	tongtien=0;
	for(int i=1;i<=tshangxuat;i++)
	{
		dshx[i].hang::nhap();
		dshx[i].hangxuat::nhap();
		tongtien+=dshx[i].thanhtien;
	}
}
void phieuxuat::xem()
{
	cout<<"So phieu"<<sophieu;
	for(int i=1;i<=tshangxuat;i++)
	{
		dshx[i].hang::xem();
		dshx[i].hangxuat::xem();
	}
	cout<<"Tong tien: "<<tongtien<<" VND";
}
void phieuxuat::ghitep()
{
	fstream f("8.dat",ios::out|ios::binary|ios::app);
	f.write(reinterpret_cast <char*> (this),sizeof(phieuxuat));
	f.close();
}
/*-----------------------------------------------*/
void doctep(phieuxuat x[],int &tsphieu)
{
	fstream f("8.dat",ios::in|ios::binary);
	tsphieu=0;
	while(f)
	{
		tsphieu+=1;
		f.read(reinterpret_cast <char*> (&x[tsphieu]),sizeof(phieuxuat));
	}
	tsphieu-=1;
	f.close();
}
main()
{
}
