//Yifei Zheng

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

pair<vector<pair<string,double>>::const_iterator,
     vector<pair<string,double>>::const_iterator>
Movies::getPrefixRange(const string& prefix) const {

    auto start = lower_bound(
        movies.begin(),
        movies.end(),
        prefix,
        [](const pair<string,double>& movie, const string& pref){
            return movie.first < pref;
        });

    if(start == movies.end() || !start->first.starts_with(prefix)) {
        return {movies.end(), movies.end()};
    }

    auto end = start;
    while(end != movies.end() && end->first.starts_with(prefix)) {
        ++end;
    }

    return {start, end};
}
/*pair<vector<pair<string,double>>::const_iterator,
     vector<pair<string,double>>::const_iterator>
Movies::getPrefixRange(const string& prefix) const {

	auto start = lower_bound(movies.begin(), movies.end(), prefix,
		[](const auto& a,const string& pref){
			return a.first<pref;
		});
    
    if (start == movies.end() || !start->first.starts_with(prefix)) {
        return {movies.end(), movies.end()};
    }

    auto end = std::upper_bound(start, movies.end(), prefix,
        [](const string& pref, const auto& a) {
            return !a.first.starts_with(pref);
        });

    return {start, end};
}*/

vector<pair<string,double>>
Movies::getPrefixMovies(const string& prefix) const {

    auto [start, end] = getPrefixRange(prefix);

    if(start == movies.end()) {
        return {};
    }

    vector<pair<string,double>> matched(start, end);

    sort(matched.begin(), matched.end(),
         [](const pair<string,double>& a,
            const pair<string,double>& b){
                if(a.second == b.second) return a.first < b.first;
                return a.second > b.second;
         });

    return matched;
}

optional<pair<string,double>>
Movies::getBestMovieWithPrefix(const string& prefix) const {

    auto [start, end] = getPrefixRange(prefix);

    if(start == movies.end()) {
        return nullopt;
    }

    auto best = max_element(start, end,
        [](const pair<string,double>& a,
           const pair<string,double>& b){
            return a.second < b.second;
        });

    return *best;
}