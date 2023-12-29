import random

def main():
    # input text file.
    name = "1.txt"

    sets , mod = shingle(name)

    # number of hash functions
    k = 100

    p_arx = mod-1
    perms_arx=[]
    for i in range(k):
        b = random.randint(p_arx//2,3*p_arx//2)
        lambda_expr = lambda x , b=b: (x+b) & p_arx
        perms_arx.append(lambda_expr)

    p_cw = 4294967311
    perms_cw=[]
    for i in range(k):
        a = random.randint(1,p_cw-1)
        b = random.randint(1,p_cw-1)
        lambda_expr = lambda x , a=a , b=b: (a*x+b) % p_cw
        perms_cw.append(lambda_expr)


    dif_cw = dif_arx = 0
    count = 0
    for a in range(1):
        for b in range(1,len(sets)):
            print(100*'--')
            print(f'set {a} and  {b}:')
            jac = len(sets[a].intersection(sets[b]))/len(sets[a].union(sets[b]))
            print("jaccardi is: ", jac)


            j = minhash_arx([sets[a],sets[b]],perms_arx,p_arx)
            print("arx is : ",j)
            dif_arx+=abs(jac-j)


            j = minhash_cw([sets[a],sets[b]],perms_cw,p_cw)
            print("cw is : ",j)
            dif_cw+=abs(jac-j)

            count+=1
    print(100*'--')
    print('dif cw :',dif_cw/count)
    print('dif arx :',dif_arx/count)




def minhash_cw(sets,perms,p):

    k = len(perms)
    sigs = []
    for s in sets:
        sig = [p+1]*k
        for j in range(k):
            for i in s:
                hashcode = perms[j](i)
                if hashcode < sig[j]:
                    sig[j] = hashcode
        sigs.append(sig)



    count = 0
    for i in range(len(sigs[0])):
        if sigs[0][i] == sigs[1][i]:
            count+=1
    return count/k

def minhash_arx(sets,perms,p):
    
    k = len(perms)
    sigs = []
    for s in sets:
        sig = [p+1]*k
        for j in range(k):
            for i in s:
                hashcode = perms[j](i)
                if hashcode < sig[j]:
                    sig[j] = hashcode
        sigs.append(sig)



    count = 0
    for i in range(len(sigs[0])):
        if sigs[0][i] == sigs[1][i]:
            count+=1
    return count/k





def shingle(name):

    with open(name,'r') as file: 
        text = file.read().lower()


    # randomize the text

    data = [text]

    for _ in range(10):
        for chunk_size in range(1,11):
            words = text.split()

            word_groups = [words[i:i + chunk_size] for i in range(0, len(words), chunk_size)]

            random.shuffle(word_groups)

            permuted_text = ' '.join([' '.join(group) for group in word_groups])
            data.append(permuted_text)


    mod = 2**32
    sets = []
    for i in range(len(data)):
        s = set()
        for j in range(0,len(data[i])-8,1):
            s.add(hash(data[i][j:j+9])%mod)
        sets.append(s)


    return sets , mod

if __name__ == "__main__":
    main()
