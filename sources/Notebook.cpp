

#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

#include "Notebook.hpp"

     

    void ariel::Notebook::write(  int page, int row,  int column, Direction d, string txt){
        // cout<< "start writing"<< endl;
        const int minsymb=32;
        const int maxsymb=125;
        const int max=100;
        int txt_length=txt.length(); 

        if(page<0 ||row<0 ||column<0){
            // cout<< "threw exception"<< endl;
            throw std::invalid_argument( "the page or row or column is negative" );
        }

        for (std::string::size_type i = 0; i < txt.size(); i++){
            if(txt.at(i)<minsymb || txt.at(i)>maxsymb){
                // cout<< "threw exception"<< endl;
                throw std::invalid_argument( "the text has an illegal symbol" );  
            }
        }

        if(d==Direction::Horizontal){
            if (column+txt_length>=max){
                // cout<< "threw exception"<< endl;
                throw std::invalid_argument( "the text goes out of bound of the row" );
            }
        }
        else{
            if (column>max){
                // cout<< "threw exception"<< endl;
                throw std::invalid_argument( "the text goes out of bound of the row" );  
            }
        }
        std::string reading=ariel::Notebook::read(page,row,column,d,txt.size());
        for( std::string::size_type i = 0; i < txt.size(); i++){
            if(reading[i]!='_'){
                // cout<< "threw exception"<< endl;
                 throw std::invalid_argument( "the text is trying to over write other text or marked out text" );
            }
        }
        if (d==Direction::Horizontal){
             std::string::size_type j=0;
            for( int i=column; i<column+txt_length;i++){
                unsigned long k=(unsigned long)i;
                // _NotebookPageMap[page]._PageRowMap[row]._row[k]=txt[j];   
                _NotebookPageMap[page]._PageRowMap[row][k]=txt[j];
                j++;
            } 
        }
        else{
            std::string::size_type j=0; 
            for( int i=row; i<row+txt_length;i++){
                unsigned long k=(unsigned long)column;
               // _NotebookPageMap[page]._PageRowMap[i]._row[k]=txt[j]; 
               _NotebookPageMap[page]._PageRowMap[i][k]=txt[j];
                j++; 
            } 
        }
        // cout<< "finish writing"<< endl;
    }

    string ariel::Notebook::read( int page, int row, int column, Direction d, int length){
        // cout<< "start reading"<< endl;
        if(page<0 ||row<0 ||column<0 || length<0){
            //  cout<< "threw exception"<< endl;
            throw std::invalid_argument( "the page or row or column or length is negative" );
        }

        //cout << "this function should read" << endl;
        
        const int max=100;
        if(d==Direction::Horizontal){
            if (column+length>max){
                //  cout<< "threw exception"<< endl;
                throw std::invalid_argument( "the text goes out of bound of the row" );
            }
        }
        else{
            if (column>max){
                //  cout<< "threw exception"<< endl;
              throw std::invalid_argument( "the text goes out of bound of the row" );  
            }
        }
    
        // check if page exsists, if not add the page
        // cout<< "checking page"<< endl;
        if(_NotebookPageMap.find(page)==_NotebookPageMap.end()){ 
            Page p;
            _NotebookPageMap.insert( pair< int, Page>(page, p)); 
        }    
        // cout<< "finish checking page"<< endl;
        std::string ans;

        //horizantal
        if (d==Direction::Horizontal){
            if(_NotebookPageMap[page]._PageRowMap.find(row)==_NotebookPageMap[page]._PageRowMap.end()){
                // Row r;
                // r.start();
                // cout<< 2;
                
                // _NotebookPageMap[page]._PageRowMap.insert(pair< int,Row>(row,r));
                _NotebookPageMap[page].addRow(row);
                // Row row1=_NotebookPageMap[page]._PageRowMap[row];
                // cout<< "prow"<<endl;
                // row1._row[0]='_';
                // row1.print();
                // cout<< 3;
                for(  int i=column; i<column+length;i++){
                    // cout<< 4;
                    unsigned long k=(unsigned long)i;
                    // cout<< 5;
                    // std::vector<char>* v=&_NotebookPageMap[page]._PageRowMap[row];
                    // std::vector<char> copy= *v;
                    // cout << copy.size()<< endl;
                    // cout<<copy[0];
                    char c=_NotebookPageMap[page]._PageRowMap[row][k];
                    cout<< c;
                  
                    ans.push_back(_NotebookPageMap[page]._PageRowMap[row][k]);
                    // ans.push_back(_NotebookPageMap[page]._PageRowMap[row]._row.at(k));
                    cout<< 6<<endl;
                }   
            }
            else{
                for(int i=column; i<column+length;i++){
                    // cout <<7;
                    unsigned long k=(unsigned long)i;
                    // cout <<8<< endl;
                    // Row prow=_NotebookPageMap[page]._PageRowMap[row];
                    // cout<< "prow"<<endl;
                    // prow.print();
                    // char c=_NotebookPageMap[page]._PageRowMap[row]._row.at(k);
                    // cout << c;
                    // ans.push_back(_NotebookPageMap[page]._PageRowMap[row]._row.at(k));
                    ans.push_back(_NotebookPageMap[page]._PageRowMap[row][k]);
                    // cout <<9<<endl;
                } 
            }
            return ans;
        }
        //vertical
        for ( int i=row; i<row+length;i++){
            if(_NotebookPageMap[page]._PageRowMap.find(i)==_NotebookPageMap[page]._PageRowMap.end()){


                // Row r;
                // r.start();
                // _NotebookPageMap[page]._PageRowMap.insert(pair< int,Row>(i,r));
                _NotebookPageMap[page].addRow(i);
                // Row prow=_NotebookPageMap[page]._PageRowMap[i];
                // prow.print();
                unsigned long k=(unsigned long)column;
                //ans.push_back(_NotebookPageMap[page]._PageRowMap[i]._row.at(k));
                ans.push_back(_NotebookPageMap[page]._PageRowMap[i][k]);
            }
            else{
                unsigned long k=(unsigned long)column;
                //ans.push_back(_NotebookPageMap[page]._PageRowMap[i]._row.at(k));
                ans.push_back(_NotebookPageMap[page]._PageRowMap[i][k]);
            }
        }
        // cout << "finished reading"<< endl;
        return ans;
        //return "somthing";
    
    }


    void ariel::Notebook::erase( int page,  int row,  int column, Direction d, int length){

         if(page<0 ||row<0 ||column<0 || length<0){
            //   cout<< "threw exception"<< endl;
            throw std::invalid_argument( "the page or row or column or length is negative" );
        }
         
        //cout << "this function should erase" << endl;
        
        const int max=100; 
        if(d==Direction::Horizontal){
            if (column+length>=max){
                //  cout<< "threw exception"<< endl;
                throw std::invalid_argument( "the text goes out of bound of the row" );
            }
        }
        else{
            if (column>=max){
                //  cout<< "threw exception"<< endl;
                throw std::invalid_argument( "the text goes out of bound of the row" );  
            }
        }
      
        if (d==Direction::Horizontal){
            for( int i=column; i<column+length;i++){
                unsigned long k=(unsigned long)i;
               // _NotebookPageMap[page]._PageRowMap[row]._row[k]='~';
               _NotebookPageMap[page]._PageRowMap[row][k]='~';
            } 
        }
        else{
            for( int i=row; i<row+length;i++){
                unsigned long k=(unsigned long)column;
               // _NotebookPageMap[page]._PageRowMap[i]._row[k]='~'; 
                _NotebookPageMap[page]._PageRowMap[i][k]='~'; 
            }   
        }
    }

    void ariel::Notebook::show( int page){
        const int max=100;
        const int intraval =50;
        if(page<0 ){
            //  cout<< "threw exception"<< endl;
            throw std::invalid_argument( "the page is negative" );
        }
        //cout << "this function should show" << endl;
        if(_NotebookPageMap.find(page)==_NotebookPageMap.end()){
            cout << "this page has not been created"<<endl;
            cout << "do you want to create it? \n  reply 0 for yes, 1 for no"<<endl;
            int ans=1;
            cin >> ans;
            if (ans==0){
                Page p;
                // _NotebookPageMap.insert(pair< int,Page>(0,p));
                // Row r;
                //_NotebookPageMap[page]._PageRowMap.insert(pair< int,Row>(0,r));
                _NotebookPageMap[page].addRow(0);
                cout << "page number" << page <<endl;
                cout <<"row 0: " ;
                string line =read(/*page*/page,  /*row*/0,  /*column*/0,  Direction::Horizontal,max);
                cout<< line<< endl;  
            }
        }
        else{
            int ans=0;
            int start=0;
            int end=intraval;
            while (ans ==0){
                cout << "printing the first 50 rows that have been used"<< endl;
                for (int i=start; i<end;i++){
                    if(_NotebookPageMap[page]._PageRowMap.find(i)!=_NotebookPageMap[page]._PageRowMap.end()){
                        cout << "row " << i << ":   ";
                        string line=read(/*page*/page,  /*row*/i,  /*column*/0,  Direction::Horizontal,max);
                        cout<< line<< endl; 
                    }
                }
                cout << "do you want to print the next 50 used rows? \n  reply 0 for yes, 1 for no"<< endl;
                cin >> ans;
                start=start+intraval;
                end=end+intraval;
            }
            
        }
    }


