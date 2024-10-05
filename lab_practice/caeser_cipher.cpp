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

int main(){
    freopen("caeser.txt","r",stdin);

    string p_txt,c_txt;
    getline(cin,p_txt);

    int sft;
    cin>>sft;
   
    cout<<p_txt<<endl;
    cout<<sft<<endl;

    c_txt = encryptCaeser(p_txt,sft);
    cout<<"The ciphertext of caeser is: ";
    cout<<c_txt;
}