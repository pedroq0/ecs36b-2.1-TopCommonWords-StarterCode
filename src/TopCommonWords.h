#ifndef TOPCOMMONWORDS_TOPCOMMONWORDS_H
#define TOPCOMMONWORDS_TOPCOMMONWORDS_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <functional>

std::string cleanWords(const std:: string& word); // gets rid of punctuation/lowercase
bool shouldlIgnore (const std::string& word); //ignores common words
std:: map <std::string, int> countWords(std::istream& input); // counts words
std::map<int, std::vector<std::string>, std::greater<int>>groupByCount(
    const std::map<std::string,int> & wordCounts
    );
void printTopWords( //prints result
    const std::map<int, std::vector<std::string>,std::greater<int>>& groupWords,int n
    );

#endif //TOPCOMMONWORDS_TOPCOMMONWORDS_H
