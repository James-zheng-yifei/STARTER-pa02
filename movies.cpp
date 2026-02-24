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
    auto it = lower_bound(
    movies.begin(),
    movies.end(),
    prefix,
    [](const pair<string,double>& movie, const string& pref){
        return movie.first < pref;
    });
    if(it == movies.end() || !(it->first.starts_with(prefix))) {
        cout << "No movies found with prefix " << prefix << endl;
        return;
    }
    const double* best = &(it->second);
    const string* bestName = &(it->first);
    while(it != movies.end() && it->first.starts_with(prefix)) {
        cout << it->first << ", " << fixed << setprecision(1) << it->second << endl;
        if(it->second > *best) {
            best = &(it->second);
            bestName = &(it->first);
        }
        it++;
    }
    cout << '\n';
    cout << "Best movie with prefix " << prefix << " is: " << *bestName << " with rating " << *best;
}