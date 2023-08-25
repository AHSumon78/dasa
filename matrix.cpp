#include<bits/stdc++.h>
using namespace std;
class matrix{
         int mat[100];
         int r;
         int c;
         int l;
         public:
         matrix(int ro,int co){
            r=ro;
            c=co;
            l=r*c;
         }
         void insertMat(){ 
            for(int i=0;i<l;i++){
               cin>>mat[i];
            }
         }
         void printMat(){
            for(int i=0;i<l;i++){
                cout<<mat[i]<<" ";
                if((i+1)%r==0){
                    cout<<"\n";
                }
            }
         }
         void printCol(int col){
             for(int i=col-1;i<l;i+=c){
                for(int j=0;j<col*2-2;j++)
                cout<<" ";
                printf("%d\n",mat[i]);
             }
         }
        void printRow(int ro){
                for(int j=0;j<ro;j++)
                cout<<"\n";
            for(int i = (ro-1)*c; i<(ro-1)*c+c;i++){
               cout<<mat[i]<<" ";
            }
            cout<<endl;
        }
        int *getMatrix(){
            return mat;
        }
        int getR(){
            return r;
        }
        int getC(){
            return c;
        }
        
};


int *addMatrix(int *a,int ra,int ca,int *b,int rb,int cb){
   
    int l1=ra*ca;
    int l2=rb*cb;
    if(l2!=l1){
        cout<<"Sorry invalid operatin!\n";
    }
     static int ab[100];
    for(int i=0;i<l1;i++){
        ab[i]=*(a+i)+*(b+i);
    }
    return ab;
}
 int *subMatrix(int *a,int ra,int ca,int *b,int rb,int cb){
   
    int l1=ra*ca;
    int l2=rb*cb;
    if(l2!=l1){
        cout<<"Sorry invalid operatin!\n";
    }
     static int ab[100];
    for(int i=0;i<l1;i++){
        ab[i]=*(a+i)+*(b+i);
    }
    return ab;
}
int *multMatrix(int *a,int ra,int ca,int *b,int rb,int cb){
    static int ab[100];
    if(ca!=rb){
        "sorry invalid Mult!\n";
        return NULL;
    }
    
        for(int i=0;i<ra;i++){
            for(int j=0;j<cb;j++){
                int sum=0;
                for(int k=0;k<rb;k++){
                    sum+=(*(a+(i*ca+k)))*(*(b+(k*ca)+j));
            }
            ab[(i*ca)+j]=sum;
        }
    }
    return ab;
}
 void printMat(int *a,int r,int c){
    int l=r*c;
            for(int i=0;i<l;i++){
                cout<<*(a+i)<<" ";
                if((i+1)%r==0){
                    cout<<"\n";
                }
            }
         }
int main(){
      cout<<" Enter A matrix row column then matrix:\n";
      int r,c;
      cin>>r>>c;
      matrix A(r,c);
      A.insertMat();
      int *matA=A.getMatrix();
      cout<<" Enter B matrix row column then matrix:\n";
      int x,y;
      cin>>x>>y;
      matrix B(x,y);
      B.insertMat();
      int *matB=B.getMatrix();
   
   printMat(addMatrix(matA,r,c,matB,x,y),r,c);
   cout<<"\n\n";
   printMat(multMatrix(matA,r,c,matB,x,y),r,y);
}