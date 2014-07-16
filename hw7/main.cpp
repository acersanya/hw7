#include <iostream>
#include <time.h>
#include <queue>
#include <math.h>
#include <deque>
#include <list>
#include <iterator>
using namespace std;

class Polynomial {
private:
	int pow; // deg of polynom
    int x; // arg
	queue <int> coeffs;
public:
	queue <int> *Polynomial:: get_c();
	queue <int> Polynomial::get_coeff();
	int get_pow();
	int Polynomial::get_arg();
	int Polynomial::poly_calc( Polynomial *pol);
	Polynomial Polynomial::poly_add_sub(Polynomial *pol1 , Polynomial *pol2 , bool ad_sub);
	int Polynomial::poly_subtract();
	Polynomial Polynomial::poly_mult(Polynomial *pol1 , Polynomial *p2);
	 Polynomial::Polynomial(int pow , int x , queue<int> st);
	 ~Polynomial();

};

Polynomial::Polynomial(int _pow , int _x , queue <int> coeff){
	coeffs=coeff;
	pow=_pow;
	x=_x;
};


queue<int> *Polynomial::get_c(){
	return &coeffs;
}

queue<int> Polynomial::get_coeff(){
return coeffs;
}

int Polynomial::get_pow(){
	return pow;
}

int Polynomial::get_arg(){
	return x;}

int Polynomial::poly_calc( Polynomial *polyc){
         int result=0;

		 queue <int> t = polyc->get_coeff();

		 int a0 = t.front();
		 t.pop(); 
		 int tmp,n=1;

		 while( !(t.empty())){
			 
			 tmp = t.front(); 
				 t.pop();
			 		 
			 result = result + polyc->get_arg()*_Pow_int(tmp,n);
			  n++;
		 } 
		 result= result+a0;
	
		 return result;
	
}


Polynomial Polynomial::poly_add_sub(Polynomial *pol1 , Polynomial *pol2 , bool ad_sub){ // The sum of two polynoms :D

	if(pol1->get_coeff().size () > pol2->get_coeff().size()){
	    int tmp1,tmp2,tmp3;
		queue <int> q1 = pol1->get_coeff();
		queue <int> q2 = pol2->get_coeff();
		queue <int> q3;

		while(!q2.empty()){
			
			tmp1 = q1.front(); 
			tmp2 = q2.front();
			if(ad_sub==true){
				tmp3=tmp1+tmp2;}
			
			else if(ad_sub==false){
				tmp3=tmp1-tmp2;
			}

			q3.push(tmp3);
             q1.pop();
             q2.pop();
		}

		 while(!q1.empty()){
			 tmp1=q1.front(); 
			 q3.push(tmp1);
			 q1.pop();

		 }

		 Polynomial *pol3 = new Polynomial ( (q3.size()), 0 , q3);
	 return *pol3;
	}


	else if(pol2->get_coeff().size() > pol1->get_coeff().size()){
		 int tmp1,tmp2,tmp3;
		queue <int> q1 = pol2->get_coeff();
		queue <int> q2 = pol1->get_coeff();
		queue <int> q3;

		while(!q2.empty()){
			
			tmp1 = q2.front(); q2.pop();
			tmp2 = q1.front(); q1.pop();
			if(ad_sub==true){
				tmp3=tmp1+tmp2;}
			else if(ad_sub==false){
				tmp3=tmp1-tmp2;
			}
			q3.push(tmp3);
		}
		if(ad_sub==true){
		 while(!q1.empty()){
			 tmp1=q1.front(); q1.pop();
			 q3.push(tmp1); }}
		else if(ad_sub==false){
					 while(!q1.empty()){
			 tmp1=-1*q1.front(); q1.pop();
			 q3.push(tmp1); }

		}
		
		 Polynomial *pol3 = new Polynomial ( (q3.size()), 0 , q3);
		 return *pol3;

	}

	else  if (pol1->get_coeff().size () == pol2->get_coeff().size())
	{

	int tmp1,tmp2,tmp3;
		queue <int> q1 = pol1->get_coeff();
		queue <int> q2 = pol2->get_coeff();
		queue <int> q3;

		while(!q1.empty()){
			
			tmp1 = q1.front(); q1.pop();
			tmp2 = q2.front(); q2.pop();
			if(ad_sub==true){
				tmp3=tmp1+tmp2;}
			else if(ad_sub==false){
				tmp3=tmp1-tmp2;
			}
			q3.push(tmp3);
		}

				 Polynomial *pol3 = new Polynomial ( (q3.size()), 0 , q3);
		 return *pol3;
	}

	return *pol1;

}


Polynomial Polynomial::poly_mult (Polynomial *a , Polynomial *b){
	
	queue <int> aa = a->get_coeff();
	queue <int> bb = b->get_coeff();
	queue <int> res ;
	
	int *array1 = new int [aa.size()];
	int *array2= new int [bb.size()];

	int v = aa.size(); 
	int w=  bb.size();

	for(int i=0;i<v;i++){
		array1[i]=aa.front(); aa.pop();
	}

	for(int i=0;i<w;i++){
		array2[i]=bb.front();bb.pop();
	}

	int tmp,temp;

	for(int i=0;i<v;i++){
		tmp=array1[i];
		int rese=0;
		for(int j=0;j<w;j++){
			temp=array2[j];
	     rese=rese+temp*tmp;
		}
		res.push(rese);
	}


Polynomial *polynom = new Polynomial(res.size()-1,0,res);
  return *polynom;
}


void get_info( Polynomial *polynom){
	cout<<"Coefficients table:";
	queue <int> p = polynom->get_coeff();
	
   while(!p.empty()){

	 cout<<p.front()<<",";
       p.pop();	
   }
   cout<<endl;
   cout<<"Pow of your polinom equals:";
   cout<<polynom->get_pow();
   p.empty();
 
}


queue <int> filling (){
	int size=0;
	cout<<"Enter pow: \n";
	cin>>size;
	size=size+1;
	queue <int> st ;
	int k=0;
		while(size!=0){
       cout<<"Enter coeff: \n";
	   cin>>k;
		st.push(k);
		size--;
	}
		return st;
	
}


int main(){
	queue <int> st = filling();
	//system("cls");
	queue<int> st1= filling();

   cout<<"Enter argument: \n";
   int arg ,arg1;
   cin>>arg;
   cin>>arg1;
   Polynomial *polyc1  = new Polynomial (st.size(),arg,st);
   Polynomial *polyc2  = new Polynomial (st1.size(),arg1,st1);
  Polynomial *polyc3 =  new Polynomial( polyc1->poly_add_sub(polyc1,polyc2,false));
  cout<<"Adding two polynoms:"<<endl;
   get_info(polyc3);

   cout<<"Multiplication of two polynoms:"<<endl;
   Polynomial *polyc4 = new Polynomial(polyc2->poly_mult(polyc1,polyc2));
get_info(polyc4);
   //cout<<f<<endl;
cin.get();
	return 0;}