def complement_dna(dna_sequence):
    # DNA 상보적 쌍을 위한 사전 정의
    complement = {'A': 'T', 'T': 'A', 'G': 'C', 'C': 'G'}
    
    complement_sequence = []
    for a in dna_sequence :
        complement_sequence.append(a)
    return complement_sequence

# 예제 DNA 서열
dna_sequence = input()

# 상보적 서열 출력
print(*complement_dna(dna_sequence))  # TAGCCTA