/*Bai 4*/
#include<iostream>
#include<fstream>
using namespace std;
class danhsach;
class sinhvien
{
	friend class danhsach;
	private:
		int ma;
		char ten[8];
	public:
		void nhap();
		void xem();	
};
void sinhvien::nhap()
{
	cout<<"Ma Sinh Vien: ";cin>>ma;
	fflush(stdin);
	cout<<"Ten: ";cin.getline(ten,8);
}
void sinhvien::xem()
{
	cout<<ma<<" "<<ten;
}
/*-------------------------------------------*/
struct NODE
{
	sinhvien info;//data
	NODE *next;//con tro next
};
NODE *create(sinhvien a)
{
	NODE *p=new NODE;
	if(p==NULL) return NULL;//Neu khong du bo nho, tao node that bai
	p->info=a;
	p->next=NULL;
	return p;
}
/*-------------------------------------------*/
class danhsach
{
	private:
		NODE *fist,*last;
	public:
		danhsach();
		danhsach themcuoi(sinhvien);
		danhsach themsauk(sinhvien,int);
		danhsach xoak(int);
		sinhvien timkiem(int);
		void xem();
		void ghitep();
		void doctep();
		danhsach(const char file_name[]);
//		~danhsach();
		danhsach operator+(danhsach);
};
danhsach::danhsach()
{
	fist=last=NULL;
}
danhsach danhsach::themcuoi(sinhvien a)
{
	danhsach b=*this;
	NODE *add=create(a);
	if(fist==NULL)
	{
		b.fist=b.last=add;
	}
	else
	{
		b.last->next=add;
		b.last=add;
	}
	return b;
}
danhsach danhsach::themsauk(sinhvien a,int k)
{
	danhsach b=*this;
	NODE *p=b.fist;
	NODE *add=create(a);
	for(int i=2;i<=k;i++)
	{
		p=p->next;
		if(p==NULL) return b.themcuoi(a);
	}
	add->next=p->next;
	p->next=add;
	return b;
}
danhsach danhsach::xoak(int k)
{
	danhsach b=*this;
	NODE *p=b.fist;
	for(int i=2;i<k;i++) p=p->next;
	p->next=p->next->next;
	return b;
}
sinhvien danhsach::timkiem(int ma)
{
	for(NODE *p=fist;p=last;p=p->next) if(ma==p->info.ma) return p->info;
}
void danhsach::xem()
{
	for(NODE *p=fist;p;p=p->next)
	{
		p->info.xem();
		cout<<endl;
	}
}
void danhsach::ghitep()
{
	fstream f("4.dat",ios::out|ios::binary);
	f.write(reinterpret_cast <char*> (this),sizeof(danhsach));
	f.close();
}
void danhsach::doctep()
{
	fstream f("4.dat",ios::in|ios::binary);
	f.read(reinterpret_cast <char*> (this),sizeof(danhsach));
	f.close();
}
danhsach::danhsach(const char file_name[])
{
	fstream f(file_name,ios::in|ios::binary);
	f.read(reinterpret_cast <char*> (this),sizeof(danhsach));
	f.close();	
}
/*danhsach::~danhsach()
{
	cout<<"Da huy!";
	this->ghitep();
	delete fist;
	delete last;
}*/
danhsach danhsach::operator+(danhsach b)
{
	danhsach result=*this;
	NODE *p=result.fist;
	while(p->next!=NULL) p=p->next;
	p->next=b.fist;
	result.last=b.last;
	return result;
}
main()
{
	cout<<"Test them cuoi:"<<endl;
	sinhvien b;
	b.nhap();
	danhsach a;
	a=a.themcuoi(b);
	a=a.themcuoi(b);
	a.xem();
	sinhvien c;
	c.nhap();
	a.themsauk(c,10);
	a.xem();
	cout<<"Xoa phan tu thu 2:"<<endl;
	a.xoak(3);
	a.xem();
	a.ghitep();
	a.doctep();
	cout<<"Test doc tep:"<<endl;
	a.xem();
	cout<<"Noi 2 danh sach(danh sach e 1 sinh vien + danh sach a):"<<endl;
	b.nhap();
	danhsach e;
	e=e.themcuoi(b);
	e=e+a;
	cout<<"Test operator+"<<endl;
	e.xem();
}
