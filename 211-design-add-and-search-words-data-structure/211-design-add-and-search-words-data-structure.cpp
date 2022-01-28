struct Trie 
{
     vector<Trie *> child;
     bool isWord;
     Trie() : isWord(false), child(vector<Trie *>(26, nullptr)) {}
 };

class WordDictionary {
public:
 Trie *root;
 WordDictionary() : root(new Trie()) {}

void addWord(string word) {
    const int size_w = word.size();
    Trie *cur = root;
    for (int i = 0; i < size_w; i++) {
        int index = word[i] - 'a';
        if (!cur->child[index]) cur->child[index] = new Trie();
        cur = cur->child[index];
    }
    cur->isWord = true;
}

bool search(string word) {
    return search(word.c_str(), root);
}
bool search(const char *ch, Trie *cur) {
    if (!cur) return false;
    if (*ch == '\0') return cur->isWord;
    if (*ch != '.') {
         return search(ch+1, cur->child[*ch - 'a']);
    } else {
        for (int i = 0; i <= 25; i++) {
            if (search(ch+1, cur->child[i])) return true;
        }
        return false;
    }
}
};