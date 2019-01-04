#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class dmsach;
class phieutra;
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
	cout<<"Ma sach: ";fflush(stdin);cin.getline(masach,10);
	cout<<"Ten sach: ";cin.getline(tensach,60);
}
void sach::xem()
{
	cout<<masach<<" "<<tensach;
}
/*----------------------------------------*/
class dmsach
{
	private:
		sach dms[100];
		unsigned tssach;
	public:
		void nhap();
		void xem();
		sach xemten(char c[]);
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
/*----------------------------------------*/
class sachtra:public sach
{
	friend class phieutra;
	private:
		unsigned soluong;
	public:
		void nhap();
		void xem();
};
void sachtra::nhap()
{
	cout<<"So luong sach tra: ";cin>>soluong;
}
void sachtra::xem()
{
	cout<<soluong;
}
/*----------------------------------------*/
class phieutra
{
	private:
		unsigned sophieu,tongsoluong,tssachtra;
		sachtra dmsachtra[100];
	public:
		void nhap();
		void xem();
		void ghitep();
};
void phieutra::nhap()
{
	cout<<"So phieu: ";cin>>sophieu;
	cout<<"Tong so loai sach tra: ";cin>>tssachtra;
	tongsoluong=0;
	for(int i=1;i<=tssachtra;i++)
	{
		dmsachtra[i].sach::nhap();
		dmsachtra[i].sachtra::nhap();
		tongsoluong+=dmsachtra[i].soluong;
	}
}
void phieutra::xem()
{
	cout<<"So phieu: "<<sophieu<<endl;
	cout<<"Tong so loai sach tra: "<<tssachtra<<" sach"<<endl;
	for(int i=1;i<=tssachtra;i++)
	{
		dmsachtra[i].sach::xem();
		cout<<" ";
		dmsachtra[i].sachtra::xem();
		cout<<endl;
	}
	cout<<"Tong so luong sach: "<<tongsoluong<<" quyen";
}
void phieutra::ghitep()
{
	fstream f("6.dat",ios::out|ios::binary|ios::app);
	f.write(reinterpret_cast <char *> (this),sizeof(phieutra));
	f.close();
}
void doctep(phieutra x[],unsigned &tsphieutra)
{
	fstream f("6.dat",ios::in|ios::binary);
	while(f)
	{
		tsphieutra++;
		f.read(reinterpret_cast <char *> (&x[tsphieutra]),sizeof(tsphieutra));
	}
	tsphieutra-=1;
	f.close();
}
/*----------------------------------------*/
main()
{
	
}
