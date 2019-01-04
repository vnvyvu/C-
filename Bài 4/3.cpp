#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class lop;
class bangdiem;
class sinhvien
{
	friend class lop;
	friend class bangdiem;
	protected:
		string maso;
		string hoten;
	public:
		void nhap();
		void xem();
};
void sinhvien::nhap()
{
	cout<<"Ma so: ";fflush(stdin);getline(cin,maso);
	cout<<"Ho va ten: ";;getline(cin,hoten);
}
void sinhvien::xem()
{
	cout<<"["<<maso<<"] "<<hoten;
}
/*----------------------------------------*/
class lop
{
	friend class bangdiem;
	protected:
		sinhvien dssinhvien[100];
		unsigned tssinhvien;
	public:
		void nhap();
		void xem();
		lop sapxeptang();
};
void lop::nhap()
{
	cout<<"Tong so sinh vien: ";cin>>tssinhvien;
	for(int i=1;i<=tssinhvien;i++)
	{
		dssinhvien[i].nhap();
	}
}
void lop::xem()
{
	for(int i=1;i<=tssinhvien;i++)
	{
		dssinhvien[i].xem();
		cout<<endl;
	}
}
lop lop::sapxeptang()
{
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
/*----------------------------------------*/
class diemsinhvien:public sinhvien
{
	friend class bangdiem;
	private:
		unsigned diemthi;
		string ketqua;
	public:
		void nhap();
		void xem();
};
void diemsinhvien::nhap()
{
	cout<<"|Diem thi: ";cin>>diemthi;
	if(diemthi>=5) ketqua="Qua";
	else ketqua="Thi lai";
}
void diemsinhvien::xem()
{
	cout<<" "<<diemthi<<"-"<<ketqua;
}
/*----------------------------------------*/
class bangdiem
{
	private:
		char monhoc[60];
		diemsinhvien dsdiem[100];
		unsigned tssinhvien;
	public:
		bangdiem(lop);
		void nhap();
		void xem();
		void ghitep();
};
bangdiem::bangdiem(lop a)
{
	tssinhvien=a.tssinhvien;
	for(int i=1;i<=tssinhvien;i++)
	{
		dsdiem[i].hoten=a.dssinhvien[i].hoten;
		dsdiem[i].maso=a.dssinhvien[i].maso;
	}
}
void bangdiem::nhap()
{
	cout<<"Mon hoc: ";fflush(stdin);cin.getline(monhoc,60);
	for(int i=1;i<=tssinhvien;i++)
	{
		dsdiem[i].sinhvien::xem();
		dsdiem[i].diemsinhvien::nhap();
	}
}
void bangdiem::xem()
{
	cout<<"Mon hoc: "<<monhoc<<endl;
	for(int i=1;i<=tssinhvien;i++)
	{
		dsdiem[i].sinhvien::xem();
		dsdiem[i].diemsinhvien::xem();
		cout<<endl;
	}
}
void bangdiem::ghitep()
{
	fstream f("3.dat",ios::out|ios::binary|ios::app);
	f.write(reinterpret_cast <char*> (this),sizeof(bangdiem));
	f.close();
}
void doctep(bangdiem x[],unsigned &tsbangdiem)
{
	fstream f("3.dat",ios::in|ios::binary);
	while(f)
	{
		tsbangdiem++;
		f.read(reinterpret_cast <char*> (&x[tsbangdiem]),sizeof(bangdiem));
	}
	tsbangdiem-=1;
	f.close();
}
/*----------------------------------------*/
main()
{
//	diemsinhvien c;
//	c.nhap();
//	c.xem();
	lop b;
	b.nhap();
	bangdiem a(b);
	a.nhap();
	a.xem();
}
