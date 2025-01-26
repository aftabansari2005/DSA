class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int idx = -1;
        int n1 = searchWord.size();
        int n2 = sentence.size();

        int wordIndex = 1;  // to keep track of the word position
        int i = 0;

        while (i < n2) {
            while (i < n2 && sentence[i] == ' ') {
                i++;
            }

            if (i >= n2) break;

            int temp = i;
            while (i < n2 && sentence[i] != ' ') {
                i++;
            }

            int length = i - temp;
            if (n1 <= length && sentence.substr(temp, n1) == searchWord) {
                return wordIndex;
            }
            wordIndex++;
        }
        return idx;
    }
};
