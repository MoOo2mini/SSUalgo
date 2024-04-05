def find(dna_sequence1, dna_sequence2):
    # DNA 상보적 쌍을 위한 사전 정의
    complement = {'A': 'T', 'T': 'A', 'G': 'C', 'C': 'G'}
    
    for i in range(len(dna_sequence1)) :
        if (dna_sequence2[i] == complement[dna_sequence1[i]]) :
            continue
        else :
            return str(i + 1) + "번째에서 돌연변이 발생"

# 예제 DNA 서열
dna_sequence1 = input()
dna_sequence2 = input()
# 상보적 서열 출력
print(*find(dna_sequence1, dna_sequence2))  # TAGCCTA