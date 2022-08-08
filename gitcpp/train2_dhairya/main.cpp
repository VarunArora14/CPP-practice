


  #include <iostream>

using namespace std;

int main() {
	int testcases;
	cin>>testcases;
	while(testcases--){
	    int n;
	    cin>>n;
	    int i=n%12;
	    if(i==0)
	        cout<<n-11<<" ";
	    else
	        cout<<n-i+12-i+1<<" ";


	    if(i==1 || i==6 || i==7 || i==0)
	        cout<<"WS"<<endl;
	    else if(i==2 || i==5 || i==8 || i==11)
	        cout<<"MS"<<endl;
	    else
	       cout<<"AS"<<endl;

	}
}

