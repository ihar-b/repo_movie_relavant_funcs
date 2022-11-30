#include <iostream>
#include <string>
#include <vector>
using namespace std;


    enum type{
        ACTION = 1,
        ADVENTURE= 2,
        COMEDY= 3,
        DRAMA= 4,
        FANTASY= 5,
        HORROR= 6,
        ROMANCE = 7,
        THRILLER =8
    };
class movie{
private:
    string title;
    string comment;
    int ranking;
    int id;
    int releaseDate;
    int characterNum;
    int ticketPrice;
    type filmType;
    int day;
public:
    movie(){
        
    }
    movie( string title,
          string comment,
          int ranking,
          int id,
          int releaseDate,
          int characterNum,
          int ticketPrice,
          int day,
          type filmType){
        
        this->title= title;
        this->comment = comment;
        this->ranking=ranking;
        this->id = id;
        this->releaseDate= releaseDate;
        this->characterNum= characterNum;
        this->ticketPrice=ticketPrice;
        this->filmType=filmType;
        this->day = day;
    }
    ~movie(){
        
    }
    string getTitle(){
        return title;
    }
    string getComment(){
        return comment;
    }
    int getRanking(){
        return ranking;
    }
    int getId(){
        return id;
    }
    int getReleaseDate(){
        return releaseDate;
    }
    int getCharacterNum(){
        return characterNum;
    }
    int getTicketPrice(){
        return ticketPrice;
    }
    int getDay(){
        return day;
    }
    type getFilmType(){
        return filmType;}
        
    bool choice(string word) {
            return comment.find(word) != string::npos;
        }
    void printMovie(){
        cout<< title <<" "<< comment<<" "<<ranking<<" "<<id<<" "<<releaseDate<<" "<<characterNum<<" "<<ticketPrice<<" "<<day<<" "<<filmType<<endl;
      
     
    }
    
        
    };
class cinema{
private:
    string name;
    string location;
    
public:
    vector<movie> movies;
    
    
    cinema(){
        
    }
    
    cinema(string name, string location){
        this->name= name;
        this->location= location;
    }
    
    ~cinema(){
        
    }
    void addMovie(movie film1){
        movies.push_back(film1);
    }
    string getName( ){
        return name;
    }
    string getlocation( ){
        return location;
    }
    
    void printMovies(){
        for(int i = 0;i<movies.size();i++){
            movies[i].printMovie();
            
            
            
        }
       
        
    }
    
    void selectFilmByType(type filmType){
        for(int i = 0;i<movies.size();i++){
            if (filmType == movies[i].getFilmType()){
                movies[i].printMovie();
            }
        }
        
    }
    
    void sortByReleaseDate(){
        for(int i = 0; i< movies.size()-1; i++){
            for(int j = 0; j<movies.size()-i-1;j++)
                if(movies[j].getReleaseDate()>movies[j+1].getReleaseDate()){
                    swap(movies[j] ,movies[j+1] );
                }
        }
        
    }
};

void calculateProfit(vector<movie> movies, int day, int count){
    int profit = 0;
    for(int i = 0; i<count; i++){
        if(movies[i].getDay()== day){
            profit+= movies[i].getTicketPrice();
            
        }
    }
    cout<<"profit per day is:"<< profit<< endl;
}
        

/*string title;
string comment;
int ranking;
int id;
int releaseDate;
int characterNum;
int ticketPrice;
type filmType;*/


        

int main(){
    movie film1 = movie("aot","incredible",1,12,2012,60,100,2,HORROR);
    movie film2 = movie("batman","fine",1,12,2009,50,50,3,COMEDY);
    movie film3 = movie("superman","good",1,12,2014,50,25,4,THRILLER);
    movie film4 = movie("marvel","bad",1,12,2015,50,75,2,ACTION);
    cinema forum;
    forum.addMovie(film1);
    forum.addMovie(film2);
    forum.addMovie(film3);
    forum.addMovie(film4);
    calculateProfit(forum.movies, 2, (int)forum.movies.size());
    forum.printMovies();
    forum.sortByReleaseDate();
    forum.printMovies();
    
    
    cout<<"enter genre: ";
    int a;
    cin>> a;
    type genre = static_cast<type>(a);
    forum.selectFilmByType(genre);
     
       
        
    return 0;
    }


