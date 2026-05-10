#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>

using namespace std;

// 判断字符是否是单词字符
bool isWordChar(char c) {
    return isalpha(c) || c == '-' || c == '\'';
}

// 清理单词
string cleanWord(string word) {
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    while (!word.empty() && !isalpha(word.front())) {
        word.erase(0, 1);
    }
    while (!word.empty() && !isalpha(word.back())) {
        word.pop_back();
    }
    return word;
}

unordered_map<string, int> countWords(ifstream& inputFile) {
    unordered_map<string, int> wordCount;
    string word;
    char c;
    while (inputFile.get(c)) {
        if (isWordChar(c)) {
            word += c;
        }
        else if (!word.empty()) {
            string cleaned = cleanWord(word);
            if (!cleaned.empty()) {
                wordCount[cleaned]++;
            }
            word.clear();
        }
    }
    if (!word.empty()) {
        string cleaned = cleanWord(word);
        if (!cleaned.empty()) {
            wordCount[cleaned]++;
        }
    }
    return wordCount;
}

int main() {
    string inputFilename, outputFilename;
    cout << "输入文件路径: ";
    cin >> inputFilename;
    cout << "输出文件路径: ";
    cin >> outputFilename;
    ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        cerr << "无法打开输入文件: " << inputFilename << endl;
        return 1;
    }
    auto wordCount = countWords(inputFile);
    inputFile.close();
    ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        cerr << "无法打开输出文件: " << outputFilename << endl;
        return 1;
    }
    outputFile << "统计结果（共 " << wordCount.size() << " 个不同单词）:\n";
    for (const auto& pair : wordCount) {
        outputFile << pair.first << ": " << pair.second << " 次\n";
    }
    outputFile.close();
    cout << "统计完成，结果已保存到 " << outputFilename << endl;
    return 0;
}