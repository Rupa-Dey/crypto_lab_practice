//Rupa Dey

#include<bits/stdc++.h>
typedef long long  ll;
using namespace std;

ll modExp(ll base, ll exp, ll mod){
    ll res = 1;
    while(exp>0){
        if(exp%2==1) res = (res*base)%mod;
        exp/=2;
        base= (base*base)%mod;
    }
    return res;
}

vector<ll>splitmsgblk(string msg, int blk_size){
    int i;
    vector<ll>blocks;
    string blk;
    for(i=0;i<msg.length();i+=blk_size){
        blk = msg.substr(i,blk_size);
        blocks.push_back(stoll(blk));  //string to ll
    }
    return blocks;
}


int main(){
    ll n,e,d;
    n = 3337;
    e = 79;
    d = 1019;
    string msg = "6882326879666683";

    int blk_sz = to_string(n).length()-1;
    vector<ll>en_blk,dec_blk,msg_blk;

    msg_blk = splitmsgblk(msg,blk_sz);

    cout<<"original msg block: ";
    for(auto m:msg_blk){
        cout<<m<<" ";
    }
    cout<<endl;
    
    ll en_msg,dec_msg;
    for (auto m:msg_blk){
        en_msg = modExp(m,e,n);
        en_blk.push_back(en_msg);
    }

    cout<<"encrypt msg block: ";
    for(auto cipher:en_blk){
        cout<<cipher<<" ";
    }
    cout<<endl;
    for(auto c:en_blk){
        dec_msg = modExp(c,d,n);
        dec_blk.push_back(dec_msg);
    }

     cout<<"decrypt msg block: ";
    for(auto dcipher:dec_blk){
        cout<<dcipher<<" ";
    }
}