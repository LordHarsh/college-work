#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
map<char, set<char>> first, follow;
vector<string> grammar;
map<char, vector<string>> rules;
set<char> nonTerminals, terminals;
char startSymbol;

// Use 'e' as epsilon symbol instead of 'ε'
const char EPSILON = 'e';

void findFirst(char symbol)
{
    if (first.count(symbol))
        return;
    first[symbol] = {};

    for (auto &rule : rules[symbol])
    {
        for (char ch : rule)
        {
            if (!isupper(ch))
            {
                first[symbol].insert(ch);
                break;
            }
            findFirst(ch);
            first[symbol].insert(first[ch].begin(), first[ch].end());
            if (first[ch].count(EPSILON) == 0)
                break;
        }
    }
}

void findFollow(char symbol)
{
    if (follow.count(symbol))
        return;
    follow[symbol] = {};
    if (symbol == startSymbol)
        follow[symbol].insert('$');

    for (auto &[lhs, prods] : rules)
    {
        for (auto &rule : prods)
        {
            for (size_t i = 0; i < rule.size(); ++i)
            {
                if (rule[i] == symbol)
                {
                    for (size_t j = i + 1; j < rule.size(); ++j)
                    {
                        char next = rule[j];
                        follow[symbol].insert(first[next].begin(), first[next].end());
                        if (first[next].count(EPSILON) == 0)
                            break;
                    }
                    if (i + 1 == rule.size() || first[rule[i + 1]].count(EPSILON))
                    {
                        findFollow(lhs);
                        follow[symbol].insert(follow[lhs].begin(), follow[lhs].end());
                    }
                }
            }
        }
    }
}

void printSet(string name, map<char, set<char>> &sets)
{
    for (auto &[symbol, setVals] : sets)
    {
        cout << name << "(" << symbol << ") = { ";
        for (char val : setVals)
            cout << val << " ";
        cout << "}\n";
    }
}

int main()
{
    int n;
    cout << "Enter number of productions: ";
    cin >> n;

    cout << "Enter grammar rules (Example: E->TX):\n";
    for (int i = 0; i < n; ++i)
    {
        string rule;
        cin >> rule;
        char lhs = rule[0];
        string rhs = rule.substr(3);
        rules[lhs].push_back(rhs);
        nonTerminals.insert(lhs);
        if (i == 0)
            startSymbol = lhs;
    }

    for (auto &[lhs, prods] : rules)
        findFirst(lhs);
    for (auto &[lhs, prods] : rules)
        findFollow(lhs);

    cout << "\nFIRST and FOLLOW sets:\n";
    printSet("FIRST", first);
    printSet("FOLLOW", follow);

    return 0;
}