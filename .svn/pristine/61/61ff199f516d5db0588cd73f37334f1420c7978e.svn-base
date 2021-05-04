//Matthew Michael Sherlin
//CS3 Lab 2
//2/5/2021

#ifndef WordList_H_
#define WordList_H_
#include <string>

using std::string;

class WordOccurrence {
public:
    WordOccurrence(const string& word="", int num=0);
    bool matchWord(const string &); // returns true if word matches stored
    void increment(); // increments number of occurrences
    string getWord() const; 
    int getNum() const;
    bool operator<(const WordOccurrence&);

private:
    string word_;
    int num_;
};

class WordList{
public:
    // add copy constructor, destructor, overloaded assignment
    WordList();
    WordList(const WordList &);
    ~WordList(); 
    WordList& operator=(WordList);
    
    // implement comparison as friend
    friend bool equal(const WordList&, const WordList&);

    void addWord(const string &);
    void print();
private:
    WordOccurrence *wordArray_; // a dynamically allocated array of WordOccurrences
                                // may or may not be sorted
    int size_;
};

#endif