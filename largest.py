from functools import cmp_to_key
from typing import List


class Solution:
    def largestNumber(self, nums: List[int]) -> str:
       
        # transforma a lista em uma string
        
        for i,n in enumerate(nums):
            nums[i] = str(n)
       
        # compara a concatenação dos números da lista de forma a achar em qual ordem devem ser inseridos,
        # caso o primeiro resulte em um número maior, retorna a primeira concatenação, 
        # caso o segundo resulte em um número maior, retorna a segunda concatenação,
        # caso não tenha diferença, retorna a primeira por padrão(economiza de usar um elif)
       
        def compara(n1,n2):
            if n1 + n2 > n2 + n1:
                return -1
            else:
                return 1
            
        # utilizando as funções existentes no python de comparação(cmp_to_key), 
        # conversão(int para se livrar do caso de existirem apenas 0s na lista e str antes dele para reconverter em string) 
        # e ordenação(sorted)

        nums = sorted(nums, key = cmp_to_key(compara))
        return str(int("".join(nums)))