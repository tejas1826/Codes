import sys
class Solution:
    def trailingZeroes(self, n: int) -> int:
       
        sys.set_int_max_str_digits(0)
        fact=1
        c=0
        l=[]
        for i in range(1,n+1):
            fact=fact*i
        for x in str(fact):
            l.append(x)
        for j in l:
            if j=='0':
                c+=1
            if j!='0':
                c=0
        return c