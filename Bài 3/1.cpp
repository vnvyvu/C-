/*Bai 1*/
#include<iostream>
#include<fstream>
using namespace std;
class xau;
xau operator +(xau,xau);
class xau
{
	friend xau operator +(xau,xau);
	private:
		char *a;
		int n;
	public:
		xau();
		xau(char c[]);
		xau(int);
		void xem();
		xau doichuhoa();
		xau trichtrai(int);
		xau trichphai(int);
		bool timkiem(xau c);
		xau thaythe(xau,xau);
		xau operator-(xau);
};
xau::xau()
{
	*a=NULL;
}
xau::xau(char c[255])
{
	int i=0;
	while(c[i]!=NULL) i++;
	n=i;
	a=new char [n];
	for(int i=0;i<n;i++)
	{
		a[i]=c[i];
	}
	a[n]=NULL;
}
xau::xau(int k)
{
	a=new char [k];
	n=k;
}
void xau::xem()
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
	}
}
xau xau::doichuhoa()
{
	xau result=*this;
	char k='a'-'A';
	for(int i=0;i<result.n;i++)
	{
		if(result.a[i]>='a' and result.a[i]<='z') result.a[i]-=k;
	}
	return result;
}
xau xau::trichphai(int m)
{
	xau c(m);
	for(int i=0;i<m;i++)
	{
		c.a[i]=a[i];
	}
	return c;
}
xau xau::trichtrai(int m)
{
	xau c(m);
	for(int i=0;i<m;i++)
	{
		c.a[m-i-1]=a[n-i-1];
	}
	return c;
}
bool xau::timkiem(xau c)//tim xau c trong xau a,kieu tra ve la true-false
{
	for(int i=0;i<n;i++)//duyet a
	{
		bool check=true;//kiem tra xem c co trong a hay khong
		for(int j=0;j<=c.n;j++)//duyet c
		{
			if(c.a[j]!=a[i+j])
			{
				check=false;
				break;
			}
		}
		if(check) return true;
	}
	return false;
}
xau xau::thaythe(xau c,xau body)//tim xau c trong xau a va thay the no bang xau body
{
	xau box=*this;
	if(box.timkiem(c))//kiem tra xem c co trong a hay khong
	{
		int vitri=-1;//vi tri cua c trong a
		if(vitri==-1)//neu vi tri cua no khong thay doi
		for(int i=0;i<box.n;i++)//duyet a
		{
			bool check=true;//kiem tra xem cac ky tu cua a co trung c hay khong
			for(int j=0;j<c.n;j++)//duyet c
			{
				if(check and j==c.n-1)//neu cac ky tu cua a trung c
				{
					vitri=i;//lay duoc vi tri cua c trong a
					break;
				}
				if(c.a[j]!=box.a[i+j])//neu ki tu cua c khac ki tu cua a
				{
					check=false;
					break;
				}
			}
		}
		xau head=box.trichphai(vitri);//trich <vitri> ki tu cua box
		xau last=box.trichtrai(box.n-vitri-c.n);//trich <>
		xau result=head+body+last;
		/*Mo ta:
		Truoc: 
		Xau a |----------------------|======|____________|
		Sau:
		Xau a |----------------------|..........|____________|
		
		*Chu thich:
		Do dai cua xau head ki hieu la: "-"
		Do dai cua xau c ki hieu la: "="
		Do dai cua xau last ki hieu la: "_"
		Do dai cua xau body ki hieu la: "."
		*/
		return result;
	}
}
xau operator +(xau a,xau b)//noi 2 xau ki tu
{
	for(int i=0;i<a.n+b.n;i++)
	{
		a.a[i+a.n]=b.a[i];
	}
	a.n+=b.n;
	return a;
}
xau xau::operator-(xau b)//noi 2 xau ki tu
{
	while(a[n-1]==' ')
	{
		a[n-1]=NULL;
		n--;
	}
	for(int i=0;i<n+b.n;i++)
	{
		a[i+n]=b.a[i];
	}
	n+=b.n;
	return a;
}
main()
{
/*Test 4
	xau a("Doi chU hOa");
	xau chuhoa=a.doichuhoa();
	chuhoa.xem();
*/
/*Test 7
	xau a("Hoc Vien Vien Thong");
	xau c("Vien Thong");
	if(a.timkiem(c)) cout<<"TRUE";
	else cout<<"FALSE";
*/
/*Test 5-6-7-8-9-10
	xau a("Hoc Vien PTIT");
	xau b("Buu Chinh Vien Thong");
	xau c("PTIT");
	xau replace_test=a.thaythe(c,b);//tim xau c trong a, thay no bang xau b
	replace_test.xem();
*/
}
