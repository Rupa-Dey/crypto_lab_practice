#include<bits/stdc++.h>
using namespace std;

string trans_cipher(string str, int txt_sz, int width){
    string new_str;
    int i,j,k;

    for(i=0;i<width;i++){
        for(j=i;j<txt_sz;j+=width){
            // if(isupper(str[j])){
            //      new_str+=(str[j]-'A')+'A';
            // }
            // else if(islower(str[j])){
            //     new_str+=(str[j]-'a')+'a';
            // }
            // else
                new_str+=str[j];
           
        }
    }
    return new_str;
    
}

string trans_decipher(string txt,int n, int w){
   int i,j,k,len;

    string txt2="";
   k = n/w;
   //  len hocche column songkha for decryption
   if(n%w==0) len = k;
   else len = k + 1;

    txt2+=txt[0];
    for(i=1;i<len;i++) {  
      for(j=i;j<txt.size()-k;j+= k){
          txt2+=txt[j+ k];   
      }
     txt2+= txt[i];  
    }
    return txt2;
    
}

int main(){
    freopen("transposition.txt","r",stdin);
    string p_txt,trans_c_txt,trans_d_txt;
    getline(cin,p_txt);
    int width,txt_sz;
    cin>>width;
    txt_sz = p_txt.size();

    cout<<"------encryption-----"<<endl;
    cout<<"Plain text is:\n";
    cout<<p_txt<<endl;
    cout<<"width: ";
    cout<<txt_sz<<endl;
    trans_c_txt = trans_cipher(p_txt,txt_sz,width);
    cout<<"transposition cipher is : ";
    cout<<trans_c_txt<<endl;

     trans_d_txt = trans_decipher(trans_c_txt,txt_sz,width);
     cout<<"transposition Decipher is : ";
    cout<<trans_d_txt<<endl;


}