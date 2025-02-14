#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// Function to compare pairs by frequency in descending order
bool compareFrequency(const pair<char, double>& a, const pair<char, double>& b){
    return a.second > b.second;
}

string decText(const string& text, const vector<char>& tableArray){
    map<char, int> letterCounts;
    int totalLetters = 0;
    
    
    // Initialize the map with all letters from a-z
    for(char letter = 'a'; letter <= 'z'; ++letter){
        letterCounts[letter] = 0;
    }

    // Count each time each letter appears in the encrypted text
    for(char letter : text){
        if (isalpha(letter)){
            letter = tolower(letter);
            letterCounts[letter]++;
            totalLetters++;
        }
    }

    // Calculate the frequency of each letter relative to how often they appear in the encrypted text
    vector<pair<char, double>> frequencies;
    for(char letter = 'a'; letter <= 'z'; ++letter){
        double frequency = static_cast<double>(letterCounts[letter]) / totalLetters;
        frequencies.push_back({letter, frequency});
    }

    
    // Sort the frequencies in descending order
    sort(frequencies.begin(), frequencies.end(), compareFrequency);



    // Save the sorted letters to an array
    char sortedLetters[26];
    for(int i = 0; i < 26; ++i){
        sortedLetters[i] = frequencies[i].first;
    }

    //-----------------DEBUG-------------------//
    cout << "\n---------------------DEBUG---------------------" << endl;
    cout << "\nSorted Letters in Order of Frequency; Decending Order\n";
    for(char c : sortedLetters){
        cout << c << " ";
    }
    cout << endl;
    
    // Print the sorted letters and their frequencies
    cout << "\nFrequency of Sorted Letters\n";
    for(const auto& pair : frequencies){
        cout << pair.first << ": " << pair.second << " " <<"\n";
    }
    cout << endl;

    
    // Create substitution map
    map<char, char> substitutionMap;

    for(int i = 0; i < 26; ++i){
        substitutionMap[sortedLetters[i]] = tableArray[i];
    }

    cout << "\nSubstitution Map: BEFORE Correction\n";
    for(auto it = substitutionMap.cbegin(); it != substitutionMap.cend(); ++it){
        cout << "[" << it->first << " : " << it->second << "]" << "\t";
    }
    cout << endl;
    cout << endl;

    
    //Correct the map as needed
    substitutionMap['l'] = 'b';
    substitutionMap['n'] = 'u';
    substitutionMap['j'] = 'o';
    substitutionMap['x'] = 'f';
    substitutionMap['q'] = 'k';
    substitutionMap['s'] = 'p';
    substitutionMap['t'] = 'y';
    substitutionMap['w'] = 'i';
    substitutionMap['k'] = 'n';
    substitutionMap['o'] = 'g';
    substitutionMap['b'] = 't';
    substitutionMap['a'] = 'x';
    substitutionMap['e'] = 'v';
    substitutionMap['g'] = 'z';
    substitutionMap['c'] = 'w';
    substitutionMap['f'] = 'q';
    substitutionMap['z'] = 'j';
    
    cout << "\nSubstitution Map: AFTER Correction\n";
    for(auto it = substitutionMap.cbegin(); it != substitutionMap.cend(); ++it){
        cout << "[" << it->first << " : " << it->second << "]" << "\t";
    }
    cout << "\n\n-------------------DEBUG-END-------------------\n\n";
    //-----------------DEBUG-END-------------------//

    // Decrypt the text
    string plainText;
    for(char letter : text){
        if(isalpha(letter)){
            plainText += substitutionMap[letter];
        }else{
            plainText += letter;
        }
    }
    
    cout << "Plain Text:" << endl;
    return plainText;
}


int main(){
    string eText = "lrvmnir bpr sumvbwvr jx bpr lmiwv yjeryrkbi jx qmbm wi "
    "bpr xjvni mkd ymibrut jx irhx wi bpr riirkvr jx "
    "ymbinlmtmipw utn qmumbr dj w ipmhh but bj rhnvwdmbr bpr "
    "yjeryrkbi jx bpr qmbm mvvjudwko bj yt wkbrusurbmbwjk "
    "lmird jk xjubt trmui jx ibndt "
    "            "
    "wb wi kjb mk rmit bmiq bj rashmwk rmvp yjeryrkb mkd wbi "
    "iwokwxwvmkvr mkd ijyr ynib urymwk nkrashmwkrd bj ower m "
    "vjyshrbr rashmkmbwjk jkr cjnhd pmer bj lr fnmhwxwrd mkd "
    "wkiswurd bj invp mk rabrkb bpmb pr vjnhd urmvp bpr ibmbr "
    "jx rkhwopbrkrd ywkd vmsmlhr jx urvjokwgwko ijnkdhrii "
    "ijnkd mkd ipmsrhrii ipmsr w dj kjb drry ytirhx bpr xwkmh "
    "mnbpjuwbt lnb yt rasruwrkvr cwbp qmbm pmi hrxb kj djnlb "
    "bpmb bpr xjhhjcwko wi bpr sujsru msshwvmbwjk mkd "
    "wkbrusurbmbwjk w jxxru yt bprjuwri wk bpr pjsr bpmb bpr "
    "riirkvr jx jqwkmcmk qmumbr cwhh urymwk wkbmvb ";

    //Sorted table array
    vector<char> tableText = {
        'e', 't', 'a', 'o', 'i', 'n', 's', 'h', 'r', 'd',
        'l', 'c', 'u', 'm', 'w', 'f', 'g', 'y', 'p', 'b',
        'v', 'k', 'j', 'x', 'q', 'z'
    };

    cout << "\nSorted table array\n";
    for(char c : tableText){
        cout << c << " ";
    }
    cout << endl;
    
    //decrypt the text
    cout << decText(eText, tableText) << endl;

    return 0;
}
