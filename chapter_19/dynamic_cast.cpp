#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <typeinfo>
using namespace std;
 
class A
{
public:
	A()
	{
		cout<<"A()"<<endl;
	}
	virtual ~A()
	{
		cout<<"~A()"<<endl;
	}
};
 
class B:virtual public A
{
public:
	B()
	{
		cout<<"B()"<<endl;
	}
	virtual ~B()
	{
		cout<<"~B()"<<endl;
	}
};
class C:public B
{
public:
	C()
	{
		cout<<"C()"<<endl;
	}
	virtual ~C()
	{
		cout<<"~C()"<<endl;
	}
};
class D:public B,virtual public A
{
public:
	D()
	{
		cout<<"D()"<<endl;
	}
	virtual ~D()
	{
		cout<<"~D()"<<endl;
	}
};
int main(int argc,char** argv)
{
	A *pa = new C;
	if (B *pb = dynamic_cast<B*>(pa))
	{
		cout<<"True"<<endl;
	}
	else
	{
		cout<<"False"<<endl;
	}
 
	try
	{
		C &cp = dynamic_cast<C&>(*pa);//正确，*pa的类型是C  
		cout << "cp" << endl;  
	}  
	catch (std::bad_cast e) 
	{  
		cout << e.what() << endl;  
	}//引用类型失败返回的是bad_cast  
 
	B *pbb = new B;
	if (C *pc = dynamic_cast<C*>(pbb))
	{
		cout<<"True"<<endl;
	}
	else
	{
		cout<<"False"<<endl;
	}
 
	A *paa = new D;
	if (B *pc = dynamic_cast<B*>(paa))
	{
		cout<<"True"<<endl;
	}
	else
	{
		cout<<"False"<<endl;
	}
 
	A *paaa = new B;
	if (C *pc = dynamic_cast<C*>(paa))
	{
		cout<<"True"<<endl;
	}
	else
	{
		cout<<"False"<<endl;
	}
	return 0;
}