#include "Movies.h"
#include <iostream>


Movies::Movies(){

}

Movies::Movies(const std::vector<Movie> & movies_collection)
    : movies_collection{movies_collection}{

    }

void Movies::add_movie(const std::string &movie_name, Movie::MOVIE_RATING movie_rating, int watched){
    
    for(Movie curr : movies_collection){
        if(curr.getMovieName() == movie_name){
            std::cout << "Movie Name already exists" << std::endl;
            return;
        }
    }

    Movie new_movie = Movie(movie_name, movie_rating, watched);
    movies_collection.push_back(new_movie);
}    

void Movies:: display_movies() const{
    if(movies_collection.size() == 0){
        std:: cout <<  "Sory no movies to display" << std::endl;
        return;
    }

    for(Movie curr : movies_collection){
        curr.display_movie();
    }
}


void Movies::watchedMovie(const std::string & movie_name){
    int length = movies_collection.size();
    for(int i = 0 ; i < length ; i++){
        Movie &curr = movies_collection.at(i);
        if(movie_name == curr.getMovieName()){
            curr.add_watch();
            return;
        }
    }
    std:: cout <<  "Movie name not exists in the list of movies" << std::endl;
}