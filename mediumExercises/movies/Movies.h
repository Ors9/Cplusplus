#ifndef MOVIES_H
#define MOVIES_H

#include "Movie.h"
#include <vector>


class Movies{

    private:
        std::vector<Movie> movies_collection;

    public:
        Movies();
        Movies(const std::vector<Movie> & movies_collection);
        void add_movie(const std::string &movie_name, Movie::MOVIE_RATING movie_rating, int watched);
        void display_movies() const;
        void watchedMovie(const std::string & movie_name);
};


#endif // MOVIES_H