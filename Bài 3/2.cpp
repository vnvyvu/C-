/*Bai 2*/
#include<iostream>
#include<fstream>
using namespace std;
class vecto;
class matran;
vecto operator*(vecto,matran);
void create(float *&a,int n)
{
	a=new float[n];
	for(int i=1;i<=n;i++) a[i]=0;
}
class vecto
{
	private:
		float *a;
		int n;
	public:
		void nhapbp();
		void xemmh();
		void doctep();
		void ghitep();
		float operator*(vecto b);
		friend vecto operator*(vecto,matran);
		/*Đổi ma trận sang vector
		Chỉ ma trận 1xn mới có thể đổi sang dạng vecto
		
		Hàm vecto(matran) ngay dưới Class matran
		Để không bị lỗi:
		Phải có hàm vecto() trong class vecto
		Trong Class matran cần có "friend vecto::vecto(matran);"
		*/
		vecto(matran);
		int get_n(){return n;}
		int get_a(int i){return a[i];}
		vecto(){}
};
void vecto::nhapbp()
{
	cout<<"[Vecto] Nhap kich thuoc: ";cin>>n;
	create(a,n);
	cout<<"[Vecto] Nhap cac phan tu: "<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<"a"<<i<<"= ";cin>>a[i];
	}
}
void vecto::xemmh()
{
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
}
void vecto::ghitep()
{
	fstream f("2vecto.dat",ios::out|ios::binary);
	f.write(reinterpret_cast <char*> (this),sizeof(vecto));
	f.close();
}
void vecto::doctep()
{
	fstream f("2vecto.dat",ios::out|ios::binary);
	f.read(reinterpret_cast <char*> (this),sizeof(vecto));
	f.close();
}
float vecto::operator*(vecto b)
{
	if(n==b.n)
	{
		float s=0;
		for(int i=1;i<=n;i++) s+=a[i]*b.a[i];
		return (float)s;	
	}
}
/*------------------------------------------------------*/
matran operator -(matran);
void create(float **&a,int n,int m)
{
	a=new float*[n];
	for(int j=1;j<=n;j++)
	{
		a[j]=new float[m];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) a[i][j]=0;
	}
}
class matran
{
	private:
		float **b;
		int n,m;
	public:
		void nhapbp();
		void xemmh();
		void doctep();
		void ghitep();
		friend matran operator - (matran);
		friend vecto operator*(vecto,matran);
		matran operator-();
		/*Doi vecto thanh ma tran
		  Chu y: (Giong voi "Doi matran thanh vecto")
		  T phai dung ham get_n() va get_a(i) moi co the
		  lay duoc gia tri cua n(do dai vecto a)
		  va cac phan tu trong vecto a
		  Ban nao co cach khac thi chi cho t vs
		*/
		matran(vecto,const char chieu[]);
		friend vecto::vecto(matran);
		matran(){}
};
void matran::nhapbp()
{
	cout<<"[Ma tran] Nhap n(Hang)= ";cin>>n;
	cout<<"[Ma tran] Nhap m(Cot)= ";cin>>m;
	create(b,n,m);
	cout<<"[Ma tran] Nhap cac phan tu"<<endl;
	for(int i=1;i<=n;i++)//n hang
	{
		for(int j=1;j<=m;j++) // m cot
		{
			cout<<"b"<<i<<j<<"= ";cin>>b[i][j];
		}
	}
}
void matran::xemmh()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		cout<<b[i][j]<<" ";
		cout<<endl;
	}
}
void matran::ghitep()
{
	fstream f("2matran.dat",ios::out|ios::binary);
	f.write(reinterpret_cast <char*> (this),sizeof(matran));
	f.close();
}
void matran::doctep()
{
	fstream f("2matran.dat",ios::in|ios::binary);
	f.read(reinterpret_cast <char*> (this),sizeof(matran));
	f.close();
}
matran matran::operator-()
{
	if(m==n)
	{
		//tinh dinh thuc cua ma tran
		for(int i=2;i<=n;i++) for(int j=i;j<=m;j++) for(int k=1;k<=n;k++) b[j][k]-=b[i-1][k]*b[j][i-1]/b[i-1][i-1];
		float det=b[1][1];
		for(int i=1;i<=n;i++) det*=b[i][i];
		if(det!=0)
		{
			//nghich dao
			matran result;
			create(result.b,n,m);
			result.n=n;result.m=m;
			for(int i=1;i<=result.n;i++)
			{
				for(int j=1;j<=result.m;j++) result.b[i][j]=b[i][j]/det;
			}
			return result;
		}
	}
}
/*---------------------------------------------------------*/
vecto operator*(vecto a,matran b)
{
	vecto c;
	if(a.n==b.n)
	{
		create(c.a,b.m);
		c.n=b.m;
		for(int j=1;j<=b.m;j++)
		{
			for(int i=1;i<=b.n;i++) c.a[j]+=a.a[i]*b.b[i][j];
		}
	}
	else
	{
		create(c.a,0);
		c.n=0;
	}
	return c;
}
matran operator-(matran b)
{
	if(b.m==b.n)
	{
		//tinh dinh thuc cua b
		for(int i=2;i<=b.n;i++)
		{
			for(int j=i;j<=b.m;j++)
			{
				float box=b.b[j][i-1]/b.b[i-1][i-1];
				for(int k=1;k<=b.n;k++)
				{
					b.b[j][k]-=b.b[i-1][k]*box;
				}
			}
		}
		float det=b.b[1][1];
		for(int i=1;i<=b.n;i++)
		{
			det*=b.b[i][i];
		}
		if(det!=0)
		{
			//nghich dao
			matran result;
			create(result.b,b.n,b.m);
			result.n=b.n;result.m=b.m;
			for(int i=1;i<=result.n;i++)
			{
				for(int j=1;j<=result.m;j++) result.b[i][j]=b.b[i][j]/det;
			}
			return result;
		}
	}
}
/*---------------------------------------------------------*/
vecto::vecto(matran b)
{
	if(b.n==1)
	{
		create(a,b.m);
		n=b.m;
		for(int i=1;i<=n;i++) a[i]=b.b[1][i];
	}
	if(b.m==1)
	{
		create(a,b.n);
		n=b.n;
		for(int i=1;i<=n;i++) a[i]=b.b[i][1];
	}
}
matran::matran(vecto a,const char chieu[])
{
	if(chieu=="N")
	{
		create(b,1,a.get_n());
		n=1;m=a.get_n();
		for(int i=1;i<=m;i++) b[1][i]=a.get_a(i);
	}
	if(chieu=="D")
	{
		create(b,a.get_n(),1);
		n=a.get_n();m=1;
		for(int i=1;i<=n;i++) b[i][1]=a.get_a(i);
	}
}
/*---------------------------------------------------------*/
main()
{
/*Test 11
	vecto a;
	matran b;
	b.nhapbp();
	a.nhapbp();
	vecto c=a*b;
	c.xemmh();
*/
/*Test 10
	vecto a,b;
	a.nhapbp();b.nhapbp();
	float tichaxb=a*b;
	cout<<tichaxb;
*/
/*Test 9
	matran a;
	a.nhapbp();
	matran b=-a;
	b.xemmh();
*/
/*Test 12
	matran a;
	a.nhapbp();
	matran b=a.operator-();
	b.xemmh();
*/
/*Test matran-->vecto
	matran a;
	a.nhapbp();
	vecto b(a);
	b.xemmh();
*/
/*Test vecto-->matran
	vecto a;
	a.nhapbp();
	matran b_ngang(a,"N");
	b_ngang.xemmh();
	matran b_doc(a,"D");
	b_doc.xemmh();
*/
/*Test ghi tep
	vecto a;
	a.nhapbp();
	a.ghitep();
*/
///*Test doc tep
	vecto a;
	a.doctep();
	a.xemmh();
//*/
}
