#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// English letter frequencies (approximate) - Table 1.1
vector<pair<char, double>> englishF = {
    {'a', 0.0817}, {'b', 0.0150}, {'c', 0.0278}, {'d', 0.0425}, {'e', 0.1270},
    {'f', 0.0223}, {'g', 0.0202}, {'h', 0.0609}, {'i', 0.0697}, {'j', 0.0015},
    {'k', 0.0077}, {'l', 0.0403}, {'m', 0.0241}, {'n', 0.0241}, {'o', 0.0675},
    {'p', 0.0193}, {'q', 0.0010}, {'r', 0.0599}, {'s', 0.0633}, {'t', 0.0906},
    {'u', 0.0276}, {'v', 0.0098}, {'w', 0.0236}, {'x', 0.015}, {'y', 0.0197},
    {'z', 0.0007}
};

// Function to compare pairs by frequency in descending order
bool compareFrequency(const pair<char, double>& a, const pair<char, double>& b){
    return a.second > b.second;
}

string decText(const string& text, const vector<char>& subArray){
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

        // sort English letter frequencies from smallest to largest using compareFrequency function
    sort(englishF.begin(), englishF.end(), compareFrequency);
    
    
    // add sorted frequencies to an array
    // increment through each letter and frequency to add them to the sortedLetters array
    char sortedLetters[26];
    for(int i=0; i < 26; i++){
        sortedLetters[i] = frequencies[i].first;
    }
    // do the same for the English Frequencies
    char sortedLettersENG[26];
    for(int i=0; i < 26; i++){
        sortedLettersENG[i] = englishF[i].first;
    }
    
    
    // Debugging
    cout << "\nENCRYPTED - Sorted Letters in Descending Order of Frequency\n";
    for(char c : sortedLetters){
        cout << c << " ";
    }
    cout << endl;
    
    cout << "\nENGLISH - Sorted Letters in Descending Order of Frequency\n";
    for(char c : sortedLettersENG){
        cout << c << " ";
    }
    cout << endl;
    
    
    cout << "\nEncrypted Frequency of Sorted Letters in Encrypted Text\n";
    // 'auto' sorts through all elements in map and prints the letter and their frequency (Descending Order)
    for(const auto& pair : frequencies){
        cout << pair.first << ": " << pair.second << " " << "\n";
    }

    // Print the sorted letters and their frequencies for the English Language (Descending Order)
    cout << "\nFrequency of Sorted Letters in English Language\n";
    for(const auto& pair : englishF){
        cout << pair.first << ": " << pair.second << " " <<"\n";
    }
    cout << endl;
    
    
    
    // Substitution Map
    // Map that tells us which letters should substitute each other
    map<char, char> substitutionMap;
    
    for(int i = 0; i < 26; i++){
        substitutionMap[(sortedLetters[i])] = (sortedLettersENG[i]);
    }

    cout << "\nSubstitution Map: BEFORE Correction\n";
    for(auto j = substitutionMap.cbegin(); j != substitutionMap.cend(); ++j){
        cout << "[" << j->first << " : " << j->second << "]" << "\t";
    }
    cout << endl;

    
    
    //Correct the map as needed
    substitutionMap['l'] = 'b';
    substitutionMap['n'] = 'u';
    substitutionMap['x'] = 'f';
    substitutionMap['q'] = 'k';
    substitutionMap['s'] = 'p';
    substitutionMap['t'] = 'y';
    substitutionMap['w'] = 'i';
    substitutionMap['k'] = 'n';
    substitutionMap['o'] = 'g';
    substitutionMap['a'] = 'x';
    substitutionMap['g'] = 'z';
    substitutionMap['c'] = 'w';
    substitutionMap['z'] = 'j';
    substitutionMap['v'] = 'c';
    substitutionMap['i'] = 's';
    substitutionMap['p'] = 'h';
    substitutionMap['u'] = 'r';
    substitutionMap['y'] = 'm';
    substitutionMap['d'] = 'd';
    substitutionMap['h'] = 'l';
    
    

    cout << "\nSubstitution Map: AFTER Correction\n";
    for(auto j = substitutionMap.cbegin(); j != substitutionMap.cend(); ++j){
        cout << "[" << j->first << " : " << j->second << "]" << "\t";
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
        'e', 't', 'a', 'i', 'o', 's', 'h', 'r', 'd',
        'l', 'c', 'u', 'm', 'n', 'w', 'f', 'g', 'y', 
        'p', 'x', 'b', 'v', 'k', 'j', 'q', 'z'
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
