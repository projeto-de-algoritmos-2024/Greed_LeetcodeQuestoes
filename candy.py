from typing import List


class Solution:
    def candy(self, ratings: List[int]) -> int:
        
        # inicia todas as crianças com pelo menos 1 doce, que é o mínimo pedido
        # pela questão
        
        doce = [1] * len(ratings)

        # a solução pensada é percorrer o vetor duas vezes, porém corrigindo apenas 
        # os valores das crianças com pontuação maior que o vizinho da direita na volta.
        

        for i in range(1, len(ratings)):
            if ratings[i - 1] < ratings[i]:
                doce[i] = doce[i - 1] + 1
        
        # faz a checagem reversa do for de cima, apenas aumentando o que for necessário aumentar,
        # uma vez que agora os valores mínimos já foram encontrados pelo primeiro for

        for i in range(len(ratings) - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                
                # para não dar chance de aumentar ainda mais o valor, pois queremos o mínimo
                doce[i] = max(doce[i],doce[i+1]+1)
        
        return sum(doce)