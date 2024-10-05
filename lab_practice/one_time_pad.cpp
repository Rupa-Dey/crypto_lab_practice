#include<bits/stdc++.h>
using namespace std;

string encrypt_oneTimePad(string m, string s){
    string new_str;
    int i,j;

    for(i=0;i<m.size();i++){
        if(isupper(m[i])){
            new_str+= (((m[i]-'A')+(s[i]-'A'))%26) + 'A';
        }
        else if(islower(m[i]))
        {
             new_str+= (((m[i]-'a')+ (s[i])-'a')%26) + 'a';
        }
        else 
        new_str+=m[i];
    }
    return new_str;
}

string decrypt_oneTimePad(string m, string s){
     string new_str;
    int i,j;

    for(i=0;i<m.size();i++){
        if(isupper(m[i])){
            new_str+= (((m[i]-'A')-(s[i]-'A'))+26)%26 + 'A';
        }
        else if(islower(m[i]))
        {
             new_str+= (((m[i]-'a')-(s[i])-'a')+26)%26 + 'a';
        }
        else 
        new_str+=m[i];
    }
    return new_str;

}


int main(){
    freopen("otp.txt","r",stdin);
    string msg,sec_key,otp_cipher,otp_dcipher;
    getline(cin,msg);
    getline(cin,sec_key);

    cout<<"--------encryption-----"<<endl;
    cout<<"original text is : ";
    cout<<msg<<endl;
    cout<<"secret key is: ";
    cout<<sec_key<<endl;
    otp_cipher = encrypt_oneTimePad(msg,sec_key);
    cout<<"one time pad cipher is : ";
    cout<<otp_cipher<<endl;

    cout<<"--------decryption--------"<<endl;
    otp_dcipher = decrypt_oneTimePad(otp_cipher,sec_key);
    cout<<"one time pad decipher is : ";
    cout<<otp_dcipher<<endl;


}