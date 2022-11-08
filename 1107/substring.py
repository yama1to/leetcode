class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        seen = {}
        l = 0
        output = 0
        
        for r in range(len(s)):

            #s[r]がseenの中に入っていないならば、output更新
            if s[r] not in seen:
                output = max(output, r-l+1)

            #s[r]がseenの中に入っている。
            else:
                #それが、lよりも左側になるならば、output更新
                if seen[s[r]] < l:
                    output = max(output, r-l+1)
                #lと同じか右側ならば、lを更新する。
                else:
                    l = seen[s[r]] + 1
            seen[s[r]] = r 
        
        return output
            


