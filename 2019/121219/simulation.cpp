#include <iostream>
#include <unordered_map>
using namespace std;

#define steps 1000
#define sig 4
#define coord 3
#define type 2
#define interval 100

bool x_equal(int arr1[sig][coord], int arr2[sig][coord]);
bool y_equal(int arr1[sig][coord], int arr2[sig][coord]);
bool z_equal(int arr1[sig][coord], int arr2[sig][coord]);

long long get_gcd(long long a, long long b);
long long get_lcm(int arr[], int n);

int main(int argc, char** argv){
    int pos[sig][coord] = {{-4, 3, 15}, {-11, -10, 13}, {2, 2, 18}, {7, -1, 0}};
    int origpos[sig][coord] = {{-4, 3, 15}, {-11, -10, 13}, {2, 2, 18}, {7, -1, 0}};
    // {{-1, 0, 2}, {2, -10, -7}, {4, -8, 8}, {3, 5, -1}};
    // {{-8, -10, 0}, {5, 5, 10}, {2, -7, 3}, {9, -8, -3}};
    // {{-4, 3, 15}, {-11, -10, 13}, {2, 2, 18}, {7, -1, 0}};
    int vel[sig][coord] = {0};
    int origvel[sig][coord] = {0};
    int energy[sig][type] = {0};
    int total[sig] = {0};
    int period[coord] = {0};
    int count=0;
    bool x=false, y=false, z=false;

    /*for(int i=0; i<=steps; i++){
        if(i%interval == 0){
            cout << "After " << i << " steps:" << endl;

            for(int j=0; j<sig; j++){
                cout << "pos=<x=" << pos[j][0] << ", y=" << pos[j][1] << ", z=" << pos[j][2] << ">, vel=<x=" << vel[j][0] << ", y=" << vel[j][1] << ", z=" << vel[j][2] << endl;
            }

            cout << endl;
        }

        if(i == steps){
            break;
        }*/
    do{
        for(int j=0; j<sig; j++){
            for(int k=j+1; k<sig; k++){
                for(int l=0; l<coord; l++){
                    if(pos[j][l] < pos[k][l]){
                        vel[j][l]++;
                        vel[k][l]--;
                    }

                    else if(pos[j][l] > pos[k][l]){
                        vel[j][l]--;
                        vel[k][l]++;
                    }
                }
            }
        }

        for(int j=0; j<sig; j++){
            for(int k=0; k<coord; k++){
                pos[j][k] += vel[j][k];
            }
        }

        count++;

        if(x_equal(pos, origpos) && x_equal(vel, origvel) && !x){
            period[0] = count;
            x = true;
        }

        if(y_equal(pos, origpos) && y_equal(vel, origvel) && !y){
            period[1] = count;
            y = true;
        }

        if(z_equal(pos, origpos) && z_equal(vel, origvel) && !z){
            period[2] = count;
            z = true;
        }
    } while(!x || !y || !z);

    /* cout << "Energy after " << steps << " steps:" << endl;

    for(int i=0; i<sig; i++){
        cout << "pot: ";

        for(int j=0; j<coord; j++){
            energy[i][0] += abs(pos[i][j]);
            cout << abs(pos[i][j]);

            if(j == coord-1){
                cout << " = ";
            }

            else{
                cout << " + ";
            }
        }

        cout << energy[i][0] << "; ";
        cout << "kin: ";

        for(int j=0; j<coord; j++){
            energy[i][1] += abs(vel[i][j]);
            cout << abs(vel[i][j]);

            if(j == coord-1){
                cout << " = ";
            }

            else{
                cout << " + ";
            }
        }

        cout << energy[i][1] << "; ";
        cout << "total: " << energy[i][0] << " * " << energy[i][1] << " = " << energy[i][0]*energy[i][1] << endl;

        total[i] = energy[i][0]*energy[i][1];
    }

    int sum=0;
    cout << endl << "Sum of total energy: ";

    for(int i=0; i<sig; i++){
        cout << total[i];

        if(i == sig-1){
            cout << " = ";
        }

        else{
            cout << " + ";
        }

        sum += total[i];
    }

    cout << sum << endl << endl;*/
    cout << "x repeats after " << period[0] << " steps" << endl;
    cout << "y repeats after " << period[1] << " steps" << endl;
    cout << "z repeats after " << period[2] << " steps" << endl;
    cout << "Duplicate state found after " << get_lcm(period, coord) << " steps" << endl << endl;

    return 0;
}

bool x_equal(int arr1[sig][coord], int arr2[sig][coord]){
    for(int i=0; i<sig; i++){
        if(arr1[i][0] != arr2[i][0]){
            return false;
        }
    }

    return true;
}

bool y_equal(int arr1[sig][coord], int arr2[sig][coord]){
    for(int i=0; i<sig; i++){
        if(arr1[i][1] != arr2[i][1]){
            return false;
        }
    }

    return true;
}

bool z_equal(int arr1[sig][coord], int arr2[sig][coord]){
    for(int i=0; i<sig; i++){
        if(arr1[i][2] != arr2[i][2]){
            return false;
        }
    }

    return true;
}

long long get_gcd(long long a, long long b){
    if(b == 0)
        return a;
    return get_gcd(b, a % b);
}

// Returns LCM of array elements
long long get_lcm(int arr[], int n){
    // Initialize result
    long long ans = arr[0];

    // ans contains LCM of arr[0], ..arr[i]
    // after i'th iteration,
    for(int i=1; i<n; i++)
        ans = (((arr[i] * ans)) / (get_gcd(arr[i], ans)));

    return ans;
}