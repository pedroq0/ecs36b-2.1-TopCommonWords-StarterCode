# include "TopCommonWords.h"


# include <cctype>
#include <set>

std::string cleanWords(const std::string& word) {
    int start = 0;
    int end = static_cast<int>(word.size()) - 1;

    while (start <= end && !std::isalnum(word[start])){
        start++;
    } // removes stuff in front of words
    while (end >= start && !std::isalnum(word[end])) {
        end--;
    }// removes stuff behind

    std::string cleaned = word.substr(start, end - start+1);

    for (char& c :cleaned ) {
        c = static_cast<char>(std::tolower(c));
    }//lower cases everything
    return cleaned;
}

bool shouldIgnore(const std::string& word) {
    static const std::set<std::string> ignored = {
        "a","an","and","in","it","the"
    };
    return ignored.count(word)>0;
}

std::map <std::string, int> countWords (std::istream& input) {
    std::map<std::string, int > counts;
    std::string word;
    while ( input>> word) {
        std::string cleaned = cleanWords(word);

        if (!cleaned.empty() && !shouldIgnore(cleaned)) {
            counts[cleaned]++;
        }
    }
    return counts;
}

std::map<int, std::vector<std::string>, std::greater<int>> groupByCount(
   const std::map<std::string, int>& wordCounts
   ){
    std::map<int, std::vector<std::string>, std::greater<int>> grouped;

    for (const auto& pair: wordCounts) {
        grouped[pair.second].push_back(pair.first);
    }
    return grouped;
   }

void printTopWords(
    const std::map<int, std::vector<std::string>, std::greater<int> > &groupWords,
    int n
    ) {
    int rank=1;
    for (const auto& pair: groupWords) {
        if (rank > n )break;
        std::cout << rank<< ".) These words appeared "
        << pair.first << " times: {";
        for (size_t i= 0; i< pair.second.size(); i++) {
            std:: cout << pair.second[i];
            if ( i< pair.second.size()-1 ) {
                std::cout<< ", ";
            }
        }
        std::cout << "}" << std::endl;
        rank++;
    }
}
