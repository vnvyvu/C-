/*Bài 5*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class sach
{
	friend class dmsach;
	private:
		char ma[20];
		char tensach[255];
	public:
		void nhapbp();
		void xemmh();
};
void sach::nhapbp()
{
	cout<<"Nhap ma sach:";cin>>ma;
	cout<<"Nhap ten sach:";cin.ignore();cin.getline(tensach,255);cin.ignore();
}
void sach::xemmh()
{
	cout<<"Ma sach:"<<ma<<endl;
	cout<<"Ten sach:"<<tensach<<endl;
}
/*------------------------------------------------------------*/
class dmsach
{
	private:
		sach dms[1000];
		int tssach;
	public:
		void nhapbp();
		void xemmh();
		void ghitep();
		dmsach();
		dmsach(const char file_name[]);
		sach xemten(char name[]);
};
dmsach::dmsach()
{
}
void dmsach::nhapbp()
{
	cout<<"Nhap so luong sach:";cin>>tssach;
	for(int i=1;i<=tssach;i++)
	{
		cout<<"Cuon sach thu "<<i<<endl;dms[i].nhapbp();
	}
}
void dmsach::xemmh()
{
	for(int i=1;i<=tssach;i++)
	{
		cout<<i<<".\n";dms[i].xemmh();cout<<endl;
	}
}
void dmsach::ghitep()
{
	fstream f("5.dat",ios::out|ios::binary);
	f.write(reinterpret_cast <char*> (this),sizeof(dmsach));
	f.close();
}
dmsach::dmsach(const char file_name[])
{
	fstream f(file_name,ios::in|ios::binary);
	f.read(reinterpret_cast <char*> (this),sizeof(dmsach));
	f.close();
}
sach dmsach::xemten(char name[])
{
	for(int i=1;i<=tssach;i++)
	{
		char *token;
		token=strstr(dms[i].ma,name);
		if(token!=NULL) return dms[i];
	}
}
main()
{
}
