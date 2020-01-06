#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    int count = 1;

    for(int i=108457; i<562042; i++){
        vector<int> counter;
        count = 1;

        int one = i%10;
        int two = (i/10)%10;
        int three = (i/100)%10;
        int four = (i/1000)%10;
        int five = (i/10000)%10;
        int six = (i/100000)%10;

        if(one < two || two < three || three < four || four < five || five < six){
            continue;
        }

        if(one == two){
            count++;
        }

        else{
            counter.push_back(count);
            count = 1;
        }

        if(two == three){
            count++;
        }

        else{
            counter.push_back(count);
            count = 1;
        }

        if(three == four){
            count++;
        }

        else{
            counter.push_back(count);
            count = 1;
        }

        if(four == five){
            count++;
        }

        else{
            counter.push_back(count);
            count = 1;
        }

        if(five == six){
            count++;
        }

        else{
            counter.push_back(count);
            count = 1;
        }

        counter.push_back(count);

        for(int j=0; j<counter.size(); j++){
            if(counter[j] == 2){
                v.push_back(i);
                cout << i << endl;
                break;
            }
        }
    }

    cout << v.size() << endl;

    return 0;
}