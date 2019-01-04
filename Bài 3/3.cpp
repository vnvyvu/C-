/*Bai 3*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class danhsach;
bool operator==(danhsach,danhsach);
class sinhvien
{
	private:
		char ma[20];
		char ten[60];
	public:
		void nhapbp();
		void xemmh();
		friend class danhsach;
		friend bool operator==(sinhvien,sinhvien);
};
void sinhvien::nhapbp()
{
	fflush(stdin);
	cout<<"Nhap ma: ";cin.getline(ma,20);
	cout<<"Nhap ten: ";cin.getline(ten,60);
}
void sinhvien::xemmh()
{
	cout<<ma<<" "<<ten;
}
/*-------------------------------------------*/
danhsach operator+(danhsach,danhsach);
class danhsach
{
	private:
		sinhvien dssv[200];
		int tssinhvien;
	public:
		danhsach();
		danhsach themdau(sinhvien);
		danhsach themsauk(sinhvien,int);
		danhsach xoak(int);
		sinhvien timkiem(char[]);
		void xemmh();
		void ghitep();
		void doctep();
		danhsach(const char file_name[]);
		sinhvien timtheoma(char m[]);
		danhsach operator-(danhsach);
		friend danhsach operator+(danhsach,danhsach);
};
danhsach::danhsach()
{
	tssinhvien=0;
}
danhsach danhsach::themdau(sinhvien a)
{
	danhsach result=*this;
	for(int i=result.tssinhvien+1;i>=2;i--)
	{
		result.dssv[i]=result.dssv[i-1];
	}
	result.tssinhvien+=1;
	result.dssv[1]=a;
	return result;
}
danhsach danhsach::themsauk(sinhvien a,int k)
{
	danhsach result=*this;
	for(int i=result.tssinhvien+1;i>k;i--)
	{
		result.dssv[i]=result.dssv[i-1];
	}
	result.tssinhvien+=1;
	result.dssv[k]=a;
	return result;
}
danhsach danhsach::xoak(int k)
{
	danhsach result=*this;
	for(int i=k;i<=result.tssinhvien;i++)
	{
		result.dssv[i]=result.dssv[i+1];
	}
	result.tssinhvien--;
	return result;
}
sinhvien danhsach::timkiem(char c[])
{
	for(int i=1;i<=tssinhvien;i++)
	{
		char* token;
		token=strstr(dssv[i].ma,c);
		if(token!=NULL)
		{
			return dssv[i];
		}
	}
}
void danhsach::xemmh()
{
	for(int i=1;i<=tssinhvien;i++)
	{
		dssv[i].xemmh();
		cout<<endl;
	}
}
void danhsach::ghitep()
{
	fstream f("3.dat",ios::out);
	f.write(reinterpret_cast <char*> (this),sizeof(danhsach));
	f.close();
}
void danhsach::doctep()
{
	fstream f("3.dat",ios::in);
	f.read(reinterpret_cast <char*> (this),sizeof(danhsach));
	f.close();
}
bool operator==(sinhvien a,sinhvien b)
{
	int i=0;
	while(a.ma[i]!=NULL)
	{
		if(a.ma[i]!=b.ma[i]) return false;
		i++;
	}
	i=0;
	while(a.ten[i]!=NULL)
	{
		if(a.ten[i]!=b.ten[i]) return false;
		i++;
	}
	return true;
}
danhsach danhsach::operator-(danhsach b)
{
	danhsach a=*this;
	for(int j=1;j<=a.tssinhvien;j++)
	for(int i=1;i<=b.tssinhvien;i++)
	if(a.dssv[j]==b.dssv[i])
	{
		a=a.xoak(j);
	}
	return a;
}
danhsach operator+(danhsach a,danhsach b)
{
	danhsach result=a;
	for(int i=result.tssinhvien+1;i<=result.tssinhvien+b.tssinhvien;i++)
	{
		result.dssv[i]=b.dssv[i-result.tssinhvien];
	}
	result.tssinhvien+=b.tssinhvien;
	return result;
}
/*----------------------------------*/
main()
{
	int n;sinhvien a;
	
	danhsach b;
	cout<<"So luong sinh vien b: ";cin>>n;
	for(int i=1;i<=n;i++)
	{
		a.nhapbp();
		b=b.themdau(a);
	}
	danhsach c;
	cout<<"So luong sinh vien c: ";cin>>n;
	for(int i=1;i<=n;i++)
	{
		a.nhapbp();
		c=c.themdau(a);
	}
/*Test 10
	danhsach loaibo=b-c;
	loaibo.xemmh();
*/
/*Test 11
	danhsach noidanhsach=b+c;
	noidanhsach.xemmh();
*/
}
