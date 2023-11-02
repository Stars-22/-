#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct BigInteger{
    //BASEΪvector������һλ�����洢�����֣�ǰ�涼����10�����
    //WIDTHΪ���
    static const int BASE = 100000000;
    static const int WIDTH = 8;
    vector<int> s;
    //����Ϊ1������Ϊ-1
    int flag = 1;
    
    //���캯��
    BigInteger(ll num = 0){*this = num;}
    BigInteger(string str){*this = str;}
    BigInteger(const BigInteger& t){
        this->flag = t.flag;
        this->s = t.s;
    }
    //��ֵ����
    BigInteger operator = (ll num){
        s.clear();
        do {
            s.push_back(num % BASE);
            num /= BASE;
        }while(num > 0);
        return *this;
    }
    BigInteger operator = (string &str){
        s.clear();
        int x,len = (str.length()-1)/WIDTH + 1;
        for(int i=0;i<len;i++){
            int end = str.length() - i*WIDTH;
            int start = max(0,end - WIDTH);
            sscanf(str.substr(start,end-start).c_str(),"%d",&x);
            s.push_back(x);
        }
        return *this;
    }
 
    //�����ȽϺ��� A < B
    bool cmp( vector<int> &A, vector<int> & B){
        if(A.size() != B.size())return A.size() < B.size();
        for(int i=A.size()-1;i>=0;i--){
            if(A[i] != B[i]){
                return A[i] < B[i];
            }
        }
        return false;
    }
    //�ȽϺ������С���򷵻���
    bool operator < ( BigInteger & b){
        return cmp(s,b.s);
    }
    bool operator > ( BigInteger& b){
        return b < *this;
    }
    bool operator <= ( BigInteger &b){
        return !(b < *this);
    }
    bool operator >= ( BigInteger &b){
        return !(*this < b);
    }
    bool operator == ( BigInteger &b){
        return !(b < *this) && (*this < b);
    }
    //������������
    vector<int> add(vector<int> &A, vector<int> &B);
    vector<int> sub(vector<int> &A, vector<int> &B);
    vector<int> mul(vector<int> &A, int b);
    vector<int> mul(vector<int> &A, vector<int> &B);
    vector<int> div(vector<int> &A, int b);
    vector<int> div(vector<int> A, vector<int> B);
 
    //���������
    BigInteger operator + (BigInteger &b);
    BigInteger operator - (BigInteger &b);
    BigInteger operator * (BigInteger &b);
    BigInteger operator * (int& b);
    BigInteger operator / (BigInteger & b);
    BigInteger operator / (int b);
};
//����<<
ostream& operator << (ostream &out,const BigInteger& x) {
    if(x.flag == -1)out << '-';
    out << x.s.back();
    for(int i = x.s.size() - 2; i >= 0;i--){
        char buf[20];
        sprintf(buf,"%08d",x.s[i]);//08d�˴���8Ӧ����WIDTHһ��
        for(int j=0;j<strlen(buf);j++)out<<buf[j];
    }
    return out;
}
//��������
istream& operator >> (istream & in,BigInteger & x){
    string s;
    if(!(in>>s))return in;
    x = s;
    return in;
}
vector<int> BigInteger::add( vector<int> &A, vector<int> &B){
    if(A.size() < B.size())return add(B,A);
    int t = 0;
    vector<int> C;
    for(int i=0;i<A.size();i++){
        if(i<B.size())t += B[i];
        t += A[i];
        C.push_back(t%BASE);
        t /= BASE;
    }
    if(t)C.push_back(t);
    while(C.size() > 1 && C.back() == 0)C.pop_back();
    return C;
}
vector<int> BigInteger::sub( vector<int> &A, vector<int> &B){
    vector<int> C;
    for(int i=0,t=0;i<A.size();i++){
        t = A[i] - t;
        if(i<B.size())t -= B[i];
        C.push_back((t+BASE)%BASE);
        if(t < 0)t = 1;
        else t = 0;
    }
    while(C.size() > 1 && C.back() == 0)C.pop_back();
    return C;
}
vector<int> BigInteger::mul(vector<int> &A,int b){
    vector<int> C;
    int t = 0;
    for(int i = 0;i < A.size() || t; i++){
        if(i < A.size()) t += A[i] * b;
        C.push_back(t%BASE);
        t /= BASE;
    }
    return C;
}
//�����˴����˷���Ҫ��BASE����Ϊ10��WIDTH����Ϊ1
vector<int> BigInteger::mul( vector<int> &A, vector<int> &B) {
    int la = A.size(),lb = B.size();
    vector<int> C(la+lb+10,0);
    for(int i=0;i<la;i++){
        for(int j=0;j<lb;j++){
            C[i+j] += A[i] * B[j];
        }
    }
    for(int i=0;i<C.size();i++){
        if(C[i] >= BASE){
            C[i + 1] += C[i] / BASE;
            C[i] %= BASE;
        }
    }
    while(C.size() > 1 && C.back() == 0)C.pop_back();
    return C;
}
//������������
vector<int> BigInteger::div(vector<int> & A,int b){
    vector<int> C;
    int r = 0;
    for(int i = A.size() - 1;i >= 0;i--){
        r = r * 10 + A[i];
        C.push_back(r/b);
        r %= b;
    }
    reverse(C.begin(),C.end());
    while(C.size() > 1 && C.back() == 0)C.pop_back();
    return C;
}
//�������Դ���
vector<int> BigInteger::div(vector<int> A,vector<int> B){
    int la = A.size(),lb = B.size();
    int dv = la - lb; // ���λ��
    vector<int> C(dv+1,0);
    //����������ʹ�ó����ͱ�����λ�����
    reverse(B.begin(),B.end());
    for(int i=0;i<dv;i++)B.push_back(0);
    reverse(B.begin(),B.end());
    lb = la;
    for(int j=0;j<=dv;j++){
        while(!cmp(A,B)){
            A = sub(A,B);
            C[dv-j]++;
        }
        B.erase(B.begin());
    }
    while(C.size()>1 && C.back() == 0)C.pop_back();
    return C;
}
BigInteger BigInteger::operator + ( BigInteger & b){
    BigInteger c;
    c.s.clear();
    c.s = add(s,b.s);
    return c;
}
 
BigInteger BigInteger::operator - ( BigInteger & b) {
    BigInteger c;
    c.s.clear();
    if(*this < b){
        c.flag = -1;
        c.s = sub(b.s,s);
    }
    else{
        c.flag = 1;
        c.s = sub(s,b.s);
    }
    return  c;
}
BigInteger BigInteger::operator *(BigInteger & b){
    BigInteger c;
    c.s = mul(s,b.s);
    return c;
}
BigInteger BigInteger::operator *(int& b){
    BigInteger c;
    c.s = mul(s,b);
    return c;
}
BigInteger BigInteger::operator /(BigInteger & b){
    BigInteger c;
    if(*this < b){
        c.s.push_back(0);
    }
    else{
        c.flag = 1;
        c.s = div(s,b.s);
    }
    return c;
}
BigInteger BigInteger::operator /(int b){
    BigInteger c;
    BigInteger t = b;
    if(*this < t){
        c.s.push_back(0);
    }
    else{
        c.flag = 1;
        c.s = div(s,b);
    }
    return c;
}
int main(){
    BigInteger A,B;
    cin>>A>>B;
    cout<<A-B<<endl;
    return 0;
}
