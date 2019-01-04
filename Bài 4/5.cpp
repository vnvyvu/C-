#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class dmsach;
class sach
{
	friend class dmsach;
	protected:
		char masach[10],tensach[60];
	public:
		void nhap();
		void xem();
};
void sach::nhap()
{
	fflush(stdin);
	cout<<"Ma sach: ";cin.getline(masach,10);
	cout<<"Ten sach: ";cin.getline(tensach,60);
}
void sach::xem()
{
	cout<<masach<<" "<<tensach;
}
/*-------------------------------------*/
class dmsach
{
	protected:
		sach dms[100];
		unsigned tssach;
	public:
		void nhap();
		void xem();
		void xemten(char c[]);
};
void dmsach::nhap()
{
	cout<<"Tong so sach: ";cin>>tssach;
	for(int i=1;i<=tssach;i++)
	{
		dms[i].nhap();
	}
}
void dmsach::xem()
{
	for(int i=1;i<=tssach;i++)
	{
		dms[i].xem();
		cout<<endl;
	}
}
sach dmsach::xemten(char c[])
{
	for(int i=1;i<=tssach;i++)
	{
		bool check=true;
		for(int j=0;j<strlen(c);j++)
		{
			if(c[j]!=dms[i].masach[j])
			{
				check=false;
				break;
			}
		}
		if(check) return dms[i];
	}
}
/*-------------------------------------*/
class sachmuon:public sach
{
	friend class phieumuon;
	private:
		unsigned soluong;
	public:
		void nhap();
		void xem();
};
void sachmuon::nhap()
{
	cout<<"So luong sach muon: ";cin>>soluong;
}
void sachmuon::xem()
{
	cout<<soluong;
}
/*-------------------------------------*/
class phieumuon
{
	private:
		unsigned sophieu,tongsoluong,tssachmuon;
		sachmuon dssachmuon[100];
	public:
		void nhap();
		void xem();
		void ghitep();
};
void phieumuon::nhap()
{
	cout<<"So phieu: ";cin>>sophieu;
	cout<<"Tong so sach muon: ";cin>>tssachmuon;
	tongsoluong=0;
	for(int i=1;i<=tssachmuon;i++)
	{
		dssachmuon[i].sach::nhap();
		dssachmuon[i].sachmuon::nhap();
		tongsoluong+=dssachmuon[i].soluong;
	}
}
void phieumuon::xem()
{
	cout<<"So phieu: "<<sophieu<<endl;
	cout<<"Tong so sach muon: "<<tssachmuon<<" sach"<<endl;
	for(int i=1;i<=tssachmuon;i++)
	{
		dssachmuon[i].sach::xem();
		cout<<endl;
		dssachmuon[i].sachmuon::xem();
		cout<<endl;
	}
	cout<<"Tong so luong sach muon: "<<tongsoluong<<" quyen";
}
void phieumuon::ghitep()
{
	fstream f("5.dat",ios::out|ios::binary|ios::app);
	f.write(reinterpret_cast <char*> (this),sizeof(phieumuon));
	f.close();
}
void doctep(phieumuon x[],unsigned &tsphieu)
{
	fstream f("5.dat",ios::in|ios::binary);
	while(f)
	{
		tsphieu++;
		f.read(reinterpret_cast <char*> (&x[tsphieu]),sizeof(phieumuon));
	}
	f.close();	
}
main()
{
//	sach a;
//	a.nhap();
//	a.xem();
//	dmsach b;
//	b.nhap();
//	b.xem();
//	sach timsach=b.xemten("c");
//	timsach.xem();
//	sachmuon c;
//	c.sach::nhap();
//	c.sachmuon::nhap();
//	c.sach::xem();
//	c.sachmuon::xem();
	phieumuon d[10];
	unsigned tsphieu=0;
	doctep(d,tsphieu);
//	d.nhap();
	for(int i=1;i<=tsphieu;i++) d[i].xem();
//	d.ghitep();
}
