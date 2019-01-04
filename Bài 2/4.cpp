/*Bai 4*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class nganhangch;
class cauhoi
{
	friend class nganhangch;
	private:
		unsigned stt;
		float diem;
		char noidung[500],dapan[1];
	public:
		void nhapbp();
		void xemmh();
};
void cauhoi::nhapbp()
{
	fflush(stdin);
	cout<<"STT: ";cin>>stt;
	cout<<"Noi dung: ";cin.getline(noidung,500);
	cout<<"Dap an: ";cin>>dapan;
	cout<<"Diem: ";cin>>diem;
}
void cauhoi::xemmh()
{
	cout<<stt<<"("<<diem<<" diem): "<<noidung<<endl<<"Dap an: "<<dapan;
}
class nganhangch
{
	private:
		cauhoi dscauhoi[100];
		long tscauhoi;
	public:
		void nhapbp();
		void xemmh();
		void ghitep();
		nganhangch(const char c[]);
		cauhoi xemcauhoi(unsigned);
};
void nganhangch::nhapbp()
{
	cout<<"Nhap tong so cau hoi: ";cin>>tscauhoi;
	for(int i=1;i<=tscauhoi;i++)
	{
		dscauhoi[i].nhapbp();
	}
}
void nganhangch::xemmh()
{
	for(int i=1;i<=tscauhoi;i++)
	{
		dscauhoi[i].nhapbp();
		cout<<endl;
	}
}
void nganhangch::ghitep()
{
	fstream f("4.dat",ios::out|ios::binary);
	f.write(reinterpret_cast <char*> (this),sizeof(nganhangch));
	f.close();
}
nganhangch::nganhangch(const char c[])
{
	fstream f(c,ios::in|ios::binary);
	f.read(reinterpret_cast <char*> (this),sizeof(nganhangch));
	f.close();	
}
cauhoi nganhangch::xemcauhoi(unsigned n)
{
	for(int i=1;i<=tscauhoi;i++) if(dscauhoi[i].stt==n) return dscauhoi[i];
}
main()
{
}
