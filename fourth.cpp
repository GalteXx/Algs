#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct TourAgency{
    string country;
    string city;
    string living_conditions;
    string travel_conditions;
    string excursion_services;
    string host_services;

    TourAgency(string cn, string ct, string lc, string tc, string es, string hs){
        country = cn;
        city = ct;
        living_conditions = lc;
        travel_conditions = tc;
        excursion_services = es;
        host_services = hs;
    }
};

void write_tour_agency(ofstream file, TourAgency t){
    file << t.country << ',' << t.city << ',' << t.living_conditions << ',' << t.travel_conditions
        << ',' << t.excursion_services << ',' << t.host_services << '\n';
}

vector<TourAgency> readDataFromFile(string filename) {
    vector<TourAgency> tourAgencies;
    ifstream infile(filename);
    string ln, fn, dob, g, w, h;
    while (infile >> ln >> fn >> dob >> w >> h >> g) {
        tourAgencies.push_back(TourAgency(ln, fn, dob, w, h, g));
    }
    infile.close();
    return tourAgencies;
}

void writeDataToFile(vector<TourAgency> ta, string filename) {
    ofstream outfile(filename);
    for (auto a : ta) {
        outfile << a.country << " " << a.city << " " << a.living_conditions << " "
            << a.travel_conditions << " " << a.excursion_services << " " << a.host_services << endl;
    }
    outfile.close();
}

void mergeSeries(vector<TourAgency>& series1, vector<TourAgency>& series2, vector<TourAgency>& res) {
    size_t i = 0;
    size_t j = 0;
    while (i < series1.size() && j < series2.size()) {
        if (series1[i].country <= series2[j].country) {
            res.push_back(series1[i]);
            i++;
        }
        else {
            res.push_back(series2[j]);
            j++;
        }
    }
    while (i < series1.size()) {
        res.push_back(series1[i]);
        i++;
    }
    while (j < series2.size()) {
        res.push_back(series2[j]);
        j++;
    }
}

void naturalMergeSort(string inf, string sf1, string sf2, string outf) {
    vector<TourAgency> athletes1 = readDataFromFile(sf1);
    vector<TourAgency> athletes2 = readDataFromFile(sf2);

    sort(athletes1.begin(), athletes1.end(), [](const TourAgency& a, const TourAgency& b) {
        return a.country < b.country;
        });

    sort(athletes2.begin(), athletes2.end(), [](const TourAgency& a, const TourAgency& b) {
        return a.country < b.country;
        });

    vector<TourAgency> result;
    mergeSeries(athletes1, athletes2, result);

    writeDataToFile(result, outf);
}

int main() {
    string inputFile1 = "input.txt";
    string sortFile2 = "h_sort1.txt";
    string sortFile3 = "h_sort2.txt";
    string outputFile = "output.txt";

    ifstream inputFile(inputFile1);
    ofstream sortFile2Output(sortFile2);
    ofstream sortFile3Output(sortFile3);

    string line;
    bool isFirstSeries = true;

    while (getline(inputFile, line)) {
        if (isFirstSeries) {
            sortFile2Output << line << endl;
        }
        else {
            sortFile3Output << line << endl;
        }
        isFirstSeries = !isFirstSeries;
    }

    inputFile.close();
    sortFile2Output.close();
    sortFile3Output.close();

    naturalMergeSort(inputFile1, sortFile2, sortFile3, outputFile);

    return 0;
}