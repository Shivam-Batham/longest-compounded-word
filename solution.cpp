// Algorithm:

// The program uses a Trie data structure to efficiently check if a word can be formed by concatenating other words. It follows these steps:

// 1.Read the list of words from the input file and insert them into a Trie.
// 2.Sort the list of words in descending order of length.
// 3.For each word in the sorted list, check if it is a compound word by traversing the Trie.
// 4.Store compound words in a set.
// 5.Find the longest and second-longest compound words from the set.
#include <bits/stdc++.h>
using namespace std;
struct TrieNode
{
    bool isEOF;
     unordered_map<char, TrieNode*> child;

    TrieNode() : isEOF(false) {}
};

void insert(TrieNode* root, const  string& word)
{
    TrieNode* current = root;
    for (char c : word) {
        if (!current->child.count(c))
        {
            current->child[c] = new TrieNode();
        }
        current = current->child[c];
    }
    current->isEOF = true;
}

bool compound(TrieNode* root, const  string& word, int start, int length, int count)
{
    TrieNode* current = root;
    for (int i = start; i < length; ++i)
    {
        char c = word[i];
        if (!current->child.count(c))
        {
            return false;
        }
        current = current->child[c];
        if (current->isEOF)
        {
            if (i == length - 1)
            {
                return count >= 2;
            }
            if (compound(root, word, i + 1, length, count + 1))
            {
                return true;
            }
        }
    }
    return false;
}

void longest( ifstream& inputFile,  string& first,  string& second)
{
    TrieNode* root = new TrieNode();
    first = "";
    second = "";

     vector< string> wordList;
     set< string> compoundWords;

     string word;
    while (inputFile >> word)
    {
        insert(root, word);
        wordList.push_back(word);
    }

     sort(wordList.begin(), wordList.end(), [](const  string& a, const  string& b)
    {
        return a.size() > b.size();
    });

    for (const  string& word : wordList)
    {
        if (compound(root, word, 0, word.length(), 0))
        {
            compoundWords.insert(word);
        }
    }

    for (const  string& word : wordList)
    {
        if (compoundWords.find(word) != compoundWords.end())
        {
            if (first.empty() || word.size() > first.size())
            {
                second = first;
                first = word;
            }
            else if (word.size() > second.size())
            {
                second = word;
            }
        }
    }
}

int main()
{
     ifstream file("Input_01.txt");
    if (!file)
    {
         cerr << "Failed to open the input file." <<  endl;
        return 1;
    }

     string first, second;
    auto startTime =  chrono::high_resolution_clock::now();
    longest(file, first, second);
    auto endTime =  chrono::high_resolution_clock::now();
    auto processingTime =  chrono::duration_cast< chrono::milliseconds>(endTime - startTime);

    if (!first.empty())
    {
         cout << "Answer:" <<  endl;
         cout << "1. Longest Compound Word: " << first <<  endl;
    } else
    {
         cout << "No compounded words found in the list." <<  endl;
    }

    if (!second.empty())
    {
         cout << "2. Second Longest Compound Word: " << second <<  endl;
    }
    else
    {
         cout << "No second longest compounded word found." <<  endl;
    }

     cout << "Time taken to process the input file: " << processingTime.count() / 1000.0 << " seconds" <<  endl;

    return 0;
}