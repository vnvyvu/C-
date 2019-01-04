#include<iostream>
#include<fstream>
using namespace std;
class danhsach;
class canbo
{
	friend class danhsach;
	private:
		char hoten[60];
		long luongcoban;
	public:
		void nhapbp();
		void xemmh();
};
void canbo::nhapbp()
{
	fflush(stdin);
	cout<<"Ho va Ten: ";cin.getline(hoten,60);
	cout<<"Luong co ban: ";cin>>luongcoban;
}
void canbo::xemmh()
{
	cout<<"Ho va Ten: "<<hoten<<":";cout<<"Luong co ban: "<<luongcoban;
}
/*---------------------------------------------------*/
class danhsach
{
	private:
		canbo dscanbo[100];
		long tscanbo;
	public:
		danhsach();
		void nhapbp();
		void xemmh();
		void ghitep();
		danhsach sapxep();
		danhsach(const char file_name[]);
};
danhsach::danhsach()
{
	
}
void danhsach::nhapbp()
{
	cout<<"Tong so can bo: ";cin>>tscanbo;
	for(int i=0;i<tscanbo;i++)
	{
		cout<<i+1<<"."<<endl;
		dscanbo[i].nhapbp();
	}
}
void danhsach::xemmh()
{
	for(int i=0;i<tscanbo;i++)
	{
		dscanbo[i].xemmh();cout<<endl;
	}
}
void danhsach::ghitep()
{
	fstream f("1.dat",ios::out|ios::binary);
	f.write(reinterpret_cast <char*> (this),sizeof(danhsach));
	f.close();
}
danhsach::danhsach(const char file_name[])
{
	/*Giong nhu ham doc tep*/
	fstream f(file_name,ios::in|ios::binary);
	f.read(reinterpret_cast <char*> (this),sizeof(danhsach));
	f.close();
}
danhsach danhsach::sapxep()
{
	danhsach sx=*this;
	for(int i=0;i<sx.tscanbo;i++)
	{
		for(int j=sx.tscanbo-1;j>i;j--)
		if(sx.dscanbo[j].luongcoban<sx.dscanbo[j-1].luongcoban)
		{
			/*Hoan doi can bo*/
			canbo box=sx.dscanbo[j];
			sx.dscanbo[j]=sx.dscanbo[j-1];
			sx.dscanbo[j-1]=box;
		}
	}
	return sx;
}
main()
{
/*Test 5
	danhsach a;
	a.nhapbp();
	a.ghitep();
*/
/*Test 6
	danhsach a("1.dat");
	a.xemmh();
*/
/*Test 7
	danhsach a;
	a.nhapbp();
	danhsach dasapxep=a.sapxep();
	dasapxep.xemmh();
*/
}
