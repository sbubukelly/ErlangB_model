#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <random>

using namespace std;

bool arrival(float lambda){
    srand(time(NULL));
    float x = (float) rand() / (RAND_MAX + 1.0);
    printf("x = %f\n", x);
    float prob_a = 1 - exp(-lambda);
    cout<<prob_a<<endl;
    //if the random num x smaller than prob_a
    //then it means the customer arrive
    //if bigger it means the customer didnt arrive
    if(x<=prob_a)
        return true;
    else 
        return false;
}

bool departure(float mu){
    srand(time(NULL));
    float x = (float) rand() / (RAND_MAX + 1.0);       
    printf("x = %f\n", x);
    float prob_d = 1 - exp(-mu);
    cout<<prob_d<<endl;
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
    static int systemT = 100000;
    static int simulationT = 10;
    int server = 1;     //init value 
    float lambda = 0.01;    //init value
    float mu = 0.01     //init value

    /********
    float lambda = 1;
    bool test = arrival(lambda);
    cout<<test<<endl;
    *********/
}