#include<bits/stdc++.h>
using namespace std;

string trans_cipher(string str, int txt_sz, int width){
    string new_str;
    int i,j,k,len;

    for(i=0;i<width;i++){
        for(j=i;j<txt_sz;j+=width){
            if(isupper(str[j])){
                 new_str+=(str[j]-'A')+'A';
            }
            else if(islower(str[j])){
                new_str+=(str[j]-'a')+'a';
            }
            else
                new_str+=str[j];
           
        }
    }
    return new_str;
    
}
int main(){
    freopen("transposition.txt","r",stdin);
    string p_txt,trans_c_txt;
    getline(cin,p_txt);
    int width,txt_sz;
    cin>>width;
    txt_sz = p_txt.size();
    cout<<"Plain text is:\n";
    cout<<p_txt<<endl;
    cout<<"width: ";
    cout<<txt_sz<<endl;
    trans_c_txt = trans_cipher(p_txt,txt_sz,width);
    cout<<"transposition cipher is : ";
    cout<<trans_c_txt;
}