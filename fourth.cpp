#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

// No docs (obv)
// Data In file will be stored like so:
// Contry,City,Living Conditions,Travel Conditions,Excrusions,Host service,Price
// No spaces in separators.



struct TourAgency{
    string country;
    string city;
    string living_conditions;
    string travel_conditions;
    string excursion_services;
    string host_services;
};

TourAgency Split(string str){
    size_t position = 0;
    TourAgency result;
    for(int i = 0;(position = str.find(",")) != string::npos; i++){
        switch(i){
            case 0:
                result.country = str.substr(0, position);
                
            case 1:
                result.city = str.substr(0, position);
            case 2:
                result.living_conditions = str.substr(0, position);
            case 3:
                result.travel_conditions = str.substr(0, position);
            case 4:
                result.excursion_services = str.substr(0, position);
            case 5:
                result.host_services = str.substr(0, position);
            default:
                cout << "More commas than expected. Data is corrupt";
        }
        str.erase(0, position + 1);
    }
    return result;
}

void SplittingPhase(){
    ifstream A("a.txt");
    ofstream B("b.txt");
    ofstream C("c.txt");
    string input;
    bool TflipFlop;
    while(A >> input){
        if(TflipFlop)
            B << input;
        else
            C << input;
        TflipFlop = !TflipFlop;
    }
    A.close();
    B.close();
    C.close();
}

int main(){
    SplittingPhase();

    ofstream A("a.txt");
    ifstream B("b.txt");
    ifstream C("c.txt");
    string b = "", c = "";
    while(B>>b && C>>c){
        TourAgency fromB = Split(b);
        TourAgency fromC = Split(c);
    }
}