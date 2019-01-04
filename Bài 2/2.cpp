/*Bai 2*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class banggia;
class tenhang
{
	friend class banggia;
	private:
		char tenhang[100];
		long gia;
	public:
		void nhapbp();
		void xemmh();
};
void tenhang::nhapbp()
{
	fflush(stdin);
	cout<<"Nhap ten hang: ";cin.getline(tenhang,100);
	cout<<"Nhap gia: ";cin>>gia;
}
void tenhang::xemmh()
{
	cout<<tenhang<<" "<<gia;
}
/*----------------------------------*/
class banggia
{
	private:
		tenhang dshang[100];
		unsigned tshang;
	public:
		void nhapbp();
		void xemmh();
		void ghitep();
		banggia(const char file_name[]);
		tenhang xemgia(char name[]);
};
void banggia::nhapbp()
{
	cout<<"Nhap tong so hang: ";cin>>tshang;
	for(int i=1;i<=tshang;i++)
	{
		dshang[i].nhapbp();
	}
}
void banggia::xemmh()
{
	for(int i=1;i<=tshang;i++)
	{
		dshang[i].xemmh();
		cout<<endl;
	}
}
void banggia::ghitep()
{
	fstream f("2.dat",ios::out|ios::binary);
	f.write(reinterpret_cast <char*> (this),sizeof(banggia));
	f.close();
}
banggia::banggia(const char file_name[])
{
	fstream f(file_name,ios::in|ios::binary);
	f.read(reinterpret_cast <char*> (this),sizeof(banggia));
	f.close();	
}
tenhang banggia::xemgia(char name[])
{
	/*Y tuong: duyet toan bo bang gia --> su dung token=strstr(<ten hang i>,<ten hang ma nguoi dung dua vao>), neu token!=null
	thi <ten hang ma nguoi dung dua vao> se ton tai trong <ten hang i>*/
	for(int i=1;i<=tshang;i++)
	{
		char *token;
		token=strstr(dshang[i].tenhang,name);
		if(token!=NULL)
		{
			return dshang[i];
		}
	}
}
main()
{
	/*Test tuong tu nhu bai 1*/
}
