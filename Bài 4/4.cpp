#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<unistd.h>
using namespace std;
class cauhoi
{
	friend class nganhangch;
	friend class baithiCpp;
	protected:
		int stt,diem,dapan;
		string noidung,a,b,c,d;
	public:
		void nhap();
		void xem();
};
void cauhoi::nhap()
{
	cout<<"STT: ";cin>>stt;
	fflush(stdin);
	cout<<"Cau hoi: ";getline(cin,noidung);
	fflush(stdin);
	cout<<"Dap an: ";cin>>dapan;
}
void cauhoi::xem()
{
	diem=2;
	cout<<"Cau "<<stt<<"("<<diem<<" diem):"<<endl;
	cout<<noidung<<endl;
	cout<<"----------------------------"<<endl;
}
/*---------------------------------------------*/
class nganhangch;
class cauhoitraloi;
class nganhangch
{
	friend class baithiCpp;
	protected:
		cauhoi dsch[100];
		int tscauhoi;
	public:
		void nhap();
		void xem();
		cauhoi xemcauhoi(int);
};
void nganhangch::nhap()
{
	cout<<"Tong so cau hoi: ";cin>>tscauhoi;
	for(int i=1;i<=tscauhoi;i++)
	{
		dsch[i].nhap();
	}
}
void nganhangch::xem()
{
	for(int i=1;i<=tscauhoi;i++)
	{
		dsch[i].xem();
		cout<<endl;
	}
}
cauhoi nganhangch::xemcauhoi(int n)
{
	for(int i=1;i<=tscauhoi;i++)
	{
		if(dsch[i].stt==n) return dsch[i];
	}
}
/*---------------------------------------------*/
class cauhoitraloi:public cauhoi
{
	friend class baithiCpp;
	private:
		int traloi,diem;
	public:
		void nhap();
		void xem();
};
void cauhoitraloi::nhap()
{
	cout<<"Tra loi: ";cin>>traloi;
	if(traloi==dapan) diem=2;
	else diem=0;
}
void cauhoitraloi::xem()
{
	cout<<"Cau tra loi cua ban: "<<traloi<<" (+"<<diem<<" diem)";
}
/*---------------------------------------------*/
class baithiCpp
{
	private:
		int tongdiem;
		cauhoitraloi dscauhoitraloi[6];
	public:
		baithiCpp(nganhangch);
		void lambai();
		void xem();
		void ghitep();
};
baithiCpp::baithiCpp(nganhangch a)
{
	cout<<"----------------------------"<<endl;
	cout<<"He thong dang chon ngau nhien 5 cau hoi.Vui long cho..."<<endl;
	tongdiem=0;
	int box[6];
	bool check[a.tscauhoi];
	for(int i=1;i<=a.tscauhoi;i++)
	{
		check[i]=true;
	}
	for(int i=1;i<=5;i++)
	{
		srand(time(NULL));
		box[i]=rand()%a.tscauhoi+1;
		while(!check[box[i]])
		{
			srand(time(NULL));
			box[i]=rand()%a.tscauhoi+1;
		}
		dscauhoitraloi[i].stt=a.dsch[box[i]].stt;
		dscauhoitraloi[i].noidung=a.dsch[box[i]].noidung;
		dscauhoitraloi[i].diem=a.dsch[box[i]].diem;
		dscauhoitraloi[i].dapan=a.dsch[box[i]].dapan;
		check[box[i]]=false;
		cout<<"Da lay du lieu cho cau hoi "<<i<<" !"<<endl;
	}
}
void baithiCpp::lambai()
{
	system("CLS");
	cout<<"----------------------------"<<endl;
	cout<<"Bat dau lam bai!"<<endl;
	for(int i=1;i<=5;i++)
	{
		dscauhoitraloi[i].cauhoi::xem();
		dscauhoitraloi[i].cauhoitraloi::nhap();
		tongdiem+=dscauhoitraloi[i].diem;
	}
}
void baithiCpp::xem()
{
	cout<<"----------------------------"<<endl;
	cout<<"Ket qua!"<<endl;
	int max=0;
	for(int i=1;i<=5;i++)
	{
		dscauhoitraloi[i].cauhoi::xem();
		dscauhoitraloi[i].cauhoitraloi::xem();
		cout<<endl;
		max+=dscauhoitraloi[i].cauhoi::diem;
	}
	cout<<"----------------------------"<<endl;
	cout<<"Tong diem: "<<tongdiem;
}
void baithiCpp::ghitep()
{
	fstream f("4.dat",ios::out|ios::binary|ios::app);
	f.write(reinterpret_cast <char*> (this),sizeof(baithiCpp));
	f.close();
}
void doctep(baithiCpp x[100],int &tsbaithi)
{
	fstream f("4.dat",ios::in|ios::binary);
	tsbaithi=0;
	while(f)
	{
		tsbaithi++;
		f.read(reinterpret_cast <char*> (&x[tsbaithi]),sizeof(baithiCpp));
	}
	f.close();
}
/*---------------------------------------------*/
main()
{
//	cauhoi a;
//	a.nhap();
//	a.xem();
	nganhangch b;
	b.nhap();
//	b.xem();
//	b.xemcauhoi(3);
//	cauhoitraloi c;
//	c.cauhoi::nhap();
//	c.cauhoi::xem();
//	c.cauhoitraloi::nhap();
//	c.cauhoitraloi::xem();
	baithiCpp d(b);
	d.lambai();
	d.baithiCpp::xem();
}
