#include<bits/stdc++.h>
using namespace std;
map<string,string>e_txt,d_txt;

string encipher_polygram(string p_txt){
    string tmp,new_str;
    int i,j,k=0;
    for(i=0;i<p_txt.size();i++){
        if(p_txt[i]==' '){
            new_str+=' ';
            continue;
        }
        tmp+=p_txt[i];
        k++;

        if(k%3==0){
            if(e_txt.find(tmp)!=e_txt.end())
               new_str+=e_txt[tmp];
            else 
               new_str+=tmp;
            tmp="";
            k=0;
        }
    }
    if(k!=3){
       if(e_txt.find(tmp)!=e_txt.end())
           new_str+=e_txt[tmp];
        else 
            new_str+=tmp;
    }
    return new_str;
}

string decipher_polygram(string str){
    string tmp,new_str;
    int i,j,k=0;
    for(i=0;i<str.size();i++){
        if(str[i]==' '){
            new_str+=' ';
            continue;
        }
        tmp+=str[i];
        k++;

        if(k%3==0){
            if(d_txt.find(tmp)!=d_txt.end())
               new_str+=d_txt[tmp];
            else 
               new_str+=tmp;
            tmp="";
            k=0;
        }
    }
    if(k!=3){
       if(d_txt.find(tmp)!=d_txt.end())
           new_str+=d_txt[tmp];
        else 
            new_str+=tmp;
    }
    return new_str;
}


int main(){
    freopen("polygram.txt","r", stdin);
    string p_txt,str1,str2,c_txt,dec_txt;
    getline(cin,p_txt);
    cin.clear();
    freopen("dict.txt","r",stdin);
    
    while(cin>>str1>>str2){
        e_txt[str1] = str2;
        d_txt[str2] = str1;
    }

    cout<<"------------encryption msg--------"<<endl;
    c_txt = encipher_polygram(p_txt);
    cout<<"Plian Text : ";
    cout<<p_txt<<endl;
    cout<<"polygram_Cipher_text is : ";
    cout<<c_txt<<endl;

    cout<<"----------------decryption msg---------"<<endl;
    dec_txt = decipher_polygram(c_txt);
    cout<<"polygram_Decipher_text is : ";
    cout<<dec_txt<<endl;


}