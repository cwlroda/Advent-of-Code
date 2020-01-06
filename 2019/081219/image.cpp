#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char** argv){
    ifstream infile;
    infile.open(argv[1]);

    vector<vector<char> > image;
    vector<char> layer;
    string c;
    int fewest=1000000, mult=0;

    infile >> c;

    for(int i=0; i<c.size(); i++){
        layer.push_back(c[i]);

        if(layer.size() == 150){
            image.push_back(layer);
            layer.erase(layer.begin(), layer.end());
        }
    }

    infile.close();

    for(int i=0; i<image.size(); i++){
        int zero=0, one=0, two=0;
        cout  << "Layer " << i+1 << ":" << endl;

        for(int j=0; j<image[i].size(); j++){
            cout << image[i][j];

            if(j>0 && ((j+1)%25 == 0)){
                cout << endl;
            }

            if(image[i][j] == '0'){
                zero++;
            }

            else if(image[i][j] == '1'){
                one++;
            }

            else if(image[i][j] == '2'){
                two++;
            }
        }

        if(zero < fewest){
            fewest = zero;
            mult = one*two;
        }

        cout << endl;
    }

    cout << "Value is: " << mult << endl << endl;

    vector<char> final;

    for(int i=0; i<image[0].size(); i++){
        for(int j=0; j<image.size(); j++){
            if(image[j][i] == '0'){
                final.push_back(' ');
                break;
            }

            else if(image[j][i] == '1'){
                final.push_back('.');
                break;
            }

            else if(image[j][i] == '2'){
                continue;
            }
        }
    }

    for(int i=0; i<final.size(); i++){
        cout << final[i];

        if(i>0 && ((i+1)%25 == 0)){
            cout << endl;
        }
    }

    cout << endl;

    return 0;
}

