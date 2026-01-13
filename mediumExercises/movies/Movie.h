#ifndef MOVIE_H
#define MOVIE_H

#include <string>



class Movie
{

public:
    enum MOVIE_RATING
    {
        G = 0,
        PG = 1,
        PG13 = 2,
        R = 3,
    };

private:
    std::string movie_name;
    MOVIE_RATING movie_rating;
    int watched;

public:
    Movie();
    Movie(const std::string & movie_name, MOVIE_RATING movie_rating, int watched);
    std::string getMovieName()const;
    void display_movie() const;
    std::string getMovieRating() const;
    void add_watch();
};


#endif //MOVIE_H