//Matthew Michael Sherlin
//CS3 Lab 2
//2/5/2021

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include "WordList.hpp"

using std::string;


//class WordOccurrence

    WordOccurrence::WordOccurrence(const string& word, int num){
      word_ = word;
      num_ = num;
    }
    
    bool WordOccurrence::matchWord(const string& word){ // returns true if word matches stored
      if(word == word_){
        return true;
      }
      else{
        return false;
      }
    }
    
    
    void WordOccurrence::increment(){  // increments number of occurrences
      ++num_;
    }
    
    std::string WordOccurrence::getWord() const{
      return word_;    
    }
    
    int WordOccurrence::getNum() const{
      return num_;
    }

    bool WordOccurrence::operator<(const WordOccurrence& temp){
      return temp.num_ > num_;
    }


//class WordList

    //add copy constructor, destructor, overloaded assignment
    //constructor
    WordList::WordList() {
      size_ = 0;
      wordArray_ = new WordOccurrence[size_];
    }    
        
    //copy constructor
    WordList::WordList(const WordList& copy){
      size_ = copy.size_;
      wordArray_ = new WordOccurrence [size_];
      for(int i=0; i < size_; i++){
        wordArray_[i]=copy.wordArray_[i];
      }
    }
    
    
    //overloaded assignment
    WordList& WordList::operator=(WordList rhs) { 
      if (this == &rhs){
        return *this;                                    //protection against these cases
      }
      if (wordArray_ != nullptr){
        delete[] wordArray_;
      }
      size_ = rhs.size_;
      wordArray_ = new WordOccurrence[size_];

      for (int i = 0; i < size_; ++i){
        wordArray_[i] = rhs.wordArray_[i];
      }
      return *this;
      }
    
    //destructor
    WordList::~WordList(){
      delete [] wordArray_;
    } 
    
    // implement comparison as friend
    bool equal(const WordList& lhs, const WordList& rhs){
      if(lhs.size_ != rhs.size_){
        return false;
    }
      for(int i=0; lhs.size_> i; ++i){
        if(lhs.wordArray_[i].getWord() != rhs.wordArray_[i].getWord()){      //compare wordArray_ to the argument, if any differences in words
          return false;                                                      // or in the numCount, return false for boolean
        }
        if(lhs.wordArray_[i].getNum() != rhs.wordArray_[i].getNum()){
          return false;
        }
      }
      return true;
    } 
    
    void WordList::addWord(const string& word){
      for(int i=0; i < size_; ++i){                  //iterate through the list
        if(wordArray_[i].matchWord(word)){           //if the word matches another on list
          wordArray_[i].increment();                  //increment the wordCount
          return;
          }
        }
        
      WordOccurrence *tmp = wordArray_;
      wordArray_ = new WordOccurrence[size_ + 1];
      for(int i=0; i < size_; ++i){                  //iterate through and set values from tmp back into wordArray_
        wordArray_[i] = tmp[i];
      }
      delete[] tmp;                                  //delete and new word added to end
      wordArray_[size_] = word;                        //increment one onto the numCount for new word
      wordArray_[size_].increment();
      size_++;
  }

    void WordList::print(){
    std::cout << "Word Count Assignment" << std::endl;
    std::cout << "Word" << "\t" << "Occurrence" << std::endl;
    std::cout << "-------------------" << std::endl;
   
    std::sort(wordArray_, wordArray_ + size_);                  //using sort function to get order. Created < operator in WordOccurrence
    for(int i = 0; i < size_; ++i){
      std::cout << wordArray_[i].getWord() << "\t" << wordArray_[i].getNum() << std::endl;
      }
    }

