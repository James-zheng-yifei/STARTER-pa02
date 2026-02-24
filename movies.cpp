#include "movies.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;

void Movies::insert(const string &name, double rate) {
    movies.emplace_back(name, rate);
}


void Movies::sortMovies() {
    sort(movies.begin(), movies.end());
}


void Movies::printMoviesInOrder() const {
    for(const auto &a : movies) {
        cout << a.first << ", " << fixed << setprecision(1) << a.second << endl;
    }
}


void Movies::printTheBestMoviesWithPrefix(const string &prefix) const {
    vector<pair<string, double>> temp{};
    for(const auto &a : movies) {
        if(a.first.substr(0, prefix.length()) == prefix) {
            temp.push_back(a);
            cout << a.first << ", " << fixed << setprecision(1) << a.second << endl;
        }
    }
    cout << endl;
    if(temp.empty()) {
        cout << "No movies found with prefix " << prefix << endl;
        return;
    }
    pair<string, double> bestMovie = temp[0];
    for(const auto &p : temp) {
        if(p.second > bestMovie.second) bestMovie = p;
    }
    cout << "Best movie with prefix " << prefix << "is: " << bestMovie.first << " with rating " << bestMovie.second << endl;
}