CXX = g++
CXXFLAGS = -Wall -std=c++11

# הקבצים להרצה
OBJS = main.o Movie.o Movies.o

all: movie

movie: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o movie

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o movie