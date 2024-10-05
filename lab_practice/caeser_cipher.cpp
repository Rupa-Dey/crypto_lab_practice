#include<bits/stdc++.h>
using namespace std;

string encryptCaeser(string str, int n){
    int mod_n;
    string new_str;

    for(auto ch: str){
        if(isupper(ch))
            new_str+=((ch+n-'A')%26 + 'A');
        else if(islower(ch))
            new_str+=((ch+n-'a')%26 + 'a');
        else 
            new_str+=ch;
    }

    return new_str;
}

string decryptCaeser(string str, int n){
    int mod_n;
    string new_str;

    for(auto ch: str){
        if(isupper(ch))
            new_str+=((ch-n+26)-'A')%26 + 'A';
        else if(islower(ch))
            new_str+=((ch-n+26)-'a')%26 + 'a';
        else 
            new_str+=ch;
    }

    return new_str;
}

int main(){
    freopen("caeser.txt","r",stdin);

    string p_txt,c_txt,d_txt;
    getline(cin,p_txt);

    int sft;
    cin>>sft;
   
    

   cout<<"---------encryption----"<<endl;
    cout<<p_txt<<endl;
    c_txt = encryptCaeser(p_txt,sft);
    cout<<"The ciphertext of caeser is: ";
    cout<<c_txt<<endl;

    cout<<"-------decryption-------"<<endl;
    d_txt = decryptCaeser(c_txt,sft);
    cout<<"The deciphertext is : ";
    cout<<d_txt;
}