from sympy import primerange
import random

def main():
    names = ["1.txt" , "2.txt"]

    sets , mod = shingle(names)
    sets = [set(sets[0]) , set(sets[1])]
    print("jaccardi is: ", len(sets[0].intersection(sets[1]))/len(sets[0].union(sets[1])))
    

    n = 100

    s = 0
    for i in range(n):
        j = minhash_arx(sets,mod)
        s+=j

    print("CW is : ",s/n)

    s = 0
    for i in range(n):
        j = minhash_cw(sets,mod)
        s+=j

    print("arx is : ",s/n)



def minhash_cw(sets,mod):
    k=10     # number of permutations(hash functions)
    prime_generator = primerange(mod + 1, mod + 100000)
    p = next(prime_generator)
    perms=[]
    for i in range(k):
        a = random.randint(1,p-1)
        b = random.randint(1,p-1)
        lambda_expr = lambda x , a=a , b=b: (a*x+b) % p
        perms.append(lambda_expr)
    

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

def minhash_arx(sets,mod):
    k=10     # number of permutations(hash functions)
    prime_generator = primerange(mod + 1, mod + 1000)
    p = next(prime_generator)


    p = mod-1
    perms=[]
    for i in range(k):
        b = random.randint(p//2,3*p//2)
        lambda_expr = lambda x , b=b: (x+b) & p
        perms.append(lambda_expr)
    

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





def shingle(names):
    data = []
    for name in names:

        with open(name,'r') as file: 
            d = file.read().lower()
            data.append(d)

    size = []
    for i in range(len(data)):
        size.append(len(data[i]))

    mod = max(size)
    print(mod)
    mod = 2**32

    sets = []
    for i in range(len(data)):
        s = []
        for j in range(0,len(data[i])-8,1):
            s.append(hash(data[i][j:j+9])%mod)
        sets.append(s)


    return sets , mod

if __name__ == "__main__":
    main()