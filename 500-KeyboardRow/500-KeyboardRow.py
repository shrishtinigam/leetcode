# Last updated: 9/4/2025, 7:51:43 AM
class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        row_a = "qwertyuiop"
        row_b = "asdfghjkl"
        row_c = "zxcvbnm"
        result = []
        cur = 0
        for _word in words:
            word = _word.lower()
            for letter in word:
                row = 0
                if letter in row_a:
                    row = 1
                elif letter in row_b:
                    row = 2
                else:
                    row = 3
                if cur == 0:
                    cur = row
                elif cur != row:
                    cur = 0
                    break
            if cur != 0:
                result.append(_word)
            cur = 0
        return result
                
                
        