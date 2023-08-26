#include<iostream>
#include<string>
#include<math.h>
using namespace std;
class stack{
        double str[100];
        int TOP=-1;
        public:
        int top(){
            return str[TOP];
        }
        void push(double a){
            TOP+=1;
            str[TOP]=a;
        }
        void pop(){
            if (TOP!=-1){
                TOP-=1;
            }
        }
        bool empty(){
            if(TOP==-1)
            return true;
            else 
            return false;
        }
};
 double operation(int a,int b,char op){
    switch (op)
    {
    case '-':
         return a-b;
        break;
    case '+':
         return a+b;
        break;
    case '*':
         return a*b;
        break;
     case '/':
         return a*(1.0)/b;
             break;
     case '^':
         return pow(a,b);
        break;
    
    default:
       cout<<"invalid OP!\n";
        return -1;
        break;
    }
 }
double postFixEvaluation(string s){
      stack st;
      int i=0;
      //s[i]>='a' && s[i]<='z'|| s[i]>='A'&& s[i]<='Z'||s[i]>='0' && s[i]<='9'
      while(s[i]!='\0'){
         if(s[i]>='a' && s[i]<='z'|| s[i]>='A'&& s[i]<='Z'){
            cout<<"Set value for "<<s[i]<<": ";
            int x;
            cin>>x;
            st.push(x);
            i++;
        }
        else if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
            i++;
        }
        else{
             int b=st.top();
             st.pop();
             int a=st.top();
             st.pop();
             st.push(operation(a,b,s[i]));
             i++;
            }
      }
      return st.top();
}
int main(){
    string st;
    cin>>st;
    cout<<postFixEvaluation(st);
}