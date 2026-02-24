//Yifei Zheng

#ifndef MOVIES_H
#define MOVIES_H

#include <string>
#include <vector>
#include <utility>
#include <optional>
#include <algorithm>

class Movies {
    private:
        std::vector<std::pair<std::string, double>> movies;
        std::pair<std::vector<std::pair<std::string,double>>::const_iterator,std::vector<std::pair<std::string,double>>::const_iterator> getPrefixRange(const std::string& prefix) const;
    public:
        void insert(const std::string &name, double rate);
        void sortMovies();
        void printMoviesInOrder() const;
        std::vector<std::pair<std::string,double>> getPrefixMovies(const std::string& prefix) const;
        std::optional<std::pair<std::string,double>> getBestMovieWithPrefix(const std::string& prefix) const;
};

#endif