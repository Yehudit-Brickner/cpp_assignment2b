

#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>
#include "Direction.hpp"
#include "Page.hpp"

using namespace std;



namespace ariel{ 

    class Notebook{
   
        private:

            std::map< int, Page> _NotebookPageMap;

        public:
           

            void write( int page,  int row, int column, Direction d, string txt);
            string read( int page,  int row,  int column, Direction d,  int length);
            void erase( int page,  int row,  int column, Direction d,  int length);
            void show( int page);
           
                       
            
            void addPage( int num){
                if(_NotebookPageMap.find(num)==_NotebookPageMap.end()){ // check if the page exsits
                    Page p;
                    _NotebookPageMap.insert( pair<int, Page>(num, p)); // if not create new page
                }
            }

            // //constructer
            // Notebook(){
            //     addPage(0);
            // }
    };

}; 