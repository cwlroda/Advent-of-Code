#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void test(vector<int> v);

int main(int argc, char** argv){
    ifstream infile;
    vector<int> v;
    string n;

    infile.open(argv[1]);

    while(infile >> n){
        v.push_back(stoi(n));
    }

    infile.close();

    test(v);

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

void test(vector<int> v){
    for(int i=0; i<v.size(); i++){
        if(v[i] == 99){
            break;
        }

        int ten = v[i]%10;
        int hundred = (v[i]/100)%10;
        int thousand = (v[i]/1000)%10;
        int tenk = (v[i]/10000)%10;
        int one, two, three;

        if(hundred){
            one = v[i+1];
        }

        else{
            one = v[v[i+1]];
        }

        if(thousand){
            two = v[i+2];
        }

        else{
            two = v[v[i+2]];
        }

        if(ten == 1){
            v[v[i+3]] = one + two;
            i+=3;
        }

        else if(ten == 2){
            v[v[i+3]] = one * two;
            i+=3;
        }

        else if(ten == 3){
            int n;
            cin >> n;
            v[v[i+1]] = n;
            i++;
        }

        else if(ten == 4){
            if(hundred){
                cout << v[i+1];
            }

            else{
                cout << v[v[i+1]] << endl;
            }

            i++;
        }

        else if(ten == 5){
            if(one != 0){
                i = two-1;
                continue;
            }

            else{
                i+=2;
            }
        }

        else if(ten == 6){
            if(one == 0){
                i = two-1;
                continue;
            }

            else{
                i+=2;
            }
        }

        else if(ten == 7){
            if(one < two){
                v[v[i+3]] = 1;
            }

            else{
                v[v[i+3]] = 0;
            }

            i+=3;
        }

        else if(ten == 8){
            if(one == two){
                v[v[i+3]] = 1;
            }

            else{
                v[v[i+3]] = 0;
            }

            i+=3;
        }
    }
}