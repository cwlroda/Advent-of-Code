#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int calc_fuel(int fuel);

int main(int argc, char** argv){
    ifstream infile;
    int n, total=0;

    infile.open(argv[1]);

    while(infile >> n){
        total += calc_fuel(n);
    }

    cout << total << endl << endl;

    return 0;
}

int calc_fuel(int fuel){
    int required = floor(fuel/3)-2;

    if(required <= 0){
        return 0;
    }

    else{
        return required + calc_fuel(required);
    }
}