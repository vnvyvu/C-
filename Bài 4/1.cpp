#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class bangluong;
class danhsach;
class canbo
{
	friend class danhsach;
	friend class bangluong;
	protected:
		char hoten[36];
		int luongcoban;
	public:
		void nhap();
		void xem();
};
/*--------------------------------------------------------*/
void canbo::nhap()
{
	fflush(stdin);
	cout<<"Ho va ten: ";cin.getline(hoten,36);
	cout<<"Luong co ban: ";cin>>luongcoban;
}
void canbo::xem()
{
	cout<<hoten<<" "<<luongcoban<<" ";
}
/*--------------------------------------------------------*/
class danhsach
{
	friend class bangluong;
	private:
		canbo dscanbo[100];
		int tscanbo;
	public:
		void nhap();
		void xem();
		danhsach sapxepgiam();
};
/*--------------------------------------------------------*/
void danhsach::nhap()
{
	cout<<"Tong so can bo: ";cin>>tscanbo;
	cout<<"------------------------------------"<<endl;
	for(int i=1;i<=tscanbo;i++)
	{
		dscanbo[i].nhap();
	}
}
void danhsach::xem()
{
	for(int i=1;i<=tscanbo;i++)
	{
		dscanbo[i].xem();
		cout<<endl;
	}
}
danhsach danhsach::sapxepgiam()
{
	danhsach result=*this;
	for(int i=1;i<=result.tscanbo;i++)
	{
		for(int j=result.tscanbo;j>=i+1;j--)
		{
			if(result.dscanbo[j-1].luongcoban<result.dscanbo[j].luongcoban)
			{
				canbo box=result.dscanbo[j-1];
				result.dscanbo[j-1]=result.dscanbo[j];
				result.dscanbo[j]=box;
			}
		}
	}
	return result;
}
/*--------------------------------------------------------*/
class luongcb:public canbo
{
	friend class bangluong;
	private:
		unsigned ngaycong,luong;
	public:
		void nhap();
		void xem();
};
void luongcb::nhap()
{
	cout<<"Ngay cong: ";cin>>ngaycong;
	luong=luongcoban+ngaycong*50000;
}
void luongcb::xem()
{
	cout<<" "<<ngaycong<<" "<<luong<<" VND";
}
/*--------------------------------------------------------*/
class bangluong
{
	private:
		unsigned thang,tongluong,tscanbo;
		luongcb dslcanbo[100];
	public:
		bangluong(danhsach);
		void nhap();
		void xem();
		void ghitep();
		bangluong(){}
};
bangluong::bangluong(danhsach a)
{
	tscanbo=a.tscanbo;
	for(int i=1;i<=tscanbo;i++)
	{
		for(int j=0;j<=strlen(a.dscanbo[i].hoten);j++)
		dslcanbo[i].hoten[j]=a.dscanbo[i].hoten[j];
		dslcanbo[i].luongcoban=a.dscanbo[i].luongcoban;
	}
}
void bangluong::nhap()
{
	cout<<"Thang: ";cin>>thang;
	tongluong=0;
	for(int i=1;i<=tscanbo;i++)
	{
		dslcanbo[i].canbo::xem();
		dslcanbo[i].luongcb::nhap();
		tongluong+=dslcanbo[i].luong;
	}
}
void bangluong::xem()
{
	cout<<"Thang: "<<thang<<endl;
	cout<<"Ho va ten->Luong co ban->Ngay cong->Tien luong"<<endl;
	for(int i=1;i<=tscanbo;i++)
	{
		dslcanbo[i].canbo::xem();
		dslcanbo[i].luongcb::xem();
		cout<<endl;
	}
	cout<<"Tong luong tra cho can bo: "<<tongluong<<" VND";
}
void bangluong::ghitep()
{
	fstream f("1.dat",ios::out|ios::binary|ios::app);
	f.write(reinterpret_cast <char*> (this),sizeof(bangluong));
	f.close();
}
void doctep(bangluong x[],int &tsbangluong)
{
	fstream f("1.dat",ios::in|ios::binary);
	tsbangluong=0;
	while(f)
	{
		tsbangluong++;
		f.read(reinterpret_cast <char*> (&x[tsbangluong]),sizeof(bangluong));
	}
	tsbangluong--;
	f.close();
}
/*--------------------------------------------------------*/
main()
{
/*Test 3
	danhsach a;
	a.nhap();
	danhsach sapxep=a.sapxepgiam();
	sapxep.xem();
*/
/*Test 7-8
	bangluong c[10];
	unsigned tsbangluong=0;
	doctep(c,tsbangluong);
	for(int i=1;i<=tsbangluong;i++)
	{
		c[i].xem();
		cout<<endl;
	}
*/
/*Test ghi tep
	danhsach a;
	a.nhap();
	bangluong b(a);
	b.nhap();
	b.ghitep();
	b.xem();
*/
/*Test doc tep
	bangluong x[10];
	int tongsobl;
	doctep(x,tongsobl);
	for(int i=1;i<=tongsobl;i++)
	{
		x[i].xem();
	}
*/
}
