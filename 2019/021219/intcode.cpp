#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int test(vector<int> v, int noun, int verb);

int main(int argc, char** argv){
    ifstream infile;
    vector<int> v;
    string n;

    infile.open(argv[1]);

    while(infile >> n){
        v.push_back(stoi(n));
    }

    infile.close();

    for(int noun=0; noun<100; noun++){
        for(int verb=0; verb<100; verb++){
            if(test(v, noun, verb) == 19690720){
                cout << 100*noun+verb << endl;
                return 0;
            }
        }
    }

    /* for(int i=0; i<v.size(); i++){
        if(i%4 == 0){
            cout << endl;
        }

        cout << v[i] << ", ";

        if(v[i] == 99){
            cout << endl;
        }
    } */

    return 0;
}

int test(vector<int> v, int noun, int verb){
    v[1] = noun;
    v[2] = verb;

    for(int i=0; i<v.size(); i+=4){
        if(v[i] == 1){
            v[v[i+3]] = v[v[i+1]] + v[v[i+2]];
        }

        else if(v[i] == 2){
            v[v[i+3]] = v[v[i+1]] * v[v[i+2]];
        }

        else if(v[i] == 99){
            break;
        }
    }

    return v[0];
}