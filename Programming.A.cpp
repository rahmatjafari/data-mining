#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n,i,first_q3,end_q1;
	double q1,q2,q3,iqr,outlier,z;
	bool flag=false;
	cout<<"Enter Number Of Statistics Data"<<endl;			
	cin>>n;							//تعداد داده ها را دریافت می کنیم
	double * arr=new double[n+1];
	cout<<"Enter Data"<<endl;
	for(i=1;i<=n;i++)
		cin>>arr[i];					//داده ها را یکی یکی وارد می کنیم
	
	sort(arr+1,arr+n+1);

	if(n%2==1)
	{
		end_q1=(n+1)/2-1;
		first_q3=(n+1)/2+1;

		q2=arr[(n+1)/2];

		if(end_q1%2==1)
		{
			q1=arr[(end_q1+1)/2];
			q3=arr[(first_q3+n)/2];
		}
		else
		{
			q1=(arr[end_q1/2]+arr[(end_q1/2)+1])/2;
			q3=(arr[((n-(end_q1+1))/2+end_q1+1)]+arr[((n-(end_q1+1))/2+end_q1+1+1)])/2;
		}
		
	}
	else
	{
		end_q1=n/2;
		first_q3=n/2+1;

		q2=(arr[n/2]+arr[(n/2)+1])/2;
		
		if(end_q1%2==1)
		{
			q1=arr[(end_q1+1)/2];
			q3=arr[(first_q3+n)/2];
		}
		else
		{
			q1=(arr[end_q1/2]+arr[(end_q1/2)+1])/2;
			q3=(arr[((n-(end_q1+1))/2+end_q1+1)]+arr[((n-(end_q1+1))/2+end_q1+1+1)])/2;
		}
	}

	iqr=q3-q1;
	z=iqr*1.5;

	cout<<endl<<"MIN: "<<arr[1]<<endl;
	cout<<"Q1: "<<q1<<" -- "<<"Q2: "<<q2<<" -- "<<"Q3: "<<q3<<endl;
	cout<<"MAX: "<<arr[n]<<endl;

	cout<<"OUTLIERS: ";
	for(i=1;i<=n;i++)
		if((arr[i]>(z+q3)) || (arr[i]<(q1-z)))
		{
			cout<<arr[i]<<"	,";
			flag=true;	
		}
	if(flag==false)
		cout<<"There is no outlier.";

	return 0;
}
