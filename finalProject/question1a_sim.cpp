#include<iostream>
using namespace std;
bool f1[26];
bool f2[26];
bool evaluate(){
	for(int i=0;i<8;i++){
		if(f1[i]==f2[i])
		return false;
	}
	return true;
}
void equ1(){
	cout<<endl;
	
	int w=0;
	cout<<"\t\t***********************************************\n";
	cout<<"\t\t*                                             *\n";
	cout<<"\t\t*                  TRUTH TABLE                *\n";
	cout<<"\t\t*                                             *\n";
	cout<<"\t\t***********************************************\n\n";
    cout << "p\tq\tr\t(p^q)>r\t\t(p>(q>r))\t\t[(p^q)>r]<>(p>(q> r))" << endl;
    for (int p = 0; p <= 1; p++) {
        for (int q = 0; q <= 1; q++) {
            for (int r = 0; r <= 1; r++) {
                int eq1 = ((p && q) ? r : true);//(p^q)>r
                int eq2 = (((!p) || q) ? r : true);//(p>(q>r))
                int eq3 = ((!p || q) && (!q || r)) ? true : false;//[(p^q)>r]<>(p>(q> r))
                cout << p << "\t" << q << "\t" << r << "\t" << eq1 << "\t\t" << eq2 << "\t\t\t" << eq3 << endl;
                f1[w]=eq3;
                w++;
            }
        }
    }
}
void equ2(){
		bool f2[26];
	int w1=0;
    cout << "p|\tq|\tr|\t(p>q)|\t\t(q>r)|\t\t(p>q)&(q>r)|\t\t(p>r)|\t\t[(p>q)&(q>r)]>(p>r)|" << endl;
    cout<<"_______________________________________________________________________________________________________________________"<<endl;
    for (int p = 0; p <= 1; p++) {
        for (int q = 0; q <= 1; q++) {
            for (int r = 0; r <= 1; r++) {
                int eq1 = ((!p) || q) ? true : false;//(p>q
                int eq2 = ((!q) || r) ? true : false;//(q>r)
                int eq3 = eq1 && eq2;//p>q)&(q>r)
                int eq4 = ((!p) || r) ? true : false;//(p>r)
                int eq5 = ((!eq3) || eq4) ? true : false;//[(p>q)&(q>r)]>(p>r)
                cout << p << "|\t" << q << "|\t" << r << "|\t" << eq1 << "|\t\t" << eq2 << "|\t\t" << eq3 << "|\t\t\t" << eq4 << "|\t\t\t" << eq5 << endl;
            f2[w1]=eq5;
                w1++;}
        }
    }
}
int main()
{
	
	//[(p^q) ? r] ? (p ? (q ? r)) 
	cout<<"[(p^q)>r]<>(p>(q>r))=[(p>q)^(q>r)]>(p>r)\n";
	equ1();//.....................................for left side
	cout<<"\n\n\n";
	equ2();//......................................for right side
	if(evaluate()==true)
	cout<<"BOTH EQUATION ARE EQUAIVALENT TO EACH OTHER\n";
	else
	cout<<"BOTH EQUATION ARE NOT EQUAIVALENT TO EACH OTHER\n";
	
	//system(pause);
    return 0;
}

	
 