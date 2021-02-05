#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void showData(double *a,int N,int M){           //N คือ หลัก M คือแถว และ  ใช้ *a หรือ a[] มีค่าเท่ากัน
    cout << fixed << setprecision(2.0);         //setprecision(2.0) เป็นการกำหนดจุดของทศนิม เป็น libary ของ iostream
    for(int i = 0; i < N*M; i++){
        cout << a[i];                            //print Arrays ตัวที่ i
        if((i+1)%M==0) cout << endl;             //Aarrays ตัวที่หารหลัก ลงตัว ให้เว้นบรทัด แต่ต้องเป็น i+1 เพราะเริ่มที่ i=0
        else cout << " ";
    }
}

void randData(double a[],int N,int M){    //  ใช้ *a หรือ a[] มีค่าเท่ากัน
    for(int i = 0; i < N*M; i++){
        a[i] = (rand()%101)/100.00;  //100.00 เพราะ N,M เป็น int เลยต้องหาร .00 เพื่อเอาค่าทศนิยม 2 ตำแหน่ง
    }
}

void findRowSum(const double *a,double *b,int N,int M)
{
     for(int i=0 ; i < N ; i++)   // ลูปแถว
	  {*(b+i) = 0;                // set b+i เป็น 0 เพราะเป็นการล้างค่าในหน่วยความจำเพื่อไม่ให้เอาค่าเดิมมาบวกกัน
	     for(int j=0 ; j<M ; j++) //ลูปหลัก
	     {   
	        *(b+i)+= *(a+((i*M)+j)); // *(b+i) เป็นค่า sum , (i*M)+j คือการขยับตำแหน่ง 1,2,3,4,5 เพื่อเอาจำนวนใน Arrays มาบวก , *(a+((i*M)+j)) = *(a+...)
	     }
	  }
}

void findColSum(const double *a,double *b,int N,int M)
{
	for(int i=0 ; i < M ; i++)   // ลูปแถว
	  {*(b+i) = 0;                // set b+i เป็น 0 เพราะเป็นการล้างค่าในหน่วยความจำเพื่อไม่ให้เอาค่าเดิมมาบวกกัน
	     for(int j=0 ; j<N ; j++) //ลูปหลัก
	     {   
	        *(b+i)+= *(a+((j*M)+i));
	     }
	  }
}
     