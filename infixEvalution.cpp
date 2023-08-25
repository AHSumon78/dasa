#include<bits/stdc++.h>
using namespace std;
class stackx{
           char a[100];
           double b[100];
           int TOPD=-1;
           int TOP=-1;

           public:
           void push(char data){
                TOP++;
                a[TOP]=data;
           }
           char top(){
            return a[TOP];
           }
           void pop(){
            TOP--;
           }
           bool empty(){
            if(TOP==-1)
            return true;
            else 
            return false;
           }


             void pushd(double data){
                TOPD++;
                b[TOPD]=data;
           }
           char topd(){
            return b[TOPD];
           }
           void popd(){
            TOPD--;
           }
           bool emptyd(){
            if(TOPD==-1)
            return true;
            else 
            return false;
           }
};
int priority(char op){
    if(op=='+'||op=='-'){
        return 1;
    }
    else if(op=='*'||op=='/'){
        return 2;
    }
    else if(op=='^'){
        return 3;
    }
    else return 0;
}
string infixToPostfix(string str){
        stackx st;
        string postfix="";
        int i=0;
        while(str[i]!='\0'){
            if(str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z' || str[i]>='0' && str[i]<='9'){
                postfix+=str[i];
            }
            else if(str[i]=='('){
                st.push(str[i]);
            }
            else if(str[i]==')'){
                while(st.top()!='('){
                  postfix+=st.top();
                  st.pop();
                }
                st.pop();
            }
            else {
                while(!st.empty() && priority(str[i])<=priority(st.top())){
                    postfix+=st.top();
                    st.pop();
                }
                st.push(str[i]);
            }
              i++;
            }
            while(!st.empty()){
                postfix+=st.top();
                st.pop();
            }
        return postfix;
}
double operation(int a,int b,char op){
 switch (op)
 {
  case '+':
    return a+b;
    break;
  case '-':
    return a-b;
    break;
  case '*':
   return a*b;
   break;
   case '/':
   return a/b;
   break;
   case '^':
   return pow(a,b);

 default:
 return -1;
    break;
 }
}
double evalPostfix(string str){
     stackx st;
     int i=0;
     while(str[i]!='\0'){
            if(str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z'){
                cout<<"Give value for "<<str[i]<<" : ";
                int x;
                cin>>x;
                st.pushd(x);
            }
            else if(str[i]>='0' && str[i]<='9'){
                  st.pushd(str[i]-'0');
            }
            else{
                double b=st.topd();
                st.popd();
                double a=st.topd();
                st.popd();
                st.pushd(operation(a,b,str[i]));
            }
            i++;
     }
     return st.topd();
      
}
int main(){
    string st="a+b*(5/b)";
    cout<<"provide an infix notation:\n";
    cin>>st;
    cout<<evalPostfix(infixToPostfix(st));

}