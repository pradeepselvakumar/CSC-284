#include <curses.h> // PDCurses
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

struct TrieNode {
    std::unordered_map<char, std::unique_ptr<TrieNode>> children;
    bool isWord = false;
};

class Trie {
public:
    Trie() : root(std::make_unique<TrieNode>()) {}

void insert(const std::string& word) {
    TrieNode* node = root.get();
    for (char ch : word) {
        ch = std::tolower(ch);
        if (!node->children[ch])
            node->children[ch] = std::make_unique<TrieNode>();
        node = node->children[ch].get();
    }
    node->isWord = true;
}

void searchPrefix(const std::string& prefix, std::vector<std::string>& results, int limit = 20) const {
    const TrieNode* node = root.get();
    for (char ch : prefix) {
        if (!node->children.count(ch)) return;
        node = node->children.at(ch).get();
    }
    collectWords(node, prefix, results, limit);
}

private:
    std::unique_ptr<TrieNode> root;

void collectWords(const TrieNode* node, std::string current, std::vector<std::string>& results, int limit) const {
    if (results.size() >= static_cast<size_t>(limit)) return;
    if (node->isWord) results.push_back(current);
    for (const auto& [ch, child] : node->children) {
        collectWords(child.get(), current + ch, results, limit);
    }
}
};

// === Utility Functions ===
void loadWordsFromFile(const std::string& filename, Trie& trie) {
    std::ifstream file(filename);
    std::string word;
    while (std::getline(file, word)) {
        if (!word.empty())
            trie.insert(word);
    }
}

void printHighlighted(WINDOW* win, const std::string& word, const std::string& prefix, int row) {
    wattron(win, A_BOLD);
    mvwprintw(win, row, 0, "%s", prefix.c_str());
    wattroff(win, A_BOLD);
    wprintw(win, "%s", word.substr(prefix.length()).c_str());
}

// === Main Program ===
int main() {
    Trie trie;
    loadWordsFromFile("words.txt", trie);

    initscr();            // Start curses mode
    cbreak();             // Disable line buffering
    noecho();             // Don't echo typed characters
    keypad(stdscr, TRUE); // Enable special keys (like backspace)
    curs_set(1);          // Show cursor

    std::string input;
    int ch;

    while (true) {
        clear();
        // Display input prompt and user-typed text
        mvprintw(0, 0, "Type to search (ESC to exit): ");
        attron(A_BOLD);
        mvprintw(1, 0, "%s", input.c_str());
        attroff(A_BOLD);

        // Get matches
        std::vector<std::string> matches;
        trie.searchPrefix(input, matches);

        // Display matches
        int row = 3;
        for (const std::string& word : matches) {
            printHighlighted(stdscr, word, input, row++);
        }

        // Move the cursor to the end of the user input on line 1
        move(1, static_cast<int>(input.size()));

        refresh();

        ch = getch();
        if (ch == 27) break; // ESC key to quit
        else if (ch == KEY_BACKSPACE || ch == 127 || ch == 8) {
            if (!input.empty())
                input.pop_back();
        }
        else if (std::isprint(ch)) {
            input.push_back(static_cast<char>(ch));
        }
    }

    endwin(); // End curses mode
    return 0;
}
