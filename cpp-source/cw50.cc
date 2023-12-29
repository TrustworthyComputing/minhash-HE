#pragma hls_top
unsigned short minhash(unsigned short set1 [50], unsigned short set2 [50]){
    unsigned short prime = 16381;
    unsigned short const number_of_hashes = 5;
    unsigned short a [number_of_hashes] = {53,59,61,71,73};
    unsigned short b [number_of_hashes] = {16000,16050,16100,16150,16200};
    unsigned short sig1 [number_of_hashes];

    #pragma hls_unroll yes
    for ( unsigned short j = 0; j<number_of_hashes; j++){
        unsigned short minhash_value = prime;
	#pragma hls_unroll yes
        for ( unsigned short k = 0; k<50; k++){
            unsigned short hash = (a[j] * set1[k] + b[j]) % prime;
            if (hash < minhash_value){
                minhash_value = hash;
            }
        }
        sig1[j] = minhash_value;

    }

    unsigned short sig2[number_of_hashes];
    #pragma hls_unroll yes
    for ( unsigned short j = 0; j<number_of_hashes; j++){
        unsigned short minhash_value = prime;
        #pragma hls_unroll yes
        for ( unsigned short k = 0; k<50; k++){
            unsigned short hash = (a[j] * set2[k] + b[j]) % prime;
            if (hash < minhash_value){
                minhash_value = hash;
            }
        }
        sig2[j] = minhash_value;

    }

    unsigned short count=0;
    #pragma hls_unroll yes
    for( unsigned short i = 0; i < number_of_hashes; i++){
        if (sig1[i] == sig2[i]){
            count+=1;
        }
    }
    return count;
}

