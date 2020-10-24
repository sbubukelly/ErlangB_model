#include <iostream>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <random>

using namespace std;

float delta = 0.4;

bool arrival(float lambda){
    //srand(time(NULL));
    float x = (float) rand() / (RAND_MAX + 1.0);
    float prob_a = 1 - exp(-(lambda*delta));
    //if the random num x smaller than prob_a
    //then it means the customer arrive
    //if bigger it means the customer didnt arrive
    if(x<=prob_a)
        return true;
    else 
        return false;
}

bool departure(float mu,int i){
    //srand(time(NULL));
    float x = (float) rand() / (RAND_MAX + 1.0);   
    float prob_d = 1 - exp(-(i*delta*mu));
    //if the random num x smallerr than prob_d
    //then it means the customer depart
    //if bigger it means the customer didnt arrive
    if(x<=prob_d)
        return true;
    else 
        return false;
}

int main()
{
    srand(time(NULL));
    static int systemT = 100000;
    static int simulationT = 10;
    int server = 1;     //init value
    int Q = 0; 
    float lambda = 0.01;    //init value
    float mu = 0.01;     //init value

    float arrival_count[24] ={};
    float departure_count[24] = {};
    float ppInServer[24] = {};
    float block_count[24] = {};
    float bp[24] = {};

    for(int i = 0;i < 24;i ++){
        arrival_count[i] = 0;
        departure_count[i] = 0;
        ppInServer[i] = 0;
        block_count[i] = 0;
        bp[i] = 0;
    }
    int count = 0;
    //S=1,Q = 0
    for(float i = lambda;i <= 10;i *= 10 ){
        //cout<<i<<endl;
        for(float j = mu;j <= 10.24;j *= 4){
            //cout<<j<<endl;
            for(int k = 0;k < simulationT;k ++){
                //cout<<k<<endl;
                for(int l = 0;l < systemT;l ++){
                    if(arrival(i)){
                        //cout<<"++"<<endl;
                        arrival_count[count] ++;
                        if(ppInServer[count] >= server){
                            block_count[count] ++;
                        }
                        else{
                            ppInServer[count] ++;
                        }
                    }
                    if(ppInServer[count] > 0){
                        if(departure(j,ppInServer[count])){
                            ppInServer[count] --;
                        }
                    }
                }
            }
            //cout<<arrival_count[count]<<" "<<block_count[count]<<endl;
            bp[count] = block_count[count]/arrival_count[count];
            //cout<<endl<<bp[count]<<endl;
            count ++;
        }
    }
    
    
    fstream file;
    file.open("Output1.csv", ios::out);
    if(!file)     //檢查檔案是否成功開啟，如果!file為真，表示無法開啟檔案
    {
        cerr << "Can't open file!\n";
        exit(1);     //在不正常情形下，中斷程式的執行

    }
    for(int i = 0;i < 24;i ++){
            file<<i<<","<<bp[i]<<"\n";
    }
    
    file.close();
    /********
    float lambda = 1;
    bool test = arrival(lambda);
    cout<<test<<endl;
    *********/
}