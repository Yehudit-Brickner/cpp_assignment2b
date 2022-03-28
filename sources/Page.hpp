#pragma once


#include <stdexcept>
#include <string>
#include <iostream>
//#include <vector>
#include <map>
using namespace std;
 

class Page{

      
    public: 
        // std::map< int, Row> _PageRowMap;

            std::map< int, std::string > _PageRowMap;

        // void addRow( int num){
        //     if(_PageRowMap.find(num)==_PageRowMap.end()){ // check if the row exsits
        //         Row r;
        //         r.start();
        //         _PageRowMap.insert( pair< int, Row>(num, r)); // if not create new row 
        //     }
        // }

         void addRow(int num){
            if(_PageRowMap.find(num)==_PageRowMap.end()){ // check if the row exsits
                std::string s="____________________________________________________________________________________________________";
            //     r.reserve(100);
            //     for (unsigned long i=0; i<100; i++){
            //         r[i]='_';
            //    }
                _PageRowMap.insert( pair< int, std::string >(num, s)); // if not create new row 
            }
        }
        
        
        //constructer
        // Page(){
        //     addRow(0);
        // }   

};