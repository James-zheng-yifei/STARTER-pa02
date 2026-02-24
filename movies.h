#ifndef MOVIES_H
#define MOVIES_H

#include <string>
#include <vector>
#include <utility>

class Movies {
    private:
        std::vector<std::pair<std::string, double>> movies;
    public:
        void insert(const std::string &name, double rate);
        void sortMovies();
        void printMoviesInOrder() const;
        void printTheBestMoviesWithPrefix(const std::string &prefix) const;
};

#endif